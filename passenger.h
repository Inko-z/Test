#include <seat.h>
#include<airline.h>
#include <string>

class Passenger {       
  public:  

    
  private:          
    std::string Fname;
    std::string Lname;
    std::string phone;
    int pass_id;
    Seat * seat;    //ex: (example: 6A, 13C, 2B, etc), points to specific seat on a flight seat map
    
    
};