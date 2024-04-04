import random
import time
from tkinter import *
from tkinter import messagebox
import math


global turn
turn = 1
root = Tk()
root.geometry("300x300")
canvas = Canvas(root, width=300, height=300)
canvas.create_line(100, 0, 100, 300)
canvas.create_line(200, 0, 200, 300)
canvas.create_line(0, 100, 300, 100)
canvas.create_line(0, 200, 300, 200)

def drawMove(x, y):

    if turn % 2 == 1:
        canvas.create_oval(x*100, y*100, (x*100)+100, (y*100)+100)
    else:
        canvas.create_line(x*100, y*100, (x*100)+100, (y*100)+100)
        canvas.create_line(x*100, (y*100)+100, (x*100)+100, y*100)

def onClick(event):

    xPos = math.floor(event.x / 100)
    yPos = math.floor(event.y / 100)
    if xPos >= 3:
        xPos - 1
    if yPos >= 3:
        yPos - 1

    print(xPos, " ", yPos)
    drawMove(xPos, yPos)
    insert(yPos, xPos)
    winCheck()
    fullCheck()

    if fullCheck() != False:
        display(table)
        print("draw")
        exit()
    
    if ifComputer == True:
    
        computerPlay()
    
        winCheck()
        
        if fullCheck() != False:
            display(table)
            print("draw")
            exit()

canvas.bind("<Button-1>", onClick)
canvas.pack()

def create():

    global table
    table = [[" "," "," "],[" "," "," "],[" "," "," "]]


def display(x):


    for i in range(3):
        for j in range(3):
            print(x[i][j], end = "|")
        print()
        print("------")


def insert(a, b):
    
    global turn
    validInput = False
    
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

    if turn % 2 == 1:
       table[a][b] = "O"
    else:
        table[a][b] = "X"

    turn += 1

    display(table)


def winCheck():

    if (table[0][0] == table[0][1] and table[0][0] == table[0][2] and table[0][0] != " " or
    table[1][0] == table[1][1] and table[1][0] == table[1][2] and table[1][0] != " " or
    table[2][0] == table[2][1] and table[2][0] == table[2][2] and table[2][0] != " " or
    table[0][0] == table[1][0] and table[0][0] == table[2][0] and table[0][0] != " " or
    table[0][1] == table[1][1] and table[0][1] == table[2][1] and table[0][1] != " " or
    table[0][2] == table[1][2] and table[0][2] == table[2][2] and table[0][2] != " " or
    table[0][0] == table[1][1] and table[0][0] == table[2][2] and table[0][0] != " " or
    table[0][2] == table[1][1] and table[0][2] == table[2][0] and table[0][2] != " " ):

        if turn % 2 == 0:
            display(table)
            print("player O wins!")
            exit()
        else:
            display(table)
            print("player X wins!")
            exit()


def fullCheck():

   for i in range(3):
        for j in range(3):
            if table[i][j] == " ":
                return False


def computerPlay():
    
    correctPosition = False
    
    time.sleep(1.5)

    while correctPosition == False:
        position1 = random.randint(0,2)
        position2 = random.randint(0,2)
        
        if table[position1][position2] == " ":
            correctPosition = True
    
    if correctPosition == True:
        drawMove(position2, position1)
        insert(position1, position2)


ifComputerInput = messagebox.askquestion("Playstyle", "Do you want to play against the computer?", icon="question")
if ifComputerInput == "yes":
    ifComputer = True
else:
    ifComputer = False

create()
root.mainloop()