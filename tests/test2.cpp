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
    DataBase* database = new DataBase();
    database->Append("IamTheFirstString");
    database->Append("IamTheSecondString");
    database->Append("IamTheThirdString");
    ProxyMock prox(database);
    prox.Login("Me", "MyPassword1234");
    prox.Truncate();
    std::list<std::string> testList1;
   EXPECT_EQ(prox.GetList(), testList1);
} 