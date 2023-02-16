import csv

with open("favorites.csv" , "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1
    print(f"Scratch: {scratch}")
    print(f"Python : {python}")
    print(f"C: {c}")