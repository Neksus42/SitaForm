#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;





System::Void SitaForm::MyForm::button_add_department_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        
        std::string name = ConvertString(this->textbox_foraddDepartment->Text);
        std::cout << "E_Name: " + name + "\n";
  
        if (name == "")
        {
            this->label_department_add->Text = L"Введите название отдела";
            return;
        }
      

        std::string checkexisted = "SELECT * FROM lerbd.отдел where Название_отдела ='" + name + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if ((res->next()))
        {
            this->label_department_add->Text = L"Такой отдел уже существует";

        }
        else
        {
            std::string addclient = "INSERT INTO `lerbd`.`отдел` (`Название_отдела`) VALUES ('" + name + "');";

            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_department_add->Text = L"Отдел успешно добавлен";
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

System::Void SitaForm::MyForm::button_show_all_departmnents_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {


        std::string selectQuery = "SELECT * FROM lerbd.отдел;";
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);


        System::Data::DataTable^ dataTable2 = gcnew System::Data::DataTable();


        dataTable2->Columns->Add("ID_отдел", int::typeid);
        dataTable2->Columns->Add("Название_отдела", String::typeid);
     
        while (res->next())
        {

            int id = res->getInt("ID_отдел");
            std::string name = res->getString("Название_отдела");
          
            std::cerr << "id" + std::to_string(id) << std::endl;
            dataTable2->Rows->Add(id, gcnew String(name.c_str()));
        }


        this->dataGridView_Departments->DataSource = dataTable2;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SitaForm::MyForm::button_to_delete_department_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        std::string id = ConvertString(this->textBox_for_deleting_Department->Text);

        std::cout << "ID: " + id + "\n";

        if (id == "")
        {
            this->label_department_delete->Text = L"Введите id отдела";
            return;
        }
        if (!(validation_digits(id)))
        {
            this->label_department_delete->Text = L"Введите id отдела";
            return;
        }

        std::string checkexisted = "SELECT * FROM lerbd.отдел where ID_отдел = '" + id + "';";
        std::cout << checkexisted + "\n";
        stmt = con->createStatement();
        res = stmt->executeQuery(checkexisted);
        if (!(res->next()))
        {
            this->label_department_delete->Text = L"Такого отдела не существует";

        }
        else
        {
            std::string addclient = "DELETE FROM `lerbd`.`отдел` WHERE (`ID_отдел` = '" + id + "');";
            std::cout << addclient + "\n";
            stmt = con->createStatement();
            stmt->executeUpdate(addclient);
            this->label_department_delete->Text = L"Отдел успешно удален";
            SitaForm::MyForm::button_show_all_departmnents_Click(this, gcnew EventArgs());
        }

    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
