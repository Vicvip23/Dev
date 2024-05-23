from tkinter import *
import random

root = Tk()
global direction
global score
score = 0
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
        if i > 0:
            print(i)
            gameArea.moveto(snake[i], gameArea.coords(snake[i-1])[0]-1, gameArea.coords(snake[i-1])[1]-1)

    match direction:
        case "Up":
                gameArea.move(head, 0, -10)
        case "Down":
                gameArea.move(head, 0, 10)
        case "Left":
                gameArea.move(head, -10, 0)
        case "Right":
                gameArea.move(head, 10, 0)


    root.after(400, moveSnake)
    


def checkInBounds():

    if gameArea.coords(head)[0] < 0:
        gameArea.move(head, 500, 0)
    if gameArea.coords(head)[0] > 500:
        gameArea.move(head, -500, 0)
    if gameArea.coords(head)[3] < 0:
        gameArea.move(head, 0, 500)
    if gameArea.coords(head)[3] > 500:
        gameArea.move(head, 0, -500)

    root.after(80, checkInBounds)


def genFruit():

    pos = random.randint(1, 495)
    global fruit
    fruit = gameArea.create_oval(pos, pos, pos+4, pos+4, fill='red')


def snakeAppendBody():

    snake.append(gameArea.create_rectangle(244, 255, 254, 265, fill='black'))
    root.after(800 * 4, snakeAppendBody)


def fruitCollision():

    global score

    if gameArea.find_overlapping(gameArea.coords(fruit)) != 0:
        gameArea.delete("fruit")
        score += 1
        snakeAppendBody()
        genFruit()
    root.after(80, fruitCollision)
        



root.bind("<KeyPress-Up>", changeDir)
root.bind("<KeyPress-Down>", changeDir)
root.bind("<KeyPress-Left>", changeDir)
root.bind("<KeyPress-Right>", changeDir)



checkInBounds()
moveSnake()
genFruit()
#fruitCollision()
snakeAppendBody()
gameArea.find_overlapping(gameArea.coords(fruit)[0],gameArea.coords(fruit)[1],gameArea.coords(fruit)[2],gameArea.coords(fruit)[3])
root.mainloop()