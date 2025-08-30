module;

#include <string>

export module airline_ticket_p5;

export class AirlineTicket {
  public:
    // 읽기 전용 함수들은 모두 const 멤버 함수로 변경
    double calculatePriceInDollars() const;
    const std::string &getPassengerName() const;
    int getNumberOfMiles() const;
    bool hasEliteSuperRewardsStatus() const;

    // Setter 함수들
    void setPassengerName(const std::string &name);
    void setNumberOfMiles(int miles); // int는 값으로 받는 것이 더 효율적
    void setHasEliteSuperRewardsStatus(bool status); // bool도 값으로 받음

  private:
    std::string m_passengerName{"Unknown Passenger"};
    int m_numberofMiles{};
    bool m_hasEliteSuperRewardsStatus{false};
};

double AirlineTicket::calculatePriceInDollars() const {
    if (hasEliteSuperRewardsStatus())
        return 0;
    return getNumberOfMiles() * 0.1;
}

const std::string &AirlineTicket::getPassengerName() const {
    return m_passengerName;
}

void AirlineTicket::setPassengerName(const std::string &name) {
    m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() const { return m_numberofMiles; }

void AirlineTicket::setNumberOfMiles(int miles) { m_numberofMiles = miles; }

bool AirlineTicket::hasEliteSuperRewardsStatus() const {
    return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status) {
    m_hasEliteSuperRewardsStatus = status;
}