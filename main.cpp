#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "airline.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "extraction.cpp"
#include "Globalfunctions.h"


int main(){
    
    std::ifstream readingstream("flight_info.txt");
    
    //read all data from file and turn it into objects, lists, ect. in the program
    // airline ptr
    if(readingstream.is_open()){
        std::cout << "file error\n";
    }
    std::string line = extract_the_line(readingstream); // reads first line

    Airline a1 = extract_airline(line); //makes airline object based on first line
    a1.set_num(1);
    Flight* f1 = extract_flight(line); //makes flight object on the heap based on first line


    FlightList* fl1 = new FlightList{*f1, nullptr}; //first flightlist struct 

    a1.set_list(fl1); // sets first flightlist struct as head of list

    
    while(!readingstream.eof()){
        std::string line = extract_the_line(readingstream);
        Passenger* new_pass = extract_passenger(line);
        PassengerList* p1 = new PassengerList{*new_pass, nullptr}; // first passengerlist struct
        
        p1->next = f1->get_pass_listH();
        f1->set_pass_listH(p1);
        p1 = nullptr;
        delete new_pass;
        new_pass = nullptr;
 
    

    printfirstmessege();
    int runprogram = 1; //bool logic to eventually exit the program
    char selection;

    ////////////////////////////////////THIS IS A TESTING THING/////////////////////////////////
    std::string s = "booger";
    Flight f(24, 6, s, nullptr);
    ////////////////////////////////////////////////////////////////////////////////////////////
    if(pressreturntocontinue()){
        printoptions();
///////////////////////////////////////////MAIN PROGRAM LOOP///////////////////////////////////////////
        while(runprogram){ 



            std::cin >> selection;
            if(selection == '1'){
                DisplaySeatMap(f); /////////////////////////testing////////////////////////////////////////
                pressreturntocontinue();
                printoptions();

            }else if (selection == '2')
            {
                pressreturntocontinue();
                printoptions();
            }
            else if (selection == '3')
            {
                pressreturntocontinue();
                printoptions();            
            }
            else if (selection == '4')
            {
                pressreturntocontinue();
                printoptions();
            }else if (selection == '5')
            {
                pressreturntocontinue();
                printoptions();               

            }else if (selection == '6')
            {
                runprogram = 0;
            }
            else
            {
                std::cout << "Worng input\n";

            }
        }
    }
}
