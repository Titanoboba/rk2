#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Proxy.h"

class ProxyMock : public Proxy{
    public:
    ProxyMock(DataBase*database) : Proxy(database){}
    MOCK_CONST_METHOD2(Login, void(std::string userName, std::string password));
    MOCK_METHOD1(Append, void(std::string));
    MOCK_CONST_METHOD0(GetList, std::list<std::string>());
    MOCK_METHOD0(Truncate, void());
};


TEST(ProxyState, myTest){
    /*DataBase* database = new DataBase();
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    ProxyMock prox(database);
    prox.Login("Me", "MyPassword1234");
    prox.Append("IamTheFourthString");
    std::list<std::string> testList1;
    testList1.insert(testList1.end(), {"IamTheFirstString","IamTheSecondString","IamTheThirdString","IamTheFourthString"});
    //First test
    EXPECT_EQ(prox.GetList(), testList1);
    //Second test
    prox.Truncate();
    std::list<std::string> testList2;
    EXPECT_EQ(prox.GetList(), testList2);
    //Third test
    ProxyMock prox2(database);
    //prox2.Login("Me", "MyPassword1234"); I am not logged in
    std::list<std::string> dummy;
    EXPECT_EQ(prox2.GetList(), dummy);
    EXPECT_FALSE(prox2.IsLogedIn());
    delete database;*/

    *DataBase* database = new DataBase();
    EXPECT_CALL(database, Append()).Times(3);
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    ProxyMock prox(database);
    EXPECT_CALL(prox, Login()).Times(1);
    prox.Login("Me", "MyPassword1234");
    EXPECT_CALL(prox, Truncate()).Times(1);
    prox.Truncate();
    std::list<std::string> dummy;
    EXPECT_CALL(prox, GetList()).Times(1);
    std::list<std::string> proxList;
    proxList = prox.GetList();
    EXPECT_EQ(proxList, dummy);

    delete database;
}
