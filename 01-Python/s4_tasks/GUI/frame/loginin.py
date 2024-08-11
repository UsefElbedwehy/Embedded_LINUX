from tkinter import *

'''
local_window = Tk()
local_window.title("Login System")
local_window.geometry("300x300+10+10")

def Login_system():
    print("Enter the first name:",Username.get())
    print("Enter the second name:",password.get())

Label(local_window,text="First name: ").grid(row=0)
Label(local_window,text="Second name: ").grid(row=1)
Username = Entry(local_window)
password = Entry(local_window)
Username.grid(row=0,column=1)
password.grid(row=1,column=1)

B1 = Button(local_window,command=Login_system,text="submit")
B1.grid(row=2)

local_window.mainloop()
'''
local_window = Tk()
local_window.title("Login System")
local_window.geometry("300x300+10+10")

user_name = StringVar()
user_password = StringVar()

def login_system():
    print("your name is:",user_name.get())
    print("your password is:",user_password.get())
    local_window.destroy()

Label(local_window,text="username: ").grid(row=0)
Label(local_window,text="Password: ").grid(row=1)

Entry(local_window,textvariable=user_name).grid(row=0,column=1)
Entry(local_window,textvariable=user_password).grid(row=1,column=1)

B1 = Button(local_window,text="Login",command=login_system)
B1.grid(row=2)

local_window.mainloop()