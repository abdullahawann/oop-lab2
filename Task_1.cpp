#include <iostream>
using namespace std;

// a.
int** AllocateMemory(int& rows, int& cols)
{
	int** arr = new int*[rows];

	for (int i=0; i<rows; i++)

	{
		arr[i] = new int[cols];
	}

	return arr;
}

// b.
void InputMatrix(int** matrix, const int rows, const int cols)
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			cout << "Enter the values at " << i << j << " index : ";
			cin >> matrix[i][j];
		}
	}
	cout << endl;
}

// c.
void DisplayMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << "The matrix is : " << endl;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// d.
int* maxCol(int** matrix, int rows, int cols)
{
	int* maxcolarr = new int[cols];
	int maxvalue;

	for (int i=0; i<cols; i++)
	{
		maxvalue = 0;
		for (int j=0; j<rows; j++)
		{
			if (maxvalue <= *(*(matrix + j) + i))
			{
				maxvalue = *(*(matrix + j) + i);
			}
			maxcolarr[i] = maxvalue;
		}
	}

	return maxcolarr;
}

// e.
void DeallocateMemory(int** matrix, const int& rows)
{

	for (int i=0; i<rows; i++)
	{
		delete []matrix[i];
		matrix[i] = NULL;
	}

	delete []matrix;
	matrix = NULL;
}

void main()
{
    int rows, cols; 
	cout << "Enter the number of rows : ";
	cin >> rows;
	cout << "Enter the number of columns : ";
	cin >> cols;

    int** matrix = AllocateMemory(rows, cols);

    InputMatrix(matrix, rows, cols);                      // this will take the input from the user.

    DisplayMatrix(matrix, rows, cols);                    // this will display the matrix.

    int* maxColValues = maxCol(matrix, rows, cols);

	cout << "Array containing maximum elements of all the columns is : ";
	cout << "{ ";
    for(int i=0; i<cols; i++)
	{
	    cout << *(maxColValues + i) << " , ";
	}
	cout << "}";
    cout << endl;

	DeallocateMemory(matrix, rows);                      // for deallocating matrix

	delete maxColValues;                                 // for deleting maxColValues;
	maxColValues = NULL;                               

	system("pause");
}

