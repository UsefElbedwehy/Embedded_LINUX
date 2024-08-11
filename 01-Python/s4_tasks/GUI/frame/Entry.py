from tkinter import *

local_window = Tk()

local_window.title("PYTHON")
local_window.geometry("300x300+20+20")

EntryBox_username = StringVar()
Label(local_window,text="Username: ").grid(row=0,column=0)
Entry(local_window,textvariable=EntryBox_username).grid(row=0,column=1)

EntryBox_password =StringVar()
Label(local_window,text="Password: ").grid(row=1,column=0)
Entry(local_window,textvariable=EntryBox_password).grid(row=1,column=1)



local_window.mainloop()