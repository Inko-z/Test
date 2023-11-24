#include<vector>
#include <string>
#include <iostream>
#include "airline.h"

Airline::Airline(){
    airline_name = '\0';
    flight_list = nullptr;
    flight_num = 0;
}

Airline::Airline(std::string name, FlightList* list, int num){
    airline_name = name;
    flight_list = list; 
    flight_num = num;
}

Airline::Airline(const Airline& source){
    airline_name = source.airline_name;
    flight_num = source.flight_num;
    flight_list = nullptr;
    for(FlightList* p = source.flight_list; p!= nullptr;p = p -> next){
        insert(p -> Fname);
    }
}

Airline::~Airline(){
    while(flight_list != nullptr)
    {
        FlightList* p = flight_list;
        flight_list = flight_list -> next;
        delete p;
    }
}

void Airline::set_name(std::string Name){
    airline_name = Name;
}

void Airline::set_list(FlightList* List){
    flight_list = List;
}

void Airline::set_num(int n){
    flight_num = n;
}

const std::string Airline::get_name()const{
    return airline_name;
}

const FlightList* Airline::get_list()const{
    return flight_list;
}

const int Airline::get_num()const{
    return flight_num;
}

void Airline::insert(std::string& Name){
    FlightList* newflight = new FlightList;
    if(newflight == 0){
        std::cout<<"Error allocating space for a new flight"<< std::endl;
        exit(1);
    }
    newflight -> Fname = Name;
    newflight -> next = nullptr;

    FlightList * last = flight_list;

    if(flight_list == nullptr){
        flight_list = newflight;
        return;
    }

    while(last -> next != nullptr){
        last = last -> next;
    }
    last -> next = newflight;
}
