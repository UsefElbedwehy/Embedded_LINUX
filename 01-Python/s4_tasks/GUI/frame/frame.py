from tkinter import *

root_window = Tk()
root_window.title("four colored buttons")
root_window.geometry("300x300+100+100")
root_window.configure(bg="#333333")
#top frame
upper_frame = Frame(root_window,background="red")
upper_frame.pack(side="top",expand=True,fill="both")
#bottom frame
bottom_frame = Frame(root_window,background="blue")
bottom_frame.pack(side="bottom",expand=True,fill="both")

#bottom
Blue_Button = Button(upper_frame,fg="blue" , text="Blue" ,bg="#444444" ,highlightbackground="#555555")
Blue_Button.pack(side="left")

Red_Button = Button(upper_frame,fg="red" , text="Red" ,bg="#444444" ,highlightbackground="#555555")
Red_Button.pack(side="left")

Green_Button = Button(upper_frame,fg="green" , text="Green" ,bg="#444444",highlightbackground="#555555")
Green_Button.pack(side="left")

Yellow_Button = Button(bottom_frame,fg="yellow" , text="Yellow" ,bg="#444444",highlightbackground="#555555")
Yellow_Button.pack(side="left")

root_window.mainloop()