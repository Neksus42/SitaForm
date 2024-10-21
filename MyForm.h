#pragma once

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include<string>
#include <msclr/marshal_cppstd.h>
#include <regex>
#include<thread>
#include<chrono>
bool validation(std::string tovalidate, std::string parameter);
bool validation_digits(std::string tovalidate);
bool validation_phone(std::string tovalidate);
extern sql::mysql::MySQL_Driver* driver;
extern sql::Connection* con;
extern sql::Statement* stmt;
extern sql::ResultSet* res;
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
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ Price_Box;

	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ ID_Client_Box;
	private: System::Windows::Forms::ComboBox^ comboBox1_Status;



	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::TextBox^ Brand_Box;

	private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::TextBox^ DeviceType_Box;

	private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::TextBox^ ID_Order_Box;

private: System::Windows::Forms::Button^ button_add_order;
private: System::Windows::Forms::Label^ Order_Label;
private: System::Windows::Forms::Label^ label_add_device;
private: System::Windows::Forms::Button^ button_add_device;
private: System::Windows::Forms::DataGridView^ dataGridView2_Orders;
private: System::Windows::Forms::Button^ button_show_orders;
private: System::Windows::Forms::TextBox^ textBox_forOrder;
private: System::Windows::Forms::Button^ button_selected_order;
private: System::Windows::Forms::Button^ button_delete_order;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::TextBox^ textBox_order_forreport;

private: System::Windows::Forms::Label^ label_23;
private: System::Windows::Forms::RichTextBox^ richTextBox1_for_problem;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::RichTextBox^ richTextBox1_for_recommendtaion;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Label^ label_for_reports;
private: System::Windows::Forms::DataGridView^ dataGridView2_reports;

