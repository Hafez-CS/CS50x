#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function for number
int letters(string word);
int words(string word);
int sentences(string word);




int main(void)
{

    // Get input words from both players
    string text = get_string("Text: ");







    // Score both words
    float x = letters(text);
    float y = words(text);
    float z = sentences(text);


    // TODO: Print the winner





//printf("%f \n",x);
//printf("%f \n",y);
//printf("%f \n",z);

    float r = (x / y) * 100 ;
    float e = (z / y) * 100 ;
    float c = (0.0588 * r - 0.296 * e - 15.8);

    int u = round(c);

// find out about grades
    if (u < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (u > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", u);
    }



}






















// forletters
int letters(string word)
{


    int a = strlen(word);
    int b = 0;
    int n = 0;
    int p = 0;
    char g;



    for (int i = 0 ; i < a ; i++)
    {

        g = word[i];

        if ((g >= 65 &&  g <= 90) || (g >= 97 &&  g <= 122))
        {
            b += 1;

        }

    }



    return b;


}






// for words
int words(string word)
{



    int c = strlen(word);
    int t = 0;
    char g;
    int i = 0;


    do
    {

        g = word[i];

        if ((g >= 65 &&  g <= 90)  || (g == 45) || (g == 39) || (g >= 97 &&  g <= 122))
        {

            t += 1;


            do
            {

                i += 1;
                g = word[i];

            }
            while ((g >= 65 &&  g <= 90)  || (g == 45) || (g == 39) || (g >= 97 &&  g <= 122)); // find word between a-z


        }
        else
        {
            i += 1;
        }

    }
    while (i < c);




    return t;

}












// for sentences
int sentences(string word)
{




    int a = strlen(word);
    int t = 0;
    int r = 0;
    int q = 0;
    char g;





    for (int i = 0 ; i < a ; i++)
    {

        g = word[i];

        if ((g == 46) || (g == 33) || (g == 63))
        {
            t += 1 ;

        }

    }


    return t;


}



















