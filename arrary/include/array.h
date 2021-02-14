#include "../../all.h"
#include "array_iterator.h"

template <typename T, std::size_t N>
struct array {
	T storage[N] ;

	using reference = T & ;
	using const_reference = T const & ;

#if defined(REFERENCE)
	reference operator [] ( std::size_t i ) { 
		 return storage[i] ; 
	} 

	reference front() { 
		 return storage[0] ; 
	} 

	reference back() { 
		 return storage[N - 1] ; 
	} 

#else

	const_reference operator [] ( std::size_t i ) { 
		 return storage[i] ; 
	} 

	const_reference front() { 
		 return storage[0] ; 
	} 

	const_reference back() { 
		 return storage[N - 1] ; 
	} 

#endif
	
	// イテレーターを型
	// array_iterator は、 array_iterator<array<T,N>> と書いたことと一緒
	using iterator = array_iterator<array>;

	// 先頭のイテレーターを返す
	iterator begin() {
		return iterator(*this, 0);
	}

	// 最後の次の要素へのイテレータ
	iterator end() {
		return iterator(*this, N);
	}

} ;