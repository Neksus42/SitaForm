#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

System::Void SitaForm::MyForm::button_add_manager_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        std::string name = ConvertString(this->textBox_manager_name->Text);
        std::string phone = ConvertString(this->textBox_manager_phone->Text);
    
        std::string id_department = ConvertString(this->textBox_manager_ID_department->Text);
        std::cout << "E_Name: " + name + "\n";
        std::cout << "E_Phone: " + phone + "\n";
      
        std::cout << "E_Department: " + id_department + "\n";
        if (name == "")
        {
            this->label_managers_add->Text = L"Введите имя менеджера";
            return;
        }
        if (!(validation_phone(phone)))
        {
            this->label_managers_add->Text = L"Неправильный формат номера";
            return;
        }

        std::string checkexisted = "SELECT * FROM lerbd.менеджер where Номер_телефона =" + phone + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label_managers_add->Text = L"Такой номер уже существует";
            return;
        }
       checkexisted = "SELECT * FROM lerbd.менеджер where ID_Отдел =" + id_department + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label_managers_add->Text = L"У этого отдела уже есть менеджер";
            return;

        }

        checkexisted = "SELECT * FROM lerbd.отдел where ID_отдел =" + id_department + ";";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_managers_add->Text = L"Этого отдела не существует";
            return;
        }

        else
        {
            std::string addclient = "INSERT INTO `lerbd`.`менеджер` (`ФИО`, `Номер_телефона`,`ID_отдел`) VALUES ('" + name + "', '" + phone + "','" + id_department + "');";

            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_managers_add->Text = L"Менеджер успешно добавлен";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

System::Void SitaForm::MyForm::button_show_allmanagers_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {


        std::string selectQuery = "SELECT * FROM lerbd.менеджер;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);


        System::Data::DataTable^ dataTable2 = gcnew System::Data::DataTable();


        dataTable2->Columns->Add("ID_менеджер", int::typeid);
        dataTable2->Columns->Add("ФИО", String::typeid);
        dataTable2->Columns->Add("Номер_телефона", String::typeid);
        dataTable2->Columns->Add("ID_отдел", int::typeid);
        while (res->next())
        {

            int id = res->getInt("ID_менеджер");
            std::string name = res->getString("ФИО");
            std::string contactInfo = res->getString("Номер_телефона");
            int id_department = res->getInt("ID_Отдел");
            std::cerr << "id" + std::to_string(id) << std::endl;
            dataTable2->Rows->Add(id, gcnew String(name.c_str()), gcnew String(contactInfo.c_str()), id_department);
        }


        this->dataGridView_managers->DataSource = dataTable2;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SitaForm::MyForm::button_manager_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        std::string id = ConvertString(this->textBox_manager_delete->Text);

        std::cout << "ID: " + id + "\n";

        if (id == "")
        {
            this->label_manager_delete->Text = L"Введите id менеджера";
            return;
        }
        if (!(validation_digits(id)))
        {
            this->label_manager_delete->Text = L"Введите id менеджера";
            return;
        }

        std::string checkexisted = "SELECT * FROM lerbd.менеджер where ID_менеджер = '" + id + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_manager_delete->Text = L"Такого менеджера не существует";
            return;
        }
        else
        {
            std::string addclient = "DELETE FROM `lerbd`.`менеджер` WHERE (`ID_менеджер` = '" + id + "');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_manager_delete->Text = L"Менеджер успешно удален";
            SitaForm::MyForm::button_show_allmanagers_Click(this, gcnew EventArgs());
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
