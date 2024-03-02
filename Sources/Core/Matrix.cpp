#include "Matrix.h"

Matrix::Matrix() : Matrix(2, 2) {}

Matrix::Matrix(int w, int h) : width(w), height(h)
{
    matrix = new int *[height];
    for (int i = 0; i < height; i++)
        matrix[i] = new int[width];
}

Matrix::~Matrix()
{
    for (int i = 0; i < height; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    for (int y = 0; y < m.height; ++y)
    {
        for (int x = 0; x < m.width; ++x)
        {
            os << m.matrix[y][x] << " ";
        }
        os << "\n";
    }
    return os;
}

void Matrix::FillWithRandomNumbers()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            matrix[y][x] = rand() % 100;
        }
    }
}

void Matrix::SwapLines(int first, int second)
{
    assert(first >= 0 && first < height);
    assert(second >= 0 && second < height);

    std::swap(matrix[first], matrix[second]);
}

void Matrix::SwapCols(int first, int second)
{
    assert(first >= 0 && first < width);
    assert(second >= 0 && second < width);

    for (int i = 0; i < width; i++)
    {
        std::swap(matrix[i][first], matrix[i][second]);
    }
}