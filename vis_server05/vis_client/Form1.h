#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

namespace vis_client {

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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  tb_server;

	private: System::Windows::Forms::Button^  bt_conect;
	private: System::Windows::Forms::Button^  bt_socket;
	private: System::Windows::Forms::DomainUpDown^  tb_port;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  trans_bt;
	private: System::Windows::Forms::TextBox^  mesaj;
	private: System::Windows::Forms::TextBox^  evenim;
	private: System::Windows::Forms::TextBox^  mesaje;

	protected: 

	private:
		static SOCKET ConnectSocket = INVALID_SOCKET;
        struct addrinfo* result;
		int iResult;
	private: System::Windows::Forms::Button^  bt_ascult;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tb_port = (gcnew System::Windows::Forms::DomainUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_server = (gcnew System::Windows::Forms::TextBox());
			this->bt_conect = (gcnew System::Windows::Forms::Button());
			this->bt_socket = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trans_bt = (gcnew System::Windows::Forms::Button());
			this->mesaj = (gcnew System::Windows::Forms::TextBox());
			this->evenim = (gcnew System::Windows::Forms::TextBox());
			this->mesaje = (gcnew System::Windows::Forms::TextBox());
			this->bt_ascult = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tb_port);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->tb_server);
			this->panel1->Controls->Add(this->bt_conect);
			this->panel1->Controls->Add(this->bt_socket);
			this->panel1->Location = System::Drawing::Point(19, 11);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(136, 175);
			this->panel1->TabIndex = 0;
			// 
			// tb_port
			// 
			this->tb_port->Location = System::Drawing::Point(17, 139);
			this->tb_port->Name = L"tb_port";
			this->tb_port->Size = System::Drawing::Size(94, 20);
			this->tb_port->TabIndex = 6;
			this->tb_port->Text = L"1200";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Port";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Adresa serverului";
			// 
			// tb_server
			// 
			this->tb_server->Location = System::Drawing::Point(17, 100);
			this->tb_server->Name = L"tb_server";
			this->tb_server->Size = System::Drawing::Size(96, 20);
			this->tb_server->TabIndex = 2;
			// 
			// bt_conect
			// 
			this->bt_conect->Location = System::Drawing::Point(17, 49);
			this->bt_conect->Name = L"bt_conect";
			this->bt_conect->Size = System::Drawing::Size(96, 27);
			this->bt_conect->TabIndex = 1;
			this->bt_conect->Text = L"Conectare";
			this->bt_conect->UseVisualStyleBackColor = true;
			this->bt_conect->Click += gcnew System::EventHandler(this, &Form1::bt_conect_Click);
			// 
			// bt_socket
			// 
			this->bt_socket->Location = System::Drawing::Point(17, 16);
			this->bt_socket->Name = L"bt_socket";
			this->bt_socket->Size = System::Drawing::Size(96, 27);
			this->bt_socket->TabIndex = 0;
			this->bt_socket->Text = L"Creare socket";
			this->bt_socket->UseVisualStyleBackColor = true;
			this->bt_socket->Click += gcnew System::EventHandler(this, &Form1::bt_socket_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(165, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Scrieti mesajul";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(16, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Evenimente";
			// 
			// trans_bt
			// 
			this->trans_bt->Location = System::Drawing::Point(316, 179);
			this->trans_bt->Name = L"trans_bt";
			this->trans_bt->Size = System::Drawing::Size(91, 31);
			this->trans_bt->TabIndex = 11;
			this->trans_bt->Text = L"Transmite";
			this->trans_bt->UseVisualStyleBackColor = true;
			this->trans_bt->Click += gcnew System::EventHandler(this, &Form1::trans_bt_Click);
			// 
			// mesaj
			// 
			this->mesaj->Location = System::Drawing::Point(168, 113);
			this->mesaj->Multiline = true;
			this->mesaj->Name = L"mesaj";
			this->mesaj->Size = System::Drawing::Size(239, 59);
			this->mesaj->TabIndex = 10;
			// 
			// evenim
			// 
			this->evenim->Location = System::Drawing::Point(19, 216);
			this->evenim->Multiline = true;
			this->evenim->Name = L"evenim";
			this->evenim->ReadOnly = true;
			this->evenim->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->evenim->Size = System::Drawing::Size(403, 71);
			this->evenim->TabIndex = 9;
			// 
			// mesaje
			// 
			this->mesaje->Location = System::Drawing::Point(168, 29);
			this->mesaje->Multiline = true;
			this->mesaje->Name = L"mesaje";
			this->mesaje->Size = System::Drawing::Size(239, 59);
			this->mesaje->TabIndex = 14;
			// 
			// bt_ascult
			// 
			this->bt_ascult->Location = System::Drawing::Point(316, 2);
			this->bt_ascult->Name = L"bt_ascult";
			this->bt_ascult->Size = System::Drawing::Size(91, 21);
			this->bt_ascult->TabIndex = 15;
			this->bt_ascult->Text = L"Asculta";
			this->bt_ascult->UseVisualStyleBackColor = true;
			this->bt_ascult->Click += gcnew System::EventHandler(this, &Form1::bt_ascult_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 299);
			this->Controls->Add(this->bt_ascult);
			this->Controls->Add(this->mesaje);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trans_bt);
			this->Controls->Add(this->mesaj);
			this->Controls->Add(this->evenim);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"client";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bt_socket_Click(System::Object^  sender, System::EventArgs^  e) {
				struct addrinfo *res = NULL,
							*ptr = NULL,
							hints;
				char *nodename="127.0.0.1";
                char *servname=DEFAULT_PORT;
				WSADATA wsaData;
				// Initialize Winsock
				iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
				if (iResult != 0) {
					evenim->Text=String::Concat(evenim->Text,"WSAStartup esuat\r\n");
				};
				ZeroMemory( &hints, sizeof(hints) );
				hints.ai_family = AF_UNSPEC;
				hints.ai_socktype = SOCK_STREAM;
				hints.ai_protocol = IPPROTO_TCP;
				// Resolve the server address and port
				iResult = getaddrinfo(nodename, servname, &hints, &res);
                
				if ( iResult != 0 ) {
					evenim->Text=String::Concat(evenim->Text,"getaddrinfo esuat\r\n");
					WSACleanup();
				} else {
			         this->result=res;
			         evenim->Text=String::Concat(evenim->Text,"getaddrinfo reusit\r\n");
				}
			 }

	private: System::Void bt_conect_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 struct addrinfo *ptr = NULL;
               
				 // Attempt to connect to an address until one succeeds
				 
				 for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

					// Create a SOCKET for connecting to server
					ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
						ptr->ai_protocol);
					if (ConnectSocket == INVALID_SOCKET) {
						evenim->Text=String::Concat(evenim->Text,"Eroare la creare socket-ului client\r\n");
						freeaddrinfo(result);
						WSACleanup();
						break;
					}

					// Connect to server.
					iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
					if (iResult == SOCKET_ERROR) {
						closesocket(ConnectSocket);
						ConnectSocket = INVALID_SOCKET;
						continue;
					}
					break;
				}
				freeaddrinfo(result);
			 }

private: System::Void ascult() {
		 
			char rcvbuf[DEFAULT_BUFLEN];
            int recvbuflen =  DEFAULT_BUFLEN; 
		 //do {
				   iResult = recv(ConnectSocket, rcvbuf, recvbuflen, 0);
				   if (iResult > 0) {
					   mesaje->Text = String::Concat(mesaje->Text,gcnew String(rcvbuf,0,iResult));
                       mesaje->Text = String::Concat(mesaje->Text,"\r\n");
					}
					else if (iResult == 0)
						evenim->Text=String::Concat(evenim->Text,"Connection closing...\r\n");
					else  {
						evenim->Text=String::Concat(evenim->Text,"recv esuat\r\n");
						closesocket(ConnectSocket);
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
				iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
					if (iResult == SOCKET_ERROR) {
						evenim->Text=String::Concat(evenim->Text,"send esuat\r\n");
						closesocket(ConnectSocket);
						WSACleanup();
					}

				evenim->Text=String::Concat(evenim->Text,"Mesaj trimis\r\n");


		 }
};
}

