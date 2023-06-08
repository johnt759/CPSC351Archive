#include<iostream>
using namespace std;
// This program demonstrates operating system commands
// via the system() function.

int main()
{
	// Let's greet the user with the instructions below.
	cout << "Be sure to follow the prompts. Press any key to begin.\n";
	system("pause");	// Wait for the user to press any key to continue.
	system("cls");

	cout << "Now demonstrating the operating system commands...\n";
	cout << "First is the clear screen. It will clear everything from the window.\n";
	system("pause");
	system("cls");	// Clear screen is useful when doing menu-driven programs.
	// Null can also refer to a pointer and a value of zero.
	cout << "Next is null, which is to check if a system processor exists.\n";
	system("pause");
	if (system(NULL))
	{
		cout << "A command processor exists in this system.\n";
	}
	else
	{
		cout << "No command processor found in this system.\n";
	}
	system("pause");
	system("cls");

	cout << "End of demonstration of system calls.\n";
	system("pause");	// This helps when the user wants to end the program.
	system("cls");
}