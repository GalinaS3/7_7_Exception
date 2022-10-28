#include"MyExcept1.h"

const char* MyExcept1::what() const noexcept
{
	return "Bad range";
}
MyExcept1::~MyExcept1() = default;

