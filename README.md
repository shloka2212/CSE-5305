# Coding Assignment 1

Your assignment's C file name will be Code1_xxxxxxxxxx.c where xxxxxxxxxx is your student id. The rest of this document will refer to the program Code1.c.

## High Level Description:

Code1.c will perform the following actions:

1. Read an input file that is a list of words (see examples). The filename should be obtained from the command line arguments.
2. Use the input file to create the output file name. The output file name should be created using the input file name but with the extension of the input file name replaced with “out”.
3. Open the files and, if either file does not open, exit the program.
4. Read through all lines in the file – a single line in the file may contain multiple words.
5. For each line in the file, calculate the ASCII sum of that line.
6. Use modulus with the number of rows in the 2D array and the ASCII sum to determine a row value within the limits of the 2D array
7. Use modulus with the number of columns in the 2D array and the ASCII sum to determine a column value within the limits of the 2D array
8. Use modulus with the ASCII sum to calculate a value within the printable range of ASCII value (ASCII 33 through ASCII 126). Store this result in the 2D array using the calculated row value and the calculated column value.
9. After all lines have been read from the file and stored in the 2D array, write the alphanumeric elements of the 2D array to a single line in the output file.
10. Use a conditional compile statement of PRINTARRAY in main() to call a function that prints the 2D array to the screen.
11. The dimensions of the 2D array should be set at the top of the program in a define for ROWS and a define for COL.

You need to create your own input file. An example file is shown here with the resulting output to help you understand how the program must be written. You can test your code with this example file; however, your code will be graded using both a file created by you and another test file provided by the instructor for grading purposes.

Example:

If the array is 11 rows by 7 columns and a line of the file is
Hello there!

then the ASCII value of that line is
H(72)+e(101)+l(108)+l(108)+o(111)+ (32)+t(116)+h(104)+e(101)+r(114)+e(101)+!(33) = 1101
1101 % 11 (number of rows) = 1
1101 % 7 (number of columns) =2

The [1][2] cell of the 2D array will be updated with the character result of using modulus to transform 1101 into a value within the printable ASCII range (33 through 126).
No ASCII values should be hardcoded in the program.
