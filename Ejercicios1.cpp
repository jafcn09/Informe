#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct paciente{
	char nombre[20];
	struct paciente *sgte;
};

struct doctor{
	char nombre[20];
	char especialidad[100];
	struct doctor *sgte;
	struct paciente *proximo;
	struct carga *historialPaciente;
};

struct historialPaciente{
	char enfemerdad[50];
	char estado[50];
	char tratamientos[50];
	struct historialPaciente *sgte;
};

typedef struct paciente *Paciente;
typedef struct doctor *Doctor;
typedef struct historialPaciente *Historial;

void insertar(Doctor &lista, char nombre[], char especialidad[]);
void imprimir(Doctor lista);
void ingresaPacientes(Doctor lista);
void buscarDoctor(Doctor lista, char nombre[], char especialidad[]);
void ingreseHistorial(Doctor lista);

int main(){
	Doctor listaDoctor = NULL;
	int nd, np;
	char nombre[20];
	char especialidad[100];


	

	cout << ".:.:. BIENVENIDO AL HOSPITAL CAYETANO HEREDIA .:.:." << endl;


	cout << " \n>>> Ingrese la cantidad de especialistas: ";
	cin >> nd;

	for (int i = 0; i < nd; i++){
		cout << endl;
		cout << " ---> Nombre del especialista (" << i + 1 << "): ";
		cin >> nombre;
		cout << " ---> Ingrese su especialidad (" << i + 1 << "): ";
		cin >> especialidad;

		insertar(listaDoctor, nombre, especialidad);
	}

	ingresaPacientes(listaDoctor);

	cout << "\n===========================================\n";

	imprimir(listaDoctor);

	cout << "\n===========================================\n";

	cout << endl;
	cout << " ---> Ingrese el especialista que desee buscar: ";
	cin >> nombre;

	cout << " ---> Ingrese la especialidad que desee buscar: ";
	cin >> especialidad;

	buscarDoctor(listaDoctor, nombre, especialidad);
	ingreseHistorial(listaDoctor);

	return 0;
}

void insertar(Doctor &lista, char nombre[], char especialidad[]){
	Doctor nuevo = new (struct doctor);
	strcpy(nuevo -> nombre, nombre);
	strcpy(nuevo -> especialidad, especialidad);
	nuevo -> proximo = NULL;
	nuevo -> sgte = lista;
	lista = nuevo;
}

void imprimir(Doctor lista){
	Doctor tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial tmpHistorial = NULL;

	while (tmp){
		cout << endl;
		cout << ">>> El especialista es: " << tmp -> nombre << endl;
		tmpPaciente = tmp -> proximo;

		while (tmpPaciente){
			cout << ">>> El paciente es: " << tmpPaciente -> nombre << endl;
			tmpPaciente = tmpPaciente -> sgte;
		}

		while (tmpHistorial){
			cout << ">>> El historial del paciente medico es: " << tmpHistorial -> enfemerdad << endl;
			cout << ">>> El estado del paciente es: " << tmpHistorial -> estado << endl;
			cout << ">>> El tratamiento del paciente es: " << tmpHistorial -> tratamientos << endl;
			tmpHistorial = tmpHistorial -> sgte;
			tmpHistorial = tmpHistorial -> sgte;
		}
		tmp = tmp -> sgte;
	}
}

void ingresaPacientes(Doctor lista){
	int np;
	Doctor tmp = lista;
	Paciente paciente = NULL;

	while (tmp){
		cout << "\n>>> Inserte la cantidad de pacientes para el especialista [" << tmp -> nombre << "]: ";
		cin >> np;
		cout << endl;

		for (int i = 0; i < np; i++){
			paciente = new (struct paciente);
			
			cout << " ---> Paciente Num " << i + 1 << ": ";
			cin >> paciente -> nombre;
			paciente -> sgte = tmp -> proximo;
			tmp -> proximo = paciente;
		}
		tmp = tmp -> sgte;
	}
}

void ingreseHistorial(Doctor lista){
	int np;
	Doctor tmp = lista;
	Paciente paciente = NULL;
	Historial historialPaciente = NULL;

	while (tmp){
		cout << ">>> Historial medico de los pacientes asignados " << tmp ->nombre<<np + 1 << ": ";
		cin >> np;
		for (int i = 0; i < np; i++){
			historialPaciente = new (struct historialPaciente);

			cout << " ---> La enfermedad del paciente es: " << endl;
			cin >> historialPaciente -> enfemerdad;
			tmp -> historialPaciente;

			cout << " --> El estado del paciente es: " << endl;
			cin >> historialPaciente -> estado;

			cout << " --> Los tratamientos del paciente es: " << endl;
			cin >> historialPaciente -> tratamientos;
		}
		tmp = tmp -> sgte;
	}
}



void buscarDoctor(Doctor lista,char nombre[], char especialidad[])
{
    Doctor tmp = lista;
	Paciente tmpPaciente=NULL;
	Historial tmpHistorial = NULL;
	while(tmp)
	{
		if(!strcmp(tmp->nombre,nombre))
		{
		cout << ">>> El nombre del especialista es: " << tmp -> nombre << endl;
			tmpPaciente = tmp -> proximo;
			while(tmpPaciente)
			{
			cout << ">>> Los pacientes asignados son: " << tmpPaciente -> nombre << endl;
				tmpPaciente = tmpPaciente->sgte;
			}
			
			while (tmpHistorial){
			    cout << ">>>El Historial del paciente: " << tmpPaciente -> nombre << endl;
				cout << ">>>¿La enfermedad del paciente es? : " << tmpHistorial -> enfemerdad << endl;
				cout << ">>> El estado del paciente es: " << tmpHistorial -> estado << endl;
				cout << ">>> El tratamiento aplicado es: " << tmpHistorial -> tratamientos << endl;
				tmpHistorial = tmpHistorial -> sgte;
			}
			return;
		}
		tmp = tmp->sgte;
	if(tmp==NULL)
	{
	    cout << " ---> No hemos podido encontrar el nombre del especialista " << nombre << endl;
		cout << " ---> No hemos podido encontrar  su especialidad" << especialidad << endl;
	    
	    
	}
}
}
