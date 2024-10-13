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

        con->setSchema("mainbase");

        
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
        
      
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    //form.UpdateButtonText("gfdg");
    SitaForm::MyForm form;
    //form.Initialize(con, stmt, res);
    Application::Run(% form);
   
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
        if (!(validation_digits(phone)))
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
void SitaForm::MyForm::UpdateLabel(String^ text)
{
    this->label4->Text = text;
}