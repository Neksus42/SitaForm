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
#include<format>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

System::Void SitaForm::MyForm::button_delete_order_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string idOrder = ConvertString(this->textBox_forOrder->Text);
    std::cout << "id " + idOrder << std::endl;
    std::string selectQuery = "SELECT * FROM lerbd.заказ where ID_заказ = " + idOrder + ";";
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
        stmt->executeUpdate("DELETE FROM `lerbd`.`заказ` WHERE (`ID_заказ` = '" + idOrder + "');");
        stmt->executeUpdate("DELETE FROM `lerbd`.`станок` WHERE (`ID_заказ` = '" + idOrder + "');");
        this->Order_Label->Text = "Заказ удалён";
    }


}
System::Void SitaForm::MyForm::dataGridView2_Orders_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex < 0) return;
        this->textBox_forOrder_Enter(this->textBox_forOrder, gcnew System::EventArgs());
        this->textBox_forOrder->Text = (this->dataGridView2_Orders->Rows[e->RowIndex]->Cells[0]->Value->ToString());
        this->textBox_forOrder_Leave(this->textBox_forOrder, gcnew System::EventArgs());
    
}

//void SitaForm::MyForm::combobox_selected_event()
//{
//    if (!(validation_digits(ConvertString(this->textBox_forOrder->Text))))
//    {
//        this->textBox_forOrder->Text = "Error";
//        return;
//    }
//    else
//    {
//        //UPDATE `sita`.`orders` SET `OrderStatus` = 'Ремонт' WHERE (`OrderID` = '2');
//        stmt = con->createStatement();
//        stmt->executeUpdate("UPDATE `sita`.`orders` SET `OrderStatus` = '" + ConvertString(this->comboBox1_Status->Text) + "' WHERE (`OrderID` = '" + ConvertString(this->textBox_forOrder->Text) + "')");
//    }
//}
void SitaForm::MyForm::selected_order()
{
    try
    {
        std::string idOrder = ConvertString(this->textBox_forOrder->Text);
        std::string selectQuery = "SELECT * FROM lerbd.станок where ID_заказ = " + idOrder + ";";
        if (!validation_digits(idOrder))
        {
            this->textBox_forOrder->Text = "Error";
            return;
        }
        //stmt->execute("SET NAMES 'cp1251'");
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);


        System::Data::DataTable^ dataTable3 = gcnew System::Data::DataTable();

        dataTable3->Columns->Add("ID_станок", int::typeid);
        dataTable3->Columns->Add("Серийный_номер", int::typeid);
        dataTable3->Columns->Add("Вид_неисправности", String::typeid);

        dataTable3->Columns->Add("ID_заказ", int::typeid);
        while (res->next())
        {

            int Machine_ID = res->getInt("ID_станок");
            int SerialNumber = res->getInt("Серийный_номер");
            std::string ProblemType = res->getString("Вид_неисправности");
            int ID_Order = res->getInt("ID_заказ");



           
            std::cerr << "id" + std::to_string(Machine_ID) << "\t" + std::to_string(ID_Order) << std::endl;

            dataTable3->Rows->Add(Machine_ID, SerialNumber, gcnew String(ProblemType.c_str()), ID_Order);
        }

        this->dataGridView2_Orders->DataSource = dataTable3;
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
        std::string idmanager = ConvertString(this->textBox_order_managerID->Text);
        std::string idEmployee = ConvertString(this->textBox_order_ID_Employee->Text);
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

        std::string checkexisted = "SELECT * FROM lerbd.клиент where ID_клиент =" + idclient + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->Order_Label->Text = L"Такого клиента не существует";

        }
        else
        {
            std::string addorder = "INSERT INTO `lerbd`.`заказ` (`ID_клиент`, `Стоимость`,`ID_менеджер`,`ID_сотрудник`) VALUES('" + idclient + "', '" + price + "','"+ idmanager +"','"+idEmployee+"')";


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
        std::string SerialNumber = ConvertString(this->SerialNumber_Box->Text);
        std::string problem_type = ConvertString(this->comboBox_problem_type->Text);
        std::cout << "E_idclient: " + idorder + "\n";
        std::cout << "E_SerialNumber: " + SerialNumber + "\n";
        std::cout << "E_problem_type: " + problem_type + "\n";
        if (idorder == "")
        {
            this->label_add_device->Text = L"Введите ID заказа";
            return;
        }


        std::string checkexisted = "SELECT * FROM lerbd.заказ where ID_заказ =" + idorder + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_add_device->Text = L"Такого заказа не существует";

        }
        else
        {
            std::string adddevice = "INSERT INTO `lerbd`.`станок` (`ID_заказ`, `Серийный_номер`, `Вид_неисправности`) VALUES('" + idorder + "', '" + SerialNumber + "', '" + problem_type + "')";



            std::cout << adddevice + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(adddevice);
            this->label_add_device->Text = L"Станок успешно добавлен";
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

        std::string selectQuery = "SELECT * FROM lerbd.заказ;";
        stmt = con->createStatement();
        //stmt->execute("SET NAMES 'cp1251'");
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);

        System::Data::DataTable^ dataTable3 = gcnew System::Data::DataTable();

        dataTable3->Columns->Add("ID\nзаказ", int::typeid);
        dataTable3->Columns->Add("ID\nклиент", int::typeid);
        dataTable3->Columns->Add("ID\nменеджер", int::typeid);
        dataTable3->Columns->Add("ID\nсотрудник", int::typeid);

        dataTable3->Columns->Add("Стоимость", double::typeid);
        dataTable3->Columns->Add("Дата\nоформления заказа", String::typeid);
        dataTable3->Columns->Add("Дата\nвыполнения заказа", String::typeid);
        while (res->next())
        {

            int OrderID = res->getInt("ID_заказ");
            int idCustomer = res->getInt("ID_клиент");

            int idManager = res->getInt("ID_менеджер");
            int idEmployee = res->getInt("ID_сотрудник");




            double Price = res->getDouble("Стоимость");
            std::string OrderDate = res->getString("Дата_оформления_заказа");
            std::string OrdercompleteDate = res->getString("Дата_выполнения_заказа");
            std::cerr << "id" + std::to_string(OrderID) << std::endl;

            dataTable3->Rows->Add(OrderID, idCustomer, idManager,idEmployee,Price, gcnew String(OrderDate.c_str()), gcnew String(OrdercompleteDate.c_str()));
        }

        this->dataGridView2_Orders->DataSource = dataTable3;

     
        System::Drawing::Font^ smallerFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 10); 
        for (int i = 0; i < this->dataGridView2_Orders->Columns->Count; i++)
        {
            System::Windows::Forms::DataGridViewColumn^ column = this->dataGridView2_Orders->Columns[i];
            column->DefaultCellStyle->Font = smallerFont; 
        }

       
        for (int i = 0; i < this->dataGridView2_Orders->Columns->Count; i++)
        {
            System::Windows::Forms::DataGridViewColumn^ column = this->dataGridView2_Orders->Columns[i];
            if (i < 4) // Для первых 4 колонок с ID
            {
                column->Width = 100; // Установите меньшую ширину
            }
            else if (i == 4) // Для колонки "Стоимость"
            {
                column->Width = 120; // Средняя ширина
            }
            else if (i <= 6) // Для колонки "Дата оформления заказа"
            {
                column->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill; // Заполнение оставшегося пространства
            }
        }
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



        std::string checkexisted = "SELECT * FROM lerbd.заказ where ID_заказ =" + idOrder + ";";
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

            //this->comboBox1_Status->SelectedItem = gcnew String(res->getString("OrderStatus").c_str());
            if (res->isNull("Дата_выполнения_заказа"))
            {
                this->label_order_status->Text = L"В процессе";
                std::cout << idOrder +" Status: NULL"  << std::endl;
            }
            else
            {
                this->label_order_status->Text = L"Выполнен";
                std::cout << res->getString("Дата_выполнения_заказа") << std::endl;
            }
            

        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

}
System::Void SitaForm::MyForm::button_confirm_order_status_date_Click(System::Object^ sender, System::EventArgs^ e)
{
    /*UPDATE lerbd.заказ
        SET Дата_выполнения_заказа = NOW()
        WHERE ID_заказ = 5 AND Дата_выполнения_заказа IS NULL;*/

    try
    {
        std::string idOrder = ConvertString(this->textBox_forOrder->Text);
        if (!validation_digits(idOrder)) return;
        std::cout << "id " + idOrder << std::endl;

        std::string selectQuery = std::format(R"(
    UPDATE lerbd.заказ
    SET Дата_выполнения_заказа = NOW()
    WHERE ID_заказ = {} AND Дата_выполнения_заказа IS NULL;)", idOrder);
        stmt = con->createStatement();
        stmt->executeUpdate(selectQuery);
        show_all_orders();
        this->textBox_forOrder->Text = "";
        textBox_forOrder_Leave(this, gcnew EventArgs());
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

}


