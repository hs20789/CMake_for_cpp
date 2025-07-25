module;
#include <string>;
export module airline_ticket;

export class AirlineTicket {
  public:
    double calculatePriceInDollars() {
        if (hasEliteSuperRewardsStatus())
            return 0;
        return getNumberOfMiles() * 0.1; // 마일당 0.1달러
    }
    void setPassengerName(std::string name) { m_passengerName = name; }
    std::string getPassengerName() { return m_passengerName; }

    int getNumberOfMiles() { return m_numberofMiles; }
    void setNumberOfMiles(int miles) { m_numberofMiles = miles; }

    bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status) {
        m_hasEliteSuperRewardsStatus = status;
    }

    // 클래스의 데이터 멤버 이름앞에 'm_' 접두사를 붙이는 것이 일반적입니다.
    // 이는 멤버 변수를 나타내는 관례로, 코드의 가독성을 높입니다.
  private:
    std::string m_passengerName{"Unknown Passenger"};
    int m_numberofMiles{};
    bool m_hasEliteSuperRewardsStatus{false};
};
