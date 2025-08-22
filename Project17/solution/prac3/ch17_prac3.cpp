#include <format>
#include <iostream>
#include <iterator>
#include <numeric> // std::accumulate
#include <ranges>
#include <string>
#include <utility>
#include <vector>

template <std::ranges::input_range R> auto sum(R &&r)
{
    return std::accumulate(std::ranges::begin(r), std::ranges::end(r),
                           typename std::ranges::range_value_t<R>{});
}

template <typename InputIter, typename OuputIter>
void myCopy(InputIter begin, InputIter end, OuputIter target)
{
    for (auto iter{begin}; iter != end; ++iter) {
        *target = *iter;
    }
}

class Person
{
  public:
    Person(std::string first, std::string last)
        : m_firstName{std::move(first)}, m_lastName{std::move(last)}
    {}
    std::string const &getFirstName() const { return m_firstName; }
    std::string const &getLastName() const { return m_lastName; }

  private:
    std::string m_firstName;
    std::string m_lastName;
};

std::ostream &operator<<(std::ostream &os, Person const &person)
{
    os << person.getFirstName() << " " << person.getLastName();
    return os;
}

int main()
{
    //
    //
    std::vector persons{std::pair{Person{"Izzie", "Fellows"}, 11},
                        std::pair{Person{"Eshaan", "Cooper"}, 15},
                        std::pair{Person{"Rick", "Crouch"}, 48},
                        std::pair{Person{"Faye", "Pittman"}, 35},
                        std::pair{Person{"Jude", "Bone"}, 69},
                        std::pair{Person{"Ella-Louise", "Byers"}, 60},
                        std::pair{Person{"Jad", "Lott"}, 75},
                        std::pair{Person{"Teddie", "Love"}, 24},
                        std::pair{Person{"Niko", "Silva"}, 16},
                        std::pair{Person{"Bryan", "Melendez"}, 42},
                        std::pair{Person{"Jeong", "HeonSu"}, 25}};

    auto filterdAges =
        persons | std::views::values | std::views::filter([](auto const &age) {
            return age >= 12 && age <= 65;
        });
    //
    //

    {
        auto fourPersons = std::views::common(
            persons | std::views::keys | std::views::take(4) |
            std::views::transform(
                [](auto const &person) { return person.getLastName(); }));
        myCopy(std::begin(fourPersons), std::end(fourPersons),
               std::ostream_iterator<std::string>{std::cout, "\n"});
    }

    {
        auto fourPersons = std::views::common(persons | std::views::keys |
                                              std::views::take(4));
        myCopy(std::begin(fourPersons), std::end(fourPersons),
               std::ostream_iterator<Person>{std::cout, "\n"});
    }
}