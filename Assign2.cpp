
/* Roll NO. 22L - 6551
   Name : Ali Zain
   BS CS 2D
   Assignment 2.*/

#include<iostream>
#include<fstream>


using namespace std;

int** InputMatrix(ifstream& fin, int& rows, int& cols)
{
	fin >> rows;                  //taking input of rows.
		if (rows < 0) 
		{
			cout << "Error the no. of rows is negative. ";
			return 0;
		}
	fin >> cols;                 //taking input of coloumns.
		if (cols < 0) 
		{
			cout << "Error the no. of cols is negative. ";
			return 0;
		}
	
	int** matrix = new int* [rows];     //creating a doubble pointer to point the 2d array
	for (int i = 0; i < rows; i++) 
	{
			*(matrix+i) = new int[cols];
	}
	
	int** r = matrix + rows;
	for (int** tempi = matrix; tempi < r; tempi++)            
	{         
		int* c = *tempi + cols;
		for (int* tempj = *tempi; tempj < c; tempj++)
		{
			fin >> *tempj;           //loop for  reading the inputs of the 2d array from the file.
		}
	}
	return matrix;
}

void OutputMatrix(int** matrix,const int& rows,const int& cols) 
{
	if (rows && cols > 0) 
	{
		int** r = matrix + rows;
		for (int** tempi = matrix; tempi < r; tempi++)
		{
			int* c = *tempi + cols;
			for (int* tempj = *tempi; tempj < c; tempj++)
			{
				cout<< *tempj<<" ";                     //ouputting the matrix
			}
			cout << endl;
		}
		cout << endl;
	}
	else {
		cout << "\nError rows or cols are negative \n";
	}
}

int** AddMatrix(int** matrixA, int** matrixB, const int& rows,const int& cols) {
	

		int** sum = 0;
		sum = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			*(sum+i) = new int[cols];
		}
		int** r = sum + rows;
		int** tempA = matrixA;
		int** tempB = matrixB;
		
		for (int** tempi = sum; tempi < r; tempi++, tempA++, tempB++)
		{
			int* c = *tempi + cols;
			int* a = *tempA;
			int* b = *tempB;
			for (int* tempj = *tempi; tempj < c; tempj++, a++, b++ )
			{
				*tempj= *a + *b;   //the elements at i and j of sum are equal to the sum of matices A and B
			}
		}
		
		return sum;

}

int** TransposeMatrix(int** matrix, const int& rows, const int& cols)
{
	int** Transpose = new int* [cols];
	for (int i = 0; i < cols; i++) 
	{
		*(Transpose+i) = new int[rows];
	}
	
	
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				*(*(Transpose+j)+i) = *(*(matrix+i)+j);        

			}
		}
		
	return Transpose;

}
bool IsSymmetric(int** matrix,const int& rows, const int& cols)
{
	bool checkSymmetry = false;
	if (rows != cols)
	{
		return checkSymmetry;
	}
	else 
	{
		int** Transpose = TransposeMatrix(matrix, rows, cols);     //getting transpose
		int** trans = Transpose;
		int** r = Transpose + rows;
	   for (int** tempi = Transpose,**tempmat=matrix; tempi <r; tempi++,trans++,tempmat++)
	   {
		   int* c = *tempi+cols;
		   int* tran = *trans;
		   
		   for (int* tempj = *tempi, *mat = *tempmat; tempj < c; tempj++,tran++,mat++)
		   {
			  if(*mat!=*tempj)
			  {
				   checkSymmetry = false;                 //if one of the elements of the array is not equal to the transpose break the loop and return false.
				   break;
			  }
			  else 
			  {
				  checkSymmetry = true;
			  }
		   }
	   }
	   for (int i = 0; i < rows; i++)
	   {        //deleting to clear the memory;
		   delete[]*(Transpose+i);
	   }
	   delete Transpose;
	   Transpose = 0;
	}
	
	return checkSymmetry;    //returns '1' or '0'.
}

void InterchangeRows(int* &row1, int* &row2)
{
	//swaping the pointers that are pointing to the rows. 
	int* temp =row1;                  
     row1= row2;
	row2 = temp;
	
}

void InterchangeRows(int** matrix,const int& rows, const int cols)
{
	int row1=1, row2=3;

	cout << endl;
	cout << "ROW 1: " << row1 << endl;
	cout << "ROW 2: "<<row2<<endl;

		InterchangeRows(*(matrix + (row1-1)), *(matrix+(row2-1)));         	//giving the parameters the pointer of the first element of the rows and subtracting 1 as the indexing starts with "0".        
		
		cout << "The interchanged Matrix is : \n";                              
		OutputMatrix(matrix, rows, cols);
		
		
}

