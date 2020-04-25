#include <unistd.h>
#include <string.h>
char *str_find(char c)
{
    char *s;
    if (c == '(')
        return("]}");
    if (c == '{')
        return(")]");
    return(")}");
}

char char_find(char c)
{
    if (c == '(')
        return(')');
    if (c == '{')
        return('}');
    return(']');
}

int ft_comp(char c, char *s)
{
    if (*s == '\0')
        return(0);
    if (*s == c)
        return(-1);
    return(ft_comp(c, s + 1));
}

char *skobki(char *s, char *s2, char c)
{
    if (*s == '(' || *s == '[' || *s == '{')
    {
        if ((s = skobki(s + 1, str_find(*s), char_find(*s))) == NULL)
            return(NULL);
    }
    else if (*s == '\0')
    {
        if (ft_comp(c, ")]}") == -1)
            return (NULL);
        return ("correct");
    }
    else if (ft_comp(*s, s2) == -1)
        return(NULL);
    else if (*s == c)
        return(s + 1);
    else
        return(skobki(s + 1, s2, c));
    return(skobki(s, s2, c));

}

int main() {
    char buf[100];
    int i;

    i = read(0, buf, 30);
    buf[i] = '\0';
    if (buf[0] != '\0')
    {
        if (skobki(buf, ")]}", 0) == NULL)
            write (1, "error", 5);
        else
            write(1, "correct", 7);
    }
    write(1, "\n", 1);
    return(0);
}