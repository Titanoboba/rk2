#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Proxy.h"

class ProxyMock : public Proxy{
    public:
    ProxyMock(DataBase*database) : Proxy(database){}
    MOCK_METHOD(Login, void(std::string userName,std::string password));
    MOCK_METHOD(Append, void(const std::string &data));
    MOCK_METHOD(GetList, std::list<std::string>);
    MOCK_METHOD(Truncate, void());
};

TEST(Proxy, Mock){
    DataBase* database;
    database.append("IamTheFirstString");
    database.append("IamTheSecondString");
    database.append("IamTheThirdString");
    ProxyMock prox(DataBase*database);
    //prox.Login("Me", "MyPassword1234"); I am not logged in
    std::list<std::string> dummy
    EXPECT_EQ(prox.GetList(), dummy);
    EXPECT_EQ(prox.Truncate(), void());
    EXPECT_EQ(prox.IsLogedIn(), false);
} 