while True:
    print("Height: ")
    # Take Input Nb From User
    nb = input()
    # Type Cast Nb Into Integer
    nb = int(nb)
    if nb >= 1 and nb <= 8:
        break
  
# Loop To Print Two Side Pyramid Block
for i in range(nb):
    #Left Side Pyramid
    print(" " * (nb - 1 - i), end="")
    print("#" * (i + 1), end="")
    #Right Side Pyramid
    print(" " * 2, end="")
    print("#" * (i + 1))