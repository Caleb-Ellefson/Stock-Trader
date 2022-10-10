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

    #find user id
    user_id = session["user_id"]

    #Select the symbol of stock add the shares togther and seperate the sum of shares by symbol
    purchases_db = db.execute("SELECT symbol, SUM(SHARES) AS shares, price FROM purchases WHERE user_id = ? AND shares >= 1 AND type = 'BUY' GROUP BY symbol", user_id)

    #total amount of stocks purchased
    total = db.execute("SELECT SUM(price) AS total FROM purchases WHERE user_id = ?", user_id)
    total = total[0]['total']

    #find users cash
    cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = cash_db[0]["cash"]

    #render the database to the template
    return render_template("index.html", database=purchases_db, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    #display buy form
    if request.method == "GET":
        user_id = session["user_id"]

        #Select the symbol of stock add the shares togther and seperate the sum of shares by symbol
        purchases_db = db.execute("SELECT symbol, SUM(SHARES) AS shares, price FROM purchases WHERE user_id = ? AND shares >= 1 AND type = 'BUY' GROUP BY symbol", user_id)

        #find users cash
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]["cash"]
        return render_template("buy.html", database=purchases_db, cash=cash)

    else:
        symbol = request.form.get("symbol")
        quantity = int(request.form.get("quantity"))

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
        total_price = quantity * stock["price"]

        #find user id to select from database
        user_id = session["user_id"]

        #find user cash from data base
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)

        #take user cash from user_cash_db returned dict
        user_cash = float(user_cash_db[0]["cash"])

        #check if user has enough cash
        if total_price > user_cash:
            return apology("Not enough funds. :(")

        updt_cash = user_cash - total_price

        #store updated cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        date = datetime.datetime.now()

        db.execute("DELETE FROM purchases WHERE symbol = ? AND ")
        db.execute("INSERT INTO history (symbol, shares, price, date, user_id, type, owned) VALUES (?, ?, ?, ?, ?, 'BUY', 1)", stock["symbol"], quantity, stock["price"], date, user_id)


        flash("Purschased!")

        return redirect("/")



@app.route("/history")
@login_required
def history():

    if request.method == "GET":
            #find user id
        user_id = session["user_id"]

        #Select the symbol of stock add the shares togther and seperate the sum of shares by symbol
        purchases_db = db.execute("SELECT * FROM purchases WHERE user_id = ?", user_id)


        #render the database to the template
        return render_template("history.html", database=purchases_db)



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

    if request.method == "GET":

        user_id = session["user_id"]

        #Select the symbol of stock add the shares togther and seperate the sum of shares by symbol
        purchases_db = db.execute("SELECT symbol, SUM(SHARES) AS shares, price FROM purchases WHERE user_id = ? AND shares >= 1 AND type = 'BUY' GROUP BY symbol", user_id)

        #find users cash
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]["cash"]

        return render_template("sell.html", database=purchases_db, cash=cash)

    else:
        symbol = request.form.get("symbol")
        quantity = int(request.form.get("shares"))

        #ensure a stock was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        #ensure quanity is submitted
        if not request.form.get("shares"):
            return apology("must provide quantity")

        #lookup stock
        stock = lookup(symbol.upper())

        #if stock does not exist
        if stock == None:
            return apology("No stock found. :(")

        #find total price
        total_price = quantity * stock["price"]

        #find user id to select from database
        user_id = session["user_id"]

        #find user cash from data base
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)

        #take user cash from user_cash_db returned dict
        user_cash = float(user_cash_db[0]["cash"])
        updt_cash = user_cash + total_price

        #find user shares
        user_shares = db.execute("SELECT shares FROM purchases WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)
        user_share_real = user_shares[0]["shares"]
        
        if quantity > user_share_real:
            return apology("You do not have enough shares.")

        if user_shares == 0:
            return apology("You do not have enough shares.")

        #store updated cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        date = datetime.datetime.now()

        db.execute("INSERT INTO purchases (symbol, shares, price, date, user_id, type) VALUES (?, ?, ?, ?, ?, 'SELL')", stock["symbol"], quantity, stock["price"], date, user_id)
        db.execute("INSERT INTO history (symbol, shares, price, date, user_id, type, owned) VALUES (?, ?, ?, ?, ?, 'BUY', 1)", stock["symbol"], quantity, stock["price"], date, user_id)


        #add sum of stock symbol wanting to be sold
        #Select the symbol of stock add the shares togther and seperate the sum of shares by symbol
        owned_shares = db.execute("SELECT ?, SUM(SHARES) AS shares, price FROM purchases WHERE user_id = ?", symbol, user_id)
        # if stock symbol = 0 delete it from purchases
        flash("Sold!")

        return redirect("/")












