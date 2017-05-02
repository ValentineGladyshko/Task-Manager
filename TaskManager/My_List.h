#pragma once
#include "Obj.h"
#include "MyString.h"
#include "Str.h"
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <conio.h>


using std::vector;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class My_List
{
	vector<CObj>table_intime; //������ �������� �������
	vector<CObj>table_outtime;//������ �������� �������
public:
	My_List();
	void add_obj(CObj);    //������� ������� ������ ��������
	void update_obj(string, string, STime, int, int);
	void show(DataGridView^);//��������� ������ ����
	void showIntime(DataGridView^);
	void showOuttime(DataGridView^);
	bool IsIntimeEmpty();
	bool IsOuttimeEmpty();
	void showOne(RichTextBox^, RichTextBox^, RichTextBox^, RichTextBox^, Button^, int, int);//��������� ������ ��������
	void showOne(RichTextBox^, RichTextBox^, DateTimePicker^, int, int);
	void ChangeObjStatus(int, int, Button^);//���������� �������� � �������� � ������
	void SortByName();
	void SortByDate();
	void SortByDeadline();
	void DeleteObj(int, int);
	void CheckStatus();
	void read_from_file(); //������� � �����
	void write_to_file();  //����� � ����
	~My_List();
};