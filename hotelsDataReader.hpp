#ifndef HOTELSDATAREADER_HPP
#define HOTELSDATAREADER_HPP "HOTELSDATAREADER_HPP"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "hotel.hpp"

#define HOTEL_FILE_COLUMNS 16

#define PART1 4
#define PART2 8
#define PART3 12
#define PART4 16

#define S_ROOM 's'
#define D_ROOM 'd'
#define L_ROOM 'l'
#define P_ROOM 'p'

#define STRING_PTR_FROM 0
#define CHAR_DELIMETER ','

#define P_A_CHAR_DELIMETER '|'

#define UNIQUE_ID 0
#define PROPERTY_NAME 1
#define HOTEL_STAR_RATING 2
#define HOTEL_OVERVIEW 3
#define PROPERTY_AMENITIES 4
#define CITY 5
#define LATITUDE 6
#define LONGITUDE 7
#define IMAGEURL 8
#define NUM_STANDARD_ROOMS 9
#define NUM_DELUXE_ROOMS 10
#define NUM_LUXURY_ROOMS 11
#define NUM_PREMIUM_ROOMS 12
#define STANDARD_ROOMS_PRICE 13
#define DELUXE_ROOMS_PRICE 14
#define LUXURY_ROOMS_PRICE 15
#define PREMIUM_ROOMS_PRICE 16


class Hotel;

typedef std::vector< Hotel* >  HOTELS;

class HotelsDataReader : public Hotel
{
public:
    HotelsDataReader() = default;
    HOTELS saveHotelsInfo(const std::string &hotelsInfoAdd);

private:

    void setFilters( Hotel* &hotel);
    Hotel* eachLineHotelsInfo(std::string &tempString);
    void savingData1(std::string &firstPart , Hotel* &hotel);
    void savingData2(std::string &firstPart , Hotel* &hotel);
    void savingData3(std::string &firstPart , Hotel* &hotel);
    void savingData4(std::string &firstPart , Hotel* &hotel);
    std::string prepareString(std::string &tempString, char delimeter);
    std::vector<std::string> readHotelPropertyAmenities(std::string &propertyAmenitiesString);
    std::vector<RoomF> prepareRooms(int roomsNum,char roomtype);

    int numOfPA;
    int stringDelimeterPos;
    int fillingLevel;
    std::string firstPart;
    std::string tempString; 
    std::vector<RoomF> rooms;

};


#endif