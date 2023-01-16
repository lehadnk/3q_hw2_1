#pragma once
#include "../business/WordsSplitter.h"
#include "../business/WordsFilter.h"
#include "../framework/StringConverterHelper.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ descriptionLabel;
	private: System::Windows::Forms::Label^ inputTextboxLabel;
	protected:


	private: System::Windows::Forms::RichTextBox^ inputTextbox;
	private: System::Windows::Forms::Label^ outputTextboxLabel;



	private: System::Windows::Forms::RichTextBox^ outputTextbox;
	private: System::Windows::Forms::Button^ findButton;


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
			this->descriptionLabel = (gcnew System::Windows::Forms::Label());
			this->inputTextboxLabel = (gcnew System::Windows::Forms::Label());
			this->inputTextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->outputTextboxLabel = (gcnew System::Windows::Forms::Label());
			this->outputTextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->findButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// descriptionLabel
			// 
			this->descriptionLabel->AutoSize = true;
			this->descriptionLabel->Location = System::Drawing::Point(17, 9);
			this->descriptionLabel->Name = L"descriptionLabel";
			this->descriptionLabel->Size = System::Drawing::Size(586, 25);
			this->descriptionLabel->TabIndex = 0;
			this->descriptionLabel->Text = L"Задание: найти в тексте слова, заканчивающиеся на гласные";
			// 
			// inputTextboxLabel
			// 
			this->inputTextboxLabel->AutoSize = true;
			this->inputTextboxLabel->Location = System::Drawing::Point(17, 42);
			this->inputTextboxLabel->Name = L"inputTextboxLabel";
			this->inputTextboxLabel->Size = System::Drawing::Size(171, 25);
			this->inputTextboxLabel->TabIndex = 1;
			this->inputTextboxLabel->Text = L"Исходный текст:";
			// 
			// inputTextbox
			// 
			this->inputTextbox->Location = System::Drawing::Point(22, 70);
			this->inputTextbox->Name = L"inputTextbox";
			this->inputTextbox->Size = System::Drawing::Size(635, 164);
			this->inputTextbox->TabIndex = 2;
			this->inputTextbox->Text = L"";
			// 
			// outputTextboxLabel
			// 
			this->outputTextboxLabel->AutoSize = true;
			this->outputTextboxLabel->Location = System::Drawing::Point(17, 299);
			this->outputTextboxLabel->Name = L"outputTextboxLabel";
			this->outputTextboxLabel->Size = System::Drawing::Size(180, 25);
			this->outputTextboxLabel->TabIndex = 3;
			this->outputTextboxLabel->Text = L"Найденные слова:";
			// 
			// outputTextbox
			// 
			this->outputTextbox->Location = System::Drawing::Point(22, 327);
			this->outputTextbox->Name = L"outputTextbox";
			this->outputTextbox->Size = System::Drawing::Size(635, 164);
			this->outputTextbox->TabIndex = 4;
			this->outputTextbox->Text = L"";
			// 
			// findButton
			// 
			this->findButton->Location = System::Drawing::Point(22, 240);
			this->findButton->Name = L"findButton";
			this->findButton->Size = System::Drawing::Size(134, 47);
			this->findButton->TabIndex = 5;
			this->findButton->Text = L"Поиск";
			this->findButton->UseVisualStyleBackColor = true;
			this->findButton->Click += gcnew System::EventHandler(this, &MainForm::findButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(676, 502);
			this->Controls->Add(this->findButton);
			this->Controls->Add(this->outputTextbox);
			this->Controls->Add(this->outputTextboxLabel);
			this->Controls->Add(this->inputTextbox);
			this->Controls->Add(this->inputTextboxLabel);
			this->Controls->Add(this->descriptionLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void findButton_Click(System::Object^ sender, System::EventArgs^ e) {
		auto stringConverter = StringConverterHelper();
		auto stdString = stringConverter.convertString(this->inputTextbox->Text);

		WordsSplitter wordsSplitter = WordsSplitter();
		auto unfilteredWords = wordsSplitter.splitSentence(stdString);

		WordsFilter wordsFilter = WordsFilter();
		auto filteredWords = wordsFilter.filterWordList(unfilteredWords);

		System::String ^ outputStr = "";
		for (int i = 0; i < filteredWords.size(); i++) {
			outputStr += gcnew String(filteredWords[i].c_str());
			if (i < filteredWords.size() - 1) {
				outputStr += " ";
			}
		}

		this->outputTextbox->Text = outputStr;
	}
};
}
