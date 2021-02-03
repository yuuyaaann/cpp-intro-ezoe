#include "../include/array.h"

int main() { 
	array<int,10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;

	auto iter = a.begin();
	std::cout << *iter << std::endl;
	++iter;
	std::cout << *iter << std::endl;

}