from flask import Flask, render_template, request

app = Flask(__name__) #__name__ refers to the current file. "Turn this file into a Flask application"


@app.route("/", methods=["GET", "POST"]) #The @ is called a decorator
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
        #request.args is used when the method is GET. request.form is used when the method is POST

