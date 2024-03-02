#pragma once

#include <iostream>
#include <assert.h>
class Matrix
{
public:
    Matrix();
    Matrix(int w, int h);
    ~Matrix();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

    void FillWithRandomNumbers();

public:
    void SwapLines(int first, int second);
    void SwapCols(int first, int second);

private:
    int **matrix;
    int height;
    int width;
};
