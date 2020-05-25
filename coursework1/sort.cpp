#include "sort.h"
#include <msclr\marshal_cppstd.h>
#include "GUI.h"
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



void Program::Array::generate(int *a)
{
	for (int i = 0; i < n; i++)
	{
		*a = rand() % n + 1;
		a++;
	}
}



void Program::Array::output(string output)
{
	//ofstream outfile(output);
	//if (!outfile.is_open()) { cout << "Error. Cannot open output file\n"; return; }

	//outfile.close();

}



