from tkinter import *

root = Tk()
global direction
direction = "Up"
root.geometry("500x500")
gameArea = Canvas(root, width=500, height=500)
head = gameArea.create_rectangle(245, 245, 255, 255, fill='black')
gameArea.pack()

def changeDir(event):
    global direction 
    direction = event.keysym

def moveHead():
    match direction:
        case "Up":
            gameArea.move(head, 0, -20)
        case "Down":
            gameArea.move(head, 0, 20)
        case "Left":
            gameArea.move(head, -20, 0)
        case "Right":
            gameArea.move(head, 20, 0)
    root.after(500, moveHead)
    



root.bind("<KeyPress-Up>", changeDir)
root.bind("<KeyPress-Down>", changeDir)
root.bind("<KeyPress-Left>", changeDir)
root.bind("<KeyPress-Right>", changeDir)



game = True

moveHead()

root.mainloop()