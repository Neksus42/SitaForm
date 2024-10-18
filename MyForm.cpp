#include "MyForm.h"
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
bool isValidUTF8(const std::string& str) {
    int expectedBytes = 0;

    for (unsigned char c : str) {
        if (expectedBytes == 0) {
            if ((c & 0x80) == 0) {
                continue; // ASCII
            }
            else if ((c & 0xE0) == 0xC0) {
                expectedBytes = 1; // 110xxxxx
            }
            else if ((c & 0xF0) == 0xE0) {
                expectedBytes = 2; // 1110xxxx
            }
            else if ((c & 0xF8) == 0xF0) {
                expectedBytes = 3; // 11110xxx
            }
            else {
                return false; // недопустимый байт
            }
        }
        else {
            if ((c & 0xC0) != 0x80) {
                return false; // недопустимый байт продолжения
            }
            expectedBytes--;
        }
    }
    return expectedBytes == 0; // должно закончиться корректно
}
sql::mysql::MySQL_Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::ResultSet* res;
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

        con->setSchema("sita");
        stmt = con->createStatement();
        stmt->execute("SET NAMES 'cp1251'");
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
        
        // Создание SQL-запроса для получения всех клиентов
        std::string selectQuery = "SELECT * FROM sita.employee;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);

        // Создаем DataTable для хранения данных
        System::Data::DataTable^ dataTable2 = gcnew System::Data::DataTable();

        // Заполняем DataTable данными из ResultSet
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

        // Устанавливаем DataTable как источник данных для DataGridView
        this->dataGridView2_employee->DataSource = dataTable2;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void SitaForm::MyForm::add_order()
{
    try
    {
        std::string idclient = ConvertString(this->ID_Client_Box->Text);
        
        std::string price = ConvertString(this->Price_Box->Text);
        std::cout << "E_idclient: " + idclient + "\n";
        std::cout << "E_price: " + price + "\n";
        if (idclient == "")
        {
            this->Order_Label->Text = L"Введите ID клиента";
            return;
        }
        if (!(validation_digits(price)))
        {
            this->Order_Label->Text = L"Неправильный формат цены";
            return;
        }
        
        std::string checkexisted = "SELECT * FROM sita.customers where idCustomer =" + idclient + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->Order_Label->Text = L"Такого клиента не существует";

        }
        else
        {
            std::string addorder = "INSERT INTO `sita`.`orders` (`idCustomer`, `Price`) VALUES('" + idclient + "', '"+ price +"')";


            std::cout << addorder + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addorder);
            this->Order_Label->Text = L"Заказ успешно добавлен";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void SitaForm::MyForm::add_device()
{
    try
    {
        std::string idorder = ConvertString(this->ID_Order_Box->Text);
        std::string DeviceType = ConvertString(this->DeviceType_Box->Text);
        std::string Brand = ConvertString(this->Brand_Box->Text);
        std::cout << "E_idclient: " + idorder + "\n";
        std::cout << "E_DeviceType: " + DeviceType + "\n";
        std::cout << "E_price: " + Brand + "\n";
        if (idorder == "")
        {
            this->label_add_device->Text = L"Введите ID заказа";
            return;
        }
        

        std::string checkexisted = "SELECT * FROM sita.orders where OrderID =" + idorder + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_add_device->Text = L"Такого заказа не существует";

        }
        else
        {
            std::string adddevice = "INSERT INTO `sita`.`devices` (`OrderID`, `DeviceType`, `Brand`) VALUES('" + idorder + "', '"+ DeviceType +"', '"+ Brand +"')";



            std::cout << adddevice + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(adddevice);
            this->label_add_device->Text = L"Устройство успешно добавлено";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void SitaForm::MyForm::show_all_orders()
{
    try
    {
        
        // Создание SQL-запроса для получения всех клиентов
        std::string selectQuery = "SELECT * FROM sita.orders;";
        stmt = con->createStatement();
        //stmt->execute("SET NAMES 'cp1251'");
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);

        // Создаем DataTable для хранения данных
        System::Data::DataTable^ dataTable3 = gcnew System::Data::DataTable();

        // Заполняем DataTable данными из ResultSet
        dataTable3->Columns->Add("OrderID", int::typeid);
        dataTable3->Columns->Add("idCustomer", int::typeid);
        dataTable3->Columns->Add("OrderStatus", String::typeid);
        dataTable3->Columns->Add("Price", double::typeid);
        dataTable3->Columns->Add("OrderDate", String::typeid);
        while (res->next())
        {

            int OrderID = res->getInt("OrderID");
            int idCustomer = res->getInt("idCustomer");
            std::string OrderStatus = res->getString("OrderStatus");
            


            double Price = res->getDouble("Price");
            std::string OrderDate = res->getString("OrderDate");
            std::cerr << "id" + std::to_string(OrderID) <<"\t" + OrderStatus << std::endl;
            
            dataTable3->Rows->Add(OrderID, idCustomer, gcnew String(OrderStatus.c_str()), Price, gcnew String(OrderDate.c_str()));
        }

        // Устанавливаем DataTable как источник данных для DataGridView
        this->dataGridView2_Orders->DataSource = dataTable3;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void SitaForm::MyForm::change_combobox()
{
    try
    {
        std::string idOrder = ConvertString(this->textBox_forOrder->Text);
        
        
        std::cout << "E_idOrder: " + idOrder + "\n";
        
        
        
        std::string checkexisted = "SELECT * FROM sita.orders where OrderID =" + idOrder + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            return;

        }
        else
        {
           //gcnew String(res->getString("OrderStatus").c_str())
           
            this->comboBox1_Status->SelectedItem = gcnew String(res->getString("OrderStatus").c_str());
            std::cout << res->getString("OrderStatus") << std::endl;
            
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void SitaForm::MyForm::selected_order()
{
    try
    {
        std::string idOrder = ConvertString(this->textBox_forOrder->Text);
        // Создание SQL-запроса для получения всех клиентов
        std::string selectQuery = "SELECT * FROM sita.devices where OrderID = "+ idOrder +";";
        if (!validation_digits(idOrder))
        {
            this->textBox_forOrder->Text = "Error";
            return;
        }
        //stmt->execute("SET NAMES 'cp1251'");
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);
        
        
        // Создаем DataTable для хранения данных
        System::Data::DataTable^ dataTable3 = gcnew System::Data::DataTable();

        // Заполняем DataTable данными из ResultSet
        dataTable3->Columns->Add("idDevices", int::typeid);
        dataTable3->Columns->Add("OrderID", int::typeid);
        dataTable3->Columns->Add("DeviceType", String::typeid);
        
        dataTable3->Columns->Add("Brand", String::typeid);
        while (res->next())
        {

            int OrderID = res->getInt("idDevices");
            int idCustomer = res->getInt("OrderID");
            std::string OrderStatus = res->getString("DeviceType");



            
            std::string OrderDate = res->getString("Brand");
            std::cerr << "id" + std::to_string(OrderID) << "\t" + OrderStatus << std::endl;

            dataTable3->Rows->Add(OrderID, idCustomer, gcnew String(OrderStatus.c_str()), gcnew String(OrderDate.c_str()));
        }

        // Устанавливаем DataTable как источник данных для DataGridView
        this->dataGridView2_Orders->DataSource = dataTable3;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void SitaForm::MyForm::combobox_selected_event()
{
    if (!(validation_digits(ConvertString(this->textBox_forOrder->Text))))
    {
        this->textBox_forOrder->Text = "Error";
        return;
    }
    else
    {
        //UPDATE `sita`.`orders` SET `OrderStatus` = 'Ремонт' WHERE (`OrderID` = '2');
        stmt = con->createStatement();
        stmt->executeUpdate("UPDATE `sita`.`orders` SET `OrderStatus` = '"+ConvertString(this->comboBox1_Status->Text) + "' WHERE (`OrderID` = '" + ConvertString(this->textBox_forOrder->Text) + "')");
    }
}



System::Void SitaForm::MyForm::dataGridView2_Orders_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    this->textBox_forOrder_Enter(this->textBox_forOrder, gcnew System::EventArgs());
    this->textBox_forOrder->Text = (this->dataGridView2_Orders->Rows[e->RowIndex]->Cells[0]->Value->ToString());
    this->textBox_forOrder_Leave(this->textBox_forOrder, gcnew System::EventArgs());
}

System::Void SitaForm::MyForm::button_delete_order_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string idOrder = ConvertString(this->textBox_forOrder->Text);
    std::cout << "id " + idOrder << std::endl;
    std::string selectQuery = "SELECT * FROM sita.orders where OrderID = " + idOrder + ";";
    if (!validation_digits(idOrder))
    {
        this->textBox_forOrder->Text = "Error";
        return;
    }
    //stmt->execute("SET NAMES 'cp1251'");
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQuery);
    if (!(res->next()))
    {
        this->Order_Label->Text = "Такого заказа не существует";
    }
    else
    {
        stmt->executeUpdate("DELETE FROM `sita`.`orders` WHERE (`OrderID` = '" + idOrder + "');");
        this->Order_Label->Text = "Заказ удалён";
    }


}

