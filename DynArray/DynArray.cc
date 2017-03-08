#include "DynArray.hh"
#include <iostream>

DynArray::DynArray(void) {
	m_size = 0;
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_data = new int[m_capacity];
}

DynArray::DynArray(int *arr, size_t size) {
	m_capacity = size;
	m_data = new int[m_capacity];
	m_size = size;

	for (int i = 0; i < size; i++) {
		m_data[i] = arr[i];
	}
}

DynArray::~DynArray() {
	delete[]m_data;
}

DynArray& DynArray::operator= (const DynArray &x) {
	m_capacity = x.m_capacity;
	m_size = x.m_size;
	for (int i = 0; i < m_size; i++) {
		m_data[i] = x[i];
	}
	return *this;
}

int* DynArray::begin(void) const {
	return m_data;
}

int* DynArray::end(void) const {
	return m_data + m_size;
}

int& DynArray::operator[] (size_t n) const {
	return m_data[n];
}

bool operator== (const DynArray& lhs, const DynArray& rhs) {
	int i = 0;

	while (i < lhs.m_size) {
		if (lhs[i] == rhs[i]) {
			i++;
		}
		else {
			return false;
		}
	}
	return true;
}

bool operator!= (const DynArray& lhs, const DynArray& rhs) {
	int i = 0;

	while (i < lhs.m_size) {
		if (lhs[i] != rhs[i]) {
			i++;
		}
		else {
			return false;
		}
	}
	return true;
}

bool operator<  (const DynArray& lhs, const DynArray& rhs) {

}

std::ostream& operator<< (std::ostream &out, const DynArray &x) {
	int i = 0;
	while (i < x.m_size) {
		std::cout << x[i];
		i++;
	}
}

void DynArray::clear(void) {
	for (int i = 0; i < m_capacity; i++) {
		m_data[i] = NULL;
	}
	m_size = 0;
}