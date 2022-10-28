#pragma once
#include"MyExcept1.h"
#include"MyExcept2.h"

class IntegerArray
{
	int _dlina = 0;
	int* _mass = NULL;

public:
	IntegerArray() = default;
	IntegerArray(int dlina); // ����������� ������������� ������� � �����������

	virtual ~IntegerArray();//��������� ����������� ������, ���������� new

	int IntArreySize();//������ ������� � ������

	int& operator[] (int index);//���������� ���������� []

	void resize(int new_dlina);//����� ����� ������� � ��������� ���� ���������. ���� ����� ������, �� ��������� �������� 0

	void insert(int znachenie, int index);//��������� �������� � ������, ������� ������� � ���������.

	void remove(int index);//������� ������� �� �������

	const char* poiskZnyachen(int znachenie);

	int getDlina()const;

};