#include <exception>
#include <format>
#include <iostream>
#include <queue>
#include <string>

template <typename T> class PacketBuffer
{
  public:
    explicit PacketBuffer(size_t maxSize = 0);

    virtual ~PacketBuffer() = default;

    bool bufferPacket(T const &packet);

    [[nodiscard]] T getNextPacket();

  private:
    std::queue<T> m_packets;
    size_t m_maxSize;
};

class IPPacket final
{
  public:
    explicit IPPacket(int id) : m_id{id} {}
    int getID() const { return m_id; }

  private:
    int m_id{};
};

int main()
{
    PacketBuffer<IPPacket> ipPacket{3};

    for (int i{1}; i <= 4; ++i) {
        if (!ipPacket.bufferPacket(IPPacket{i})) {
            std::cout << std::format(
                "Packet {} dropped (because queue is full).\n", i);
        }
    }
    while (true) {
        try {
            IPPacket packet{ipPacket.getNextPacket()};
            std::cout << "Processing packet " << packet.getID() << std::endl;
        } catch (std::out_of_range const &e) {
            std::cout << "Queue is empty.\n" << e.what() << std::endl;
            break;
        }
    }
}

template <typename T> // default 값은 선언부에만
PacketBuffer<T>::PacketBuffer(size_t maxSize) : m_maxSize{maxSize}
{}

template <typename T> bool PacketBuffer<T>::bufferPacket(T const &packet)
{
    if (m_maxSize > 0 && m_packets.size() == m_maxSize) {
        // 더 이상 공간이 없으므로 패킷을 버린다.
        return false;
    }
    // 공간 존재
    m_packets.push(packet);
    return true;
}

template <typename T> T PacketBuffer<T>::getNextPacket()
{
    if (m_packets.empty()) {
        throw std::out_of_range{"Buffer is empty"};
    }
    T temp{m_packets.front()};
    m_packets.pop(); // void queue::pop();
    return temp;
}