#include "Integer.hpp"
#include <conio.h>
#include <algorithm>
#include <math.h>

Integer::Integer(int digits, unsigned char base, char sign)
	: mBase(base)
	,mSign(sign)
{

	int digitsDuplicate = digits;
	while (digitsDuplicate) {

		mDigits.push_back((digitsDuplicate % 10) + '0');
		digitsDuplicate /= 10;

	}

	reverse(mDigits.begin(), mDigits.end());

}

Integer::Integer(long long int digits, unsigned char base)
	: mBase(base)
{

	mDigits.push_back(digits);
}

Integer::Integer(std::string digits, unsigned char base) 
	: mBase(base)
{
		
	char sign;

	if (digits[0] == '-') sign = '-';
	else sign = '+';

	mSign = sign;
	 
	if (digits[0] == '+' || digits[0] == '-')
		for (int i = 1; i < digits.length(); i++)
			if (strchr("+-0123456789", digits[i]) == 0) {
				std::cout << "Numarul introdus nu este intreg!";
				break;
			}
			else
				mDigits.push_back(digits[i]);
	else
		for (int i = 0; i < digits.length(); i++)
			if (strchr("+-0123456789", digits[i]) == 0) {
				std::cout << "Numarul introdus nu este intreg!";
				break;
			}
			else
				mDigits.push_back(digits[i]);

}

void Integer::setBase(int base) {
	mBase = base;
}

int Integer::getBase() {
	return mBase;
}

void Integer::setSign(char sign){
	mSign = sign;
}

char Integer::getSign() {
	return mSign;
}

Integer& Integer::operator+=(const Integer & ob) {	

	*this = *this + ob;
	return *this;


}

Integer& Integer::operator+= (const int & nr) {

	Integer obj(nr);
	*this = *this + obj;
	return *this;

}

Integer& Integer::operator-=(const Integer & ob) {

	*this = *this - ob;
	return *this;

}

Integer& Integer::operator-=(const int & nr) {

	Integer obj(nr);
	*this = *this - obj;
	return *this;

}

Integer& Integer::operator*=(const Integer & ob) {

	*this = *this * ob;
	return *this;

}

Integer& Integer::operator*=(const int & nr) {

	Integer obj(nr);
	*this = *this * obj;
	return *this;

}

Integer& Integer::operator/=(const Integer & ob) {

	*this = *this / ob;
	return *this;

}

Integer& Integer::operator/=(const int & nr) {

	Integer obj(nr);
	*this = *this / obj;
	return *this;

}

Integer& Integer::operator%=(const Integer & ob) {

	*this = *this % ob;
	return *this;

}

Integer& Integer::operator%=(const int & nr) {

	Integer obj(nr);
	*this = *this % obj;
	return *this;

}

bool operator==(Integer ob1, Integer ob2) {

	if (ob1.mSign == ob2.mSign && ob1.mBase == ob2.mBase && ob1 <= ob2 && ob1 >= ob2)
		return true;
	return false;

}
bool operator==(Integer ob1, int nr) {

	Integer obj(nr);
	if (ob1.mSign == obj.mSign && ob1.mBase == obj.mBase && ob1 <= obj && ob1 >= obj)
		return true;
	return false;

}
bool operator==(int nr, Integer ob1) {

	Integer obj(nr);
	if (ob1.mSign == obj.mSign && ob1.mBase == obj.mBase && ob1 <= obj && ob1 >= obj)
		return true;
	return false;

}

bool operator!=(Integer ob1, Integer ob2) {

		return !(ob1 == ob2);

}

bool operator!=(Integer ob1, int nr) {

	Integer obj(nr);
	
	return !(ob1 == obj);

}

bool operator!=(int nr, Integer ob1) {

	Integer obj(nr);
	
	return !(obj == ob1);

}

bool operator<(Integer ob1, Integer ob2) {
	int n = ob1.mDigits.size(), m = ob2.mDigits.size();
	if (n < m)
		return true;

	if (m < n)
		return false;

	for (int i = 0; i < n; i++) {
		if (ob1.mDigits[i] < ob2.mDigits[i])
			return true;
		if (ob1.mDigits[i] > ob2.mDigits[i])
			return false;
	}

	return false;
}

