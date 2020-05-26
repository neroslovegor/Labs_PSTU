#pragma once

namespace Лаб33 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::TextBox^ textBox4;


































































	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;

















private: System::Windows::Forms::TextBox^ textBox1;


private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Panel^ panel1;


private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::Panel^ panel13;

















	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Plum;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox4->Location = System::Drawing::Point(17, 104);
			this->textBox4->MaxLength = 10;
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(365, 29);
			this->textBox4->TabIndex = 23;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(12, 291);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 29);
			this->label1->TabIndex = 50;
			this->label1->Text = L"СС исходного числа";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->Location = System::Drawing::Point(12, 359);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(213, 29);
			this->label2->TabIndex = 51;
			this->label2->Text = L"СС конечного числа";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Location = System::Drawing::Point(12, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(175, 29);
			this->label3->TabIndex = 52;
			this->label3->Text = L"Исходное число";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SkyBlue;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri Light", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button1->Location = System::Drawing::Point(3, 444);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(397, 90);
			this->button1->TabIndex = 53;
			this->button1->Text = L"start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Location = System::Drawing::Point(12, 164);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 29);
			this->label4->TabIndex = 54;
			this->label4->Text = L"Результат";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Plum;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox1->Location = System::Drawing::Point(17, 202);
			this->textBox1->MaximumSize = System::Drawing::Size(425, 29);
			this->textBox1->MaxLength = 10;
			this->textBox1->MinimumSize = System::Drawing::Size(425, 29);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(425, 29);
			this->textBox1->TabIndex = 72;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Plum;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox2->Location = System::Drawing::Point(250, 291);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(135, 29);
			this->textBox2->TabIndex = 75;
			this->textBox2->Text = L"2";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Plum;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox3->Location = System::Drawing::Point(250, 359);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(135, 29);
			this->textBox3->TabIndex = 76;
			this->textBox3->Text = L"2";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Plum;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button2->Location = System::Drawing::Point(365, -25);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 57);
			this->button2->TabIndex = 77;
			this->button2->Text = L"×";
			this->button2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(262, 29);
			this->panel1->TabIndex = 78;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel4->Controls->Add(this->panel2);
			this->panel4->Location = System::Drawing::Point(247, 387);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(135, 1);
			this->panel4->TabIndex = 81;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Location = System::Drawing::Point(0, 28);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(223, 1);
			this->panel2->TabIndex = 82;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel3->Location = System::Drawing::Point(0, 20);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(223, 1);
			this->panel3->TabIndex = 82;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Location = System::Drawing::Point(17, 230);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(365, 1);
			this->panel5->TabIndex = 82;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Location = System::Drawing::Point(0, 28);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(223, 1);
			this->panel6->TabIndex = 82;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel7->Location = System::Drawing::Point(0, 20);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(223, 1);
			this->panel7->TabIndex = 82;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Location = System::Drawing::Point(17, 132);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(365, 1);
			this->panel8->TabIndex = 83;
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel9->Controls->Add(this->panel10);
			this->panel9->Location = System::Drawing::Point(0, 28);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(223, 1);
			this->panel9->TabIndex = 82;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel10->Location = System::Drawing::Point(0, 20);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(223, 1);
			this->panel10->TabIndex = 82;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel11->Controls->Add(this->panel12);
			this->panel11->Location = System::Drawing::Point(247, 319);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(135, 1);
			this->panel11->TabIndex = 84;
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel12->Controls->Add(this->panel13);
			this->panel12->Location = System::Drawing::Point(0, 28);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(223, 1);
			this->panel12->TabIndex = 82;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::SystemColors::GrayText;
			this->panel13->Location = System::Drawing::Point(0, 20);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(223, 1);
			this->panel13->TabIndex = 82;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Plum;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(403, 536);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDown2_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
