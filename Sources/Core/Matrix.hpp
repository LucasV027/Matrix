#pragma once

#include <assert.h>
#include <iostream>
#include <utility>

#include "MatrixIterator.hpp"

#define size_t long unsigned int

template <size_t rows, size_t cols, typename T>
class Matrix
{
public:
    using Iterator = MatrixIterator<Matrix<rows, cols, T>>;
    using ValueType = T;
    friend class MatrixIterator<Matrix<rows, cols, T>>;

public:
    Matrix()
    {
        matrix = new T *[rows];
        for (size_t i = 0; i < rows; i++)
            matrix[i] = new T[cols];
    }

    ~Matrix()
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    inline size_t Rows() const { return rows; }
    inline size_t Cols() const { return cols; }

    void Display() const
    {
        for (size_t y = 0; y < rows; ++y)
        {
            for (size_t x = 0; x < cols; ++x)
                std::cout << matrix[y][x] << " ";

            std::cout << "\n";
        }
    }

    void FillWithRandomValues()
    {
        for (auto it = begin(); it != end(); ++it)
        {
            *it = rand() % 1000;
        }
    }

    Iterator begin()
    {
        return Iterator(*this, 0, 0);
    }

    Iterator end()
    {
        return Iterator(*this, rows, 0);
    }

private:
    void SwapLines(size_t first, size_t second)
    {
        assert(first >= 0 && first < rows);
        assert(second >= 0 && second < rows);

        std::swap(matrix[first], matrix[second]);
    }

    void SwapCols(size_t first, size_t second)
    {
        assert(first >= 0 && first < cols);
        assert(second >= 0 && second < cols);

        for (size_t i = 0; i < cols; i++)
        {
            std::swap(matrix[i][first], matrix[i][second]);
        }
    }

private:
    T **matrix;
};
