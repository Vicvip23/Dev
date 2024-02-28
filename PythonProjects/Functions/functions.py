from tkinter import *
import math
from tkinter import messagebox
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl


window = Tk()
window.geometry("150x150")

def linear(a, b, x = []):
    y = []
    for item in x:
        y.append((a * item) + b) 
    return y

def trigonometric(a, b, x = []):
    y = []
    for item in x:
        y.append(math.sin((a * item) + b)) 
    return y

def quadratic(a, b, x = []):
    y = []
    for item in x:
        y.append(math.pow((item - a), 2) + b) 
    return y

def run():
    a = int(input1.get())
    b = int(input2.get())
    func = int(funcType.get())
    values = []
    values = np.linspace(0,30,1000)
    print(func)
    match func:
        case 1:
            plt.plot(values, linear(a, b, values))
            plt.show()
            print("lin")
        case 2:
            plt.plot(values, trigonometric(a, b, values))
            plt.show()
            print("trig")
        case 3:
            plt.plot(values, quadratic(a, b, values))
            plt.show()
            print("quad")

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