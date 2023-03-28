// memory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

int menu()
{
	int size;
	system("cls");
	cout << "Компьютерная игра ПАМЯТЬ" << endl;
	cout << "========================" << endl;
	cout << "1 - Начать игру" << endl;
	cout << "2 - Выход" << endl;
	char key = _getch();
	if (key == '1') {
		do {
			system("cls");
			cout << "Введите размер поля ";
			cin >> size;
		} while (size>10 || size<0 || (size%2)!=0);
		system("cls");
	};
	if (key == '2') exit;
	return size;
}

int checkXY(int** arr, int&size, int& x, int& y)
{
	int c=0;
	for (size_t i = 0; i < size * size; i++)
	{
		if ((arr[0][i] == x) && (arr[1][i] == y)) {
			c = 1; return c;
		}
	}
	return c;
}

int checkVal(int*& arr, int& size, int& val)
{
	int c = 0;
	for (size_t i = 0; i < size*size/2; i++)
	{
		if(arr[i]==val) {
			c = 1; return c;
		}
	}
	return c;

}

void printArr(int** arr, int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl<< endl;
	}
}

void fillArr1(int**arr, int&size)
{
	int x,y,val;
	int count = 0;
// временный массив для координат
	int** temp = new int* [2];
	for (size_t i = 0; i < 2; i++)
	{
		temp[i] = new int[size * size];
	}
// временный массив для значений
	int* temp1 = new int[size*size/2];
// цикл по всем значениям/2
	for (size_t i = 0; i < size*size/2; i++)
	{
//вычисляем значение и проверяем что такого еще не было
		int flag = 1;
		while (flag == 1)
		{
			val = 10 + rand() % 70;
			flag = checkVal(temp1, size, val);
		}
// вычисляем 2 пары координат значения и проверяем, что таких координат еще не было
		for (size_t j = 0; j < 2; j++)
		{

			int flag = 1;
			while (flag == 1)
			{
				x = rand() % size;
				y = rand() % size;
				flag = checkXY(temp, size, x, y);
			}
			temp[0][count] = x;
			temp[1][count] = y;
			count++;
			arr[x][y] = val;
		}
	}
	delete[]temp;
}

void fillArr2(int** arr, int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}
}

int game1(int** arr1, int** arr2, int& size, int& Score1, int& Score2, string& p)
{
	char key;
	int x = 0, y = 0;
	arr2[x][y] = 1;
	printArr(arr2, size);
	cout << "ОЧКИ ИГРОК 1" << Score1 << "      ОЧКИ ИГРОК 2 " << Score2;
	cout << endl << endl;
	cout << "Играет " << p << endl;
	cout << "Двигая курсор (WASD) выберите первую цифру и нажмите E" << endl;
	key = _getch();
	if ((key=='w'||key=='W')&&(y!=0)) {}

}

void game(int** arr1, int** arr2, int& size)
{
	cout << "ВНИМАНИЕ!!!" << endl;
	cout << "Приготовьтесь запомнить массив цифр" << endl;
	cout << "Массив будет показан на 10 секунд" << endl;
	cout << "Для продолжения нажмите любую клавишу";
	_getch();
	system("cls");
	printArr(arr1, size);
	Sleep(10000);
	int Game = 1;
	int Score1 = 0;
	int Score2 = 0;
	while (Game)
	{
		string p1 = "ИГРОК 1";
		string p2 = "ИГРОК 2";
		Score1 = game1(arr1, arr2, size,Score1, Score2, p1)

	}

}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int size = menu();
	int** arr1 = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		arr1[i] = new int[size];
	}
	int** arr2 = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		arr2[i] = new int[size];
	}
	fillArr1(arr1, size);
	fillArr2(arr2, size);
	game(arr1, arr2, size);
	printArr(arr2, size);


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
