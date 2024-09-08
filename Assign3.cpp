#include<iostream>
#include<fstream>
using namespace std;

int strlength(char arr[])
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;

}
void strcopy(char destination[], char source[])
{
	//Deep copy.
	int i = 0;
	for (; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}
char* read1D(ifstream& fin)
{
	char temp[50];
	fin.getline(temp, 50);
	int s = strlength(temp) + 1;
	char* names = new char[s];
	strcopy(names, temp);	
	return names;
}

char** read2D(ifstream& fin, int& size)
{
	fin >> size;
	if (size <= 0) {
		cout << "Error";
	}

	char temp[50];
	char** names = new char* [size];
	for (int i = 0; i < size; i++)
	{

		fin.getline(temp, 50);
		names[i] = new char[strlen(temp) + 1];
		strcopy(names[i], temp);
	}
	return names;
}
void Display(char** str, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << str[i];
		cout << endl;
	}
}

void StringConcatenate(char* &str1,char* str2)
{
	int l1 = strlength(str1);
	int l2 = strlength(str2);
	int s = l1 + l2+1 ;
	char* temp = new char[s];
	int k = 0;
	for (int i = 0; i < l1; i++)
	{
		temp[k] = str1[i];
		k++;
	}
	for (int j = 0; j < l2; j++)
	{
		temp[k] = str2[j];
		k++;
	}
	temp[k] = '\0';
	delete[]str1;
	
	str1 = temp;

}
int WordCount(char* str) 
{
	int count = 0;
	for (int i = 0;str[i]!='\0'; i++)
	{
		if (str[i] == ' ' || str[i + 1] == '\0')
		{
			count++;
		}		
	}
	return count;
}
char** StringTokens(char* str)
{
	int l = strlength(str);
	int w = WordCount(str);
	char** Toks = new char* [w];
	char temp[20];
	int k = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0;str[k]!='\0'; j++)
		{
				temp[j] = str[k];
				k++;
			
			if (str[k] == ' ')
			{
				
				temp[j + 1] = '\0';	
				k++;
				break;
			}
			
		}
		int s = strlength(temp) + 1;
		Toks[i] = new char[s];
		strcopy(Toks[i], temp);
	}
	return Toks;
}

char** InverseStringTokens(char* str)
{
	int l = strlength(str);
	int w = WordCount(str);
	char** InToks = new char* [w];
	char temp[20];
	int k = 0;
	for (int i = w-1; i >= 0; i--)
	{
		for (int j = 0; str[k] != '\0'; j++)
		{
			temp[j] = str[k];
			k++;

			if (str[k] == ' ')
			{
				temp[j + 1] = '\0';
				k++;
				break;
			}
		}
		int s = strlength(temp) + 1;
		InToks[i] = new char[s];
		strcopy(InToks[i], temp);
	}


	return InToks;

}

char* reverseSentence(char* str)
{   
	int w = WordCount(str);
	int l = strlength(str);
	int s = l + 1;
	char* rs = new char[s];
	char** temp = InverseStringTokens(str);
	int k = 0;
	for (int i = 0;i<w; i++)
	{
		for (int j = 0; temp[i][j] != '\0';j++)
		{
			rs[k] = temp[i][j];
			k++;
		}
			rs[k] = ' ';
			k++;
	}
	rs[k-1] = '\0';
	
	
	return rs;
	
}

int Compare(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1 == str2)
		{
			return 0;
		}
		i++;
	}
}

void BubbleSort(char** names,int size)
{
	int check;
	
	for (int i = 0; i < size; i++)
	{

		for (int j = i + 1; j < size; j++)
		{
			check = Compare(names[i], names[j]);
			if (check == 1)
			{
				char* temp;
				temp = names[i];
				names[i] = names[j];
				names[j] = temp;
			}
		}
	}

}

int main()
{
	ifstream fin("Data.txt");
	if (!fin)
	{
		cout << "Failed To open File\n";
	}
	else
	{
		cout << "File opened SucessFully. \n\n";
		
		char* str1;
		char* str2;

		str1 = read1D(fin);
		str2 = read1D(fin);
		cout << "Testing String Concatenate: \n\n";
		cout << "Before Concatenation: \n\n";
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		cout << endl;
		StringConcatenate(str1, str2);

		cout << "After Concatenation: \n\n";
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		cout << "___________________________________________________________________________________________________________\n";

		cout << "Testing String Token: \n\n";
		int wc = WordCount(str1);
		char** Tokens = StringTokens(str1);
		cout << "Tokens of String 1 is: \n";
		Display(Tokens, wc);

		
		cout << "___________________________________________________________________________________________________________\n";
	
		cout << "Testing Inverse String Tokens: \n\n";
		char** Intoks = InverseStringTokens(str1);
		cout << "Inverse String Tokens of string 1:  \n\n";
		Display(Intoks, wc);
		cout << "___________________________________________________________________________________________________________\n";
		cout << "Testing Reverse string. \n\n";
		char* rs = reverseSentence(str1);
		cout << "Reverse of string 1 is : \n";
		cout << rs << endl;
		
		cout << "___________________________________________________________________________________________________________\n";
		int size;
		char** names= read2D(fin, size);
		cout << "Names Before Sorting: \n\n";
		Display(names, size);
		BubbleSort(names, size);
		cout << "\n\nNames After Sorting: \n\n";
		Display(names, size);

		delete[]str1; str1 = 0;
		delete[]str2; str2 = 0;
		delete[]Tokens; Tokens = 0;
		delete[]Intoks; Intoks = 0;
		delete rs; rs = 0;
	    delete[]names; names = 0;
		
		fin.close();
	}    

	cout << endl;
	system("pause");
	return 0;
}