import pandas as fd

data = {
'name': ["usef","reem","mazen"],
'age': [10,20,30],
'male': ['True','False','True']
}

file_excel = fd.DataFrame(data)

file_excel.to_csv("fiel.csv")
file_excel.to_excel("fiel.xlsx")

def excel_read(path):
    return fd.read_excel(path)

def csv_read(path):
    return fd.read_csv(path)

print(excel_read('fiel.xlsx'))
print("-"*30)
print(csv_read('fiel.csv'))