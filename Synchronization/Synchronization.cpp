// John Tu CPSC 351
#include<iostream>
#include<string>	// Needed to work with strings
#include<fstream>	// Needed to do file operations
#include "Windows.h"	// Needed for sleep timer
// The following 2 headers below are needed to
// handle mutex and thread operations.
#include<thread>
#include<mutex>
using namespace std;

void printFile(int num, string str[]);

// Designate this variable as the critical section in the mutex.
mutex crit;

string numArray[26] = { "1", "2", "3", "4", "5", "6", "7",
					"8", "9", "10", "11", "12", "13", "14",
					"15", "16", "17", "18", "19", "20", "21",
					"22", "23", "24", "25", "26" };
string charArray[26] = { "A", "B", "C", "D", "E", "F", "G",
					"H", "I", "J", "K", "L", "M", "N",
					"O", "P", "Q", "R", "S", "T", "U",
					"V", "W", "X", "Y", "Z" };

const int MAX_ELEMENTS = 26;
const char* fileName = "synch.txt";

int main()
{
	// Let's greet the user about how the program works.
	cout << "Greetings and welcome!\n";
	cout << "This program demonstrates synchronization of two threads.\n";
	cout << "Press any key when ready...\n";
	system("pause");

	// Declare the two threads here. After each thread execution, pause the
	// program for the user to continue on.
	thread first(printFile, 20, numArray);
	thread second(printFile, 20, charArray);
	first.join();
	second.join();

	cout << "Synchronization test complete. End of thread demonstration.\n";
	Sleep(1500);
	return 0;
}

void printFile(int num, string str[])
{
	crit.lock();

	// Make sure to create a new text file for the threads to write into.
	// Also be sure to append all data into the text file.
	ofstream threadFile;
	threadFile.open(fileName, ios::app);
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < MAX_ELEMENTS; j++)
		{
			cout << str[j] << " ";
			threadFile << str[j] << " ";
		}
		cout << "\n";
		threadFile << "\n";
	}

	threadFile.close();
	crit.unlock();
}