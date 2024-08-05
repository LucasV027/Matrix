#pragma once

#include <assert.h>
#include <iostream>
#include <utility>

#define size_t long unsigned int

template <size_t lines, size_t columns, typename T>
class Matrix
{
public:
    Matrix()
    {
        matrix = new T *[lines];
        for (size_t i = 0; i < lines; i++)
            matrix[i] = new T[columns];
    }

    ~Matrix()
    {
        for (size_t i = 0; i < lines; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void Display() const
    {
        for (size_t y = 0; y < lines; ++y)
        {
            for (size_t x = 0; x < columns; ++x)
                std::cout << matrix[y][x] << " ";

            std::cout << "\n";
        }
    }

private:
    void SwapLines(size_t first, size_t second)
    {
        assert(first >= 0 && first < lines);
        assert(second >= 0 && second < lines);

        std::swap(matrix[first], matrix[second]);
    }

    void SwapCols(size_t first, size_t second)
    {
        assert(first >= 0 && first < columns);
        assert(second >= 0 && second < columns);

        for (size_t i = 0; i < columns; i++)
        {
            std::swap(matrix[i][first], matrix[i][second]);
        }
    }

public:
    T **matrix;
};
