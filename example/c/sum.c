#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return (a + b);
}

int main(int ac, char **av)
{
    if (ac != 3) return (fprintf(stderr, "usage %s : <number> <number>\n", av[0]), 1);

    int a = 0, b = 0;

    a = atoi(av[1]);
    b = atoi(av[2]);

    printf("Sum of %d + %d is %d\n", a, b, sum(a, b));
    return (0);
}
