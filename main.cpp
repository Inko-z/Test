#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "airline.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "extraction.cpp"

void printfirstmessege();
void printreturnmessege();
void printoptions();
void printwronginput();

int main(){
    
    std::ifstream readingstream("flight_info.txt");
    
    //read all data from file and turn it into objects, lists, ect. in the program
    // airline ptr
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
    }
    

    printfirstmessege();
    printreturnmessege();
    char returnchar = std::cin.get();
    int runprogram = 1; //bool logic to eventually exit the program
    int selection;

    if(returnchar == '\n'){
        while(runprogram){ ///MAIN PROGRAM LOOP///
    
            printoptions();
            std::cin >> selection;

            if(selection == 1){

            }else if (selection == 2)
            {

            }
            else if (selection == 3)
            {

            }
            else if (selection == 4)
            {

            }else if (selection == 5)
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
                            std::string seat = std::to_string(current_pass->Pass.get_seat().get_row()) + current_pass->Pass.get_seat().get_column();

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
            }else if (selection == 6)
            {
                runprogram = 0;
            }
            else
            {
                
            }


        }
    }
    
    while(1){
        std::cin >> returnchar;
        if(returnchar == '1'){

        }
        if(returnchar == '2'){
            
        }
        if(returnchar == '3'){
            
        }
        if(returnchar == '4'){
            
        }
        if(returnchar == '5'){
            
        }
        if(returnchar == '6'){
            std::cout<<"\nProgram Terminated"<<std::endl;
            break;
        }
    }
}
void printfirstmessege(){
    std::cout << "Version: 1.0\n";
    std::cout << "Term Project - Flight Management Programm in C++\n";
    std::cout << "Produced by: Rodolfo Gil-Pereira, Anastasia Zaharia, Sebastian Nieto\n";
}
void printreturnmessege(){
    std::cout <<"<<< Press Return to Continue >>>\n";
    std::cout <<"(anything else will end the program)\n";
}
void printoptions(){
    std::cout << "Please select one of the following functions:\n";
    std::cout << "1.  Display Flight Seat Map.\n";
    std::cout << "2.  Display Passengers Information.\n";
    std::cout << "3.  Add a New Passenger.\n";
    std::cout << "4.  Remove an Existing Passenger.\n";
    std::cout << "5.  Save data.\n";
    std::cout << "6.  Quit.\n\n";
    std::cout << "Enter your choice: (1, 2, 3, 4, 5 or 6\n";
}
void printwronginput(){
    std::cout << "Invalid input, please try again: \n";
}