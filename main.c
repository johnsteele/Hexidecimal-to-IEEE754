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
static const char VALID_HEX [] = {'0', '1', '2', '3', '4', '5', '6', '7', 
																  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
																	'a', 'b', 'c', 'd', 'e', 'f'};


/*===============================[ Prototypes ]==============================*/ 
int hex_value (char c); 
bool validate_hex (char *&hex);


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
	// Our own copy of the hex value. 
	char *tmp = argv [1];
	char *hex = (char *) malloc (sizeof (strlen (argv [1]) + 1));
	strcpy (hex, tmp);	
	char null_term = '\0';
	strcat (hex, &null_term);



	//	x |= (3 << 4);
  //	printf ("%d \n", x);	

	printf ("%s %s \n", "Before : ", hex); 
	validate_hex (hex);
	printf ("%s %s \n", "After  : ", hex);

	free (hex);
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
	char *tmp   = hex;

	// Skip leading 0x 
	if (hex [index] == '0' && (hex [index + 1] == 'x' || hex [index + 1] == 'X')) {
		tmp += 2;		
		return  (strtok (tmp, VALID_HEX) == NULL); 
	}

	// We need to append the 0x
	else{  

		// Check for valid hexidecimal values. 
		if (strtok (hex, VALID_HEX) != NULL) return false;
		
		// Append values. 
		char hex_prefix [] = "0x";
		char null_term  = '\0';

		// Extra room for hex prefix and terminating character. 		
		char *temp = (char *) malloc (sizeof (strlen (hex) + 3));

		// Append hex prefix and terminate character. 
		strcat (temp, hex_prefix);
		strcat (temp, hex);	
		strcat (temp, &null_term);

		// Swap them out. 
		free (hex);
		hex = temp;
		temp = NULL;
	}

	return true;
} /* end valid_hex () */ 


/*===========================================================================*/
/**
 * @brief Returns the integer value of the provided hexidecimal value. This 
 * @brief Method turned out not to be needed. 
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

	for (i = 0; VALID_HEX [i] != '\0'; i++) 
		if (toupper (c) == VALID_HEX [i]) break;

	return i;	
} /* end hex_value () */

