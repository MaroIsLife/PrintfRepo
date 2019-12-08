#include "printf.h"

int print_s(va_list args, int *i ,const char *num)
{
    char *s;
    int c;
    int k;

    s = va_arg(args,char *);
    if (s == NULL)
    {
        c = ft_putstr("(null)");
    }
    else
    c = ft_putstr(s);
    k = *i;
    *i = *i + 1 + mcounter2(num,k + 1) + zcounter2(num,k + 1);
    return (c);
}

int print_d(va_list args, int *i ,const char *num)
{
    int s;
    int c;
    int k;

    k = *i;
    s = va_arg(args,int);
    c = ft_putnbr(s);
    *i = *i + 1 + mcounter2(num,k + 1) + zcounter2(num,k + 1);
    return (c);
}

int print_c(va_list args, int *i,const char *num) // ADD NUM to others
{
    int s;
    int c;
    int k;

    k = *i;
    s = va_arg(args,int);
    ft_putchar(s);
    c = 1;
    *i = *i + 1 + mcounter2(num,k + 1) + zcounter2(num,k + 1); // ADD TO OTHERS MCOUNTER
    return (c);
}

int print_u(va_list args, int *i ,const char *num)
{
    unsigned int s;
    int c;
    int k;

    k = *i;
    s = va_arg(args,unsigned int);
    c = ft_putunsigned(s);
    *i = *i + 1 + mcounter2(num,k + 1) + zcounter2(num,k + 1);
    return (c);
}

int print_x(va_list args, int *i ,const char *num)
{
    int c;
    int a;
    char *buff;
    char *af; 
    
    af = "0123456789abcdef"; 
    c = 0;
    buff = calloc(20,1);
    a = va_arg(args,int);
    while (a != 0)
    {
        buff[c] = af[a % 16];
        a = a / 16;
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    a = *i;
    *i = *i + 1 + mcounter2(num,a + 1) + zcounter2(num,a + 1);;
    return (c);
}
