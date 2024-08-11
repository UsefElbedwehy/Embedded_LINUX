import openpyxl

workbook = openpyxl.Workbook()

data = [['name','age'],
        ['Alice',50],
        ['Usef',25],
        ['Reem',20]]

for row in data:
    workbook.active.append(row)

workbook.save('test.xlsx')
workbook.close()























