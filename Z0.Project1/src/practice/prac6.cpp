#include <iostream>

import airline_ticket_p6;

using namespace std;

int main() {
    AirlineTicket myTicket; // Stack-based AirlineTicket
    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    //myTicket.setFrequentFlyerNumber(123'456);
    const double cost{myTicket.calculatePriceInDollars()};
    cout << format("This ticket will cost ${}", cost) << endl;

    const auto frequentFlyerNumber{myTicket.getFrequentFlyerNumber()};
    if (frequentFlyerNumber) {
        cout << format("Frequent flyer number: {}", frequentFlyerNumber.value())
             << endl;
    } else {
        cout << "No frequent flyer number." << endl;
        cout << "If you want Frequent Flyer Number. Please subscribe our Elite "
                "Super Rewards Program.\n";
        cout << "link is: [ https://github.com/hs20789 ]\n";
    }
}