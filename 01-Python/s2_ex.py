'''
name = "usef14Reem"
print("type",type(name))
name:str = "usef14Reem"
print("type",type(name))
print("Cap",name.capitalize())
print("casefold",name.casefold())
print("center",name.center(20,'*'))
print("count",name.count('u'))
print("find u",name.find('u'))
print(("endwith",name.endswith('u')))
print(("encode",name.encode()))
print("format",name.format())
print("format map",name.format_map('u'))
print("index",name.index('u'))
print("index",name.isalnum())
print("index",name.isalpha())
print("index",name.isdecimal())
'''
'''
txt = "Usef is embedded software engineer reem is embedded hardware engineer"
x = "ees" in txt
print(x)
'''
'''
def foo():
    print("hello from the other world")


def fooo(pname):
    print("hello from the other " + pname)

def pnumber(x):
    return x**x

def my_function(child1,child2,child3):
    print(f"child1 {child1} child2 {child2} child3 {child3}")

def my_default(pname="world"):
    print("hello from the other " + pname)



foo()
fooo(str(pnumber(2)))
my_function(child3='Amr' ,child1="Ahmed" ,child2="Usef")
my_default()
my_default("usef")
'''
'''
def my_function(*arg):
    for x in arg:
        print(x, end=" ")

ls = ["Apple","Banana","Cherry",2323 , 2,4,42,1]
tb = (1,2,3,3,"Usef",2323 , 2,4,42,1)

my_function(ls)
my_function(tb[4])
'''
'''
def my_function(**names):
    print("His name is: "+names["name"])


my_function(name="usef")

def gFun(arg):
    for x in arg:
        print("Key:",x , "Value:",arg[x])

c = {
    "fname":"Usef",
"lname":"Elbedwehy",
"age":"23"
}

gFun(c)
'''
'''

x = 555
def myfuction():
    global x
    x = 111
    print(x , id(x))


myfuction()

print(x , id(x))

'''
'''
x = lambda a,b:a*b

print(x(3,3))
'''

























