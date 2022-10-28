#pragma once
#include<iostream>
#include<exception>

class MyExcept1 : public std::exception
{
public:
	virtual const char* what() const noexcept override;

	virtual ~MyExcept1();
};