from tkinter import *
import threading
import timer

main_window = Tk()
main_window.title("main window")
main_window.geometry("500x500+100+100")
main_window.resizable(width=False,height=False)
value = IntVar()
Scale(main_window,variable=value,from_=0 ,to=255 ).pack()

def show():
    global t
    print(value.get())
    t = threading.Timer(1 , show)    
    t.start()

t = threading.Timer(1 , show)
t.start()

try:       
    main_window.mainloop()
    t.cancel()
except:
    print("Exiting...")
    exit()