'''
class car:
    name = "BMW"

    def __init__(self,name):
        print("Constructor is called form car")
        print(self)
        self.name = name
        print(self.name)

    def __del__(self):
        print("Destructor is called from car")

class focus:
    name = "BMW"

    def __init__(self,name):
        print("Constructor is called form focus")
        print(self)
        self.name = name
        print(self.name)

    def __del__(self):
        print("Destructor is called form focus")

AMRA = focus("FOCUS")
USEF = car("USEF")
print("Enter")
print("Enter")
print("Enter")
'''
'''
class person:
    name = ""
    age = 0 

    def __init__(self,name):
        print("Constructor is called...")
        self.name = name

    def greeting(self):
        print("hello!")

    def __del__(self):
        print("Destructor is called...")



Usef = person("Usef")
Usef.greeting()


class MyClass:

    def __init__(self):
        self.attribute1 = 0
        self.attribute2 = ""

    def greeting(self):
        print("Action completed!")



obj = MyClass()
print(obj.__doc__)
#help(obj.greeting)
print(obj.greeting.__doc__)
'''







