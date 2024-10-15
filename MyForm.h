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
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;


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
	private: System::Windows::Forms::Label^ label_del_employee;


	private: System::Windows::Forms::Button^ button_delete_employee;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ Employee_ID_Box;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button_showall_employee;
	private: System::Windows::Forms::DataGridView^ dataGridView2_employee;


	private: System::Windows::Forms::Label^ label_add_employee;

	private: System::Windows::Forms::Button^ button_add_employee;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ Employee_name_Box;
	private: System::Windows::Forms::TextBox^ Employee_phone_Box;


	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ Employee_Post_Box;


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
		
		void show_all_clients();
		void delete_client();
		void add_employee();
		void delete_employee();
		void show_all_employee();


		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->Employee_Post_Box = (gcnew System::Windows::Forms::TextBox());
			this->label_del_employee = (gcnew System::Windows::Forms::Label());
			this->button_delete_employee = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Employee_ID_Box = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button_showall_employee = (gcnew System::Windows::Forms::Button());
			this->dataGridView2_employee = (gcnew System::Windows::Forms::DataGridView());
			this->label_add_employee = (gcnew System::Windows::Forms::Label());
			this->button_add_employee = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->Employee_name_Box = (gcnew System::Windows::Forms::TextBox());
			this->Employee_phone_Box = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
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
			this->tabPage1->Text = L"Клиенты";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1240, 406);
			this->label7->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(285, 47);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Отображение";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1213, 228);
			this->button3->Margin = System::Windows::Forms::Padding(7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(408, 71);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Удалить клиента";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1032, 98);
			this->label6->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(228, 47);
			this->label6->TabIndex = 17;
			this->label6->Text = L"ID клиента";
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
			this->label5->Text = L"Удаление клиента";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(166, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(486, 74);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Вывести всех клиентов";
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
			this->label4->Location = System::Drawing::Point(7, 406);
			this->label4->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(285, 47);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Отображение";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(166, 228);
			this->button1->Margin = System::Windows::Forms::Padding(7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(486, 71);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Добавить клиента";
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
			this->label3->Text = L"Добавление клиента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 152);
			this->label2->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(361, 47);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Телефон клиента";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 74);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 47);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Имя клиента";
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
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->Employee_Post_Box);
			this->tabPage2->Controls->Add(this->label_del_employee);
			this->tabPage2->Controls->Add(this->button_delete_employee);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->Employee_ID_Box);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->button_showall_employee);
			this->tabPage2->Controls->Add(this->dataGridView2_employee);
			this->tabPage2->Controls->Add(this->label_add_employee);
			this->tabPage2->Controls->Add(this->button_add_employee);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->Employee_name_Box);
			this->tabPage2->Controls->Add(this->Employee_phone_Box);
			this->tabPage2->Location = System::Drawing::Point(10, 65);
			this->tabPage2->Margin = System::Windows::Forms::Padding(7);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(7);
			this->tabPage2->Size = System::Drawing::Size(1728, 901);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Работники";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(100, 233);
			this->label15->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(231, 47);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Должность";
			// 
			// Employee_Post_Box
			// 
			this->Employee_Post_Box->Location = System::Drawing::Point(444, 233);
			this->Employee_Post_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_Post_Box->Name = L"Employee_Post_Box";
			this->Employee_Post_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_Post_Box->TabIndex = 34;
			// 
			// label_del_employee
			// 
			this->label_del_employee->AutoSize = true;
			this->label_del_employee->Location = System::Drawing::Point(1254, 481);
			this->label_del_employee->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label_del_employee->Name = L"label_del_employee";
			this->label_del_employee->Size = System::Drawing::Size(320, 47);
			this->label_del_employee->TabIndex = 33;
			this->label_del_employee->Text = L"Отображение р";
			// 
			// button_delete_employee
			// 
			this->button_delete_employee->Location = System::Drawing::Point(1227, 303);
			this->button_delete_employee->Margin = System::Windows::Forms::Padding(7);
			this->button_delete_employee->Name = L"button_delete_employee";
			this->button_delete_employee->Size = System::Drawing::Size(408, 71);
			this->button_delete_employee->TabIndex = 32;
			this->button_delete_employee->Text = L"Удалить работника";
			this->button_delete_employee->UseVisualStyleBackColor = true;
			this->button_delete_employee->Click += gcnew System::EventHandler(this, &MyForm::button_delete_employee_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1048, 102);
			this->label9->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(273, 47);
			this->label9->TabIndex = 31;
			this->label9->Text = L"ID работника";
			// 
			// Employee_ID_Box
			// 
			this->Employee_ID_Box->Location = System::Drawing::Point(1344, 99);
			this->Employee_ID_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_ID_Box->Name = L"Employee_ID_Box";
			this->Employee_ID_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_ID_Box->TabIndex = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1221, 11);
			this->label10->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(420, 47);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Удаление работника";
			// 
			// button_showall_employee
			// 
			this->button_showall_employee->Location = System::Drawing::Point(180, 395);
			this->button_showall_employee->Name = L"button_showall_employee";
			this->button_showall_employee->Size = System::Drawing::Size(534, 74);
			this->button_showall_employee->TabIndex = 28;
			this->button_showall_employee->Text = L"Вывести всех работников";
			this->button_showall_employee->UseVisualStyleBackColor = true;
			this->button_showall_employee->Click += gcnew System::EventHandler(this, &MyForm::button_showall_employee_Click);
			// 
			// dataGridView2_employee
			// 
			this->dataGridView2_employee->AllowUserToAddRows = false;
			this->dataGridView2_employee->AllowUserToDeleteRows = false;
			this->dataGridView2_employee->AllowUserToResizeColumns = false;
			this->dataGridView2_employee->AllowUserToResizeRows = false;
			this->dataGridView2_employee->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2_employee->BackgroundColor = System::Drawing::Color::Bisque;
			this->dataGridView2_employee->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2_employee->Location = System::Drawing::Point(108, 550);
			this->dataGridView2_employee->Name = L"dataGridView2_employee";
			this->dataGridView2_employee->ReadOnly = true;
			this->dataGridView2_employee->RowHeadersWidth = 92;
			this->dataGridView2_employee->RowTemplate->Height = 37;
			this->dataGridView2_employee->Size = System::Drawing::Size(1553, 341);
			this->dataGridView2_employee->TabIndex = 20;
			// 
			// label_add_employee
			// 
			this->label_add_employee->AutoSize = true;
			this->label_add_employee->Location = System::Drawing::Point(21, 481);
			this->label_add_employee->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label_add_employee->Name = L"label_add_employee";
			this->label_add_employee->Size = System::Drawing::Size(320, 47);
			this->label_add_employee->TabIndex = 27;
			this->label_add_employee->Text = L"Отображение р";
			// 
			// button_add_employee
			// 
			this->button_add_employee->Location = System::Drawing::Point(180, 303);
			this->button_add_employee->Margin = System::Windows::Forms::Padding(7);
			this->button_add_employee->Name = L"button_add_employee";
			this->button_add_employee->Size = System::Drawing::Size(534, 71);
			this->button_add_employee->TabIndex = 26;
			this->button_add_employee->Text = L"Добавить работника";
			this->button_add_employee->UseVisualStyleBackColor = true;
			this->button_add_employee->Click += gcnew System::EventHandler(this, &MyForm::button_add_employee_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(217, 11);
			this->label12->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(466, 47);
			this->label12->TabIndex = 25;
			this->label12->Text = L"Добавление работника";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 153);
			this->label13->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(406, 47);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Телефон работника";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(56, 75);
			this->label14->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(313, 47);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Имя работника";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// Employee_name_Box
			// 
			this->Employee_name_Box->Location = System::Drawing::Point(444, 75);
			this->Employee_name_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_name_Box->Name = L"Employee_name_Box";
			this->Employee_name_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_name_Box->TabIndex = 21;
			// 
			// Employee_phone_Box
			// 
			this->Employee_phone_Box->Location = System::Drawing::Point(444, 153);
			this->Employee_phone_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_phone_Box->Name = L"Employee_phone_Box";
			this->Employee_phone_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_phone_Box->TabIndex = 22;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(10, 65);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1728, 901);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Заказы";
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(10, 65);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1728, 901);
			this->tabPage4->TabIndex = 3;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(10, 65);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1728, 901);
			this->tabPage5->TabIndex = 4;
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
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->EndInit();
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
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_add_employee_Click(System::Object^ sender, System::EventArgs^ e) {
	add_employee();
}
private: System::Void button_showall_employee_Click(System::Object^ sender, System::EventArgs^ e) {
	show_all_employee();
}
private: System::Void button_delete_employee_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_employee();
}
};
	
}
