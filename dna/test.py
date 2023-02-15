import sys
import csv

match = {"AGATC": 29, "TTTTTTCT":50, "AATG":18, "TCTAG":23, "GATA":38, "TATC":24, "GAAA":22, "TCTG":9}
match_list = match.items()
with open(sys.argv[1], "r") as csvFile:
    reader = csv.DictReader(csvFile)
    for row in reader:
        del row["name"]
    row_list = row.items()
    if row_list == match_list:
        print("Equal")
    else:
        print("Different")
print(row_list)
print(match_list)