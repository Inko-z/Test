#include<vector>
#include <string>

struct PassengerList{
    
    PassengerList * next;
};

class Airpline {       
  public:  
    // .checkseatavailability???
  private:          
    std::string flight_id;
    int rows;
    int columns;
    PassengerList* pass_listH;
    // seat map datamember: vector of vector
    
};