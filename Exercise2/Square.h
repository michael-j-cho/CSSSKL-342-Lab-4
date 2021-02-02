/*
 *  Square.h
 *  Class-example
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

template<class T>
class Square {
	template<class U>
	friend std::ostream& operator<<(std::ostream&, const Square<U>&);
public:
	Square<T> & operator=(const Square<T>&);
	bool operator<(const Square<T>&);
	void setSize(T newSize);
	T getSize(void) const;

private:
	T theSize;
};
#include "Square.cpp"
#endif
