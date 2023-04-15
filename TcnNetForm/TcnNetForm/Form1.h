#pragma once

namespace TcnNetForm {

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
	private: System::Windows::Forms::Button^  btnStartWsa;
	protected: 

	private: System::Windows::Forms::Button^  btnCreate;
	private: System::Windows::Forms::Button^  btnBind;
	private: System::Windows::Forms::Button^  btnListen;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btnAccept;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::RichTextBox^  richTextBox;

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
			this->btnStartWsa = (gcnew System::Windows::Forms::Button());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnBind = (gcnew System::Windows::Forms::Button());
			this->btnListen = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// btnStartWsa
			// 
			this->btnStartWsa->Location = System::Drawing::Point(399, 32);
			this->btnStartWsa->Name = L"btnStartWsa";
			this->btnStartWsa->Size = System::Drawing::Size(76, 28);
			this->btnStartWsa->TabIndex = 0;
			this->btnStartWsa->Text = L"WsaStart";
			this->btnStartWsa->UseVisualStyleBackColor = true;
			this->btnStartWsa->Click += gcnew System::EventHandler(this, &Form1::btnStartWsa_Click);
			// 
			// btnCreate
			// 
			this->btnCreate->Location = System::Drawing::Point(399, 88);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(76, 28);
			this->btnCreate->TabIndex = 0;
			this->btnCreate->Text = L"Create";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &Form1::btnCreate_Click);
			// 
			// btnBind
			// 
			this->btnBind->Location = System::Drawing::Point(399, 140);
			this->btnBind->Name = L"btnBind";
			this->btnBind->Size = System::Drawing::Size(76, 28);
			this->btnBind->TabIndex = 0;
			this->btnBind->Text = L"Bind";
			this->btnBind->UseVisualStyleBackColor = true;
			this->btnBind->Click += gcnew System::EventHandler(this, &Form1::btnBind_Click);
			// 
			// btnListen
			// 
			this->btnListen->Location = System::Drawing::Point(399, 199);
			this->btnListen->Name = L"btnListen";
			this->btnListen->Size = System::Drawing::Size(76, 28);
			this->btnListen->TabIndex = 0;
			this->btnListen->Text = L"Listen";
			this->btnListen->UseVisualStyleBackColor = true;
			this->btnListen->Click += gcnew System::EventHandler(this, &Form1::btnListen_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(246, 199);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(76, 28);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(136, 199);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(76, 28);
			this->btnAccept->TabIndex = 0;
			this->btnAccept->Text = L"Accept";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &Form1::btnAccept_Click);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(29, 199);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(76, 28);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// richTextBox
			// 
			this->richTextBox->Location = System::Drawing::Point(29, 17);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->Size = System::Drawing::Size(370, 182);
			this->richTextBox->TabIndex = 1;
			this->richTextBox->Text = L"";
			this->richTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 261);
			this->Controls->Add(this->richTextBox);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnListen);
			this->Controls->Add(this->btnBind);
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->btnStartWsa);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void richTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
      // Initialize Winsock version 2.2
     if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
     {
          // MSDN: An application can call the WSAGetLastError() function to determine the
          // extended error code for other Windows sockets functions as is normally
          // done in Windows Sockets even if the WSAStartup function fails or the WSAStartup
          // function was not called to properly initialize Windows Sockets before calling a
          // Windows Sockets function. The WSAGetLastError() function is one of the only functions
          // in the Winsock 2.2 DLL that can be called in the case of a WSAStartup failure
		 richTextBox->Text+= "Server: WSAStartup failed with error %ld" + Convert::ToString (WSAGetLastError())+"\n";
          
     }
     else
     {
          richTextBox->Text+="Server: The Winsock dll found!";
          richTextBox->Text+="Server: The current status is " + gcnew String (wsaData.szSystemStatus)+".\n";
	 }
         if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
     {
          //Tell the user that we could not find a usable WinSock DLL
          richTextBox->Text+="Server: The dll do not support the Winsock version " + LOBYTE(wsaData.wVersion)+ "," + HIBYTE(wsaData.wVersion)+".\n";
                    
          // Do the clean up
          WSACleanup();
          
     }
     else
     {
          richTextBox->Text+="Server: The dll supports the Winsock version " + LOBYTE(wsaData.wVersion)+","+HIBYTE(wsaData.wVersion)+".\n";
                    
          richTextBox->Text+="Server: The highest version this dll can support is "+LOBYTE(wsaData.wHighVersion)+","+ HIBYTE(wsaData.wHighVersion)+".\n";
                    
     }
		 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void TextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void btnCreate_Click(System::Object^  sender, System::EventArgs^  e) {
			  // Create a new socket to listen for client connections.
     ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     
     // Check for errors to ensure that the socket is a valid socket.
     if (ListeningSocket == INVALID_SOCKET)
     {
          richTextBox->Text+="Server: Error at socket(), error code:"+ Convert::ToString (WSAGetLastError())+" ";
          // Clean up
          WSACleanup();
          
     }
     else
          richTextBox->Text+="Server: socket() is OK!\n";
 
     // Set up a SOCKADDR_IN structure that will tell bind that we
     // want to listen for connections on all interfaces using port 5150.
 
     // The IPv4 family
     ServerAddr.sin_family = AF_INET;
     // host-to-network byte order
     ServerAddr.sin_port = htons(Port);
     // Listen on all interface, host-to-network byte order
     ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		 }

