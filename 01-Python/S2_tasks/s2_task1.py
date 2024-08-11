#find the largest item from a given list using loop

ls = [90,80,68,53,673,233,3627]


#first way

largest_number = ls[0]
for i in range(1,len(ls)):
    if ls[i-1] < ls[i]:
        largest_number = ls[i]

print(f"The largest item form the array: {largest_number}")

#another way
ls.sort()
largest_number = ls[len(ls)-1]
print(f"The largest item form the array: {largest_number}")

# another way
ls.sort()
largest_number=0
largest_number = max(ls)
print(f"The largest item form the array: {largest_number}")



