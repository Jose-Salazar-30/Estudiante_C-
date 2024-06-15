#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Estudiante
{
private:
	   string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	   int telefono = 0, id = 0;

	   //constructor
public:
		Estudiante() {
		}
		Estudiante(string cod, string nom, string ape, string dire, int t, string fn,int i) {
			codigo = cod;
			nombres = nom;
			apellidos = ape;
			direccion = dire;
			telefono = t;
			fecha_nacimiento = fn;
			id = i;
		}

		//Metodos
		//Set (Modificar)
		void setId(int i) { id = i; }
		void setCodigo(string cod) { codigo = cod; }
		void setNombres(string nom) { nombres = nom; }
		void setApellidos(string ape) { apellidos = ape; }
		void setDireccion(string dire) { direccion = dire; }
		void setTelefono(int t) { telefono = t; }
		void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
		//get (Mostrar)
		int getId() { return id; }
		string getCodigo() { return codigo; }
		string getNombres() { return nombres; }
		string getApellidos() { return apellidos; }
		string getDirecion() { return direccion; }
		int getTelefono() { return telefono; }
		string getFecha_Nacimiento() { return fecha_nacimiento; }

		void crear() {
			int q_estado;
			ConexionBD cn = ConexionBD();

			cn.abrir_Conexion();
			string t = to_string(telefono);

			if (cn.getConectar()) {
				string insertar =
					"INSERT INTO estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + fecha_nacimiento + "')";
				const char* i = insertar.c_str();
				//query execute
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "--------Ingreso de Estudiante Exitoso...-------" << endl;
				}
				else {
					cout << "-------Error al ingresar Estudiante-------" << endl;
				}
			}
			else {
				cout << "--------Error en la conexion-------" << endl;
			}
			cn.cerrar_conexion();
		}

		void leer() {
			int	q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
	
			cn.abrir_Conexion();

			if (cn.getConectar()) {

				cout << "---*Datos Estudiante*---" << endl;
				string consulta = "select * from estudiantes;";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << ":" << fila[1] << ":" << fila[2] << ":" << fila[3] << ":" << fila[4] << ":" << fila[5] << ":" << fila[6] << endl;
					}
				}
				else {
					cout << "---*Error al Consultar*---" << endl;
				}
			}
			else {
				cout << "---*Error en la conexion*---" << endl;
			}
			cn.cerrar_conexion();

		}

		void actualizar() {
			int q_estado;
			ConexionBD cn = ConexionBD();

			cn.abrir_Conexion();
			string t = to_string(telefono);
			string ii = to_string(id);
			if (cn.getConectar()) {
				string actualizar =
					"update estudiantes set codigo = '" + codigo + "', nombres='" + nombres + "', apellidos= '" + apellidos
					+ "', direccion= '" + direccion + "', telefono =" + t + ", fecha_nacimiento='" + fecha_nacimiento + 
					"' where id_estudiante + " + ii + "";
				const char* i = actualizar.c_str();
				//execute query
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "---*Actualizacion Exitosa*---" << endl;
				}
				else {
					cout << "---*Error al actualizar*---" << endl;
				}
			}
			else {
				cout << "****Error en la conexion*****" << endl;
			}
			cn.cerrar_conexion();
		}

		void borrar() {
			int q_estado;
			ConexionBD cn = ConexionBD();

			cn.abrir_Conexion();
			string ii = to_string(id);
			if (cn.getConectar()) {
				string borrar =
					"delete from estudiantes where id_estudiante = " + ii + "";
				const char* i = borrar.c_str();
				//execute query
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "---*Eliminacion Exitosa*---" << endl;
				}
				else {
					cout << "---*Error al eliminar*---" << endl;
				}
			}
			else {
				cout << "****Error en la conexion*****" << endl;
			}
			cn.cerrar_conexion();
		}
};

