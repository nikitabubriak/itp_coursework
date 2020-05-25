//#include "sort.h"
#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]

//void __clrcall WinMain()//array<String^>^ args) //
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	coursework1::GUI form;
	Application::Run(%form);

	//srand((unsigned)time(0));
	srand((unsigned)time(NULL));



}

