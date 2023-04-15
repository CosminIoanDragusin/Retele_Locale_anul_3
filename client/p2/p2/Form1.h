#pragma once
#include <winsock2.h>
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

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
	private: System::Windows::Forms::Button^  button1;




	private:

		 SOCKET             SendingSocket;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  sendText;




	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sendText = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 87);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(316, 114);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(168, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(62, 8);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(62, 30);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"IP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Port";
			// 
			// sendText
			// 
			this->sendText->Location = System::Drawing::Point(12, 231);
			this->sendText->Multiline = true;
			this->sendText->Name = L"sendText";
			this->sendText->Size = System::Drawing::Size(316, 77);
			this->sendText->TabIndex = 0;
			this->sendText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::sendText_KeyDown);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(253, 319);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 215);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"SendData";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"ReceiveData";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 319);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 354);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->sendText);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
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

		while(true) {
		   ByteReceived = recv(SendingSocket, buff, sizeof(buff), 0);

		   if(ByteReceived > 0) {
				PrintStringDel^ print = gcnew PrintStringDel(this, &Form1::PrintString);
				String^ text = gcnew String(buff);
				textBox1->BeginInvoke(print, text);
		   }
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		WSADATA            wsaData;
		SOCKADDR_IN          ServerAddr;

		if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		 {
			 textBox1->Text = "Client: WSAStartup failed with error";
			  // Exit with error
		 }
		 else
		 {
			 textBox1->Text += "Client: The Winsock dll found!" + Environment::NewLine;
			  textBox1->Text += "Client: The current status is" + Environment::NewLine;
			  textBox1->Text += gcnew String(wsaData.szSystemStatus);
		 }
	     
		 if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
		 {
			  //Tell the user that we could not find a usable WinSock DLL
			  textBox1->Text += "Client: The dll do not support the Winsock version" + Environment::NewLine;
			  WSACleanup();
		 }
		 else
		 {
			 textBox1->Text += "Client: The dll supports the Winsock version" + Environment::NewLine;
		 }
	     
		 // Create a new socket to listen for client connections.
		 SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		 int address = inet_addr((char*)(void*)Marshal::StringToHGlobalAnsi(textBox2->Text));
	     
		 // Check for errors to ensure that the socket is a valid socket.
		 if (SendingSocket == INVALID_SOCKET)
		 {
			 textBox1->Text += String::Format("Client: Error at socket(), error code: {0}", WSAGetLastError());
			  WSACleanup();
		 }
		 else {
			  textBox1->Text += "Client: socket() is OK!" + Environment::NewLine;
			 }

		 int port = Convert::ToUInt32(textBox3->Text);


		ServerAddr.sin_family = AF_INET;
		 // Port no.
		 ServerAddr.sin_port = htons(port);
		 // The IP address
		 ServerAddr.sin_addr.s_addr = address;

		 int  RetCode;
		 RetCode = connect(SendingSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));
		  if(RetCode != 0)
		 {
			 textBox1->Text += "Client: connect() failed!" + Environment::NewLine;
			  // Close the socket
			  closesocket(SendingSocket);
			  // Do the clean up
			  WSACleanup();
		 }
		 else textBox1->Text += "Client connected";

		 Threading::ThreadStart^ ts = gcnew Threading::ThreadStart(this,
										   &Form1::ReceiveThread);
		Threading::Thread^ t = gcnew Threading::Thread(ts);
		t->Start();
	}

	void SendText(String^ str) {
		char buff[1024];
		strcpy(buff, (char*)(void*)Marshal::StringToHGlobalAnsi(str));
		int BytesSent = send(SendingSocket, buff, strlen(buff) + 1, 0);
	}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 SendText(sendText->Text);
				 }
private: System::Void sendText_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			  if(e->KeyCode == System::Windows::Forms::Keys::Enter) {
				SendText(sendText->Text);
				sendText->Text = "";
				e->Handled = true;
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
};
}