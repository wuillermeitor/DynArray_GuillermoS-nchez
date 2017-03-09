#include "DynArray.hh"
#include <iostream>

//constructores
DynArray::DynArray(void) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size) {
	m_capacity = size;
	m_size = size;
	m_data = new int[size];
}

DynArray::DynArray(size_t size, const int &value) {
	m_capacity = size;
	m_size = size;
	m_data = new int[size];
	
	fill(begin(), end(), value);
}

DynArray::DynArray(int *arr, size_t size) {
	m_capacity = size;
	m_size = size;
	m_data = new int[size];

	for (int i = 0; i < size; i++) {
		m_data[i] = arr[i];
	}
}

//destructor
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

void DynArray::push(const int &val) {
	int *tmp;
	if (m_size == m_capacity){
		delete[] m_data;
		tmp = new int[m_capacity + 1];
	}
	else if (m_size < m_capacity) {
		m_size++;
		DynArray::DynArray[m_size] = val;
	}
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
	int i = 0;
	int j = 0;
	while (i < lhs.m_size) {
		i++;
	}
	while (j < rhs.m_size) {
		j++;
	}
	return i < j;
}

bool operator<=  (const DynArray& lhs, const DynArray& rhs) {
	int i = 0;
	int j = 0;
	while (i < lhs.m_size) {
		i++;
	}
	while (j < rhs.m_size) {
		j++;
	}
	return i <= j;
}

bool operator>  (const DynArray& lhs, const DynArray& rhs) {
	int i = 0;
	int j = 0;
	while (i < lhs.m_size) {
		i++;
	}
	while (j < rhs.m_size) {
		j++;
	}
	return i > j;
}

bool operator>=  (const DynArray& lhs, const DynArray& rhs) {
	int i = 0;
	int j = 0;
	while (i < lhs.m_size) {
		i++;
	}
	while (j < rhs.m_size) {
		j++;
	}
	return i >= j;
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