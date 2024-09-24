/**
 * @file style.c
 * @author Rohit Arun (rarun3)
 * This program uses the random number generator to output a 
 * randomly generated paragraph of text
*/
#include <stdio.h>
#include <stdlib.h>

/* Constant for value of 72*/
#define SEVENTYTWO 72
/* Constant for value of 97*/
#define NINETYSEVEN 97
/* Constant for value of 26*/
#define TWENTYSIX 26
/* Constant for value of 10*/
#define TEN 10

/**
 * Uses a for-loop to print a random lowercase letter
 * 
 * @param x number of for-loop iterations 
*/
void printWord( int x )
{
    for ( int i = 0; i < x; i++ ) {
        // Print a random lower-case letter.
    	printf( "%c", NINETYSEVEN + rand() % TWENTYSIX );
    }
}

/**
 * Concatenates and prints line while the sum of the position, 
 * length, and space is less than 72
 * 
 * @return count the length derived from the while-loop
*/
int printLine() 
{
	int count = 0, pos = 0, space = 0;
	int len = 1 + rand() % TEN;
	// Print a line of words up to a limited length.
	while ( pos + len + space < SEVENTYTWO ) {
		if ( space > 0 ) {
			printf( " " );
        }
		printWord( len );
		pos += len + space;
		len = 1 + rand() % TEN;
		space = 1;
		count += 1;
	}
	printf( "\n" );
	return count;
}

/**
 * Concatenates lines into a paragraph using for-loop from i until the 
 * limit provided through the parameter of the function
 * 
 * @param n limit for the function's for-loop iteration 
 * @return total total number of lines.
*/
int printParagraph( int n )
{
	int total = 0;
	//Concatenates return value form printLine funtion to total
	for ( int i = 0; i < n; i++ ) {
		total += printLine();	
	}
	return total;
}

/**
 * Calls printParagraph function by passing the constant for 10
 * as the parameter
 * formats the output to the terminal
 * 
 * @return program exit status
*/
int main()
{
	// Passes constant for 10 as a parameter to printParagrap
	// So the for-loop in printParagraph will be dictated by this parameter
	int w = printParagraph( TEN );
	printf( "Words: %d\n",w );
	return 0;
}