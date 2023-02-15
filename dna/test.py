import sys
import csv

match = {"AGATC": 29, "TTTTTTCT":50, "AATG":18, "TCTAG":23, "GATA":38, "TATC":24, "GAAA":22, "TCTG":9}
with open(sys.argv[1], "r") as csvFile:
    reader = csv.DictReader(csvFile)
    for dicts in match:
        for keys in dicts:
            dicts[keys] = int(dicts[keys])
    for row in reader:
        del row["name"]
        for dicts in row:
            for keys in dicts:
                dicts[keys] = int(dicts[keys])
    if row.values() == match.values():
        print("Equal")
    else:
        print("Different")
print(int(row.values()))
print(int(match.values()))