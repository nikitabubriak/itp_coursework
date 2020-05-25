#include "sort.h"
#include "GUI.h"

#include <msclr\marshal_cppstd.h>

using namespace std;
//using namespace coursework1;



void Program::init(System::Windows::Forms::TextBox ^textbox)//, System::Windows::Forms::Label ^label)
{
	System::String^ managed_s = textbox->Text;
	msclr::interop::marshal_context context;
	std::string standard_s = context.marshal_as<std::string>(managed_s);
	//label->Text = managed_s;
	this->directory = standard_s;

}

string Program::get_dir()
{
	//string dir = this->directory;
	return this->directory;
}

/*int* Program::Array::get_array()
{
	return 0;
}*/


void Program::Array::generate()//int *a)
{
	for (int i = 0; i < n; i++)
	{
		this->random[i] = rand() % n + 1;
		//*this->random++;
		//*a = rand() % n + 1;
		//a++;
	}
}


void Program::Array::copy()//int *a)
{
	for (int i = 0; i < n; i++)
	{
		this->sorted[i] = this->random[i];
	}
}



void Program::Array::output(string output, int s)
{
	string out = output;

	switch (s)
	{
	case 0: out += "/random_array.txt";
			break;
	case 1: out += "/merge_sort.txt";
			break;
	case 2: out += "/quick_sort.txt";
			break;
	case 3: out += "/tree_sort.txt";
			break;
	default: out += "/error.txt";
			break;
	}

	ofstream outfile(out);
	//if (!outfile.is_open()) { cout << "Error. Cannot open output file\n"; return; }

	if (s == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			outfile << this->random[i-1] << ' ';
			if (i != 0 && i % 16 == 0) outfile << endl;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			outfile << this->sorted[i] << ' ';
			if (i != 0 && i % 16 == 0) outfile << endl;
		}
	}
	
	outfile.close();
}



