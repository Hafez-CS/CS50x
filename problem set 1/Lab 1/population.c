#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // TODO: Prompt for start size
    int startsize;
    do
    {
        startsize = get_int("pleas enter start size number between 1,8 : ");
    }
    while (startsize < 9);


    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("pleas enter end size number , smaller than start size number : ");
    }
    while (endsize < startsize);





    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (startsize < endsize)
    {
        startsize = startsize + (startsize / 3) - (startsize / 4);
        years++;
    }



    // TODO: Print number of years
    printf("Years: %i\n", years);



}
