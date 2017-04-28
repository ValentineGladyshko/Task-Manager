#pragma once
#include "My_List.h"
#include "Deletef.h"

namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DeletingTask
	/// </summary>
	public ref class DeletingTask : public System::Windows::Forms::Form
	{
	public:
		DeletingTask(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DeletingTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  NameList;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name3;
	private: System::Windows::Forms::Button^  Deleting;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->NameList = (gcnew System::Windows::Forms::DataGridView());
			this->Name3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Deleting = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NameList))->BeginInit();
			this->SuspendLayout();
			// 
			// NameList
			// 
			this->NameList->AllowUserToAddRows = false;
			this->NameList->AllowUserToDeleteRows = false;
			this->NameList->AllowUserToResizeColumns = false;
			this->NameList->AllowUserToResizeRows = false;
			this->NameList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->NameList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Name3 });
			this->NameList->Location = System::Drawing::Point(12, 12);
			this->NameList->Name = L"NameList";
			this->NameList->ReadOnly = true;
			this->NameList->RowHeadersVisible = false;
			this->NameList->RowHeadersWidth = 30;
			this->NameList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->NameList->Size = System::Drawing::Size(158, 368);
			this->NameList->TabIndex = 3;
			// 
			// Name3
			// 
			this->Name3->HeaderText = L"Назва";
			this->Name3->Name = L"Name3";
			this->Name3->ReadOnly = true;
			this->Name3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Name3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Name3->Width = 155;
			// 
			// Deleting
			// 
			this->Deleting->Location = System::Drawing::Point(344, 158);
			this->Deleting->Name = L"Deleting";
			this->Deleting->Size = System::Drawing::Size(123, 62);
			this->Deleting->TabIndex = 4;
			this->Deleting->Text = L"Видалити";
			this->Deleting->UseVisualStyleBackColor = true;
			this->Deleting->Click += gcnew System::EventHandler(this, &DeletingTask::Delete);
			// 
			// DeletingTask
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(589, 395);
			this->Controls->Add(this->Deleting);
			this->Controls->Add(this->NameList);
			this->MaximumSize = System::Drawing::Size(605, 434);
			this->MinimumSize = System::Drawing::Size(605, 434);
			this->Name = L"DeletingTask";
			this->Text = L"DeletingTask";
			this->Load += gcnew System::EventHandler(this, &DeletingTask::Loading);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NameList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool WantDelete()
		{
			Deletef^ form = gcnew Deletef;
			form->ShowDialog();
			return (form->flagDel == 1);
		}

	private: System::Void Delete(System::Object^  sender, System::EventArgs^  e) {
		if (WantDelete())
		{
			My_List list;
			list.read_from_file();
			int t = Convert::ToInt32(NameList->CurrentRow->Index);
//			list.DeleteObj(t);
			list.write_to_file();
		}
		Close();
	}
	private: System::Void Loading(System::Object^  sender, System::EventArgs^  e) {
		My_List list;
		list.read_from_file();
		list.show(NameList);
	}
	};
}
