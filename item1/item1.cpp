#include <iostream>
#include <string>
#include <vector>
#include "../shared/get_name.h"

#define NAME(x) #x

template<typename T>
void f(T&& param , const char* desc)
{
    std::cout<< desc << "'s type_info:\t"<<GetName( typeid(T).name() )<<std::endl;
}

template<typename T>
void f_ref(T& param , const char* desc)
{
    std::cout<< desc << "'s type_info:\t"<<GetName( typeid(T).name() )<<std::endl;
}

template<typename T>
void f_pointer(T* param, const char* desc)
{
	std::cout << desc << "'s type_info:\t" << GetName(typeid(T).name()) << std::endl;
}

#define FUN_UNIVERSAL(x) f(x,NAME(x))
#define FUN_REF(x) f_ref(x,NAME(x))
#define FUN_POINTER(x) f_pointer(x,NAME(x))


int main(void)
{
    const char const_scope_str_array[6] = "hello";
	static const char static_str_array[8] = "s_hello";
	char * pointer_str = "pointer_str";
	const char* const_pointer_str = "const_pointer_str";
    FUN_UNIVERSAL(const_scope_str_array);
	FUN_UNIVERSAL(static_str_array);
    FUN_UNIVERSAL("world");
	FUN_UNIVERSAL(pointer_str);
	FUN_UNIVERSAL(const_pointer_str);
	
	std::cout<<"FUN_REF-----\n\n";

	FUN_REF(const_scope_str_array);
	FUN_REF(static_str_array);
    FUN_REF("world");
	FUN_REF(pointer_str);
	FUN_REF(const_pointer_str);

	FUN_POINTER(const_scope_str_array);
	FUN_POINTER(static_str_array);
	FUN_POINTER("world");
	FUN_POINTER(pointer_str);
	FUN_POINTER(const_pointer_str);
    return 0;
}


