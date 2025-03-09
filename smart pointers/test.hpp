#ifndef CLASS_HPP_
#define CLASS_HPP_

#pragma once

#include <iostream>
#include <memory>

class Integer
{
public:
	// default constructor
	Integer();
	// parametarize constructor
	explicit Integer(int value);
	// copy constructor
	Integer(const Integer &obj);
	// Move constructor
	Integer(Integer &&obj);
	// copy assignment constructor
	Integer &operator=(const Integer &obj);
	// move assignment constructor
	Integer &operator=(Integer &&obj);
	Integer &operator+(const Integer &obj);
	Integer &operator++();	 // pre increment
	Integer operator++(int); // post increment
	explicit operator int();
	friend std::istream &operator>>(std::istream &input, Integer &ref);
	int GetValue(void) const;
	void SetValue(int value);

	// Destructor
	~Integer();

private:
	int *m_ptr;
};

void raw_pointer(void);
void stduniqueptr(void);
void sharingptr(void);
void weakptr(void);
void Deleter(void);
void Make_Functions(void);
#endif
