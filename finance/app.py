import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "GET":
        # Get current balance from user
        c_row = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        cash = c_row[0]["cash"]
        # Declaring sum valuable to have a total of the holdings
        sum = cash
        # Select current username
        row = db.execute("SELECT username FROM users WHERE id = :id", id=session["user_id"])
        username = row[0]["username"]
        # Select all columns from stocks table
        rows = db.execute("SELECT * FROM stocks")
        for row in rows:
            look = lookup(row["share_symbol"])
            row["name"] = look["name"]
            row["price"] = look["price"]
            row["total"] = row["price"] * row["shares_number"]

            sum += row["total"]
            # Convert values to usd
            row["price"] = usd(row["price"])
            row["total"] = usd(row["total"])
        return render_template("index.html",username=username, rows=rows, cash=usd(cash), sum=usd(sum))



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Must provide symbol")

        symbol = lookup(request.form.get("symbol"))
        if symbol == None:
            return apology("Couldn't find stock")
        # If the number of shares is less than 1
        if int(request.form.get("shares")) < 1:
            return apology("Must provide a number of shares to buy greater than 0")
        # Retrieving current cash amount
        row = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        cash_current = float(row[0]["cash"])
        # If current cash amount is greater than the total amount to buy, update cash amount
        numeric_price = int(symbol["price"])
        numeric_shares = int(request.form.get("shares"))
        numeric_total = numeric_price * numeric_shares
        if cash_current > numeric_total:
            balance = cash_current - numeric_total
            id = int(session["user_id"])
            db.execute("UPDATE users SET cash = ? WHERE id = ?", balance, id)
            # Get time of request
            date = datetime.now().strftime("%d-%m-%Y %H:%M:%S")
            # Get value at time of purchase
            init_value = int(symbol["price"])
            # Update stocks table with purchase information
            db.execute("INSERT INTO stocks (user_id, shares_number, share_symbol, time_of_purchase, value_at_time_of_purchase) VALUES(?, ?, ?, ?, ?)", id, int(request.form.get("shares")), symbol["symbol"], date, init_value)
        else:
            return apology("Can't afford number of shares at current price")
        return redirect ("/")

    # If request method is GET
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    # initialize dictionary with returned values
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Must provide symbol")

        symbol = lookup(request.form.get("symbol"))
        if symbol == None:
            return apology("Couldn't find stock")
        return render_template("quoted.html", symbol=symbol)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Ensure username was submitted
        newuser = request.form.get("username")
        newpass = request.form.get("password")
        usernames = db.execute("SELECT username FROM users")
        if not request.form.get("username"):
            return apology("must provide username", 403)
        # If username exists, return apology and 409 code (CONFLICT)
        elif newuser in usernames:
            return apology("username already exists", 409)
        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password", 403)
        elif newpass != request.form.get("confirmation"):
            return apology("password doesn't match", 409)
        # Hash new password
        hash = generate_password_hash(newpass, method="pbkdf2:sha256", salt_length=32)
        # Insert new username and hashed password into username
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", newuser, hash)

        return render_template("login.html")
    # User reached route via GET
    else:
        return render_template("register.html")





@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Must provide a share symbol")
        elif len(request.form.get("shares")) == 0:
            return apology("Must provide a number of shares to sell")
        elif int(request.form.get("shares")) < 1:
            return apology("Share number must be greater than 0")
        # Get current user balance
        c_row = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        cash = float(c_row[0]["cash"])
        # Get total value of the current sale
        symbol = lookup(request.form.get("symbol"))
        shares = int(request.form.get("shares"))
        price = int(symbol["price"])
        sale_value = shares * price
        updated_cash = cash + sale_value
        id = int(session["user_id"])
        # Update user's balance
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, id)
        # Update stocks table
        # Substract number of shares sold to current shares if it's more than 0 and update the database
        if shares > 1:
            current_symbol = request.form.get("symbol")
            id = session["user_id"]
            row = db.execute("SELECT shares_number FROM stocks WHERE share_symbol = ? AND ?", current_symbol, id)
            old_shares = row[0]["shares_number"]
            current_shares = shares - int(old_shares)
            db.execute("UPDATE stocks SET shares_number = ? WHERE share_symbol = ?", current_shares, current_symbol)
        if:
            db.execute("DELETE FROM stocks WHERE stock_symbol = ?", symbol)

        return redirect("/")
    else:
        rows = db.execute("SELECT share_symbol FROM stocks")
        for row in rows:
            look = lookup(row["share_symbol"])
            row["name"] = look["name"]
        return render_template("sell.html", rows=rows)
