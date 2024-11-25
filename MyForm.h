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
	using namespace System::Windows::Forms::DataVisualization::Charting;

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
	private: System::Windows::Forms::TabPage^ tabPage6;

	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::TabPage^ tabPage8;



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


private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
private: System::Windows::Forms::Label^ label_department_delete;



private: System::Windows::Forms::Button^ button_to_delete_department;

private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::TextBox^ textBox_for_deleting_Department;

private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Button^ button_show_all_departmnents;
private: System::Windows::Forms::DataGridView^ dataGridView_Departments;
private: System::Windows::Forms::Label^ label_department_add;



private: System::Windows::Forms::Button^ button_add_department;

private: System::Windows::Forms::Label^ label34;

private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::TextBox^ textbox_foraddDepartment;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::TextBox^ textBox_for_id_department_employee;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::TextBox^ textBox_manager_ID_department;
private: System::Windows::Forms::Label^ label_manager_delete;
private: System::Windows::Forms::Button^ button_manager_delete;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::TextBox^ textBox_manager_delete;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Button^ button_show_allmanagers;
private: System::Windows::Forms::DataGridView^ dataGridView_managers;
private: System::Windows::Forms::Label^ label_managers_add;
private: System::Windows::Forms::Button^ button_add_manager;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::TextBox^ textBox_manager_name;
private: System::Windows::Forms::TextBox^ textBox_manager_phone;


