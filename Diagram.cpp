#include "MyForm.h"
#include <vector>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::Windows::Forms::DataVisualization::Charting;

System::Void SitaForm::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::vector<int> vec;
    std::string selectQuery = "SELECT * FROM sita.reports;";
    stmt = con->createStatement();
    //stmt->execute("SET NAMES 'cp1251'");
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);

    res = stmt->executeQuery(selectQuery);

    while (res->next())
    {
        std::string tocheck = res->getString("Problem_Category");
        if (tocheck == "�������")
            ++vec[0];
        if (tocheck == "�� ��������� ����")
            ++vec[1];
        if (tocheck == "�������")
            ++vec[2];
        if (tocheck == "������")
            ++vec[3];

    }



    // ���������, ���� �� ��� ChartArea
    if (this->chart1->ChartAreas->Count == 0) {
        ChartArea^ chartArea = gcnew ChartArea();
        this->chart1->ChartAreas->Add(chartArea);
    }

    // ���������, ���� �� ��� Series � ������ "PieSeries"
    if (this->chart1->Series->IndexOf("PieSeries") == -1) {
        Series^ series = gcnew Series();
        series->Name = "Problem_Category";
        //series->ChartType = SeriesChartType::Pie;  // �������� ���������
        series->Points->AddXY("�������", vec[0]);
        series->Points->AddXY("�� ��������� ����", vec[1]);
        series->Points->AddXY("�������", vec[2]);
        series->Points->AddXY("������", vec[3]);

        // ��������� ������ � �����
        series->Points[0]->Color = System::Drawing::Color::Red;
        series->Points[1]->Color = System::Drawing::Color::Green;
        series->Points[2]->Color = System::Drawing::Color::Blue;
        series->Points[3]->Color = System::Drawing::Color::Yellow;

        // ��������� ������� � ������������ �����
       /* series->Points[0]->Label = "30%";
        series->Points[0]->LegendText = "Category 1";*/

        this->chart1->Series->Add(series);
    }

}