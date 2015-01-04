#pragma once

#include <iostream>

template<typename T>
class Widget
{
public:
	Widget()
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	explicit Widget( const T& t ):t_(t) 
	{
		std::cout<<__FUNCTION__ <<" : "<< t_ << "\n";
	}

	~Widget()
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	Widget( const Widget& w )
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	Widget( Widget&& rW )
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	Widget& operator=(const Widget& rhs )
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	Widget& operator=(const Widget&& rhs )
	{
		std::cout<<__FUNCTION__ <<'\n';
	}

	void SetT(const T& t)
	{
		t_ = t;
	}

	void Bark() const 
	{
		std::cout<<__FUNCTION__ << " : " << t_ <<'\n';
	}

private:
	T t_;
};