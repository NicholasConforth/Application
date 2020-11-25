#include "pch.h"

void _assert(bool condition, const std::string& conditionString, const std::string& filename, int line, const std::string& functionName)
{
	if (!condition)
	{
		std::cout << "assertion fail: " << conditionString << std::endl;
		std::cout << "source file: " << filename << std::endl;
		std::cout << "line: " << line << std::endl;
		std::cout << "function: " << functionName << std::endl;

		abort();
	}
}

void _assert(bool condition, const std::string& conditionString, const std::string& filename, int line, const std::string& functionName, const std::string& message)
{
	if (!condition)
	{
		std::cout << "assertion fail: " << conditionString << std::endl;
		std::cout << message << std::endl;
		std::cout << "source file: " << filename << std::endl;
		std::cout << "line: " << line << std::endl;
		std::cout << "function: " << functionName << std::endl;

		abort();
	}
}
