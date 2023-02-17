import csv
from cs50 import SQL
db = SQL("sqlite:///roster.db")
with open("students.csv", "r") as students:
    reader = csv.reader(students)
    for row in students:
        db.execute("INSERT INTO students (student_id, student_name) VALUES 
