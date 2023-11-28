#include<vector>
#include <string>
#include <iostream>
#include "airline.h"

Airline::Airline(){
    airline_name = '\0';
    flight_listH = nullptr;
    number_of_flights = 0;
}

Airline::Airline(std::string name, FlightList* list, int num){
    airline_name = name;
    flight_listH = list; 
    number_of_flights = num;
}

Airline::Airline(const Airline& source){
    airline_name = source.airline_name;
    number_of_flights = source.number_of_flights;
    flight_listH = nullptr;
    for(FlightList* p = source.flight_listH; p!= nullptr;p = p -> next){
        insert(p -> flight_id);
    }
}

Airline::~Airline(){
    while(flight_listH != nullptr)
    {
        FlightList* p = flight_listH;
        flight_listH = flight_listH -> next;
        delete p;
    }
}

void Airline::set_name(std::string Name){
    airline_name = Name;
}

void Airline::set_list(FlightList* List){
    flight_listH = List;
}

void Airline::set_num(int n){
    number_of_flights = n;
}

const std::string Airline::get_name()const{
    return airline_name;
}

const FlightList* Airline::get_list()const{
    return flight_listH;
}

const int Airline::get_num()const{
    return number_of_flights;
}

void Airline::insert(std::string& Name){
    FlightList* newflight = new FlightList;
    if(newflight == 0){
        std::cout<<"Error allocating space for a new flight"<< std::endl;
        std::exit(1);
    }
    newflight -> flight_id = Name;
    newflight -> next = nullptr;

    FlightList * last = flight_listH;

    if(flight_listH == nullptr){
        flight_listH = newflight;
        return;
    }

    while(last -> next != nullptr){
        last = last -> next;
    }
    last -> next = newflight;
}
