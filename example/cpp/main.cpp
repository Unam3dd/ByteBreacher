#include <cstdlib>
#include <iostream>

int sum(int a, int b)
{
    return (a + b);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "usage " << av[0] << ": <number> <number> " << std::endl;
        return (1);
    }

    auto a = 0, b = 0;

    a = std::strtol(av[1], NULL, 10);
    b = std::strtol(av[2], NULL, 10);

    std::cout << "The sum of " << a << " + " << b << " is " << sum(a, b) << "." << std::endl;

    return (0);
}
