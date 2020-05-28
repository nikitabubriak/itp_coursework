#pragma once

#include "GUI.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

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

		class Merge
		{
			void sort(int*, int, int, int);
		public:
			void divide(int*, int, int);

		}merge;



		class Quick
		{
			void swap(int*, int*);
			int  partition(int*, int, int);
		public:
			void sort(int*, int, int);

		}quick;



		class Tree
		{
			vector<int> temp;

			struct Node
			{
				int data;
				Node *left, *right;
			};

			Node *new_node(int);
			Node *insert(Node*, int);
			void output(Node*);
		public:
			void create(int*, int, int);

		}tree;

	}sort;

	void   set_dir(System::Windows::Forms::TextBox^);// , System::Windows::Forms::Label^);
	string get_dir();
	
}program;



#include "sort.cpp"