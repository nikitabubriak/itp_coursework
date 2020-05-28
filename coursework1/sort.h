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
	m = 0,		//array first index
	n = 1024;	//array size

//primary class
class Program
{
	string directory; //working directory storage

public:

	//data processing class
	class Array
	{
		//arrays for storing data to output
		int random[n]; //can be copied in order to sort with different algorithms at once; stores random data
		int sorted[n]; //is identical to random array when copied; after sorting stores sorted data

	public:
		//basic array processing methods
		void generate();
		void copy();
		void output(string, int);
		int* get_array();

	}array;

	//sorting algorithm class
	struct Sort
	{
		//merge sort
		class Merge
		{
			//divide and conquer
			void sort(int*, int, int, int);
		public:
			void divide(int*, int, int);

		}merge;


		//quick sort
		class Quick
		{
			//divide and conquer
			void swap(int*, int*);
			int  partition(int*, int, int);
		public:
			void sort(int*, int, int);

		}quick;


		//tree sort
		class Tree
		{
			vector<int> temp;

			//binary search tree

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

	//working directory's setter and getter
	void   set_dir(System::Windows::Forms::TextBox^);
	string get_dir();
	
}program;



#include "sort.cpp"