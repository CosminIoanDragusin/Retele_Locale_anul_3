#include <winsock2.h>
#include <stdio.h>
#include <string.h> 
#include <windows.h>
#pragma once


namespace Aplicatie {

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFile;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuNew;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOpen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSave;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuQuit;
	private: System::Windows::Forms::ToolStripMenuItem^  viewProjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewFilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuUndo;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCut;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuCopy;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuPaste;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuView;

	private: System::Windows::Forms::ToolStripMenuItem^  mnuViewTextBoxes;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuViewLabels;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuViewImages;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFD;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewProjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuQuit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuUndo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCut = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuPaste = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuView = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuViewTextBoxes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuViewLabels = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuViewImages = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuFile, this->editToolStripMenuItem, 
				this->mnuView});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(570, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mnuFile
			// 
			this->mnuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->mnuNew, this->mnuOpen, 
				this->mnuSave, this->toolStripMenuItem1, this->mnuQuit});
			this->mnuFile->Name = L"mnuFile";
			this->mnuFile->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->mnuFile->Size = System::Drawing::Size(37, 20);
			this->mnuFile->Text = L"&File";
			// 
			// mnuNew
			// 
			this->mnuNew->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->viewProjectToolStripMenuItem, 
				this->viewFilesToolStripMenuItem});
			this->mnuNew->Name = L"mnuNew";
			this->mnuNew->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->mnuNew->Size = System::Drawing::Size(146, 22);
			this->mnuNew->Text = L"&New";
			// 
			// viewProjectToolStripMenuItem
			// 
			this->viewProjectToolStripMenuItem->Name = L"viewProjectToolStripMenuItem";
			this->viewProjectToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->viewProjectToolStripMenuItem->Text = L"&View Projects";
			// 
			// viewFilesToolStripMenuItem
			// 
			this->viewFilesToolStripMenuItem->Name = L"viewFilesToolStripMenuItem";
			this->viewFilesToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->viewFilesToolStripMenuItem->Text = L"&View Files";
			// 
			// mnuOpen
			// 
			this->mnuOpen->Name = L"mnuOpen";
			this->mnuOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->mnuOpen->Size = System::Drawing::Size(146, 22);
			this->mnuOpen->Text = L"&Open";
			// 
			// mnuSave
			// 
			this->mnuSave->Name = L"mnuSave";
			this->mnuSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->mnuSave->Size = System::Drawing::Size(146, 22);
			this->mnuSave->Text = L"&Save";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(143, 6);
			// 
			// mnuQuit
			// 
			this->mnuQuit->Name = L"mnuQuit";
			this->mnuQuit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->mnuQuit->Size = System::Drawing::Size(146, 22);
			this->mnuQuit->Text = L"&Quit";
			this->mnuQuit->Click += gcnew System::EventHandler(this, &Form1::mnuQuit_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->mnuUndo, 
				this->mnuCut, this->mnuCopy, this->mnuPaste});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// mnuUndo
			// 
			this->mnuUndo->Name = L"mnuUndo";
			this->mnuUndo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->mnuUndo->Size = System::Drawing::Size(144, 22);
			this->mnuUndo->Text = L"&Undo";
			this->mnuUndo->Click += gcnew System::EventHandler(this, &Form1::mnuUndo_Click);
			// 
			// mnuCut
			// 
			this->mnuCut->Name = L"mnuCut";
			this->mnuCut->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->mnuCut->Size = System::Drawing::Size(144, 22);
			this->mnuCut->Text = L"&Cut";
			this->mnuCut->Click += gcnew System::EventHandler(this, &Form1::mnuCut_Click);
			// 
			// mnuCopy
			// 
			this->mnuCopy->Name = L"mnuCopy";
			this->mnuCopy->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->mnuCopy->Size = System::Drawing::Size(144, 22);
			this->mnuCopy->Text = L"&Copy";
			this->mnuCopy->Click += gcnew System::EventHandler(this, &Form1::mnuCopy_Click);
			// 
			// mnuPaste
			// 
			this->mnuPaste->Name = L"mnuPaste";
			this->mnuPaste->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->mnuPaste->Size = System::Drawing::Size(144, 22);
			this->mnuPaste->Text = L"&Paste";
			this->mnuPaste->Click += gcnew System::EventHandler(this, &Form1::mnuPaste_Click);
			// 
			// mnuView
			// 
			this->mnuView->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuViewTextBoxes, 
				this->mnuViewLabels, this->mnuViewImages});
			this->mnuView->Name = L"mnuView";
			this->mnuView->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::V));
			this->mnuView->Size = System::Drawing::Size(44, 20);
			this->mnuView->Text = L"&View";
			// 
			// mnuViewTextBoxes
			// 
			this->mnuViewTextBoxes->Checked = true;
			this->mnuViewTextBoxes->CheckState = System::Windows::Forms::CheckState::Checked;
			this->mnuViewTextBoxes->Name = L"mnuViewTextBoxes";
			this->mnuViewTextBoxes->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::T));
			this->mnuViewTextBoxes->Size = System::Drawing::Size(229, 22);
			this->mnuViewTextBoxes->Text = L"View Text &Boxes";
			this->mnuViewTextBoxes->Click += gcnew System::EventHandler(this, &Form1::mnuViewTextBoxes_Click);
			// 
			// mnuViewLabels
			// 
			this->mnuViewLabels->Name = L"mnuViewLabels";
			this->mnuViewLabels->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::Y));
			this->mnuViewLabels->Size = System::Drawing::Size(229, 22);
			this->mnuViewLabels->Text = L"View &Labels";
			// 
			// mnuViewImages
			// 
			this->mnuViewImages->Name = L"mnuViewImages";
			this->mnuViewImages->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::I));
			this->mnuViewImages->Size = System::Drawing::Size(229, 22);
			this->mnuViewImages->Text = L"View &Images";
			this->mnuViewImages->Click += gcnew System::EventHandler(this, &Form1::mnuViewImages_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 56);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 68);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(204, 56);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 68);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(95, 153);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(165, 63);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// openFD
			// 
			this->openFD->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(570, 261);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mnuQuit_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (MessageBox->Show("Really Quit?", "Exit", MessageBoxButtons->OKCancel) == DialogResult->OK){	
					 exit(0);}
				 
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void mnuCut_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^someText;
			 if(textBox1->SelectedText!="") {
				 someText=textBox1->SelectedText;
				// textBox1->Cut();
				 MessageBox->Show(someText);
			 }
		 }
