/* School of Computing, FAST, Islamabad
   Data Science, Section N
   Project: Fireworks
   Shape Assigned: Serpentine
   Group Members:
   					Abdullah Khan : 20I-0894
*/


#include <iostream>
using namespace std;

void cw45(int initrow, int initcolumn, char firework[][45]);
void cw135(int initrow, int initcolumn, char firework[][45]);
void halfcw45(int initrow, int initcolumn, char firework[][45]);
void verticalstars(int initrow, int column, int stars, char firework[][45]);
void horizontalstars(int row, int initcolumn, int stars, char firework[][45]);

int main()
{	
	char firework[20][45];  // array for printing the firework
	int initrow, initcolumn, row, column, stars;
	
	// printing verticle upper petal and lower petal
	cw135(1, 24, firework);
	cw45(6, 20, firework);
	cw135(11, 24, firework);
	halfcw45(16, 20, firework);
	halfcw45(16, 20, firework);
	cw135(1, 24, firework);
	cw45(6, 20, firework);
	cw135(11, 24, firework);
	
	
	// printing 45 degrees, 135 degrees, 225 degrees, and 315 degrees fireworks
	verticalstars(5, 7, 5, firework);
	verticalstars(11, 13, 5, firework);
	verticalstars(17, 19, 3, firework);
	verticalstars(17, 25, 3, firework);
	verticalstars(11, 31, 5, firework);
	verticalstars(5, 37, 5, firework);
	horizontalstars(4, 4, 3, firework);
	horizontalstars(10, 8, 5, firework);
	horizontalstars(16, 14, 5, firework);
	horizontalstars(19, 19, 3, firework);
	horizontalstars(4, 38, 3, firework);
	horizontalstars(10, 32, 5, firework);
	horizontalstars(16, 26, 5, firework);
	horizontalstars(19, 23, 3, firework);
	
	// setting empty spaces in the array as '<space>' = ' '
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 44; j++)
			if (firework[i][j] != '*')
				firework[i][j] = ' ';
	}
	
	// firework output upper part
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 44; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
	
	// firework output lower part
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j <= 44; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
			

	return 0;  // to hold output
}

// self-defined functions

void cw45(int initrow, int initcolumn, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + 4, j <= initcolumn + 4; i++, j++)
		firework[i][j] = '*';	
}

void cw135(int initrow, int initcolumn, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + 4, j >= initcolumn - 4; i++, j--)
		firework[i][j] = '*';
}

void halfcw45(int initrow, int initcolumn, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + 2, j <= initcolumn + 2; i++, j++)
		firework[i][j] = '*';
}

void verticalstars(int initrow, int column, int stars, char firework[][45])
{
	for (int i = initrow; i <= initrow + (stars - 1); i += 2)
		firework[i][column] = '*';
}

void horizontalstars(int row, int initcolumn, int stars, char firework[][45])
{
	for (int j = initcolumn; j <= initcolumn + (stars - 1); j += 2)
		firework[row][j] = '*';
}


