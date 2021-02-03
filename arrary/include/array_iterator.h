#include "all.h"

template <typename Arrary>
struct array_iterator{
	Arrary & a;
	std::size_t i;

	// コンストラクタ
	array_iterator( Arrary & a, std::size_t i) : a( a ) , i (i){}

	// 次の要素を指す
	array_iterator & operator ++() {
		++i;
		return *this;
	}

	array_iterator & operator --();

	// 今参照している要素を返す
	typename Arrary::reference operator *() {
		return a[i];
	}

};