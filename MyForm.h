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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		static int counter = 0;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		//void Initialize(sql::Connection* con, sql::Statement* stmt, sql::ResultSet* res)
		//{
		//	this->con = con;
		//	this->stmt = stmt;
		//	this->res = res;

		//	// ����� ����� �������� ��� ��� ������ � ����������� �����������
		//}
	/*private:
		sql::Connection* con;
		sql::Statement* stmt;
		sql::ResultSet* res;*/
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ ClientID;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		std::string ConvertString(String^ str);
		void addclient();
		void SitaForm::MyForm::UpdateLabel(String^ text);
		void show_all_clients();
		void delete_client();



		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ClientID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClientNameBox = (gcnew System::Windows::Forms::TextBox());
			this->ClientPhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->tabControl1->Margin = System::Windows::Forms::Padding(7);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1748, 976);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->ClientID);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->ClientNameBox);
			this->tabPage1->Controls->Add(this->ClientPhoneBox);
			this->tabPage1->Location = System::Drawing::Point(10, 65);
			this->tabPage1->Margin = System::Windows::Forms::Padding(7);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(7);
			this->tabPage1->Size = System::Drawing::Size(1728, 901);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�������";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1213, 228);
			this->button3->Margin = System::Windows::Forms::Padding(7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(408, 71);
			this->button3->TabIndex = 18;
			this->button3->Text = L"������� �������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1001, 104);
			this->label6->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(228, 47);
			this->label6->TabIndex = 17;
			this->label6->Text = L"ID �������";
			// 
			// ClientID
			// 
			this->ClientID->Location = System::Drawing::Point(1328, 95);
			this->ClientID->Margin = System::Windows::Forms::Padding(7);
			this->ClientID->Name = L"ClientID";
			this->ClientID->Size = System::Drawing::Size(370, 56);
			this->ClientID->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1205, 7);
			this->label5->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(375, 47);
			this->label5->TabIndex = 15;
			this->label5->Text = L"�������� �������";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(166, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(408, 74);
			this->button2->TabIndex = 14;
			this->button2->Text = L"������� ���� ��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(96, 495);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 92;
			this->dataGridView1->RowTemplate->Height = 37;
			this->dataGridView1->Size = System::Drawing::Size(1553, 341);
			this->dataGridView1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 406);
			this->label4->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(285, 47);
			this->label4->TabIndex = 13;
			this->label4->Text = L"�����������";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(166, 228);
			this->button1->Margin = System::Windows::Forms::Padding(7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(408, 71);
			this->button1->TabIndex = 12;
			this->button1->Text = L"�������� �������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(201, 7);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(421, 47);
			this->label3->TabIndex = 11;
			this->label3->Text = L"���������� �������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 158);
			this->label2->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(361, 47);
			this->label2->TabIndex = 10;
			this->label2->Text = L"������� �������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 80);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 47);
			this->label1->TabIndex = 9;
			this->label1->Text = L"��� �������";
			// 
			// ClientNameBox
			// 
			this->ClientNameBox->Location = System::Drawing::Point(415, 71);
			this->ClientNameBox->Margin = System::Windows::Forms::Padding(7);
			this->ClientNameBox->Name = L"ClientNameBox";
			this->ClientNameBox->Size = System::Drawing::Size(370, 56);
			this->ClientNameBox->TabIndex = 6;
			// 
			// ClientPhoneBox
			// 
			this->ClientPhoneBox->Location = System::Drawing::Point(415, 149);
			this->ClientPhoneBox->Margin = System::Windows::Forms::Padding(7);
			this->ClientPhoneBox->Name = L"ClientPhoneBox";
			this->ClientPhoneBox->Size = System::Drawing::Size(370, 56);
			this->ClientPhoneBox->TabIndex = 7;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Location = System::Drawing::Point(10, 65);
			this->tabPage2->Margin = System::Windows::Forms::Padding(7);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(7);
			this->tabPage2->Size = System::Drawing::Size(1728, 901);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(194, 109);
			this->comboBox1->Margin = System::Windows::Forms::Padding(7);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(277, 55);
			this->comboBox1->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1240, 406);
			this->label7->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(285, 47);
			this->label7->TabIndex = 19;
			this->label7->Text = L"�����������";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1748, 976);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	show_all_clients();
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_client();
}
};
	
}
