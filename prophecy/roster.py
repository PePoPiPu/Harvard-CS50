import csv
from cs50 import SQL
db = SQL("sqlite:///roster.db")
with open("students.csv", "r") as students:
    reader = csv.reader(students)
    for row in students:
        db.execute(")
