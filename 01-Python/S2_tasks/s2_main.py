#nested
'''
ls = ['a',['b','c'],'d']
ls[1].insert(1,'f')
print(ls) '''

#tuples
'''

thistuble = ('apple','banana','cherry')
print(len(thistuble))
print(id(thistuble))
print(type(thistuble))
print(thistuble)
print(' ')

thistuble = ('apple',)
print(len(thistuble))
print(id(thistuble))
print(type(thistuble))
print(thistuble)
print(' ')

thistuble = ('apple')
print(len(thistuble))
print(id(thistuble))
print(type(thistuble))
print(thistuble)
print(' ')

thistuble = ("abc",34,True,40,"male")
print(len(thistuble))
print(id(thistuble))
print(type(thistuble))
print(thistuble)
print(' ')

thistuble = (('apple','banana','cherry'))
print(len(thistuble))
print(id(thistuble))
print(type(thistuble))
print(thistuble)
print(' ')
'''

thistuble = (('apple','banana','cherry','orange','mango'))
(*yellow,green,red) = thistuble
print(yellow,green,red) 



