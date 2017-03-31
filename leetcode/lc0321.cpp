//
// Created by aleafall on 17-3-5.
//

#include <iostream>

using namespace std;

class A {
public:
	A() {
		x = 1;
	}

	void fa() {
		cout << "fa" << endl;
	}

//	virtual void fva() {
//		cout << "virtual fa\n";
//	}

	int x;
private:
};

class B : public A {
public:
	B() {
		A();
		x = 2;
	}

	void fa() {
		cout << "fb" << endl;
	}

//	void fva() override {
//		cout << "virtual fb\n";
//	}

	int x;
private:
};

int main() {
	A *a = new B;
	auto c = static_cast<B *>(a);
	a->fa();
//	a->fva();
	B b;
	cout << "b "<<sizeof(b) << endl;
	cout << a->x << endl;   //为什么是1？
	cout << c->x << endl;
	delete a;
	return 0;
}
