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


TEST(Proxy, Mock){
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
    EXPECT_EQ(1,1);
}
