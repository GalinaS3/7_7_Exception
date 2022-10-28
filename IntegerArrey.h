#pragma once
#include"MyExcept1.h"
#include"MyExcept2.h"

class IntegerArray
{
	int _dlina = 0;
	int* _mass = NULL;

public:
	IntegerArray() = default;
	IntegerArray(int dlina); // конструктор динамического массива с исключением

	virtual ~IntegerArray();//деструкто освобождает пямять, выделенную new

	int IntArreySize();//размер массива в байтах

	int& operator[] (int index);//перегрузка опереатора []

	void resize(int new_dlina);//новая длина массива с переносом всех элементов. если длина больше, то остальные элементы 0

	void insert(int znachenie, int index);//вставляем занчение в массив, включая нулевой и последний.

	void remove(int index);//удаляем элемент из массива

	const char* poiskZnyachen(int znachenie);

	int getDlina()const;

};