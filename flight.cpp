#include <flight.h>
//Default ctor
Flight::Flight(){
    number_of_rows = 0;
    number_of_columns = 0;
    flight_id = "";
    pass_listH = nullptr;
    FSmap = {};
}
//custom ctor
Flight::Flight(){
    number_of_rows = 0;
    number_of_columns = 0;
    flight_id = "";
    pass_listH = nullptr;
    FSmap = {};




//implementation
int Flight::get_number_of_rows()const{return number_of_rows;}