#include"MyExcept2.h"

const char* MyExcept2::what() const noexcept
{
	return "Bad length";
}
MyExcept2::~MyExcept2() = default;