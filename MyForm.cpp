#include "MyForm.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include<string>
#include <msclr/marshal_cppstd.h>
#include <regex>
using namespace System;
using namespace System::Windows::Forms;

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

sql::mysql::MySQL_Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::ResultSet* res;
[STAThreadAttribute]
void main(array<String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    
   
 
   
    std::string clientName;
    try {
       

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", "root", "1111");

        con->setSchema("sita");

        
       /* stmt = con->createStatement();*/


        //// SQL query to retrieve data from the table
        //std::string selectDataSQL = "SELECT * FROM mainbase.clients;";

        //res = stmt->executeQuery(selectDataSQL);

        //// Loop through the result set and display data
        //int count = 0;
        ////res->next();
        //
        ////clientName = res->getString("ClientName"); // замените "client_name" на название столбца
      
        ////String^ clientNameStr = gcnew String(clientName.c_str());
        ////form.UpdateButtonText(clientNameStr); // Обновляем текст на кнопке
       

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
        
        std::string checkexisted = "SELECT * FROM sita.customers where ContactInfo = '" + phone + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label4->Text = L"Такой номер уже существует";
        
        }
        else
        {
            std::string addclient = "INSERT INTO `sita`.`customers` (`Name`, `ContactInfo`) VALUES('" + name + "', '" + phone + "');";
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
        // Создание SQL-запроса для получения всех клиентов
        std::string selectQuery = "SELECT * FROM sita.customers;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);

        // Создаем DataTable для хранения данных
        System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

        // Заполняем DataTable данными из ResultSet
        dataTable->Columns->Add("ID", int::typeid);
        dataTable->Columns->Add("Name", String::typeid);
        dataTable->Columns->Add("ContactInfo", String::typeid);

        while (res->next())
        {
            
            int id = res->getInt("idCustomer");
            std::string name = res->getString("Name");
            std::string contactInfo = res->getString("ContactInfo");
            std::cerr << "id" + std::to_string(id) << std::endl;
            dataTable->Rows->Add(id, gcnew String(name.c_str()), gcnew String(contactInfo.c_str()));
        }

        // Устанавливаем DataTable как источник данных для DataGridView
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

        std::string checkexisted = "SELECT * FROM sita.customers where idCustomer = '" + id + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label7->Text = L"Такого клиента не существует";

        }
        else
        {
            std::string addclient = "DELETE FROM `sita`.`customers` WHERE (`idCustomer` = '"+id+"');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label7->Text = L"Клиент успешно удален";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void SitaForm::MyForm::UpdateLabel(String^ text)
{
    this->label4->Text = text;
}