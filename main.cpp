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
    std::string line = extract_the_line(readingstream);
    

    printfirstmessege();

    int runprogram = 1; //bool logic to eventually exit the program
    char selection;
    std::string s = "booger";
    Flight f(24, 6, s, nullptr);

    if(pressreturntocontinue()){
        printoptions();

        while(runprogram){ ///MAIN PROGRAM LOOP///



            std::cin >> selection;
            if(selection == '1'){
                DisplaySeatMap(f);
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
