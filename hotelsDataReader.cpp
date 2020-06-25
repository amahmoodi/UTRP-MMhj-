#include "hotelsDataReader.hpp"

using namespace std;

string HotelsDataReader::prepareString(string &tempString, char delimeter)
{
    stringDelimeterPos = tempString.find(delimeter);
	firstPart = tempString.substr(STRING_PTR_FROM, stringDelimeterPos);
    tempString = tempString.substr(stringDelimeterPos + 1);
    return firstPart;
}

void HotelsDataReader::savingData4(string &firstPart , Hotel* &hotel)
{
	if (fillingLevel == STANDARD_ROOMS_PRICE)
		hotel->setStandardRoomsPrice(stod(firstPart));
	if (fillingLevel == DELUXE_ROOMS_PRICE)
		hotel->setDeluxeRoomsPrice(stod(firstPart));
	if (fillingLevel == LUXURY_ROOMS_PRICE)
	    hotel->setLuxuryRoomsPrice(stod(firstPart));
    if (fillingLevel == PREMIUM_ROOMS_PRICE)
	    hotel->setPremiumRoomsPrice(stod(firstPart));
        
}

vector<RoomF> HotelsDataReader::prepareRooms(int roomsNum,char roomtype)
{
    vector<RoomF> rooms;

    for(int i=0;i<roomsNum;i++)
    {
        vector<pair<int ,int>> dates;

        dates.push_back(make_pair(0,0));
        rooms.push_back({false,roomtype+to_string(i+1),dates});
    }
    
    return rooms;
}

void HotelsDataReader::savingData3(string &firstPart , Hotel* &hotel)
{
	if (fillingLevel == NUM_STANDARD_ROOMS)
	{
        hotel->setNumStandardRooms(stoi(firstPart));
        hotel->setSRooms(prepareRooms(stoi(firstPart),S_ROOM));
    }
    if (fillingLevel == NUM_DELUXE_ROOMS)
	{
    	hotel->setNumDeluxeRooms(stoi(firstPart));
        hotel->setDRooms(prepareRooms(stoi(firstPart),D_ROOM));
    }
	if (fillingLevel == NUM_LUXURY_ROOMS)
	{
        hotel->setNumLuxuryRooms(stoi(firstPart));
        hotel->setLRooms(prepareRooms(stoi(firstPart),L_ROOM));
    }
    if (fillingLevel == NUM_PREMIUM_ROOMS)
	{
        hotel->setNumPremiumRooms(stoi(firstPart));
        hotel->setPRooms(prepareRooms(stoi(firstPart),P_ROOM));
    }    
}

vector<string> HotelsDataReader::readHotelPropertyAmenities(string &propertyAmenitiesString)
{
    vector<string> propertyAmenities;
    numOfPA= count(propertyAmenitiesString.begin(), propertyAmenitiesString.end(), P_A_CHAR_DELIMETER);
    tempString = propertyAmenitiesString;
	
    for (int j = 0; j <= numOfPA; j++)
	{
        j == (numOfPA) ? firstPart = tempString  : firstPart = prepareString(tempString,P_A_CHAR_DELIMETER);
		propertyAmenities.push_back(firstPart);
	}

    return propertyAmenities;
}

void HotelsDataReader::savingData2(string &firstPart , Hotel* &hotel)
{
	if (fillingLevel == PROPERTY_AMENITIES)
	{
    	hotel->setPropertyAmenities(readHotelPropertyAmenities(firstPart));
    }
    if (fillingLevel == CITY)
	{
    	hotel->setCity(firstPart);
    }
    if (fillingLevel == LATITUDE)
	{
    	hotel->setLatitude(stod(firstPart));
    }
    if (fillingLevel == LONGITUDE)
	{
        hotel->setLongitude(stod(firstPart));
    }
    if (fillingLevel == IMAGEURL)
	{
    	hotel->setImageUrl(firstPart);  
    }
}

void HotelsDataReader::savingData1(string &firstPart , Hotel* &hotel)
{
	if (fillingLevel == UNIQUE_ID)
	{
        hotel->setUniqueId(firstPart);
    }
	if (fillingLevel == PROPERTY_NAME)
	{
    	hotel->setPropertyName(firstPart);
    }
    if (fillingLevel == HOTEL_STAR_RATING)
	{
    	hotel->setHotelStarRating(stoi(firstPart));
    }
    if (fillingLevel == HOTEL_OVERVIEW)
	{
        hotel->setHotelOverview(firstPart);
    }
}

void HotelsDataReader::setFilters( Hotel* &hotel)
{
    hotel->setCityFilter(false);
    hotel->setStarFilter(false);
    hotel->setPriceFilter(false);
    hotel->setVacantFilter(false);
    hotel->setPrintFilter(false);
}

Hotel* HotelsDataReader::eachLineHotelsInfo(string &tempString)
{
    Hotel* hotel = new Hotel();
    setFilters(hotel);

    for( fillingLevel = 0 ;fillingLevel <= HOTEL_FILE_COLUMNS ; fillingLevel++)
    {

        fillingLevel == (HOTEL_FILE_COLUMNS) ? firstPart = tempString  :
                         firstPart = prepareString(tempString,CHAR_DELIMETER);
        if(fillingLevel < PART1 )
        {
            savingData1(firstPart,hotel);
            continue;
        }
        if((fillingLevel <= PART2) && (PART1 <= fillingLevel))
        {
            savingData2(firstPart,hotel);
            continue;
        }
        if((fillingLevel <= PART3) && (PART2 < fillingLevel))
        {
            savingData3(firstPart,hotel);
            continue;
        }
        if((fillingLevel <= PART4) && (PART3 < fillingLevel))
        {
            savingData4(firstPart,hotel);
            continue;
        }    
    }

    return hotel;

}

HOTELS HotelsDataReader::saveHotelsInfo(const std::string &hotelsInfoAdd)
{
    HOTELS hotels;
    HotelsDataReader read;

    ifstream hotelsFile;
    hotelsFile.open(hotelsInfoAdd);

    getline(hotelsFile,tempString,'\n');
    while (getline(hotelsFile,tempString,'\n'))
    {
        hotels.push_back(read.eachLineHotelsInfo(tempString));
    }

    hotelsFile.close();
    return hotels;
}