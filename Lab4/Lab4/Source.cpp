//-------------------------------
// Author: Tyler Patrick
// Assignment: Lab 4
// Last Date Modified: 2/7/19
//Description: Temperature Reader for Low and High Temps
//Assistance: I recieved assistance from: Ryan Bezold

#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>

using namespace std;

int main() {

	ifstream infile;
	ofstream fout;

	// Initalize Variables
	string date;
	int numreadings, min = 99, max = 0;
	if (!infile.fail())
	{
		infile.open("tempsin.txt");
	// Print Header
		fout.open("tempsout.txt");
		fout << "DATE    HIGH LOW" << endl;
		fout << " ------ ---- ---" << endl;

		while (date != "ENDOFDATA")
		{
			// Set the max and min for the loop statement
			max = 0;
			min = 99;
			// Assign First date from text document
			infile >> date;
			if (date != "ENDOFDATA")
			{
				// Collect Number of readings
				infile >> numreadings;
				// Loop until document says "END OF DATA"
				for (int i = 0; i < numreadings; i++)
				{
					// Initalize the temperature
					int temp;
					infile >> temp;
					if (temp > max)
					{
						max = temp;
					}
					if (temp < min)
					{
						// Assign new min value
						min = temp;


					}
				}
				fout << date << "  " << setw(2) << right << max << "  " << setw(2) << right << min << endl;
			}
		}

		infile.close();
	}
	
	// In case the file did not read
	else
	{
		fout << "Error opening the file" << endl;
		//finish program
		return(0);
	}
	
	


	return 0;
}
