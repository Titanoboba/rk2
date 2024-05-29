#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Proxy.h"

class ProxyMock : public Proxy{
    public:
    ProxyMock(DataBase*database) : Proxy(database){}
    MOCK_CONST_METHOD2(Login, void(std::string, std::string));
    MOCK_METHOD1(Append, void(std::string));
    MOCK_CONST_METHOD0(GetList, std::list<std::string>());
    MOCK_METHOD0(Truncate, void());
};

TEST(ProxyState, firstTest){
    DataBase* database = new DataBase();
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    Proxy prox(database);
    prox.Login("Me", "MyPassword1234");
    prox.Append("IamTheFourthString");
    std::list<std::string> testList1;
    testList1.insert(testList1.end(), {"IamTheFirstString","IamTheSecondString","IamTheThirdString","IamTheFourthString"});
    //First test
    EXPECT_EQ(prox.GetList(), testList1);
    delete database;
}
TEST(ProxyState, secondTest){
    DataBase* database = new DataBase();
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    ProxyMock prox(database);
    //Second test
    EXPECT_CALL(prox, Truncate()).Times(1);
    prox.Truncate();
    std::list<std::string> testList2;
    EXPECT_EQ(prox.GetList(), testList2);
    delete database;
}
TEST(ProxyState, thirdTest){
    DataBase* database = new DataBase();
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    //Third test
    ProxyMock prox(database);
    //prox.Login("Me", "MyPassword1234"); I am not logged in
    std::list<std::string> dummy;
    EXPECT_EQ(prox.GetList(), dummy);
    EXPECT_FALSE(prox.IsLogedIn());
    delete database;
}
