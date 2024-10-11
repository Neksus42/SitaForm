#include "MyForm.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include<string>
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SitaForm::MyForm form;
 
 
    std::string clientName;
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", "root", "1111");

        con->setSchema("mainbase");

        sql::Statement* stmt;
        stmt = con->createStatement();


        // SQL query to retrieve data from the table
        std::string selectDataSQL = "SELECT * FROM mainbase.clients;";

        sql::ResultSet* res = stmt->executeQuery(selectDataSQL);

        // Loop through the result set and display data
        int count = 0;
        res->next();

        clientName = res->getString("clients"); // замените "client_name" на название столбца
        String^ clientNameStr = gcnew String(clientName.c_str());
        form.UpdateButtonText(L"hhh"); // Обновляем текст на кнопке
       

        delete res;
        delete stmt;
        delete con;
        
      
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    form.UpdateButtonText(gcnew String(clientName.c_str()));
    Application::Run(% form);
}