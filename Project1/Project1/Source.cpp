
#include <iostream>
#include "Integer.hpp"

int main() {
	Integer ob1("-1111"), ob2("-999");
	std::cout <<"ob1 == ob2 ?'\n"<< (ob1 == ob2);
	std::cout << "\nob1 != ob2 ?'\n" << (ob1 != ob2);
	std::cout << "\nob1 < ob2 ?'\n" << (ob1 < ob2);
	std::cout << "\nob1 <= ob2 ?'\n" << (ob1 <= ob2);
	std::cout << "\nob1 > ob2 ?'\n" << (ob1 > ob2);
	std::cout << "\nob1 >= ob2 ?'\n" << (ob1 >= ob2);
	int nr;
	std::cout << "\nIntrodu numarul: ";
	std::cin >> nr;
	std::cout << '\n';
	
	std::cout << ob1 << ob2 << '\n';



	std::cout << "ob1+ob2: ";
	Integer ob31 = ob1 + ob2;
	std::cout << ob31<<'\n';

	std::cout << "ob1+int: ";
	Integer ob32 = ob1 + nr;
	std::cout << ob32 << '\n';

	std::cout << "int+ob1: ";
	Integer ob33 = nr + ob1;
	std::cout << ob33 << '\n';

	std::cout << "ob1-ob2: ";
	Integer ob41;
	ob41 = ob1 - ob2;
	std::cout << ob41<<'\n';

	std::cout << "ob1-int: ";
	Integer ob42;
	ob42 = ob1 - nr;
	std::cout << ob42 << '\n';

	std::cout << "int-ob1: ";
	Integer ob43;
	ob43 = nr - ob1;
	std::cout << ob43 << '\n';

	std::cout << "ob1*ob2: ";
	Integer ob51 = ob1 * ob2;
	std::cout << ob51<<'\n';

	std::cout << "ob1*int: ";
	Integer ob52 = ob1 * nr;
	std::cout << ob52 << '\n';

	std::cout << "int*ob1: ";
	Integer ob53 = nr * ob1;
	std::cout << ob53 << '\n';
	
	std::cout << "ob1/ob2: ";
	Integer ob61 = ob1 / ob2;
	std::cout << ob61<<'\n';

	std::cout << "ob1/int: ";
	Integer ob62 = ob1 / nr;
	std::cout << ob62 << '\n';

	std::cout << "int/ob1: ";
	Integer ob63 = nr / ob1;
	std::cout << ob63 << '\n';

	std::cout << "ob1%ob2: ";
	Integer ob71 = ob1 % ob2;
	std::cout << ob71<<'\n';

	std::cout << "ob1%int: ";
	Integer ob72 = ob1 % nr;
	std::cout << ob72 << '\n';

	std::cout << "int%ob1: ";
	Integer ob73 = nr % ob1;
	std::cout << ob73 << '\n';

	std::cout << "Introdu puterea: ";
	int p;
	std::cin >> p;
	std::cout << "\n ob1^p: ";
	Integer ob8 = ob1 ^ p;
	std::cout << ob8;
	
	std::cout << "ob1+=ob2: ";
	Integer ob01 = ob1;
	ob01 += ob2;
	std::cout << ob01 << '\n';

	std::cout << "ob1+=int: ";
	Integer ob02 = ob1;
	ob02 += nr;
	std::cout << ob02 << '\n';

	std::cout << "ob1-=ob2: ";
	Integer ob03 = ob1;
	ob03 -= ob2;
	std::cout << ob03 << '\n';

	std::cout << "ob1-=int: ";
	Integer ob04 = ob1;
	ob04 -= nr;
	std::cout << ob04 << '\n';

	std::cout << "ob1*=ob2: ";
	Integer ob05 = ob1;
	ob05 *= ob2;
	std::cout << ob05 << '\n';

	std::cout << "ob1*=int: ";
	Integer ob06 = ob1;
	ob06 *= nr;
	std::cout << ob06 << '\n';

	std::cout << "ob1/=ob2: ";
	Integer ob07 = ob1;
	ob07 /= ob2;
	std::cout << ob07 << '\n';

	std::cout << "ob1/=int: ";
	Integer ob08 = ob1;
	ob08 /= nr;
	std::cout << ob08 << '\n';

	std::cout << "ob1%=ob2: ";
	Integer ob09 = ob1;
	ob09 %= ob2;
	std::cout << ob09 << '\n';

	std::cout << "ob1%=int: ";
	Integer ob00 = ob1;
	ob00 %= nr;
	std::cout << ob00 << '\n';


	system("pause");
}