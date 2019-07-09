### matrix.h
```c++
#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

template <class T>
class matrix
{
private:
    std::vector<std::vector<T>> array;
    int height;
    int width;

public:
    // constuctors
    matrix<T>(int height, int width);
    matrix<T>(std::vector<std::vector<T>> const &array);
    matrix<T>(std::initializer_list<std::initializer_list<T>> const &ll);
    matrix<T>();

    // utility methods
    int getHeight() const;
    int getWidth() const;

    matrix<T> applyFunction(T (*function)(T)) const;
    matrix<T> subMat(int startH, int startW, int h, int w) const;

    void fill(const T &value);
    void put(int h, int w, const T &value);
    T get(int h, int w) const;

    void print(std::ostream &flux) const;

    // operators helpers
    matrix<T> add(const matrix<T> &m) const;
    matrix<T> subtract(const matrix<T> &m) const;
    matrix<T> multiply(const matrix<T> &m) const;
    matrix<T> dot(const matrix<T> &m) const;
    matrix<T> transpose() const;
    matrix<T> multiply(const T &value) const;
    matrix<T> divide(const T &value) const;

    // operators
    bool operator==(const matrix<T> &m);
    bool operator!=(const matrix<T> &m);
    matrix<T> operator+=(const matrix<T> &m);
    matrix<T> operator-=(const matrix<T> &m);
    matrix<T> operator*=(const matrix<T> &m);
    matrix<T> operator*=(const T &m);
    matrix<T> operator/=(const T &m);
    T &operator()(int y, int x);
};

template <class T>
matrix<T> operator+(const matrix<T> &a, const matrix<T> &b);
template <class T>
matrix<T> operator-(const matrix<T> &a, const matrix<T> &b);
template <class T>
matrix<T> operator*(const matrix<T> &a, const matrix<T> &b);
template <class T>
matrix<T> operator*(const T &b, const matrix<T> &a);
template <class T>
matrix<T> operator/(const matrix<T> &a, const T &b);
template <class T>
std::ostream &operator<<(std::ostream &flux, const matrix<T> &m);

template <class T>
matrix<T>::matrix(int height, int width)
{
    this->height = height;
    this->width = width;
    this->array = std::vector<std::vector<T>>(height, std::vector<T>(width));
}

template <class T>
matrix<T>::matrix(std::vector<std::vector<T>> const &array)
{
    if (array.size() == 0)
        throw std::invalid_argument("Size of array must be greater than 0.");

    this->height = array.size();
    this->width = array[0].size();
    this->array = array;
}

template <class T>
matrix<T>::matrix(std::initializer_list<std::initializer_list<T>> const &ll)
{
    if (ll.size() == 0)
        throw std::invalid_argument("Size of array must be greater than 0.");

    this->height = ll.size();
    this->width = (*ll.begin()).size();

    for_each(begin(ll), end(ll), [this](auto &l) {
        array.push_back(l);
    });
}

template <class T>
matrix<T>::matrix()
{
    height = 0;
    width = 0;
}

template <class T>
int matrix<T>::getHeight() const
{
    return height;
}

template <class T>
int matrix<T>::getWidth() const
{
    return width;
}

template <class T>
void matrix<T>::fill(const T &value)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            array[i][j] = value;
        }
    }
}

template <class T>
void matrix<T>::put(int h, int w, const T &value)
{
    if (!(h >= 0 && h < height && w >= 0 && w < width))
        throw std::invalid_argument("Index out of bounds.");

    array[h][w] = value;
}

template <class T>
T matrix<T>::get(int h, int w) const
{
    if (!(h >= 0 && h < height && w >= 0 && w < width))
        throw std::invalid_argument("Index out of bounds.");

    return array[h][w];
}

template <class T>
matrix<T> matrix<T>::multiply(const T &value) const
{
    matrix result(array);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] *= value;
        }
    }

    return result;
}

template <class T>
matrix<T> matrix<T>::divide(const T &value) const
{
    matrix result(array);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] /= value;
        }
    }

    return result;
}

template <class T>
matrix<T> matrix<T>::add(const matrix &m) const
{
    if (!(height == m.height && width == m.width))
        throw std::invalid_argument("matrix dimension must be the same.");

    matrix result(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] = array[i][j] + m.array[i][j];
        }
    }

    return result;
}

template <class T>
matrix<T> matrix<T>::subtract(const matrix &m) const
{
    if (!(height == m.height && width == m.width))
        throw std::invalid_argument("matrix dimension must be the same.");

    matrix result(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] = array[i][j] - m.array[i][j];
        }
    }
    return result;
}

template <class T>
matrix<T> matrix<T>::multiply(const matrix &m) const
{
    if (!(height == m.height && width == m.width))
        throw std::invalid_argument("matrix dimension must be the same.");

    matrix result(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] = array[i][j] * m.array[i][j];
        }
    }
    return result;
}

template <class T>
matrix<T> matrix<T>::dot(const matrix &m) const
{
    if (!(width == m.height))
        throw std::invalid_argument("Dot product not compatible.");

    T w = 0;
    int mwidth = m.width;

    matrix<T> result(height, mwidth);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mwidth; j++)
        {
            for (int h = 0; h < width; h++)
            {
                w += array[i][h] * m.array[h][j];
            }
            result.array[i][j] = w;
            w = 0;
        }
    }

    return result;
}

template <class T>
matrix<T> matrix<T>::transpose() const
{
    matrix<T> result(width, height);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            result.array[i][j] = array[j][i];
        }
    }
    return result;
}

template <class T>
matrix<T> matrix<T>::applyFunction(T (*function)(T)) const
{
    matrix<T> result(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.array[i][j] = (*function)(array[i][j]);
        }
    }

    return result;
}

template <class T>
matrix<T> matrix<T>::subMat(int startH, int startW, int h, int w) const
{
    if (!(startH >= 0 && startH + h <= height && startW >= 0 && startW + w <= width))
        throw std::invalid_argument("Index out of bounds");

    matrix<T> result(h, w);
    for (int i = startH; i < startH + h; i++)
    {
        for (int j = startW; j < startW + w; j++)
        {
            result.array[i - startH][j - startW] = array[i][j];
        }
    }
    return result;
}

template <class T>
void matrix<T>::print(std::ostream &flux) const
{
    int maxLength[width] = {};
    std::stringstream ss;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ss << array[i][j];
            if (maxLength[j] < ss.str().size())
            {
                maxLength[j] = ss.str().size();
            }
            ss.str(std::string());
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            flux << array[i][j];
            ss << array[i][j];
            for (int k = 0; k < maxLength[j] - ss.str().size() + 1; k++)
            {
                flux << " ";
            }
            ss.str(std::string());
        }
        flux << std::endl;
    }
}

template <class T>
bool matrix<T>::operator==(const matrix &m)
{
    if (height == m.height && width == m.width)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (array[i][j] != m.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <class T>
bool matrix<T>::operator!=(const matrix &m)
{
    return !operator==(m);
}

template <class T>
matrix<T> matrix<T>::operator+=(const matrix &m)
{
    this->array = add(m).array;
    return *this;
}

template <class T>
matrix<T> matrix<T>::operator-=(const matrix &m)
{
    this->array = subtract(m).array;
    return *this;
}

template <class T>
matrix<T> matrix<T>::operator*=(const matrix &m)
{
    this->array = multiply(m).array;
    return *this;
}

template <class T>
matrix<T> matrix<T>::operator*=(const T &m)
{
    *this = this->multiply(m);
    return *this;
}

template <class T>
matrix<T> matrix<T>::operator/=(const T &m)
{
    *this = this->divide(m);
    return *this;
}

template <class T>
T &matrix<T>::operator()(int y, int x)
{
    if (!(y >= 0 && y < height && x >= 0 && x < width))
        throw std::invalid_argument("Index out of bounds.");
    return array[y][x];
}

template <class T>
matrix<T> operator+(const matrix<T> &a, const matrix<T> &b)
{
    return a.add(b);
}

template <class T>
matrix<T> operator-(const matrix<T> &a, const matrix<T> &b)
{
    return a.subtract(b);
}

template <class T>
matrix<T> operator*(const matrix<T> &a, const matrix<T> &b)
{
    return a.multiply(b);
}

template <class T>
matrix<T> operator*(const T &b, const matrix<T> &a)
{
    return a.multiply(b);
}
template <class T>
matrix<T> operator/(const matrix<T> &a, const T &b)
{
    return a.divide(b);
}

template <class T>
std::ostream &operator<<(std::ostream &flux, const matrix<T> &m)
{
    m.print(flux);
    return flux;
}
```

