//
// Created by aleafall on 17-3-2.
//

#include <cstdlib>
#include "SmartPtr.h"

template <typename T>
SmartPtr::SmartPtr(T *tp) {
	ref = tp;
	ref_count = (unsigned int *) malloc(sizeof(unsigned));
	*ref_count = 1;
}

template <typename T>
SmartPtr::SmartPtr(SmartPtr<T> &ptr) {
	ref = ptr.ref;
	ref_count = ptr.ref_count;
	++(*ref_count);
}

template <typename T>
SmartPtr<T> &SmartPtr::operator=(SmartPtr<T> &ptr) {
	if (this == &ptr) {
		return *this;
	}
	if (*ref_count > 0) {
		remove();
	}
	ref = ptr.ref;
	ref_count = ptr.ref_count;
	++(*ref_count);
	return *this;
}


template <typename T>
SmartPtr::~SmartPtr() {
	remove();
}
template <typename T>
void SmartPtr::remove() {
	--(*ref_count);
	if (!ref_count) {
		free(ref_count);
		delete ref;
		ref = NULL;
		ref_count = NULL;
	}
}
