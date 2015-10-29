#pragma once
template<class A, class B>
struct select_larger
{
	//typedef std::conditional<sizeof(A) > sizeof(B),A,B>::type type;
	typedef typename std::conditional<(sizeof(A) > sizeof(B)), A, B>::type type;
};

template<class T, class Y >
typename select_larger<T, Y>::type maximum(T left, Y right)
{
	static_assert(std::is_convertible<T, Y>::value, "Cannot use those types");
	static_assert(std::is_convertible<Y, T>::value, "Cannot use those types");
	return left > right ? left : right;
}

