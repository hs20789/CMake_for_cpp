module;
#include <string>;
export module airline_ticket;

export class AirlineTicket {
  public:
    double calculatePriceInDollars() {
        if (hasEliteSuperRewardsStatus())
            return 0;
        return getNumberOfMiles() * 0.1; // ���ϴ� 0.1�޷�
    }
    void setPassengerName(std::string name) { m_passengerName = name; }
    std::string getPassengerName() { return m_passengerName; }

    int getNumberOfMiles() { return m_numberofMiles; }
    void setNumberOfMiles(int miles) { m_numberofMiles = miles; }

    bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status) {
        m_hasEliteSuperRewardsStatus = status;
    }

    // Ŭ������ ������ ��� �̸��տ� 'm_' ���λ縦 ���̴� ���� �Ϲ����Դϴ�.
    // �̴� ��� ������ ��Ÿ���� ���ʷ�, �ڵ��� �������� ���Դϴ�.
  private:
    std::string m_passengerName{"Unknown Passenger"};
    int m_numberofMiles{};
    bool m_hasEliteSuperRewardsStatus{false};
};
