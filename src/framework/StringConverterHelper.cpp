#include "StringConverterHelper.h"

#include <string>
#include <iostream>
using namespace std;
using namespace System;

std::string StringConverterHelper::convertString(String ^ s) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	return chars;
}