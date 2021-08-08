#include "push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\0')
    {
        i++;
    }
return (i);
}

void ft_putstr(char *str)
{
    printf("%s", str);
    return;
    int i;

    i = 0;
    if (str == NULL)
        return;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_isdigit(int c)
{
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int neg;
    int i;
    int num;

    i = 0;
    neg = 1;
    num = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
        num = num * 10 + (str[i] - 48);
        i++;
    }
    return (num * neg);
}
