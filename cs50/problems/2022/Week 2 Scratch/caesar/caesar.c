#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

int ft_isupper_c(char c) //Is Character Uppercase
{
        if (c >= 'A' && c <= 'Z')
            return(1);
    return (0);
}

int ft_islower_c(char c) //Is Character Lowercase
{
     if (c >= 'a' && c <= 'z')
        return(1);
    return (0);
}

int    ft_isnb_str(char *str) //Is the string a nb
{
    int i;
    i = 0;

    while (str[i] != '\0')  
    {
        if (!(str[i] >= '0' && str[i] <= '9')) 
            return(0);
        i++;
    }
    return (1);
}

int main (int argc, char *argv[])
{
    int i;
    char str[1000]; //Allocating The Memory Space For Cyphertext Input
    int check;

    i = 0;
    while (argv[1][i] != '\0')
    {
        if (!(ft_isnb_str(argv[1])) || i > 1 || argc != 2 || argv[1][0] == '0')
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
        i++;
    }
    int k = atoi(argv[1]);
    printf("Plaintext: ");
    scanf("%s", &str);
    printf("Cyphertext: ");
    i = 0;
    while (str[i] != '\0')
    {
        if ((ft_isupper_c(str[i])))
            printf("%c", (str[i] - 65 + k) % 26 + 65); //The Caesar Encryption
        else if ((ft_islower_c(str[i])))
            printf("%c", (str[i] - 97 + k) % 26 + 97); //The Caesar Encryption
        else
            printf("%c", str[i]); //Else Print Normal
        i++;
    }
    printf("\n");
    return (0);
}