private: System::Windows::Forms::Button^ button_show_reports;
private: System::Windows::Forms::TextBox^ textBox_selected_report;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ button_for_making_order;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::TextBox^ textBox_order_idemployee;
private: System::Windows::Forms::TextBox^ textBox_order_foridorder;
private: System::Windows::Forms::Label^ label_for_asign;
private: System::Windows::Forms::Button^ button_show_all_asign;
private: System::Windows::Forms::DataGridView^ dataGridView_for_asign;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::TextBox^ textBox_for_selected_asign;








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
		void add_order();
		void add_device();
		void show_all_orders();
		void change_combobox();
		void selected_order();
		void combobox_selected_event();
		//void datagridlclick();




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
			this->button_delete_order = (gcnew System::Windows::Forms::Button());
			this->button_selected_order = (gcnew System::Windows::Forms::Button());
			this->textBox_forOrder = (gcnew System::Windows::Forms::TextBox());
			this->button_show_orders = (gcnew System::Windows::Forms::Button());
			this->dataGridView2_Orders = (gcnew System::Windows::Forms::DataGridView());
			this->label_add_device = (gcnew System::Windows::Forms::Label());
			this->button_add_device = (gcnew System::Windows::Forms::Button());
			this->Order_Label = (gcnew System::Windows::Forms::Label());
			this->button_add_order = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->Brand_Box = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->DeviceType_Box = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->ID_Order_Box = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1_Status = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->Price_Box = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->ID_Client_Box = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox_selected_report = (gcnew System::Windows::Forms::TextBox());
			this->button_show_reports = (gcnew System::Windows::Forms::Button());
			this->dataGridView2_reports = (gcnew System::Windows::Forms::DataGridView());
			this->label_for_reports = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1_for_recommendtaion = (gcnew System::Windows::Forms::RichTextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1_for_problem = (gcnew System::Windows::Forms::RichTextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox_order_forreport = (gcnew System::Windows::Forms::TextBox());
			this->label_23 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox_for_selected_asign = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView_for_asign = (gcnew System::Windows::Forms::DataGridView());
			this->button_show_all_asign = (gcnew System::Windows::Forms::Button());
			this->label_for_asign = (gcnew System::Windows::Forms::Label());
			this->button_for_making_order = (gcnew System::Windows::Forms::Button());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox_order_idemployee = (gcnew System::Windows::Forms::TextBox());
			this->textBox_order_foridorder = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_Orders))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_reports))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_for_asign))->BeginInit();
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
			this->tabControl1->Size = System::Drawing::Size(2095, 1274);
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
			this->tabPage1->Size = System::Drawing::Size(2075, 1199);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Клиенты";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1552, 406);
			this->label7->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(285, 47);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Отображение";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1526, 228);
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
			this->label6->Location = System::Drawing::Point(1344, 98);
			this->label6->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(228, 47);
			this->label6->TabIndex = 17;
			this->label6->Text = L"ID клиента";
			// 
			// ClientID
			// 
			this->ClientID->Location = System::Drawing::Point(1640, 96);
			this->ClientID->Margin = System::Windows::Forms::Padding(7);
			this->ClientID->Name = L"ClientID";
			this->ClientID->Size = System::Drawing::Size(370, 56);
			this->ClientID->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1517, 7);
			this->label5->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(375, 47);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Удаление клиента";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(166, 319);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(485, 74);
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
			this->dataGridView1->Location = System::Drawing::Point(166, 605);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 92;
			this->dataGridView1->RowTemplate->Height = 37;
			this->dataGridView1->Size = System::Drawing::Size(1769, 551);
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
			this->button1->Size = System::Drawing::Size(485, 71);
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
			this->label1->Location = System::Drawing::Point(89, 74);
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
			this->ClientNameBox->Text = L" ";
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
			this->tabPage2->Size = System::Drawing::Size(2075, 1199);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Работники";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(100, 232);
			this->label15->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(231, 47);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Должность";
			// 
			// Employee_Post_Box
			// 
			this->Employee_Post_Box->Location = System::Drawing::Point(443, 232);
			this->Employee_Post_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_Post_Box->Name = L"Employee_Post_Box";
			this->Employee_Post_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_Post_Box->TabIndex = 34;
			// 
			// label_del_employee
			// 
			this->label_del_employee->AutoSize = true;
			this->label_del_employee->Location = System::Drawing::Point(1552, 482);
			this->label_del_employee->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label_del_employee->Name = L"label_del_employee";
			this->label_del_employee->Size = System::Drawing::Size(320, 47);
			this->label_del_employee->TabIndex = 33;
			this->label_del_employee->Text = L"Отображение р";
			// 
			// button_delete_employee
			// 
			this->button_delete_employee->Location = System::Drawing::Point(1526, 303);
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
			this->label9->Location = System::Drawing::Point(1346, 103);
			this->label9->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(273, 47);
			this->label9->TabIndex = 31;
			this->label9->Text = L"ID работника";
			// 
			// Employee_ID_Box
			// 
			this->Employee_ID_Box->Location = System::Drawing::Point(1643, 98);
			this->Employee_ID_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_ID_Box->Name = L"Employee_ID_Box";
			this->Employee_ID_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_ID_Box->TabIndex = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1519, 11);
			this->label10->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(420, 47);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Удаление работника";
			// 
			// button_showall_employee
			// 
			this->button_showall_employee->Location = System::Drawing::Point(180, 395);
			this->button_showall_employee->Margin = System::Windows::Forms::Padding(2);
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
			this->dataGridView2_employee->Location = System::Drawing::Point(110, 732);
			this->dataGridView2_employee->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2_employee->Name = L"dataGridView2_employee";
			this->dataGridView2_employee->ReadOnly = true;
			this->dataGridView2_employee->RowHeadersWidth = 92;
			this->dataGridView2_employee->RowTemplate->Height = 37;
			this->dataGridView2_employee->Size = System::Drawing::Size(1848, 404);
			this->dataGridView2_employee->TabIndex = 20;
			// 
			// label_add_employee
			// 
			this->label_add_employee->AutoSize = true;
			this->label_add_employee->Location = System::Drawing::Point(21, 482);
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
			this->label13->Location = System::Drawing::Point(7, 154);
			this->label13->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(406, 47);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Телефон работника";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(56, 76);
			this->label14->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(313, 47);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Имя работника";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// Employee_name_Box
			// 
			this->Employee_name_Box->Location = System::Drawing::Point(443, 76);
			this->Employee_name_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_name_Box->Name = L"Employee_name_Box";
			this->Employee_name_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_name_Box->TabIndex = 21;
			// 
			// Employee_phone_Box
			// 
			this->Employee_phone_Box->Location = System::Drawing::Point(443, 154);
			this->Employee_phone_Box->Margin = System::Windows::Forms::Padding(7);
			this->Employee_phone_Box->Name = L"Employee_phone_Box";
			this->Employee_phone_Box->Size = System::Drawing::Size(370, 56);
			this->Employee_phone_Box->TabIndex = 22;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button_delete_order);
			this->tabPage3->Controls->Add(this->button_selected_order);
			this->tabPage3->Controls->Add(this->textBox_forOrder);
			this->tabPage3->Controls->Add(this->button_show_orders);
			this->tabPage3->Controls->Add(this->dataGridView2_Orders);
			this->tabPage3->Controls->Add(this->label_add_device);
			this->tabPage3->Controls->Add(this->button_add_device);
			this->tabPage3->Controls->Add(this->Order_Label);
			this->tabPage3->Controls->Add(this->button_add_order);
			this->tabPage3->Controls->Add(this->label21);
			this->tabPage3->Controls->Add(this->Brand_Box);
			this->tabPage3->Controls->Add(this->label20);
			this->tabPage3->Controls->Add(this->DeviceType_Box);
			this->tabPage3->Controls->Add(this->label19);
			this->tabPage3->Controls->Add(this->ID_Order_Box);
			this->tabPage3->Controls->Add(this->comboBox1_Status);
			this->tabPage3->Controls->Add(this->label16);
			this->tabPage3->Controls->Add(this->Price_Box);
			this->tabPage3->Controls->Add(this->label17);
			this->tabPage3->Controls->Add(this->label18);
			this->tabPage3->Controls->Add(this->ID_Client_Box);
			this->tabPage3->Controls->Add(this->label8);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Location = System::Drawing::Point(10, 65);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(2075, 1199);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Заказы";
			this->tabPage3->Click += gcnew System::EventHandler(this, &MyForm::tabPage3_Click);
			// 
			// button_delete_order
			// 
			this->button_delete_order->Location = System::Drawing::Point(670, 630);
			this->button_delete_order->Margin = System::Windows::Forms::Padding(7);
			this->button_delete_order->Name = L"button_delete_order";
			this->button_delete_order->Size = System::Drawing::Size(415, 67);
			this->button_delete_order->TabIndex = 57;
			this->button_delete_order->Text = L"Удалить заказ";
			this->button_delete_order->UseVisualStyleBackColor = true;
			this->button_delete_order->Click += gcnew System::EventHandler(this, &MyForm::button_delete_order_Click);
			// 
			// button_selected_order
			// 
			this->button_selected_order->Location = System::Drawing::Point(670, 549);
			this->button_selected_order->Margin = System::Windows::Forms::Padding(7);
			this->button_selected_order->Name = L"button_selected_order";
			this->button_selected_order->Size = System::Drawing::Size(415, 67);
			this->button_selected_order->TabIndex = 56;
			this->button_selected_order->Text = L"Отобразить заказ";
			this->button_selected_order->UseVisualStyleBackColor = true;
			this->button_selected_order->Click += gcnew System::EventHandler(this, &MyForm::button_selected_order_Click);
			// 
			// textBox_forOrder
			// 
			this->textBox_forOrder->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_forOrder->Location = System::Drawing::Point(147, 551);
			this->textBox_forOrder->Margin = System::Windows::Forms::Padding(7);
			this->textBox_forOrder->Name = L"textBox_forOrder";
			this->textBox_forOrder->Size = System::Drawing::Size(436, 56);
			this->textBox_forOrder->TabIndex = 55;
			this->textBox_forOrder->Text = L"Введите ID заказа...";
			this->textBox_forOrder->Enter += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Enter);
			this->textBox_forOrder->Leave += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Leave);
			// 
			// button_show_orders
			// 
			this->button_show_orders->Location = System::Drawing::Point(194, 337);
			this->button_show_orders->Margin = System::Windows::Forms::Padding(7);
			this->button_show_orders->Name = L"button_show_orders";
			this->button_show_orders->Size = System::Drawing::Size(415, 67);
			this->button_show_orders->TabIndex = 54;
			this->button_show_orders->Text = L"Показать заказы";
			this->button_show_orders->UseVisualStyleBackColor = true;
			this->button_show_orders->Click += gcnew System::EventHandler(this, &MyForm::button_show_orders_Click);
			// 
			// dataGridView2_Orders
			// 
			this->dataGridView2_Orders->AllowUserToAddRows = false;
			this->dataGridView2_Orders->AllowUserToDeleteRows = false;
			this->dataGridView2_Orders->AllowUserToResizeColumns = false;
			this->dataGridView2_Orders->AllowUserToResizeRows = false;
			this->dataGridView2_Orders->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2_Orders->BackgroundColor = System::Drawing::Color::Brown;
			this->dataGridView2_Orders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2_Orders->Location = System::Drawing::Point(147, 747);
			this->dataGridView2_Orders->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2_Orders->Name = L"dataGridView2_Orders";
			this->dataGridView2_Orders->ReadOnly = true;
			this->dataGridView2_Orders->RowHeadersWidth = 92;
			this->dataGridView2_Orders->RowTemplate->Height = 37;
			this->dataGridView2_Orders->Size = System::Drawing::Size(1848, 435);
			this->dataGridView2_Orders->TabIndex = 53;
			this->dataGridView2_Orders->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_Orders_CellClick);
			// 
			// label_add_device
			// 
			this->label_add_device->AutoSize = true;
			this->label_add_device->Location = System::Drawing::Point(1430, 424);
			this->label_add_device->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label_add_device->Name = L"label_add_device";
			this->label_add_device->Size = System::Drawing::Size(423, 47);
			this->label_add_device->TabIndex = 52;
			this->label_add_device->Text = L"Отображение заказа";
			// 
			// button_add_device
			// 
			this->button_add_device->Location = System::Drawing::Point(1526, 328);
			this->button_add_device->Margin = System::Windows::Forms::Padding(7);
			this->button_add_device->Name = L"button_add_device";
			this->button_add_device->Size = System::Drawing::Size(481, 67);
			this->button_add_device->TabIndex = 51;
			this->button_add_device->Text = L"Добавить устройство";
			this->button_add_device->UseVisualStyleBackColor = true;
			this->button_add_device->Click += gcnew System::EventHandler(this, &MyForm::button_add_device_Click);
			// 
			// Order_Label
			// 
			this->Order_Label->AutoSize = true;
			this->Order_Label->Location = System::Drawing::Point(184, 424);
			this->Order_Label->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->Order_Label->Name = L"Order_Label";
			this->Order_Label->Size = System::Drawing::Size(423, 47);
			this->Order_Label->TabIndex = 50;
			this->Order_Label->Text = L"Отображение заказа";
			// 
			// button_add_order
			// 
			this->button_add_order->Location = System::Drawing::Point(194, 257);
			this->button_add_order->Margin = System::Windows::Forms::Padding(7);
			this->button_add_order->Name = L"button_add_order";
			this->button_add_order->Size = System::Drawing::Size(415, 67);
			this->button_add_order->TabIndex = 49;
			this->button_add_order->Text = L"Добавить заказ";
			this->button_add_order->UseVisualStyleBackColor = true;
			this->button_add_order->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(1199, 257);
			this->label21->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(318, 47);
			this->label21->TabIndex = 48;
			this->label21->Text = L"Производитель";
			// 
			// Brand_Box
			// 
			this->Brand_Box->Location = System::Drawing::Point(1566, 250);
			this->Brand_Box->Margin = System::Windows::Forms::Padding(7);
			this->Brand_Box->Name = L"Brand_Box";
			this->Brand_Box->Size = System::Drawing::Size(370, 56);
			this->Brand_Box->TabIndex = 47;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1199, 176);
			this->label20->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(317, 47);
			this->label20->TabIndex = 46;
			this->label20->Text = L"Тип устройства";
			// 
			// DeviceType_Box
			// 
			this->DeviceType_Box->Location = System::Drawing::Point(1566, 170);
			this->DeviceType_Box->Margin = System::Windows::Forms::Padding(7);
			this->DeviceType_Box->Name = L"DeviceType_Box";
			this->DeviceType_Box->Size = System::Drawing::Size(370, 56);
			this->DeviceType_Box->TabIndex = 45;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(1199, 98);
			this->label19->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(200, 47);
			this->label19->TabIndex = 44;
			this->label19->Text = L"ID заказа";
			// 
			// ID_Order_Box
			// 
			this->ID_Order_Box->Location = System::Drawing::Point(1566, 91);
			this->ID_Order_Box->Margin = System::Windows::Forms::Padding(7);
			this->ID_Order_Box->Name = L"ID_Order_Box";
			this->ID_Order_Box->Size = System::Drawing::Size(370, 56);
			this->ID_Order_Box->TabIndex = 43;
			// 
			// comboBox1_Status
			// 
			this->comboBox1_Status->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1_Status->FormattingEnabled = true;
			this->comboBox1_Status->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Ожидание", L"Диагностика", L"Ремонт",
					L"Завершён"
			});
			this->comboBox1_Status->Location = System::Drawing::Point(1566, 549);
			this->comboBox1_Status->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1_Status->Name = L"comboBox1_Status";
			this->comboBox1_Status->Size = System::Drawing::Size(370, 55);
			this->comboBox1_Status->TabIndex = 42;
			this->comboBox1_Status->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_Status_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(138, 183);
			this->label16->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(120, 47);
			this->label16->TabIndex = 41;
			this->label16->Text = L"Цена";
			// 
			// Price_Box
			// 
			this->Price_Box->Location = System::Drawing::Point(455, 176);
			this->Price_Box->Margin = System::Windows::Forms::Padding(7);
			this->Price_Box->Name = L"Price_Box";
			this->Price_Box->Size = System::Drawing::Size(370, 56);
			this->Price_Box->TabIndex = 40;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(1178, 555);
			this->label17->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(290, 47);
			this->label17->TabIndex = 39;
			this->label17->Text = L"Статус заказа";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(89, 91);
			this->label18->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(228, 47);
			this->label18->TabIndex = 38;
			this->label18->Text = L"ID клиента";
			// 
			// ID_Client_Box
			// 
			this->ID_Client_Box->Location = System::Drawing::Point(455, 85);
			this->ID_Client_Box->Margin = System::Windows::Forms::Padding(7);
			this->ID_Client_Box->Name = L"ID_Client_Box";
			this->ID_Client_Box->Size = System::Drawing::Size(370, 56);
			this->ID_Client_Box->TabIndex = 36;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1524, 20);
			this->label8->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(461, 47);
			this->label8->TabIndex = 31;
			this->label8->Text = L"Устройство для заказа";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(208, 20);
			this->label11->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(412, 47);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Составление заказа";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->button6);
			this->tabPage4->Controls->Add(this->button5);
			this->tabPage4->Controls->Add(this->textBox_selected_report);
			this->tabPage4->Controls->Add(this->button_show_reports);
			this->tabPage4->Controls->Add(this->dataGridView2_reports);
			this->tabPage4->Controls->Add(this->label_for_reports);
			this->tabPage4->Controls->Add(this->button4);
			this->tabPage4->Controls->Add(this->richTextBox1_for_recommendtaion);
			this->tabPage4->Controls->Add(this->label24);
			this->tabPage4->Controls->Add(this->richTextBox1_for_problem);
			this->tabPage4->Controls->Add(this->label23);
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->textBox_order_forreport);
			this->tabPage4->Controls->Add(this->label_23);
			this->tabPage4->Location = System::Drawing::Point(10, 65);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(2075, 1199);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Отчёты";
			this->tabPage4->Click += gcnew System::EventHandler(this, &MyForm::tabPage4_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button6->Location = System::Drawing::Point(28, 1005);
			this->button6->Margin = System::Windows::Forms::Padding(7);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(445, 78);
			this->button6->TabIndex = 58;
			this->button6->Text = L"Удалить отчёт";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button5->Location = System::Drawing::Point(28, 892);
			this->button5->Margin = System::Windows::Forms::Padding(7);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(445, 78);
			this->button5->TabIndex = 57;
			this->button5->Text = L"Отобразить отчёт";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox_selected_report
			// 
			this->textBox_selected_report->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_selected_report->Location = System::Drawing::Point(28, 803);
			this->textBox_selected_report->Name = L"textBox_selected_report";
			this->textBox_selected_report->Size = System::Drawing::Size(445, 56);
			this->textBox_selected_report->TabIndex = 56;
			this->textBox_selected_report->Text = L"Введите ID отчёта...";
			this->textBox_selected_report->Enter += gcnew System::EventHandler(this, &MyForm::textBox1_Enter);
			this->textBox_selected_report->Leave += gcnew System::EventHandler(this, &MyForm::textBox1_Leave);
			// 
			// button_show_reports
			// 
			this->button_show_reports->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button_show_reports->Location = System::Drawing::Point(28, 700);
			this->button_show_reports->Margin = System::Windows::Forms::Padding(7);
			this->button_show_reports->Name = L"button_show_reports";
			this->button_show_reports->Size = System::Drawing::Size(445, 78);
			this->button_show_reports->TabIndex = 55;
			this->button_show_reports->Text = L"Показать отчёты";
			this->button_show_reports->UseVisualStyleBackColor = false;
			this->button_show_reports->Click += gcnew System::EventHandler(this, &MyForm::button_show_reports_Click);
			// 
			// dataGridView2_reports
			// 
			this->dataGridView2_reports->AllowUserToAddRows = false;
			this->dataGridView2_reports->AllowUserToDeleteRows = false;
			this->dataGridView2_reports->AllowUserToResizeColumns = false;
			this->dataGridView2_reports->AllowUserToResizeRows = false;
			this->dataGridView2_reports->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2_reports->BackgroundColor = System::Drawing::Color::Tomato;
			this->dataGridView2_reports->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2_reports->Location = System::Drawing::Point(501, 748);
			this->dataGridView2_reports->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2_reports->Name = L"dataGridView2_reports";
			this->dataGridView2_reports->ReadOnly = true;
			this->dataGridView2_reports->RowHeadersWidth = 92;
			this->dataGridView2_reports->RowTemplate->Height = 37;
			this->dataGridView2_reports->Size = System::Drawing::Size(1469, 435);
			this->dataGridView2_reports->TabIndex = 54;
			this->dataGridView2_reports->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_reports_CellClick);
			// 
			// label_for_reports
			// 
			this->label_for_reports->AutoSize = true;
			this->label_for_reports->Location = System::Drawing::Point(833, 104);
			this->label_for_reports->Name = L"label_for_reports";
			this->label_for_reports->Size = System::Drawing::Size(401, 47);
			this->label_for_reports->TabIndex = 51;
			this->label_for_reports->Text = L"Отображение отчет";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button4->Location = System::Drawing::Point(28, 581);
			this->button4->Margin = System::Windows::Forms::Padding(7);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(445, 105);
			this->button4->TabIndex = 50;
			this->button4->Text = L"Добавить отчёт";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// richTextBox1_for_recommendtaion
			// 
			this->richTextBox1_for_recommendtaion->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBox1_for_recommendtaion->Location = System::Drawing::Point(501, 504);
			this->richTextBox1_for_recommendtaion->Name = L"richTextBox1_for_recommendtaion";
			this->richTextBox1_for_recommendtaion->Size = System::Drawing::Size(1469, 182);
			this->richTextBox1_for_recommendtaion->TabIndex = 46;
			this->richTextBox1_for_recommendtaion->Text = L"";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(99, 504);
			this->label24->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(303, 47);
			this->label24->TabIndex = 45;
			this->label24->Text = L"Рекомендации";
			this->label24->Click += gcnew System::EventHandler(this, &MyForm::label24_Click);
			// 
			// richTextBox1_for_problem
			// 
			this->richTextBox1_for_problem->Location = System::Drawing::Point(501, 204);
			this->richTextBox1_for_problem->Name = L"richTextBox1_for_problem";
			this->richTextBox1_for_problem->Size = System::Drawing::Size(1469, 283);
			this->richTextBox1_for_problem->TabIndex = 44;
			this->richTextBox1_for_problem->Text = L"";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(51, 204);
			this->label23->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(422, 47);
			this->label23->TabIndex = 43;
			this->label23->Text = L"Описание проблемы";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(51, 107);
			this->label22->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(200, 47);
			this->label22->TabIndex = 41;
			this->label22->Text = L"ID заказа";
			// 
			// textBox_order_forreport
			// 
			this->textBox_order_forreport->Location = System::Drawing::Point(417, 101);
			this->textBox_order_forreport->Margin = System::Windows::Forms::Padding(7);
			this->textBox_order_forreport->Name = L"textBox_order_forreport";
			this->textBox_order_forreport->Size = System::Drawing::Size(370, 56);
			this->textBox_order_forreport->TabIndex = 40;
			// 
			// label_23
			// 
			this->label_23->AutoSize = true;
			this->label_23->Location = System::Drawing::Point(170, 36);
			this->label_23->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label_23->Name = L"label_23";
			this->label_23->Size = System::Drawing::Size(414, 47);
			this->label_23->TabIndex = 39;
			this->label_23->Text = L"Составление отчёта";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->button7);
			this->tabPage5->Controls->Add(this->textBox_for_selected_asign);
			this->tabPage5->Controls->Add(this->dataGridView_for_asign);
			this->tabPage5->Controls->Add(this->button_show_all_asign);
			this->tabPage5->Controls->Add(this->label_for_asign);
			this->tabPage5->Controls->Add(this->button_for_making_order);
			this->tabPage5->Controls->Add(this->label25);
			this->tabPage5->Controls->Add(this->label26);
			this->tabPage5->Controls->Add(this->label27);
			this->tabPage5->Controls->Add(this->textBox_order_idemployee);
			this->tabPage5->Controls->Add(this->textBox_order_foridorder);
			this->tabPage5->Location = System::Drawing::Point(10, 65);
			this->tabPage5->Margin = System::Windows::Forms::Padding(2);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(2075, 1199);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Распределение заказов";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(763, 599);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(363, 58);
			this->button7->TabIndex = 56;
			this->button7->Text = L"Удалить связь";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// textBox_for_selected_asign
			// 
			this->textBox_for_selected_asign->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_for_selected_asign->Location = System::Drawing::Point(228, 601);
			this->textBox_for_selected_asign->Name = L"textBox_for_selected_asign";
			this->textBox_for_selected_asign->Size = System::Drawing::Size(417, 56);
			this->textBox_for_selected_asign->TabIndex = 55;
			this->textBox_for_selected_asign->Text = L"Введите ID заказа...";
			this->textBox_for_selected_asign->Enter += gcnew System::EventHandler(this, &MyForm::textBox_for_selected_asign_Enter);
			this->textBox_for_selected_asign->Leave += gcnew System::EventHandler(this, &MyForm::textBox_for_selected_asign_Leave);
			// 
			// dataGridView_for_asign
			// 
			this->dataGridView_for_asign->AllowUserToAddRows = false;
			this->dataGridView_for_asign->AllowUserToDeleteRows = false;
			this->dataGridView_for_asign->AllowUserToResizeColumns = false;
			this->dataGridView_for_asign->AllowUserToResizeRows = false;
			this->dataGridView_for_asign->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView_for_asign->BackgroundColor = System::Drawing::Color::CornflowerBlue;
			this->dataGridView_for_asign->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_for_asign->Location = System::Drawing::Point(116, 732);
			this->dataGridView_for_asign->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_for_asign->Name = L"dataGridView_for_asign";
			this->dataGridView_for_asign->ReadOnly = true;
			this->dataGridView_for_asign->RowHeadersWidth = 92;
			this->dataGridView_for_asign->RowTemplate->Height = 37;
			this->dataGridView_for_asign->Size = System::Drawing::Size(1848, 435);
			this->dataGridView_for_asign->TabIndex = 54;
			this->dataGridView_for_asign->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView_for_asign_CellClick);
			// 
			// button_show_all_asign
			// 
			this->button_show_all_asign->Location = System::Drawing::Point(434, 365);
			this->button_show_all_asign->Name = L"button_show_all_asign";
			this->button_show_all_asign->Size = System::Drawing::Size(396, 73);
			this->button_show_all_asign->TabIndex = 19;
			this->button_show_all_asign->Text = L"Отобразить связи";
			this->button_show_all_asign->UseVisualStyleBackColor = true;
			this->button_show_all_asign->Click += gcnew System::EventHandler(this, &MyForm::button_show_all_asign_Click);
			// 
			// label_for_asign
			// 
			this->label_for_asign->AutoSize = true;
			this->label_for_asign->Location = System::Drawing::Point(492, 500);
			this->label_for_asign->Name = L"label_for_asign";
			this->label_for_asign->Size = System::Drawing::Size(285, 47);
			this->label_for_asign->TabIndex = 18;
			this->label_for_asign->Text = L"Отображение";
			// 
			// button_for_making_order
			// 
			this->button_for_making_order->Location = System::Drawing::Point(434, 286);
			this->button_for_making_order->Name = L"button_for_making_order";
			this->button_for_making_order->Size = System::Drawing::Size(396, 61);
			this->button_for_making_order->TabIndex = 17;
			this->button_for_making_order->Text = L"Выдать заказ";
			this->button_for_making_order->UseVisualStyleBackColor = true;
			this->button_for_making_order->Click += gcnew System::EventHandler(this, &MyForm::button_for_making_order_Click);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(220, 50);
			this->label25->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(410, 47);
			this->label25->TabIndex = 16;
			this->label25->Text = L"Распределить заказ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(149, 201);
			this->label26->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(200, 47);
			this->label26->TabIndex = 15;
			this->label26->Text = L"ID заказа";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(108, 117);
			this->label27->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(277, 47);
			this->label27->TabIndex = 14;
			this->label27->Text = L"ID Работника";
			// 
			// textBox_order_idemployee
			// 
			this->textBox_order_idemployee->Location = System::Drawing::Point(434, 114);
			this->textBox_order_idemployee->Margin = System::Windows::Forms::Padding(7);
			this->textBox_order_idemployee->Name = L"textBox_order_idemployee";
			this->textBox_order_idemployee->Size = System::Drawing::Size(396, 56);
			this->textBox_order_idemployee->TabIndex = 12;
			// 
			// textBox_order_foridorder
			// 
			this->textBox_order_foridorder->Location = System::Drawing::Point(434, 192);
			this->textBox_order_foridorder->Margin = System::Windows::Forms::Padding(7);
			this->textBox_order_foridorder->Name = L"textBox_order_foridorder";
			this->textBox_order_foridorder->Size = System::Drawing::Size(396, 56);
			this->textBox_order_foridorder->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(216, 216);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(2095, 1274);
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
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_Orders))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_reports))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_for_asign))->EndInit();
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



