/**
 * @file	/home/johnsteele/Desktop/css422/hw_3/main.c
 * @author	John Steele <EMAIL:programjsteele {at} gmail {dot} com>
 * @version	1.0.0
 * @date
 * 	Created:	Sat 15 Jan 2011 07:12:37 PM PST \n
 * 	Last Update:	Sat 15 Jan 2011 07:12:37 PM PST
 */

/*
 * Description:	This program takes a hexadecimal number from the command
 *					    line, which it interprets to be a IEEE single precision 
 *					    floating-point value and prints it out as 2 to the
 *					    exponent times the sum of powers of 2. 
 */


/*===============================[ Includes ]================================*/ 
#include	<stdio.h> 
#include	<stdlib.h> /* EXIT_SUCCESS/FAILURE, malloc */ 
#include	<ctype.h>  /* toupper */
#include	<string.h> /* strtok */



/*===============================[ Valid Hex ]================================*/ 
/**
 * @brief Valid hexadecimal characters.
 */
static const char VALID_HEX [] = {'0', '1', '2', '3', '4', '5', '6', '7', 
																  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
																	'a', 'b', 'c', 'd', 'e', 'f'};

/**
 * @brief Number of bits per hex value.
 */
#define	NIBBLE 4

/**
 * @brief The binary32 exponent bias. 
 */
#define	BIAS 127

/*===============================[ Prototypes ]==============================*/ 
bool validate_hex (char *&hex);
int  hex_value    (char c);
void calculate    (int  bits);
int  get_exponent (int  bits);


/*===========================================================================*/
/**
 * @brief The main method for this driver.  
 *
 * @param argc The number of command line arguments. 
 * @param argv A pointer to an array of command line switches.  
 * @return EXIT_SUCCESS
 */ 
/*===========================================================================*/
int main (int argc, char **argv)
{ 
	int hex_count  = 0;
	int hex_bits   = 0;
	int hex_length = 0;
	int index		   = 0;
	char *hex      = argv [1];

	// Check for valid hexadecimal value. 	
	if (validate_hex (hex)) { 
	 	index = hex_length = strlen (hex);	

		// Convert the hex string to int bits.  
		while (hex_count < hex_length)  
		 	hex_bits |= (hex_value (hex [hex_count++]) << (--index * NIBBLE));

		// Display the hexadecimal value.
		printf ("%s %s", hex, " ==> ");	
	
		// Calculate the powers. 
  	calculate (hex_bits);			
	} 

	// Invalid Hexidecimal value. 	
	else 
		printf ("***Error: Invalid Hexidecimal value. \n");
	
	return EXIT_SUCCESS;
} /* end main () */



/*===========================================================================*/
/**
 * @brief Evaluates the provided hex string for valid hexidecimal values. 
 *
 * @param hex The hexadecimal string to evaluate. 
 *
 * @return True if the string contained only valid hexidecimal values, 
 * 				 false otherwise. 
 */ 
/*===========================================================================*/
bool validate_hex (char *&hex)
{
	int index   = 0;
	
	// Skip leading 0x 
	if (hex [index] == '0' && (hex [index + 1] == 'x' || hex [index + 1] == 'X')) 
		hex += 2;		

	return  (strtok (hex, VALID_HEX) == NULL); 
} /* end valid_hex () */ 



/*===========================================================================*/
/**
 * @brief Returns the integer value of the provided hexidecimal value. This 
 *
 * Preconditions: The provided character must be a valid hexidecimal value. 
 *
 * @param c The character to evaluate. 
 * @return The integer value of the hexidecimal value. 
 */ 
/*===========================================================================*/
int hex_value (char c)
{

		int i;

		for (i = 0; VALID_HEX [i]!= '\0'; i++)
				if (toupper (c)== VALID_HEX [i])
					break;
					
		return i;	
} /* end hex_value () */


/*===========================================================================*/
/**
 * @brief 
 *
 * Preconditions: 
 *
 * @param bits The bits to perform calculations on.
 */ 
/*===========================================================================*/
void calculate (int bits)
{
	int exponent    = get_exponent (bits);	;
	int current_bit = 22;
	int base        = 2;

	printf ("%d %s %d %s", base, "^", exponent, "(1");

	// Count back from bit-22.	
	while (0) {
		
	}

	printf ("%s \n", ")");
} /* end calculate () */ 


/*===========================================================================*/
/**
 * @brief Returns the exponent of the given IEEE754 floating point bits.  
 *
 * Preconditions: The given integer contains a bit patter as that of an IEEE 
 * 							  754 (32-bit) single precision floating-point number.
 * 							  It is assumed that the value is 32-bits, and bits 23 to 30
 * 							  contain the BIASED exponent of 127.   
 *
 * @param bits The string of hex values to calculate. 
 * @return The exponent of the floating point value. 
 */ 
/*===========================================================================*/
int get_exponent (int bits)
{
	int exponent  = 0;
 	int exp_start = 23;		
	int exp_end   = 30;
	int index     = 1;
	int mask      = 1;

	while (exp_start <= exp_end) {
		exponent |=  (((bits >> exp_start++) & mask) * index);	
		index *= 2;
	}

	return (exponent - BIAS);
} /* end get_exponent () */

