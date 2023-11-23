#include<seat.h>
#include<vector>
#include <string>

struct PassengerList{
    int pass_id;
    PassengerList * next;
};

typedef std::vector< std::vector<Seat> > SeatMap;

class Flight {       
  public:  
    // .checkseatavailability
  private:          
    std::string flight_id;
    int rows;
    int columns;
    PassengerList* pass_listH;
    SeatMap FSmap;
    
};