private: System::Void tabPage3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	add_order();
}
private: System::Void button_add_device_Click(System::Object^ sender, System::EventArgs^ e) {
	add_device();
}
private: System::Void button_show_orders_Click(System::Object^ sender, System::EventArgs^ e) {
	show_all_orders();
}
private: System::String^ placeholderText = "Введите ID заказа..."; 
private: System::Void textBox_forOrder_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_forOrder->Text == placeholderText || textBox_forOrder->Text == "Error") {
		textBox_forOrder->Text = "";
		textBox_forOrder->ForeColor = System::Drawing::Color::Black; 
	}

}
private: System::Void textBox_forOrder_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_forOrder->Text->Length == 0) {
		textBox_forOrder->Text = placeholderText;
		textBox_forOrder->ForeColor = System::Drawing::Color::LightGray; 
		return;
	}
	change_combobox();
}

	  
private: System::Void button_selected_order_Click(System::Object^ sender, System::EventArgs^ e) {
	selected_order();
}
private: System::Void comboBox1_Status_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	combobox_selected_event();
}
private: System::Void dataGridView2_Orders_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	


private: System::Void button_delete_order_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void tabPage4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label24_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_show_reports_Click(System::Object^ sender, System::EventArgs^ e);
	   private: System::String^ placeholderText_for_report = "Введите ID отчёта...";
private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e); 
private: System::Void dataGridView2_reports_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_for_making_order_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_show_all_asign_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::String^ placeholderText_for_asign = "Введите ID заказа...";
private: System::Void textBox_for_selected_asign_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_for_selected_asign_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView_for_asign_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
};




}
