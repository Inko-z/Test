//here the extraction functions will be created
//The functions to extract info from the .txt file
#include "airline.cpp"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string extract_the_line(ifstream stream){
    //returns a string of the line the stream pointer is pointing to
    //then makes the file ptr go to next line
}
Airline extract_airline(string flight_info_line){
    //take string extracted form get_line_line() and extracts airline info 
    //put info extracted from said airline into new airline object
    //returns an airline object
}
Flight* extract_flight(string flight_info_line){
     //take string extracted form get_line_line() and extracts flight info and creates airline object on the heap
     //put info into said flight object
     //return address of object
}
Passenger* extract_passenger(string passenger_info_line){
    //take string extracted form get_line_line() and extracts passenger info and creates passenger object on the heap
    //put info into passenger 
}
