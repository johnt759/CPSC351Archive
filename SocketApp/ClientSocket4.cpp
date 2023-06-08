// John Tu CPSC 351
// This source code demonstrates the use of sockets
// in a simple chat messanger application.
// This program will implement UDP (connectionless sockets)
// along with sendto() and recvfrom() functions.

// The macro below suppresses WinSock.h from being included by Windows.h
// in order to prevent declaration conflicts with WinSock2.h.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define _WINSOCK_DEPRECATED_NO_WARNINGS	// Needed to ignore warnings about outdated Winsock functions

#include<iostream>
#include<string>
#include<stdio.h>
#include<Windows.h>
#pragma comment(lib, "Ws2_32.lib")	// Needed to link build environment to Winsock Library
// The following two header files are required in order
// to work with Winsock functions and definitions.
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iphlpapi.h>	// Needed to use IP helper APIs
#include<thread>
#include<mutex>

#define MAXLINE 128
#define PORT_SENDER 3514
#define PORT_RECEIVER 3515
using namespace std;

// Be sure to have strlen for sendto() since we don't know how much bytes the sender will send to receiver.
void sendFunc(int newClient, struct sockaddr_in* sendAddr)
{
	char inputBuffer[MAXLINE];
	int bytesSent = 0;

	do {
		fgets(inputBuffer, MAXLINE, stdin);	// Let the user enter any message.
		bytesSent = sendto(newClient, inputBuffer, strlen(inputBuffer) + 1, 0, (struct sockaddr*) sendAddr, sizeof(*sendAddr));
		printf("Byte sent: %d\n", bytesSent);
	} while (1);
}

void recvFunc(int newClient, struct sockaddr_in* recvAddr, socklen_t* recvAddrLen)
{
	char resultBuffer[MAXLINE];
	int bytesReceived = 0;

	// Display message only if the number of bytes received is greater than 0.
	do {
		bytesReceived = recvfrom(newClient, resultBuffer, sizeof(resultBuffer), 0, (struct sockaddr*) recvAddr, recvAddrLen);
		if (bytesReceived > 0)
		{
			printf("Message from sender: %s\n", resultBuffer);
		}
		Sleep(100);
	} while (1);
}

// Both the sender and receiver will use IP address 127.0.0.1.
// Port number for sender is 3514 and receiver is 3515.

int main()
{
	WSADATA wsaData;
	struct sockaddr_in sendAddr, recvAddr;
	// This integer variable returns a 0 if success
	// and other numbers as all failure cases.
	int newClient;

	// Initialize the Winsock API first.
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cerr << "WSAStartup has failed.\n";
		Sleep(1000);
		return 1;
	}

	// Create a socket connection the first time if able.
	newClient = socket(AF_INET, SOCK_DGRAM, 0);
	if (newClient < 0)
	{
		cerr << "Unable to create a UDP socket.\n";
		WSACleanup();
		Sleep(1000);
		return 1;
	}

	// Now configure the send and receive parts of the client.
	sendAddr.sin_family = AF_INET;
	sendAddr.sin_addr.s_addr = INADDR_ANY;
	sendAddr.sin_port = htons(PORT_SENDER);
	sendAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	recvAddr.sin_family = AF_INET;
	recvAddr.sin_addr.s_addr = INADDR_ANY;
	recvAddr.sin_port = htons(PORT_RECEIVER);
	socklen_t recvAddrLen = sizeof(recvAddr);
	recvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Try to bind the receiving address if possible.
	if (::bind(newClient, (struct sockaddr*) & recvAddr, sizeof(recvAddr)) < 0)
	{
		cerr << "Unable to bind receiving address.\n";
		WSACleanup();
		Sleep(1000);
		return 1;
	}

	thread sendThread(sendFunc, newClient, &sendAddr);
	thread recvThread(recvFunc, newClient, &recvAddr, &recvAddrLen);

	// In this loop create new socket for each iteration of user input
	// and then after that, close and recreate a new one until the user
	// decides to press Crtl-C to break out of the while(1) loop.
	do {

	} while (1);

	// Now close the current socket connection.
	closesocket(newClient);
	WSACleanup();
	Sleep(2000);
	return 0;
}