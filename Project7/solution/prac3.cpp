// 연습문제 7-3
// 3D 좌표 (x, y, z)를 저장하는 클래스를 정의하자. 이때 x, y, z 인술르 받는
// 생성자를 정의한다. 또한, 3D 좌표를 받아서 std::format() 으로 좌표를 출력하는
// 함수도 만든다. main() 함수에서 이 클래스의 인스턴스를 동적으로 할당한 뒤
// 정의한 함수를 호출해보자.

#include <format>
#include <iostream>
#include <memory>

class TriDimension
{
  public:
    TriDimension() = default;
    TriDimension(double x_, double y_, double z_)
        : m_xValue{x_}, m_yValue{y_}, m_zValue{z_}
    {}
    void getDimensionValue()
    {
        std::cout << std::format("x: {}, y: {}, z: {}\n", m_xValue, m_yValue,
                                 m_zValue);
    }

  private:
    double m_xValue{};
    double m_yValue{};
    double m_zValue{};
};

//// 1. new /delete
// int main()
// {
//     TriDimension *triPtr{new TriDimension{3, 5, 1}};
//     triPtr->getDimensionValue();
//     delete triPtr;
//     triPtr = nullptr;
// }

//// 2. std::unique_ptr
// int main()
// {
//     std::unique_ptr<TriDimension> triPtr{new TriDimension{1, 2, 3}};
//     triPtr->getDimensionValue();
// }

// 3. std::make_unique
int main()
{
    auto triPtr = std::make_unique<TriDimension>(1, 2, 3);
    triPtr->getDimensionValue();
}

