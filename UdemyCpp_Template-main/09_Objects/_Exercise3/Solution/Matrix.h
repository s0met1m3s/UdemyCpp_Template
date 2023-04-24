#pragma once

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(const T &A, const T &B, const T &C, const T &D);
    ~Matrix() = default;

    // Exercise 1: Copy Constructor
    Matrix(const Matrix &other);
    // Exercise 2: Copy Assignment Operator
    Matrix &operator=(const Matrix &other);

    Matrix operator+(const Matrix &rhs) const;
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs) const;
    Matrix &operator-=(const Matrix &rhs);

    Matrix operator*(const T &scalar) const;
    Matrix &operator*=(const T &scalar);
    Matrix operator/(const T &scalar) const;
    Matrix &operator/=(const T &scalar);

    void print_matrix() const;

    T get_A() const;
    T get_B() const;
    T get_C() const;
    T get_D() const;

    void set_A(const T &new_A);
    void set_B(const T &new_B);
    void set_C(const T &new_C);
    void set_D(const T &new_D);

private:
    T m_A;
    T m_B;
    T m_C;
    T m_D;
};

template <typename T>
Matrix<T>::Matrix() : m_A(0.0), m_B(0.0), m_C(0.0), m_D(0.0)
{
}

template <typename T>
Matrix<T>::Matrix(const T &A, const T &B, const T &C, const T &D)
    : m_A(A), m_B(B), m_C(C), m_D(D)
{
}

// Copy Constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other)
    : m_A(other.m_A), m_B(other.m_B), m_C(other.m_C), m_D(other.m_D)
{
}

// Copy Assignment Operator
template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other)
{
    this->m_A = other.m_A;
    this->m_B = other.m_B;
    this->m_C = other.m_C;
    this->m_D = other.m_D;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    auto result = Matrix{};

    result.set_A(this->get_A() + rhs.get_A());
    result.set_B(this->get_B() + rhs.get_B());
    result.set_C(this->get_C() + rhs.get_C());
    result.set_D(this->get_D() + rhs.get_D());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    this->set_A(this->get_A() + rhs.get_A());
    this->set_B(this->get_B() + rhs.get_B());
    this->set_C(this->get_C() + rhs.get_C());
    this->set_D(this->get_D() + rhs.get_D());

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    auto result = Matrix{};

    result.set_A(this->get_A() - rhs.get_A());
    result.set_B(this->get_B() - rhs.get_B());
    result.set_C(this->get_C() - rhs.get_C());
    result.set_D(this->get_D() - rhs.get_D());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    this->set_A(this->get_A() - rhs.get_A());
    this->set_B(this->get_B() - rhs.get_B());
    this->set_C(this->get_C() - rhs.get_C());
    this->set_D(this->get_D() - rhs.get_D());

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const
{
    auto result = Matrix{};

    result.set_A(get_A() * scalar);
    result.set_B(get_B() * scalar);
    result.set_C(get_C() * scalar);
    result.set_D(get_D() * scalar);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    this->set_A(this->get_A() * scalar);
    this->set_B(this->get_B() * scalar);
    this->set_C(this->get_C() * scalar);
    this->set_D(this->get_D() * scalar);

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const
{
    auto result = Matrix{};

    result.set_A(get_A() / scalar);
    result.set_B(get_B() / scalar);
    result.set_C(get_C() / scalar);
    result.set_D(get_D() / scalar);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
    this->set_A(this->get_A() / scalar);
    this->set_B(this->get_B() / scalar);
    this->set_C(this->get_C() / scalar);
    this->set_D(this->get_D() / scalar);

    return *this;
}

template <typename T>
void Matrix<T>::print_matrix() const
{
    std::cout << m_A << " " << m_B << '\n';
    std::cout << m_C << " " << m_D << "\n\n";
}

template <typename T>
T Matrix<T>::get_A() const
{
    return m_A;
}

template <typename T>
T Matrix<T>::get_B() const
{
    return m_B;
}

template <typename T>
T Matrix<T>::get_C() const
{
    return m_C;
}

template <typename T>
T Matrix<T>::get_D() const
{
    return m_D;
}

template <typename T>
void Matrix<T>::set_A(const T &new_A)
{
    m_A = new_A;
}

template <typename T>
void Matrix<T>::set_B(const T &new_B)
{
    m_B = new_B;
}

template <typename T>
void Matrix<T>::set_C(const T &new_C)
{
    m_C = new_C;
}

template <typename T>
void Matrix<T>::set_D(const T &new_D)
{
    m_D = new_D;
}
