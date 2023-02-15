import sys
import csv

match = {"AGATC": 29, "TTTTTTCT":50, "AATG":18, "TCTAG":23, "GATA":38, "TATC":24, "GAAA":22, "TCTG":9}
with open(sys.argv[1], "r") as csvFile:
    reader = csv.DictReader(csvFile)
    for row in reader:
        del row["name"]
    if row == match:
        print("Equal")
    else:
        print("Different")
print(row)
print(match)