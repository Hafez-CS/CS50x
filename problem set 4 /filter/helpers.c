#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
                             3.0); // average of the red, green, and blue values
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue); // the cs50x algorithm
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue); // the cs50x algorithm
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue); // the cs50x algorithm

            if (sepiaBlue >= 255) //  values will be whole numbers between 0 and 255, inclusive. for all value
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            if (sepiaGreen >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaRed >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ali[height][width];
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0) // we want to know about width number of pic
        {
            for (int k = 0; k < width / 2; k++)
            {
                ali[i][k] = image[i][k];
                image[i][k] = image[i][width - (k + 1)]; //  now we cahang it
                image[i][width - (k + 1)] = ali[i][k];
            }
        }
        else
        {
            for (int o = 0; o < (width - 1) / 2; o++)
            {
                ali[i][o] = image[i][o];
                image[i][o] = image[i][width - (o + 1)]; // again we cahnge it
                image[i][width - (o + 1)] = ali[i][o];
            }
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ali[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float sumBz = 0;
            float sumGz = 0;
            float sumRz = 0;
            int a = 0;

            for (int q = (0 - 1); q < (3 - 1); q++)
            {
                for (int w = (0 - 1); w < (3 - 1); w++)
                {
                    if (i + q < 0 || i + q > height - 1)
                    {
                        continue;
                    }

                    if (k + w < 0 || k + w > width - 1)
                    {
                        continue;
                    }

                    sumBz += image[i + q][k + w].rgbtBlue;
                    sumGz += image[i + q][k + w].rgbtGreen;
                    sumRz += image[i + q][k + w].rgbtRed;
                    a++;
                }
            }

            ali[i][k].rgbtBlue = round(sumBz / a);  // avarage for blu
            ali[i][k].rgbtGreen = round(sumGz / a); // avarage for green
            ali[i][k].rgbtRed = round(sumRz / a);   // avarage for red
        }
    }

    for (int b = 0; b < height; b++)
    {
        for (int o = 0; o < width; o++)
        {
            image[b][o].rgbtBlue = ali[b][o].rgbtBlue;   // the last answer of average blu
            image[b][o].rgbtGreen = ali[b][o].rgbtGreen; // the last answer of average green
            image[b][o].rgbtRed = ali[b][o].rgbtRed;     // the last answer of average red
        }
    }

    return;
}
