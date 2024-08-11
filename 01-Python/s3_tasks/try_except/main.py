x=0
try:
    print(x)

except NameError:
    print(f"name error: name '{'x'}' is not defined")

else:
    print("Error")

finally:
    print("finished")