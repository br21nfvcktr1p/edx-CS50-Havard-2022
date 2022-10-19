#include <stdio.h>
#include <string.h>

//MAX Nb Of Candidates
#define MAX 9

//Candidates Have A Name & A Vote
typedef struct 
{
    char  *name;
    int votes;
}
candidate;

//Array Of Candidates
candidate candidates[MAX];

//Nb Of Candidates
int candidate_count;

//Function Vote
int ft_vote(char *name)
{
    int i;
    
    i = 0;
    while (i < candidate_count)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return (1);
        }
        i++;
    }
    return (0);
}

//Function Print Winner
void    ft_print_winner()
{
    int    maxvotes;
    int i;

    i = 0;
    maxvotes = 0;
    while(i < candidate_count)
    {
        if (candidates[i].votes > maxvotes)
            maxvotes = candidates[i].votes; //Defining Max Votes To Candidates Votes
        i++;
    }
    i = 0;
    while (i < candidate_count) 
    {
        if (candidates[i].votes == maxvotes)
            printf("%s\n", candidates[i].name); //Print Candidate Winners
        i++;
    }
    return;
}

int main(int argc, char *argv[])
{
    int i;
    int voter_count;
    char name[100]; //Allocating Memory For String
    i = 0;
    if (argc < 2) //If Argument Less Than 2
    {
        printf("Usage: pluriality[candidate ..]\n");
        return (1);
    }
    //Populate Array Of Candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) //If Is More Than Maximum Candidate
    {
        printf("Maximum number of candidate is %i\n");
        return (2);
    }
    while (i < candidate_count) //Counting & Storing Trough Candidates
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        i++;
    }
    i = 0;
    printf("Numbers Of Vote: ");
    scanf("%i", &voter_count); //Storing Nb Of Vote
    while (i < voter_count)
    {
        printf("Vote: ");
        scanf("%s", &name); //Storing Vote
        if (!ft_vote(name))
            printf("Invalid vote.\n"); 
        i++;
    }
    ft_print_winner();
}