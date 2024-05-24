from tkinter import *
import random

root = Tk()
global direction
global score
time = 400
direction = "Up"
root.geometry("500x500")
gameArea = Canvas(root, width=500, height=500)
head = gameArea.create_rectangle(245, 245, 255, 255, fill='black')
body = gameArea.create_rectangle(245, 255, 255, 265, fill='black')
snake = []
snake.append(head)
snake.append(body)
gameArea.pack()



def changeDir(event):

    global direction

    match direction:
        case "Up":
            if event.keysym != "Down":
                direction = event.keysym
        case "Down":
            if event.keysym != "Up":
                direction = event.keysym
        case "Left":
            if event.keysym != "Right":
                direction = event.keysym
        case "Right":
            if event.keysym != "Left":
                direction = event.keysym


def moveSnake():

    global direction

    for i in range(len(snake)):
        if i != len(snake)-1:
            lastCoords = gameArea.coords(snake[len(snake)-i-2])
            gameArea.moveto(snake[len(snake)-1-i], lastCoords[0]-1, lastCoords[1]-1)

    match direction:
        case "Up":
                gameArea.move(head, 0, -10)
        case "Down":
                gameArea.move(head, 0, 10)
        case "Left":
                gameArea.move(head, -10, 0)
        case "Right":
                gameArea.move(head, 10, 0)
    


def checkInBounds():

    if gameArea.coords(head)[0] < 0:
        gameArea.move(head, 500, 0)
    if gameArea.coords(head)[0] > 500:
        gameArea.move(head, -500, 0)
    if gameArea.coords(head)[3] < 0:
        gameArea.move(head, 0, 500)
    if gameArea.coords(head)[3] > 500:
        gameArea.move(head, 0, -500)


def genFruit():

    pos1 = random.randint(1, 495)
    pos2 = random.randint(1, 495)
    global fruit
    fruit = gameArea.create_oval(pos1, pos2, pos1+4, pos2+4, fill='red')


def snakeAppendBody():

    snake.append(gameArea.create_rectangle(1244, 1255, 1254, 1265, fill='black'))
    #root.after(1000, snakeAppendBody)


def fruitCollision():

    global time

    if gameArea.find_overlapping(gameArea.coords(fruit)[0],gameArea.coords(fruit)[1],gameArea.coords(fruit)[2],gameArea.coords(fruit)[3])[0] == 1:
        gameArea.delete(fruit)
        snakeAppendBody()
        time = time / 1.03
        genFruit()


def snakeCollision():

    for segment in snake:
        if gameArea.coords(head) == gameArea.coords(segment) and segment != head:
            exit()
        

def updateGame():

    checkInBounds()
    moveSnake()
    fruitCollision()
    snakeCollision()
    #print(gameArea.find_overlapping(gameArea.coords(fruit)[0],gameArea.coords(fruit)[1],gameArea.coords(fruit)[2],gameArea.coords(fruit)[3]))

    root.after(int(time), updateGame)



root.bind("<KeyPress-Up>", changeDir)
root.bind("<KeyPress-Down>", changeDir)
root.bind("<KeyPress-Left>", changeDir)
root.bind("<KeyPress-Right>", changeDir)


genFruit()
updateGame()
#snakeAppendBody()

root.mainloop()