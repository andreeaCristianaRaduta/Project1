#pragma once
#include <vector>
#include <iostream>

class Integer {

public:

	Integer(int digits = 0, unsigned char base = 10, char sign = '+');

	Integer(long long int digits, unsigned char base = 10);

	Integer(std::string digits,unsigned char base = 10);

	void setBase(int base);
	int getBase();

	void setSign(char sign);
	char getSign();

	Integer& operator+=(const Integer&ob);
	Integer& operator+=(const int&nr);
	Integer& operator-=(const Integer&ob);
	Integer& operator-=(const int&nr);
	Integer& operator*=(const Integer&ob);
	Integer& operator*=(const int&nr);
	Integer& operator/=(const Integer&ob);
	Integer& operator/=(const int&nr);
	Integer& operator%=(const Integer&ob);
	Integer& operator%=(const int&nr);
	friend std::ostream& operator<<(std::ostream& , Integer &);
	friend std::istream& operator>>(std::istream&, Integer &);
	friend bool operator==(Integer ob1, Integer ob2);
	friend bool operator==(Integer ob1, int nr);
	friend bool operator==(int nr, Integer ob1);
	friend bool operator!=(Integer ob1, Integer ob2);
	friend bool operator!=(Integer ob1, int nr);
	friend bool operator!=(int nr, Integer ob1);
	friend bool operator<(Integer ob1, Integer ob2);
	friend bool operator<(Integer ob, int nr);
	friend bool operator<(int nr, Integer ob);
	friend bool operator<=(Integer ob1, Integer ob2);
	friend bool operator<=(Integer ob, int nr);
	friend bool operator<=(int nr, Integer ob);
	friend bool operator>(Integer ob1, Integer ob2);
	friend bool operator>(Integer ob, int nr);
	friend bool operator>(int nr, Integer ob);
	friend bool operator>=(Integer ob1, Integer ob2);
	friend bool operator>=(Integer ob, int nr);
	friend bool operator>=(int nr, Integer ob);
	friend Integer operator+(Integer ob1,const Integer &ob2);
	friend Integer operator+(Integer ob, int nr);
	friend Integer operator+(int nr, Integer ob);
	friend Integer operator-(Integer ob1, const Integer &ob2);
	friend Integer operator-(Integer ob, int nr);
	friend Integer operator-(int nr, Integer ob);
	friend Integer operator*(Integer ob1, const Integer &ob2);
	friend Integer operator*(Integer ob, int nr);
	friend Integer operator*(int nr, Integer ob);
	friend Integer operator/(Integer ob1, const Integer &ob2);
	friend Integer operator/(Integer ob, int nr);
	friend Integer operator/(int nr, Integer ob);
	friend Integer operator%(Integer ob1, const Integer &ob2);
	friend Integer operator%(Integer ob, int nr);
	friend Integer operator%(int nr, Integer ob);
	friend Integer operator^(Integer ob, int nr);
	
private:

	std::vector<char> mDigits;
	char mSign;
	unsigned char mBase;

};