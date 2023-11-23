#include<vector>
#include <string>

struct FlightList{
    std::string Fname;
    FlightList * next;
};

class Airpline {       
  public:  
           
  private:          
    std::string airline_name;
    FlightList* flight_listH;
    int flight_num;  
};