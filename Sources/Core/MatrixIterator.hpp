#pragma once

template <typename Matrix>
class MatrixIterator
{
public:
    using ValueType = typename Matrix::ValueType;

public:
    MatrixIterator(Matrix &matrix, size_t row, size_t col) : matrix(matrix), row(row), col(col) {}

    MatrixIterator &operator++()
    {
        if (col + 1 < matrix.Cols())
        {
            ++col;
        }
        else if (row + 1 < matrix.Rows())
        {
            ++row;
            col = 0;
        }
        else
        {
            row = matrix.Rows();
            col = 0;
        }
        return *this;
    }

    ValueType &operator*()
    {
        return matrix.matrix[row][col];
    }

    bool operator==(const MatrixIterator &other) const
    {
        return (row == other.row) && (col == other.col);
    }
    bool operator!=(const MatrixIterator &other) const
    {
        return !(*this == other);
    }

private:
    Matrix &matrix;
    size_t row;
    size_t col;
};