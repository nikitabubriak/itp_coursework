#include "sort.h"
#include "GUI.h"

#include <msclr\marshal_cppstd.h>

using namespace std;


//working directory setter based on user input data
void Program::set_dir(System::Windows::Forms::TextBox ^textbox)
{
	//convert System::String to std::string
	System::String^ managed_s = textbox->Text;
	msclr::interop::marshal_context context;
	std::string standard_s = context.marshal_as<std::string>(managed_s);

	this->directory = standard_s;
}


//working directory getter for array output method
string Program::get_dir()
{
	return this->directory;
}


//random array generator
void Program::Array::generate()
{
	for (int i = 0; i < n; i++)
	{
		this->random[i] = rand() % n + 1;
	}
}


//copy data from random array to array used in sorting algorithms
void Program::Array::copy()
{
	for (int i = 0; i < n; i++)
	{
		this->sorted[i] = this->random[i];
	}
}


//output either random or particular sorted array in form of 16x64 matrix
//into new .txt file in working directory, depending on the integer flag passed
void Program::Array::output(string output, int s)
{
	string out = output;

	//select the filename
	switch (s)
	{
	case 0: out += "/array_random.txt";
			break;
	case 1: out += "/merge_sort.txt";
			break;
	case 2: out += "/quick_sort.txt";
			break;
	case 3: out += "/tree_sort.txt";
			break;
	default:out += "/error.txt";
			break;
	}

	ofstream outfile(out);
	if (!outfile.is_open()) return;

	//output random array
	if (s == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			outfile << this->random[i-1] << ' ';
			if (i != 0 && i % 16 == 0) outfile << endl;
		}
	}
	//output sorted array
	else
	{
		for (int i = 1; i <= n; i++)
		{
			outfile << this->sorted[i - 1] << ' ';
			if (i != 0 && i % 16 == 0) outfile << endl;
		}
	}
	
	outfile.close();
}


//array getter for processing in the sorting algorithm
int* Program::Array::get_array()
{
	return this->sorted;
}

//===============================< Merge sort >==================================

void Program::Sort::Merge::divide(int *a, int low, int high)
{
	int mid;

	//divide and conquer
	if (low < high)
	{
		mid = (low + high) / 2;

		//recursively sort two parts one by one
		divide(a, low, mid);
		divide(a, mid + 1, high);

		//merge sorted arrays
		sort(a, low, high, mid);
	}
}



void Program::Sort::Merge::sort(int *a, int low, int high, int mid)
{
	int t[n - m + 1]; //temp

	//index storage
	int i = low,
		j = mid + 1,
		k = m;

	//until reaching middle or high point, put elements in correct positions
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			t[k] = a[i];
			k++;
			i++;
		}

		else
		{
			t[k] = a[j];
			k++;
			j++;
		}
	}
	//iterate and get remaining data through lower part
	while (i <= mid)
	{
		t[k] = a[i];
		k++;
		i++;
	}
	//iterate and get remaining data through higher part
	while (j <= high)
	{
		t[k] = a[j];
		k++;
		j++;
	}
	//copy temporary data to sorted array
	for (i = low; i <= high; i++)
	{
		a[i] = t[i - low];
	}
}

//===============================< Quick sort >==================================

void Program::Sort::Quick::sort(int *a, int low, int high)
{
	//divide and conquer
	if (low < high)
	{
		//partition the array using pivot
		int pivot = partition(a, low, high);

		//recursively sort two parts one by one
		sort(a, low, pivot - 1);
		sort(a, pivot + 1, high);
	}
}



void Program::Sort::Quick::swap(int *a, int *b)
{
	//swap two array elements
	int  t = *a;
		*a = *b;
		*b = t;
}



int Program::Sort::Quick::partition(int *a, int low, int high)
{
	int pivot = a[high], //pick last element as pivot
		i = low - 1; //lower element index

	//element smaller than the pivot goes lower, element bigger than the pivot goes higher

	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[i + 1], &a[high]);

	return (i + 1);
}

//===============================< Tree sort >===================================

//create binary search tree
void Program::Sort::Tree::create(int *a, int low, int high)
{
	//first node
	Node *root = NULL;

	//fill the tree with random data in the correct order
	for (int i = low; i < high; i++)
	{
		root = insert(root, a[i]);
	}

	//traverse the tree
	output(root);

	//copy temporary data to the sorted array
	for (int i = low; i < high; i++)
	{
		a[i] = temp[i];
	}

	temp.clear();
}


//create binary tree node, initialize its members
Program::Sort::Tree::Node* Program::Sort::Tree::new_node(int new_data)
{
	Node *temp = new Node();

	temp->data = new_data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


//insert a new node with new data
Program::Sort::Tree::Node* Program::Sort::Tree::insert(Node *node, int new_data)
{
	//create the root node in the empty binary tree
	if (node == NULL)			return new_node(new_data);

	//binary tree is not empty, put data on the correct subnode of the node based on value
	if (new_data < node->data)	node->left = insert(node->left, new_data);
	else						node->right = insert(node->right, new_data);

	return node;
}


//inorder binary search tree traversal, recursively adding data to the temporary vector 
void Program::Sort::Tree::output(Node* root)
{
	if (root != NULL)
	{
		output(root->left);

		temp.push_back(root->data);

		output(root->right);
	}
}
