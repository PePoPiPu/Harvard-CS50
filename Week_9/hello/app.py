from flask import Flask, render_template, request

app = Flask(__name__) #__name__ refers to the current file. "Turn this file into a Flask application"


@app.route("/") #The @ is called a decorator
def index():
    return render_template("index.html")