bool operator<(Integer ob, int nr) {

	Integer obj(nr);
	if (ob < obj)
		return true;
	return false;

}

bool operator<(int nr, Integer ob) {

	Integer obj(nr);
	if (obj < ob)
		return true;
	return false;

}

bool operator<=(Integer ob1, Integer ob2) {
	int n = ob1.mDigits.size(), m = ob2.mDigits.size();
	if (n < m)
		return true;

	if (m < n)
		return false;

	for (int i = 0; i < n; i++) {
		if (ob1.mDigits[i] < ob2.mDigits[i])
			return true;
		if (ob1.mDigits[i] > ob2.mDigits[i])
			return false;
	}

	return true;
}

bool operator<=(Integer ob, int nr) {

	Integer obj(nr);
	if (ob <= obj)
		return true;
	return false;

}

bool operator<=(int nr, Integer ob) {

	Integer obj(nr);
	if (obj <= ob)
		return true;
	return false;

}

bool operator>(Integer ob1, Integer ob2) {

	int n = ob1.mDigits.size(), m = ob2.mDigits.size();
	if (n < m)
		return false;

	if (m < n)
		return true;

	for (int i = 0; i < n; i++) {
		if (ob1.mDigits[i] < ob2.mDigits[i])
			return false;
		if (ob1.mDigits[i] > ob2.mDigits[i])
			return true;
	}

	return false;

}

bool operator>(Integer ob, int nr) {

	Integer obj(nr);
	if (ob > obj)
		return true;
	return false;

}

bool operator>(int nr, Integer ob) {

	Integer obj(nr);
	if (obj > ob)
		return true;
	return false;

}

bool operator>=(Integer ob1, Integer ob2){

	int n = ob1.mDigits.size(), m = ob2.mDigits.size();
	if (n < m)
		return false;

	if (m < n)
		return true;

	for (int i = 0; i < n; i++) {
		if (ob1.mDigits[i] < ob2.mDigits[i])
			return false;
		if (ob1.mDigits[i] > ob2.mDigits[i])
			return true;
	}

	return true;

	}

bool operator>=(Integer ob, int nr) {

	Integer obj(nr);
	if (ob >= obj)
		return true;
	return false;

}

bool operator>=(int nr, Integer ob) {

	Integer obj(nr);
	if (obj >= ob)
		return true;
	return false;

}

Integer operator+(Integer ob1,const Integer& ob2) {

	Integer ob2Duplicate = ob2;
	int n = ob1.mDigits.size();
	int m = ob2Duplicate.mDigits.size();
	Integer plus;
	plus.mDigits.clear();
	plus.mSign = '+';
	Integer dif;
	dif.mDigits.clear();
	if (ob1.mSign == ob2Duplicate.mSign) {

		int nr=0;
		reverse(ob1.mDigits.begin(), ob1.mDigits.end());
		reverse(ob2Duplicate.mDigits.begin(), ob2Duplicate.mDigits.end());

		for (int i=0;i < std::min(n, m);i++) {

			plus.mDigits.push_back((((ob1.mDigits[i] - '0') + (ob2Duplicate.mDigits[i] - '0') + nr))%10 + '0');
			nr = ((ob1.mDigits[i] - '0') + (ob2Duplicate.mDigits[i] - '0')) / 10;
		}

		for (int i = std::min(n, m);i < std::max(n, m);i++) {

			if (m > n) {

				plus.mDigits.push_back(((ob2Duplicate.mDigits[i] - '0') + nr)%10 + '0');
				nr = (nr + (ob2Duplicate.mDigits[i] - '0')) / 10;
			}

			if (n > m) {

				plus.mDigits.push_back(((ob1.mDigits[i] - '0') + nr)%10 + '0');
				nr = ((ob1.mDigits[i] - '0') + nr) / 10;
			}
			
		}

		if (nr != 0)
			plus.mDigits.push_back(nr + '0');

		while (plus.mDigits.back() == '0')
			plus.mDigits.pop_back();

		reverse(plus.mDigits.begin(), plus.mDigits.end());

		if (ob1.mSign == '-')
			plus.mSign = '-';

	}

	else if (ob1.mSign == '+' && ob2Duplicate.mSign == '-') {

		ob2Duplicate.mSign = '+';
		dif = ob1 - ob2Duplicate;
		int sDif = dif.mDigits.size();
		for (int i = 0;i < sDif;i++)
			plus.mDigits.push_back(dif.mDigits[i]);

		plus.mSign = dif.mSign;
	}

	else {
		ob1.mSign = '+';
		dif = ob2Duplicate - ob1;
		int sDif = dif.mDigits.size();
		for (int i = 0;i < sDif;i++)
			plus.mDigits.push_back(dif.mDigits[i]);
		plus.mSign = dif.mSign;
	}

	return plus;
}

