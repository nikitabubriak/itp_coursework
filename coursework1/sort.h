#pragma once

#include "GUI.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int 
m = 0, 
n = 1024;



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
		int* get_array();

	}array;

	class Sort
	{


	public:
		void merge_divide(int*, int, int);
		void merge_sort(int*, int, int, int);

		void quick();
		void tree();

	}sort;

	void set_dir(System::Windows::Forms::TextBox^);// , System::Windows::Forms::Label^);
	string get_dir();
	
	
}program;



#include "sort.cpp"