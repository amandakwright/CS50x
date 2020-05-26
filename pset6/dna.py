import sys
import csv
from sys import argv


if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")


# open the csv file and read its contents into memory
with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile)
    firstline = next(reader)
    header = list(firstline)
    # print(header)


# open the DNA sequence and read its contents into memory
with open(sys.argv[2]) as f:
    sequence = f.readline()
    dna_counts = {}
    max_counts = {}
    for i in header:
        dna_counts[i] = 0
        max_counts[i] = 0
        j = 0
        while j <= len(sequence):
            if sequence[j:j + len(i)] == i:
                dna_counts[i] += 1
                if dna_counts[i] >= max_counts[i]:
                    max_counts[i] = dna_counts[i]
                # print(sequence[j:j+len(i)])
                j += len(i)
            else:
                # print(sequence[j:j+len(i)])
                dna_counts[i] = 0
                j += 1
    # print(max_counts)

with open(sys.argv[1]) as csvfile:
    database = csv.DictReader(csvfile)
    printed_name = False
    for row in database:
        match = 0
        for i in max_counts:
            # print("row: ", row[i])
            # print("max: ", max_counts[i])
            if row[i] == str(max_counts[i]):
                match += 1
                # print("match: ", match)
        # print(len(row))
        if (len(row) - 1) == match:
            print(row['name'])
            print_name = True
    if printed_name == False:
        print('No match')

