#include"god.h"

//DEFAULT CTR
Seat::Seat(){
    row = 0;
    column = '\0';
    seat_status = 0;
}
//CUSTOM CTR
Seat::Seat(int r, int c, int s_s){
    row = r;
    column = c;
    seat_status = s_s;
}
//COPY CTR
Seat::Seat(const Seat& rhs){  //Currently assumed that the seats ARE NOT created on the heap
    row = rhs.row;
    column = rhs.column;
    seat_status = rhs.seat_status;
}
//IMPLEMENTATION
int Seat::get_row()const{return row;}
char Seat::get_column()const{return column;}
int Seat::get_seat_status()const{return seat_status;}
void Seat::set_row(int r){row = r;}
void Seat::set_column(int c){column = c;}
void Seat::set_seat_status(int s_s){seat_status = s_s;}



