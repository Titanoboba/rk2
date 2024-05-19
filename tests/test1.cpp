#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Proxy.h"

class ProxyMock : public Proxy{
    public:
    ProxyMock(DataBase*database) : Proxy(database){}
    MOCK_METHOD2(Login, (std::string userName,std::string password));
    MOCK_METHOD1(Append, (void(const std::string &data)));
    MOCK_METHOD0(GetList, void());
    MOCK_METHOD0(Truncate, void());
};

TEST(Proxy, Mock){
    DataBase* database;
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    ProxyMock prox(DataBase*database);
    prox.Login("Me", "MyPassword1234");
    prox.Append("IamTheFourthString");
    std::list<std::string> testList1;
    testList1.insert(testList1.end() {"IamTheFirstString","IamTheSecondString","IamTheThirdString","IamTheFourthString"});
    EXPECT_EQ(prox.GetList(), testList1);
}