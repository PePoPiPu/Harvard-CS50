from cs50 import SQL

db = SQL("sqlite:///favorites.db")

try:
    show = input("Show name: ")
    change = db.execute("UPDATE shows SET title = ? WHERE title LIKE ?", show)
except KeyboardInterrupt:

    for row in change:
        print(row["title"])