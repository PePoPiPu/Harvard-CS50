import os

# Importing modules
from cs50 import SQL
from flask import Flask, render_template, redirect, request, session, url_for, flash
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import date

from helpers import login_required
# Configuring the app
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 library to use SQLite database
db = SQL("sqlite:///psp.db")

@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Error handler for 404
@app.errorhandler(404)
def page_not_found(error):
    return ("Page Not Found"), 404

# Error handler for bad request (400)
@app.errorhandler(400)
def handle_bad_request(e):
    return ("Bad Request"), 400

# Index
@app.route("/")
@login_required
def index():
    if request.method == "GET":
        today = date.today()
        return render_template("index.html", today)

# Login
@app.route("/login", methods=["GET", "POST"])
def login():
    """ Log user in """

    # Forget any user_id
    session.clear()

    # Set error variable for message flashing
    error = None

    # User reached route via POST
    if request.method == "POST":

        # Query database for a username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        count = db.execute("SELECT COUNT (username) FROM users WHERE username = ?", request.form.get("username"))
        # Ensure credentials are correct
        if count[0]["COUNT (username)"] == 0:
            error = "Invalid credentials"
            return render_template("login.html", error=error)
        else:
            validation = None
            # Remember what user was logged in
            session["user_id"] = rows[0]["id"]
            validation = "You're logged in!"
            return render_template("index.html", validation=validation)

    # User reached route via GET
    else:
        return render_template("login.html")

# Logout
@app.route("/logout")
def logout():
    """ Log user out """

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/login")

# Register
@app.route("/register", methods=["GET", "POST"])
def register():
    """ Register user """

    # Set error variable for message flashing
    error = None
    if request.method == "POST":

        # Declaring variables to work with them later
        username = request.form.get("username")
        password = request.form.get("password")

        # Ensure username was submitted
        if not request.form.get("username"):
            error = "Must input a username"
            return render_template("register.html", error=error)

        # Check if any rows are returned from the query
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if len(rows) != 1:

            # Ensure password was submitted
            if not request.form.get("password"):
                error = "Must input a password"
                return render_template("register.html", error=error)

            # Password length validation
            if len(password) < 8:
                error = "Password has to be at least 8 characters long"
                return render_template("register.html", error=error)

            elif password != request.form.get("confirmation"):
                error = "Passwords don't match!"
                return render_template("register.html", error=error)

            # Hash new password
            hash = generate_password_hash(password, method="pbkdf2:sha256", salt_length=32)

            # Insert new username and hash into users table
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

            validation = ("You were registered successfully")
            return render_template("login.html", validation=validation)

        else:
            # I think this is redundant code. if len(rows) != 1 already checks username existance
            row = db.execute("SELECT username FROM users WHERE username = ?", username)
            user_check = row[0]["username"]
            if username == user_check:
                return ("Hello i'm a bad request"), 400

    # Reached route via GET
    else:
        return render_template("register.html")

@app.route("/staff", methods=["GET", "POST"])
@login_required
def staff():
    if request.method == "GET":
        return render_template("staff.html")