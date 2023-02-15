import sys
import csv

match = {"AGATC": 29, "TTTTTTCT":50, "AATG":18, "TCTAG":23, "GATA":38, "TATC":24, "GAAA":22, "TCTG":9}
match_list = match.items()
match_listint = [dict([key, int(value)]
       for key, value in dict.items())
       for dicts in match_list]
with open(sys.argv[1], "r") as csvFile:
    reader = csv.DictReader(csvFile)
    for row in reader:
        del row["name"]
    row_list = row.items()
    row_listint =[dict([key, int(value)]
            for key, value in dicts.items())
            for dicts in row_list]
    if row_list == match_list:
        print("Equal")
    else:
        print("Different")
print(row_list)
print(match_listint)