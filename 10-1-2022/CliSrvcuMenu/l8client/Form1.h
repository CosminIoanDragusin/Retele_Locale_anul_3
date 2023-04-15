#pragma once
#include <winsock2.h>
#include <stdio.h>
#include <vcclr.h>
#include <sys\types.h> 
#include <sys\stat.h>

#include <io.h>
#define MAXBLOCKSIZE 64

WSADATA              wsaData;
     SOCKET               SendingSocket,ListeningSocket, NewConnection;
     // Server/receiver address
     SOCKADDR_IN          ServerAddr, ThisSenderInfo,SenderInfo;
     // Server/receiver port to connect to
     unsigned int         Port = 8001;
     int  RetCode;
     // Be careful with the array bound, provide some checking mechanism...
     char sendbuf[1024] = "IO";


     // Receiving part
     char          recvbuff[1024];
     int                BytesSent,ByteReceived, i, nlen, SelectTiming;
int recvTimeOutTCP(SOCKET socket, long sec, long usec)
{
    // Setup timeval variable
    struct timeval timeout;
    struct fd_set fds;
 
     // assign the second and microsecond variables
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;
    // Setup fd_set structure
    FD_ZERO(&fds);
    FD_SET(socket, &fds);
    // Possible return values:
    // -1: error occurred
    // 0: timed out
    // > 0: data ready to be read
    return select(0, &fds, 0, 0, &timeout);
}

using namespace System::Runtime::InteropServices;
using namespace System::Threading;

namespace l8 {

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

