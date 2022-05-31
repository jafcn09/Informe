#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


struct paciente
{
  char nombre[20];
  struct paciente *sgte;
};

struct doctor
{
  char nombre[20];
  char especialidad[100];
  struct doctor *sgte;
  struct paciente *proximo;
  struct carga * historial_paciente;
};

struct historial_paciente {
    char enfemerdad[50];
    char estado[50];
    char tratamientos[50];
    struct historial_paciente * sgte;
};
typedef struct paciente *TPaciente;
typedef struct doctor *TDoctor;
typedef struct historial_paciente *THistorial;

void insertar(TDoctor &lista,char nombre[], char especialidad[]);
void imprimir(TDoctor lista);
void ingresaPacientes(TDoctor lista);
void buscarDoctor(TDoctor lista,char nombre[], char especialidad[]);

void ingreseHistorial(TDoctor lista);

int main()
{
	TDoctor listaDoctor=NULL;
	int nd,np;
	char nombre[20];
	char especialidad[100];
	cout<<"Bienvenido al hospital cayetano heredia"<<endl;
	cout<<"cantidad de especialistas: ";cin>>nd;
	for(int i=0;i<nd;i++)
	{
		cout<<"Nombre del especialista ("<<i<<"): ";cin>>nombre;
		cout<<"ingrese su especialidad ("<<i<<"): ";cin>>especialidad;
		insertar(listaDoctor,nombre, especialidad);
	}
	ingresaPacientes(listaDoctor);
	cout<<endl<<"=================="<<endl;
	imprimir(listaDoctor);
	cout<<"=================="<<endl;
	cout<<"Que especialista desea buscar? ";cin>>nombre;
	cout<<"Cual es la especialidad a buscar? ";cin>>especialidad;
	
	buscarDoctor(listaDoctor,nombre, especialidad);
	ingreseHistorial(listaDoctor);
	return 0;
}

void insertar(TDoctor &lista,char nombre[], char especialidad[])
{
	TDoctor nuevo = new(struct doctor);
	strcpy(nuevo->nombre,nombre);
	strcpy(nuevo-> especialidad, especialidad);
	nuevo->proximo = NULL;
	nuevo->sgte = lista;
	lista = nuevo;
}

void imprimir(TDoctor lista)
{
	TDoctor tmp = lista;
	TPaciente tmpPaciente=NULL;
	THistorial tmpHistorial = NULL;
	while(tmp)
	{
		cout<<"el especialista es "<<tmp->nombre<<endl;
		tmpPaciente = tmp->proximo;
		while(tmpPaciente)
		{
			cout<<"el paciente es "<<tmpPaciente->nombre<<endl;
			tmpPaciente = tmpPaciente->sgte;
		}	while(tmpHistorial)
		{
		    cout<<"Este es el historial medico del paciente"<<tmpHistorial->enfemerdad<<endl;
		    cout<<"El estado del paciente sera"<<tmpHistorial->estado<<endl;
		       cout<<"Que tratamiento desea aplicar"<<tmpHistorial->tratamientos<<endl;
		    tmpHistorial = tmpHistorial->sgte;
		    tmpHistorial = tmpHistorial->sgte;
		}
		tmp = tmp->sgte;
	}
}

void ingresaPacientes(TDoctor lista)
{
	int np;
	TDoctor tmp = lista;
	TPaciente paciente=NULL;
	while(tmp)
	{
		cout<<"Cantidad de pacientes para el especialista "<<tmp->nombre<<": ";cin>>np;
		for(int i=0;i<np;i++)
		{
			paciente = new(struct paciente);
			cout<<"Paciente "<<i<<" : ";
			cin>>paciente->nombre;
			paciente->sgte = tmp->proximo;
			tmp->proximo = paciente;
		}
		tmp = tmp->sgte;
	}
}

void ingreseHistorial(TDoctor lista){
    int np;
    TDoctor tmp = lista;
    THistorial historial_paciente = NULL;

    while(tmp){
       cout<<"Historial medico de los pacientes asignados"<<tmp->historial_paciente<<":";cin>>np;
        for(int i=0;i<np;i++) {
       historial_paciente = new(struct historial_paciente);
       cout<<"Su enfermedad es:"<<endl;
       cin>>historial_paciente->enfemerdad;
    tmp->historial_paciente;
       cout<<"El estado del paciente es:"<<endl;
       cin>>historial_paciente->estado;
       cout<<"¿Que tratamientos aplico?"<<endl;
            cin>>historial_paciente->tratamientos;
    }
    tmp = tmp -> sgte;
}

}
void buscarDoctor(TDoctor lista,char nombre[], char especialidad[])
{
	TDoctor tmp = lista;
	TPaciente tmpPaciente=NULL;
	THistorial tmpHistorial= NULL;
	while(tmp)
	{
		if(!strcmp(tmp->nombre,nombre))
		{
			cout<<"el nombre del especialista es. "<<tmp->nombre<<endl;
			tmpPaciente = tmp->proximo;
			while(tmpPaciente)
			{
				cout<<"Estos son las pacientes asignados: "<<tmpPaciente->nombre<<endl;
				tmpPaciente = tmpPaciente->sgte;
			}
			while(tmpHistorial){
			    cout<<"Este es el historial de los pacientes:"<<tmpHistorial->enfemerdad<<endl;
			        cout<<"Su estado sera:"<<tmpHistorial->estado<<endl;
			         cout<<"El tratamiento aplicado es:"<<tmpHistorial->tratamientos<<endl;
			    tmpHistorial = tmpHistorial->sgte;
			    
			}
			return;
		}else if(!strcmp(tmp->especialidad,especialidad))
		{
			cout<<"su especialidad es. "<<tmp->especialidad<<endl;
			tmpPaciente = tmp->proximo;
			while(tmpPaciente)
			{
				cout<<"Estos son las pacientes asignados: "<<tmpPaciente->nombre<<endl;
				tmpPaciente = tmpPaciente->sgte;
			}
			return;
		}	while(tmpHistorial){
			    cout<<"Este es el historial de los pacientes:"<<tmpHistorial->enfemerdad<<endl;
			        cout<<"Su estado sera:"<<tmpHistorial->estado<<endl;
			               cout<<"Su estado sera:"<<tmpHistorial->tratamientos<<endl;
			    tmpHistorial = tmpHistorial->sgte;
			    
			}
			return;
	}
	if(tmp==NULL){
		cout<<"No hemos podido encontrar el nombre del especialista "<<nombre<<endl;
		cout<<"No hemos podido encontrar  su especialidad"<<especialidad<<endl;
	
	}
}
