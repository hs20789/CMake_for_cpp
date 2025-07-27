#include <iostream>

import airline_ticket_p5;

int main() {

    AirlineTicket myTicket;
    myTicket.setPassengerName("HeonSu Jeong");
    myTicket.setNumberOfMiles(98'342'122);
    double cost{myTicket.calculatePriceInDollars()};
    std::string myName = myTicket.getPassengerName();
    std::cout << std::format("This ticket for {}\nPrice: {:.3f}\n", myName,
                             cost);
//..
}