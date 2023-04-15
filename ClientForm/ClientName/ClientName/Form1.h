
#include <winsock2.h>
#include <stdio.h>
#include <vcclr.h>
//#include <msclr/marshal.h>


//using namespace msclr::interop;

namespace ClientName {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	WSADATA              wsaData;
     SOCKET               SendingSocket;
     // Server/receiver address
     SOCKADDR_IN          ServerAddr;
     // Server/receiver port to connect to
     unsigned int         Port = 5150;
     int  RetCode;

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textIp;
	private: System::Windows::Forms::TextBox^  textPort;


	private: System::Windows::Forms::Button^  btnConnect;





	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::TextBox^  TextBox;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textIp = (gcnew System::Windows::Forms::TextBox());
			this->textPort = (gcnew System::Windows::Forms::TextBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ip";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(31, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Port";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// textIp
			// 
			this->textIp->Location = System::Drawing::Point(110, 36);
			this->textIp->Name = L"textIp";
			this->textIp->Size = System::Drawing::Size(200, 20);
			this->textIp->TabIndex = 2;
			// 
			// textPort
			// 
			this->textPort->Location = System::Drawing::Point(110, 66);
			this->textPort->Name = L"textPort";
			this->textPort->Size = System::Drawing::Size(200, 20);
			this->textPort->TabIndex = 3;
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(387, 33);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(107, 53);
			this->btnConnect->TabIndex = 4;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(387, 314);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(107, 39);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// TextBox
			// 
			this->TextBox->Location = System::Drawing::Point(47, 135);
			this->TextBox->Multiline = true;
			this->TextBox->Name = L"TextBox";
			this->TextBox->Size = System::Drawing::Size(315, 218);
			this->TextBox->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(506, 366);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->textPort);
			this->Controls->Add(this->textIp);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Initialize Winsock version 2.2
     WSAStartup(MAKEWORD(2,2), &wsaData);
     TextBox->AppendText("Server: WSAStartup failed with error " + Convert::ToString(WSAGetLastError()) + "\n");
     // Create a new socket to make a client connection.
     // AF_INET = 2, The Internet Protocol version 4 (IPv4) address family, TCP protocol
     SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     if(SendingSocket == INVALID_SOCKET)
     {
          TextBox->AppendText("Client: socket() failed! Error code: %ld\n" + Convert::ToString(WSAGetLastError()) + "\n");
          // Do the clean up
          WSACleanup();
          // Exit with error
          
     }
     else
          TextBox->AppendText("Client: socket() is OK!\n");
 
     // Set up a SOCKADDR_IN structure that will be used to connect
     // to a listening server on port 5150. For demonstration
     // purposes, let's assume our server's IP address is 127.0.0.1 or localhost
 
     
     RetCode = connect(SendingSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));
     if(RetCode != 0)
     {
          TextBox->AppendText("Client: connect() failed! Error code: %ld\n" + Convert::ToString(WSAGetLastError()) + "\n");
          // Close the socket
          closesocket(SendingSocket);
          // Do the clean up
          WSACleanup();
          // Exit with error
          
     }
     else
     {
         TextBox->AppendText("Client: connect() is OK, got connected...\n");
          TextBox->AppendText("Client: Ready for sending and receiving data...\n");
     }
 
     // At this point you can start sending or receiving data on
     // the socket SendingSocket. We will describe sending and receiving data
     // later in the chapter.
 
     // When you are finished sending and receiving data on socket SendingSocket,
     // you should close the socket using the closesocket API. We will
     // describe socket closure later in the chapter.
     if(closesocket(SendingSocket) != 0)
          TextBox->AppendText("Client: Cannot close \"SendingSocket\" socket. Error code: %ld\n"+ Convert::ToString(WSAGetLastError()) + "\n");
     else
          TextBox->AppendText("Client: Closing \"SendingSocket\" socket...\n");
 
     // When your application is finished handling the connection, call WSACleanup.
     if(WSACleanup() != 0)
          TextBox->AppendText("Client: WSACleanup() failed!...\n");
     else
          TextBox->AppendText("Client: WSACleanup() is OK...\n");

	 // IPv4
ServerAddr.sin_family = AF_INET;
// Port no.

ServerAddr.sin_port = htons(Convert::ToInt32(textPort->TextBox));
// The IP address
System::String ^orig = this->textIp->TextBox;
pin_ptr<const wchar_t> wch = PtrToStringChars(orig);

size_t origsize = wcslen(wch) + 1;
const size_t newsize = 100;
size_t convertedChars = 0;
char nstring[newsize];
wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);


			 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
            Close();
		 }
};
}

