from cs50 import get_string


#prompt the user to input text
def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (int(letters) / int(words)) * 100
    S = (int(sentences) / int(words)) * 100
    index = (0.0588 * L) - (0.296 * S) - 15.8
    grade = round(index)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    letter_sum = 0
    for a in text:
        if (a.isalpha()) == True:
            letter_sum+=1
    return letter_sum


def count_words(text):
    for b in text:
       word_count = len(text.split())
    word_sum = str(word_count)
    return word_sum


def count_sentences(text):
    sentence_sum = 0
    for c in text:
        if (c == "." or c == "?" or c == "!"):
            sentence_sum += 1
    return sentence_sum


main()