# Usage

```c++
#include "matrix.h"
...

// Constructors :
matrix<type_of_variable> matrix(int height, int width);
matrix<type_of_variable> matrix(vector<vector<type_of_variable> > &array);
matrix<T>(std::initializer_list<std::initializer_list<T>> const &ll);
matrix<type_of_variable> matrix();
```

# Operators

```c++
matrix<int> a,b,c;
int z;

c = a + b;
c = a - b;
c = a * b;
c = z * a;
c = a / z;
```

# Example

```c++
matrix<int> A(4,5);
matrix<int> B(4,5);
matrix<int> C(5,6);
matrix<int> X{
              {1, 1}, 
              {1, 0}
              };

matrix<int> D = A + B;  // = A.add(B)
matrix<int> D = A - B;  // = A.subtract(B)
matrix<int> D = A * B;  // = A.multiply(B)
matrix<int> D = B.dot(C);
matrix<int> D = A.transpose();
matrix<int> D = A.submatrix(0,0, 2,2); // get a sub matrix of size 2x2 from coordinates 0;0 in A

A += B;
A -= B;
A *= B;

int multiplyByTwo(int x){
    return 2*x;
}

matrix<int> D = A.applyFunction(multiplyByTwo);

// you can combine operations :

matrix<int> D = (A+B).dot(C).applyFunction(multiplyByTwo);

std::cout << D << std::endl;
```
