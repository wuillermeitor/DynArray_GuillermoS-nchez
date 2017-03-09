#include "DynArray.hh"
#include <iostream>

void main() {
	DynArray d1;
	DynArray d2(5, 10);
	d1.push(20);

	operator<(d1, d2);
	//1. Verificar capacidad.
	//2. Reservar espacio de capacidad + 1.
	//3. Copy
	//4. Asignar *******
	//5. delete[]m_data
	//6. Actualizar m_data
	//7. Actualizar capacity
	//8. Actualziar size
}