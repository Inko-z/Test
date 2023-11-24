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
    Flight::Flight(int rows, int columns, const std::__cxx11::string &id, PassengerList *passList, const SeatMap &map);
    Flight(const Flight& rhs);
    int get_number_of_rows()const;
    int get_number_of_columns()const;
    std::string get_flight_id()const;
    SeatMap get_FSmap()const;
    void set_number_of_columns(int c);
    void set_number_of_rows(int r);
    void set_flight_id(std::string f_id);
    void set_FSmap(const SeatMap& fmap);


  private:          
    std::string flight_id;
    int number_of_rows;
    int number_of_columns;
    PassengerList* pass_listH;
    SeatMap FSmap;
    
};