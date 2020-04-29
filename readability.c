#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    //prompt the user to input text
    string text = get_string("Text: ");

    //call count_letters function
    float letters = count_letters(text);
    //print out the number of letters in the text

    //call count_words function
    float words = count_words(text);
    //print out the number of words in the text

    //call count_sentences function
    float sentences = count_sentences(text);
    //print out the number of sentences in the text

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    float grade = roundf(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", grade);
    }

}

float count_letters(string text)
{
    //isalpha checks if uppercase OR if lowercase
    float sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            sum++;
        }
    }
    return sum;
}

float count_words(string text)
{
    //isgraph checks for any characters except space.
    float sum = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isgraph(text[i]) == 0)
        {
            sum++;
        }
    }
    return sum;
}

float count_sentences(string text)
{
    float sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sum++;
        }
    }
    return sum;
}








