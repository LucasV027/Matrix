#include <iostream>

#include "Core/Matrix.h"

int main(void)
{
    Matrix m(5, 5);
    m.FillWithRandomNumbers();
    std::cout << m << "\n";
    m.SwapCols(0, 4);
    std::cout << m;
    return 0;
}