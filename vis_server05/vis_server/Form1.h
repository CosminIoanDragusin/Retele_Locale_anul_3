#pragma once
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <vcclr.h>
  

namespace vis_server {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

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
            result = NULL;

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
	private: System::Windows::Forms::Button^  socket_cr;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  accept_bt;

	private: System::Windows::Forms::Button^  listen_bt;

	private: System::Windows::Forms::Button^  bind_bt;

	private: System::Windows::Forms::Button^  info_bt;
	private: System::Windows::Forms::TextBox^  evenim;
	private: System::Windows::Forms::TextBox^  mesaje;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  mesaj;
	private: System::Windows::Forms::Button^  trans_bt;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: 
	

    static SOCKET ListenSocket = INVALID_SOCKET,
           ClientSocket = INVALID_SOCKET;
    struct addrinfo* result; 
    String^ recvbuf;
    int iResult, iSendResult;
    static int recvbuflen = DEFAULT_BUFLEN;
	private: System::Windows::Forms::Button^  bt_ascult;



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
			this->socket_cr = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->accept_bt = (gcnew System::Windows::Forms::Button());
			this->listen_bt = (gcnew System::Windows::Forms::Button());
			this->bind_bt = (gcnew System::Windows::Forms::Button());
			this->info_bt = (gcnew System::Windows::Forms::Button());
			this->evenim = (gcnew System::Windows::Forms::TextBox());
			this->mesaje = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mesaj = (gcnew System::Windows::Forms::TextBox());
			this->trans_bt = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bt_ascult = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// socket_cr
			// 
			this->socket_cr->Location = System::Drawing::Point(19, 13);
			this->socket_cr->Name = L"socket_cr";
			this->socket_cr->Size = System::Drawing::Size(100, 21);
			this->socket_cr->TabIndex = 0;
			this->socket_cr->Text = L"Creare socket";
			this->socket_cr->UseVisualStyleBackColor = true;
			this->socket_cr->Click += gcnew System::EventHandler(this, &Form1::socket_cr_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->accept_bt);
			this->panel1->Controls->Add(this->listen_bt);
			this->panel1->Controls->Add(this->bind_bt);
			this->panel1->Controls->Add(this->info_bt);
			this->panel1->Controls->Add(this->socket_cr);
			this->panel1->Location = System::Drawing::Point(17, 15);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(135, 162);
			this->panel1->TabIndex = 1;
			// 
			// accept_bt
			// 
			this->accept_bt->Enabled = false;
			this->accept_bt->Location = System::Drawing::Point(19, 121);
			this->accept_bt->Name = L"accept_bt";
			this->accept_bt->Size = System::Drawing::Size(100, 21);
			this->accept_bt->TabIndex = 4;
			this->accept_bt->Text = L"accept()";
			this->accept_bt->UseVisualStyleBackColor = true;
			this->accept_bt->Click += gcnew System::EventHandler(this, &Form1::accept_bt_Click);
			// 
			// listen_bt
			// 
			this->listen_bt->Enabled = false;
			this->listen_bt->Location = System::Drawing::Point(19, 94);
			this->listen_bt->Name = L"listen_bt";
			this->listen_bt->Size = System::Drawing::Size(100, 21);
			this->listen_bt->TabIndex = 3;
			this->listen_bt->Text = L"listen()";
			this->listen_bt->UseVisualStyleBackColor = true;
			this->listen_bt->Click += gcnew System::EventHandler(this, &Form1::listen_bt_Click);
			// 
			// bind_bt
			// 
			this->bind_bt->Enabled = false;
			this->bind_bt->Location = System::Drawing::Point(19, 67);
			this->bind_bt->Name = L"bind_bt";
			this->bind_bt->Size = System::Drawing::Size(100, 21);
			this->bind_bt->TabIndex = 2;
			this->bind_bt->Text = L"bind()";
			this->bind_bt->UseVisualStyleBackColor = true;
			this->bind_bt->Click += gcnew System::EventHandler(this, &Form1::bind_bt_Click);
			// 
			// info_bt
			// 
			this->info_bt->Location = System::Drawing::Point(19, 40);
			this->info_bt->Name = L"info_bt";
			this->info_bt->Size = System::Drawing::Size(100, 21);
			this->info_bt->TabIndex = 1;
			this->info_bt->Text = L"Info";
			this->info_bt->UseVisualStyleBackColor = true;
			// 
			// evenim
			// 
			this->evenim->AcceptsReturn = true;
			this->evenim->AcceptsTab = true;
			this->evenim->Location = System::Drawing::Point(17, 208);
			this->evenim->Multiline = true;
			this->evenim->Name = L"evenim";
			this->evenim->ReadOnly = true;
			this->evenim->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->evenim->Size = System::Drawing::Size(401, 62);
			this->evenim->TabIndex = 2;
			// 
			// mesaje
			// 
			this->mesaje->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->mesaje->ForeColor = System::Drawing::SystemColors::InfoText;
			this->mesaje->Location = System::Drawing::Point(170, 43);
			this->mesaje->Multiline = true;
			this->mesaje->Name = L"mesaje";
			this->mesaje->ReadOnly = true;
			this->mesaje->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->mesaje->Size = System::Drawing::Size(239, 77);
			this->mesaje->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(167, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Cerere de conexiune";
			// 
			// mesaj
			// 
			this->mesaj->Location = System::Drawing::Point(170, 138);
			this->mesaj->Multiline = true;
			this->mesaj->Name = L"mesaj";
			this->mesaj->Size = System::Drawing::Size(239, 39);
			this->mesaj->TabIndex = 5;
			// 
			// trans_bt
			// 
			this->trans_bt->Location = System::Drawing::Point(324, 181);
			this->trans_bt->Name = L"trans_bt";
			this->trans_bt->Size = System::Drawing::Size(85, 21);
			this->trans_bt->TabIndex = 6;
			this->trans_bt->Text = L"Transmite";
			this->trans_bt->UseVisualStyleBackColor = true;
			this->trans_bt->Click += gcnew System::EventHandler(this, &Form1::trans_bt_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(14, 192);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Evenimente";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(185, 123);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Scrieti mesajul";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(330, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Lime;
			this->label5->Location = System::Drawing::Point(297, 17);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"    ";
			// 
			// bt_ascult
			// 
			this->bt_ascult->Location = System::Drawing::Point(324, 15);
			this->bt_ascult->Name = L"bt_ascult";
			this->bt_ascult->Size = System::Drawing::Size(85, 21);
			this->bt_ascult->TabIndex = 11;
			this->bt_ascult->Text = L"Asculta";
			this->bt_ascult->UseVisualStyleBackColor = true;
			this->bt_ascult->Click += gcnew System::EventHandler(this, &Form1::bt_ascult_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 292);
			this->Controls->Add(this->bt_ascult);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trans_bt);
			this->Controls->Add(this->mesaj);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->mesaje);
			this->Controls->Add(this->evenim);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void socket_cr_Click(System::Object^  sender, System::EventArgs^  e) {
		  struct addrinfo hints,*res=NULL; 
		  WSADATA wsaData;
		  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
          if (iResult != 0) {
              evenim->Text=String::Concat(evenim->Text,"WSAStartup da eroare\r\n");
		  }else {evenim->Text=String::Concat(evenim->Text,"WSAStartup reusit\r\n");};

          ZeroMemory(&hints, sizeof(hints));
		  hints.ai_family = AF_INET;
		  hints.ai_socktype = SOCK_STREAM;
		  hints.ai_protocol = IPPROTO_TCP;
		  hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
          iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &res);
          if ( iResult != 0 ) {
             evenim->Text=String::Concat(evenim->Text,"getaddrinfo esuat\r\n");
             WSACleanup();
		  } else {
			  this->result=res;
			  evenim->Text=String::Concat(evenim->Text,"getaddrinfo reusit\r\n");
		  };

    // Create a SOCKET for connecting to server

		  ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		  if (ListenSocket == INVALID_SOCKET) {
		    	evenim->Text=String::Concat(evenim->Text,"socket da eroare\r\n");
				freeaddrinfo(result);
				WSACleanup();}
		  else {
				  this->bind_bt->Enabled = true;
				  evenim->Text=String::Concat(evenim->Text,"socket creat\r\n");};
		  };




private: System::Void bind_bt_Click(System::Object^  sender, System::EventArgs^  e) {
			 iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
             if (iResult == SOCKET_ERROR) {
                    evenim->Text=String::Concat(evenim->Text,"bind esuat\r\n");
					freeaddrinfo(result);
					closesocket(ListenSocket);
					WSACleanup();
			 } 
			 else {
				  this->listen_bt->Enabled = true;
				  evenim->Text=String::Concat(evenim->Text,"bind reusit\r\n");};
		  };
private: System::Void listen_bt_Click(System::Object^  sender, System::EventArgs^  e) {
			iResult = listen(ListenSocket, SOMAXCONN);
			if (iResult == SOCKET_ERROR) {
				evenim->Text=String::Concat(evenim->Text,"listen esuat\r\n");
				closesocket(ListenSocket);
				WSACleanup();
			}
			else{
				  this->accept_bt->Enabled = true;
				  evenim->Text=String::Concat(evenim->Text,"listen reusit\r\n");
			};
		 };

		 
		 
		 
		 
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		  
				closesocket(ListenSocket);
				WSACleanup();
				  
};
private: System::Void accept_bt_Click(System::Object^  sender, System::EventArgs^  e) { 
			ClientSocket = accept(ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET) {
				evenim->Text=String::Concat(evenim->Text,"accept esuat\r\n");
				closesocket(ListenSocket);
				WSACleanup();
			}
			else{
			     evenim->Text=String::Concat(evenim->Text,"Serverul a acceptat conexiunea si asculta\r\n");
			};

}
private: System::Void ascult() {
		 
			char rcvbuf[DEFAULT_BUFLEN];
            int recvbuflen =  DEFAULT_BUFLEN; 
		 //do {
				   iResult = recv(ClientSocket, rcvbuf, recvbuflen, 0);
				   if (iResult > 0) {
					   mesaje->Text = String::Concat(mesaje->Text,gcnew String(rcvbuf,0,iResult));
                       mesaje->Text = String::Concat(mesaje->Text,"\r\n");
					}
					else if (iResult == 0)
						evenim->Text=String::Concat(evenim->Text,"Connection closing...\r\n");
					else  {
						evenim->Text=String::Concat(evenim->Text,"recv esuat\r\n");
						closesocket(ClientSocket);
						WSACleanup();
					}

			//} while (iResult > 0);
		 
		 }
 	
private: System::Void bt_ascult_Click(System::Object^  sender, System::EventArgs^  e) {
           ascult();
		 }

private: System::Void trans_bt_Click(System::Object^  sender, System::EventArgs^  e) {
             	//char *sendbuf = "this is a test";
                int recvbuflen = DEFAULT_BUFLEN;
                int sendbuflen = DEFAULT_BUFLEN;
				//char sendbuf[DEFAULT_BUFLEN]; 
				char recvbuf[DEFAULT_BUFLEN];
				char * sendbuf = (char*)(void*)Marshal::StringToHGlobalAnsi(mesaj->Text);
				iResult = send(ClientSocket, sendbuf, (int)strlen(sendbuf), 0 );
					if (iResult == SOCKET_ERROR) {
						evenim->Text=String::Concat(evenim->Text,"send esuat\r\n");
						closesocket(ClientSocket);
						WSACleanup();
					}

				evenim->Text=String::Concat(evenim->Text,"Mesaj trimis\r\n");


		 }
};
}