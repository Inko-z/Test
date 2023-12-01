#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "airline.cpp"

void printfirstmessege();
void printreturnmessege();
void printoptions();
void printwronginput();

int main(){
    std::ifstream readingstream("flight_info.txt");
    std::ofstream writingstream("flight_info.txt");
    
    //read all data from file and turn it into objects, lists, ect. in the program
    // airline ptr
    std::string line = extract_the_line(readingstream);
    

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