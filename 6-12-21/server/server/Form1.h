
#include <winsock2.h>
#include <stdio.h>
#include <string.h> 


#pragma once
    WSADATA           wsaData;
    SOCKET             ListeningSocket;
    SOCKET             NewConnection;
    int                Port = 5150;
    char sendbuf[100] = "This is a test string from sender";
    char          recvbuff[100];
    SOCKADDR_IN        ServerAddr, SenderInfo;
    SOCKADDR_IN        ThisSenderInfo;
    int BytesSent,ByteReceived, i, nlen, SelectTiming;
   


namespace  server{

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
	private: System::Windows::Forms::TextBox^  rtb;
	protected: 
      private: System::Windows::Forms::Button^  button5;
      private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  rtbSent;
	private: System::Windows::Forms::TextBox^  rtbRecv;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;



	protected: 

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
			this->rtb = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->rtbSent = (gcnew System::Windows::Forms::TextBox());
			this->rtbRecv = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(55, 15);
			this->rtb->Margin = System::Windows::Forms::Padding(4);
			this->rtb->Multiline = true;
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(320, 143);
			this->rtb->TabIndex = 1;
			this->rtb->TextChanged += gcnew System::EventHandler(this, &Form1::rtb_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(410, 434);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 38);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Exit";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Red;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(410, 15);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 73);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Start Server";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// rtbSent
			// 
			this->rtbSent->Location = System::Drawing::Point(55, 181);
			this->rtbSent->Margin = System::Windows::Forms::Padding(4);
			this->rtbSent->Multiline = true;
			this->rtbSent->Name = L"rtbSent";
			this->rtbSent->Size = System::Drawing::Size(320, 132);
			this->rtbSent->TabIndex = 9;
			// 
			// rtbRecv
			// 
			this->rtbRecv->Location = System::Drawing::Point(55, 340);
			this->rtbRecv->Margin = System::Windows::Forms::Padding(4);
			this->rtbRecv->Multiline = true;
			this->rtbRecv->Name = L"rtbRecv";
			this->rtbRecv->Size = System::Drawing::Size(320, 132);
			this->rtbRecv->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(410, 340);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 38);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Receive";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(410, 181);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 41);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Send";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 537);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->rtbRecv);
			this->Controls->Add(this->rtbSent);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->rtb);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rtb_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
      // Initialize Winsock version 2.2
     if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
     {
          // MSDN: An application can call the WSAGetLastError() function to determine the
          // extended error code for other Windows sockets functions as is normally
          // done in Windows Sockets even if the WSAStartup function fails or the WSAStartup
          // function was not called to properly initialize Windows Sockets before calling a
          // Windows Sockets function. The WSAGetLastError() function is one of the only functions
          // in the Winsock 2.2 DLL that can be called in the case of a WSAStartup failure
          this->rtb->Text="Server: WSAStartup failed with error";
			  this->rtb->Text+=Convert::ToString(WSAGetLastError());
          // Exit with error
          this->rtb->Text="Error 1";
     }
     else
     {
          this->rtb->Text="Server: The Winsock dll found!";
          this->rtb->Text="Server: The current status is ";
		  
     }
     
     if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
     {
          //Tell the user that we could not find a usable WinSock DLL
          this->rtb->Text="Server: The dll do not support the Winsock version";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wVersion));
          // Do the clean up
          WSACleanup();
          // and exit with error
		  this->rtb->Text="Error 1";
     }
     else
     {
          this->rtb->Text="Server: The dll supports the Winsock version";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wVersion));

		  this->rtb->Text="Server: The highest version this dll can support is";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wHighVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wHighVersion));
     }
     
     // Create a new socket to listen for client connections.
     ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     
     // Check for errors to ensure that the socket is a valid socket.
     if (ListeningSocket == INVALID_SOCKET)
     {
          this->rtb->Text="Server: Error at socket(), error code:";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());

          // Clean up
          WSACleanup();
          // and exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: socket() is OK!";
 } 
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

   // Set up a SOCKADDR_IN structure that will tell bind that we
     // want to listen for connections on all interfaces using port 5150.
 
     // The IPv4 family
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
          this->rtb->Text="Server: bind() failed! Error code: ";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());

          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // and exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: bind() is OK!";
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
     // Listen for client connections. We used a backlog of 5, which
     // is normal for many applications.
     if (listen(ListeningSocket, 5) == SOCKET_ERROR)
     {
          this->rtb->Text="Server: listen(): Error listening on socket";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());
          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // Exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: listen() is OK, I'm waiting for connections...";
 
          //this->rtb->Text="Server: accept() is ready...\n";
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

			     // Accept a new connection when one arrives.
     while(1)
     {
          NewConnection = SOCKET_ERROR;
          while(NewConnection == SOCKET_ERROR)
          {
              NewConnection = accept(ListeningSocket, NULL, NULL);
          }
			
          this->rtb->Text="Server: accept() is OK...";
          this->rtb->Text="Server: Client connected, ready for receiving and sending data...";
		  //this->label1-> BackColor=System::Drawing::Color::Lime;
		  // Transfer the connected socket to the listening socket
          ListeningSocket = NewConnection;
          break;
     }
 
     // At this point you can do two things with these sockets. Wait
     // for more connections by calling accept again on ListeningSocket
     // and start sending or receiving data on NewConnection (need a loop). We will
     // describe how to send and receive data later in the chapter.
 
     // When you are finished sending and receiving data on the
     // NewConnection socket and are finished accepting new connections
     // on ListeningSocket, you should close the sockets using the closesocket API.
	 if(closesocket(NewConnection) != 0) {
          this->rtb->Text="Server: Cannot close \"NewConnection\" socket. Error code: ";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());
	 }
     else
          this->rtb->Text="Server: Closing \"NewConnection\" socket...";
 
     // When your application is finished handling the connections, 
     // call WSACleanup.
	 if(WSACleanup() != 0) {
          this->rtb->Text="Server: WSACleanup() failed! Error code: ";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());
	 }
	
	 else {
          this->rtb->Text="Server: WSACleanup() is OK...";
		  this->rtb->Text="New client connected. Socket is ready for sending and receiving data"; 
			}
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
          
           if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
     {
          // MSDN: An application can call the WSAGetLastError() function to determine the
          // extended error code for other Windows sockets functions as is normally
          // done in Windows Sockets even if the WSAStartup function fails or the WSAStartup
          // function was not called to properly initialize Windows Sockets before calling a
          // Windows Sockets function. The WSAGetLastError() function is one of the only functions
          // in the Winsock 2.2 DLL that can be called in the case of a WSAStartup failure
          this->rtb->Text="Server: WSAStartup failed with error";
			  this->rtb->Text+=Convert::ToString(WSAGetLastError());
          // Exit with error
          this->rtb->Text="Error 1";
     }
     else
     {
       this->rtb->Text="Server: The Winsock dll found!";
       this->rtb->Text="Server: The current status is ";
     }
     
     if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
     {
          //Tell the user that we could not find a usable WinSock DLL
          this->rtb->Text="Server: The dll do not support the Winsock version";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wVersion));
          // Do the clean up
          WSACleanup();
          // and exit with error
		  this->rtb->Text="Error 1";
     }
     else
     {
          this->rtb->Text="Server: The dll supports the Winsock version";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wVersion));

		  this->rtb->Text="Server: The highest version this dll can support is";
		  this->rtb->Text+=Convert::ToString(LOBYTE(wsaData.wHighVersion));
		  this->rtb->Text+=Convert::ToString(HIBYTE(wsaData.wHighVersion));
     }
     
     // Create a new socket to listen for client connections.
     ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     
     // Check for errors to ensure that the socket is a valid socket.
     if (ListeningSocket == INVALID_SOCKET)
     {
          this->rtb->Text="Server: Error at socket(), error code:";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());

          // Clean up
          WSACleanup();
          // and exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: socket() is OK!";

      
     // The IPv4 family
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
          this->rtb->Text="Server: bind() failed! Error code: ";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());

          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // and exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: bind() is OK!";

       
