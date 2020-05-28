#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;

//main function

[STAThread]

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	coursework1::GUI form;
	Application::Run(%form);
}