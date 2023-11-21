#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("pleas enter number between 1,8 : ");
        // we cant get a number
    }
    while (n > 8 || n < 1);





    // and we can make a mario with space
    for (int i = 0 ; i < n ; i++)
    {


        for (int b = 0 ; b <= i ; b++)
        {


            for (int c = 1 ; c < n - i ; c++)
            {
                printf(" ");     //here we can make space
            }

            for (int z = 0 ; b <= i ; b++)
            {
                printf("#");    // here we can make #
            }


        }

        printf("\n");


    }




}
