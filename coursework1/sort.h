#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int n = 1024;

class program
{
	string directory;

public:
	class array
	{
		int random[n];
		int sorted[n];

	public:
		void generate();
		void output();
	};

	class sort
	{


	public:
		void merge();
		void quick();
		void tree();
	};

	string init();
};



//#include "sort.cpp"