from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")
# Returns list of dictionaries when using SELECT
rows = db.execute("SELECT * FROM favorites WHERE problem = 'Mario'")

for row in rows:
    print(row["Timestamp"])