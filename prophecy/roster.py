import csv
from cs50 import SQL
db = SQL("sqlite:///roster.db")
with open("students.csv", "r") as students:
    reader = csv.reader(students)
    # Skip header row
    next(reader)
    for row in reader:
        db.execute("INSERT INTO student (student_id, student_name) VALUES (?, ?)" , row[0], row[1])
        print(row[0])
