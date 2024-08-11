'''f1 = open("file1.txt","r")
f2 = open("file2.txt","r")
f3 = open("file3.txt","r")

print(f"file #one: {f1.read()}")
print(f"file #two: {f2.read()}")
print(f"file #three: {f3.read()}")

f1.close()
f2.close()
f3.close()

#error
#f1.read()

f1 = open("file1.txt","r")
f2 = open("file2.txt","r")
f3 = open("file3.txt","r")

print(f1.readline())
print(f2.readlines())
print(f3.readlines())

f3.seek(5)
print(f3.readline(2))
print(f3.readlines(2))


go = f3.read()
goo = f3.readlines()

print(go)
print(goo)
'''
'''
f1 = open("file1.txt","r")
f2 = open("file2.txt","r")
f3 = open("file3.txt","r")


#go = f3.read()
goo = f2.readline()

#print(go)
print(goo)
goo = f2.readline()
print(goo)

f1.close()
f2.close()
f3.close()
'''

f2 = open("file4.txt","w")

f2.write("Hello from the other side")

f2.close()

f2 = open("file4.txt","r")

readable = f2.read()

print(readable)




