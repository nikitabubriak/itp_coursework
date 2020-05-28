#pragma once
#include "sort.h"

namespace coursework1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//The constructor code
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(44, 68);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GUI::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 177);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Merge sort";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(109, 177);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Quick sort";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(189, 177);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 32);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Tree sort";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GUI::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(74, 105);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 32);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Generate random array";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GUI::button4_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(84, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Select sorting algorithm:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(79, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(130, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Please enter the directory:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(64, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(160, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Welcome to Array sorter!";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(94, 245);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"2020 Nikita Bubriak";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(69, 222);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"-";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Click += gcnew System::EventHandler(this, &GUI::label3_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"GUI";
			this->Text = L"Array sorter";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		label2->Visible = false;

		textBox1->Text = "D:/KPI/OP2";
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		program.set_dir(textBox1);
		button4->Enabled = true;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		program.array.copy();

		program.sort.merge.divide(program.array.get_array(), m, n-1);

		program.array.output(program.get_dir(), 1);

		button1->Enabled = false;
		button4->Enabled = true;
		button1->Text = "Done!";
		label3->Text = "Merge_sort(n) = O(n log(n))";
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		program.array.copy();

		program.sort.quick.sort(program.array.get_array(), m, n-1);

		program.array.output(program.get_dir(), 2);

		button2->Enabled = false;
		button4->Enabled = true;
		button2->Text = "Done!";
		label3->Text = "Quick_sort(n) = O(n log(n))";
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		program.array.copy();

		program.sort.tree.create(program.array.get_array(), m, n);

		program.array.output(program.get_dir(), 3);

		button3->Enabled = false;
		button4->Enabled = true;
		button3->Text = "Done!";
		label3->Text = "Tree_sort(n) = O(n log(n))";
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		srand((unsigned)time(NULL));
		program.array.generate();
		program.array.output(program.get_dir(), 0);

		label2->Visible = true;
		button4->Enabled = false;

		button1->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = true;

		button1->Text = "Merge sort";
		button2->Text = "Quick sort";
		button3->Text = "Tree sort";
		label3->Text = "[Complexity]";

		//button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	}

private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};

}
