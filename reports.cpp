#include"MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

System::Void SitaForm::MyForm::button4_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    std::string idOrder = ConvertString(this->textBox_order_forreport->Text);
    std::string CategoryProblem = ConvertString(this->comboBox_for_category->Text);
    std::cout << "id " + idOrder << std::endl;
    std::string selectQuery = "SELECT * FROM sita.orders where OrderID = " + idOrder + ";";
    if (!validation_digits(idOrder))
    {
        this->label_for_reports->Text = "Введите ID заказа";
        return;
    }
    if (idOrder == "")
    {
        this->label_for_reports->Text = "Введите ID заказа";
        return;
    }
    if (CategoryProblem == "")
    {
        this->label_for_reports->Text = "Выберите категорию проблемы";
        return;
    }
    //stmt->execute("SET NAMES 'cp1251'");
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQuery);
    if (!(res->next()))
    {
        this->label_for_reports->Text = "Такого заказа не существует";
    }
    else
    {
        std::string problem = ConvertString(this->richTextBox1_for_problem->Text);
        std::string recommend = ConvertString(this->richTextBox1_for_recommendtaion->Text);
        std::string forquery = "INSERT INTO `sita`.`reports` (`OrderID`, `ProblemDescription`, `Recommendations`,`Problem_Category`) VALUES ('"+idOrder+"', '"+problem+"', '"+recommend+"','" + CategoryProblem + "');";
        stmt = con->createStatement();
        stmt->executeUpdate(forquery);
        this->label_for_reports->Text = "Отчёт успешно добавлен";
    }
}

System::Void SitaForm::MyForm::button_show_reports_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {

        std::string selectQuery = "SELECT * FROM sita.reports;";
        stmt = con->createStatement();
        //stmt->execute("SET NAMES 'cp1251'");
        
        res = stmt->executeQuery(selectQuery);

        System::Data::DataTable^ dataTable4 = gcnew System::Data::DataTable();

        dataTable4->Columns->Add("idReports", int::typeid);
        dataTable4->Columns->Add("OrderID", int::typeid);
        dataTable4->Columns->Add("ReportDate", String::typeid);
      
        while (res->next())
        {

            int idReports = res->getInt("idReports");
            int OrderID = res->getInt("OrderID");
            std::string ReportDate = res->getString("ReportDate");



            
            std::cerr << "id" + std::to_string(OrderID) << std::endl;

            dataTable4->Rows->Add(idReports, OrderID, gcnew String(ReportDate.c_str()));
        }

        this->dataGridView2_reports->DataSource = dataTable4;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SitaForm::MyForm::textBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox_selected_report->Text == placeholderText_for_report || textBox_selected_report->Text == "Error") {
        textBox_selected_report->Text = "";
        textBox_selected_report->ForeColor = System::Drawing::Color::Black; 
    }
}

System::Void SitaForm::MyForm::textBox1_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox_selected_report->Text->Length == 0) {
        textBox_selected_report->Text = placeholderText_for_report;
        textBox_selected_report->ForeColor = System::Drawing::Color::LightGray; 
        return;
    }
}

System::Void SitaForm::MyForm::dataGridView2_reports_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex < 0) return;
    
        this->textBox1_Enter(this->textBox_selected_report, gcnew System::EventArgs());
        this->textBox_selected_report->Text = (this->dataGridView2_reports->Rows[e->RowIndex]->Cells[0]->Value->ToString());
        this->textBox1_Leave(this->textBox_selected_report, gcnew System::EventArgs());
    
    }

System::Void SitaForm::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        dataGridView2_reports->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

        dataGridView2_reports->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
        dataGridView2_reports->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

        std::string idReports = ConvertString(this->textBox_selected_report->Text);
        std::string selectQuery = "SELECT * FROM sita.reports where idReports = " + idReports + ";";
        if (!validation_digits(idReports))
        {
            this->textBox_selected_report->Text = "Error";
            return;
        }
        //stmt->execute("SET NAMES 'cp1251'");
        stmt = con->createStatement();
        res = stmt->executeQuery(selectQuery);


        System::Data::DataTable^ dataTable4 = gcnew System::Data::DataTable();

      
        dataTable4->Columns->Add("OrderID", int::typeid);
        dataTable4->Columns->Add("ProblemDescription", String::typeid);
        dataTable4->Columns->Add("Recommendations", String::typeid);
        dataTable4->Columns->Add("Problem_Category", String::typeid);

        
        while (res->next())
        {

            int OrderID = res->getInt("OrderID");
            std::string ProblemDescription = res->getString("ProblemDescription");
            std::string Recommendations = res->getString("Recommendations");
            std::string Problem = res->getString("Problem_Category");



            std::cerr << "id" + std::to_string(OrderID) << std::endl;

            dataTable4->Rows->Add(OrderID, gcnew String(ProblemDescription.c_str()), gcnew String(Recommendations.c_str()), gcnew String(Problem.c_str()));
        }

        this->dataGridView2_reports->DataSource = dataTable4;
    }
    catch (sql::SQLException& e)
    {
        MessageBox::Show(gcnew String(e.what()), "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SitaForm::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string idReport = ConvertString(this->textBox_selected_report->Text);
    std::cout << "id " + idReport << std::endl;
    std::string selectQuery = "SELECT * FROM sita.reports where idReports = " + idReport + ";";
    if (!validation_digits(idReport))
    {
        this->textBox_selected_report->Text = "Error";
        return;
    }
    //stmt->execute("SET NAMES 'cp1251'");
    stmt = con->createStatement();
    res = stmt->executeQuery(selectQuery);
    if (!(res->next()))
    {
        this->label_for_reports->Text = "Такого заказа не существует";
    }
    else
    {
        stmt->executeUpdate("DELETE FROM `sita`.`reports` WHERE (`OrderID` = '" + idReport + "');");
        this->label_for_reports->Text = "Отчёт удалён";
    }
}
