#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;



System::Void SitaForm::MyForm::button_for_making_order_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string idEmployee = ConvertString(this->textBox_order_idemployee->Text);
    std::string idOrder = ConvertString(this->textBox_order_foridorder->Text);

    std::cout << "id " + idOrder << std::endl;
    std::string selectQueryEmployee = "SELECT * FROM sita.employee where idEmployee = " + idEmployee + ";";
    std::string selectQueryOrder = "SELECT * FROM sita.orders where OrderID = " + idOrder + ";";
    std::string selectQuery = "SELECT * FROM sita.employeeorders where idEmployee = " + idEmployee + " and OrderID = "+idOrder+";";
    if (!validation_digits(idOrder))
    {
        this->label_for_asign->Text = "Введите ID заказа";
        return;
    }
    if (idOrder == "")
    {
        this->label_for_asign->Text = "Введите ID заказа";
        return;
    }
    if (!validation_digits(idEmployee))
    {
        this->label_for_asign->Text = "Введите ID работника";
        return;
    }
    if (idEmployee == "")
    {
        this->label_for_asign->Text = "Введите ID работника";
        return;
    }
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQueryEmployee);
    if (!(res->next()))
    {
        this->label_for_asign->Text = "Такого работника не существует";
        return;
    }
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQueryOrder);
    if (!(res->next()))
    {
        this->label_for_asign->Text = "Такого заказа не существует";
        return;
    }






    //stmt->execute("SET NAMES 'cp1251'");
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQuery);
    if ((res->next()))
    {
        this->label_for_asign->Text = "Такая связь уже существует";
    }
    else
    {
        
        std::string forquery = "INSERT INTO `sita`.`employeeorders` (`idEmployee`, `OrderID`) VALUES ('" + idEmployee + "', '"+idOrder+"');";
        stmt = con->createStatement();
        stmt->executeUpdate(forquery);
        this->label_for_asign->Text = "Связь успешно создана";
    }
}

System::Void SitaForm::MyForm::button_show_all_asign_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {

        
        std::string selectQuery = "SELECT * FROM sita.employeeorders;";
        stmt = con->createStatement();
        //stmt->execute("SET NAMES 'cp1251'");

        res = stmt->executeQuery(selectQuery);

       
        System::Data::DataTable^ dataTable5 = gcnew System::Data::DataTable();

       
        dataTable5->Columns->Add("idEmployee", int::typeid);
        dataTable5->Columns->Add("OrderID", int::typeid);

        while (res->next())
        {

            int idEmployee = res->getInt("idEmployee");
            int OrderID = res->getInt("OrderID");



            std::cerr << "id" + std::to_string(OrderID) << std::endl;

            dataTable5->Rows->Add(idEmployee, OrderID);
        }

        
        this->dataGridView_for_asign->DataSource = dataTable5;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SitaForm::MyForm::textBox_for_selected_asign_Enter(System::Object^ sender, System::EventArgs^ e)
{
    
    if (textBox_for_selected_asign->Text == placeholderText_for_asign || textBox_selected_report->Text == "Error") {
        textBox_for_selected_asign->Text = "";
        textBox_for_selected_asign->ForeColor = System::Drawing::Color::Black; 
    }
}

System::Void SitaForm::MyForm::textBox_for_selected_asign_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox_for_selected_asign->Text->Length == 0) {
        textBox_for_selected_asign->Text = placeholderText_for_asign;
        textBox_for_selected_asign->ForeColor = System::Drawing::Color::LightGray; 
        return;
    }
}

System::Void SitaForm::MyForm::dataGridView_for_asign_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex < 0) return;

    this->textBox_for_selected_asign_Enter(this->textBox_for_selected_asign, gcnew System::EventArgs());
    this->textBox_for_selected_asign->Text = (this->dataGridView_for_asign->Rows[e->RowIndex]->Cells[1]->Value->ToString());
    this->textBox_for_selected_asign_Leave(this->textBox_for_selected_asign, gcnew System::EventArgs());
}

System::Void SitaForm::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string idOrder = ConvertString(this->textBox_for_selected_asign->Text);
    std::cout << "id " + idOrder << std::endl;
    std::string selectQuery = "SELECT * FROM sita.employeeorders where OrderID = " + idOrder + ";";
    if (!validation_digits(idOrder))
    {
        this->textBox_for_selected_asign->Text = "Error";
        return;
    }
    //stmt->execute("SET NAMES 'cp1251'");
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQuery);
    if (!(res->next()))
    {
        this->label_for_asign->Text = "Такой связи не существует";
    }
    else
    {
        stmt->executeUpdate("DELETE FROM `sita`.`employeeorders` WHERE (`OrderID` = '"+ idOrder +"')");
        this->label_for_asign->Text = "Связь удалена";
    }
}
