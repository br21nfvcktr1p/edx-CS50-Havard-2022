#include <stdio.h>

void    ft_printcubes(int nb)
{
    int i;
    int counter;
    i = 1;
    counter = 0;
    while (i <= nb)
    {   
        //Empties On Left Pyramid
        while (counter != (nb - i))
        {
            printf(" ");
            counter++;
        }
        counter = 0;
        //Blocks Left Pyramid
        while (counter != i)
        {
            printf("#");
             counter++;
        }
        counter = 0;
        //Two Empty Space
        printf("  ");
        //Right Side Pyramid
        while (counter != i)
        {
            printf("#");
             counter++;
        }
        printf("\n");
        counter = 0;
        i++;
        }
}

int    ft_height_nb()
{  
    int nb;
    printf("Height: ");
    scanf("%i", &nb); //Stores Value Inputed
    if (nb < 0)
    {
        printf("\n"); //Newline for Height Prompt
        return (ft_height_nb()); //Recall Height To Restart
    }
    return (nb);   //Returns nb if not NEGATIVE;
}

int main(void)
{
    int nb;
    nb = ft_height_nb(); //Sorts Numbers Inputed
    if (nb > 0)
        ft_printcubes(nb);
    return (0);
}