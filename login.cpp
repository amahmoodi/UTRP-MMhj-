#include "login.hpp"

using namespace std;


void Login::dischargeReserves(int id)
{
    double money;
    money = currentCustomer->cancelReserve(id);
    int last = currentCustomer->getWallet().size()-1;
    money += currentCustomer->getWallet()[last];
    currentCustomer->setWallet(money);

}

void Login::getReservesList()
{
    currentCustomer->printReservesList();
}

void Login::setReserves(Map &param,int &hotelNum , double &price ,Rooms &rooms )
{
    currentCustomer->setInReserveList(param,hotelNum , price ,rooms);

}

void Login::checkWallet(double quantity ,double price)
{
    int last = currentCustomer->getWallet().size() -1;
    double money =  currentCustomer->getWallet()[last];
    if(money < (quantity * price))
        throw EnoughCredit();
    else
        currentCustomer->setWallet((money - (quantity*price)));

}

void Login::deleteFilters()
{
    setLoginFiltersOff();
    DB->setFiltersOff();
    cerr<<"OK"<<endl;
}

void Login::getWallet(int upTo)
{
    currentCustomer->lookAtWallet(upTo);
}

void Login::chargeAccount(Map &params)
{

    currentCustomer->setWallet(stod(params["amount"]));
    cerr<<"OK"<<endl;

}

void Login::login(Customer* customer) 
{
    currentCustomer = customer;
    customerN = customer->getUserName();
    customerE = customer->getEmail();
    IsLoggedIn = true;
    cerr<<"OK"<<endl;
}

void Login::setLoginFiltersOff() 
{
    IsFilterPosted = false;
    cityFOn=false;
    starFOn=false;
    priceFOn=false;
    vacantFOn=false;
}

void Login::logout() 
{
    found = false;
    IsLoggedIn = false;
    setLoginFiltersOff();
    DB->setFiltersOff();
    DB->setLogin(customerN,customerE,false);
    currentCustomer->setLogin(false);
    cerr<<"OK"<<endl;
}

void Login::handleLogin(Map &Parameters)
{
    int upTo = DB->getCustomers().size();
    for (int  i = 0; i < upTo; i++)
    {
        if((Parameters["email"]== DB->getCustomers()[i]->getEmail())&&
            (Parameters["password"]== DB->getCustomers()[i]->getPassWord()))
        {
            found=true;
            currentCustomer = DB->getCustomerByMail(Parameters["email"]);
            customerN = currentCustomer->getUserName();
            customerE = currentCustomer->getEmail();
            customerP = currentCustomer->getPassWord();
            IsLoggedIn = true;
        }
    }
    if(found == true )
    {
        cerr<<"OK"<<endl;
    }
    else
    {
        throw BadRequestError();
    }
    
}

int Login::howManyFiltersOn()
{
    int count =0;
    if(cityFOn)
        count++;
    if(starFOn)
        count++;
    if(priceFOn)
        count++;
    if(vacantFOn)
        count++;

    return count;
}