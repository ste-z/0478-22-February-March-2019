
# coding: utf-8

"""
======
TASK 1
======
"""

while True:

    size = ["small","medium","large"]
    choosedSize = 0
    base = ["thin","thick"]
    choosedBase = 0
    standardToppings = ["tomato","cheese"]
    toppingsChoice = ["pepperoni","chicken","extra cheese","mushrooms","spinach","olives"]
    choosedToppings = []
    maxTopping = 0
    i=0
    confirm = 0


    while True:
        choosedSize = int(input("Please choose the size\n1=small, 2=medium, 3=large\n-->"))
        if (choosedSize <1):
            print("\n\nPlease input the correct numer!")
        elif (choosedSize >3):
            print("\n\nPlease input the correct numer!")
        else:
            break



    while True:
        choosedBase = int(input("Please choose the base\n1=thin, 2=thick\n-->"))
        if (choosedBase <0):
            print("\n\nPlease input the correct numer!")
        elif (choosedBase >2):
            print("\n\nPlease input the correct numer!")
        else:
            break



    print("Your pizza will have tomato and cheese automatically, there are also avalible extra toppings:\npepperoni=1, chicken=2, extra cheese=3, mushrooms=4, spinach=5, olives=6\nMAX NUMBER OF TOPPING IS 3")
    while True:
        maxTopping = int(input("How many extra topping do you want ? -->"))
        if maxTopping > 3:
            print("\n\nMaximum numer of extra toppings is 3!")
        else:
            break
    for i in range(maxTopping):
        toppingAppend = int(input("Extra topping -->"))
        toppingAppend -= 1
        choosedToppings.append(toppingsChoice[toppingAppend])
        

    print("\n\n\n\n=============================\nyour toppings:\n- Standard:", standardToppings, "\n- Extra:", choosedToppings)
    print("\nyour size:", size[choosedSize-1])
    print("\nyour base:", base[choosedBase-1], "\n=============================")



    confirm = int(input("\nConfirm?\n1=Yes, 0=No\n-->"))
    if confirm == 0:
        continue
    if confirm == 1:
        break

