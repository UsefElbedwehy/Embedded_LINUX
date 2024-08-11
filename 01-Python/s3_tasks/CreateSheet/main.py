import openpyxl

workbook = openpyxl.Workbook()

New_Sheet = workbook.create_sheet(title="NewSheet")

New_Sheet["A1"] = "name"
New_Sheet["B1"] = "age"
New_Sheet["A2"] = "usef"
New_Sheet["B2"] = 21

workbook.save("File.xlsx")