if (listen(ListeningSocket, 5) == SOCKET_ERROR)
     {
          this->rtb->Text="Server: listen(): Error listening on socket";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());
          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // Exit with error
          this->rtb->Text="Error 1";
     }
     else
          this->rtb->Text="Server: listen() is OK, I'm waiting for connections...";

           while(1)
     {
          NewConnection = SOCKET_ERROR;
          while(NewConnection == SOCKET_ERROR)
          {
              NewConnection = accept(ListeningSocket, NULL, NULL);
          }
			this->button6->BackColor = System::Drawing::Color::Green;
          this->rtb->Text="Server: accept() is OK...";
          this->rtb->Text="Server: Client connected, ready for receiving and sending data...";
		  //this->label1-> BackColor=System::Drawing::Color::Lime;
		  // Transfer the connected socket to the listening socket
          ListeningSocket = NewConnection;
          break;
     }
 
     // At this point you can do two things with these sockets. Wait
     // for more connections by calling accept again on ListeningSocket
     // and start sending or receiving data on NewConnection (need a loop). We will
     // describe how to send and receive data later in the chapter.
 
     // When you are finished sending and receiving data on the
     // NewConnection socket and are finished accepting new connections
     // on ListeningSocket, you should close the sockets using the closesocket API.
	 //if(closesocket(NewConnection) != 0) {
  //        this->rtb->Text="Server: Cannot close \"NewConnection\" socket. Error code: ";
		//  this->rtb->Text+=Convert::ToString(WSAGetLastError());
	 //}
  //   else
  //        this->rtb->Text="Server: Closing \"NewConnection\" socket...";
 
  //   // When your application is finished handling the connections, 
  //   // call WSACleanup.
	 /*if(WSACleanup() != 0) {
          this->rtb->Text="Server: WSACleanup() failed! Error code: ";
		  this->rtb->Text+=Convert::ToString(WSAGetLastError());
	 }
	
	 else {
          this->rtb->Text="Server: WSACleanup() is OK...";
		  this->rtb->Text="New client connected. Socket is ready for sending and receiving data";
		  this->button6->BackColor = System::Drawing::Color::Green;
			}*/

		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
                String^ text=Convert::ToString(rtbSent->Text); 
		    for (int i=0; i < text->Length ; i++)
			sendbuf[i] =(char) text[i];
			 BytesSent = send(NewConnection, sendbuf, strlen(sendbuf), 0);
              if(BytesSent == SOCKET_ERROR)
              rtb->AppendText("Client: send() error "+ WSAGetLastError());
     else
     {
          rtb->AppendText("Client: send() is OK - bytes sent:"+BytesSent);
          // Some info on this sender side...
          // Allocate the required resources
          memset(&ThisSenderInfo, 0, sizeof(ThisSenderInfo));
          nlen = sizeof(ThisSenderInfo);
		  //System::String^ text=gcnew String(rtbSent->Text->ToString());
          getsockname(NewConnection, (SOCKADDR *)&ThisSenderInfo, &nlen);
           rtb->AppendText("\r\nClient: Sender IP(s) used: "+gcnew String( inet_ntoa(ThisSenderInfo.sin_addr)));
		   rtb->AppendText("\r\nClient: Sender port used: "+Convert::ToString( htons(ThisSenderInfo.sin_port)));
           rtbSent->AppendText("Client: Those bytes represent: "+text);
     }    

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
                ByteReceived = recv(NewConnection, recvbuff, sizeof(recvbuff), 0);
                            // When there is data
                             if ( ByteReceived > 0 )
                             {
                                rtb->AppendText("Server: recv() looks fine....\n");
                                  // Some info on the receiver side...
                                //  getsockname(ListeningSocket, (SOCKADDR *)&ServerAddr,(int *)sizeof(ServerAddr rtb->AppendText("Server: Receiving IP(s) used:" + Convert::ToString(inet_ntoa(ServerAddr.sin_addr)))));
                                  rtb->AppendText("Server: Receiving port used:"+ Convert::ToString(htons(ServerAddr.sin_port)));
 
                                  // Some info on the sender side
                                  // Allocate the required resources
                                  memset(&SenderInfo, 0, sizeof(SenderInfo));
                                  nlen = sizeof(SenderInfo);
 
                                  getpeername(NewConnection, (SOCKADDR *)&SenderInfo, &nlen);
                                  rtb->AppendText("Server: Sending IP used: %s\n");//, inet_ntoa(SenderInfo.sin_addr)
                                  rtb->AppendText("Server: Sending port used: %d\n");//, htons(SenderInfo.sin_port)
 
                                  // Print the received bytes. Take note that this is the total
                                  // byte received, it is not the size of the declared buffer
                                 rtb->AppendText("Server: Bytes received: %d\n"+ ByteReceived);
                                  // Print what those bytes represent
                                 rtb->AppendText("Server: Those bytes are: \"");
                                  // Print the string only, discard other
                                  // remaining 'rubbish' in the 1024 buffer size
					   System::String^ Text=gcnew String(recvbuff);
                                 //for(i=0;i < ByteReceived;i++)
						rtbRecv->AppendText(Text);
                                 // printf("\"");
                             }
                             // No data
                             else if ( ByteReceived == 0 )
                                 rtb->AppendText("Server: Connection closed!\n");
                             // Others
                             else
                                 rtb->AppendText("Server: recv() failed with error code: %d\n"+ WSAGetLastError());

		 }
}
;}

