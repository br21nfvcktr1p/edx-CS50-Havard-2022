#AMEX card=378282246310005
while True:
    print("Card: ")
    lenght = 0
    Number_CC = input()
    # Type Cast Number_CC Into int
    Number_CC = int(Number_CC)
    if Number_CC > 0:
        break
# Find digits to be multiplied by 2
def luhn_checksum(Number_CC):
    def digits_of(n):
        return[int(d) for d in str (n)]
    digits = digits_of(Number_CC)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    return checksum % 10

visa = Number_CC
master = Number_CC
amex = Number_CC
length = len(str(Number_CC))

#Identify if card is visa
while visa >= 10:
    visa = int(visa / 10)
#Identify if card is amex
while amex >= 10**13:
    amex = int(amex / 10**13)
#Identify if card is mastercard
while master >= 10**14:
    master = int(master / 10**14)

#Print results
if luhn_checksum(Number_CC) == 0:
    if visa == 4 and (length == 13 or length == 16):
            print("VISA")
    elif length == 15 and (amex == 34 or amex == 37):
        print("AMEX")
    elif length == 16 and (51 <= master <= 55):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")