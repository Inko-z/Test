#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

#include "airline.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "extraction.cpp"
#include "Globalfunctions.h"

int main(){
    
    std::ifstream readingstream("C:\\Users\\nieto\\OneDrive\\Desktop\\final 337\\ENSF337-Term-Project\\flight_info.txt");
    
    //read all data from file and turn it into objects, lists, ect. in the program
    // airline ptr
    if(!readingstream.is_open()){
        std::cout << "****************FILE ERROR****************\n";
    }
    std::string line = extract_the_line(readingstream); // reads first line

    Airline a1 = extract_airline(line); //makes airline object based on first line
    a1.set_num(1);
    Flight* f1 = extract_flight(line); //makes flight object on the heap based on first line
    
    FlightList* fl1 = new FlightList{*f1, nullptr}; //first flightlist struct 

    a1.set_list(fl1); // sets first flightlist struct as head of list

    ///////////////READING FILE THE FIRST TIME///////////////////////////////////////////
    while(!readingstream.eof()){
        std::string line = extract_the_line(readingstream);
        Passenger* new_pass = extract_passenger(line);
        PassengerList* p1 = new PassengerList{*new_pass, nullptr}; // first passengerlist struct
        
        p1->next = a1.get_list()->flight.get_pass_listH();
        a1.get_list()->flight.set_pass_listH(p1);
        p1 = nullptr;
        delete new_pass;
        new_pass = nullptr;
    }
    //////////////////////////////////////FIRST SETUP////////////////////////////////
    a1.get_list()->flight.update_FSmap(); //updating the seat map with all info
    printfirstmessege();
    int runprogram = 1; //bool logic to eventually exit the program
    char selection;
    ////////////////////////////////////////////////////////////////////////////////////////////
    if(pressreturntocontinue()){
        printoptions();
        ///////////////////////////////////////////MAIN PROGRAM LOOP///////////////////////////////////////////
        while(runprogram){ 
            std::cin >> selection;
            if(selection == '1'){
                a1.get_list()->flight.update_FSmap();
                DisplaySeatMap(a1.get_list()->flight); 
                pressreturntocontinue();
                printoptions();

            }else if (selection == '2'){
              
              a1.get_list()->flight.DisplayPassInfo();
                pressreturntocontinue();
                printoptions();
            }
            else if (selection == '3')
            {
                (a1.get_list()->flight).addpassenger(); //Add new passenger
                (a1.get_list()->flight).update_FSmap(); // update map
                pressreturntocontinue();
                printoptions();            
            }
            else if (selection == '4')
            {   int removeinput;
                cout<<"Enter PassengerID of Passenger you wish to remove"<<endl;
                while (!(std::cin >> removeinput)){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter an integer: ";
                   }
                a1.get_list()->flight.RemovePassengerById(removeinput);
                pressreturntocontinue();
                printoptions();
            }else if (selection == '5')
            {
                std::cout<<"Do you want to save the data in the flight_info.txt? Please answer <Y or N>"<<std::endl;
                char ans;
                std::cin >> ans;
                if(ans == 'Y' || ans == 'y'){
                    std::ofstream writingstream("flight_info.txt"); //opens file for writing

                    FlightList* current_flight = a1.get_list();
                    writingstream << a1.get_name() << current_flight->flight.get_flight_id() <<setw(9) << current_flight->flight.get_number_of_rows() << setw(6)
                    <<current_flight->flight.get_number_of_columns()<<std::endl; // writes in the airline name, rows, cols

                    PassengerList* current_pass = f1->get_pass_listH();

                    if(current_pass == nullptr){
                        std::cout<<"No passengers to save in file."<<std::endl;
                    }
                    else{
                        while(current_pass != nullptr){  //continues to write in passengers until reaches end of linked list
                            std::string seat = std::to_string(current_pass->Pass.get_seat()->get_row()) + current_pass->Pass.get_seat()->get_column();
                            
                            writingstream << current_pass->Pass.get_Fname()<<setw(20)<<current_pass->Pass.get_Lname()<<setw(20)
                            << current_pass->Pass.get_phone()<<setw(20)<<seat<<setw(4)<<current_pass->Pass.get_pass_id()<<std::endl;
                            current_pass = current_pass->next;
                        }
                        std::cout<<"All the data in the passenger list was saved into flight_info.txt."<<std::endl;
                    }
                }
                else{
                    std::cout<<"New Data was not saved."<<std::endl;
                } 
                pressreturntocontinue();
                printoptions();               

            }else if (selection == '6')
            {
                runprogram = 0;
            }
            else
            {
                std::cout << "Invalid input, please enter a number between 1 and 6\n";
                continue;
            }
        }
        std::cout<<"Program Terminated"<<std::endl;
    }
}
