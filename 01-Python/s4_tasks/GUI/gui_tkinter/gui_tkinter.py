from tkinter import *

def Led_on():
    print("LED ON")

def Led_off():
    print("LED OFF")

main_window = Tk()
main_window.title("Calculator")
main_window.geometry("500x500+50+50")
main_window.resizable(False,False)
main_window.configure(background="white")

Label(main_window,text="+",font=('body,14'),bg="cyan",fg="black").grid(row=0 , column=0 )
Label(main_window,text="-",font=('body,14'),bg="cyan",fg="black").grid(row=1 , column=1 )
Label(main_window,text="*",font=('body,14'),bg="cyan",fg="black").grid(row=2 , column=2 )
Label(main_window,text="/",font=('body,14'),bg="cyan",fg="black").grid(row=3 , column=3 )

Button(main_window ,text="close" ,width="10" , command=main_window.destroy).grid(row=4 , column=0 )
Button(main_window ,text="LED ON" ,width="10" , command=Led_on).grid(row=5 , column=0 )
Button(main_window ,text="LED ON" ,width="10" , command=Led_off).grid(row=6 , column=0 )

main_window.mainloop()