		SOCKET             SendingSocket;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  sendText;





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  connectMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  exitMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  browseFolderMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  browseFileMenu;
	private: System::Windows::Forms::OpenFileDialog^  openFD;
	private: System::Windows::Forms::FolderBrowserDialog^  FDBrowser;
	private: System::Windows::Forms::ToolStripMenuItem^  sendToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFD;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;




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
			 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			 this->label1 = (gcnew System::Windows::Forms::Label());
			 this->label2 = (gcnew System::Windows::Forms::Label());
			 this->sendText = (gcnew System::Windows::Forms::TextBox());
			 this->label3 = (gcnew System::Windows::Forms::Label());
			 this->label4 = (gcnew System::Windows::Forms::Label());
			 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->connectMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->sendToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->exitMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->browseFolderMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->browseFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			 this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			 this->FDBrowser = (gcnew System::Windows::Forms::FolderBrowserDialog());
			 this->saveFD = (gcnew System::Windows::Forms::SaveFileDialog());
			 this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			 this->button1 = (gcnew System::Windows::Forms::Button());
			 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			 this->menuStrip1->SuspendLayout();
			 this->SuspendLayout();
			 // 
			 // textBox1
			 // 
			 this->textBox1->Location = System::Drawing::Point(12, 100);
			 this->textBox1->Multiline = true;
			 this->textBox1->Name = L"textBox1";
			 this->textBox1->Size = System::Drawing::Size(367, 114);
			 this->textBox1->TabIndex = 2;
			 // 
			 // textBox2
			 // 
			 this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->textBox2->Location = System::Drawing::Point(38, 40);
			 this->textBox2->Name = L"textBox2";
			 this->textBox2->Size = System::Drawing::Size(100, 20);
			 this->textBox2->TabIndex = 0;
			 this->textBox2->Text = L"127.0.0.1";
			 // 
			 // textBox3
			 // 
			 this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->textBox3->Location = System::Drawing::Point(268, 40);
			 this->textBox3->Name = L"textBox3";
			 this->textBox3->Size = System::Drawing::Size(111, 20);
			 this->textBox3->TabIndex = 1;
			 this->textBox3->Text = L"8001";
			 // 
			 // label1
			 // 
			 this->label1->AutoSize = true;
			 this->label1->Location = System::Drawing::Point(15, 43);
			 this->label1->Name = L"label1";
			 this->label1->Size = System::Drawing::Size(17, 13);
			 this->label1->TabIndex = 3;
			 this->label1->Text = L"IP";
			 // 
			 // label2
			 // 
			 this->label2->AutoSize = true;
			 this->label2->Location = System::Drawing::Point(236, 43);
			 this->label2->Name = L"label2";
			 this->label2->Size = System::Drawing::Size(26, 13);
			 this->label2->TabIndex = 4;
			 this->label2->Text = L"Port";
			 // 
			 // sendText
			 // 
			 this->sendText->Location = System::Drawing::Point(12, 233);
			 this->sendText->Multiline = true;
			 this->sendText->Name = L"sendText";
			 this->sendText->Size = System::Drawing::Size(367, 150);
			 this->sendText->TabIndex = 3;
			 this->sendText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::sendText_KeyDown);
			 // 
			 // label3
			 // 
			 this->label3->AutoSize = true;
			 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->label3->Location = System::Drawing::Point(12, 217);
			 this->label3->Name = L"label3";
			 this->label3->Size = System::Drawing::Size(61, 13);
			 this->label3->TabIndex = 5;
			 this->label3->Text = L"Send text";
			 // 
			 // label4
			 // 
			 this->label4->AutoSize = true;
			 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->label4->Location = System::Drawing::Point(9, 84);
			 this->label4->Name = L"label4";
			 this->label4->Size = System::Drawing::Size(79, 13);
			 this->label4->TabIndex = 6;
			 this->label4->Text = L"Receive text";
			 // 
			 // menuStrip1
			 // 
			 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				 this->toolsToolStripMenuItem});
			 this->menuStrip1->Location = System::Drawing::Point(0, 0);
			 this->menuStrip1->Name = L"menuStrip1";
			 this->menuStrip1->Size = System::Drawing::Size(397, 24);
			 this->menuStrip1->TabIndex = 8;
			 this->menuStrip1->Text = L"menuStrip1";
			 // 
			 // fileToolStripMenuItem
			 // 
			 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->connectMenu, 
				 this->sendToolStripMenuItem, this->exitMenu});
			 this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			 this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			 this->fileToolStripMenuItem->Text = L"&File";
			 // 
			 // connectMenu
			 // 
			 this->connectMenu->Name = L"connectMenu";
			 this->connectMenu->Size = System::Drawing::Size(131, 22);
			 this->connectMenu->Text = L"&Connect";
			 this->connectMenu->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			 // 
			 // sendToolStripMenuItem
			 // 
			 this->sendToolStripMenuItem->Name = L"sendToolStripMenuItem";
			 this->sendToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			 this->sendToolStripMenuItem->Text = L"Send";
			 this->sendToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			 // 
			 // exitMenu
			 // 
			 this->exitMenu->Name = L"exitMenu";
			 this->exitMenu->Size = System::Drawing::Size(131, 22);
			 this->exitMenu->Text = L"E&xit";
			 this->exitMenu->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			 // 
			 // toolsToolStripMenuItem
			 // 
			 this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->browseFolderMenu, 
				 this->browseFileMenu, this->saveAsToolStripMenuItem});
			 this->toolsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(238)));
			 this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			 this->toolsToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			 this->toolsToolStripMenuItem->Text = L"Tools";
			 // 
			 // browseFolderMenu
			 // 
			 this->browseFolderMenu->Name = L"browseFolderMenu";
			 this->browseFolderMenu->Size = System::Drawing::Size(164, 22);
			 this->browseFolderMenu->Text = L"Browse Folder";
			 this->browseFolderMenu->Click += gcnew System::EventHandler(this, &Form1::browseFolderToolStripMenuItem_Click);
			 // 
			 // browseFileMenu
			 // 
			 this->browseFileMenu->Name = L"browseFileMenu";
			 this->browseFileMenu->Size = System::Drawing::Size(164, 22);
			 this->browseFileMenu->Text = L"Browse File";
			 this->browseFileMenu->Click += gcnew System::EventHandler(this, &Form1::brouseFileMenu_Click);
			 // 
			 // saveAsToolStripMenuItem
			 // 
			 this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			 this->saveAsToolStripMenuItem->Size = System::Drawing::Size(164, 22);
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
			 this->button1->Location = System::Drawing::Point(288, 404);
			 this->button1->Name = L"button1";
			 this->button1->Size = System::Drawing::Size(91, 23);
			 this->button1->TabIndex = 9;
			 this->button1->Text = L"Receivefile";
			 this->button1->UseVisualStyleBackColor = true;
			 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			 // 
			 // progressBar1
			 // 
			 this->progressBar1->Location = System::Drawing::Point(12, 404);
			 this->progressBar1->Name = L"progressBar1";
			 this->progressBar1->Size = System::Drawing::Size(250, 23);
			 this->progressBar1->TabIndex = 10;
			 // 
			 // Form1
			 // 
			 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			 this->ClientSize = System::Drawing::Size(397, 455);
			 this->Controls->Add(this->progressBar1);
			 this->Controls->Add(this->button1);
			 this->Controls->Add(this->label4);
			 this->Controls->Add(this->label3);
			 this->Controls->Add(this->label2);
			 this->Controls->Add(this->label1);
			 this->Controls->Add(this->textBox3);
			 this->Controls->Add(this->textBox2);
			 this->Controls->Add(this->sendText);
			 this->Controls->Add(this->textBox1);
			 this->Controls->Add(this->menuStrip1);
			 this->MainMenuStrip = this->menuStrip1;
			 this->Name = L"Form1";
			 this->Text = L"ClientUtilities";
			 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			 this->menuStrip1->ResumeLayout(false);
			 this->menuStrip1->PerformLayout();
			 this->ResumeLayout(false);
			 this->PerformLayout();

				 }
