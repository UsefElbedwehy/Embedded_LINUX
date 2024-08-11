import csv
#import os 
#os.system("touch data.csv")


reader = csv.reader(open('data.csv',"r"))

print(reader)
for line in reader:
    print(line)



