Integer operator+(Integer ob, int nr) {

	Integer obj(nr);
	Integer plus;
	plus = ob + obj;
	return plus;

}

Integer operator+(int nr, Integer ob) {

	Integer obj(nr);
	Integer plus;
	plus = obj + ob;
	return plus;

}

Integer operator-(Integer ob1, const Integer& ob2) {

	Integer add;
	add.mDigits.clear();
	Integer minus;
	minus.mDigits.clear();
	Integer ob2Duplicate = ob2;
	int n = ob1.mDigits.size();
	int m = ob2Duplicate.mDigits.size();
	int aux;

	if (ob1.mSign == ob2Duplicate.mSign) {
		if (ob1 < ob2Duplicate) {
			if( ob2Duplicate.mSign == '-')
				minus.mSign = '+';
			else minus.mSign = '-';

			std::swap(ob1, ob2Duplicate);
			aux = n;
			n = m;
			m = aux;
		}
		else minus.mSign = ob1.mSign;

		reverse(ob1.mDigits.begin(), ob1.mDigits.end());
		reverse(ob2Duplicate.mDigits.begin(), ob2Duplicate.mDigits.end());

		int carry = 0;

		for (int i = 0; i < m; i++) {

			int sub = ((ob1.mDigits[i] - '0') - (ob2Duplicate.mDigits[i] - '0') - carry);

			if (sub < 0) {
				sub = sub + 10;
				carry = 1;
			}
			else
				carry = 0;

			minus.mDigits.push_back(sub + '0');
		}

		for (int i = m; i < n; i++) {
			int sub = ((ob1.mDigits[i] - '0') - carry);

			if (sub < 0) {
				sub = sub + 10;
				carry = 1;
			}
			else
				carry = 0;

			minus.mDigits.push_back(sub + '0');
		}

		while (minus.mDigits.back() == '0') {

			if (minus.mDigits.size() == 1)
				break;
			minus.mDigits.pop_back();
			
		}
		reverse(minus.mDigits.begin(), minus.mDigits.end());
	}
	
	else if (ob1.mSign == '+' && ob2Duplicate.mSign == '-') {

		ob2Duplicate.mSign = '+';
		add = ob1 + ob2Duplicate;
		for (int i = 0;i < std::max(n, m);i++)
			minus.mDigits.push_back(add.mDigits[i]);
		minus.mSign = add.mSign;

	}

	else {
		ob1.mSign = '+';
		add = ob1 + ob2Duplicate;
		for (int i = 0;i < std::max(n, m);i++)
			minus.mDigits.push_back(add.mDigits[i]);
		minus.mSign = '-';
	}

	return minus;

}

Integer operator-(Integer ob, int nr) {

	Integer obj(nr);
	Integer minus;
	minus = ob - obj;
	return minus;

}

Integer operator-(int nr, Integer ob) {

	Integer obj(nr);
	Integer minus;
	minus = obj - ob;
	return minus;

}

