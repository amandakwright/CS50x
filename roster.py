import sys
import cs50
from sys import argv
from cs50 import SQL


# check command-line arguments
if len(argv) != 2:
    print("Usage: python roster.py house")

house_name = sys.argv[1]
db = SQL("sqlite:///students.db")
list = db.execute("SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last ASC, first ASC", house_name);

for row in list:
    birth = int(row["birth"])
    if row["middle"] == None:
        name = row["first"] + " " + row["last"] + "," + " " + "born"
        print(name, birth)
    else:
        name = row["first"] + " " + row["middle"] + " " + row["last"] + "," + " " + "born"
        print(name, birth)