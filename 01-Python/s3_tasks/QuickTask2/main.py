#Write a Python program to write a “list” to a file.
import os 
#create text file
os.system("touch main.txt")

#open the text file
txtFile = open("main.txt","w")

#write into the text file
ls = ['Usef','is','our','hero']
txtFile.writelines(" ".join(ls))


