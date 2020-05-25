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

	struct Sort
	{
		struct Merge
		{
			void divide(int*, int, int);
			void sort(int*, int, int, int);

		}merge;

		struct Quick
		{
			void sort(int*, int, int);
			void swap(int*, int*);
			int  partition(int*, int, int);

		}quick;
		
		struct Tree
		{
			void tree();


		}tree;

	}sort;

	void   set_dir(System::Windows::Forms::TextBox^);// , System::Windows::Forms::Label^);
	string get_dir();
	
	
}program;



#include "sort.cpp"