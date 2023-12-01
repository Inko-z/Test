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


Airline::Airline(const Airline& source) {
    // Copy the airline name and the number of flights
    airline_name = source.airline_name;
    number_of_flights = source.number_of_flights;

    // Copy the linked list of flights
    if (source.flight_listH != nullptr) {
        FlightList* sourceFlightNode = source.flight_listH;
        flight_listH = new FlightList{ sourceFlightNode->flight, nullptr };

        FlightList* currentCopyFlightNode = flight_listH;

        // Iterate through the source flight list
        while (sourceFlightNode->next != nullptr) {
            sourceFlightNode = sourceFlightNode->next;

            // Copy each flight node
            currentCopyFlightNode->next = new FlightList{ sourceFlightNode->flight, nullptr };
            currentCopyFlightNode = currentCopyFlightNode->next;
        }
    } else {
        flight_listH = nullptr;
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

int Airline::get_num()const{
    return number_of_flights;
}

void Airline::insert(Flight* flight){
    FlightList* new_flight = new FlightList{*flight, nullptr};
    new_flight->next = flight_listH;
    flight_listH = new_flight;
}