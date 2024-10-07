#include "HashTable.h"
#include <vector>
#include <cstdlib>
#include <random>
#include "HashTableModel.hpp"
#include <Windows.h>


using namespace lab1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HashTable);
    return 0;
}

std::vector<int> get_uniq(int n) {
    int seed = time(nullptr);
    srand(seed);
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(1e4, 1e5);

    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        int element = distribution(generator);
        while (std::find(arr.begin(), arr.end(), element) != arr.end()) {
            element = distribution(generator);
        }

        arr.push_back(element);
    }
    return arr;
}

System::Void lab1::HashTable::button_Click(System::Object^ sender, System::EventArgs^ e) {
    auto arr = get_uniq(48);
    tableModel.clear();
    for (auto& i : arr) {
        tableModel.push(i); // »спользуем оператор -> дл€ доступа к методу
    }
    return System::Void();
}

System::Void lab1::HashTable::updateTable(System::Object^ sender, System::EventArgs^ e) {

    fillFactorLable->Text = "Table fill factor : " +( round(tableModel.fillFactor() * 1000) / 1000 ).ToString();
    averageLable->Text = "Average number of steps : " + (round(tableModel.average() * 1000) / 1000).ToString();
    dataGridView1->Rows->Clear();
    this->dataGridView1->ColumnCount = 2*3; 
    this->dataGridView1->RowCount = 40;

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 3; j++) {
            if (i * 3 + j >= tableModel.get_t()) break;
            dataGridView1->Rows[i]->Cells[2 * j]->Value = (i * 3 + j).ToString();
            dataGridView1->Rows[i]->Cells[2 * j]->Style->BackColor = System::Drawing::Color::Gray;
            if (tableModel.get_ind(i) != 0) dataGridView1->Rows[i]->Cells[2*j+1]->Value = tableModel.get_ind(i).ToString();
            else {
                dataGridView1->Rows[i]->Cells[2 * j + 1]->Value = "";
            }
        }
    }
    // «аполн€ем DataGridView данными из вашей модели
  
  
}

System::Void lab1::HashTable::HashTable_Load(System::Object^ sender, System::EventArgs^ e) {
    this->tableModel.observers += gcnew System::EventHandler(this, &HashTable::updateTable);

    return System::Void();
}
