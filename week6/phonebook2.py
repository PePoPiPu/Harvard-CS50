# csv files are comma separated values. A form of very lightweight spreadsheet
import csv

file = open("phonebook.csv", "a")

name = input("Name: ")
number = input ("NUmber: ")

writer = csv.writer(file)
writer.writerow([name, number])

file.close()