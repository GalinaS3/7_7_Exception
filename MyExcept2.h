#pragma once
#include<iostream>
#include<exception>

class MyExcept2 : public std::exception
{
public:
	virtual const char* what() const noexcept override;

	virtual ~MyExcept2();
};