private: System::ComponentModel::IContainer^ components;








	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


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
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->label_department_delete = (gcnew System::Windows::Forms::Label());
			this->button_to_delete_department = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->textBox_for_deleting_Department = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button_show_all_departmnents = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Departments = (gcnew System::Windows::Forms::DataGridView());
			this->label_department_add = (gcnew System::Windows::Forms::Label());
			this->button_add_department = (gcnew System::Windows::Forms::Button());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textbox_foraddDepartment = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox_for_id_department_employee = (gcnew System::Windows::Forms::TextBox());
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
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox_manager_ID_department = (gcnew System::Windows::Forms::TextBox());
			this->label_manager_delete = (gcnew System::Windows::Forms::Label());
			this->button_manager_delete = (gcnew System::Windows::Forms::Button());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox_manager_delete = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->button_show_allmanagers = (gcnew System::Windows::Forms::Button());
			this->dataGridView_managers = (gcnew System::Windows::Forms::DataGridView());
			this->label_managers_add = (gcnew System::Windows::Forms::Label());
			this->button_add_manager = (gcnew System::Windows::Forms::Button());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->textBox_manager_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_manager_phone = (gcnew System::Windows::Forms::TextBox());
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
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Departments))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_Orders))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_managers))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_for_asign))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Arial", 14));
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(931, 566);
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
			this->tabPage1->Location = System::Drawing::Point(4, 31);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(923, 531);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Клиенты";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(690, 180);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(132, 22);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Отображение";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(678, 101);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(181, 32);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Удалить клиента";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(597, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 22);
			this->label6->TabIndex = 17;
			this->label6->Text = L"ID клиента";
			// 
			// ClientID
			// 
			this->ClientID->Location = System::Drawing::Point(729, 43);
			this->ClientID->Name = L"ClientID";
			this->ClientID->Size = System::Drawing::Size(167, 29);
			this->ClientID->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(674, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 22);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Удаление клиента";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(74, 142);
			this->button2->Margin = System::Windows::Forms::Padding(1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(216, 33);
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
			this->dataGridView1->Location = System::Drawing::Point(74, 269);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 92;
			this->dataGridView1->RowTemplate->Height = 37;
			this->dataGridView1->Size = System::Drawing::Size(786, 245);
			this->dataGridView1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 22);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Отображение";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(74, 101);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(216, 32);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Добавить клиента";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(89, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 22);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Добавление клиента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 22);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Телефон клиента";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 22);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Имя клиента";
			// 
			// ClientNameBox
			// 
			this->ClientNameBox->Location = System::Drawing::Point(184, 32);
			this->ClientNameBox->Name = L"ClientNameBox";
			this->ClientNameBox->Size = System::Drawing::Size(167, 29);
			this->ClientNameBox->TabIndex = 6;
			this->ClientNameBox->Text = L" ";
			// 
			// ClientPhoneBox
			// 
			this->ClientPhoneBox->Location = System::Drawing::Point(184, 66);
			this->ClientPhoneBox->Name = L"ClientPhoneBox";
			this->ClientPhoneBox->Size = System::Drawing::Size(167, 29);
			this->ClientPhoneBox->TabIndex = 7;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->label_department_delete);
			this->tabPage7->Controls->Add(this->button_to_delete_department);
			this->tabPage7->Controls->Add(this->label31);
			this->tabPage7->Controls->Add(this->textBox_for_deleting_Department);
			this->tabPage7->Controls->Add(this->label32);
			this->tabPage7->Controls->Add(this->button_show_all_departmnents);
			this->tabPage7->Controls->Add(this->dataGridView_Departments);
			this->tabPage7->Controls->Add(this->label_department_add);
			this->tabPage7->Controls->Add(this->button_add_department);
			this->tabPage7->Controls->Add(this->label34);
			this->tabPage7->Controls->Add(this->label36);
			this->tabPage7->Controls->Add(this->textbox_foraddDepartment);
			this->tabPage7->Location = System::Drawing::Point(4, 31);
			this->tabPage7->Margin = System::Windows::Forms::Padding(1);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Size = System::Drawing::Size(923, 531);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Отделы";
			// 
			// label_department_delete
			// 
			this->label_department_delete->AutoSize = true;
			this->label_department_delete->Location = System::Drawing::Point(696, 169);
			this->label_department_delete->Name = L"label_department_delete";
			this->label_department_delete->Size = System::Drawing::Size(148, 22);
			this->label_department_delete->TabIndex = 49;
			this->label_department_delete->Text = L"Отображение р";
			// 
			// button_to_delete_department
			// 
			this->button_to_delete_department->Location = System::Drawing::Point(690, 90);
			this->button_to_delete_department->Name = L"button_to_delete_department";
			this->button_to_delete_department->Size = System::Drawing::Size(181, 32);
			this->button_to_delete_department->TabIndex = 48;
			this->button_to_delete_department->Text = L"Удалить работника";
			this->button_to_delete_department->UseVisualStyleBackColor = true;
			this->button_to_delete_department->Click += gcnew System::EventHandler(this, &MyForm::button_to_delete_department_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(609, 56);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(94, 22);
			this->label31->TabIndex = 47;
			this->label31->Text = L"ID отдела";
			// 
			// textBox_for_deleting_Department
			// 
			this->textBox_for_deleting_Department->Location = System::Drawing::Point(741, 54);
			this->textBox_for_deleting_Department->Name = L"textBox_for_deleting_Department";
			this->textBox_for_deleting_Department->Size = System::Drawing::Size(167, 29);
			this->textBox_for_deleting_Department->TabIndex = 46;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(686, 15);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(158, 22);
			this->label32->TabIndex = 45;
			this->label32->Text = L"Удаление отдела";
			// 
			// button_show_all_departmnents
			// 
			this->button_show_all_departmnents->Location = System::Drawing::Point(91, 131);
			this->button_show_all_departmnents->Margin = System::Windows::Forms::Padding(1);
			this->button_show_all_departmnents->Name = L"button_show_all_departmnents";
			this->button_show_all_departmnents->Size = System::Drawing::Size(237, 33);
			this->button_show_all_departmnents->TabIndex = 44;
			this->button_show_all_departmnents->Text = L"Вывести все отделы";
			this->button_show_all_departmnents->UseVisualStyleBackColor = true;
			this->button_show_all_departmnents->Click += gcnew System::EventHandler(this, &MyForm::button_show_all_departmnents_Click);
			// 
			// dataGridView_Departments
			// 
			this->dataGridView_Departments->AllowUserToAddRows = false;
			this->dataGridView_Departments->AllowUserToDeleteRows = false;
			this->dataGridView_Departments->AllowUserToResizeColumns = false;
			this->dataGridView_Departments->AllowUserToResizeRows = false;
			this->dataGridView_Departments->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView_Departments->BackgroundColor = System::Drawing::Color::Bisque;
			this->dataGridView_Departments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Departments->Location = System::Drawing::Point(60, 335);
			this->dataGridView_Departments->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView_Departments->Name = L"dataGridView_Departments";
			this->dataGridView_Departments->ReadOnly = true;
			this->dataGridView_Departments->RowHeadersWidth = 92;
			this->dataGridView_Departments->RowTemplate->Height = 37;
			this->dataGridView_Departments->Size = System::Drawing::Size(821, 180);
			this->dataGridView_Departments->TabIndex = 36;
			// 
			// label_department_add
			// 
			this->label_department_add->AutoSize = true;
			this->label_department_add->Location = System::Drawing::Point(20, 169);
			this->label_department_add->Name = L"label_department_add";
			this->label_department_add->Size = System::Drawing::Size(148, 22);
			this->label_department_add->TabIndex = 43;
			this->label_department_add->Text = L"Отображение р";
			// 
			// button_add_department
			// 
			this->button_add_department->Location = System::Drawing::Point(91, 90);
			this->button_add_department->Name = L"button_add_department";
			this->button_add_department->Size = System::Drawing::Size(237, 32);
			this->button_add_department->TabIndex = 42;
			this->button_add_department->Text = L"Добавить отдел";
			this->button_add_department->UseVisualStyleBackColor = true;
			this->button_add_department->Click += gcnew System::EventHandler(this, &MyForm::button_add_department_Click);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(107, 15);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(181, 22);
			this->label34->TabIndex = 41;
			this->label34->Text = L"Добавление отдела";
			this->label34->Click += gcnew System::EventHandler(this, &MyForm::label34_Click);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(36, 44);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(157, 22);
			this->label36->TabIndex = 39;
			this->label36->Text = L"Название отдела";
			// 
			// textbox_foraddDepartment
			// 
			this->textbox_foraddDepartment->Location = System::Drawing::Point(208, 44);
			this->textbox_foraddDepartment->Name = L"textbox_foraddDepartment";
			this->textbox_foraddDepartment->Size = System::Drawing::Size(167, 29);
			this->textbox_foraddDepartment->TabIndex = 37;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label29);
			this->tabPage2->Controls->Add(this->textBox_for_id_department_employee);
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
			this->tabPage2->Location = System::Drawing::Point(4, 31);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(923, 531);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Работники";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(44, 140);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(98, 22);
			this->label29->TabIndex = 37;
			this->label29->Text = L"ID Отдела";
			// 
			// textBox_for_id_department_employee
			// 
			this->textBox_for_id_department_employee->Location = System::Drawing::Point(197, 140);
			this->textBox_for_id_department_employee->Name = L"textBox_for_id_department_employee";
			this->textBox_for_id_department_employee->Size = System::Drawing::Size(167, 29);
			this->textBox_for_id_department_employee->TabIndex = 36;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(44, 103);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(108, 22);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Должность";
			// 
			// Employee_Post_Box
			// 
			this->Employee_Post_Box->Location = System::Drawing::Point(197, 103);
			this->Employee_Post_Box->Name = L"Employee_Post_Box";
			this->Employee_Post_Box->Size = System::Drawing::Size(167, 29);
			this->Employee_Post_Box->TabIndex = 34;
			// 
			// label_del_employee
			// 
			this->label_del_employee->AutoSize = true;
			this->label_del_employee->Location = System::Drawing::Point(690, 214);
			this->label_del_employee->Name = L"label_del_employee";
			this->label_del_employee->Size = System::Drawing::Size(148, 22);
			this->label_del_employee->TabIndex = 33;
			this->label_del_employee->Text = L"Отображение р";
			// 
			// button_delete_employee
			// 
			this->button_delete_employee->Location = System::Drawing::Point(678, 135);
			this->button_delete_employee->Name = L"button_delete_employee";
			this->button_delete_employee->Size = System::Drawing::Size(181, 32);
			this->button_delete_employee->TabIndex = 32;
			this->button_delete_employee->Text = L"Удалить работника";
			this->button_delete_employee->UseVisualStyleBackColor = true;
			this->button_delete_employee->Click += gcnew System::EventHandler(this, &MyForm::button_delete_employee_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(598, 46);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(124, 22);
			this->label9->TabIndex = 31;
			this->label9->Text = L"ID работника";
			// 
			// Employee_ID_Box
			// 
			this->Employee_ID_Box->Location = System::Drawing::Point(730, 44);
			this->Employee_ID_Box->Name = L"Employee_ID_Box";
			this->Employee_ID_Box->Size = System::Drawing::Size(167, 29);
			this->Employee_ID_Box->TabIndex = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(675, 5);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(188, 22);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Удаление работника";
			// 
			// button_showall_employee
			// 
			this->button_showall_employee->Location = System::Drawing::Point(70, 213);
			this->button_showall_employee->Margin = System::Windows::Forms::Padding(1);
			this->button_showall_employee->Name = L"button_showall_employee";
			this->button_showall_employee->Size = System::Drawing::Size(237, 33);
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
			this->dataGridView2_employee->Location = System::Drawing::Point(49, 325);
			this->dataGridView2_employee->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView2_employee->Name = L"dataGridView2_employee";
			this->dataGridView2_employee->ReadOnly = true;
			this->dataGridView2_employee->RowHeadersWidth = 92;
			this->dataGridView2_employee->RowTemplate->Height = 37;
			this->dataGridView2_employee->Size = System::Drawing::Size(821, 180);
			this->dataGridView2_employee->TabIndex = 20;
			// 
			// label_add_employee
			// 
			this->label_add_employee->AutoSize = true;
			this->label_add_employee->Location = System::Drawing::Point(-1, 251);
			this->label_add_employee->Name = L"label_add_employee";
			this->label_add_employee->Size = System::Drawing::Size(148, 22);
			this->label_add_employee->TabIndex = 27;
			this->label_add_employee->Text = L"Отображение р";
			// 
			// button_add_employee
			// 
			this->button_add_employee->Location = System::Drawing::Point(70, 172);
			this->button_add_employee->Name = L"button_add_employee";
			this->button_add_employee->Size = System::Drawing::Size(237, 32);
			this->button_add_employee->TabIndex = 26;
			this->button_add_employee->Text = L"Добавить работника";
			this->button_add_employee->UseVisualStyleBackColor = true;
			this->button_add_employee->Click += gcnew System::EventHandler(this, &MyForm::button_add_employee_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(96, 5);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(211, 22);
			this->label12->TabIndex = 25;
			this->label12->Text = L"Добавление работника";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 68);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(183, 22);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Телефон работника";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(25, 34);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(141, 22);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Имя работника";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// Employee_name_Box
			// 
			this->Employee_name_Box->Location = System::Drawing::Point(197, 34);
			this->Employee_name_Box->Name = L"Employee_name_Box";
			this->Employee_name_Box->Size = System::Drawing::Size(167, 29);
			this->Employee_name_Box->TabIndex = 21;
			// 
			// Employee_phone_Box
			// 
			this->Employee_phone_Box->Location = System::Drawing::Point(197, 68);
			this->Employee_phone_Box->Name = L"Employee_phone_Box";
			this->Employee_phone_Box->Size = System::Drawing::Size(167, 29);
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
			this->tabPage3->Location = System::Drawing::Point(4, 31);
			this->tabPage3->Margin = System::Windows::Forms::Padding(1);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(923, 531);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Заказы";
			this->tabPage3->Click += gcnew System::EventHandler(this, &MyForm::tabPage3_Click);
			// 
			// button_delete_order
			// 
			this->button_delete_order->Location = System::Drawing::Point(298, 280);
			this->button_delete_order->Name = L"button_delete_order";
			this->button_delete_order->Size = System::Drawing::Size(184, 30);
			this->button_delete_order->TabIndex = 57;
			this->button_delete_order->Text = L"Удалить заказ";
			this->button_delete_order->UseVisualStyleBackColor = true;
			this->button_delete_order->Click += gcnew System::EventHandler(this, &MyForm::button_delete_order_Click);
			// 
			// button_selected_order
			// 
			this->button_selected_order->Location = System::Drawing::Point(298, 244);
			this->button_selected_order->Name = L"button_selected_order";
			this->button_selected_order->Size = System::Drawing::Size(184, 30);
			this->button_selected_order->TabIndex = 56;
			this->button_selected_order->Text = L"Отобразить заказ";
			this->button_selected_order->UseVisualStyleBackColor = true;
			this->button_selected_order->Click += gcnew System::EventHandler(this, &MyForm::button_selected_order_Click);
			// 
			// textBox_forOrder
			// 
			this->textBox_forOrder->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_forOrder->Location = System::Drawing::Point(65, 245);
			this->textBox_forOrder->Name = L"textBox_forOrder";
			this->textBox_forOrder->Size = System::Drawing::Size(196, 29);
			this->textBox_forOrder->TabIndex = 55;
			this->textBox_forOrder->Text = L"Введите ID заказа...";
			this->textBox_forOrder->Enter += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Enter);
			this->textBox_forOrder->Leave += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Leave);
			// 
			// button_show_orders
			// 
			this->button_show_orders->Location = System::Drawing::Point(86, 150);
			this->button_show_orders->Name = L"button_show_orders";
			this->button_show_orders->Size = System::Drawing::Size(184, 30);
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
			this->dataGridView2_Orders->Location = System::Drawing::Point(65, 332);
			this->dataGridView2_Orders->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView2_Orders->Name = L"dataGridView2_Orders";
			this->dataGridView2_Orders->ReadOnly = true;
			this->dataGridView2_Orders->RowHeadersWidth = 92;
			this->dataGridView2_Orders->RowTemplate->Height = 37;
			this->dataGridView2_Orders->Size = System::Drawing::Size(821, 193);
			this->dataGridView2_Orders->TabIndex = 53;
			this->dataGridView2_Orders->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_Orders_CellClick);
			// 
			// label_add_device
			// 
			this->label_add_device->AutoSize = true;
			this->label_add_device->Location = System::Drawing::Point(636, 188);
			this->label_add_device->Name = L"label_add_device";
			this->label_add_device->Size = System::Drawing::Size(193, 22);
			this->label_add_device->TabIndex = 52;
			this->label_add_device->Text = L"Отображение заказа";
			// 
			// button_add_device
			// 
			this->button_add_device->Location = System::Drawing::Point(678, 146);
			this->button_add_device->Name = L"button_add_device";
			this->button_add_device->Size = System::Drawing::Size(214, 30);
			this->button_add_device->TabIndex = 51;
			this->button_add_device->Text = L"Добавить устройство";
			this->button_add_device->UseVisualStyleBackColor = true;
			this->button_add_device->Click += gcnew System::EventHandler(this, &MyForm::button_add_device_Click);
			// 
			// Order_Label
			// 
			this->Order_Label->AutoSize = true;
			this->Order_Label->Location = System::Drawing::Point(82, 188);
			this->Order_Label->Name = L"Order_Label";
			this->Order_Label->Size = System::Drawing::Size(193, 22);
			this->Order_Label->TabIndex = 50;
			this->Order_Label->Text = L"Отображение заказа";
			// 
			// button_add_order
			// 
			this->button_add_order->Location = System::Drawing::Point(86, 114);
			this->button_add_order->Name = L"button_add_order";
			this->button_add_order->Size = System::Drawing::Size(184, 30);
			this->button_add_order->TabIndex = 49;
			this->button_add_order->Text = L"Добавить заказ";
			this->button_add_order->UseVisualStyleBackColor = true;
			this->button_add_order->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(533, 114);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(145, 22);
			this->label21->TabIndex = 48;
			this->label21->Text = L"Производитель";
			// 
			// Brand_Box
			// 
			this->Brand_Box->Location = System::Drawing::Point(696, 111);
			this->Brand_Box->Name = L"Brand_Box";
			this->Brand_Box->Size = System::Drawing::Size(167, 29);
			this->Brand_Box->TabIndex = 47;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(533, 78);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(142, 22);
			this->label20->TabIndex = 46;
			this->label20->Text = L"Тип устройства";
			// 
			// DeviceType_Box
			// 
			this->DeviceType_Box->Location = System::Drawing::Point(696, 76);
			this->DeviceType_Box->Name = L"DeviceType_Box";
			this->DeviceType_Box->Size = System::Drawing::Size(167, 29);
			this->DeviceType_Box->TabIndex = 45;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(533, 44);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(91, 22);
			this->label19->TabIndex = 44;
			this->label19->Text = L"ID заказа";
			// 
			// ID_Order_Box
			// 
			this->ID_Order_Box->Location = System::Drawing::Point(696, 40);
			this->ID_Order_Box->Name = L"ID_Order_Box";
			this->ID_Order_Box->Size = System::Drawing::Size(167, 29);
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
			this->comboBox1_Status->Location = System::Drawing::Point(696, 244);
			this->comboBox1_Status->Margin = System::Windows::Forms::Padding(1);
			this->comboBox1_Status->Name = L"comboBox1_Status";
			this->comboBox1_Status->Size = System::Drawing::Size(167, 30);
			this->comboBox1_Status->TabIndex = 42;
			this->comboBox1_Status->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_Status_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(61, 81);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(55, 22);
			this->label16->TabIndex = 41;
			this->label16->Text = L"Цена";
			// 
			// Price_Box
			// 
			this->Price_Box->Location = System::Drawing::Point(202, 78);
			this->Price_Box->Name = L"Price_Box";
			this->Price_Box->Size = System::Drawing::Size(167, 29);
			this->Price_Box->TabIndex = 40;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(524, 247);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(130, 22);
			this->label17->TabIndex = 39;
			this->label17->Text = L"Статус заказа";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(40, 40);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(102, 22);
			this->label18->TabIndex = 38;
			this->label18->Text = L"ID клиента";
			// 
			// ID_Client_Box
			// 
			this->ID_Client_Box->Location = System::Drawing::Point(202, 38);
			this->ID_Client_Box->Name = L"ID_Client_Box";
			this->ID_Client_Box->Size = System::Drawing::Size(167, 29);
			this->ID_Client_Box->TabIndex = 36;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(677, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(207, 22);
			this->label8->TabIndex = 31;
			this->label8->Text = L"Устройство для заказа";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(92, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(186, 22);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Составление заказа";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->textBox_manager_ID_department);
			this->tabPage4->Controls->Add(this->label_manager_delete);
			this->tabPage4->Controls->Add(this->button_manager_delete);
			this->tabPage4->Controls->Add(this->label28);
			this->tabPage4->Controls->Add(this->textBox_manager_delete);
			this->tabPage4->Controls->Add(this->label30);
			this->tabPage4->Controls->Add(this->button_show_allmanagers);
			this->tabPage4->Controls->Add(this->dataGridView_managers);
			this->tabPage4->Controls->Add(this->label_managers_add);
			this->tabPage4->Controls->Add(this->button_add_manager);
			this->tabPage4->Controls->Add(this->label35);
			this->tabPage4->Controls->Add(this->label37);
			this->tabPage4->Controls->Add(this->label38);
			this->tabPage4->Controls->Add(this->textBox_manager_name);
			this->tabPage4->Controls->Add(this->textBox_manager_phone);
			this->tabPage4->Location = System::Drawing::Point(4, 31);
			this->tabPage4->Margin = System::Windows::Forms::Padding(1);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(923, 531);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Менеджеры";
			this->tabPage4->Click += gcnew System::EventHandler(this, &MyForm::tabPage4_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(57, 113);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(98, 22);
			this->label22->TabIndex = 55;
			this->label22->Text = L"ID Отдела";
			// 
			// textBox_manager_ID_department
			// 
			this->textBox_manager_ID_department->Location = System::Drawing::Point(210, 113);
			this->textBox_manager_ID_department->Name = L"textBox_manager_ID_department";
			this->textBox_manager_ID_department->Size = System::Drawing::Size(167, 29);
			this->textBox_manager_ID_department->TabIndex = 54;
			// 
			// label_manager_delete
			// 
			this->label_manager_delete->AutoSize = true;
			this->label_manager_delete->Location = System::Drawing::Point(703, 187);
			this->label_manager_delete->Name = L"label_manager_delete";
			this->label_manager_delete->Size = System::Drawing::Size(148, 22);
			this->label_manager_delete->TabIndex = 51;
			this->label_manager_delete->Text = L"Отображение р";
			// 
			// button_manager_delete
			// 
			this->button_manager_delete->Location = System::Drawing::Point(691, 108);
			this->button_manager_delete->Name = L"button_manager_delete";
			this->button_manager_delete->Size = System::Drawing::Size(181, 32);
			this->button_manager_delete->TabIndex = 50;
			this->button_manager_delete->Text = L"Удалить работника";
			this->button_manager_delete->UseVisualStyleBackColor = true;
			this->button_manager_delete->Click += gcnew System::EventHandler(this, &MyForm::button_manager_delete_Click);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(600, 57);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(137, 22);
			this->label28->TabIndex = 49;
			this->label28->Text = L"ID менеджера";
			// 
			// textBox_manager_delete
			// 
			this->textBox_manager_delete->Location = System::Drawing::Point(743, 54);
			this->textBox_manager_delete->Name = L"textBox_manager_delete";
			this->textBox_manager_delete->Size = System::Drawing::Size(167, 29);
			this->textBox_manager_delete->TabIndex = 48;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(688, 15);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(201, 22);
			this->label30->TabIndex = 47;
			this->label30->Text = L"Удаление менеджера";
			// 
			// button_show_allmanagers
			// 
			this->button_show_allmanagers->Location = System::Drawing::Point(83, 186);
			this->button_show_allmanagers->Margin = System::Windows::Forms::Padding(1);
			this->button_show_allmanagers->Name = L"button_show_allmanagers";
			this->button_show_allmanagers->Size = System::Drawing::Size(260, 33);
			this->button_show_allmanagers->TabIndex = 46;
			this->button_show_allmanagers->Text = L"Вывести всех менеджеров";
			this->button_show_allmanagers->UseVisualStyleBackColor = true;
			this->button_show_allmanagers->Click += gcnew System::EventHandler(this, &MyForm::button_show_allmanagers_Click);
			// 
			// dataGridView_managers
			// 
			this->dataGridView_managers->AllowUserToAddRows = false;
			this->dataGridView_managers->AllowUserToDeleteRows = false;
			this->dataGridView_managers->AllowUserToResizeColumns = false;
			this->dataGridView_managers->AllowUserToResizeRows = false;
			this->dataGridView_managers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView_managers->BackgroundColor = System::Drawing::Color::Gold;
			this->dataGridView_managers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_managers->Location = System::Drawing::Point(62, 335);
			this->dataGridView_managers->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView_managers->Name = L"dataGridView_managers";
			this->dataGridView_managers->ReadOnly = true;
			this->dataGridView_managers->RowHeadersWidth = 92;
			this->dataGridView_managers->RowTemplate->Height = 37;
			this->dataGridView_managers->Size = System::Drawing::Size(821, 180);
			this->dataGridView_managers->TabIndex = 38;
			// 
			// label_managers_add
			// 
			this->label_managers_add->AutoSize = true;
			this->label_managers_add->Location = System::Drawing::Point(12, 261);
			this->label_managers_add->Name = L"label_managers_add";
			this->label_managers_add->Size = System::Drawing::Size(148, 22);
			this->label_managers_add->TabIndex = 45;
			this->label_managers_add->Text = L"Отображение р";
			// 
			// button_add_manager
			// 
			this->button_add_manager->Location = System::Drawing::Point(83, 145);
			this->button_add_manager->Name = L"button_add_manager";
			this->button_add_manager->Size = System::Drawing::Size(260, 32);
			this->button_add_manager->TabIndex = 44;
			this->button_add_manager->Text = L"Добавить менеджера";
			this->button_add_manager->UseVisualStyleBackColor = true;
			this->button_add_manager->Click += gcnew System::EventHandler(this, &MyForm::button_add_manager_Click);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(109, 15);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(224, 22);
			this->label35->TabIndex = 43;
			this->label35->Text = L"Добавление менеджера";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(8, 78);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(196, 22);
			this->label37->TabIndex = 42;
			this->label37->Text = L"Телефон менеджера";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(38, 44);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(154, 22);
			this->label38->TabIndex = 41;
			this->label38->Text = L"Имя менеджера";
			// 
			// textBox_manager_name
			// 
			this->textBox_manager_name->Location = System::Drawing::Point(210, 44);
			this->textBox_manager_name->Name = L"textBox_manager_name";
			this->textBox_manager_name->Size = System::Drawing::Size(167, 29);
			this->textBox_manager_name->TabIndex = 39;
			// 
			// textBox_manager_phone
			// 
			this->textBox_manager_phone->Location = System::Drawing::Point(210, 78);
			this->textBox_manager_phone->Name = L"textBox_manager_phone";
			this->textBox_manager_phone->Size = System::Drawing::Size(167, 29);
			this->textBox_manager_phone->TabIndex = 40;
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
			this->tabPage5->Location = System::Drawing::Point(4, 31);
			this->tabPage5->Margin = System::Windows::Forms::Padding(1);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(923, 531);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Распределение заказов";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(339, 266);
			this->button7->Margin = System::Windows::Forms::Padding(1);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(161, 26);
			this->button7->TabIndex = 56;
			this->button7->Text = L"Удалить связь";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// textBox_for_selected_asign
			// 
			this->textBox_for_selected_asign->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_for_selected_asign->Location = System::Drawing::Point(101, 267);
			this->textBox_for_selected_asign->Margin = System::Windows::Forms::Padding(1);
			this->textBox_for_selected_asign->Name = L"textBox_for_selected_asign";
			this->textBox_for_selected_asign->Size = System::Drawing::Size(188, 29);
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
			this->dataGridView_for_asign->Location = System::Drawing::Point(52, 325);
			this->dataGridView_for_asign->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView_for_asign->Name = L"dataGridView_for_asign";
			this->dataGridView_for_asign->ReadOnly = true;
			this->dataGridView_for_asign->RowHeadersWidth = 92;
			this->dataGridView_for_asign->RowTemplate->Height = 37;
			this->dataGridView_for_asign->Size = System::Drawing::Size(821, 193);
			this->dataGridView_for_asign->TabIndex = 54;
			this->dataGridView_for_asign->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView_for_asign_CellClick);
			// 
			// button_show_all_asign
			// 
			this->button_show_all_asign->Location = System::Drawing::Point(193, 162);
			this->button_show_all_asign->Margin = System::Windows::Forms::Padding(1);
			this->button_show_all_asign->Name = L"button_show_all_asign";
			this->button_show_all_asign->Size = System::Drawing::Size(176, 32);
			this->button_show_all_asign->TabIndex = 19;
			this->button_show_all_asign->Text = L"Отобразить связи";
			this->button_show_all_asign->UseVisualStyleBackColor = true;
			this->button_show_all_asign->Click += gcnew System::EventHandler(this, &MyForm::button_show_all_asign_Click);
			// 
			// label_for_asign
			// 
			this->label_for_asign->AutoSize = true;
			this->label_for_asign->Location = System::Drawing::Point(219, 222);
			this->label_for_asign->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label_for_asign->Name = L"label_for_asign";
			this->label_for_asign->Size = System::Drawing::Size(132, 22);
			this->label_for_asign->TabIndex = 18;
			this->label_for_asign->Text = L"Отображение";
			// 
			// button_for_making_order
			// 
			this->button_for_making_order->Location = System::Drawing::Point(193, 127);
			this->button_for_making_order->Margin = System::Windows::Forms::Padding(1);
			this->button_for_making_order->Name = L"button_for_making_order";
			this->button_for_making_order->Size = System::Drawing::Size(176, 27);
			this->button_for_making_order->TabIndex = 17;
			this->button_for_making_order->Text = L"Выдать заказ";
			this->button_for_making_order->UseVisualStyleBackColor = true;
			this->button_for_making_order->Click += gcnew System::EventHandler(this, &MyForm::button_for_making_order_Click);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(98, 22);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(184, 22);
			this->label25->TabIndex = 16;
			this->label25->Text = L"Распределить заказ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(66, 89);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(91, 22);
			this->label26->TabIndex = 15;
			this->label26->Text = L"ID заказа";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(48, 52);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(125, 22);
			this->label27->TabIndex = 14;
			this->label27->Text = L"ID Работника";
			// 
			// textBox_order_idemployee
			// 
			this->textBox_order_idemployee->Location = System::Drawing::Point(193, 51);
			this->textBox_order_idemployee->Name = L"textBox_order_idemployee";
			this->textBox_order_idemployee->Size = System::Drawing::Size(178, 29);
			this->textBox_order_idemployee->TabIndex = 12;
			// 
			// textBox_order_foridorder
			// 
			this->textBox_order_foridorder->Location = System::Drawing::Point(193, 85);
			this->textBox_order_foridorder->Name = L"textBox_order_foridorder";
			this->textBox_order_foridorder->Size = System::Drawing::Size(178, 29);
			this->textBox_order_foridorder->TabIndex = 13;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->chart1);
			this->tabPage6->Controls->Add(this->button8);
			this->tabPage6->Location = System::Drawing::Point(4, 31);
			this->tabPage6->Margin = System::Windows::Forms::Padding(1);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(923, 531);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Статистика";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(217, 88);
			this->chart1->Margin = System::Windows::Forms::Padding(1);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(535, 281);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(303, 20);
			this->button8->Margin = System::Windows::Forms::Padding(1);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(348, 29);
			this->button8->TabIndex = 0;
			this->button8->Text = L"Отобразить диаграмму категорий";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(931, 566);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Departments))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_Orders))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_managers))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_for_asign))->EndInit();
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
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

	   private: System::String^ placeholderText_for_report = "Введите ID отчёта...";


private: System::Void button_for_making_order_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_show_all_asign_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::String^ placeholderText_for_asign = "Введите ID заказа...";
private: System::Void textBox_for_selected_asign_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_for_selected_asign_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView_for_asign_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_order_forreport_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void label34_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_add_department_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_show_all_departmnents_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_to_delete_department_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_manager_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_show_allmanagers_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_manager_delete_Click(System::Object^ sender, System::EventArgs^ e);
};




}
