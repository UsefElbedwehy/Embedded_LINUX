from tkinter import *
def zero():
    print(0)
def one():
    print(1)
def two():
    print(2)
def three():
    print(3)
def four():
    print(4)
def five():
    print(5)
def six():
    print(6)
def seven():
    print(7)
def eight():
    print(8)
def nine():
    print(9)

window = Tk()

window.title("calculator")
window.resizable(height=False,width=False)

B1 = Button(window,text="1",command=one).grid(  row=0,column=0)
B2 = Button(window,text="2",command=two).grid(  row=0,column=1)
B3 = Button(window,text="3",command=three).grid(row=0,column=2)
B4 = Button(window,text="4",command=four).grid( row=1,column=0)
B5 = Button(window,text="5",command=five).grid( row=1,column=1)
B6 = Button(window,text="6",command=six).grid(  row=1,column=2)
B7 = Button(window,text="7",command=seven).grid(row=2,column=0)
B8 = Button(window,text="8",command=eight).grid(row=2,column=1)
B9 = Button(window,text="9",command=nine).grid( row=2,column=2)

window.mainloop()