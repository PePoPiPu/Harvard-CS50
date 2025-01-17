import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna.py data.csv sequence.txt")
    subsequence = []
    match = {}
    str = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as csvFile:
        reader = csv.DictReader(csvFile)
        # Find number of columns in the csvFile
        # counting the columns reference
        ncol = len(next(reader)) - 1
        nrow = sum(1 for row in csvFile)
        subsequence = reader.fieldnames[1:]
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequences:
        sequence = sequences.read()
    # TODO: Find longest match of each STR in DNA sequence. Load it into dict
    for i in range(ncol):
        match[subsequence[i]] = longest_match(sequence, subsequence[i])
    # TODO: Check database for matching profiles
    with open(sys.argv[1], "r") as csvFile:
        reader = csv.DictReader(csvFile)
        no_matchcount = 0
        for row in reader:
            # Pop "name" column into variable
            name = row.pop("name")
            # Convert row values to int
            row_int = {}
            for i in range(ncol):
                row_int[subsequence[i]] = int(row[subsequence[i]])
            # Compare row values to match values
            if row_int == match:
                print(name)
            else:
                no_matchcount += 1
        if no_matchcount == nrow + 1:
            print("No match")
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if subsequence in sequence[start:end]:
                count += 1
            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
