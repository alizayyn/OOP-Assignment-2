//This is an example of our uni poratl 
#include <iostream>
#include <fstream>
using namespace std;
class Helper
{
public:
	static int strlength(const char* str)
	{
		int count = 0;
		
		if (str == 0)
		{
			return count;
		}
		else
		{
			
			for (int i = 0; str[i] != '\0'; i++)
			{
				count++;
			}
			return count;
		}
	}
	static void StringCopy(char* dest, const char* src)
	{

		int i = 0;
		
		for (; src[i]!='\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';

	}
	static char* GetStringFromBuffer(char* str)
	{
		int l = strlength(str);
		char* String = new char[l + 1];
		StringCopy(String, str);
		return String;
	}
	static	int FirstIndexOfSubString(char* myStr, char* strToFind)
	{
		bool check = false;
		int index = 0;
		int l = strlen(myStr);
		int l2 = strlen(strToFind);

		for (int i = 0; i < l || myStr[i] != '\0'; i++)
		{
			int k = i;
			if (myStr[i] != ' ') {

				if (check != true)
				{
					for (int j = 0; j < l2; j++)
					{

						if (myStr[i] == strToFind[j])
						{
							index = k;
							check = true;
							i++;
						}
						else
						{
							check = false;
							index = -1;
							break;
						}
					}
				}
				else break;
			}
		}
		return index;
	}
	static int stringcmp(char* str1, const char* str2)
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


};

class EvaluationReport
{
 	friend void UpdateStatistics(EvaluationReport* list);
	friend EvaluationReport* ReadDataFromFile(const char* fileName);
private:
	
	char* FName;
	char* LName;
	int* QuizMarks;
	int* AssignmentsMarks;
	int TotalMarks;
	int TotalQuizzMarks;
	int TotalAssigmentsMarks;
	char RollNumber[9];

	static int TotalStudentCount;
	static int TotalNoOfQuiz;
	static int TotalNoOfAssigments;
	static int* TotalQMARKS;
	static int* TotalAMARKS;
	static int* MAX;
	static int TotalofQuiz;
	static int* MIN;
	static int TotalofAssigment;
	static int* AVG;

public:

	EvaluationReport()
	{
		RollNumber[0] = '\0';
		FName=LName = 0;
		QuizMarks = 0;
		AssignmentsMarks = 0;
		TotalMarks = 0;
		TotalAssigmentsMarks = 0;
		TotalQuizzMarks = 0;
	}
	//GETTERS
	static int GetTotalNoQuizz()
	{
		return TotalNoOfQuiz;
	}
	static int GetTotalNoAssigment()
	{
		return TotalNoOfAssigments;
	}
	
	static int GetStudents()
	{
		return TotalStudentCount;
	}

	EvaluationReport(const EvaluationReport& rhs)
 	{
		int l = Helper::strlength(rhs.FName) + 1;
		FName = new char[l];
		Helper::StringCopy(FName, rhs.FName);

		
		int l2  = Helper::strlength(rhs.LName) + 1;
		LName = new char[l2];
		Helper::StringCopy(LName, rhs.LName);

		QuizMarks = new int[TotalNoOfQuiz];
		for (int i = 0; i < TotalNoOfQuiz; i++)
		{
			QuizMarks[i] = rhs.QuizMarks[i];           //deep copying quiz marks
		}


		AssignmentsMarks = new int[TotalNoOfAssigments];
		for (int i = 0; i < TotalNoOfAssigments; i++)                 //deep coping Assignment marks
		{
			AssignmentsMarks[i] = rhs.AssignmentsMarks[i];
		}


		TotalMarks = rhs.TotalMarks;

		Helper::StringCopy(RollNumber, rhs.RollNumber); //deep copy roll no
	}
	const EvaluationReport& operator=(const EvaluationReport& rhs)
	{
		int l1 = Helper::strlength(FName);
		int l2 = Helper::strlength(rhs.FName);
		if (l1 != l2)
		{
			if (FName)
			{
				delete[] FName;
			}
			FName = new char[l2 + 1];
		}
		Helper::StringCopy(FName, rhs.FName);

		int l3 = Helper::strlength(LName);
		 int l4 = Helper::strlength(rhs.LName);
		if (l3 != l4)
		{
			if (LName)
			{
				delete[] LName;
			}
			LName = new char[l4 + 1];
		}
		Helper::StringCopy(LName, rhs.LName);

		TotalMarks = rhs.TotalMarks;
		Helper::StringCopy(RollNumber, rhs.RollNumber);


		if (QuizMarks == 0)
			QuizMarks = new int[TotalNoOfQuiz];

		for (int i = 0; i < TotalNoOfQuiz; i++)
		{
			QuizMarks[i] = rhs.QuizMarks[i];
		}
		if (AssignmentsMarks == 0)
			AssignmentsMarks = new int[TotalNoOfAssigments];

		for (int i = 0; i < TotalNoOfAssigments; i++)
		{
			AssignmentsMarks[i] = rhs.AssignmentsMarks[i];
		}
		return *this;
	}

