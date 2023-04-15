#pragma once
#include <winsock2.h>
#include <stdio.h>
#include <vcclr.h>
#include <sys\types.h> 
#include <sys\stat.h>

#include <io.h>
#define MAXBLOCKSIZE 64

long FileSize64( const char * szFileName ) 
{ 
  struct __stat64 fileStat; 
  int err = _stat64( szFileName, &fileStat ); 
  if (0 != err) return 0; 
  return fileStat.st_size; 
}


 long FileSize(char* filename)
 {
   struct stat stbuf;
   stat(filename, &stbuf);
   return stbuf.st_size;
 }
using namespace System::Threading;
using namespace System::Runtime::InteropServices;

namespace l8server {

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





	private: System::Windows::Forms::TextBox^  sendText;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  listenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  browseFolderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  browseFileToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFD;
	private: System::Windows::Forms::FolderBrowserDialog^  FDBrowser;
	private: System::Windows::Forms::ToolStripMenuItem^  sendToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFD;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;








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
		this->sendText = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->listenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->sendToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->browseFolderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->browseFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
		this->FDBrowser = (gcnew System::Windows::Forms::FolderBrowserDialog());
		this->saveFD = (gcnew System::Windows::Forms::SaveFileDialog());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
		this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
		this->menuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// textBox1
		// 
		this->textBox1->Location = System::Drawing::Point(12, 98);
		this->textBox1->Multiline = true;
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(367, 118);
		this->textBox1->TabIndex = 0;
		this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
		// 
		// sendText
		// 
		this->sendText->Location = System::Drawing::Point(12, 235);
		this->sendText->Multiline = true;
		this->sendText->Name = L"sendText";
		this->sendText->Size = System::Drawing::Size(367, 152);
		this->sendText->TabIndex = 1;
		this->sendText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label1->Location = System::Drawing::Point(12, 82);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(79, 13);
		this->label1->TabIndex = 8;
		this->label1->Text = L"Receive text";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label2->Location = System::Drawing::Point(9, 219);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(61, 13);
		this->label2->TabIndex = 9;
		this->label2->Text = L"Send text";
		// 
		// label3
		// 
		this->label3->BackColor = System::Drawing::Color::Red;
		this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label3->Location = System::Drawing::Point(12, 37);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(367, 46);
		this->label3->TabIndex = 11;
		this->label3->Text = L"                                 \r\n                                 Not Connected" 
			L"";
		// 
		// menuStrip1
		// 
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
			this->toolsToolStripMenuItem});
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(391, 24);
		this->menuStrip1->TabIndex = 12;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// fileToolStripMenuItem
		// 
		this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->listenToolStripMenuItem, 
			this->sendToolStripMenuItem, this->exitToolStripMenuItem});
		this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
		this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
		this->fileToolStripMenuItem->Text = L"&File";
		// 
		// listenToolStripMenuItem
		// 
		this->listenToolStripMenuItem->Name = L"listenToolStripMenuItem";
		this->listenToolStripMenuItem->Size = System::Drawing::Size(165, 22);
		this->listenToolStripMenuItem->Text = L"Start listening";
		this->listenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// sendToolStripMenuItem
		// 
		this->sendToolStripMenuItem->Name = L"sendToolStripMenuItem";
		this->sendToolStripMenuItem->Size = System::Drawing::Size(165, 22);
		this->sendToolStripMenuItem->Text = L"Send";
		this->sendToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
		// 
		// exitToolStripMenuItem
		// 
		this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
		this->exitToolStripMenuItem->Size = System::Drawing::Size(165, 22);
		this->exitToolStripMenuItem->Text = L"E&xit";
		this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
		// 
		// toolsToolStripMenuItem
		// 
		this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->browseFolderToolStripMenuItem, 
			this->browseFileToolStripMenuItem, this->saveAsToolStripMenuItem});
		this->toolsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
		this->toolsToolStripMenuItem->Size = System::Drawing::Size(49, 20);
		this->toolsToolStripMenuItem->Text = L"&Tools";
		// 
		// browseFolderToolStripMenuItem
		// 
		this->browseFolderToolStripMenuItem->Name = L"browseFolderToolStripMenuItem";
		this->browseFolderToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
		this->browseFolderToolStripMenuItem->Size = System::Drawing::Size(208, 22);
		this->browseFolderToolStripMenuItem->Text = L"Browse F&older";
		this->browseFolderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::browseFolderToolStripMenuItem_Click);
		// 
		// browseFileToolStripMenuItem
		// 
		this->browseFileToolStripMenuItem->Name = L"browseFileToolStripMenuItem";
		this->browseFileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
		this->browseFileToolStripMenuItem->Size = System::Drawing::Size(208, 22);
		this->browseFileToolStripMenuItem->Text = L"Browse F&ile";
		this->browseFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::browseFileToolStripMenuItem_Click);
		// 
		// saveAsToolStripMenuItem
		// 
		this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
		this->saveAsToolStripMenuItem->Size = System::Drawing::Size(208, 22);
		this->saveAsToolStripMenuItem->Text = L"Save As";
		this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
		// 
		// openFD
		// 
		this->openFD->FileName = L"openFD";
		// 
		// saveFD
		// 
		this->saveFD->Filter = L"Text files (*.txt)|*.txt|All files (*.*)|*.*";
		this->saveFD->InitialDirectory = L"C:\\";
		this->saveFD->Title = L"SaveAs";
		// 
		// button1
		// 
		this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button1->Location = System::Drawing::Point(262, 416);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(117, 23);
		this->button1->TabIndex = 13;
		this->button1->Text = L"Sendfile";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
		// 
		// progressBar1
		// 
		this->progressBar1->Location = System::Drawing::Point(15, 416);
		this->progressBar1->Name = L"progressBar1";
		this->progressBar1->Size = System::Drawing::Size(203, 23);
		this->progressBar1->TabIndex = 14;
		// 
		// openFileDialog1
		// 
		this->openFileDialog1->FileName = L"openFileDialog1";
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(391, 478);
		this->Controls->Add(this->progressBar1);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->sendText);
		this->Controls->Add(this->textBox1);
		this->Controls->Add(this->menuStrip1);
		this->MainMenuStrip = this->menuStrip1;
		this->Name = L"Form1";
		this->Text = L"ServerUtilities";
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
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
				  label3->BackColor = System::Drawing::Color::Green;
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

	Threading::Thread^ t;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		WSADATA            wsaData;
		label3->Text = "Using port: 8001";
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

		t = gcnew Threading::Thread(ts);
		t->Start();
	}

	void SendText(String^ str) {
		char buff[1024];
		strcpy(buff, (char*)(void*)Marshal::StringToHGlobalAnsi(str));
		int BytesSent = send(NewConnection, buff, strlen(buff) + 1, 0);
	}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 SendText(sendText->Text + Environment::NewLine);
			 sendText->Text = "";
		 }


