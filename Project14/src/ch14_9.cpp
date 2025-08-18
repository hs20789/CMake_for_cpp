#include <exception>
#include <iostream>
#include <memory>
#include <string>

template <typename T> class Matrix
{
  public:
    Matrix(size_t width, size_t height);
    virtual ~Matrix();

  private:
    void cleanup();
    size_t m_width{};
    size_t m_height{};
    T **m_matrix{nullptr};
};

int main() {}

template <typename T> Matrix<T>::Matrix(size_t width, size_t height)
{
    m_matrix = new T *[width] {};

    m_width = width;
    m_height = height;

    try {
        for (size_t i{}; i < width; i++) {
            m_matrix[i] = new T[height];
        }
    } catch (...) {
        std::cerr << "Exception caught in ctor, cleaning up..." << std::endl;
        cleanup();
        std::throw_with_nested(std::bad_alloc{});
    }
}

template <typename T> Matrix<T>::~Matrix() { cleanup(); }

template <typename T> void Matrix<T>::cleanup()
{
    for (size_t i{}; i < m_width; i++) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
    m_matrix = nullptr;
    m_width = m_height = 0;
}