# csv files are comma separated values. A form of very lightweight spreadsheet
import csv
# With the following opening of the file, do x and close it
with open("phonebook.csv", "a") as file:

    name = input("Name: ")
    number = input ("Number: ")

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
