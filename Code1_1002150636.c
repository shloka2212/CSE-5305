#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MIN_ASCII 33
#define MAX_ASCII 126
#define rows 11
#define columns 7

// Function to print the 2D array to the screen
void printArray(char array[11][7])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(array[i][j] >= MIN_ASCII && array[i][j] <= MAX_ASCII ){
                printf("%c", array[i][j]);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_filename>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];

    // Create the output file name
    char *outputFileName = malloc(strlen(inputFileName) + 4); // ".out" is 4 characters long
    if (outputFileName == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    strcpy(outputFileName, inputFileName);
    int len = strlen(outputFileName);
    if (len >= 4)
    {
        strcpy(outputFileName + len - 4, ".out");
    }

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file");
        fclose(inputFile);
        free(outputFileName);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    // int rows = 11;
    // int columns = 7;

    // // Count the number of rows and columns in the file
    // while (fgets(line, sizeof(line), inputFile) != NULL) {
    //     rows++;
    //     int currentCols = strlen(line);
    //     if (currentCols > columns) {
    //         columns = currentCols;
    //     }
    // }

    // Rewind the input file to the beginning
    rewind(inputFile);

    // Allocate memory for the 2D array
    // char *array = (char *)malloc(rows * sizeof(char *));
    // for (int i = 0; i < rows; i++)
    // {
    //     array[i] = (char *)malloc(columns * sizeof(char));
    // }

    char array[11][7];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = 32;
        }
    }


    // Read through all lines in the file and populate the 2D array
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        int asciiSum = 0;
        int length = strlen(line);
        for (int i = 0; i < length; i++)
        {
            if(line[i]!= 10){
                asciiSum += line[i];
            }   
        }
       //printf("%d \n",length);
    
        //printf("%d \n",asciiSum);
        int row = asciiSum % rows;
        int col = asciiSum % columns;
        array[row][col] = (char)(asciiSum % (MAX_ASCII - MIN_ASCII + 1) + MIN_ASCII);
    }

    // Write the alphanumeric elements of the 2D array to the output file
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char c = array[i][j];
            if (c >= MIN_ASCII && c <= MAX_ASCII
                && ((array[i][j]>=65 && array[i][j]<=90)
                || (array[i][j]>=97 && array[i][j]<=122)
                || (array[i][j]>=48 && array[i][j]<=57)))
            {
                fputc(c, outputFile);
            }
        }
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    // Print the array to the screen if PRINTARRAY is defined
#ifdef PRINTARRAY
    printArray(array);
#endif

    // Free allocated memory
    // for (int i = 0; i < rows; i++)
    // {
    //     free(array[i]);
    // }
    // free(array);
    // free(outputFileName);

    return 0;
}
