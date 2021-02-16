#include <iostream> //  Подключаем стандратную библиотеку 
#include <iomanip>//  Подключаем библиотеку для дополнителной работы с выводом
#include <list> //  Подключаем библиотеку для работы со списками

using namespace std;

class MyClass {
public:
	MyClass(int r, int c) {
		row = r;
		composition = c;
	}
	void Voice() {
		cout << "Строка " << row << " Произведение: " << composition << endl;
	}
private:
	int row;
	int composition;
};

int main()
{
	setlocale(LC_ALL, "Russian"); //подключим кириллицу
	const int N = 5;
	const int M = 7;
	int k[N], l[N];
	int max = 0, j = 0;

	cout << "Наша матрица" << endl;
	for (int i = 0; i < N; i++) {
		k[i] = rand() % 20 + 1; // заполняем рандомными числами
		max = k[i] > max ? i : max; //найдем наибольшее число
		//расположем в начале массива числа с нечетных позиций
		if (i % 2 == 0) {
			l[j] = k[i];
			j++;
		}
		cout << setw(4) << k[i]; // выведем элемент массива
	}
	cout << "\nНомер максимального числа: " << max << endl;

	//расположем в начале массива числа с четных позиций
	cout << "\nОбновленный массив" << endl;
	for (int i = 0; i < N; i++) {
		if (i % 2 != 0 && i > 0) {
			l[j] = k[i];
			j++;
		}
		cout << setw(4) << l[i]; // выведем обновленный массив
	}

	int mas[M][M];

	cout << "\n\nДвумерный массив" << endl;

	list<MyClass> list1;
	int first[M];
	for (int i = 0; i < M; i++) {
		bool constrol = false;
		int composition = 1;
		for (int p = 0; p < M; p++) {
			mas[i][p] = rand() % 35 - 5;
			cout << setw(4) << mas[i][p];
			composition *= mas[i][p];
			if (p == 0) first[i] = mas[i][p];
			if (mas[i][p] < 0 && !constrol) constrol = true;
		}
		if (constrol)
		{
			MyClass myClass = MyClass(i, composition);
			list1.push_back(myClass);
		}
		cout << endl;
	}

	// Сортировка массива пузырьком
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (first[j] > first[j + 1]) {
				int b = first[j]; // создали дополнительную переменную
				first[j] = first[j + 1]; // меняем местами
				first[j + 1] = b; // значения элементов
			}
		}
	}

	for (MyClass n : list1)
		n.Voice();

	cout << "\nОбновленная матрица\n";
	for (int i = 0; i < M; i++) {

		for (int p = 0; p < M; p++) {
			if (p == 0) mas[i][p] = first[i];
			cout << setw(4) << mas[i][p];
		}
		cout << endl;
	}

}
