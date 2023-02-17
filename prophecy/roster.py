import csv
from cs50 import SQL

rows = db.execute
with open("students.csv", "r") as students:
    reader = csv.reader(students)
    for row in students:
