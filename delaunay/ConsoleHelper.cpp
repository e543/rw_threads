#include "ConsoleHelper.h"
#include <iostream>

bool ConsoleHelper::Greeting()  const
{

	std::cout << "\tHello!\n" << std::endl;
	return true;
}

bool ConsoleHelper::sendMsg(std::string str) const
{
	std::cout << std::fixed <<  "\t" << str << std::endl;
	return true;
}

std::string ConsoleHelper::getMsg() const
{
	std::string str;
	std::cin >> str;
	std::cout << "Get: " << str << std::endl;
	return str;
}

bool ConsoleHelper::Parting() const
{
	std::cout << "\n\tGood Bye!" << std::endl;
	return true;
}

