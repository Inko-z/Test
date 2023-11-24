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
    Flight();
    int get_number_of_rows()const;
    int get_number_of_columns()const;

  private:          
    std::string flight_id;
    int number_of_rows;
    int number_of_columns;
    PassengerList* pass_listH;
    SeatMap FSmap;
    
};