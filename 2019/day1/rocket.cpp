#include <iostream>



int main(void)
{
    int m;
    long sum;
    while (std::cin >> m)
    {
        sum += (m / 3) - 2;
    }
    std::cout << sum;

    return 0;
}
