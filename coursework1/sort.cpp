#include "sort.h"
#include "GUI.h"

#include <msclr\marshal_cppstd.h>

using namespace std;



void Program::set_dir(System::Windows::Forms::TextBox ^textbox)//, System::Windows::Forms::Label ^label)
{
	System::String^ managed_s = textbox->Text;
	msclr::interop::marshal_context context;
	std::string standard_s = context.marshal_as<std::string>(managed_s);
	//label->Text = managed_s;
	this->directory = standard_s;
}



string Program::get_dir()
{
	//string dir = this->directory;
	return this->directory;
}



void Program::Array::generate()//int *a)
{
	for (int i = 0; i < n; i++)
	{
		this->random[i] = rand() % n + 1;
		//*this->random++;
		//*a = rand() % n + 1;
		//a++;
	}
}



void Program::Array::copy()//int *a)
{
	for (int i = 0; i < n; i++)
	{
		this->sorted[i] = this->random[i];
	}
}



void Program::Array::output(string output, int s)
{
	string out = output;

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
	//if (!outfile.is_open()) { cout << "Error. Cannot open output file\n"; return; }

	if (s == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			outfile << this->random[i-1] << ' ';
			if (i != 0 && i % 16 == 0) outfile << endl;
		}
	}

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



int* Program::Array::get_array()
{
	return this->sorted;
}



void Program::Sort::Merge::divide(int *a, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		divide(a, low, mid);
		divide(a, mid + 1, high);

		sort(a, low, high, mid);
	}
}



void Program::Sort::Merge::sort(int *a, int low, int high, int mid)
{
	int t[n - m + 1];

	int i = low,
		j = mid + 1,
		k = m;

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

	while (i <= mid)
	{
		t[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		t[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = t[i - low];
	}
}



void Program::Sort::Quick::sort(int *a, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(a, low, high);

		sort(a, low, pivot - 1);
		sort(a, pivot + 1, high);
	}
}



void Program::Sort::Quick::swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}



int Program::Sort::Quick::partition(int *a, int low, int high)
{
	int pivot = a[high], 
		i = low - 1;

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



void Program::Sort::Tree::create(int *a, int low, int high)
{

	Node *root = NULL;

	for (int i = low; i < high; i++)
	{
		root = insert(root, a[i]);
	}

	output(root);

	for (int i = low; i < high; i++)
	{
		a[i] = temp[i];
	}

	temp.clear();
}



Program::Sort::Tree::Node* Program::Sort::Tree::new_node(int new_data)
{
	Node *temp = new Node();

	temp->data = new_data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}



Program::Sort::Tree::Node* Program::Sort::Tree::insert(Node *node, int new_data)
{

	if (node == NULL)			return new_node(new_data);

	if (new_data < node->data)	node->left = insert(node->left, new_data);
	else						node->right = insert(node->right, new_data);

	return node;
}



void Program::Sort::Tree::output(Node* root)
{
	if (root != NULL)
	{
		output(root->left);

		temp.push_back(root->data);

		output(root->right);
	}
}