private: System::Void mnuUndo_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox1->CanUndo== true){
			 textBox1->Undo();
		 }
		 }
private: System::Void mnuCopy_Click(System::Object^  sender, System::EventArgs^  e) {
if (textBox1->SelectionLength > 0)
{
textBox1->Copy();
}
		 }
private: System::Void mnuPaste_Click(System::Object^  sender, System::EventArgs^  e) {
if (Clipboard->GetDataObject()->GetDataPresent(DataFormats->Text) == true)
{
textBox2->Paste();
Clipboard->Clear();
}
		 }
private: System::Void mnuViewTextBoxes_Click(System::Object^  sender, System::EventArgs^  e) {
mnuViewTextboxes->Checked = true;
mnuViewTextboxes->Checked = !mnuViewTextboxes->Checked;

if (mnuViewTextboxes->Checked)
{
textBox1->Visible = true;
textBox2->Visible = true;
}
else
{
textBox1->Visible = false;
textBox2->Visible = false;
}
textBox1->Visible = !textBox1->Visible;

		 }
private: System::Void mnuViewImages_Click(System::Object^  sender, System::EventArgs^  e) {

			 string ^chosenFile =" ";

			 openFD->InitialDirectory = "C:";
			 openFD->Title = "Insert an Image";
			 openFD->FileName = "";
			 openFD->Filter = "JPEG Images|*.jpg|GIF Images|*.gif|BITMAPS|*.bmp";
			 openFD->ShowDialog( );
			 chosenFile=openFD->FileName;

		 }
};
}

