// vis_server.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
//#include <cvirte.h>
//#include <userint.h>
//#include "server_socket.h"
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
using namespace vis_server;

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"








int main(array<System::String ^> ^args)
{


	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
