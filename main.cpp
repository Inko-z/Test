#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "airline.cpp"
#include "extraction.cpp"

void printfirstmessege();
void printreturnmessege();
void printoptions();
void printwronginput();

int main(){
    std::ifstream readingstream("flight_info.txt");
    std::ofstream writingstream("flight_info.txt");
    
    //read all data from file and turn it into objects, lists, ect. in the program
    // airline ptr
    std::string line = extract_the_line(readingstream); // reads first line

    Airline a1 = extract_airline(line); //makes airline object based on first line
    Flight* f1 = extract_flight(line); //makes flight object on the heap based on first line

    FlightList* fl1 = new FlightList; //first flightlist struct 
    fl1->next = nullptr;
    fl1->flight_id = f1->get_flight_id();
    a1.set_list(fl1); // sets first flightlist struct as head of list
    
    while(!readingstream.eof()){
        std::string line = extract_the_line(readingstream);
        Passenger* new_pass = extract_passenger(line);
        PassengerList* p1 = new PassengerList; // first passengerlist struct
        
        p1->next = f1->get_pass_listH();
        f1->set_pass_listH(p1);
    }
    

    printfirstmessege();
    printreturnmessege();
    char returnchar;
    std::cin >> returnchar;

    if(returnchar == '\r'){

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