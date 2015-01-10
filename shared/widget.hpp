#pragma once

#include <iostream>
#include <array>
#include <string>

#ifndef _NOEXCEPT
#define _NOEXCEPT noexcept
#endif // !_NOEXCEPT

template<typename T>
class Widget
{
public:
	Widget()
	{
		++arr_statics_[FT_CTOR];
		std::cout << "Widget()" << '\n';
	}

	explicit Widget( const T& t ):t_(t) 
	{
		++arr_statics_[FT_CTOR];
		std::cout<<"Widget(" << t_ <<")\n";
	}

	~Widget()
	{
		++arr_statics_[FT_DCTOR];
		std::cout<<__FUNCTION__ <<'\n';
	}

	Widget(const Widget& w) :t_(w.t_), arr_statics_(w.arr_statics_)
	{
		++arr_statics_[FT_COPY_CTOR];
		std::cout<<"Widget(const Widget& w)"<<'\n';
	}

	Widget(Widget&& rW) _NOEXCEPT :
	t_(std::move(rW.t_)),
	arr_statics_(std::move(rW.arr_statics_))
	{
		++arr_statics_[FT_MOVE_CTOR];
		std::cout<<"Widget(Widget&& rW)"<<'\n';
	}

	Widget& operator=(const Widget& rhs )
	{
		arr_statics_ = rhs.arr_statics_;
		t_ = rhs.t_;
		++arr_statics_[FT_COPY_ASS];
		std::cout<<"Widget& operator=(const Widget& rhs )"<<'\n';
		return *this;
	}

	Widget& operator=(Widget&& rhs) _NOEXCEPT
	{
		t_ = std::move(rhs.t_);
		arr_statics_ = std::move(rhs.arr_statics_);
		++arr_statics_[FT_MOVE_ASS];
		std::cout<<"Widget& operator=(Widget&& rhs)"<<'\n';
		return *this;
	}

	template<typename arg>
	void SetT(arg&& t)
	{
		t_ = std::forward<arg>(t);
	}

	void Bark() const 
	{
		std::cout<<__FUNCTION__ << " : " << t_ <<'\n';
	}

	void Report() const
	{
		std::cout << "\nReport:\n";
		for (int i = 0; i < FT_NUM; i++)
		{
			std::cout << FunTypeDesc(static_cast<FUN_TYPE>(i)) << ":" << arr_statics_[i] << std::endl;
		}
	}
private:
	enum FUN_TYPE
	{
		FT_CTOR = 0,
		FT_COPY_CTOR,
		FT_COPY_ASS,
		FT_MOVE_CTOR,
		FT_MOVE_ASS,
		FT_DCTOR,
		FT_NUM
	};

	std::string FunTypeDesc( FUN_TYPE f ) const
	{
		static std::string arr[] = 
		{
			
				"FT_CTOR",
				"FT_COPY_CTOR",
				"FT_COPY_ASS",
				"FT_MOVE_CTOR",
				"FT_MOVE_ASS",
				"FT_DCTOR",
				"FT_NUM"
			
		};
		return arr[static_cast<int>(f)];
	}
private:
	T t_;
	mutable std::array<int,FT_NUM> arr_statics_ = {};
};