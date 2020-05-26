#include <iostream>
#include <cmath>
#include <vector>
#include "MyForm.h"
#include "Convector.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	À‡·33::MyForm from;
	Application::Run(% from);
}

int iz, in;
std::string number;

System::Void À‡·33::MyForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void À‡·33::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "";
	Convector_String_to_string(textBox4->Text->ToString(), number);
	iz = Convert::ToInt32(textBox2->Text);
	in = Convert::ToInt32(textBox3->Text);
	bool f = true;
	if (iz > 32)
	{
		f = false;
	}
	if (in < 2)
	{
		f = false;
	}
	if (in > 32)
	{
		f = false;
	}

	std::vector<int> vhod;

	while (number.size() > 0)
	{
		if ((int)number[number.size() - 1] >= 48 && (int)number[number.size() - 1] <= 57)
		{
			vhod.insert(vhod.begin(), (int)number[number.size() - 1] - 48);
		}
		else if ((int)number[number.size() - 1] >= 65 && (int)number[number.size() - 1] <= 90)
		{
			vhod.insert(vhod.begin(), (int)number[number.size() - 1] - 65 + 10);
		}
		number.erase(number.size() - 1, 1);
	}
	for (int i = 0; i < vhod.size(); i++)
	{
		if (vhod[i] > iz)
		{
			f = false;
		}
	}
	if (f == false)
	{
		MessageBox::Show("Error!", "Calculator");
	}
	int sum = 0;
	for (int i = 0; i < vhod.size(); i++)
	{
		sum += vhod[vhod.size() - 1 - i] * pow(iz, i);
	}
	int summ = sum;
	std::vector<int> v;
	while (summ > 0)
	{
		v.insert(v.begin(), summ % in);
		summ = summ / in;
	}
	int j = 0;
	if (f == true)
	{
		char r[10] = "";
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] < 10)
			{
				textBox1->Text += v[i].ToString();
			}
			else
			{
				r[0] = 97 + v[i] - 10 - 32;
				textBox1->Text += gcnew System::String(r);
				j++;
			}
		}
	}
	return System::Void();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
System::Void À‡·33::MyForm::domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::domainUpDown2_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
/*System::Void À‡·33::MyForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 2;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 3;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 8;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 9;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 10;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	iz = 16;
	return System::Void();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
System::Void À‡·33::MyForm::radioButton11_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 2;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton10_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 3;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton12_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 8;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton9_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 9;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 10;
	return System::Void();
}
System::Void À‡·33::MyForm::radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	in = 16;
	return System::Void();
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
System::Void À‡·33::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label4_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::groupBox2_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}