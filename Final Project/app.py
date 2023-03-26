import os

# Importing modules
from cs50 import SQL
from flask import Flask
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

# Configuring the app
app = Flask(__name__)