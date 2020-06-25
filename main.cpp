
#include "hotelManagement.hpp"

using namespace std;

int main (int argc , char* argv[])
{
    string hotelsInfoAdd;
    hotelsInfoAdd = argv[1];
    
    HolidayInn* hotelManager = new HolidayInn(hotelsInfoAdd);
    hotelManager->getService(hotelsInfoAdd);
    
    return 0;
}