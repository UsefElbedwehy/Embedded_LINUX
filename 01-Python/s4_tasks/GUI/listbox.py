from tkinter import *

def ListBox_Option(self):
    selection = ls.curselection()
    print(ls.get(selection))


def RadioSelection():
    global globalVar
    print(globalVar.get())


# Initialize the main window
local_window = Tk()
local_window.geometry("500x500+100+100")
local_window.resizable(height=False, width=False)  # Disable both height and width resizing
globalVar = IntVar()
ls = Listbox(local_window)

ls.insert(1, "Python")
ls.insert(2, "CPP")
ls.insert(3, "C")
ls.insert(4, "Other option")

ls.pack()

ls.bind("<<ListboxSelect>>",ListBox_Option)

Radiobutton(local_window,text="cross",value=1,variable=globalVar).pack()
Radiobutton(local_window,text="native",value=2,variable=globalVar).pack()

Button(local_window,text="Submit",command=RadioSelection).pack()

local_window.mainloop()