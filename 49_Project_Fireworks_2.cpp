/* School of Computing, FAST, Islamabad
   Data Science, Section N
   Project: Fireworks
   Shape Assigned: Serpentine
   Group Members:
   					Abdullah Khan : 20I-0894
   					Senir Kashir  : 20I-0927
   					Firza Hussain : 19I-1725
*/


#include <windows.h>
#include <iostream>
using namespace std;

void cw45(int initrow, int initcolumn, int stars, char firework[][45]);
void cw135(int initrow, int initcolumn, int stars, char firework[][45]);
void verticalstars(int initrow, int column, int stars, int spaces, char firework[][45]);
void horizontalstars(int row, int initcolumn, int stars, int spaces, char firework[][45]);

int main()
{
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\tWelcome to Serpentine Firework\n\tPress Enter key to display the firework\n\n";
	cin.ignore();
	char firework[20][45];  // array for printing the firework's upper and lower petals
	char horizontalpetal[5][45];
	int initrow, initcolumn, row, column, stars;
	
	// inputting verticle petal
	cw45(1, 24, 5, firework);
	cw135(6, 20, 5, firework);
	cw45(11, 24, 5, firework);
	cw135(16, 20, 3, firework);
	
	// inputting horizontal petal
	horizontalstars(4, 0, 3, 1, horizontalpetal);
	horizontalstars(0, 8, 3, 1, horizontalpetal);
	horizontalstars(4, 16, 3, 1, horizontalpetal);
	horizontalstars(4, 26, 3, 1, horizontalpetal);
	horizontalstars(0, 34, 3, 1, horizontalpetal);
	horizontalstars(4, 42, 3, 1, horizontalpetal);
	cw45(2, 21, 2, horizontalpetal);
	cw45(1, 6, 3, horizontalpetal);
	cw45(1, 32, 3, horizontalpetal);
	cw135(2, 23, 2, horizontalpetal);
	cw135(1, 12, 3, horizontalpetal);
	cw135(1, 38, 3, horizontalpetal);
	
	// inputting 45 degrees, 135 degrees, 225 degrees, and 315 degrees fireworks
	verticalstars(5, 7, 5, 1, firework);
	verticalstars(11, 13, 5, 1, firework);
	verticalstars(17, 19, 3, 1, firework);
	verticalstars(17, 25, 3, 1, firework);
	verticalstars(11, 31, 5, 1, firework);
	verticalstars(5, 37, 5, 1, firework);
	horizontalstars(4, 4, 3, 1, firework);
	horizontalstars(10, 8, 5, 1, firework);
	horizontalstars(16, 14, 5, 1, firework);
	horizontalstars(4, 38, 3, 1, firework);
	horizontalstars(10, 32, 5, 1, firework);
	horizontalstars(16, 26, 5, 1, firework);
	
	// setting empty spaces in the arrays as '<space>' = ' '
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 44; j++)
			if (firework[i][j] != '*')
				firework[i][j] = ' ';	
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 44; j++)
			if (horizontalpetal[i][j] != '*')
				horizontalpetal[i][j] = ' ';
	}
	
	// firework output upper part
	SetConsoleTextAttribute(colors,2);
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 44; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
	
	// firework output middle part
	SetConsoleTextAttribute(colors,4);
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 44; j++)
			cout << horizontalpetal[i][j];
			
		cout << endl;	
	}
	
	// firework output lower part
	SetConsoleTextAttribute(colors,5);
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j <= 44; j++)
			cout << firework[i][j];
			
		cout << endl;	
	}
			
	SetConsoleTextAttribute(colors,15);
	return 0;  // to hold output
}

// self-defined functions

void cw135(int initrow, int initcolumn, int stars, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + (stars - 1), j <= initcolumn + (stars - 1); i++, j++)
		firework[i][j] = '*';	
}

void cw45(int initrow, int initcolumn, int stars, char firework[][45])
{
	for (int i = initrow, j = initcolumn; i <= initrow + (stars - 1), j >= initcolumn - (stars - 1); i++, j--)
		firework[i][j] = '*';
}

void verticalstars(int initrow, int column, int stars, int spaces, char firework[][45])
{
	for (int i = initrow; i <= initrow + (stars - 1); i += spaces + 1)
		firework[i][column] = '*';
}

void horizontalstars(int row, int initcolumn, int stars, int spaces, char firework[][45])
{
	for (int j = initcolumn; j <= initcolumn + (stars - 1); j += spaces + 1)
		firework[row][j] = '*';
}
