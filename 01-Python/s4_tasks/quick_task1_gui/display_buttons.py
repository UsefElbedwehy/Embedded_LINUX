from tkinter import *

def B1():
    print("Button1")
def B2():
    print("Button2")
def B3():
    print("Button3")
def B4():
    print("Button4")

window = Tk()

B1 = Button(window,text="Button1",command=B1).grid(row=0,column=1)
B2 = Button(window,text="Button2",command=B2).grid(row=1,column=0)
B3 = Button(window,text="Button3",command=B3).grid(row=1,column=2)
B4 = Button(window,text="Button4",command=B4).grid(row=2,column=1)

window.mainloop()