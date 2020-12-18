/* School of Computing, FAST, Islamabad
   Data Science, Section N
   Project: Fireworks
   Shape Assigned: Serpentine
   Group Members:
   					Abdullah Khan : 20I-0894
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void extraspaces(int);
void cw45();
void cw135();
void halfcw135(int);


int main()
{	
	// straight up and straight down
	halfcw135(20);
	for (int i = 1; i <= 5; i++)
	{
		if (i % 2 == 1)
			cw45();
		else 
			cw135();	
	}
	halfcw135(23);
	
	return 0;
}

// self-defined functions

void extraspaces(int j)
{
	cout << " ";
	if (j > 1 && j < 3)
		cout << " " ;
}

void cw45()
{
	for (int i = 0; i <= 5; i++)
	{
		cout << setw(20);
		for (int j = 0; j <= 5; j++)
		{
			if(j != i)
			{
				extraspaces(j);
			}
			else
				cout << "*";	
			}	
			cout << endl;	
	}	
}

void cw135()
{
	for (int i = 0; i <= 5; i++)
	{
		cout << setw (20);
		for (int j = 5; j >= 0; j--)
		{
			if(j != i)
				extraspaces(j);
			else
				cout << "*";	
				
		}
			cout << endl;	
	}
}

void halfcw135(int width)
{
	for (int i = 3; i <= 5; i++)
	{
		cout << setw (width);
		for (int j = 5; j >= 3; j--)
		{
			if(j != i)
			{
				extraspaces(j);
			}
			else
				cout << "*";	
				
		}
			cout << endl;	
	}
}
