/*
Завдання 1.
Дано текстовий файл з .cpp програмою. Видалити з файлу однорядкові коментарі(утворити новий файл без коментарів). 
Імена файлів передавати у програму  як  параметри командного рядка.
*/


#include "stdafx.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <cstring>

using namespace std;



int main(int argc, char ** argv)
{

	if (argc >= 2)
	{
		ifstream fileBefore; // 01_fileBefore.cpp
		ofstream fileAfter;  // 01_fileAfter.cpp
		
		fileBefore.open(argv[1], ios::out);
		fileAfter.open(argv[2], ios::in | ios::trunc);

		string str;

		if (!fileBefore.is_open())
		{
			cerr << "Error read\n";
			return 0;
		}
		else
			while (getline(fileBefore, str))
			{
				if (str == "");
				else
					for (int i = 0; i < str.length() - 1; ++i)
						if (str[i] == '/' && str[i + 1] == '/')
						{
							cout << "deleted commnet in row:\t" << str << endl;
							str.erase(i, str.length() - i);
							break;
						}

			fileAfter << str << endl;
				
			}

		fileBefore.close();
		fileAfter.close();
	}
	else
	{
		cout << "Function has " << argc << " agrument. Add 2 filename to command row\n";
	}

	
	

	cout << endl;
	system("pause");
	return 0;

}



