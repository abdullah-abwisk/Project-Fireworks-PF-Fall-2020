/* School of Computing, FAST, Islamabad
   Data Science, Section N
   Project: Fireworks
   Shape Assigned: Serpentine
   Written by:
   					Abdullah Khan : 20I-0894
   					
   Date:  14th December 2020
   Deadline:  17th December 2020				
*/


#include <iostream>
using namespace std;





// setting constant number of columns and rows for main array
const int rowstotal = 20;
const int colstotal = 45;
const int rowstotalhorizontal = 5;

// funtion prototypes
void cw45(int initrow, int initcolumn, int stars, char firework[][colstotal]);
void cw135(int initrow, int initcolumn, int stars, char firework[][colstotal]);
void verticalstars(int initrow, int column, int stars, int spaces, char firework[][colstotal]);
void horizontalstars(int row, int initcolumn, int stars, int spaces, char firework[][colstotal]);





int main()
{
	char firework[rowstotal][colstotal];  // array for printing the firework's upper and lower petals
	char horizontalpetal[rowstotalhorizontal][colstotal]; // array for printing the firework's middle horizontal petals
	int initrow, initcolumn, row, column, stars;
	
	
	
	
	
	// inputting verticle petal
	cw45(1, 24, 5, firework);
	cw135(6, 20, 5, firework);
	cw45(11, 24, 5, firework);
	cw135(16, 20, 3, firework);
	
	
	
	
	
	// inputting horizontal petal 'horizontal part'
	
	//	horizontalstars(4, 0, 3, 1, horizontalpetal);
	//	horizontalstars(0, 8, 3, 1, horizontalpetal);
	//	horizontalstars(4, 16, 3, 1, horizontalpetal);
	//	horizontalstars(4, 26, 3, 1, horizontalpetal);
	//	horizontalstars(0, 34, 3, 1, horizontalpetal);
	//	horizontalstars(4, 42, 3, 1, horizontalpetal);
	
	// calling above functions using loop
	for (int initcolumn = 0, count = 1, stars = 3, spaces = 1, difference = 8; initcolumn <= 42; initcolumn += difference, count++)
	{
		// setting row value to 4 each time
		row = 4;
		
		// changing row to 0 for column 8 and 34
		if (count == 2 || count == 5)
			row = 0;	
		
		// changing difference from column 16 to 26
		if (count == 4)
			difference = 10;
		else
			difference = 8;
		
		// printing using values in current loop
		horizontalstars(row, initcolumn, stars, spaces, horizontalpetal);		
	}
	
	
	// inputting horizontal petal 'angles part'
	cw45(2, 21, 2, horizontalpetal);
	cw45(1, 6, 3, horizontalpetal);
	cw45(1, 32, 3, horizontalpetal);
	cw135(2, 23, 2, horizontalpetal);
	cw135(1, 12, 3, horizontalpetal);
	cw135(1, 38, 3, horizontalpetal);
	
	
	
	
	
	// inputting 45 degrees, 135 degrees, 225 degrees, and 315 degrees firework petals 'verticle parts'
	
	//	verticalstars(5, 7, 5, 1, firework);
	//	verticalstars(11, 13, 5, 1, firework);
	//	verticalstars(17, 19, 3, 1, firework);
	//	verticalstars(17, 25, 3, 1, firework);
	//	verticalstars(11, 31, 5, 1, firework);
	//	verticalstars(5, 37, 5, 1, firework);
	
	// calling above functions using loop
	for (int initrow = 5, column = 7, stars = 5, difference = 30, spaces = 1; initrow <= 17; initrow += 6, column += 6, difference -= 12)
	{
		// changing the number of stars for the verticle lines close to the pivot
		if (initrow == 17)
			stars = 3;
			
		verticalstars(initrow, column, stars, spaces, firework);
			
		// adding difference to column	
		column += difference;
			
		verticalstars(initrow, column, stars, spaces, firework);
			
		// storing initial number of stars back into the variable
		if (initrow == 17)
			stars = 5;
			
		// reinitializing column	
		column -= difference;		
	}
	
	
	// inputting 45 degrees, 135 degrees, 225 degrees, and 315 degrees firework petals 'horizontal parts'
	
	//	horizontalstars(4, 4, 3, 1, firework);
	//	horizontalstars(10, 8, 5, 1, firework);
	//	horizontalstars(16, 14, 5, 1, firework);
	//	horizontalstars(4, 38, 3, 1, firework);
	//	horizontalstars(10, 32, 5, 1, firework);
	//	horizontalstars(16, 26, 5, 1, firework);

	// calling above functions using loop
	for (int row = 4, initcolumn = 4, difference = 34, stars = 5, spaces = 1; row <= 16; row += 6, initcolumn += 4, difference -= 10)
	{
		// changing number of stars for first row
		if (row == 4)
			stars = 3;
			
		// adding two additional values to column and reducing difference by two for row 16	
		if (row == 16)
		{
			initcolumn += 2;
			difference -= 2;
		}
		
		// inputting first half
		horizontalstars(row, initcolumn, stars, spaces, firework);
		
		// adding difference to column
		initcolumn += difference;
		
		// inputting second half
		horizontalstars(row, initcolumn, stars, spaces, firework);
		
		// setting number of stars to default value
		if (row == 4)
		{
			stars = 5;	
		}
		
		// reinitializing column
		initcolumn -= difference;
	}
	
	
	
	
	
	/* Now we will display all 
	   different parts of the 
	   firework one by one. */
	
	
	// displaying message for user
	cout << "|*\tProject Programming Fundamentals\t*|\n\n\t|* Serpentine Firework *|\n\tBy:\n\t\t Abdullah Khan\n\t\t\n\n\t|* Dated: 14th December 2020 *|\n\n\n\tWelcome to Serpentine Firework\n\tPress Enter key to display the firework\n\n";
	cin.ignore();
	
	
	// setting empty spaces in the arrays as '<space>' = ' ' in main array
	for (int i = 0; i <= rowstotal - 1; i++)
	{
		for (int j = 0; j <= colstotal - 1; j++)
			if (firework[i][j] != '*')
				firework[i][j] = ' ';	
	}
	
	
	// setting empty spaces in the arrays as '<space>' = ' ' in second array
	for (int i = 0; i <= rowstotalhorizontal - 1; i++)
	{
		for (int j = 0; j <= colstotal - 1; j++)
			if (horizontalpetal[i][j] != '*')
				horizontalpetal[i][j] = ' ';
	}
	
	
	// firework output upper part
	for (int i = 0; i <= rowstotal - 1; i++)
	{
		cout << "\t\t";
		
		for (int j = 0; j <= colstotal - 1; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
	
	
	// firework output middle part
	for (int i = 0; i <= rowstotalhorizontal - 1; i++)
	{
		cout << "\t\t";
		
		for (int j = 0; j <= colstotal - 1; j++)
			cout << horizontalpetal[i][j];
			
		cout << endl;	
	}
	
	
	// firework output lower part
	for (int i = rowstotal - 1; i >= 0; i--)
	{
		cout << "\t\t";
		
		for (int j = 0; j <= colstotal - 1; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
		
			
	return 0;  // to hold output
}

/* self-defined functions */


// for printing stars at an angle of 135 degrees clockwise
void cw135(int initrow, int initcolumn, int stars, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + (stars - 1), j <= initcolumn + (stars - 1); i++, j++)
		firework[i][j] = '*';	
}


// for printing stars at an angle of 135 degrees clockwise
void cw45(int initrow, int initcolumn, int stars, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + (stars - 1), j >= initcolumn - (stars - 1); i++, j--)
		firework[i][j] = '*';
}


// for printing stars vertically up and down
void verticalstars(int initrow, int column, int stars, int spaces, char firework[][45])
{
	for (int i = initrow; i <= initrow + (stars - 1); i += spaces + 1)
		firework[i][column] = '*';
}


// for printing stars horizontally left and right
void horizontalstars(int row, int initcolumn, int stars, int spaces, char firework[][45])
{
	for (int j = initcolumn; j <= initcolumn + (stars - 1); j += spaces + 1)
		firework[row][j] = '*';
}


/* Thank You for looking at my program */
