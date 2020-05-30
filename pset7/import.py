import cs50
import csv
import sys
from sys import argv
from cs50 import SQL


# check command-line arguments
if len(argv) != 2:
    print("Usage: python import.py characters.csv")


# create SQL database
open(f"students.db", "w").close()
db = SQL("sqlite:///students.db")
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")


# open csv file given by command-line argument
with open(sys.argv[1], "r") as csvfile:
    reader = csv.DictReader(csvfile)
    # for each row, parse name
    for row in reader:
        for i in row:
            if row[i] == row["name"]:
                name_split = row[i].split()
                name_count = len(name_split)
                birth = int(row["birth"])
                print(birth)
                if name_count == 2:
                    first_name = name_split[0]
                    middle_name = None
                    last_name = name_split[1]
                    # insert each student into the students table of students.db
                    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, row["house"], birth)
                if name_count == 3:
                    first_name = name_split[0]
                    middle_name = name_split[1]
                    last_name = name_split[2]
                    # insert each student into the students table of students.db
                    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, row["house"], birth)
