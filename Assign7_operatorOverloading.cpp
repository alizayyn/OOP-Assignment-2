#include<iostream>
using namespace std;
class MyString
{
	friend ostream& operator << (ostream&, const MyString&);
	friend istream& operator >> (istream&, MyString&);
private:
	char* str;
	int length;
	//not including the null char here
	//Add GetStringFromBuffer as static private member (helper)
	//Add Concatenate, CompareString as static private member (helper)
	//You can add your class members here
	static int strlength(char* str)
	{
		int count = 0;
		for (int i = 0; i < str[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	static void strcopy(char*& dest, char* src)
	{
		int i = 0;
		for (; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';

	}

	static void strnconcat(char*& arr, char* arr1)
	{
		int s1, s2, k = 0;

		s1 = strlength(arr);
		s2 = strlength(arr1);
		char* str = new char[s1 + s2 + 1];
		for (int i = 0; i < s1; i++)
		{
			str[k] = arr[i];
			k++;
		}

		for (int i = 0; i < s2; i++)
		{
			str[k] = arr1[i];
			k++;
		}
		str[k] = '\0';
		delete[]arr;
		arr = str;
	}
static int Compare(char* str1, char* str2)
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

public:

	//-------------DO_NOT_CHANGE REGION starts below---------------------
	//Do not change the prototypes given below

	MyString()
	{
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
	MyString(const MyString& rhs)
	{
		length = rhs.length;
		str = new char[length + 1];
		
		strcopy(str, rhs.str);
	}
    ~MyString()
	{
		if(str!=0)
		delete[]str;
	}
	MyString operator+(const MyString &rhs)
	{
		MyString temp;
		temp.length =strlength(str) + strlength(rhs.str);
		temp.str = new char[temp.length];
		strcopy(temp.str, str);
		strnconcat(temp.str, rhs.str);
		
		return temp;
	}

	MyString& operator=(const MyString& rhs)
	{	
		if (this == &rhs)
		{
			return *this;
		}
		else 
		{
			length = strlength(rhs.str);
			str = new char[length + 1];
			strcopy(str, rhs.str);
		}
		
		return *this;
	}



	bool operator<(MyString rhs) //Comparison on the basis of ascii values
	{
		int check;
		check=Compare(str, rhs.str);
		if (check == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	

	bool operator!()
	{
		if (length == 0)
		{
				return true;
		}
		else
		{
			return false;
		}
	}

	char& operator[](int index)
	{
		int l =strlength(this->str);
	    if (index >= l || index < 0)
		{
			throw exception("index is out of range for the string.");
		}
	    else if (index < l)
		{
			return str[index];
		}
		
	}
	
	MyString operator()(int s,int e)
	{
		int l = strlength(this->str);
		if (l < s||s<0||e<0)
		{
			throw exception("index is out of range for the string.");
		}
			MyString temp;
			temp.str = new char[e + 1];
			int k = 0;
			for (int i = s; i < e + s; i++)
			{
				temp.str[k] = this->str[i];
				k++;
			}
			temp.str[k] = '\0';
			return temp;
	}

};

ostream& operator<<(ostream& out, const MyString& obj)
{
	if (obj.str != 0)
		out << obj.str;
	return out;	// to enable cascading
}


istream& operator>>(istream& in, MyString& obj)
{
	if (obj.str == 0)
	{
		  char temp[80];
		  in >> temp;
		 int l = MyString::strlength(temp);
		obj.str = new char[l+1];
		MyString::strcopy(obj.str, temp);
	}
	else
	{
		delete[]obj.str;
		char temp[80];
		in >> temp;
		int l = MyString::strlength(temp);
		obj.str = new char[l+1];
		MyString::strcopy(obj.str, temp);
	}
	return in;	// to enable cascading
}


//-------------DO_NOT_CHANGE REGION starts below---------------------
void main()
{
	MyString str1, str2, str3, str4;	//Default constructor will make a string of lenght 0 but having null character (only) i.e. empty string

	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;


	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;

	////What is following code testing?
	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;


	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	str4 = str3= str1 + str2;
	
	
		cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
		cout << "str1 = " << str1 << endl;
		cout << "str2 = " << str2 << endl;
		cout << "str3 = " << str3 << endl;
		cout << "str4 = " << str4 << endl;
	
		cout << "\n\n\nEnter String 3:\t";
		cin >> str3;
	
		cout << "\n\n\nEnter String 4:\t";
		cin >> str4;
	
	
		cout << "\n\n\nstr3 = " << str3 << endl;
		cout << "str4 = " << str4 << endl;
	
		if (str3 < str4)
			cout << "String 3 is Less than String 4.\n";
		else
			cout << "String 3 is NOT Less than String 4.\n";
	
		MyString str5 = str1 + str2;
		cout << "\n\n\nStr5:\t" << str5 << endl;
		cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
	  	str5[7] = '$';
	  
	  	cout << "\n\nStr5:\t" << str5 << endl;
	  
	  	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 . Function Call str5.operator()(5,10) Let the returned MyString or char* leak
	  
 }
	//-------------End of DO_NOT_CHANGE REGION---------------------
