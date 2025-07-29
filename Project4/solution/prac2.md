## Q. 다음과 같이 정의된 Card 클래스가 있다고 하자. 이 클래스는 카드 덱에 있는 정상 카드만 지원하고, 조커 카드는 지원하지 않는다.

```
class Card
{
    public:
        enum class Number { Ace, Two, Three, Foue, FIve, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
        enum class Figure { Diamonde, Heart, Spade, Club };

        Card() {};
        Card(Number number, Figure figure)
            : m_number {number}, m_figure {figure} {}
        
        private:
            Number m_number {number::Ace};
            Figure m_figure {Figure::Diamonde};
}
```

## 이렇게 정의한 Card 클래스를 카드 한 벌을 표현하기 위해 다음과 같이 사용하는 것은 어떨까? 좀 더 개선할 방법은?

```
int main()
{
    Card deck[52];
}
```


---

## Solution.

##### 먼져 `Card deck[52];` 와 같은 방식으로 카드 한 벌을 표현하면 안된다. 왜냐하면, 저런 방식으로 카드의 형식을 지정하지 않고<br>카드 한 벌을 표현하면 Card 클래스의 기본값인 Ace, Diamonde 카드만 52개 생성되기 떄문이다.

##### Card 클래스와 Deck 클래스를 구분해서 만들면 개선이 가능하다.

```
class Card
{
    public:
        enum class Number { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
        enum class Figure { Diamonde, Heart, Spade, Club };

        Card() {};
        Card(Number number, Figure figure)
            : m_number {number}, m_figure {figure} {}
        
        private:
            Number m_number {number::Ace};
            Figure m_figure {Figure::Diamonde};
}

#inlcude <vector>

class Deck
{
    public:
        Deck() {
            for (int num=static_cast<int>(Card::Number::Ace); 
                num<=static_cast<int(card::Number::King)>; num++){
                    for (int fig=static_cast<int>(Card::Figure::Diamonde);
                        fig<=static_cast<int>(Card::Figure::Club); fig++){
                            m_cards.emplace_back(static_cast<Card::Number>(num),
                                                static_cast<Card::Figure>(fig));
                        }
                }
        }
    private:
        std::vector<Card> m_cards{};
}
```


```
//// A better approach is to wrap a deck of cards in a class, which enforces any
//// invariants, and which can include additional functionality such as shuffling a deck.

import <vector>;

class Deck
{
public:
	Deck() { /* Initialize a valid deck of cards... */ }
	
	// Retrieves the card with given index.
	// Throws std::out_of_range if index is an invalid index.
	const Card& getCard(size_t index) const { /* Validate index and return the card with given index... */ }

	// Shuffles the deck of cards.
	void shuffle() { /* Shuffle the deck... */ }

	// More methods ...

private:
	std::vector<Card> m_deck;
};
```