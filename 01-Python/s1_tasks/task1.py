#first
#Write a Python program to count the number 4 in a given list.
ls = [1,2,3, 4, 5,6,5, 4 ,3,2,3, 4 ,5,6,7]
i=0
b=0
for i in range(len(ls)):
    if ls[i] == 4:
        b +=1

print(f"4 is found {b} times")



#second
#Write a Python program to test whether a passed letter is a vowel or not.
vowel = ['a','e','i','o','u']
c = str(input("Enter the letter: "))

if c.lower() in vowel:
    print("True")
else:
    print("Flase")

#third
#Write a python program to access environment variables.



