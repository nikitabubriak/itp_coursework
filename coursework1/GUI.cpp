#include "GUI.h"
#include "sort.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThread]

void __clrcall WinMain()//array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	coursework1::GUI form;
	Application::Run(%form);

}

