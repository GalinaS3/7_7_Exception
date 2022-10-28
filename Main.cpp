#include<ctime>
#include<cassert>
#include"IntegerArrey.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	srand(time(NULL));
	int size = 11;
	int new_size = 19;

	try
	{
		IntegerArray a(size);

		cout << "Razmer massiva - " << a.IntArreySize() << " byte" << endl;
		cout << endl;

		for (int i = 0; i < size; ++i)//задаем массив длинны size
		{
			a[i] = rand() % 20;
		}

		for (int i = 0; i < size; ++i)//выводим в консоль
		{
			cout << a[i] << '\t';
		}
		cout << endl;

		a.resize(new_size);	//меняем размер
		for (int i = 0; i < new_size; ++i)//выводим в консоль
		{
			cout << a[i] << '\t';
		}
		cout << endl;

		a.insert(100, 0);//вставляем значение в начало		
		for (int i = 0; i < new_size + 1; ++i)//выводим в консоль
		{
			cout << a[i] << '\t';
		}
		cout << endl;

		int x = a.getDlina();
		a.insert(200, x);//вставляем значение в конец
		for (int i = 0; i < x + 1; ++i)//выводим в консоль
		{
			cout << a[i] << '\t';
		}
		cout << endl;

		a.remove(8);//удаляем элемент
		for (int i = 0; i < a.getDlina(); ++i)//выводим в консоль
		{
			cout << a[i] << '\t';
		}
		cout << endl;
		cout << endl;

		cout << a[4] << endl;//выводим значение i-го элемента массива
		cout << endl;

		a[4] = 500;//присваиваем i-му элементу значение
		cout << a[4] << endl;//выводим в консоль
		cout << endl;

		for (int i = 0; i < a.getDlina(); ++i)//выводим в консоль массив с новым значением
		{
			cout << a[i] << '\t';
		}
		cout << endl;

		cout << a.poiskZnyachen(500);
		cout << endl;

		cout << "Razmer massiva - " << a.IntArreySize() << " byte" << endl;
		cout << endl;
	}

	catch (MyExcept1& ex)
	{
		cout << ex.what() << endl;
		cout << "Vihod za predel massiva:" << endl;
	}

	catch (MyExcept2& ex)
	{
		cout << ex.what() << endl;
		cout << "Ne ta dlinna:" << endl;
	}	

	return 0;
}