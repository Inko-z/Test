#ifndef FLIGHT_H
#define FLIGHT_H
#include"passenger.cpp"
#include<vector>
#include <string>

struct PassengerList{
    Passenger Pass;  //pass is literal passenger object
    PassengerList * next;
};
typedef std::vector< std::vector<int> > SeatMap;
class Flight {       
  public:  
    void checkseatavail();
    Flight();
    Flight(int rows, int columns, const std::string& id, PassengerList* passList);
    Flight(const Flight& rhs);
    int get_number_of_rows()const;
    int get_number_of_columns()const;
    std::string get_flight_id()const;
    int get_seat_status(int row, int col);
    void set_number_of_columns(int c);
    void set_number_of_rows(int r);
    void set_flight_id(std::string f_id);
    //void set_FSmap(const SeatMap& fmap);
    const PassengerList* get_passlist()const;
    


  private:          
    std::string flight_id;
    int number_of_rows;
    int number_of_columns;
    PassengerList* pass_listH;
    SeatMap FSmap;   //matrix of integers

};
#endif