module;

#include <cstddef>
#include <memory>
#include <vector>

export module GameBoard;

export class GamePiece
{
  public:
    virtual ~GamePiece() = default;
    virtual std::unique_ptr<GamePiece> clone() const = 0;
};

export class GameBoard
{
    using s = std::size_t;

  public:
    explicit GameBoard(s width = DefaultWidth, s height = DefaultHeight);
    GameBoard(GameBoard const &src);                 // 복제 생성자 1/5
    virtual ~GameBoard() = default;                  // 소멸자 2/5
    GameBoard &operator=(GameBoard const &rhs);      // 복데 대입연산자 3/5
    GameBoard(GameBoard &&src) = default;            // 이동 생성자 4/5
    GameBoard &operator=(GameBoard &&rhs) = default; // 이동 대입연산자 5/5

    std::unique_ptr<GamePiece> &at(s x, s y);
    std::unique_ptr<GamePiece> const &at(s x, s y) const;

    s getHeight() const { return m_height; }
    s getWidth() const { return m_width; }

    static s const DefaultWidth{10};
    static s const DefaultHeight{10};

    void swap(GameBoard &other) noexcept;

  private:
    void verifyCoordinate(s x, s y) const;

    std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
    s m_width{}, m_height{};
};

export void swap(GameBoard &first, GameBoard &second) noexcept;