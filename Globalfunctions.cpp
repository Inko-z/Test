#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "airline.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "Globalfunctions.h"


int pressreturntocontinue(){
    std::cout <<"<<< Press Return to Continue >>>\n";
    char returnchar;
    std::cin >> returnchar;
    return 1;
}
