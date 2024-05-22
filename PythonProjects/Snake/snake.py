from tkinter import *
import random

root = Tk()
global direction
direction = "Up"
root.geometry("500x500")
gameArea = Canvas(root, width=500, height=500)
head = gameArea.create_rectangle(245, 245, 255, 255, fill='black')
snake = []
snake.append(head)
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

def moveHead():
    global direction
    match direction:
        case "Up":
                gameArea.move(head, 0, -2)
        case "Down":
                gameArea.move(head, 0, 2)
        case "Left":
                gameArea.move(head, -2, 0)
        case "Right":
                gameArea.move(head, 2, 0)
    root.after(40, moveHead)

def checkInBounds():
    if gameArea.coords(head)[0] < 0:
        gameArea.move(head, 500, 0)
    root.after(20, checkInBounds)

def genFruit():
    pos = random.randint(1, 495)
    gameArea.create_oval(pos, pos, pos+4, pos+4, fill='red')


root.bind("<KeyPress-Up>", changeDir)
root.bind("<KeyPress-Down>", changeDir)
root.bind("<KeyPress-Left>", changeDir)
root.bind("<KeyPress-Right>", changeDir)



game = True


checkInBounds()
moveHead()
genFruit()
root.mainloop()