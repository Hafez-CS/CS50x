#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *a = fopen(argv[1], "r");

    unsigned char *bb = malloc(512);

    if (bb == NULL)
    {
        return 1;
    }

    char *s = malloc(3 * sizeof(int));

    if (s == NULL)
    {
        return 1;
    }

    int nu = 0;

    while (fread(bb, sizeof(unsigned char), 512, a))
    {
        if (bb[0] == 0xff && bb[1] == 0xd8 && bb[1] == 0xd8 && bb[2] == 0xff && (bb[3] & 0xf0) == 0xe0)
        {
            sprintf(s, "%03i.jpg", nu);
            FILE *nh = fopen(s, "w");
            fwrite(bb, 1, 512, nh);
            fclose(nh);
            nu++;
        }
        else if (nu != 0)
        {
            FILE *nh = fopen(s, "a");
            fwrite(bb, 1, 512, nh);
            fclose(nh);
        }
    }

    fclose(a);
    free(s);
    free(bb);
}