private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 closesocket(NewConnection);
			 WSACleanup();
			 exit(0);
		 }
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == System::Windows::Forms::Keys::Enter) {
				SendText(sendText->Text);
				sendText->Text = "";
				e->Handled = true;
			 }
			 if(e->KeyCode == System::Windows::Forms::Keys::Escape) {
				exit(0);
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
private: System::Void listenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 button1_Click(sender, e);
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 button2_Click(sender,e);
		 }
private: System::Void browseFolderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  FDBrowser->ShowDialog();
			 textBox1->Text = FDBrowser->SelectedPath + System::Environment::NewLine;
			 textBox1->Text += System::IO::Path::GetFileName(FDBrowser->SelectedPath)+ System::Environment::NewLine;
		 }
private: System::Void browseFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFD->ShowDialog();
			 textBox1->Text=System::IO::Path::GetFileName(openFD->FileName);
		 }
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFD->ShowDialog();
			 textBox1->Text = System::IO::Path::GetFileName(saveFD->FileName);
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			  openFileDialog1->ShowDialog();

			 
			 char buffer[MAXBLOCKSIZE], error_message[MAXBLOCKSIZE];
			 char filename[255],name[50];
			 long file_size;
				int bytes_sent, byte_received;
			 int p1,p2;

			  System::String ^orig = this->openFileDialog1->FileName;
			pin_ptr<const wchar_t> wch = PtrToStringChars(orig);

			size_t origsize = wcslen(wch) + 1;
			const size_t newsize = 100;
			size_t convertedChars = 0;
			char nstring[newsize];
			wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);	
			strcpy( filename , nstring);

			FILE *fp;
			textBox1->Text+="\r\nAttempting to open "+gcnew String(filename);
			

			int poz=openFileDialog1->FileName->LastIndexOf("\\");

			orig = this->openFileDialog1->FileName->Substring(poz+1);
			wch = PtrToStringChars(orig);

			 origsize = wcslen(wch) + 1;
			 convertedChars = 0;
			nstring[newsize];
			wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);	
			strcpy( name , nstring);
			textBox1->Text+=gcnew String(name);
			fp = fopen(filename, "rb");


			if(fp == NULL)
			{
				textBox1->Text+="\r\nError opening file!File I/O Error"+ MB_OK;
			}else{
			
				//file_size=_filelengthi64(fileNum);
				file_size=FileSize(filename);
				
				textBox1->Text+="\r\n"+Convert::ToString(file_size);
				
				p1=HIWORD(file_size);
				p2=LOWORD(file_size);
				buffer[0]=(char)HIBYTE(p1);
				buffer[1]=(char)LOBYTE(p1);
				buffer[2]=(char)HIBYTE(p2);
				buffer[3]=(char)LOBYTE(p2);
				
				send(NewConnection, name,50, 0);
				send(NewConnection, buffer,4, 0);

				progressBar1->Maximum= file_size +1000;
				progressBar1->Value =0;

				while(file_size > 0)
				{
					if (MAXBLOCKSIZE <= file_size)
					fread(buffer, MAXBLOCKSIZE, 1, fp);
					else{
						fread(buffer, file_size, 1, fp);
						buffer[file_size] = '\0';
					}

					if((bytes_sent = send(NewConnection, buffer, MAXBLOCKSIZE, 0)) == SOCKET_ERROR)
					{
						itoa(WSAGetLastError(), error_message, 10);


						textBox1->Text+=gcnew String(error_message)+ "Server Error"+ MB_OK;

						break;

					}//End if
					progressBar1->Value +=bytes_sent;
			
					file_size -= bytes_sent;
					//while(recv(NewConnection, buffer, 1, 0)!=1){}
					

				}//End while

			}//End if/else

			if(fp != NULL)
			fclose(fp);
		 }
};
}

