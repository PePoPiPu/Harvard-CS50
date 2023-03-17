import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

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
    return apology("TODO")


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
        if cash_current > (int(symbol["price"] * int(request.form.get("shares")))):
            balance = cash_current - (int(symbol["price"] * int(request.form.get("shares"))))
            db.execute("UPDATE cash FROM users SET VALUES(?) WHERE id = :id", balance, id=session["user_id"])
            # Create new table to keep track of the purchase
        else:
            return apology("Can't afford number of shares at current price")
        redirect ("/")

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
    return apology("TODO")
