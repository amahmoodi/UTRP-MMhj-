#ifndef LOGIN_HPP
#define LOGIN_HPP "LOGIN_HPP"

#include "exception.hpp"
#include "dataBase.hpp"
#include "customer.hpp"

#include <map>

#define NUM_F 3




class Database;

typedef std::map<std::string, std::string> Map;
typedef std::vector< pair<std::string , int >> Rooms ;

class Login 
{
public:
    Login(DataBase* db) : DB(db) {}

    void getWallet(int upTO);    
    void chargeAccount(Map &params);
    void handleLogin(Map &Parameters);
    void login(Customer* customer);
    void logout();
    void setIsFiltered(bool _isFilter) { IsFilterPosted = _isFilter ;}

    bool isFilterPosted() { return IsFilterPosted; }
    bool isLoggedIn(){return IsLoggedIn;}
    Customer* getCurrentCustomer() { return currentCustomer;}
    std::string getCustomerN() { return customerN; }
    std::string getCustomerE() { return customerE; } 
    std::string getCustomerP() { return customerP; } 

    void setCityFOn(bool _cityFOn ){  cityFOn  = _cityFOn;  }
    void setStarFOn(bool _starFOn){   starFOn = _starFOn; }
    void setPriceFOn(bool _priceFOn){   priceFOn = _priceFOn; }
    void setVacantFOn(bool _vacantFOn) {  vacantFOn = _vacantFOn; }

    int howManyFiltersOn(); 

    bool getCityFOn(){ return cityFOn ; }
    bool getStarFOn(){ return  starFOn; }
    bool getPriceFOn(){ return  priceFOn; }
    bool getVacantFOn(){ return  vacantFOn; }

    void deleteFilters();

    void checkWallet(double quantity , double price );

    void getReservesList();
    void setReserves(Map &param,int &hotelNum , double &price ,Rooms &rooms );

    void dischargeReserves(int id);

private:
    
    void setLoginFiltersOff() ;


    DataBase* DB;
    Customer* currentCustomer;
    bool IsLoggedIn = false;
    bool IsFilterPosted = false;
    std::string customerN;
    std::string customerE;
    std::string customerP;

    bool cityFOn=false;
    bool starFOn=false;
    bool priceFOn=false;
    bool vacantFOn=false;

    bool found = false;



};

#endif