#import from folder
from mylib.modulefile import sayHello
#import from file
import util
#built-in import
import platform
import os

sayHello()

print(util.sum(4,2)) #6
print(util.sub(4,2)) #2
print(util.div(4,2)) #2.0
print(util.mul(4,2)) #8


#built-in modules
print(os.getcwd())
print(os.listdir())

print(platform.processor())
print(platform.machine())
print(platform.architecture())
print(platform.version())
print(platform.system())
print(platform.release())
print(platform.node())







