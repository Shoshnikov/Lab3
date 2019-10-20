#include <iostream>
#include <locale.h>

using namespace std;

int CorrectInput(int& value);

void PrintMatrix(int n, int m, int matrix[100][50]);

void Sort(int n, int m, int matrix[100][50]);

void Switch(int m, int matrix[100][50], int rowNumber);

int main()
{
	int matrix[100][50];
	int n, m;
	setlocale(LC_ALL,"RUS");
	cout << "Введите количество строк и столбцов через пробел\n";
	cin >> n >> m;
	cout << "Вводите числа...\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			CorrectInput(matrix[i][j]);
	PrintMatrix(n, m, matrix);
	Sort(n, m, matrix);
	PrintMatrix(n, m, matrix);
}

int CorrectInput(int& value)
{
	char fail;
	cin >> value;
	while (cin.fail())
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}

void PrintMatrix(int n, int m, int matrix[100][50])
{
	for (int i = 0; i < n; i++) 
	{
		cout << endl;
		for (int j = 0; j < m; j++)
			cout << matrix[i][j]<< "\t";
	}
	cout << endl;
}

void Sort(int n, int m, int matrix[100][50]) 
{
	for(int k = 0; k < n; k++)
	for (int i = 1; i < n && matrix[i][m - 1] < matrix[i - 1][m - 1]; i++)
			Switch(m, matrix, i);
}

void Switch(int m, int matrix[100][50], int rowNumber) 
{
	int temp;
	for (int j = 0; j < m; j++) 
	{
		temp = matrix[rowNumber][j];
		matrix[rowNumber][j] = matrix[rowNumber - 1][j];
		matrix[rowNumber - 1][j] = temp;
	}
}