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
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_employee))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2_Orders))->BeginInit();
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
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(898, 571);
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
			this->tabPage1->Size = System::Drawing::Size(890, 536);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Клиенты";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(665, 182);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(132, 22);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Отображение";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(654, 102);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(175, 32);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Удалить клиента";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(576, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 22);
			this->label6->TabIndex = 17;
			this->label6->Text = L"ID клиента";
			// 
			// ClientID
			// 
			this->ClientID->Location = System::Drawing::Point(703, 43);
			this->ClientID->Name = L"ClientID";
			this->ClientID->Size = System::Drawing::Size(161, 29);
			this->ClientID->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(650, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 22);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Удаление клиента";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(71, 143);
			this->button2->Margin = System::Windows::Forms::Padding(1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(208, 33);
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
			this->dataGridView1->Location = System::Drawing::Point(71, 271);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 92;
			this->dataGridView1->RowTemplate->Height = 37;
			this->dataGridView1->Size = System::Drawing::Size(758, 247);
			this->dataGridView1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 22);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Отображение";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 102);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 32);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Добавить клиента";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 22);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Добавление клиента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 22);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Телефон клиента";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 33);
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
			this->tabPage2->Size = System::Drawing::Size(890, 536);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Работники";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(43, 104);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(108, 22);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Должность";
			// 
			// Employee_Post_Box
			// 
			this->Employee_Post_Box->Location = System::Drawing::Point(190, 104);
			this->Employee_Post_Box->Name = L"Employee_Post_Box";
			this->Employee_Post_Box->Size = System::Drawing::Size(161, 29);
			this->Employee_Post_Box->TabIndex = 34;
			// 
			// label_del_employee
			// 
			this->label_del_employee->AutoSize = true;
			this->label_del_employee->Location = System::Drawing::Point(665, 216);
			this->label_del_employee->Name = L"label_del_employee";
			this->label_del_employee->Size = System::Drawing::Size(148, 22);
			this->label_del_employee->TabIndex = 33;
			this->label_del_employee->Text = L"Отображение р";
			// 
			// button_delete_employee
			// 
			this->button_delete_employee->Location = System::Drawing::Point(654, 136);
			this->button_delete_employee->Name = L"button_delete_employee";
			this->button_delete_employee->Size = System::Drawing::Size(175, 32);
			this->button_delete_employee->TabIndex = 32;
			this->button_delete_employee->Text = L"Удалить работника";
			this->button_delete_employee->UseVisualStyleBackColor = true;
			this->button_delete_employee->Click += gcnew System::EventHandler(this, &MyForm::button_delete_employee_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(577, 46);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(124, 22);
			this->label9->TabIndex = 31;
			this->label9->Text = L"ID работника";
			// 
			// Employee_ID_Box
			// 
			this->Employee_ID_Box->Location = System::Drawing::Point(704, 44);
			this->Employee_ID_Box->Name = L"Employee_ID_Box";
			this->Employee_ID_Box->Size = System::Drawing::Size(161, 29);
			this->Employee_ID_Box->TabIndex = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(651, 5);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(188, 22);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Удаление работника";
			// 
			// button_showall_employee
			// 
			this->button_showall_employee->Location = System::Drawing::Point(77, 177);
			this->button_showall_employee->Margin = System::Windows::Forms::Padding(1);
			this->button_showall_employee->Name = L"button_showall_employee";
			this->button_showall_employee->Size = System::Drawing::Size(229, 33);
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
			this->dataGridView2_employee->Location = System::Drawing::Point(47, 328);
			this->dataGridView2_employee->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView2_employee->Name = L"dataGridView2_employee";
			this->dataGridView2_employee->ReadOnly = true;
			this->dataGridView2_employee->RowHeadersWidth = 92;
			this->dataGridView2_employee->RowTemplate->Height = 37;
			this->dataGridView2_employee->Size = System::Drawing::Size(792, 181);
			this->dataGridView2_employee->TabIndex = 20;
			// 
			// label_add_employee
			// 
			this->label_add_employee->AutoSize = true;
			this->label_add_employee->Location = System::Drawing::Point(9, 216);
			this->label_add_employee->Name = L"label_add_employee";
			this->label_add_employee->Size = System::Drawing::Size(148, 22);
			this->label_add_employee->TabIndex = 27;
			this->label_add_employee->Text = L"Отображение р";
			// 
			// button_add_employee
			// 
			this->button_add_employee->Location = System::Drawing::Point(77, 136);
			this->button_add_employee->Name = L"button_add_employee";
			this->button_add_employee->Size = System::Drawing::Size(229, 32);
			this->button_add_employee->TabIndex = 26;
			this->button_add_employee->Text = L"Добавить работника";
			this->button_add_employee->UseVisualStyleBackColor = true;
			this->button_add_employee->Click += gcnew System::EventHandler(this, &MyForm::button_add_employee_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(93, 5);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(211, 22);
			this->label12->TabIndex = 25;
			this->label12->Text = L"Добавление работника";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 69);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(183, 22);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Телефон работника";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(24, 34);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(141, 22);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Имя работника";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// Employee_name_Box
			// 
			this->Employee_name_Box->Location = System::Drawing::Point(190, 34);
			this->Employee_name_Box->Name = L"Employee_name_Box";
			this->Employee_name_Box->Size = System::Drawing::Size(161, 29);
			this->Employee_name_Box->TabIndex = 21;
			// 
			// Employee_phone_Box
			// 
			this->Employee_phone_Box->Location = System::Drawing::Point(190, 69);
			this->Employee_phone_Box->Name = L"Employee_phone_Box";
			this->Employee_phone_Box->Size = System::Drawing::Size(161, 29);
			this->Employee_phone_Box->TabIndex = 22;
			// 
			// tabPage3
			// 
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
			this->tabPage3->Size = System::Drawing::Size(890, 536);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Заказы";
			this->tabPage3->Click += gcnew System::EventHandler(this, &MyForm::tabPage3_Click);
			// 
			// button_selected_order
			// 
			this->button_selected_order->Location = System::Drawing::Point(287, 246);
			this->button_selected_order->Name = L"button_selected_order";
			this->button_selected_order->Size = System::Drawing::Size(178, 30);
			this->button_selected_order->TabIndex = 56;
			this->button_selected_order->Text = L"Отобразить заказ";
			this->button_selected_order->UseVisualStyleBackColor = true;
			this->button_selected_order->Click += gcnew System::EventHandler(this, &MyForm::button_selected_order_Click);
			// 
			// textBox_forOrder
			// 
			this->textBox_forOrder->ForeColor = System::Drawing::Color::LightGray;
			this->textBox_forOrder->Location = System::Drawing::Point(63, 247);
			this->textBox_forOrder->Name = L"textBox_forOrder";
			this->textBox_forOrder->Size = System::Drawing::Size(189, 29);
			this->textBox_forOrder->TabIndex = 55;
			this->textBox_forOrder->Text = L"Введите ID заказа...";
			this->textBox_forOrder->Enter += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Enter);
			this->textBox_forOrder->Leave += gcnew System::EventHandler(this, &MyForm::textBox_forOrder_Leave);
			// 
			// button_show_orders
			// 
			this->button_show_orders->Location = System::Drawing::Point(83, 151);
			this->button_show_orders->Name = L"button_show_orders";
			this->button_show_orders->Size = System::Drawing::Size(178, 30);
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
			this->dataGridView2_Orders->Location = System::Drawing::Point(63, 335);
			this->dataGridView2_Orders->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView2_Orders->Name = L"dataGridView2_Orders";
			this->dataGridView2_Orders->ReadOnly = true;
			this->dataGridView2_Orders->RowHeadersWidth = 92;
			this->dataGridView2_Orders->RowTemplate->Height = 37;
			this->dataGridView2_Orders->Size = System::Drawing::Size(792, 195);
			this->dataGridView2_Orders->TabIndex = 53;
			// 
			// label_add_device
			// 
			this->label_add_device->AutoSize = true;
			this->label_add_device->Location = System::Drawing::Point(613, 190);
			this->label_add_device->Name = L"label_add_device";
			this->label_add_device->Size = System::Drawing::Size(193, 22);
			this->label_add_device->TabIndex = 52;
			this->label_add_device->Text = L"Отображение заказа";
			// 
			// button_add_device
			// 
			this->button_add_device->Location = System::Drawing::Point(654, 147);
			this->button_add_device->Name = L"button_add_device";
			this->button_add_device->Size = System::Drawing::Size(206, 30);
			this->button_add_device->TabIndex = 51;
			this->button_add_device->Text = L"Добавить устройство";
			this->button_add_device->UseVisualStyleBackColor = true;
			this->button_add_device->Click += gcnew System::EventHandler(this, &MyForm::button_add_device_Click);
			// 
			// Order_Label
			// 
			this->Order_Label->AutoSize = true;
			this->Order_Label->Location = System::Drawing::Point(79, 190);
			this->Order_Label->Name = L"Order_Label";
			this->Order_Label->Size = System::Drawing::Size(193, 22);
			this->Order_Label->TabIndex = 50;
			this->Order_Label->Text = L"Отображение заказа";
			// 
			// button_add_order
			// 
			this->button_add_order->Location = System::Drawing::Point(83, 115);
			this->button_add_order->Name = L"button_add_order";
			this->button_add_order->Size = System::Drawing::Size(178, 30);
			this->button_add_order->TabIndex = 49;
			this->button_add_order->Text = L"Добавить заказ";
			this->button_add_order->UseVisualStyleBackColor = true;
			this->button_add_order->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(514, 115);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(145, 22);
			this->label21->TabIndex = 48;
			this->label21->Text = L"Производитель";
			// 
			// Brand_Box
			// 
			this->Brand_Box->Location = System::Drawing::Point(671, 112);
			this->Brand_Box->Name = L"Brand_Box";
			this->Brand_Box->Size = System::Drawing::Size(161, 29);
			this->Brand_Box->TabIndex = 47;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(514, 79);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(142, 22);
			this->label20->TabIndex = 46;
			this->label20->Text = L"Тип устройства";
			// 
			// DeviceType_Box
			// 
			this->DeviceType_Box->Location = System::Drawing::Point(671, 76);
			this->DeviceType_Box->Name = L"DeviceType_Box";
			this->DeviceType_Box->Size = System::Drawing::Size(161, 29);
			this->DeviceType_Box->TabIndex = 45;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(514, 44);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(91, 22);
			this->label19->TabIndex = 44;
			this->label19->Text = L"ID заказа";
			// 
			// ID_Order_Box
			// 
			this->ID_Order_Box->Location = System::Drawing::Point(671, 41);
			this->ID_Order_Box->Name = L"ID_Order_Box";
			this->ID_Order_Box->Size = System::Drawing::Size(161, 29);
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
			this->comboBox1_Status->Location = System::Drawing::Point(671, 246);
			this->comboBox1_Status->Margin = System::Windows::Forms::Padding(1);
			this->comboBox1_Status->Name = L"comboBox1_Status";
			this->comboBox1_Status->Size = System::Drawing::Size(161, 30);
			this->comboBox1_Status->TabIndex = 42;
			this->comboBox1_Status->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_Status_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(59, 82);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(55, 22);
			this->label16->TabIndex = 41;
			this->label16->Text = L"Цена";
			// 
			// Price_Box
			// 
			this->Price_Box->Location = System::Drawing::Point(195, 79);
			this->Price_Box->Name = L"Price_Box";
			this->Price_Box->Size = System::Drawing::Size(161, 29);
			this->Price_Box->TabIndex = 40;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(505, 249);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(130, 22);
			this->label17->TabIndex = 39;
			this->label17->Text = L"Статус заказа";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(38, 41);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(102, 22);
			this->label18->TabIndex = 38;
			this->label18->Text = L"ID клиента";
			// 
			// ID_Client_Box
			// 
			this->ID_Client_Box->Location = System::Drawing::Point(195, 38);
			this->ID_Client_Box->Name = L"ID_Client_Box";
			this->ID_Client_Box->Size = System::Drawing::Size(161, 29);
			this->ID_Client_Box->TabIndex = 36;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(653, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(207, 22);
			this->label8->TabIndex = 31;
			this->label8->Text = L"Устройство для заказа";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(89, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(186, 22);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Составление заказа";
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 31);
			this->tabPage4->Margin = System::Windows::Forms::Padding(1);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(890, 536);
			this->tabPage4->TabIndex = 3;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 31);
			this->tabPage5->Margin = System::Windows::Forms::Padding(1);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(890, 536);
			this->tabPage5->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(898, 571);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(1);
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
private: System::String^ placeholderText = "Введите ID заказа..."; // Текст-подсказка
private: System::Void textBox_forOrder_Enter(System::Object^ sender, System::EventArgs^ e) {
	// Когда пользователь щелкает по TextBox, убираем текст-подсказку
	if (textBox_forOrder->Text == placeholderText || textBox_forOrder->Text == "Error") {
		textBox_forOrder->Text = "";
		textBox_forOrder->ForeColor = System::Drawing::Color::Black; // Установите цвет текста
	}

}
private: System::Void textBox_forOrder_Leave(System::Object^ sender, System::EventArgs^ e) {
	// Если TextBox пуст, показываем текст-подсказку
	if (textBox_forOrder->Text->Length == 0) {
		textBox_forOrder->Text = placeholderText;
		textBox_forOrder->ForeColor = System::Drawing::Color::LightGray; // Цвет подсказки
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
};




}
