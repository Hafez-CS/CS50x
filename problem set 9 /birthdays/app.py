import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        message = ""
        inname = request.form.get("name")
        inday = request.form.get("day")
        inmonth = request.form.get("month")
        if inname == "":
            message = "please enter your name"
        elif inday == "":
            message = "please enter your day of birth"
        elif inmonth == "":
            message = "please enter your day of birth"
        else:
            db.execute(
                "INSERT INTO birthdays (name, day , month) VALUES(? , ? , ?)",
                inname,
                inday,
                inmonth,
            )
            birthdays = db.execute("SELECT * FROM birthdays")
            return render_template("index.html", message=message, birthdays=birthdays)
    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)
