from tkinter import *

def open_form():
    new_window = Toplevel(window)
    new_window.title("New window")
    new_window.geometry("400x400+100+100")
    new_window.resizable(width=False,height=False)
    Label(new_window,text="This the new form").pack()
    Button(new_window,text="close",command=new_window.destroy).pack()


window = Tk()
window.title("main window")
window.geometry("400x400+100+100")
window.resizable(width=False,height=False)

Label(window,text="Add new window").pack()
Button(window,text="Add",command=open_form).pack()
Button(window,text="Close",command=window.destroy).pack()

window.mainloop()