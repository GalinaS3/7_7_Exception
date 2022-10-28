#include"IntegerArrey.h"

IntegerArray::IntegerArray(int dlina) : _dlina(dlina)// ����������� ������������� ������� � �����������
{
	if (_dlina <= 0)
	{
		throw MyExcept2();//������� ��������� �� ����������, � ��� �����, ���� �����, ��������� ������
	}
	_mass = new int[_dlina] {};//�������� ��� ������ 0	
}

IntegerArray::~IntegerArray()//��������� ����������� ������, ���������� new
{
	delete[] _mass;
}

int IntegerArray::IntArreySize()//������ ������� � ������
{
	return _dlina * sizeof(int);
}

int& IntegerArray:: operator[](int index)//���������� ���������� []
{
	if (index < 0 || index > _dlina)
	{
		throw MyExcept1();
	}
	return _mass[index];
}

void IntegerArray::resize(int new_dlina)//����� ����� ������� � ��������� ���� ���������. ���� ����� ������, �� ��������� �������� 0
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

void IntegerArray::insert(int znachenie, int index)//��������� �������� � ������, ������� ������� � ���������.
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

void IntegerArray::remove(int index)//������� ������� �� �������
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

