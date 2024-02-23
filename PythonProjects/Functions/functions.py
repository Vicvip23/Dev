from tkinter import *
import math
from tkinter import messagebox
import matplotlib.pylot as plt

window = Tk()
window.geometry("150x150")

def linear(a, b, x):
    return (a * x) + b

def trigonometric(a, b, x):
    return math.sin((a * x) + b)

def quadratic(a, b, x):
    return math.pow((x - a), 2) + b

def run():
    a = int(input1.get())
    b = int(input2.get())
    func = int(funcType.get())
    values = []
    match func:
        case 1:
            messagebox.showinfo("linear function", "result: " + linear(a,b))
        case 2:
            messagebox.showinfo("trigonometric function", "result: " + trigonometric(a,b))
        case 3:
            messagebox.showinfo("quadratic function", "result: " + quadratic(a,b))

funcType = IntVar()
input1 = Entry(window)
input1.pack()
input2 = Entry(window)
input2.pack()
radio1 = Radiobutton(window, text="f(x) = ax + b", variable=funcType, value=1)
radio1.pack()
radio2 = Radiobutton(window, text="f(x) = sin(ax + b)" , variable=funcType, value=2)
radio2.pack()
radio3 = Radiobutton(window, text="f(x) = (x - a)² + b", variable=funcType, value=3)
radio3.pack()

button1 = Button(window, text="Oblicz", command=run)
button1.pack()

window.mainloop()