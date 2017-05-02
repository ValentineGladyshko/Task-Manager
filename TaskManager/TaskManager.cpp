#include "MyForm.h"
#include "My_List.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace System;
using namespace System::Windows::Forms;
My_List list;

void main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TaskManager::MyForm form;
	Application::Run(%form);
}