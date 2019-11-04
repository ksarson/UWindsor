/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Sept. 23, 2015 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float x1, x2, x3, x4, x5;
	float variance, sd;
	float m;
	float d1, d2, d3, d4, d5;
	float d1sqr, d2sqr, d3sqr, d4sqr, d5sqr;
	float sumOfSqr;

	/*  Insturctions  */
	printf ("Type your 5 numbers \n");
	scanf ("%f %f %f %f %f", &x1, &x2, &x3, &x4, &x5);
	m = (x1 + x2 + x3 + x4 + x5) / 5.0;
	d1 = x1 - m;
	d2 = x2 - m;
	d3 = x3 - m;
	d4 = x4 - m;
	d5 = x5 - m;
	d1sqr = d1 * d1;
	d2sqr = d2 * d2;
	d3sqr = d3 * d3;
	d4sqr = d4 * d4;
	d5sqr = d5 * d5;
	sumOfSqr = d1sqr + d2sqr + d3sqr + d4sqr + d5sqr;
	variance = sumOfSqr / 5.0;
	sd = sqrt (variance);
	printf ("Score \t - \t Mean Score \t = \t Deviation Score \t Squared Deviation \n");
	printf ("(X) \t   \t (m) \t  \t \t (sd) \t \t \t (x-m)squared \n");
	printf ("---------------------------------------------------------------------------- \n");
	printf ("%f \t %f \t \t %f \t \t %f \n", x1, m, d1, d1sqr);
	printf ("%f \t %f \t \t %f \t \t %f \n", x2, m, d2, d2sqr);
	printf ("%f \t %f \t \t %f \t \t %f \n", x3, m, d3, d3sqr);
	printf ("%f \t %f \t \t %f \t \t %f \n", x4, m, d4, d4sqr);
	printf ("%f \t %f \t \t %f \t \t %f \n", x5, m, d5, d5sqr);
    printf ("\t \t \t \t \t \t \t Sum: \t %f \n", sumOfSqr);
    printf ("Variance = %f/5 = %f \n", sumOfSqr, variance);
    printf ("Standard Deviation = sd = %f \n", sd);
	return 0;
}