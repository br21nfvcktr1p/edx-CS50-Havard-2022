#include <stdio.h>

float get_cents(void)
{
    float cents;
    printf("Cents Owed: ");
    scanf("%f", &cents);
    if (cents < 0)
        get_cents();
    return (cents);
}

float calculate_quarters(float cents)
{
    float quarters;

    quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    } 
    return (quarters);
}

float calculate_dimes(float cents)
{
    float dimes;

    dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    } 
    return (dimes);
}

float calculate_nickels(float cents)
{
    float nickels;

    nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    } 
    return (nickels);
}

float calculate_pennies(float cents)
{
    float pennies;

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
    float cents = get_cents();

    //Calculate the number of quarters to give the customer
    float quarters = calculate_quarters(cents);
    cents -= (quarters * 25);

    //Calculate the number of dimes to give the customer
    float dimes = calculate_dimes(cents);
    cents -= (dimes * 10);

    //Calculate the number of nickels to give the customer
    float nickels = calculate_nickels(cents);
    cents -= (nickels * 5);

    //Calculate the number of pennies to give the customer
    float pennies = calculate_pennies(cents);
    cents -= (pennies * 1);

    //Sum Coins
    float coins = quarters + dimes + nickels + pennies;

    //Print Total Sum To Give To Customer
    printf("%.0f\n", coins);
}
