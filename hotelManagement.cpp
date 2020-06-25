#include "hotelManagement.hpp"

using namespace std;


HolidayInn::HolidayInn(const std::string &hotelsInfoAdd)
{
    DB = new DataBase(hotelsInfoAdd);
    hotel = new Hotel(DB,DB->getHotels() ) ;
    login = new Login(DB) ;
    signup = new Signup(DB,login);
    comment = new Comment(DB,login,hotel,DB->getHotels());
    rating = new Rating(DB,login,hotel,DB->getHotels());
    filters = new Filters(DB,login,hotel,DB->getHotels());
    reserve = new Reserve(DB,login,hotel,DB->getHotels(),filters);
    instruction = new Instruction(DB,login,signup,hotel,filters,reserve,comment,rating );
}

void HolidayInn::getService(const std::string &hotelsInfoAdd)
{
    instruction->distinguishInstruction();

}