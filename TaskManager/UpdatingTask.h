#pragma once
#include "My_List.h"
#include <locale.h>

using std::string;

namespace TaskManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для UpdatingTask
	/// </summary>
	public ref class UpdatingTask : public System::Windows::Forms::Form
	{
	public:
		int num;
		int table;
		UpdatingTask(int n, int t)
		{
			InitializeComponent();
			num = n;
			table = t;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UpdatingTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  Deadline2;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::RichTextBox^  Name2;
	private: System::Windows::Forms::RichTextBox^  Text2;
	private: System::Windows::Forms::Label^  Name1;
	private: System::Windows::Forms::Label^  Deadline1;
	private: System::Windows::Forms::Label^  Text1;
	private: System::Windows::Forms::Button^  Updating;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdatingTask::typeid));
			this->Deadline2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->Name2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Text2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Name1 = (gcnew System::Windows::Forms::Label());
			this->Deadline1 = (gcnew System::Windows::Forms::Label());
			this->Text1 = (gcnew System::Windows::Forms::Label());
			this->Updating = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Deadline2
			// 
			this->Deadline2->CustomFormat = L"dd MMMM yyyy  H:mm";
			this->Deadline2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->Deadline2->Location = System::Drawing::Point(350, 25);
			this->Deadline2->MinDate = System::DateTime(2016, 12, 26, 0, 0, 0, 0);
			this->Deadline2->Name = L"Deadline2";
			this->Deadline2->Size = System::Drawing::Size(199, 20);
			this->Deadline2->TabIndex = 0;
			// 
			// Name2
			// 
			this->Name2->Location = System::Drawing::Point(15, 25);
			this->Name2->MaxLength = 63;
			this->Name2->Multiline = false;
			this->Name2->Name = L"Name2";
			this->Name2->Size = System::Drawing::Size(329, 20);
			this->Name2->TabIndex = 2;
			this->Name2->Text = L"";
			this->Name2->WordWrap = false;
			// 
			// Text2
			// 
			this->Text2->Location = System::Drawing::Point(12, 64);
			this->Text2->MaxLength = 4095;
			this->Text2->Name = L"Text2";
			this->Text2->Size = System::Drawing::Size(537, 248);
			this->Text2->TabIndex = 3;
			this->Text2->Text = L"";
			// 
			// Name1
			// 
			this->Name1->AutoSize = true;
			this->Name1->Location = System::Drawing::Point(12, 9);
			this->Name1->Name = L"Name1";
			this->Name1->Size = System::Drawing::Size(39, 13);
			this->Name1->TabIndex = 4;
			this->Name1->Text = L"Назва";
			// 
			// Deadline1
			// 
			this->Deadline1->AutoSize = true;
			this->Deadline1->Location = System::Drawing::Point(347, 9);
			this->Deadline1->Name = L"Deadline1";
			this->Deadline1->Size = System::Drawing::Size(52, 13);
			this->Deadline1->TabIndex = 5;
			this->Deadline1->Text = L"Дедлайн";
			// 
			// Text1
			// 
			this->Text1->AutoSize = true;
			this->Text1->Location = System::Drawing::Point(12, 48);
			this->Text1->Name = L"Text1";
			this->Text1->Size = System::Drawing::Size(33, 13);
			this->Text1->TabIndex = 7;
			this->Text1->Text = L"Опис";
			// 
			// Updating
			// 
			this->Updating->Location = System::Drawing::Point(425, 318);
			this->Updating->Name = L"Updating";
			this->Updating->Size = System::Drawing::Size(124, 36);
			this->Updating->TabIndex = 8;
			this->Updating->Text = L"Змінити";
			this->Updating->UseVisualStyleBackColor = true;
			this->Updating->Click += gcnew System::EventHandler(this, &UpdatingTask::Update);
			// 
			// UpdatingTask
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 371);
			this->Controls->Add(this->Text2);
			this->Controls->Add(this->Updating);
			this->Controls->Add(this->Text1);
			this->Controls->Add(this->Deadline1);
			this->Controls->Add(this->Name1);
			this->Controls->Add(this->Name2);
			this->Controls->Add(this->Deadline2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(580, 410);
			this->MinimumSize = System::Drawing::Size(580, 410);
			this->Name = L"UpdatingTask";
			this->Text = L"UpdateTask";
			this->Load += gcnew System::EventHandler(this, &UpdatingTask::SLoad);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool WantUpdate();
		char* MarshalString(String ^ s) {
			using namespace Runtime::InteropServices;
			char* chars =
				(char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			return chars;
		}
	
	private: System::Void SLoad(System::Object^  sender, System::EventArgs^  e) {
		extern My_List list;
		list.CheckStatus();
		list.showOne(Name2, Text2, Deadline2, num, table);
	}

	private: System::Void Update(System::Object^  sender, System::EventArgs^  e) {
		if (Name2->Text != ""&&Text2->Text != "")
		{
			if (WantUpdate())
			{
				extern My_List list;
				list.CheckStatus();
				string name = MarshalString(Name2->Text);
				string text = MarshalString(Text2->Text);
				STime deadline;
				deadline.Set(Deadline2->Value);
				list.update_obj(name, text, deadline, num, table);
				list.write_to_file();
				Close();
			}
		}
	}
};
}