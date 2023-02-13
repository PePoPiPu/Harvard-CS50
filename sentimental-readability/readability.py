# TODO
from cs50 import get_string
def main():
    # Prompt user for input
    text = get_string("Text: ")
    print(f"{text}")



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