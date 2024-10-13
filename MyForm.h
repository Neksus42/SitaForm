#pragma once
#include<string>
namespace SitaForm {

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
		static int counter = 0;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		//void Initialize(sql::Connection* con, sql::Statement* stmt, sql::ResultSet* res)
		//{
		//	this->con = con;
		//	this->stmt = stmt;
		//	this->res = res;

		//	// Здесь можно добавить код для работы с переданными параметрами
		//}
	/*private:
		sql::Connection* con;
		sql::Statement* stmt;
		sql::ResultSet* res;*/
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






	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;

	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::TextBox^ ClientNameBox;
	private: System::Windows::Forms::TextBox^ ClientPhoneBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		std::string ConvertString(String^ str);
		void addclient();
		void SitaForm::MyForm::UpdateLabel(String^ text);





		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClientNameBox = (gcnew System::Windows::Forms::TextBox());
			this->ClientPhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Arial", 14));
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1036, 580);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->ClientNameBox);
			this->tabPage1->Controls->Add(this->ClientPhoneBox);
			this->tabPage1->Location = System::Drawing::Point(4, 31);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1028, 545);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Клиенты";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 22);
			this->label4->TabIndex = 13;
			//this->label4->Text = L"label4";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 102);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 32);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Добавить клиента";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(45, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 22);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Добавление клиента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 22);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Телефон клиента";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 22);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Имя клиента";
			// 
			// ClientNameBox
			// 
			this->ClientNameBox->Location = System::Drawing::Point(178, 32);
			this->ClientNameBox->Name = L"ClientNameBox";
			this->ClientNameBox->Size = System::Drawing::Size(161, 29);
			this->ClientNameBox->TabIndex = 6;
			// 
			// ClientPhoneBox
			// 
			this->ClientPhoneBox->Location = System::Drawing::Point(178, 67);
			this->ClientPhoneBox->Name = L"ClientPhoneBox";
			this->ClientPhoneBox->Size = System::Drawing::Size(161, 29);
			this->ClientPhoneBox->TabIndex = 7;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 31);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1028, 545);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(83, 49);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 30);
			this->comboBox1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1036, 580);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
	public:
		 void UpdateButtonText(System::String^ newText) {
			
		}
#pragma endregion


	private: System::Void ClientPhone_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		 




private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	addclient();
}
};
	
}
