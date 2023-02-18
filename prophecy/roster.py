import csv
from cs50 import SQL
db = SQL("sqlite:///roster.db")
with open("students.csv", "r") as students:
    reader = csv.reader(students)
    # Skip header row
    next(reader)
    for row in reader:
        db.execute("UPDATE students SET (id, student_name) = ?, ?" , row[0], row[1])
        db.execute("UPDATE houses SET DISTINCT house_name = '?'", row[2])

