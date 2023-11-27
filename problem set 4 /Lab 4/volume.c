
// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t ali[HEADER_SIZE];                             // unit8-t this is for haeder
    fread(&ali, HEADER_SIZE, 1, input);                   // we can read the value  =  read(value , size , object , to this file)
    fwrite(&ali, HEADER_SIZE, 1, output);                 // we can write that value = write(value , size , object , to this file)
    // TODO: Read samples from input file and write updated data to output file
    int16_t fi;
    while (fread(&fi, sizeof(int16_t), 1, input))
    {
        fi *= factor;
        fwrite(&fi, sizeof(int16_t), 1, output);                  // this is the last work for making a new voice
    }
    // Close files
    fclose(input);
    fclose(output);
}
