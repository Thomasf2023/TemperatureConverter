#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>


using namespace std;

/* This program will take tempatures in Fahrenheit from one file and convert them to Celcius and then write those values 
in another file.

Author: Thomas Fiske
Date: 1/29/2022
*/

double celciusConvert(int fDegrees) { //Function that takes degrees in F and converts them to C
	double cDegrees;

	cDegrees = (fDegrees - 32) * 5 / 9.0;

	return cDegrees;
}
int main() {
    
	//Variables One for each name in the file, each tempature in F and each tempature in C
    string fileName1;
	int fileInt1;
	string fileName2;
	int fileInt2;
	string fileName3;
	int fileInt3;
	string fileName4;
	int fileInt4;
	string fileName5;
	int fileInt5;
	string fileName6;
	int fileInt6;
	double cTemp1;
	double cTemp2;
	double cTemp3;
	double cTemp4;
	double cTemp5;
	double cTemp6;


	fstream MyFile;

	cout << "Opening file FahrenheitTemperature.txt." << endl; // Statement to show user file is being open

	MyFile.open("FahrenheitTemperature.txt");


	if (!MyFile.is_open()) { //Error catcher that will print if file does not open
		cout << "Could not open file FahrenheitTemperature.txt." << endl;
		return 1;
	} 

	//Test prints are commented out but were used to make sure inputs from file were correct.
	//cout << "Temperatures in Fahrenheit:" << endl;
	cout << "Reading File" << endl;
	MyFile >> fileName1;
	//cout << fileName1 << " ";
	MyFile >> fileInt1;
	//cout << fileInt1 << endl;

	MyFile >> fileName2;
	//cout << fileName2 << " ";
	MyFile >> fileInt2;
	//cout << fileInt2 << endl;

	MyFile >> fileName3;
	//cout << fileName3 << " ";
	MyFile >> fileInt3;
	//cout << fileInt3 << endl;

	MyFile >> fileName4;
	//cout << fileName4 << " ";
	MyFile >> fileInt4;
	//cout << fileInt4 << endl;

	MyFile >> fileName5;
	//cout << fileName5 << " ";
	MyFile >> fileInt5;
	//cout << fileInt5 << endl;

	MyFile >> fileName6;
	//cout << fileName6 << " ";
	MyFile >> fileInt6;
	//cout << fileInt6 << endl;

	

	cTemp1 = celciusConvert(fileInt1);
	cTemp2 = celciusConvert(fileInt2);
	cTemp3 = celciusConvert(fileInt3);
	cTemp4 = celciusConvert(fileInt4);
	cTemp5 = celciusConvert(fileInt5);
	cTemp6 = celciusConvert(fileInt6);

	//Test prints are commented out but were used to make sure temperature conversions were correct.
	/*cout << cTemp1 << endl;
	cout << cTemp2 << endl;
	cout << cTemp3 << endl;
	cout << cTemp4 << endl;
	cout << cTemp5 << endl;
	cout << cTemp6 << endl; */


    cout << "Closing file FahrenheitTemperature.txt." << endl; // Statement to show user file is being closed
	MyFile.close();

	cout << endl;

	cout << "Opening file CelsiusTemperature.txt." << endl; //Statement to show user file is being opened
	MyFile.open("CelsiusTemperature.txt.");

	if (!MyFile.is_open()) { // Error catcher that will open if file does not open
		cout << "Could not open file CelsiusTemperature.txt" << endl;
		return 1;
	}
	cout << "Writing File" << endl;

	//Writing Celsius temperatures to the new file with a percision of 2 decimals
	MyFile << fixed << setprecision(2) << fileName1 << " " << cTemp1 << endl;
	MyFile << fixed << setprecision(2) << fileName2 << " " << cTemp2 << endl;
	MyFile << fixed << setprecision(2) << fileName3 << " " << cTemp3 << endl;
	MyFile << fixed << setprecision(2) << fileName4 << " " << cTemp4 << endl;
	MyFile << fixed << setprecision(2) << fileName5 << " " << cTemp5 << endl;
	MyFile << fixed << setprecision(2) << fileName6 << " " << cTemp6 << endl;

	cout << "Closing file CelsiusTemperature.txt." << endl; //Statement to show user file is being closed
	MyFile.close();
	return 0;
}
