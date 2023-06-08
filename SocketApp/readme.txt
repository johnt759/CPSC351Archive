The final version of this assignment is ClientSocket.cpp. The two files ClientSocket_Sender.cpp and ClientSocket_Receiver.cpp are for debugging tests only.

ClientSocket4_Sender.cpp and Sender 2.exe are sender versions of the socket application.
ClientSocket4_Receiver.cpp and Receiver 2.exe are receiver versions of the socket application.
While both .cpp files have the same code as well as the thread functions containing the
sendto() and recvfrom(), each of the files have the port numbers swapped.
(3514 for sender and 3515 for receiver in ClientSocket4_Sender.cpp; 3515 for sender and 3514 for receiver in ClientSocket4_Receiver.cpp)

In order to open it successfully, follow the procedures below:
Open ClientSocket4_Sender.cpp with Receiver 2.exe OR ClientSocket4_Receiver.cpp with Sender 2.exe
(Be sure to open the executable file first BEFORE running the source code in debug mode or it will not be able to connect successfully!)
You are free to type anything down on either window you're running.
Each time you press enter on any of the two windows, you should get the receiving message on the other window.
Press Crtl+C anytime to close the program or you can directly close the window once you're done.