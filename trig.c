/**
 * @file textbox.c
 * @author Rohit Arun (rarun3)
 * Reads user's input of angle and prints a table 
 * of outputs progressively more accurate approximations 
 * of the sin, cos, and tan of x
 * 
*/
#include <stdio.h>
#include <stdlib.h>

/** Approximation of PI.  For now, we're using our own constant for
    this. There's also one provided by the gnu math library, once we
    learn about that. */
#define PI 3.14159265358979323846

/**
 * Retrieves the angle input from either user input 
 * or an input file, ensuring it is a valid real number 
 * within the appropriate range.
 * 
 * @return ang valid angle
*/
double getAngle()
{
  double ang;
  int valid = scanf("%le", & ang);

  if ( valid == 0 ) {
    printf( "Invalid input\n" );
    exit( 1 );
  }
  if ( ang > PI || ang < ( PI * -1 ) ) {
    printf( "Invalid input\n" );
    exit( 1 );
  }
  return ang;
}
/**
 * Function determines the level of accuracy achieved 
 * by the current estimates of sine and cosine.
 * 
 * @return diff difference between angle a and b
*/
double difference( double a, double b )
{
  if ( ( b - a ) < 0 ) {
    return ( b - a ) * -1;
  }
  double diff;
  diff = b - a;
  return diff; 
}


/** 
 * Function provides information about the total 
 * number of terms utilized in the Taylor series approximation.
 * 
 * @param terms term
 * @param s sin value
 * @param c cosvalue
 * @param t tan value
*/
void tableRow( int terms, double s, double c, double t )
{
  printf ( "%5d |  %10.7f |  %10.7f |  %10.7f\n", terms, s, c, t );
}


/**
 * Function prints the headears and columns for the table
*/
void tableHeader()
{
  printf ("terms |         sin |         cos |         tan \n");
  printf ("------+-------------+-------------+-------------\n");
}


/**
 * Computes the factorial of a given value for use in the Taylor series calculation
 * 
 * @param factorVar The value for which the factorial is computed.
 * @return The factorial of the given value.
*/
double factorial(int factorVar) 
{
  int result = 1;

  for ( int i = 2; i <= factorVar; i++ ) {
    result *= i;
  }

  return result;
}

/**
 * Function calculates the exponents in the numerators of the Taylor series
 * 
 * @param value number value
 * @param exp exponent value
*/
double exponent(double value, int exp) 
{
  double pow = 1;

  for ( int i = 1; i <= exp; ++i ) {
    pow = pow * value;
  }

  return pow;
}

/**
 * Reads user input and implement the Taylor 
 * Sequence using the above functions to
 * create an output table in the terminal
 * 
 * @return successful return value
  */
int main()
{
  double angle = getAngle();

  double thresh = 0.000001;
  int termVar = 1;
  int cosSign = -1;
  int sinSign = 1;
  double cos, sin, tan;
  double sinSum, cosSum;
  double cosDiff = 1, sinDiff = 1;

  tan = 0, cos = 1, sin = 0;

  tableHeader();
  tableRow(termVar, sin, cos, tan);
  termVar++;

  while (sinDiff > thresh && cosDiff > thresh) {

    if (termVar % 2 == 0) {
      sinSum = sin + sinSign * (exponent(angle, termVar - 1)) / factorial(termVar - 1);

      // subtracts the second parameter from the first parameter
      sinDiff = difference(sin, sinSum);
      sin = sinSum;
      sinSign = sinSign * -1;
    } else if (termVar % 2 != 0) {
      cosSum = cos + cosSign * (exponent(angle, termVar - 1)) / factorial(termVar - 1);

      // subtracts the second parameter from the first parameter
      cosDiff = difference(cos, cosSum);
      cos = cosSum;
      cosSign = cosSign * -1;
    }

    tan = sin / cos;
    tableRow(termVar, sin, cos, tan);
    termVar++;
  }
  return 0;
}
