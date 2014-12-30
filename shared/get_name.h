#pragma once

#include <string>

#ifdef __GNUC__
#include <cxxabi.h>
#include <memory>
#include <cstdlib>
#include <typeinfo>
std::string demangle(const char* mangled)
{
	int status;
	std::unique_ptr<char[], void(*)(void*)> result(
		abi::__cxa_demangle(mangled, 0, 0, &status), std::free);
	return result.get() ? std::string(result.get()) : "error occurred";
}

#endif // __GNUC__

std::string GetName(const char* str)
{
#ifdef __GNUC__
	return demangle(str);
#endif // __GNUC__
	return str;
}