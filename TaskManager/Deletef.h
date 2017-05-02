#pragma once

namespace TaskManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Deletef
	/// </summary>
	public ref class Deletef : public System::Windows::Forms::Form
	{
	public:
		Deletef(void)
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
		~Deletef()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Deletef::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Так";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Deletef::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(242, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ні";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Deletef::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(77, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(251, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ви точно хочете видалити задачу\?";
			// 
			// Deletef
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 108);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(425, 147);
			this->MinimumSize = System::Drawing::Size(425, 147);
			this->Name = L"Deletef";
			this->Text = L"Delete\?";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Deletef::Deletef_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		int flagDel = 2;
	private: System::Void Deletef_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (flagDel == 2)
		e->Cancel = true;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		flagDel = 1;
		Close();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		flagDel = 0;
		Close();
	}
	};
}
