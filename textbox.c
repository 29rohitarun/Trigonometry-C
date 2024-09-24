/**
 * @file textbox.c
 * @author Rohit Arun (rarun3)
 * This program prints text from standard input encased in a
 * textbox of printed astericks
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Width of each line of text in the box. */
#define LINE_WIDTH 60

/** Symbol used to draw the border around the box. */
#define BORDER '*'

/**
 * Reads a single line of text from standard input, prints it inside a bordered box
 * The box is rectangular, with extra spaces added at the end if the line is not long enough
 * If the line is too long, it reads and discards the extra characters.
 * 
 * @return boolean false if end of file is reached prematurely
 * true if funciton executes fully.
  */
bool paddedLine()
{
  int count = 0;
  int character = getchar();

  // checking for end of file
  if ( character == EOF ) {
    return false;
  }

  // prints borcer character ouptut stream
  putchar( BORDER );

  while ( character != '\n' && count < LINE_WIDTH ) {

    // prints character to ouptut stream
    putchar( character );
    count++;
    character = getchar();
  }
  while( character != '\n') {
    character = getchar();
  }

  int wdtcnt = count;

  while( wdtcnt < LINE_WIDTH ) {
    // prints space character ouptut stream
    putchar( ' ' );
    wdtcnt++;
  }

  // prints border character ouptut stream
  putchar( BORDER );
  // prints newline character ouptut stream
  putchar( '\n' );
  return true;

}

/**
 * Prints multiple occurrences of the specified character, followed by a newline.
 * The number of occurrences is determined by the count parameter.
 * 
 * @param ch asterick character being passed through from main function
 * @param count line width passed in from main function
  */
void lineOfChars( char ch, int count )
{
  for ( int i = 0; i < count + 2; i++ ) {
    // prints character ouptut stream
    putchar( ch );
  }
  // prints newline character ouptut stream
  putchar( '\n' );
}

/**
 * Uses the other functions above to print the text 
 * from standard input/input file with a border around it.
 * 
 * @return successful status
  */
int main()
{
  lineOfChars( BORDER, LINE_WIDTH );
  bool retVal;

  // calles paddedLine funciton until it returns false
  do {
    retVal = paddedLine();
  } while ( retVal );

  lineOfChars( BORDER, LINE_WIDTH );
  return 0;
}
