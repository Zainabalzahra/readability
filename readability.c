#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Take input from the user
    string text = get_string("Text: ");

    //Declare the variables
    int letters = 2;
    int words = 0;
    int sentences = 1;

    //Finding the letters, words and sentences.
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    //The formula to find the grade
    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Printing the grade
    if (index < 1)
    {
        printf("Before Grade 1");
    }

    else if (index > 16)
    {
        printf("Grade 16+");
    }

    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}