int main() 
{
	ifstream fin("InputFile.txt");

	if (!fin.is_open())
	{
		cout << "FAILED TO OPEN FILE\n";
	}
	else {
		cout << "FILE OPENED SUCESSFULLY!\n";
		//initializing
		int rows1=0;
		int cols1=0;
		int rows2 = 0;
		int cols2 = 0;
		int rows3 = 0;
		int cols3 = 0;
		int** matrix1=0;
		int** matrix2=0;
		int** matrix3=0;
		int** Sum=0;
		int** Transpose = 0;
		bool symmetry1;
		bool symmetry2;
		bool symmetry3;
        
		//Matrix1
		matrix1= InputMatrix(fin, rows1, cols1);
		cout << "Matrix 1: \n";
		OutputMatrix(matrix1, rows1, cols1);
		
		//Matrix2
		matrix2 = InputMatrix(fin, rows2, cols2);
		cout << "Matrix 2: \n";
		OutputMatrix(matrix2, rows2, cols2);
		
		//Matrix3
		matrix3 = InputMatrix(fin, rows3, cols3);
		cout << "Matrix 3: \n";
		OutputMatrix(matrix3, rows3, cols3);
		
		//Adding matrix 1 and 2.
		if (rows1 == rows2 && cols1 == cols2)
		{
			Sum=AddMatrix(matrix1, matrix2, rows1, cols1);

			cout << "Matrix 1 + Matrix 2: \n";
			OutputMatrix( Sum , rows1, cols1);
		}
		else
		{
			cout << "Addition is not possible\n\n";
		}
		delete[]Sum;
		Sum = 0;
		
		//Adding Matrix 1 and Matrix 3.
		if (rows1 == rows3 && cols1 == cols3) {
			Sum = AddMatrix(matrix1, matrix3, rows1, cols1);
			cout << "Matrix 1 + Matrix 3: \n";
			OutputMatrix(Sum, rows1, cols1);
		}
		else
		{
			cout << "Matrix 1 + Matrix 3: \nAddition is not possible\n\n";
		}
		delete[]Sum;
		Sum = 0;

		//Transpose of Matrix 1.
			Transpose = TransposeMatrix(matrix1, rows1, cols1);
			cout << "\nThe transpose of Matrix 1 is : \n";
			OutputMatrix(Transpose, cols1,rows1);
			cout << endl;
		
		delete[]Transpose;
		Transpose = 0;

		//Transpose of matrix 3.
			Transpose = TransposeMatrix(matrix3, rows3, cols3);
			cout << "\nThe transpose of Matrix 3 is : \n";
			OutputMatrix(Transpose,cols3 , rows3);
		delete[]Transpose;
		Transpose = 0;

		//Checking the Symmetry of Matrix 1.
		symmetry1 = IsSymmetric(matrix1, rows1, cols1);
		if (symmetry1) 
		{
			cout << "Matrix 1 is Symmetric.\n";
		}
		else
		{
			cout << "Matrix 1 is not Symmetric.\n";
		}

		//Checking the Symmetry of Matrix 2.
		symmetry2 = IsSymmetric(matrix2, rows2, cols2);
		if (symmetry2)
		{
			cout << "Matrix 2 is Symmetric.\n";
		}
		else
		{
			cout << "Matrix 2 is not Symmetric.\n";
		}

		//Checking the Symmetry of Matrix 3.
		symmetry3 = IsSymmetric(matrix3, rows3, cols3);
		if (symmetry3)
		{
			cout << "Matrix 3 is Symmetric.\n";
		}
		else 
		{
			cout << "Matrix 3 is not Symmetric.\n";
		}

		//InterChanging the Entered row or coloumn of the Matrix1.
			InterchangeRows(matrix1, rows1, cols1);
			cout << endl;

			
			//Deleting The Matices.
		for (int i = 0; i < rows1; i++) {
			delete[]*(matrix1+i);
		}
		delete[]matrix1;
		matrix1 = 0;
		for (int i = 0; i < rows2; i++) {
			delete[] * (matrix2 + i);
		}
		delete[]matrix2;
		matrix2 = 0;
		for (int i = 0; i < rows3; i++) {
			delete[] * (matrix3 + i);
		}
		delete[]matrix3;
		matrix3 = 0;
		fin.close();
		cout << endl;
		
	}
	system("pause");
	return 0;
}
