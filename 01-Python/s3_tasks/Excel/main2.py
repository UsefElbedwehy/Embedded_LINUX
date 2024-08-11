import openpyxl

wb = openpyxl.load_workbook('test.xlsx')
print(wb)
for word in wb['Sheet'].iter_rows(values_only=True):
    print(word)


