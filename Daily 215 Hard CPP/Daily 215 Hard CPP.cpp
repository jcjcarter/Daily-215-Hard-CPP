// Daily 215 Hard CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <cxxabi.h>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <iomanip>

using namespace std;

template<typename T>
typename enable_if< !is_convertible<T, bool>:: value, const char*>::type
to_bool(const T& value) { return "not implicitly convertible to bool"; }

template<typename T>
typename enable_if<is_convertible<T, bool>:: value, const char*>::type
to_bool(const T& value) {
	return static_cast<bool>(value) ? "true" : "false";
}

template<typename T> void print_truth(const string& expr, const T& value) {
	int status;
	cout << left << setw(25) << expr
		<< setw(20) << abi::_cxa_demangle(typeid(T).name(),
			0, 0, &status)
		<< to_bool(value) << endl;
}

#define PRINT_TRUTH(x) print_truth((#x), (x))


int main()
{
	PRINT_TRUTH("Hello world!");
	PRINT_TRUTH("");
	PRINT_TRUTH(string("Hello world!"));
	PRINT_TRUTH(string(""));
	PRINT_TRUTH('0');
	PRINT_TRUTH(1);
	PRINT_TRUTH(0);
	PRINT_TRUTH(nullptr);
	//PRINT_TRUTH(((int[]) { 1, 2, 3 }));
	PRINT_TRUTH(true);
	PRINT_TRUTH(false);
    return 0;
}

