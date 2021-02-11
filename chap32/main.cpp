// コピーコンストラクター、コピー代入演算子を書かない場合
// デフォルトのコピーコンストラクター、コピー代入が生成
// 要は、オブジェクトをコピーしたときに呼ばれる
#include <iostream>

struct Point
{
	int x;
	int y;
	int z;

	// コンストラクタ
	Point(int _x, int _y, int _z) {
		std::cout << "Constructor " << std::endl;
	}

	// コピーコンストラクター
	// 非const lvalueリファレンス型を引数にとるコンストラクターも
	// コピーコンストラクター
	Point(const Point & r) : x(r.x), y(r.y), z(r.z) {
		std::cout << "Copy Constructor " << std::endl; 
	}	

	// コピー代入演算子
	Point & operator = (const Point & r) {
		x = r.x;
		y = r.y;
		z = r.z;
	}

};

template <typename T>
class own {
private:
	T *ptr;
public:
	// コンストラクタ
	own() : ptr(new T) {

	}

	// デストラクタ
	~own() {
		delete ptr;
	}

	// デフォルトのコピーコンストラクタを使う場合
	// ただし、この場合だと、所有したつもりになって破棄されている可能性がある
	//own( const own &) = default;
	own (const own & r) : ptr (new T(*r.ptr)) {}
	own & operaotr = (const own &) {
		// 自分自身の代入ではなければ実施しない
		if(this != &r) {
			*ptr = *r.ptr;
		}
		return *this;
	}

	T * get() const {
		return ptr;
	} 

};


int main () {

	Point a(1,2,3);
	// コピーコンストラクタを呼ぶ
	Point b = a;
	Point c = a;

}