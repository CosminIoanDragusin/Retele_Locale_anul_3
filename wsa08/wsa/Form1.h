#include <winsock2.h>
#include <stdio.h>
#pragma once


namespace wsa {

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
	private: System::Windows::Forms::TextBox^  text1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->text1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 224);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// text1
			// 
			this->text1->Location = System::Drawing::Point(24, 16);
			this->text1->Multiline = true;
			this->text1->Name = L"text1";
			this->text1->Size = System::Drawing::Size(242, 185);
			this->text1->TabIndex = 1;
			this->text1->TextChanged += gcnew System::EventHandler(this, &Form1::text1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->text1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 	WSADATA wsaData;
   int RetCode;
 
   // Initialize Winsock version 2.2
   if ((RetCode = WSAStartup(MAKEWORD(2,2), &wsaData)) != 0)
   {
      text1->Text=text1->Text+"WSAStartup failed with error "+(RetCode);
     // return 1;
   }
   else
   {
        text1->Text=text1->Text+"The Winsock dll found!";
        text1->Text=text1->Text+"\r\nThe current status is:"+gcnew String(wsaData.szSystemStatus);
	//	char a = char(wsaData.szSystemStatus);
   }
 
   if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )
   {
        //Tell the user that we could not find a usable WinSock DLL
        text1->Text=text1->Text+"The dll do not support the Winsock version "+(LOBYTE(wsaData.wVersion))+(HIBYTE(wsaData.wVersion));
        // When your application is finished call WSACleanup
        WSACleanup();
        // and exit
       // return 0;
   }
   else
   {
        text1->Text=text1->Text+"\r\nThe dll supports the Winsock version "+(LOBYTE(wsaData.wVersion))+(HIBYTE(wsaData.wVersion));
        text1->Text=text1->Text+"\r\nThe highest version this dll can support:"+(LOBYTE(wsaData.wHighVersion))+(HIBYTE(wsaData.wHighVersion));
 
        // Setup Winsock communication code here
 
        // When your application is finished call WSACleanup
        if (WSACleanup() == SOCKET_ERROR)
        text1->Text=text1->Text+"WSACleanup failed with error "+(WSAGetLastError());
        // and exit
      //  return 1;
   }
			 }
	private: System::Void text1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

