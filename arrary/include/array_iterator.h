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

	// 後置
	array_iterator operator++(int){
		array_iterator copy = *this;
		++*this;
		return copy;
	}

	// 前置
	array_iterator & operator --() {
		--i;
		return *this;
	}


	// 後値
	array_iterator & operator --(int) {
		array_iterator copy = *this;
		--*this;
		return copy;
	}

	array_iterator & operator +=(std::size_t n) {
		i += n;
		return *this;
	}

	array_iterator & operator +(std::size_t n) const {
			auto copy = *this;
			copy += n;
			return copy;
	}

	// 今参照している要素を返す
	typename Arrary::const_reference operator *() {
		return a[i];
	}

	// 比較
	bool operator == (array_iterator const & right) {
		return i == right.i;
	}

	bool operator != (array_iterator const & right) {
		return i != right.i;
	}

};