Integer operator*(Integer ob1, const Integer &ob2) {

	Integer ob2Duplicate = ob2;
	Integer product;
	product.mDigits.clear();
	int n = ob1.mDigits.size();
	int m = ob2Duplicate.mDigits.size();

	reverse(ob1.mDigits.begin(), ob1.mDigits.end());
	reverse(ob2Duplicate.mDigits.begin(), ob2Duplicate.mDigits.end());

	
	for (int i = 0;i < n + m;i++) 
		product.mDigits.push_back('0');

	for (int i = 0;i < n;i++) 
		for (int j = 0;j < m;j++) {

			product.mDigits[i + j] = ((product.mDigits[i + j] - '0') + (ob1.mDigits[i] - '0')*(ob2Duplicate.mDigits[j] - '0')) + '0';
			product.mDigits[i + j + 1] = ((product.mDigits[i + j + 1] - '0') + (product.mDigits[i + j] - '0') / 10) + '0';
			product.mDigits[i + j] = ((product.mDigits[i + j] - '0') % 10) + '0';

		}
	if (ob1.mSign == '-' && ob2Duplicate.mSign == '-')
		product.mSign = '+';
	else if(ob1.mSign == '+' && ob2Duplicate.mSign == '+')
		product.mSign = '+';
	else product.mSign = '-';

	while (product.mDigits.back() == '0') {

		if (product.mDigits.size() == 1)
			break;
		product.mDigits.pop_back();
	}

	reverse(product.mDigits.begin(), product.mDigits.end());

	return product;
}

Integer operator*(Integer ob, int nr) {

	Integer obj(nr);
	Integer product;
	product = ob * obj;
	return product;

}

Integer operator*(int nr, Integer ob) {

	Integer obj(nr);
	Integer product;
	product = ob * obj;
	return product;

}

Integer operator/(Integer ob1, const Integer & ob2){

	Integer div;
	div.mDigits.clear();
	Integer ob1Duplicate = ob1;
	Integer ob2Duplicate = ob2;
	int count = 0;

	if (ob2.mDigits[0] == '0' && ob2.mDigits.size() == 1)
		throw std::invalid_argument("Division by 0 not allowed!");

	ob1Duplicate.mSign = '+';
	ob2Duplicate.mSign = '+';
	
	while (ob2Duplicate <= ob1Duplicate) {

		ob1Duplicate = ob1Duplicate - ob2Duplicate;
		count++;

	} 

	int nr;
	if (count > 0)
		nr = (int)log10((double)count) + 1;
	else nr = 1;

	for (int i = 0;i < nr;i++) {
		div.mDigits.push_back(count % 10 + '0');
		count = count / 10;
	}

	if (ob1.mSign == '-' || ob2Duplicate.mSign == '-')
		div.mSign = '-';

	reverse(div.mDigits.begin(), div.mDigits.end());

	return div;

}

Integer operator/(Integer ob, int nr) {

	Integer obj(nr);
	Integer div;

	if (nr == 0)
		throw std::invalid_argument("Division by 0 not allowed!");

	div = ob / obj;
	return div;

}

Integer operator/(int nr, Integer ob) {

	Integer obj(nr);
	Integer div;

	if( ob.mDigits[0] == '0' && ob.mDigits.size() == 1 )
		throw std::invalid_argument("Division by 0 not allowed!");

	div = obj / ob;
	return div;

}

Integer operator%(Integer ob1, const Integer & ob2){

	Integer mod;
	Integer ob1Duplicate = ob1;
	Integer ob2Duplicate = ob2;
	Integer div;

	div = ob1Duplicate / ob2Duplicate;
	Integer prod;
	prod= ob2Duplicate * div;
	mod = ob1 - prod;
	return mod;
	
}

Integer operator%(Integer ob, int nr) {

	Integer obj(nr);
	Integer mod;
	mod = ob % obj;
	return mod;

}

Integer operator%(int nr, Integer ob) {

	Integer obj(nr);
	Integer mod;
	mod = obj % ob;
	return mod;

}

Integer operator^(Integer ob, int nr) {

	Integer power = ob;

	for (int i = 1;i < nr;i++) 
		power = power * ob;

	return power;
}

std::ostream& operator<<(std::ostream& out, Integer &inti){

	out << "Numarul ";
	out <<inti.mSign;
	for (std::vector<char>::iterator i = inti.mDigits.begin(); i != inti.mDigits.end(); ++i)
		out << *i;
	out << ", in baza";
	out <<' '<< (int)inti.mBase<<"\n";
	return out;
}

std::istream& operator>>(std::istream& in, Integer &inti){         
	std::cout << "Introdu numarul: ";
	in >> inti.mSign;
	char digit;
	inti.mDigits.pop_back();
	while ((digit=getchar())!='\n') {

		inti.mDigits.push_back(digit);
	}
	return in;

}



