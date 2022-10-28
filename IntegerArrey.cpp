#include"IntegerArrey.h"

IntegerArray::IntegerArray(int dlina) : _dlina(dlina)// конструктор динамического массива с исключением
{
	if (_dlina <= 0)
	{
		throw MyExcept2();//сначала проверяем на исключения, а уже потом, если можно, бронируем пямять
	}
	_mass = new int[_dlina] {};//подумать над длиной 0	
}

IntegerArray::~IntegerArray()//деструкто освобождает пямять, выделенную new
{
	delete[] _mass;
}

int IntegerArray::IntArreySize()//размер массива в байтах
{
	return _dlina * sizeof(int);
}

int& IntegerArray:: operator[](int index)//перегрузка опереатора []
{
	if (index < 0 || index > _dlina)
	{
		throw MyExcept1();
	}
	return _mass[index];
}

void IntegerArray::resize(int new_dlina)//новая длина массива с переносом всех элементов. если длина больше, то остальные элементы 0
{
	if (new_dlina <= 0)
	{
		throw MyExcept2();
	}

	int* new_mass = new int[new_dlina];

	if (new_dlina >= _dlina)
	{
		for (int i = 0; i < _dlina; ++i)
		{
			new_mass[i] = _mass[i];
		}
		for (int i = _dlina; i < new_dlina; ++i)
		{
			new_mass[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < new_dlina; ++i)
		{
			new_mass[i] = _mass[i];
		}
	}

	delete[] _mass;
	_mass = new_mass;
	_dlina = new_dlina;
}

void IntegerArray::insert(int znachenie, int index)//вставляем занчение в массив, включая нулевой и последний.
{
	if (index < 0 || index > _dlina)
	{
		throw MyExcept1();
	}
	int* new_mass = new int[_dlina + 1];

	if (index <= _dlina)
	{
		for (int i = 0; i < index; ++i)
		{
			new_mass[i] = _mass[i];
		}
		new_mass[index] = znachenie;
		for (int i = index; i < _dlina + 1; ++i)
		{
			new_mass[i + 1] = _mass[i];
		}
	}
	else
	{
		for (int i = 0; i < _dlina + 1; ++i)
		{
			new_mass[i] = _mass[i];
		}
		new_mass[_dlina + 1] = znachenie;
	}
	delete[] _mass;
	_mass = new_mass;
	++_dlina;
}

void IntegerArray::remove(int index)//удаляем элемент из массива
{
	if (index < 0 || index > _dlina - 1)
	{
		throw MyExcept1();
	}
	int* new_mass = new int[_dlina - 1];

	for (int i = 0; i < index; ++i)
	{
		new_mass[i] = _mass[i];
	}
	for (int i = index; i < _dlina - 1; ++i)
	{
		new_mass[i] = _mass[i + 1];
	}
	delete[] _mass;
	_mass = new_mass;
	--_dlina;
}

const char* IntegerArray::poiskZnyachen(int znachenie)
{
	for (int i = 0; i < _dlina; ++i)
	{
		if (_mass[i] = znachenie)
		{
			return "Znachenie v massive";
		}
	}
	return "Znachenia v massive net";
}

int IntegerArray::getDlina()const
{
	return _dlina;
}

