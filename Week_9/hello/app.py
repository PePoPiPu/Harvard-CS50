from flask import Flask, render_template, request

app = Flask(__name__) #__name__ refers to the current file. "Turn this file into a Flask application"


@app.route("/") #The @ is called a decorator
def index():
    if "name" in request.args:
        name= request.args["name"]
    else:
        name="world"
    return render_template("index.html")