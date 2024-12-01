#include "MyForm.h"
#include <vector>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::Windows::Forms::DataVisualization::Charting;


System::Void SitaForm::MyForm::TabPage6Enter(System::Object^ sender, System::EventArgs^ e)
{
    std::vector<int> vec;
    std::string selectQuery = "SELECT * FROM lerbd.станок;";
    stmt = con->createStatement();
    //stmt->execute("SET NAMES 'cp1251'");
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);

    res = stmt->executeQuery(selectQuery);

    while (res->next())
    {
        std::string tocheck = res->getString("Вид_неисправности");
        if (tocheck == "Обслуживание")
            ++vec[0];
        if (tocheck == "Замена детали")
            ++vec[1];
        if (tocheck == "Диагностика")
            ++vec[2];
        if (tocheck == "Другое")
            ++vec[3];

    }



    // Проверяем, есть ли уже ChartArea
    if (this->chart1->ChartAreas->Count == 0) {
        ChartArea^ chartArea = gcnew ChartArea();
        this->chart1->ChartAreas->Add(chartArea);
    }

    if (this->chart1->Series->IndexOf("Виды неисправности") == -1) {
        Series^ series = gcnew Series();
        series->Name = "Виды неисправности";
        //series->ChartType = SeriesChartType::Pie; // Убедитесь, что это круговая диаграмма

        series->Points->AddXY("Обслуживание", vec[0]);
        series->Points->AddXY("Замена детали", vec[1]);
        series->Points->AddXY("Диагностика", vec[2]);
        series->Points->AddXY("Другое", vec[3]);

        // Настройка цветов и меток
        series->Points[0]->Color = System::Drawing::Color::Red;
        series->Points[1]->Color = System::Drawing::Color::Green;
        series->Points[2]->Color = System::Drawing::Color::Blue;
        series->Points[3]->Color = System::Drawing::Color::Yellow;

        this->chart1->Series->Add(series);
    }
    else {
        // Если серия уже существует, обновляем данные
        Series^ existingSeries = this->chart1->Series["Виды неисправности"];
        existingSeries->Points->Clear(); // Удаляем старые точки
        existingSeries->Points->AddXY("Обслуживание", vec[0]);
        existingSeries->Points->AddXY("Замена детали", vec[1]);
        existingSeries->Points->AddXY("Диагностика", vec[2]);
        existingSeries->Points->AddXY("Другое", vec[3]);
    }
}