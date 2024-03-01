import math
from tkinter import *
from tkinter import messagebox

window = Tk()
window.geometry("400x400")

def run():

    pay = 0
    yearMultiplier = 1
    sex2 = sex.get()
    yearsWorked = int(experience.get())
    name = nameInput.get()

    if pos1.get() == True:
        pay += 1500
    if pos2.get() == True:
        pay += 1200
    if pos3.get() == True:
        pay += 1000
    
    for i in range(int(yearsWorked)):
        yearMultiplier += 0.01
    
    if(yearMultiplier != 0):
        pay *= yearMultiplier
    
    if(sex2 == True):
        pay *= 1.5
        print("w")
        messagebox.showinfo("info", "Dear Miss " + name + ", your pay is: " + str(round(pay, 2)))
    else:
        pay *= 1.3
        print("m")
        messagebox.showinfo("info", "Dear Mister " + name + ", your pay is: " + str(round(pay, 2)))

    print(pay)

sex = BooleanVar()
pos1 = BooleanVar()
pos2 = BooleanVar()
pos3 = BooleanVar()



nameLabel = Label(window, text="Name:")
nameLabel.pack()
nameInput = Entry(window)
nameInput.pack()

surnameLabel = Label(window, text="Surname:")
surnameLabel.pack()
surnameInput = Entry(window)
surnameInput.pack()

sexW = Radiobutton(window, text="Woman", variable=sex, value=True)
sexW.pack()
sexM = Radiobutton(window, text="Man", variable=sex, value=False)
sexM.pack()
posCashier = Checkbutton(window, text="Cashier  1500", variable=pos1)
posCashier.pack()
posJanitor = Checkbutton(window, text="Janitor  1200", variable=pos2)
posJanitor.pack()
posDelivery = Checkbutton(window, text="Delivery  1000", variable=pos3)
posDelivery.pack()
expLabel = Label(window, text="years worked:")
expLabel.pack()
experience = Entry(window)
experience.pack()
submit = Button(window, text="SUBMIT", command=run)
submit.pack()


window.mainloop()