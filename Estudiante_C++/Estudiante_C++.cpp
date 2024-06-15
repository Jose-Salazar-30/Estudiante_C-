#include <iostream>
#include "Estudiante.h"

using namespace std; 

int main()
{
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id = 0;

	Estudiante c = Estudiante();

	c.leer();
	
	cout << "Ingrese ID:";
	cin >> id;
	cin.ignore();
	cout << "Ingrese codigo: ";
	getline(cin, codigo);
	cout << "Ingrese Nombres: ";
	getline(cin, nombres);
	cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);
	cout << "Ingrese Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese Telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese Fecha de Nacimiento: ";
	cin >> fecha_nacimiento;

	c = Estudiante(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id);
	
	//c.crear();
	//c.leer();
	c.actualizar();
	c.leer();
	cout << "Ingrese ID:";
	cin >> id;
	c.setId(id);
	c.borrar();
	c.leer();

	system("pause");
	return 0;
}

