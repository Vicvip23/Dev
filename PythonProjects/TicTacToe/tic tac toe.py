import random
import time


# global definition of 'turn' to decide whose turn it is
global turn
turn = 1

 
# definition of 'create()' function that generates a 3x3 2d list
def create():

    global table
    table = [[" "," "," "],[" "," "," "],[" "," "," "]]


# definition of 'display()' function that displays a table with dividers inbetween spaces
def display(x):

    # iterating over every table element to display it
    for i in range(3):
        for j in range(3):
            print(x[i][j], end = "|")
        print()
        print("------")


# definition of 'insert' function that takes 2 spaces and inserts a symbol in the appropriate place of a table
def insert(a, b):
    
    global turn
    validInput = False
    
    # checks if input is valid
    while validInput == False:
        if a >= 0 and a <= 2 and b >= 0 and b <= 2 and table[a][b] == " ":
            validInput = True
        else:
            try:
                print("invalid input, try again")
                a = int(input("input row: ")) - 1
                b = int(input("input column: ")) - 1
            except ValueError:
                print()

    # deciding whose turn it is based on the 'turn' variable
    if turn % 2 == 1:
       table[a][b] = "O"
    else:
        table[a][b] = "X"

    turn += 1


# definition of 'winCheck' function that checks for winning positions
def winCheck():

    if (table[0][0] == table[0][1] and table[0][0] == table[0][2] and table[0][0] != " " or
    table[1][0] == table[1][1] and table[1][0] == table[1][2] and table[1][0] != " " or
    table[2][0] == table[2][1] and table[2][0] == table[2][2] and table[2][0] != " " or
    table[0][0] == table[1][0] and table[0][0] == table[2][0] and table[0][0] != " " or
    table[0][1] == table[1][1] and table[0][1] == table[2][1] and table[0][1] != " " or
    table[0][2] == table[1][2] and table[0][2] == table[2][2] and table[0][2] != " " or
    table[0][0] == table[1][1] and table[0][0] == table[2][2] and table[0][0] != " " or
    table[0][2] == table[1][1] and table[0][2] == table[2][0] and table[0][2] != " " ):

        # using 'turn' variable to decide who won
        if turn % 2 == 0:
            display(table)
            print("player O wins!")
            exit()
        else:
            display(table)
            print("player X wins!")
            exit()


# definition of 'fullCheck()' function that checks if board is full
def fullCheck():

   for i in range(3):
        for j in range(3):
            if table[i][j] == " ":
                return False


# definition of 'computerPlay()' function that generates 2 random values and passes them on to 'insert()'
def computerPlay():
    
    # definition of variable in a way that simulates a do{}while() loop
    correctPosition = False
    
    # loop picking random values and checking their validity
    while correctPosition == False:
        position1 = random.randint(0,2)
        position2 = random.randint(0,2)
        
        if table[position1][position2] == " ":
            correctPosition = True
    
    if correctPosition == True:
        insert(position1, position2)



# asking user for game options
ifStartInput = input("start game? (Y/N): ")
ifComputerInput = input("do you want to play against the computer? (Y/N): ")

# checking user answer
if ifStartInput.upper() == "Y":
    ifStart = True
else:
    exit()

if ifComputerInput.upper() == "Y":
    ifComputer = True
else:
    ifComputer = False

# creating a global 2d list 'table[][]'
create()

# main game loop
while ifStart:
    # displaying board state
    display(table)
    # definition of variable in a way to simulate a do{}while() loop
    validInput = False
    
    # getting input from user and checking its validity
    while validInput == False:
        try:
            input1 = int(input("input row: ")) - 1
            input2 = int(input("input column: ")) - 1
            validInput = True
        except ValueError:
            print("invalid input, try again")

    # inserting symbols on the board based on user input
    insert(input1, input2)
    # checking if there's any winning position on the board
    winCheck()

    # checking if board is full, in such a scenario, declare a draw
    if fullCheck() != False:
        display(table)
        print("draw")
        exit()
    
    # only executes when user plays with computer
    if ifComputer == True:
        # displaying state of the board
        display(table)
        # delaying computer response to make it seem more sophisticated
        time.sleep(1.5)
        print("computer's response: ")
        # generation and execution of computer's move
        computerPlay()
        # checking for winning or drawing positions
        winCheck()
        
        if fullCheck() != False:
            display(table)
            print("draw")
            exit()