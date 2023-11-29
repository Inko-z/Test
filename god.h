#include <string>
#include <vector>
#ifndef GOD_H
#define GOD_H
///////////////////////////////////////////////////// SEAT CLASS////////////////////////////////////////////////
class Seat {       
  public:  
   Seat();
   Seat(int r, int c, int s_s);
   Seat(const Seat& rhs);
   int get_row()const;
   char get_column()const;
   int get_seat_status()const;
   void set_row(int r);
   void set_column(int c);
   void set_seat_status(int s);
   
  private:          
    int row;
    char column;
    int seat_status; //use for bool logic. 0=unavailable, 1 = available;
};

/////////////////////////////////////////////// PASSENGER CLASS /////////////////////////////////////////////
class Passenger {       
  public:  
   Passenger();
   Passenger(std::string& fname, std::string& lname, std::string& pho, int& p_id, Seat * s);
   Passenger(const Passenger& rhs);
   std::string get_Fname()const;
   std::string get_Lname()const;
   std::string get_phone()const;
   int get_pass_id()const;
   Seat get_seat()const;
   void set_Fname(std::string& fname);
   void set_Lname(std::string& lname);
   void set_phone(std::string& pho);
   void set_pass_id(int& id);
   void set_seat(Seat * s);
  private:          
    std::string Fname;
    std::string Lname;
    std::string phone;
    int pass_id;
    Seat * seat;    //ex: (example: 6A, 13C, 2B, etc), points to specific seat on a flight seat map 
};


/////////////////////////////////////////////////// FLIGHT CLASS + STRUCT //////////////////////////////////////////////////////
struct PassengerList{
    Passenger Pass;  //pass is literal passenger object
    PassengerList * next;
};

typedef std::vector< std::vector<Seat> > SeatMap; //matrix seat objects

class Flight {       
  public:  
    void checkseatavail();
    Flight();
    Flight(int rows, int columns, const std::string& id, PassengerList* passList);
    Flight(const Flight& rhs);
    int get_number_of_rows()const;
    int get_number_of_columns()const;
    std::string get_flight_id()const;
    SeatMap get_FSmap()const;
    void set_number_of_columns(int c);
    void set_number_of_rows(int r);
    void set_flight_id(std::string f_id);
    void set_FSmap(const SeatMap& fmap);
    const PassengerList* get_passlist()const;
    void insertID(int& id);


  private:          
    std::string flight_id;
    int number_of_rows;
    int number_of_columns;
    PassengerList* pass_listH;
    SeatMap FSmap;

};

//////////////////////////////////////////////////// AIRLINE CLASS + STRUCT ///////////////////////////////////////////////
struct FlightList{
    std::string flight_id;
    FlightList * next;
};

class Airline {       
  public:  
    Airline();
    Airline(std::string name, FlightList* list, int num);
    Airline(const Airline& source);
    ~Airline();

    void set_name(std::string Name);
    void set_list(FlightList* List);
    void set_num(int n);

    const std::string get_name()const;
    const FlightList* get_list()const;
    const int get_num()const;

    void insert(std::string& Name);
  private:          
    std::string airline_name;
    FlightList* flight_listH;
    int number_of_flights;  
};
#endif