# TODO
from cs50 import get_string
def main():
    # Prompt user for input
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    grade = float((0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8)
    if grade > 16:
        print(f"Grade 16+")
    elif grade < 1:
        print(f"Before Grade 1")
    else:
        print(f"Grade {round(grade)}")

# Count letters

def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if (text[i] >= "a" and text[i] <= "z") or (text[i] >= "A" and text[i] <= "A"):
            letters += 1
    return letters

# Count words

def count_words(text):
    words = 0
    for i in range(len(text)):
        if (text[i] == " "):
            words += 1
    return words

# Count sentences

def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if (text[i] == "!") or (text[i] == ".") or (text[i] == "?"):
            sentences += 1
    return sentences


main()