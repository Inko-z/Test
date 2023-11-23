#include<vector>
#include <string>

struct FlightList{
    std::string flight_id;
    FlightList * next;
};

class Airline {       
  public:  
           
  private:          
    std::string airline_name;
    FlightList* flight_listH;
    int flight_num;  
};