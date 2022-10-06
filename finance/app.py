import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

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

    #display buy form
    if request.method == "GET":
        return render_template("buy.html")

    else:
        symbol = request.form.get("symbol")
        quantity = request.form.get("quantity")

        #ensure a stock was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        #ensure quanity is submitted
        if not request.form.get("quantity"):
            return apology("must provide quantity")

        #lookup stock
        stock = lookup(symbol.upper())

        #if stock does not exist
        if stock == None:
            return apology("No stock found. :(")

        #find stock
        stock = lookup(symbol.upper())

        #find total price
        price = quantity * int(stock["price"])

        #find user id to select from database
        user_id = session["user_id"]

        #find user cash from data base
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id, id=user_id)

        #take user cash from user_cash_db returned dict
        user_cash = user_cash_db[0]["cash"]

        #check if user has enough cash
        if user_cash < price:
            return apology("Not enough funds. :(")

        updt_cash = user_cash - price

        #store updated cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?", id=user_id)
        new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        date = datetime.datetime.now()

        db.execute("INSERT INTO purchases (symbol, shares, price, date, user_id) VALUES (?, ?, ?, ?)", stock["symbol"], quantity, stock["price"], date, user_id)

        return redirect("/")













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

    #return html
    if request.method == "GET":
        return render_template("quote.html")

    else:
        symbol = request.form.get("symbol")

        #ensure a stock was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        #lookup stock
        stock = lookup(symbol.upper())

        #if stock does not exist
        if stock == None:
            return apology("No stock found. :(")

        return render_template("quoted.html", name = stock["name"], price = stock["price"], symbol = stock["symbol"])







@app.route("/register", methods=["GET", "POST"])
def register():

    #GET display a register form
    if request.method == "GET":
        return render_template("register.html")

    else:
        #get data from form
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        username = request.form.get("username")

        #if user did not submit username
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        #Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must reenter password", 403)

        #check if both passwords match
        elif password != confirmation:
            return apology("Passwords do not match.")

        #convert password to password hash
        hash = generate_password_hash(password)

        try:
            #insert new user into database
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        except:
            #if user name is already in data base return error
            return apology("Username already exists.", 403)

        #log user in
        session["user_id"] = new_user

        return redirect("/")




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
