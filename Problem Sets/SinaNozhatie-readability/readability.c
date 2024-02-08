#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int words_count(string text);
int sentences_count(string text);

int main(void)
{
    int letters, words, sentences;
    float index;
    string text;

    text = get_string("Sentence:");

    letters = count_letters(text);

    words = words_count(text);

    sentences = sentences_count(text);

    float L = 100.0 * letters / words; // Average Letters in 100 words

    float S = 100.0 * sentences / words; // Average Sentences in 100 words

    // printf("Average L in 100 W:%f\n",L);

    // printf("Average S in 100 W:%f\n",S);

    index = (0.0588 * L) - (0.296 * S) - 15.8;

    // printf("number of letters:%i\n",letters);

    // printf("number of words:%i\n",words);

    // printf("number of sentences:%i\n",sentences);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int letter = 0;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i])) // not calculating the SPACEs
        {
            letter++;
        }
    }
    return letter;
}

int words_count(string text)
{
    int words = 1; // because it gives us 1 less word
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int sentences_count(string text)
{
    int sentences = 0;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') // counts the number of sentences
        {
            sentences++;
        }
    }
    return sentences;
}
