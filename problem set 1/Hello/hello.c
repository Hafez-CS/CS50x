#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //you can say your name to machine and get the answer

    string a = get_string("What's your name my friend? ");
    // this line can get your name
    printf("hello, %s\n", a);
    // this line can say hello with your name
}
