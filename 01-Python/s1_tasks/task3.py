import calendar

year = int(input("Enter the year: "))
month = int(input("Enter the month: "))

# Get the calendar for the specified year
calendar_grid = calendar.calendar(year)
print(calendar_grid)