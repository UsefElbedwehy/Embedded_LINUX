#!/usr/bin/python3
'''
Name     =  input("Enter ur name: "   )
Birth    =  input("Enter ur Birth: "  )
Faculty  =  input("Enter ur Faculty: ")
Email    =  input("Enter ur Email: "  )
Address  =  input("Enter ur Address: ")
print("Full name: " + Name      )
print("Birth: "     + Birth     )

print("Faculty: "   + Faculty   )
print("E-mail: "    + Email     )
print("Address: "   + Address   )
'''
'''
print(str(x) + ' ' + str(y))
x,y = 10,20
print(x)
x = "Usef"
print(x)
x = 8.9
'''

'''
#print summation, subtraction, multiplication, division of two numbers
#Quick task
x = input("Enter the first number: ")
y = input("Enter the second number: ")
print("sum is: " + str(int(x)+int(y)))
print("Sub is: " + str(int(x)-int(y)))

print("Multi is: " + str(int(x)*int(y)))
print("Div is: " + str(int(x)/int(y)))
'''
'''
print(bool(0))
print(False)
print(bool(False))
print(bool(()))
print(bool([]))
print(bool({}))
print(bool(""))

print(bool(1))
print(bool(2))
print(bool(33))
print(bool(100))
print(True)
print(bool(True))
print(bool("H"))
'''

#list
'''
x = ["Usef",4,1,55,2,3.3]

print(x[0])
print(x[1])
print(x[2])
print(x[3])
print(x[4])
print(x[5])
print(x)
x[4] = 66
print(x)
print(x[3:])
print(x[5:])
print(x[:-1])
print(x[:0])
print(x[0:])
print(x[1:])
print(x[0:5:2])
'''

'''
#tuple 

x=("Usef",4,3,2,1,3,2,8,9,0,6,4,2,1,2)
print(x)

x=["Usef",4,3,2,1,3,2,8,9,0,6,4,2,1,2]
print(x)
'''
'''
ThisDict = {

    "car_model" : "BMW",
    "Year" : 1998,
    "Electric" : False,
    "color" : "Blue"

}

print(type(ThisDict))
print(ThisDict)
print(ThisDict["color"])
print(ThisDict.keys())
print(ThisDict.values())
print(len(ThisDict))
'''
'''
#set
x = {"apple","apple","banana"}
print(x)
x = {7,6,5,4,3,2,1}
print(x)
'''
'''
#range
for i in range(10):
    print(i, end=" ")

x = list(range(10))
print(x)
'''
'''
x=("Usef",4,3,2,1,3,2,8,9,0,6,4,2,1,2)
y=["Usef",4,3,2,1,3,2,8,9,0,6,4,2,1,2]
z={"Usef",4,3,2,1,3,2,8,9,0,6,4,2,1,2}

print(x)
print(y)
print(z)
'''

'''
x = int(input("Enter ur age: "))
print("Ur ager is: {}".format(x))
'''
'''
a = 45 

b = 40

if a>b:
    pass
    

print(b)
'''
#loop
'''
i=0
for i in range(7):
    print(i ,end=" ")
print()
while i >= 0:
    print(i , end=" ")
    i -= 1

print()

'''
#break vs continue
'''
i=2
for i in range(1,11):
    if i % 2 == 0:
        break
    print(i," is odd number") 

print(1%2)
'''
# else in for loop
'''
i=0
for i in range(10):
    print(i, end= " ")
else:
    print(i+1)
'''
#shorthand for
'''
i=0
[print(i) for i in "USEF" ]
[print(i) for i in range(10) if i%2==0]
'''
#reverse string
'''
sentence = input()
sentence = sentence[::-1]
print(sentence)

i=0
sentence = input()
for i in range(len(sentence)):
    print(sentence[-1-i],end="")

'''

'''
import psutil

print("CPU USAGE:",psutil.cpu_percent())

print("TOTAL MEMORY: " + str(psutil.virtual_memory().total / 1000000000) + " G")


print("TOTAL DISK SPACE:",psutil.disk_usage('/').total/ 1000000000, "G")
print("USED DISK SPACE:",psutil.disk_usage('/').used/ 1000000000, "G")
print("FREE DISK SPACE:",psutil.disk_usage('/').free/ 1000000000, "G")
print("PERCENTAGE DISK SPACE:",psutil.disk_usage('/').percent, "%")


'''

'''
import datetime

now = datetime.datetime.now()
print("Date and time: " + str(now))


'''
'''
import pyfiglet
print(pyfiglet.figlet_format("Usef Elbedwehy"))
'''

from gtts import gTTS
import vlc
myobj = gTTS(text="Usef Elbedwehy hates Reem Sameh" , lang='en' ,slow=False)
myobj.save("MSG.mp4")

p = vlc.MediaPlayer("./MSG.mp4")

p.play()

while True:
    pass






