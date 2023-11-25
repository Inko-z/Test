#include<flight.h>
#include <iostream>
#include <string>
//Default ctor
Flight::Flight(){
    number_of_rows = 0;
    number_of_columns = 0;
    flight_id = "";
    pass_listH = nullptr;
    FSmap = {};
}
//custom ctor
Flight::Flight(int rows, int columns, const std::string& id, PassengerList* passList, const SeatMap& map){
    number_of_rows = rows;
    number_of_columns = columns;
    flight_id = id;
    pass_listH = passList;
    FSmap = map;
}
//copy ctor
Flight::Flight(const Flight& rhs){
    number_of_rows = rhs.number_of_rows;
    number_of_columns = rhs.number_of_columns;
    flight_id = rhs.flight_id;
    if (rhs.pass_listH != nullptr) { //linked list copy
        pass_listH = new PassengerList(*rhs.pass_listH);
    } else {
        pass_listH = nullptr;
    }
    FSmap = rhs.FSmap;
}  
//implementation


int Flight::get_number_of_rows()const{return number_of_rows;}
int Flight::get_number_of_columns()const{return number_of_columns;}
std::string Flight::get_flight_id()const{return flight_id;}
SeatMap Flight::get_FSmap() const {return FSmap;}
void Flight::set_number_of_rows(int r){number_of_rows=r;}
void Flight::set_number_of_columns(int c){number_of_columns=c;}
void Flight::set_flight_id(std::string f_id){flight_id=f_id;}
void Flight::set_FSmap(const SeatMap& fmap){FSmap = fmap;}
//getter and setter for pass_listh
const PassengerList* Flight::get_passlist()const{
    return pass_listH;
}
void Flight::insertID(int& id ){
PassengerList* new_id = new PassengerList;
if (new_id == 0){
    std::cout<<"Error allocating space for a new passenger id"<< std::endl;
    std::exit(1);
}
new_id -> pass_id = id;
new_id -> next = nullptr;
PassengerList* last = pass_listH;

if(pass_listH == nullptr){
    pass_listH = new_id;
}
while(last -> next != nullptr){
    last = last -> next;
}
last -> next = new_id;
}