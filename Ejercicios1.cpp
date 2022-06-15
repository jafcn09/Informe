#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

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
	struct  camadisponible *habita;
	struct farmacia * lote;
};

struct historialPaciente{
	char enfemerdad[50];
	char estado[50];
	char tratamientos[50];
	struct historialPaciente *sgte;
};

struct camadisponible{
    char cantidad[50];
    char ubicacion[50];
    char nombre_cama[50];
    struct camadisponible *sgte;
};

struct farmacia{
	char cantidades[50];
	char codigo_medicamento[50];
	char tipo_medicamento[50];
	char estado_medicamento[50];
	struct farmacia *sgte;
};

typedef struct paciente *Paciente;
typedef struct doctor *Doctor;
typedef struct historialPaciente *Historial;
typedef struct camadisponible *Camas;
typedef struct farmacia *Medicamentos;

void insertar(Doctor &lista, char nombre[], char especialidad[]){
	Doctor nuevo = new (struct doctor);
	strcpy(nuevo -> nombre, nombre);
	strcpy(nuevo -> especialidad, especialidad);
	nuevo -> proximo = NULL;
	nuevo -> sgte = lista;
	lista = nuevo;
}

void ingresaPacientes(Doctor lista){
	int np;
	Doctor tmp = lista;
	Paciente paciente = NULL;

	while (tmp){
		cout << "\n>>> Ingrese la cantidad de pacientes para el especialista [" << tmp -> nombre << "]: ";
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
	cout << endl;
	
	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Paciente(s) registrado(s) correctamente.";Sleep(2000);
	cout << endl;
}

void ingreseHistorial(Doctor lista){
	int np;
	Doctor tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial historialPaciente = NULL;

	while (tmp){
		Sleep(1000);
		cout << ">>> Ingrese el numero de historial medico, recuerde que su medico es [" << tmp-> nombre<< "]: ";
		cin >> np;
		cout << endl;
		
		for (int i = 0; i < np; i++){
			historialPaciente = new (struct historialPaciente);

			cout << " ---> Historial [" << i + 1 << "]: La enfermedad del paciente es: ";
			cin >> historialPaciente -> enfemerdad;

			cout << " ---> Historial [" << i + 1 << "]: El estado del paciente es: ";
			cin >> historialPaciente -> estado;

			cout << " ---> Historial [" << i + 1 << "]: Los tratamientos del paciente es: ";
			cin >> historialPaciente -> tratamientos;
		}
		tmp = tmp -> sgte;
	}

	cout << endl;

	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Historial(es) medico(s) registrado(s) correctamente.";Sleep(2000);
}

void ingreseCamas(Doctor lista){
    int np;
	Doctor tmp = lista;
	Camas camadisponible = NULL;

	while (tmp){
		cout << endl;
		cout << "\n>>> Ingrese la cantidad de habitaciones para las camas disponibles, generadas para el paciente: ";
		cin >> np;
		cout << endl;

		for (int i = 0; i < np; i++){
			camadisponible = new (struct camadisponible);
			
			cout << " ---> Ingrese la cantidad de camas disponibles en la habitacion [" << i + 1 << "]: ";
			cin >> camadisponible -> cantidad;
			cout << " ---> Ingrese el piso y pasillo de la habitacion [" << i + 1 << "]: ";
			cin >> camadisponible -> ubicacion;
			cout << " ---> Ingrese un alias para la cama del paciente: ";
			cin >> camadisponible -> nombre_cama;
		}
		tmp = tmp -> sgte;
	}
	cout << endl;
	
	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Cama(s) registrada(s) correctamente.";Sleep(2000);
    
}
void ingreseMedicamentos(Doctor lista){
    int np;
    Doctor tmp = lista;
    Medicamentos farmacia = NULL;
	
    while (tmp){
		cout << endl;
		cout << "\n>>> Ingrese la cantidad de medicamentos para el paciente: ";
		cin >> np;
		cout << endl;

		for (int i = 0; i < np; i++){
			farmacia = new (struct farmacia);

			cout << " ---> El codigo del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> codigo_medicamento;
			cout << " ---> nombre del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> tipo_medicamento;
			cout << " ---> El estado del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> estado_medicamento;
		}
		tmp = tmp -> sgte;
	}
	cout << endl;
	
	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Medicamento(s) registrado(s) correctamente.";Sleep(2000);
	cout << endl;
}

void buscarDoctor(Doctor lista, char nombre[], char especialidad[]){
	Doctor tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial tmpHistorial = NULL;
    Medicamentos tmpMedicamentos = NULL;
	while (tmp){
		if (!strcmp(tmp -> nombre, nombre)){
			
			int i = 0;
			Sleep(500);
			cout << " \n ---> Buscando especialista...\n";
			Sleep(2000);
		
			cout << "\n===========================================\n";
			cout << "\t  Especialista encontrado";
			cout << "\n===========================================\n";
			Sleep(3000);
		
			cout << endl;
			cout << ">>> El nombre del especialista es: " << tmp -> nombre << endl;
			tmpPaciente = tmp -> proximo;
			cout << endl;

			while (tmpPaciente){
				cout << ">>> El paciente [" << i++ + 1 << "] del doctor [" << tmp -> nombre << "] es: " << tmpPaciente -> nombre << endl;
				tmpPaciente = tmpPaciente -> sgte;
			}
			cout << "\n===========================================\n";
			cout << endl;
			
			return;
		}
		tmp = tmp -> sgte;

		if (tmp == NULL){
			Sleep(500);
			cout << " \n ---> Buscando especialista...\n";
			Sleep(2000);

			cout << "\n===========================================\n";
			cout << "\t  Especialista no encontrado";
			cout << "\n===========================================\n";
			Sleep(3000);
			
			cout << endl;
			cout << " ---> No hemos podido encontrar el nombre del especialista [" << nombre << "]." << endl;
			cout << " ---> No hemos podido encontrar la especialidad(es) [" << especialidad << "]." << endl;
			cout << "\n===========================================\n";
			cout << endl;
			Sleep(1000);
			exit(0);
		}
	}
}

void imprimir(Doctor lista){
	Doctor tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial tmpHistorial = NULL;
	Camas tmpCamas = NULL;
	Medicamentos tmpMedicamentos = NULL;

	while (tmp){

		int i = 0;

		cout << endl;
		cout << ">>> El especialista es: " << tmp -> nombre << endl;
		tmpPaciente = tmp -> proximo;
		tmpCamas = tmp -> habita;
		tmpMedicamentos = tmp -> lote;
		cout << endl;
		
		if (tmpPaciente){
			cout << ">>> El paciente [" << i++ + 1 << "] es: " << tmpPaciente -> nombre << endl;
			tmpPaciente = tmpPaciente -> sgte;
		}

		if (tmpHistorial){
			cout << ">>> El historial del paciente medico es: " << tmpHistorial -> enfemerdad << endl;
			cout << ">>> El estado del paciente es: " << tmpHistorial -> estado << endl;
			cout << ">>> El tratamiento del paciente es: " << tmpHistorial -> tratamientos << endl;
			tmpHistorial = tmpHistorial -> sgte;
		}

		if (tmpCamas){
			cout << ">>> La cantidad de cama disponible[" << i++ + 1 << "] es: " << tmpCamas -> cantidad << endl;
			tmpCamas = tmpCamas -> sgte;
		    
		}
		
		if (tmpMedicamentos){
		    cout << ">>> La cantidad de medicamentos registrados[" << i++ + 1 << "] es: " << tmpMedicamentos -> cantidades << endl;
		    tmpMedicamentos = tmpMedicamentos -> sgte;
		}
		
		return;
	}
}

int main(){
	Doctor listaDoctor = NULL;
	int nd, np;
	char nombre[20];
	char especialidad[100];
	
	system("cls");

	cout << ".:.:. BIENVENIDO AL HOSPITAL CAYETANO HEREDIA .:.:." << endl;

	Sleep(2000);

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

	cout << endl;

	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Doctor(es) registrado(s) correctamente.";Sleep(2000);
	cout << endl;

	ingresaPacientes(listaDoctor);

	cout << endl;
	cout << " ---> Ingrese el nombre del especialista que desee buscar: ";
	cin >> nombre;

	cout << " ---> Ingrese la especialidad que desee buscar: ";
	cin >> especialidad;

	buscarDoctor(listaDoctor, nombre, especialidad);
	
	ingreseHistorial(listaDoctor);
    ingreseCamas(listaDoctor);
    ingreseMedicamentos(listaDoctor);
	cout << endl;
	cout << "  ";
	
	cout << " Imprimiendo datos, espere un momento...";Sleep(2000);
	cout << endl;

	cout << "\n===========================================\n";
	cout << "\tRegistro medico y paciente:";
	cout << "\n===========================================\n";
	imprimir(listaDoctor);
	cout << "\n===========================================\n";

	cout << "\n===========================================\n";
	cout << "\tRegistro de medicamento disponible:";
	cout << "\n===========================================\n";
	// imprimir();
	cout << "\n===========================================\n";
	
	cout << "\n===========================================\n";
	cout << "\tRegistro de camas disponibles en el hospital:";
	cout << "\n===========================================\n";
	// imprimir();
	cout << "\n===========================================\n";

	cout << "\n===========================================\n";
	cout << "\tRegistro de medicamento disponible:";
	cout << "\n===========================================\n";
	// imprimir();
	cout << "\n===========================================\n";
	cout << endl;

	return 0;
}
