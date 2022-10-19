#include <stdio.h>

int get_cents(void)
{
    int cents;
    do
    {
        printf("Cents Owed: ");
        scanf("%i", cents);
    } while (cents < 0);
    return (cents);
}

int calculate_quarters(int cents)
{
    int quarters;

    quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    } 
    return (quarters);
}

int calculate_dimes(int cents)
{
    int dimes;

    dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    } 
    return (dimes);
}

int calculate_nickels(int cents)
{
    int nickels;

    nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    } 
    return (nickels);
}

int calculate_pennies(int cents)
{
    int pennies;

    pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    } 
    return (pennies);
}

int main(void)
{

    //Ask how many cents the customer is owed
    int cents = get_cents();

    //Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents -= (quarters * 25);

    //Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents -= (dimes * 10);

    //Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents -= (nickels * 5);

    //Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents -= (pennies * 1);

    //Sum Coins
    int coins = quarters + dimes + nickels + pennies;

    //Print Total Sum To Give To Customer
    printf("%i\n", coins);
}