#ifndef HOTELMANAGEMENT_HPP
#define HOTELMANAGEMENT_HPP "HOTELMANAGEMENT_HPP"

#include "manageInstruction.hpp"
#include "customer.hpp"
#include "dataBase.hpp"
#include "comment.hpp"
#include "filters.hpp"
#include "reserve.hpp"
#include "rating.hpp"
#include "signup.hpp"
#include "hotel.hpp"
#include "login.hpp"


#include <iostream>
#include <string>
#include <vector>




class HolidayInn
{
public:
    HolidayInn(const std::string &hotelsInfoAdd);
    void getService(const std::string &hotelsInfoAdd);


private:

    DataBase* DB;
    Hotel* hotel;
    Login* login;
    Signup* signup;
    Rating* rating;
    Filters* filters;
    Comment* comment;
    Reserve* reserve;
    Instruction* instruction;

};

#endif