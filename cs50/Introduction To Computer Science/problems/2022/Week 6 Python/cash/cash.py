while True:
    print("Change Owed: ")
    # Take Input Nb (Ex: %0.Nb)
    dollars = input()
    # Type Cast Nb Into float
    dollars = float(dollars)
    if dollars >= 0:
        break   

# Converting Cents 
cents = round(dollars * 100)
coins = 0

while cents >= 25:
    cents -= 25
    coins += 1

while cents >= 10:
    cents -= 10
    coins += 1

while cents >= 5:
    cents -= 5
    coins += 1

while cents >= 1:
    cents -= 1
    coins += 1

print(coins)