#include <iostream>

int mass(int m) 
{
    int current = m;
    int total = 0;
    while ((current = ((current / 3) -2)) > 0)
    {
        total += current;
    }
    return total;
}

int main(void)
{
    int m;
    long sum;

    while (std::cin >> m)
    {
        sum += mass(m);
    }
    std::cout << sum;

    return 0;
}
