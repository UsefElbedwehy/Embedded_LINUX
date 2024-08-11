from tkinter import *

# Function to reverse the entered word and display it
def print_reversed():
    word = reversed_word.get()
    reversed_str = word[::-1]
    L1.config(text=reversed_str)

# Initialize the main window
local_window = Tk()
local_window.geometry("500x500+100+100")
local_window.resizable(height=False, width=False)  # Disable both height and width resizing

# Define a StringVar to hold the entered word
reversed_word = StringVar()

# Create and place the label and entry widgets
Label(local_window, text="Enter the word:").grid(row=0, column=0, padx=10, pady=10)
Entry(local_window, textvariable=reversed_word).grid(row=0, column=1, padx=10, pady=10)

# Create a label to display the reversed word
L1 = Label(local_window, text="")
L1.grid(row=2, column=0, columnspan=2, padx=10, pady=10)

# Create and place the submit button
Button(local_window, text="Submit", command=print_reversed).grid(row=3, column=1, pady=10)

# Run the main loop
local_window.mainloop()
