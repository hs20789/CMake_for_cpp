//
//
// Frequent Flyer Number(상용 고객 우대 프로그램)
// - 항공사들이 단골 고객을 확보하기 위해 운영하는 마일리지
// - 기반의 로열티 프로그램이다.
// - 1. 고객이 이 프로그램에 가입하면 고유한 회원 번호(Frequent Flyer Number)
//       가 부여된다.
// - 2. 비행기를 탈 때마다 이 번호를 등록하면, 비행 거리에 따라 마일리지를 적힙
// - 3. 적립된 마일리지로 혜택을 받을 수 있다.
//
//
module;

#include <optional>
#include <string>

export module airline_ticket_p6;

export class AirlineTicket {
  public:
    // 읽기 전용 함수들은 모두 const 멤버 함수로 변경
    double calculatePriceInDollars() const;
    const std::string &getPassengerName() const;
    int getNumberOfMiles() const;
    bool hasEliteSuperRewardsStatus() const;
    std::optional<int> getFrequentFlyerNumber() const;

    // Setter 함수들
    void setPassengerName(const std::string &name);
    void setNumberOfMiles(int miles); // int는 값으로 받는 것이 더 효율적
    void setHasEliteSuperRewardsStatus(bool status); // bool도 값으로 받음
    void setFrequentFlyerNumber(int number);

  private:
    std::string m_passengerName{"Unknown Passenger"};
    int m_numberofMiles{};
    bool m_hasEliteSuperRewardsStatus{false};
    std::optional<int> m_frequentFlyerNumber;

}; // End of AirlineTicket class declaration

// Start of AirlineTicket class definition
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
std::optional<int> AirlineTicket::getFrequentFlyerNumber() const {
    return m_frequentFlyerNumber;
}
void AirlineTicket::setFrequentFlyerNumber(int number) {
    m_frequentFlyerNumber = number;
}

// End of AirlineTicket class definition
