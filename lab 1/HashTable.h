#pragma once
#include "HashTableModel.hpp"
namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HashTable
	/// </summary>
	public ref class HashTable : public System::Windows::Forms::Form
	{
	public: HashTableModel tableModel;

	
	public:
		HashTable(void)
		{	

			
			InitializeComponent();
		}
		


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HashTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ fillFactorLable;
	private: System::Windows::Forms::Label^ averageLable;
	private: System::Windows::Forms::Button^ button;



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->fillFactorLable = (gcnew System::Windows::Forms::Label());
			this->averageLable = (gcnew System::Windows::Forms::Label());
			this->button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(22, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(698, 463);
			this->dataGridView1->TabIndex = 0;
			// 
			// fillFactorLable
			// 
			this->fillFactorLable->AutoSize = true;
			this->fillFactorLable->Font = (gcnew System::Drawing::Font(L"Open Sans", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fillFactorLable->Location = System::Drawing::Point(739, 29);
			this->fillFactorLable->Name = L"fillFactorLable";
			this->fillFactorLable->Size = System::Drawing::Size(169, 31);
			this->fillFactorLable->TabIndex = 1;
			this->fillFactorLable->Text = L"Table fill factor :";
			// 
			// averageLable
			// 
			this->averageLable->AutoSize = true;
			this->averageLable->Font = (gcnew System::Drawing::Font(L"Open Sans", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->averageLable->Location = System::Drawing::Point(739, 84);
			this->averageLable->Name = L"averageLable";
			this->averageLable->Size = System::Drawing::Size(270, 31);
			this->averageLable->TabIndex = 2;
			this->averageLable->Text = L"Average number of steps: ";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(846, 442);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(163, 50);
			this->button->TabIndex = 3;
			this->button->Text = L"fill with random numbers";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &HashTable::button_Click);
			// 
			// HashTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 507);
			this->Controls->Add(this->button);
			this->Controls->Add(this->averageLable);
			this->Controls->Add(this->fillFactorLable);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"HashTable";
			this->Text = L"HashTable";
			this->Load += gcnew System::EventHandler(this, &HashTable::HashTable_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HashTable_Load(System::Object^ sender, System::EventArgs^ e);
	public:  System::Void HashTable::updateTable(System::Object^ sender, System::EventArgs^ e);
	
};
}
