#ifndef SEAT_H
#define SEAT_H
#include<vector>
#include <string>

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
#endif