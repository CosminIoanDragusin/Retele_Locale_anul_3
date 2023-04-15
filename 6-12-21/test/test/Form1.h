#pragma once
#include <winsock2.h>
#include <stdio.h>
#include <vcclr.h>
#define MAXBLOCKSIZE 64

WSADATA              wsaData;
     SOCKET               SendingSocket,ListeningSocket, NewConnection;
     // Server/receiver address
     SOCKADDR_IN          ServerAddr, ThisSenderInfo,SenderInfo;
     // Server/receiver port to connect to
     unsigned int         Port = 5150;
     int  RetCode;
     // Be careful with the array bound, provide some checking mechanism...
     char sendbuf[1024] = "IO";


     // Receiving part
     char          recvbuff[1024];
     int                BytesSent,ByteReceived, i, nlen, SelectTiming;


namespace test {

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
		private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  rtb;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  rtbSent;
	private: System::Windows::Forms::TextBox^  rtbRecv;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;



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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->rtb = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->rtbSent = (gcnew System::Windows::Forms::TextBox());
			this->rtbRecv = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(305, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(64, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(198, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(64, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(103, 22);
			this->textBox2->TabIndex = 2;
			// 
			// rtb
			// 
			this->rtb->Location = System::Drawing::Point(23, 115);
			this->rtb->Multiline = true;
			this->rtb->Name = L"rtb";
			this->rtb->Size = System::Drawing::Size(378, 126);
			this->rtb->TabIndex = 3;
			// 
			// label1
             // 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(20, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"IP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(20, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Port";
			// 
			// rtbSent
			// 
			this->rtbSent->Location = System::Drawing::Point(23, 279);
			this->rtbSent->Multiline = true;
			this->rtbSent->Name = L"rtbSent";
			this->rtbSent->Size = System::Drawing::Size(281, 91);
			this->rtbSent->TabIndex = 6;
			// 
			// rtbRecv
			// 
			this->rtbRecv->Location = System::Drawing::Point(23, 400);
			this->rtbRecv->Multiline = true;
			this->rtbRecv->Name = L"rtbRecv";
			this->rtbRecv->Size = System::Drawing::Size(281, 99);
			this->rtbRecv->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(326, 322);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 48);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Send";
			this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(326, 451);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 48);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Receive";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 528);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->rtbRecv);
			this->Controls->Add(this->rtbSent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->rtb);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
			 private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
              WSAStartup(MAKEWORD(2,2), &wsaData);
	 //textBox5->Text+="Client: Winsock DLL status is %s.\n"+( wsaData.szSystemStatus);
 
     // Create a new socket to make a client connection.
     // AF_INET = 2, The Internet Protocol version 4 (IPv4) address family, TCP protocol
    SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     if(SendingSocket == INVALID_SOCKET)
     {
       rtb->Text+="Client: socket() failed! Error code: \r\n"+( WSAGetLastError());
          // Do the clean up
          WSACleanup();
          // Exit with error
          //return -1;
     }
     else
          rtb->Text+="Client: socket() is OK!\r\n";
	   ServerAddr.sin_family = AF_INET;
     // Port no.
	   Port = Convert::ToInt32(textBox2->Text);
     ServerAddr.sin_port = htons(Port);
    
     // The IP address

	  System::String ^orig = this->textBox1->Text;
pin_ptr<const wchar_t> wch = PtrToStringChars(orig);

size_t origsize = wcslen(wch) + 1;
const size_t newsize = 100;
size_t convertedChars = 0;
char nstring[newsize];
wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);
	 
     ServerAddr.sin_addr.s_addr = inet_addr(nstring);
 
     // Make a connection to the server with socket SendingSocket.
     RetCode = connect(SendingSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));
     if(RetCode != 0)
     {
         rtb->Text+="Client: connect() failed! Error code: \r\n"+( WSAGetLastError());
          // Close the socket
          //closesocket(SendingSocket);
          // Do the clean up
          WSACleanup();
          // Exit with error
          //return -1;
     }
     else
     {
          rtb->Text+="Client: connect() is OK, got connected...\r\n";
          //printf("Client: Ready for sending and/or receiving data...\n");
     }
	  // At this point you can start sending or receiving data on
     // the socket SendingSocket.

			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
            String^ text=Convert::ToString(rtbSent->Text); 
			 
			 for (int i=0; i < text->Length ; i++)
				sendbuf[i] =(char) text[i];
			 
			 BytesSent = send(SendingSocket, sendbuf, strlen(sendbuf), 0);
 
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
          getsockname(SendingSocket, (SOCKADDR *)&ThisSenderInfo, &nlen);
           rtb->AppendText("\r\nClient: Sender IP(s) used: "+gcnew String( inet_ntoa(ThisSenderInfo.sin_addr)));
		   rtb->AppendText("\r\nClient: Sender port used: "+Convert::ToString( htons(ThisSenderInfo.sin_port)));
           rtbSent->AppendText("Client: Those bytes represent: "+text);
     }

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
          
         ByteReceived = recv(SendingSocket, recvbuff, sizeof(recvbuff), 0);
 
                             // When there is data
                             if ( ByteReceived > 0 )
                             {
                                  rtb->AppendText("Server: recv() looks fine....\n");
 
                                  // Some info on the receiver side...
                                  getsockname(ListeningSocket, (SOCKADDR *)&ServerAddr,(int *)sizeof(ServerAddr));

								  //rtb->AppendText("Server: Receiving IP(s) used:" + Convert::ToString(inet_ntoa(ServerAddr.sin_addr)));
                                  //rtb->AppendText("Server: Receiving port used:"+ Convert::ToString(htons(ServerAddr.sin_port)));
 
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
									 rtbRecv->AppendText( Text);
                                 // printf("\"");
                             }
                             // No data
                             else if ( ByteReceived == 0 )
                                 rtb->AppendText("Server: Connection closed!\n");
                             // Others
                             else
                                 rtb->AppendText("Server: recv() failed with error code: %d\n"+ WSAGetLastError());

		 }

	};
}