	bool operator <(const EvaluationReport& rhs)
	{
		if (TotalMarks < rhs.TotalMarks)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ReadDataFromFile(ifstream& fin)
	{
		char Buffer[50];
		fin >> RollNumber;
		fin >> Buffer;
		FName = Helper::GetStringFromBuffer(Buffer);
		fin >> Buffer;
		LName = Helper::GetStringFromBuffer(Buffer);
		QuizMarks = new int[TotalNoOfQuiz];
		
		for (int i = 0; i < TotalNoOfQuiz; i++)
		{
	    		fin >> QuizMarks[i];
				TotalQuizzMarks = TotalQuizzMarks + QuizMarks[i];
				TotalMarks = TotalMarks + QuizMarks[i];
				
		}
		AssignmentsMarks = new int[TotalNoOfAssigments];
		for (int i = 0; i < TotalNoOfAssigments; i++)
	    {
		    	fin >> AssignmentsMarks[i];
				TotalAssigmentsMarks = TotalAssigmentsMarks + AssignmentsMarks[i];
				TotalMarks = TotalMarks + AssignmentsMarks[i];
    	}
	}
	static void PrintStatistics()
	{
		
		int TotalOfQuizAndAssign = TotalNoOfAssigments + TotalNoOfQuiz;
		cout << "\t\t";
		for (int i = 0; i < TotalNoOfQuiz; i++)
		{
			cout << "Q" << i + 1 << "\t";
		}
		for (int i = 0; i < TotalNoOfAssigments; i++)
		{
			cout << "A" << i + 1 << "\t";
		}
		cout << "\nTotal:" << "\t\t";
		for ( int i = 0;  i < TotalNoOfQuiz;  i++)
	    {
			 cout << TotalQMARKS[i] << "\t";
		}
		for (int i = 0; i < TotalNoOfAssigments; i++)
		{
			cout << TotalAMARKS[i] << "\t";
		}
		cout << "\nMaximum:" << "\t";
		for (int i = 0; i < TotalOfQuizAndAssign; i++)
		 {
			 cout << MAX[i] << "\t";
		 }
		cout << "\nMinimum:" << "\t";
		 for (int i = 0; i < TotalOfQuizAndAssign; i++)
		 {
			 cout << MIN[i] << "\t";
		 }
		cout << "\nAverage:" << "\t";
		for (int i = 0; i < TotalOfQuizAndAssign; i++)
		{
			cout << AVG[i] << "\t";
		}

	}

	static void DeleteStatic()
	{
		delete[] TotalQMARKS;
		delete[] TotalAMARKS;
		delete[] MAX;
		delete[] MIN;
		delete[] AVG;
	}

	void PrintListView()
	{
		cout << RollNumber << "\t" << FName << " " << LName << "\t";
		for (int i = 0; i < TotalNoOfQuiz; i++)
		{
			cout << QuizMarks[i] << "\t";
		}
		for (int i = 0; i < TotalNoOfAssigments; i++)
		{
			cout << AssignmentsMarks[i] << "\t";
		}
		cout << TotalMarks << endl;
	}

	bool CheckSearchStudentByKeyWord(char* temp)
	{
		if (Helper::FirstIndexOfSubString(RollNumber, temp) != -1)
		{
			return true;
		}
		else if (Helper::FirstIndexOfSubString(FName, temp) != -1)
		{
			return true;
		}
		else if (Helper::FirstIndexOfSubString(LName, temp) != -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PrintDetailView()
	{
		cout << "Roll No: " << RollNumber << endl;
		cout << "Name: " << FName << " " << LName << endl << endl;
		cout << "QuizzNO.\tObtained Marks\t   Total Marks\t     Average\t     Minimum\t     Maximum\t" << endl;
		int k = 0;
		for (int i = 0; i < TotalNoOfQuiz; i++,k++)
		{
			cout << i + 1 << "\t\t\t" << QuizMarks[i] << "\t\t" << TotalQMARKS[i] << "\t\t" << AVG[k] << "\t\t"<< MIN[k] << "\t\t" << MAX[k]<<endl;
		}
		cout << "_________________________________________________________________________________________________";
		cout << "\nTotal\t\t\t" << TotalQuizzMarks << "\t\t" << TotalofQuiz << endl<<endl;

		cout << "AssigmentNO.\tObtained Marks\t    Total Marks\t      Average\t     Minimum\t      Maximum" << endl;
		for (int i = 0; i < TotalNoOfAssigments; i++,k++)
		{
			cout << i + 1 << "\t\t\t" << AssignmentsMarks[i] << "\t\t" << TotalAMARKS[i] << "\t\t" << AVG[k] << "\t\t" << MIN[k] << "\t\t" << MAX[k] << endl;
		}
		cout << "_________________________________________________________________________________________________";
		cout << "\nTotal\t\t\t" << TotalAssigmentsMarks << "\t\t" << TotalofAssigment << endl;
	}

	bool SearchStudentByRollNo(const char* RollToFind)
	{
		if (Helper::stringcmp(RollNumber, RollToFind) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	~EvaluationReport()
	{
		delete[] AssignmentsMarks;
		delete[] QuizMarks;
		delete[] FName;
		delete[] LName;
	}
};

int EvaluationReport::TotalStudentCount = 0;
int EvaluationReport::TotalNoOfQuiz = 0;
int EvaluationReport::TotalofQuiz = 0;
int* EvaluationReport::TotalQMARKS = 0;
int* EvaluationReport::TotalAMARKS = 0;
int* EvaluationReport::MAX = 0;
int* EvaluationReport::MIN = 0;
int* EvaluationReport::AVG = 0;
int EvaluationReport::TotalNoOfAssigments = 0;
int EvaluationReport::TotalofAssigment = 0;

EvaluationReport* ReadDataFromFile(const char* fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		cout << "file is not open";
		return 0;
	}
	
	else 
	{
		fin >> EvaluationReport::TotalStudentCount;
		fin >> EvaluationReport::TotalNoOfQuiz;
		fin >> EvaluationReport::TotalNoOfAssigments;
		EvaluationReport::TotalQMARKS = new int[EvaluationReport::TotalNoOfQuiz];
		for (int i = 0; i < EvaluationReport::TotalNoOfQuiz; i++)
		{
			fin >> EvaluationReport::TotalQMARKS[i];
			EvaluationReport::TotalofQuiz = EvaluationReport::TotalofQuiz + EvaluationReport::TotalQMARKS[i];
		}
		EvaluationReport::TotalAMARKS = new int[EvaluationReport::TotalNoOfAssigments];
		for (int i = 0; i < EvaluationReport::TotalNoOfAssigments; i++)
		{
			fin >> EvaluationReport::TotalAMARKS[i];
			EvaluationReport::TotalofAssigment = EvaluationReport::TotalofAssigment + EvaluationReport::TotalAMARKS[i];
		}
		EvaluationReport* list = new EvaluationReport[EvaluationReport::TotalStudentCount];
		for (int i = 0; i < EvaluationReport::TotalStudentCount; i++)
		{
			list[i].ReadDataFromFile(fin);
		}
		fin.close();
		return list;
	}
}
void UpdateStatistics(EvaluationReport* list)
{
	
	int studentsCount = EvaluationReport::TotalStudentCount;
	int QuizCount = EvaluationReport::TotalNoOfQuiz;
	int AssignCount = EvaluationReport::TotalNoOfAssigments;
	
	int totalofQandA = QuizCount + AssignCount;
	EvaluationReport::MAX= new int[totalofQandA];
	EvaluationReport::MIN = new int[totalofQandA];
	EvaluationReport::AVG = new int[totalofQandA];
	int min = 10000000;
	int max = -9999999;
	int temp;
	int totalMarks;
	int k = 0;
	for (int i = 0; i < QuizCount; i++)
	{
		totalMarks = 0;
		min = 10000000;
		max = -9999999;
		for (int j = 0; j < studentsCount; j++)
		{
			temp = list[j].QuizMarks[i];
			if (min > temp)
			{
				min = temp;
			}

			if (max < temp)
			{
				max = temp;
			}
			totalMarks = totalMarks + temp;
		}
		EvaluationReport::MAX[k] = max;
		EvaluationReport::MIN[k] = min;
		EvaluationReport::AVG[k] = totalMarks / studentsCount;
		k++;
	}

	for (int i = 0; i < AssignCount; i++)
	{
		totalMarks = 0;
		min = 100000000;
		max = -9999999;
		for (int j = 0; j < studentsCount; j++)
		{
			temp = list[j].AssignmentsMarks[i];
			if (min > temp)
			{
				min = temp;
			}

			if (max < temp)
			{
				max = temp;
			}
			totalMarks += temp;
		}

		EvaluationReport::MAX[k] = max;
		EvaluationReport::MIN[k] = min;
		EvaluationReport::AVG[k] = totalMarks / studentsCount;
		k++;
	}
}
void PrintAll(EvaluationReport* list)
{
	int studentsCont = EvaluationReport::GetStudents();
	int TQuiz = EvaluationReport::GetTotalNoQuizz();
	int TAssigments = EvaluationReport::GetTotalNoAssigment();
	cout << "Roll No." << "\t" << "Name\t\t";
	for (int i = 0; i < TQuiz; i++)
	{
		cout << "Q" << i + 1 << "\t";
	}
	for (int i = 0; i < TAssigments; i++)
	{
		cout << "A" << i + 1 << "\t";
	}
	cout << "Total" << endl;

	for (int i = 0; i < studentsCont; i++)
	{
		list[i].PrintListView();
	}

}
EvaluationReport** SearchStudentsByKeyWord(char* search, EvaluationReport* list, int& size)
{
	EvaluationReport** ER;
	
	int studentsCount = EvaluationReport::GetStudents();
	for (int i = 0; i < studentsCount; i++)
	{
		if (list[i].CheckSearchStudentByKeyWord(search))
		{
			size++;                                              //counts the no of students found 
		}
	}
	ER = new EvaluationReport * [size];
	int k = 0;
	for (int i = 0; i < studentsCount; i++)
	{
		if (list[i].CheckSearchStudentByKeyWord(search))
		{
			ER[k++] = &list[i];                 //stores the address of the list pointer
		}
	}
	return ER;
}
void PrintAll(EvaluationReport** EvalReport, int size)
{
	int Noofquiz = EvaluationReport::GetTotalNoQuizz();
	int NoofAssignments = EvaluationReport::GetTotalNoAssigment();
	cout << "RollNo.\t          Name\t\t";
	for (int i = 0; i < Noofquiz; i++)
	{
		cout << "Q" << i + 1 << "\t";
	}
	for (int i = 0; i < NoofAssignments; i++)
	{
		cout << "A" << i + 1 << "\t";
	}
	cout << "Total" << endl;

	for (int i = 0; i < size; i++)
	{
		EvalReport[i]->PrintListView();
	}
}
void SortListByTotal(EvaluationReport* list)
{
	int studentsCount = EvaluationReport::GetStudents();

	for (int i = 0; i < studentsCount; i++)
	{
		for (int j = i+1; j < studentsCount; j++)
		{
			if (list[i] < list[j])    //using overloaded function for checking the total. 
			{
				EvaluationReport temp = list[i];
				list[i] = list[j];
				list[j] = temp;

				/*EvaluationReport temp;
				temp=list[i];
				list[i] = list[j];
				list[j] = temp;*/
			}
		}
	}
}
EvaluationReport* SearchStudentByRollNo(EvaluationReport* list, const char* RollNo)
{
	int students = EvaluationReport::GetStudents();
	for (int i = 0; i < students; i++)
	{
		if (list[i].SearchStudentByRollNo(RollNo))
		{
			return &list[i];//returns the pointer of the searched RollNO.
			break;
		}
	}
	return 0;
}
int  main()
{

	 EvaluationReport* list = ReadDataFromFile("gradesheet.txt");
	UpdateStatistics(list);
	cout << "STATISTICS: \n";
	EvaluationReport::PrintStatistics();
	cout << "\n_____________________________________________________________________________________________________________________\n\n";
	cout << "STUDENTS LIST: \n\n";
	PrintAll(list);//prints the list of students
	cout << "\n_____________________________________________________________________________________________________________________\n\n";
	cout << "SEARCHED :\n\n";
	char temp[]="43";
	cout << "Enter Word to be searched Search :  ";
	cout << temp << endl;
	/*cin.getline(temp, 80);*/
	int s = 0;
	EvaluationReport** evaluationReport = SearchStudentsByKeyWord(temp, list, s);
	PrintAll(evaluationReport, s);
	cout << "\n_________________________________________________________________________________________________________________\n\n" ;
	cout << "__________________________________________________SORTED LIST________________________________________________________\n\n";
	SortListByTotal(list);
	PrintAll(list);
	cout << "\n____________________________________________________________________________________________________________________\n\n";
	cout << "_____________________________________________________SEARCHED BY ROLL NO_______________________________________________\n\n";
	char RollNo1[9] = "15L-1234";
	EvaluationReport* Search= SearchStudentByRollNo(list, RollNo1);
	cout << "\nSearched Roll Number:  "<<RollNo1<<endl;
	
	if (Search)
		Search->PrintDetailView();
	else
		cout << "No student of such Roll No. found" << endl;
	cout << "\n________________________________________________________________________________________________________________\n\n";
	cout << "_____________________________________________________SEARCHED BY ROLL NO__________________________________________\n\n";
	char RollNo2[9] = "15L-4023";
	Search = SearchStudentByRollNo(list, RollNo2);
	cout << "\nSearched Roll Number:   " << RollNo2 << endl;
	if (Search)
	{
			Search->PrintDetailView();
    }
   else
   {
		cout << "No student of such Roll No. found" << endl;
   }
	//DEALOCATIONS
	EvaluationReport::DeleteStatic(); //deleting static members
	delete[] evaluationReport;//deleting the 2d array;
	delete[] list;//deleting the list of students;
	system("pause");
	return 0;
}