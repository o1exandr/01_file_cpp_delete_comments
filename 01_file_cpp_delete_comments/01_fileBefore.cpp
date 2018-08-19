
// oop14.cpp class work


#include "stdafx.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

  // printFile
void printFile(const string & fname)
{

	string str;

	ifstream outF(fname);
	if (!outF.is_open())
	{
		cerr << "Error read\n";
		return;
	}
	else
		while (getline(outF, str))
	{
			cout << str  << endl;
	}
	cout << "\t" << fname << " read\n";
	outF.close();

	
}

 // createFile
void createFile(const string & fname)
{
		ofstream inF;
		inF.open(fname);
	
		if (!inF.is_open())
		{
			cerr << "Error create\n";
			return;
		}
		else
		{

			int num;
			cout << "Enter number of row(s) ";
			cin >> num;
			cin.ignore();
			string str;


			for (int i = 0; i < num; ++i)
			{
				getline(cin, str);
				inF << str << endl;
			}
			inF.close();
			cout << "\t" << fname << " create\n";
		}


}

int main()
{

	createFile("text.txt");
	printFile("text.txt");

	cout << endl;
	system("pause");
	return 0;

}