private: System::Void btnBind_Click(System::Object^  sender, System::EventArgs^  e) {

			 // Associate the address information with the socket using bind.
     // Call the bind function, passing the created socket and the sockaddr_in
     // structure as parameters. Check for general errors.
     if (bind(ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
     {
		 richTextBox->Text+="Server: bind() failed! Error code: " + Convert::ToString(WSAGetLastError())+". ";
          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // and exit with error
          
     }
     else
          richTextBox->Text+="Server: bind() is OK!";
		 }
private: System::Void btnListen_Click(System::Object^  sender, System::EventArgs^  e) {
       // Listen for client connections. We used a backlog of 5, which
     // is normal for many applications.
     if (listen(ListeningSocket, 5) == SOCKET_ERROR)
     {
          richTextBox->Text+="Server: listen(): Error listening on socket \n" + Convert::ToString(WSAGetLastError())+".\n ";
          // Close the socket
          closesocket(ListeningSocket);
          // Do the clean up
          WSACleanup();
          // Exit with error
          return -1;
     }
     else
          richTextBox->Text+="Server: listen() is OK, I'm waiting for connections...\n");
 
     richTextBox->Text+="Server: accept() is ready...\n");

		 }
private: System::Void btnAccept_Click(System::Object^  sender, System::EventArgs^  e) {
        // Accept a new connection when one arrives.
     while(1)
     {
          NewConnection = SOCKET_ERROR;
          while(NewConnection == SOCKET_ERROR)
          {
              NewConnection = accept(ListeningSocket, NULL, NULL);
          }
 
          richTextBox->Text+="Server: accept() is OK...\n";
          richTextBox->Text+="Server: Client connected, ready for receiving and sending data...\n";
		 }
	 // Transfer the connected socket to the listening socket
          ListeningSocket = NewConnection;
          break;
		  if(closesocket(NewConnection) != 0)
          richTextBox->Text+="Server: Cannot close \"NewConnection\" socket. Error code: %ld\n"+ Convert::ToString(WSAGetLastError())+".\n ";
     else
          richTextBox->Text+="Server: Closing \"NewConnection\" socket...\n";
     }

private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(WSACleanup() != 0)
          richTextBox->Text+="Server: WSACleanup() failed! Error code: %ld\n"+Convert::ToString(WSAGetLastError())+".\n ";
     else
          richTextBox->Text+="Server: WSACleanup() is OK...\n");
     return 0;
}

		 }
}
};
