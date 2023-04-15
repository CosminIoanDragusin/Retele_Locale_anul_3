
#include <winsock2.h>
#include <stdio.h>
#include <string.h>

namespace Lab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	WSADATA            wsaData;
	SOCKET             ListeningSocket;
	SOCKET             NewConnection;
	SOCKADDR_IN        ServerAddr;
	int                Port = 8001;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox;
	protected: 
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Button^  btnExit;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox
			// 
			this->richTextBox->BackColor = System::Drawing::Color::MintCream;
			this->richTextBox->Location = System::Drawing::Point(39, 20);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->Size = System::Drawing::Size(585, 156);
			this->richTextBox->TabIndex = 0;
			this->richTextBox->Text = L"";
			this->richTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox_TextChanged);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(39, 196);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(130, 41);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Start Server";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(494, 196);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(130, 41);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(652, 261);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->richTextBox);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
      
		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
	private: System::Void richTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

				// Initialize Winsock version 2.2
			 if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
			 {
				  // MSDN: An application can call the WSAGetLastError() function to determine the
				  // extended error code for other Windows sockets functions as is normally
				  // done in Windows Sockets even if the WSAStartup function fails or the WSAStartup
				  // function was not called to properly initialize Windows Sockets before calling a
				  // Windows Sockets function. The WSAGetLastError() function is one of the only functions
				  // in the Winsock 2.2 DLL that can be called in the case of a WSAStartup failure
				  richTextBox->AppendText("Server: WSAStartup failed with error " + Convert::ToString(WSAGetLastError()) + "\n");			
			 }
			 else
			 {
				  richTextBox->AppendText("Server: The Winsock dll found!\n");
				  richTextBox->AppendText("Server: The current status is " + gcnew String(wsaData.szSystemStatus) + ".\n");
			 }
		     
			 if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
			 {
				  //Tell the user that we could not find a usable WinSock DLL
				  richTextBox->AppendText("Server: The dll do not support the Winsock version " + LOBYTE(wsaData.wVersion)+"."+HIBYTE(wsaData.wVersion) + "!\n");
				  // Do the clean up
				  WSACleanup();
				  // and exit with error
			 }
			 else
			 {
				  richTextBox->AppendText("Server: The dll supports the Winsock version " + LOBYTE(wsaData.wVersion)+"."+HIBYTE(wsaData.wVersion)+ "!\n");
				  richTextBox->AppendText("Server: The highest version this dll can support is " + LOBYTE(wsaData.wHighVersion)+"."+HIBYTE(wsaData.wHighVersion) + ".\n");
			 }
			 // Create a new socket to listen for client connections.
			 ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		     
			 // Check for errors to ensure that the socket is a valid socket.
			 if (ListeningSocket == INVALID_SOCKET)
			 {
				 richTextBox->AppendText("Server: Error at socket(), error code: " + Convert::ToString(WSAGetLastError()) + "\n");
				  // Clean up
				  WSACleanup();
				  // and exit with error
			 }
			 else
				  richTextBox->AppendText("Server: socket() is OK!\n");
		 
			 // Set up a SOCKADDR_IN structure that will tell bind that we
			 // want to listen for connections on all interfaces using port 5150.
		 
			 // The IPv4 family
			 ServerAddr.sin_family = AF_INET;
			 // host-to-network byte order
			 ServerAddr.sin_port = htons(Port);
			 // Listen on all interface, host-to-network byte order
			 ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

			 // Associate the address information with the socket using bind.
			 // Call the bind function, passing the created socket and the sockaddr_in
			 // structure as parameters. Check for general errors.
			 if (bind(ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
			 {
				  richTextBox->AppendText("Server: bind() failed! Error code: " + Convert::ToString(WSAGetLastError()) +".\n");
				  // Close the socket
				  closesocket(ListeningSocket);
				  // Do the clean up
				  WSACleanup();
			 }
			 else
				  richTextBox->AppendText("Server: bind() is OK!\n");
			 // Listen for client connections. We used a backlog of 5, which
			 // is normal for many applications.
			 if (listen(ListeningSocket, 5) == SOCKET_ERROR)
			 {
				 richTextBox->AppendText("Server: listen(): Error listening on socket "+ Convert::ToString(WSAGetLastError()) +".\n");
				  // Close the socket
				  closesocket(ListeningSocket);
				  // Do the clean up
				  WSACleanup();
			 }
			 else
				  richTextBox->AppendText("Server: listen() is OK, I'm waiting for connections...\n");
			 richTextBox->AppendText("Server: accept() is ready...\n");
			this->btnStart->Text = L"Port 8001";
			NewConnection = SOCKET_ERROR;
			while (NewConnection == SOCKET_ERROR)
			{
				NewConnection = accept(ListeningSocket, NULL, NULL);
			}

			richTextBox->AppendText("Server: accept() is OK...\n");
			richTextBox->AppendText("Server: Client connected, ready for receiving and sending data...\n");
			// Transfer the connected socket to the listening socket
			ListeningSocket = NewConnection;
			//break;
		 }

	};
}

