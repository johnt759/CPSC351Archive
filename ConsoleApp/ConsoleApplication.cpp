// ConsoleApplication.cpp: Command Line Interpreter in C++
// Copyright (c) John Tu 9/13/2019
#define MAXSIZE 50
#include<iostream>
#include<string>
#include<cstring>
#include<Windows.h>
#include<vector>
#include<sstream>
using namespace std;

// Prototype functions; be sure to declare each
// one of these functions separately.
DWORD WINAPI ThreadCommand_dir(LPVOID parameter);
DWORD WINAPI ThreadCommand_help(LPVOID parameter);
DWORD WINAPI ThreadCommand_tasklist(LPVOID parameter);
DWORD WINAPI ThreadCommand_vol(LPVOID parameter);
DWORD WINAPI ThreadCommand_path(LPVOID parameter);
DWORD WINAPI ThreadCommand_notepad(LPVOID parameter);
DWORD WINAPI ThreadCommand_color(LPVOID parameter);
DWORD WINAPI ThreadCommand_echo(LPVOID parameter);
DWORD WINAPI ThreadCommand_ping(LPVOID parameter);

typedef vector<char*> VectorOfChars, *PtrVectorOfChars;

int main(int argc, char *argv[])	// Include these 2 arguments to do command line arguments.
{
	char* userInput = new char[MAXSIZE];
	char delimiters[] = " \t\r\n\f\v";
	char* token = NULL;
	DWORD threadNum;
	HANDLE ThreadHandle;
	VectorOfChars tokens;	// Needed to handle multiple inputs
	char* next_token = NULL;

	cout << "Welcome to myShell!\n";

	// Be sure to have an infinite loop so that it always repeats the
	// prompt for the user to enter a command (excluding exit and quit).
	// If user enters exit or quit, break out of the while loop.
	while (1)
	{
		cout << ">>";
		fgets(userInput, MAXSIZE, stdin);

		// Use strtok_s() to split input string by a delimiter.

		token = strtok_s(userInput, delimiters, &next_token);
		tokens.clear();	// Be sure to empty out the vector list for each new command!

		// Now store each token into a vector.
		while (token != NULL)
		{		
			tokens.push_back(token);
			token = strtok_s(NULL, delimiters, &next_token);
		}

		char* validInput = tokens[0];

		// Be sure to verify if such a inputted command exists. If not,
		// then display error message and loop back to the beginning.
		// Also, be sure to implement the threads in this code.
		if (strcmp(validInput, "dir") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_dir, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "help") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_help, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "tasklist") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_tasklist, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "vol") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_vol, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "path") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_path, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "notepad") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_notepad, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}
		
		else if (strcmp(validInput, "color") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_color, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		else if (strcmp(validInput, "echo") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_echo, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}
		
		else if (strcmp(validInput, "ping") == 0)
		{
			ThreadHandle = CreateThread(NULL, 0, ThreadCommand_ping, &tokens, 0, &threadNum);
			WaitForSingleObject(ThreadHandle, INFINITE);
		}

		// clear can also be used to tidy up the console screen.
		else if ((strcmp(validInput, "cls") == 0) || (strcmp(validInput, "clear") == 0))
		{
			system("cls");
		}

		else if ((strcmp(validInput, "exit") == 0) || (strcmp(validInput, "quit") == 0))
		{
			cout << "Ending session...\n";
			delete[] userInput;
			break;
		}

		else
		{
			cout << "No such command exists.\n";
		}
	}
}

DWORD WINAPI ThreadCommand_dir(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_help(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_tasklist(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_vol(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_path(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_notepad(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

// For the following 3 functions below, implement a for
// loop in order to concatenate each token in a vector
// into the character array. After that, perform a system
// call, even if there is only one token inputted.
DWORD WINAPI ThreadCommand_color(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);

	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_echo(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars) parameter;

	strcpy(command, (*tokens)[0]);
	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}

DWORD WINAPI ThreadCommand_ping(LPVOID parameter)
{
	char command[50];	// Needed to do strcat()

	PtrVectorOfChars tokens = (PtrVectorOfChars)parameter;

	strcpy(command, (*tokens)[0]);
	for (auto ii = 1; ii < tokens->size(); ii++)
	{
		strcat(command, " ");
		strcat(command, (*tokens)[ii]);
	}

	system(command);
	return 0;
}