#pragma once

ref class HashTableModel
{
private:
    array<int>^ arr; // ���������� ����������� ������
 
    int t = 97; // ������ ���-�������
    int fill_factor = 0; // ���������� ����������� �����
    int cout_steps = 0; // ������� �����
    int element_count = 0; // ���������� ���������

    int hash(int k) {
        return (k + 7) % 10000 % t; // ���-�������
    }

public:
    HashTableModel(); // �����������
    ~HashTableModel(); // ����������
    System::EventHandler^ observers;
    void push(int element);
    void print();
    double fillFactor();
    double average();
    void clear();
    int get_t();
    int get_ind(int n);
};

HashTableModel::HashTableModel() {
    arr = gcnew array<int>(t); // ������������� ������������ �������
    for (int i = 0; i < t; ++i) {
        arr[i] = 0; // ���������� ������
    }
 
}

void HashTableModel::push(int element) {
    int a0 = hash(element);
    int i = 0;
    cout_steps++;
    element_count++;

    while (arr[(a0 + i * i) % t] > 0 && i < t) {
        i++;
        cout_steps++;
    }

    if (i >= t) {
        while (arr[(a0 + i) % t] > 0 && i < t * 2) {
            i++;
            cout_steps++;
        }
        arr[(a0 + i) % t] = element; // ������� ��������
        return;
    }

    arr[(a0 + i * i) % t] = element; // ������� ��������
    fill_factor++;

    // ��������� ������� ��� ���������� ������ ��������
    observers->Invoke(this, nullptr);
}

double HashTableModel::fillFactor() {
    return (double)fill_factor / t; // ���������� ������������� ���-�������
}

int HashTableModel::get_t() {
    return t;
}
int HashTableModel::get_ind(int n) {
    return arr[n];
}
void HashTableModel::clear() {
    for (int i = 0; i < t; ++i) {
        arr[i] = 0;
    }
    fill_factor = 0;
    cout_steps = 0;
    element_count = 0;
}

void HashTableModel::print() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 5; j++) {
            if (i * 5 + j >= 97) break;
           
        }
       
    }
}

double HashTableModel::average() {
    return (element_count > 0) ? (double)cout_steps / element_count : 0.0; // ������ �� ������� �� ����
}

HashTableModel::~HashTableModel() {
    // ����������, ���� ���������
}