#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float RGB_average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGB_average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3;
            image[i][j].rgbtBlue = roundf(RGB_average);
            image[i][j].rgbtGreen = roundf(RGB_average);
            image[i][j].rgbtRed = roundf(RGB_average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed = 0;
    float sepiaGreen = 0;
    float sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = ((image[i][j].rgbtBlue * 0.189) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtRed * 0.393));
            sepiaGreen = ((image[i][j].rgbtBlue * 0.168) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtRed * 0.349));
            sepiaBlue = ((image[i][j].rgbtBlue * 0.131) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtRed * 0.272));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtBlue = roundf(sepiaBlue);
            image[i][j].rgbtGreen = roundf(sepiaGreen);
            image[i][j].rgbtRed = roundf(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
// for each row - swap pixels on horizontally opposite sides
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width - j - 1; j++)
        {
            int k = width - j - 1;
            temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_pixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = 0;
            float new_red = 0;
            float new_green = 0;
            float new_blue = 0;
            for (int a = i - 1; a <= i + 1; a++)
            {
                if (a >= 0 && a <= height - 1)
                {
                    for (int b = j - 1; b <= j + 1; b++)
                    {
                        if (b >= 0 && b <= width - 1)
                        {
                            new_red += image[a][b].rgbtRed;
                            new_blue += image[a][b].rgbtBlue;
                            new_green += image[a][b].rgbtGreen;
                            average++;
                        }
                    }
                }
            }
            new_pixel[i][j].rgbtRed = roundf(new_red / average);
            new_pixel[i][j].rgbtBlue = roundf(new_blue / average);
            new_pixel[i][j].rgbtGreen = roundf(new_green / average);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = new_pixel[i][j].rgbtRed;
            image[i][j].rgbtBlue = new_pixel[i][j].rgbtBlue;
            image[i][j].rgbtGreen = new_pixel[i][j].rgbtGreen;
        }
    }
    return;
}
