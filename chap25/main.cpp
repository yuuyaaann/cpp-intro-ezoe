#include <iostream>

struct IntLike {

	int data {};

	IntLike & operator ++() {
		++data;
		return *this;
	}


	IntLike operator ++(int) {
		IntLike copy = *this;
		++*this;
		return copy;
	}
};