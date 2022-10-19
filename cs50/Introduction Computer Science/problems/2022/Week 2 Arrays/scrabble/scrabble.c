#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1 ,1, 4, 4, 8, 4, 10};

int ft_isupper_c(char c)
{
        if (c >= 'A' && c <= 'Z')
            return(1);
    return (0);
}

int ft_islower_c(char c)
{
     if (c >= 'a' && c <= 'z')
        return(1);
    return (0);
}

int ft_compute_score(char *word)
{
    //Compute and return score for string
    int score;
    int i;

    i = 0;
    score = 0;
    while (word[i] != '\0')
    {
        if (ft_isupper_c(word[i]))
            score += POINTS[word[i] - 65];
        if (ft_islower_c(word[i]))
            score += POINTS[word[i] - 97];
        i++;
    }
    return (score);
}

int main(void)
{
    char word2[100]; //Allocating Memory For Word2
    char word1[100]; //Allocating Memory For Word1
    int score1;
    int score2;
    int i;

    i = 0;
    printf("Player 1: ");
    scanf("%s", &word1);
    printf("Player 2: ");
    scanf("%s", &word2);
    //Scoreboth words
    score2 = ft_compute_score(word2);
    score1 = ft_compute_score(word1);
    //Print Winner
    if (score1 > score2)
        printf("Player 1 Wins!");
    else if (score2 > score1)
        printf("Player 2 Wins!"); 
    else
        printf("Tie!");
}