//
// Created by aleafall on 17-3-2.
//

#ifndef DS_A_SMARTPTR_H
#define DS_A_SMARTPTR_H

template <typename T>
class SmartPtr {
public:
	SmartPtr(T *tp);
	SmartPtr(SmartPtr<T> &ptr);

	SmartPtr<T> &operator=(SmartPtr<T> &ptr);

	~SmartPtr();
protected:
	void remove();
	unsigned *ref_count;
	T* ref;
};


#endif //DS_A_SMARTPTR_H
