#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Proxy.h"

class ProxyMock : public Proxy{
    public:
    ProxyMock(DataBase*database) : Proxy(database){}
    MOCK_METHOD(Login, (void(std::string userName,std::string password)));
    MOCK_METHOD(Append, (void(const std::string &data)));
    MOCK_METHOD(GetList, std::list<std::string>);
    MOCK_METHOD(Truncate, void());
};

TEST(Proxy, Mock){
    DataBase* database;
    database->append("IamTheFirstString");
    database->append("IamTheSecondString");
    database->append("IamTheThirdString");
    ProxyMock prox(DataBase*database);
    prox.Login("Me", "MyPassword1234");
    prox.Append("IamTheFourthString");
    std::list<std::string> testList1;
    testList1.insert(testList1.end() {"IamTheFirstString","IamTheSecondString","IamTheThirdString","IamTheFourthString"})
    EXPECT_EQ(prox.GetList(), testList1);
}