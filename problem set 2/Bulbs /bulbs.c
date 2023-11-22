#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096}; // binary table
void print_bulb(int bit);





int main(void)
{






    string text = get_string("text :"); // get word

    int f = strlen(text);    // len of the word

    for (int j = 0 ; j < f ; j++)
    {

        char G = text[j];
        int u = G;            //  number of word

        int c = 0;
        int v = 0;
        int k = 8;

        do
        {
            c += 1;
        }
        while (u >= a[c]);

        c -= 1;

        int l = c;


        int w = 8 - c;



        for (int x = 1 ; x < w ; x++)
        {
            printf("\U000026AB"); // off light
        }



        for (int h = 0 ; h <= l ; h++)
        {

            int y = a[c];

            if (u >= y)
            {

                u = u - y;

                printf("\U0001F7E1");    // on light

                k -= 1;
            }
            else
            {

                printf("\U000026AB");    // off light

                k -= 1;

            }


            c -= 1;

        }


        printf("\n");





    }


}