#pragma endregion

			/* delegate System::Void PrintStringDel(String^ str);

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
			 }*/

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
				 else textBox1->Text += "Client connected" + Environment::NewLine;;

				/* Threading::ThreadStart^ ts = gcnew Threading::ThreadStart(this,
					 &Form1::ReceiveThread);
				 Threading::Thread^ t = gcnew Threading::Thread(ts);
				 t->Start();*/
			 }

			 void SendText(String^ str) {
				 char buff[1024];
				 strcpy(buff, (char*)(void*)Marshal::StringToHGlobalAnsi(str));
				 int BytesSent = send(SendingSocket, buff, strlen(buff) + 1, 0);
			 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 SendText(sendText->Text + Environment::NewLine);
				 sendText->Text = "";
			 }
	private: System::Void sendText_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
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
	private: System::Void exitMenu_Click(System::Object^  sender, System::EventArgs^  e) {
				 exit(0);			 
			 }
	private: System::Void connectMenu_Click(System::Object^  sender, System::EventArgs^  e) {
				 button1_Click(sender,e);
			 }
	private: System::Void browseFolderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 FDBrowser->ShowDialog();
				 textBox1->Text = FDBrowser->SelectedPath + System::Environment::NewLine;
				 textBox1->Text += System::IO::Path::GetFileName(FDBrowser->SelectedPath)+ System::Environment::NewLine;
			 }
	private: System::Void brouseFileMenu_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFD->ShowDialog();
				 textBox1->Text=System::IO::Path::GetFileName(openFD->FileName);
			 }
	private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 saveFD->ShowDialog();
				 textBox1->Text= System::IO::Path::GetFileName(saveFD->FileName);
			 }
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 exit(0);
			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 //saveFileDialog1->ShowDialog();
			long file_size,fe;
			char filename[255],name[50];
			char buffer[64];
			FILE *fp;
			int bytes_received, bytes_sent;

			bytes_received = recv(SendingSocket, name, 50, 0);
			textBox1->Text+=gcnew String(name);
			saveFileDialog1->FileName=gcnew String(name);
			saveFileDialog1->ShowDialog();


			System::String ^orig = this->saveFileDialog1->FileName;
			pin_ptr<const wchar_t> wch = PtrToStringChars(orig);

			size_t origsize = wcslen(wch) + 1;
			const size_t newsize = 100;
			size_t convertedChars = 0;
			char nstring[newsize];
			wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);	

			strcpy( filename , nstring);



			textBox1->Text+="\r\nAttempting to write to "+gcnew String(filename);
	
			recvTimeOutTCP(SendingSocket,1,0);

			bytes_received = recv(SendingSocket, buffer, 4, 0);
			//buffer[bytes_received] = '\0';
			file_size = (BYTE) buffer[0];
			file_size =  file_size <<24;
			unsigned long f1=(BYTE)buffer[1];
			f1=f1<<16;
			file_size+=f1;
			f1=0;
			f1=(BYTE)buffer[2];
			f1=f1<<8;
			file_size+=f1;
			file_size +=(BYTE) buffer[3];
			progressBar1->Maximum= file_size+1000;
			progressBar1->Value=0;
			textBox1->Text+=Convert::ToString(file_size);

			fp = fopen(filename, "wb");

			if(fp!=NULL){
			while(file_size > 0)
			{
					if (MAXBLOCKSIZE <= file_size)
					bytes_received = recv(SendingSocket, buffer, MAXBLOCKSIZE, 0);
					else
					bytes_received = recv(SendingSocket, buffer, file_size, 0);
					if (bytes_received== SOCKET_ERROR){
					textBox1->Text+="Client: send() error \r\n"+( WSAGetLastError());
					break;}
					//else send(SendingSocket, "1", 1, 0);

					fwrite(buffer, bytes_received,1, fp);
					
					progressBar1->Value+=bytes_received;
					file_size -= (long)bytes_received;
			}//while

		}
			 fclose(fp);
				 }
};
}