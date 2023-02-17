from cs50 import SQL

db = SQL("sqlite:///favorites.db")

show = input("Show name: ")

change = db.execute("UPDATE shows SET title = ? WHERE title LIKE ?", show)

for row in change:
    print("title")