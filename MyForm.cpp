#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

bool validation(std::string tovalidate, std::string parameter)
{
    return std::regex_match(tovalidate, std::regex(parameter));
}
bool validation_digits(std::string tovalidate)
{

    return validation(tovalidate, "[0-9]*");
}
bool validation_phone(std::string tovalidate)
{

    return validation(tovalidate, "\\+375[0-9]{9}");
}
sql::mysql::MySQL_Driver* driver = nullptr;
sql::Connection* con= nullptr;
sql::Statement* stmt= nullptr;
sql::ResultSet* res= nullptr;
[STAThreadAttribute]
void main(array<String^>^ args)
{
    SetConsoleOutputCP(CP_UTF8);
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    
   
 
   
    std::string clientName;
    try {
       
        

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", "root", "1111");
        con->setClientOption("characterSetResults", "utf8mb4");

        con->setSchema("lerbd");
        stmt = con->createStatement();
        stmt->execute("SET NAMES 'cp1251'");
        setlocale(LC_ALL,"rus");
       /* stmt = con->createStatement();*/


        //// SQL query to retrieve data from the table
        //std::string selectDataSQL = "SELECT * FROM mainbase.clients;";

        //res = stmt->executeQuery(selectDataSQL);

        //// Loop through the result set and display data
        //int count = 0;
        ////res->next();
        //
        ////clientName = res->getString("ClientName"); 
      
        ////String^ clientNameStr = gcnew String(clientName.c_str());
        ////form.UpdateButtonText(clientNameStr); 
       

        ////delete res;
        ////delete stmt;
        ////delete con;
        
    //form.UpdateButtonText("gfdg");
        SitaForm::MyForm form;
        //form.Initialize(con, stmt, res);
        Application::Run(% form);
        
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
   
   
}



std::string SitaForm::MyForm::ConvertString(String^ str)
{
        return msclr::interop::marshal_as<std::string>(str);
    
}

void SitaForm::MyForm::addclient()
{
    try
    {
        //SELECT * FROM lerbd.клиент;
        std::string phone = ConvertString(this->ClientPhoneBox->Text);
        std::string name = ConvertString(this->ClientNameBox->Text);
        std::cout << "Name: " + name + "\n";
        std::cout << "Phone: " + phone + "\n";
        if (name == "")
        {
            this->label4->Text = L"Введите имя клиента";
            return;
        }
        if (!(validation_phone(phone)))
        {
            this->label4->Text = L"Неправильный формат номера";
            return;
        }
        
        std::string checkexisted = "SELECT * FROM lerbd.клиент where Номер_телефона = '" + phone + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label4->Text = L"Такой номер уже существует";
        
        }
        else
        {
            std::string addclient = "INSERT INTO `lerbd`.`клиент` (`ФИО`, `Номер_телефона`) VALUES('" + name + "', '" + phone + "');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label4->Text = L"Клиент успешно добавлен";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void SitaForm::MyForm::show_all_clients()
{
    try
    {
        
        std::string selectQuery = "SELECT * FROM lerbd.клиент;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);
        
        
        System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

        
        dataTable->Columns->Add("ID_клиент", int::typeid);
        dataTable->Columns->Add("ФИО", String::typeid);
        dataTable->Columns->Add("Номер_телефона", String::typeid);

        while (res->next())
        {
            
            int id = res->getInt("ID_клиент");
            std::string name = res->getString("ФИО");
            std::string contactInfo = res->getString("Номер_телефона");
            std::cerr << "id" + std::to_string(id) << std::endl;
            dataTable->Rows->Add(id, gcnew String(name.c_str()), gcnew String(contactInfo.c_str()));
        }

        std::cout << selectQuery << std::endl;
        this->dataGridView1->DataSource = dataTable;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
void SitaForm::MyForm::delete_client()
{
    try
    {
        std::string id = ConvertString(this->ClientID->Text);
       
        std::cout << "ID: " + id + "\n";
        
        if (id == "")
        {
            this->label7->Text = L"Введите id клиента";
            return;
        }
        if (!(validation_digits(id)))
        {
            this->label7->Text = L"Введите id клиента";
            return;
        }

        std::string checkexisted = "SELECT * FROM lerbd.клиент where ID_клиент = '" + id + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label7->Text = L"Такого клиента не существует";

        }
        else
        {
            std::string addclient = "DELETE FROM `lerbd`.`клиент` WHERE (`ID_клиент` = '"+id+"');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label7->Text = L"Клиент успешно удален";
            SitaForm::MyForm::show_all_clients();
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void SitaForm::MyForm::add_employee()
{
    try
    {
        std::string post = ConvertString(this->Employee_Post_Box->Text);
        std::string phone = ConvertString(this->Employee_phone_Box->Text);
        std::string name = ConvertString(this->Employee_name_Box->Text);
        std::cout << "E_Name: " + name + "\n";
        std::cout << "E_Phone: " + phone + "\n";
        std::cout << "E_Post: " + post + "\n";
        if (name == "")
        {
            this->label_add_employee->Text = L"Введите имя работника";
            return;
        }
        if (!(validation_phone(phone)))
        {
            this->label_add_employee->Text = L"Неправильный формат номера";
            return;
        }

        std::string checkexisted = "SELECT * FROM sita.employee where Telephone_number ="+phone+";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label_add_employee->Text = L"Такой номер уже существует";

        }
        else
        {
            std::string addclient = "INSERT INTO `sita`.`employee` (`Name`, `Post`, `Telephone_number`) VALUES ('" + name + "', '" + post + "', '"+phone+"');";

            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_add_employee->Text = L"Работник успешно добавлен";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void SitaForm::MyForm::delete_employee()
{
    try
    {
        std::string id = ConvertString(this->Employee_ID_Box->Text);

        std::cout << "ID: " + id + "\n";

        if (id == "")
        {
            this->label_del_employee->Text = L"Введите id работника";
            return;
        }
        if (!(validation_digits(id)))
        {
            this->label_del_employee->Text = L"Введите id работника";
            return;
        }

        std::string checkexisted = "SELECT * FROM sita.employee where idEmployee = '" + id + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_del_employee->Text = L"Такого работника не существует";

        }
        else
        {
            std::string addclient = "DELETE FROM `sita`.`employee` WHERE (`idEmployee` = '" + id + "');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_del_employee->Text = L"Работник успешно удален";
            SitaForm::MyForm::show_all_employee();
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void SitaForm::MyForm::show_all_employee()
{
    try
    {
        
        
        std::string selectQuery = "SELECT * FROM sita.employee;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);

        
        System::Data::DataTable^ dataTable2 = gcnew System::Data::DataTable();

        
        dataTable2->Columns->Add("ID", int::typeid);
        dataTable2->Columns->Add("Name", String::typeid);
        dataTable2->Columns->Add("Telephone number", String::typeid);
        dataTable2->Columns->Add("Post", String::typeid);
        while (res->next())
        {

            int id = res->getInt("idEmployee");
            std::string name = res->getString("Name");
            std::string contactInfo = res->getString("Telephone_number");
            std::string post = res->getString("Post");
            std::cerr << "id" + std::to_string(id) << std::endl;
            dataTable2->Rows->Add(id, gcnew String(name.c_str()), gcnew String(contactInfo.c_str()),gcnew String(post.c_str()));
        }

        
        this->dataGridView2_employee->DataSource = dataTable2;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}






