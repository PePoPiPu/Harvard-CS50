import os

# Importing modules
from cs50 import SQL
from flask import Flask, render_template, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

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
    return render_template("page_not_found.html"), 404

# Error handler for bad request (400)
@app.errorhandler(400)
def handle_bad_request(e):
    return render_template("bad_request.hmtl"), 400

# Index
@app.route("/")
@login_required
def index():
    if request.method == "GET":
        return render_template("index.html")

# Login
@app.route("/login", methods=["GET", "POST"])
def login():
    """ Log user in """

    # Forget any user_id
    session.clear()

    # User reached route via POST
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return handle_bad_request(400)

        #Ensure password was submitted
        if not request.form.get("password"):
            return handle_bad_request(400)

        # Query database for a username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return handle_bad_request(400)

        # Remember what user was logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to homepage
        return redirect("/")

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
    return redirect("/")

# Register
@app.route("/register")
def register():
    """ Register user """
    if request.method == "POST":

        # Declaring variables to work with them later
        username = request.form.get("username")
        password = request.form.get("password")

        # Ensure username was submitted
        if not request.form.get("username"):
            return handle_bad_request(400)

        # Check if any rows are returned from the query
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if len(rows) != 1:

            # Password length validation
            if len(password) < 8:
                return handle_bad_request(400)

            # Ensure password was submitted
            if not request.form.get("password"):
                return handle_bad_request(400)
            elif password != request.form.get("confirmation"):
                return handle_bad_request(400)

            # Hash new password
            hash = generate_password_hash(password, method="pbkdf2:sha256", salt_length=32)

            # Insert new username and hash into users table
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

            return render_template("login.html")

        else:
            # I think this is redundant code. if len(rows) != 1 already checks username existance
            row = db.execute("SELECT username FROM users WHERE username = ?", username)
            user_check = row[0]["username"]
            if username == user_check:
                return handle_bad_request(400)

    # Reached route via GET
    else:
        return render_template("register.html")
