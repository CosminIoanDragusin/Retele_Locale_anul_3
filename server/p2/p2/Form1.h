#pragma once
#include <winsock2.h>
using namespace System::Threading;
using namespace System::Runtime::InteropServices;

namespace p2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 





	private:

		 SOCKET             ListeningSocket;
		 SOCKET             NewConnection;
		 static const int                Port = 8001;
	private: System::Windows::Forms::Button^  button5;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  sendText;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;





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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->sendText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(316, 116);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(253, 274);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Send";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(12, 274);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 67);
			this->button1->TabIndex = 1;
			this->button1->Text = L"StartListening";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// sendText
			// 
			this->sendText->Location = System::Drawing::Point(12, 178);
			this->sendText->Multiline = true;
			this->sendText->Name = L"sendText";
			this->sendText->Size = System::Drawing::Size(316, 72);
			this->sendText->TabIndex = 0;
			this->sendText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"ReceiveData";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"SendData";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(255, 317);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 353);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->sendText);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		delegate System::Void PrintStringDel(String^ str);

		void PrintString(String^ str) {
			textBox1->Text += str;
			textBox1->SelectionStart = textBox1->Text->Length;
			textBox1->ScrollToCaret();
		}

	void ReceiveThread() {
		 int ByteReceived;
		char buff[1024];

		while(1) {
			  NewConnection = SOCKET_ERROR; 
			  while(NewConnection == SOCKET_ERROR)
			  {
				  NewConnection = accept(ListeningSocket, NULL, NULL);
                  button1->BackColor = System::Drawing::Color::Green;
			  }
	
			  break;
		 }

		while(true) {
		   ByteReceived = recv(NewConnection, buff, sizeof(buff), 0);

		   if(ByteReceived > 0) {
				PrintStringDel^ print = gcnew PrintStringDel(this, &Form1::PrintString);
				String^ text = gcnew String(buff);
				textBox1->BeginInvoke(print, text);
		   }
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		WSADATA            wsaData;
        button1->Text = L"Port8001";
		if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		 {
			  // MSDN: An application can call the WSAGetLastError() function to determine the
			  // extended error code for other Windows sockets functions as is normally
			  // done in Windows Sockets even if the WSAStartup function fails or the WSAStartup
			  // function was not called to properly initialize Windows Sockets before calling a
			  // Windows Sockets function. The WSAGetLastError() function is one of the only functions
			  // in the Winsock 2.2 DLL that can be called in the case of a WSAStartup failure
			 textBox1->Text = "Server: WSAStartup failed with error";
			  // Exit with error
			 
		 }
		 else
		 {
			 textBox1->Text += "Server: The Winsock dll found!" + Environment::NewLine;
			  textBox1->Text += "Server: The current status is" + Environment::NewLine;
			  textBox1->Text += gcnew String(wsaData.szSystemStatus);
		 }
	     
		 if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
		 {
			  //Tell the user that we could not find a usable WinSock DLL
			  textBox1->Text += "Server: The dll do not support the Winsock version" + Environment::NewLine;
			  WSACleanup();
		 }
		 else
		 {
			 textBox1->Text += "Server: The dll supports the Winsock version" + Environment::NewLine;
		 }
	     
		 // Create a new socket to listen for client connections.
		 ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	     
		 // Check for errors to ensure that the socket is a valid socket.
		 if (ListeningSocket == INVALID_SOCKET)
		 {
			 textBox1->Text += String::Format("Server: Error at socket(), error code: {0}", WSAGetLastError());
			  WSACleanup();
		 }
		 else {
			  textBox1->Text += "Server: socket() is OK!" + Environment::NewLine;
			 }

		 	 SOCKADDR_IN        ServerAddr;
			 ServerAddr.sin_family = AF_INET;
		 // host-to-network byte order
		 ServerAddr.sin_port = htons(Port);
		 // Listen on all interface, host-to-network byte order
		 ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	 
		 // Associate the address information with the socket using bind.
		 // Call the bind function, passing the created socket and the sockaddr_in
		 // structure as parameters. Check for general errors.
		 if (bind(ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
		 {
			 textBox1->Text += String::Format("Server: bind() failed! Error code: {0}", WSAGetLastError());
			  // Close the socket
			  closesocket(ListeningSocket);
			  // Do the clean up
			  WSACleanup();
			  // and exit with error
		 }
		 else
			  textBox1->Text += "Server: bind() is OK!"  + Environment::NewLine;
		 
	 // Listen for client connections. We used a backlog of 5, which
     // is normal for many applications.
     if (listen(ListeningSocket, 5) == SOCKET_ERROR)
     {
		 textBox1->Text += String::Format("Server: listen(): Error listening on socket  {0}", WSAGetLastError());
          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
     }
     else
          textBox1->Text += "Server: listen() is OK, I'm waiting for connections..."  + Environment::NewLine;

		Threading::ThreadStart^ ts = gcnew Threading::ThreadStart(this,
										   &Form1::ReceiveThread);

		Threading::Thread^ t = gcnew Threading::Thread(ts);
		t->Start();
	}

	void SendText(String^ str) {
		char buff[1024];
		strcpy(buff, (char*)(void*)Marshal::StringToHGlobalAnsi(str));
		int BytesSent = send(NewConnection, buff, strlen(buff) + 1, 0);
	}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 SendText(sendText->Text);
		 }


private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 closesocket(NewConnection);
			 WSACleanup();
		 }
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == System::Windows::Forms::Keys::Enter) {
				SendText(sendText->Text);
				sendText->Text = "";
				e->Handled = true;
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

