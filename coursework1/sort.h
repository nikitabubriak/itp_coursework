#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "GUI.h"

using namespace std;

const int n = 1024;


class Program
{
	string directory;

public:
	class Array
	{
		int random[n];
		int sorted[n];

	public:
		void generate();// int*);
		void copy();
		void output(string, int);
		//int* get_array();
	};

	class Sort
	{


	public:
		void merge();
		void quick();
		void tree();
	};

	Array array;
	Sort sort;

	void init(System::Windows::Forms::TextBox^);// , System::Windows::Forms::Label^);
	string get_dir();
	
	
}program;



#include "sort.cpp"