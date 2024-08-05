#include "Core/Matrix.hpp"

int main(void)
{
    Matrix<8, 8, int> matrix;
    matrix.Display();

    std::cout << "Iterator :\n";

    for (auto it = matrix.begin(); it != matrix.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    matrix.FillWithRandomValues();

    for (const auto e : matrix)
        std::cout << e << " ";

    std::cout << std::endl;

    return 0;
}