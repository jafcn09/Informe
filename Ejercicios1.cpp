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
};

typedef struct paciente *TPaciente;
typedef struct doctor *TDoctor;

void insertar(TDoctor &lista,char nombre[], char especialidad[]);
void imprimir(TDoctor lista);
void ingresaPacientes(TDoctor lista);
void buscarDoctor(TDoctor lista,char nombre[], char especialidad[]);
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
	while(tmp)
	{
		cout<<"el especialista es "<<tmp->nombre<<endl;
		tmpPaciente = tmp->proximo;
		while(tmpPaciente)
		{
			cout<<"el paciente es "<<tmpPaciente->nombre<<endl;
			tmpPaciente = tmpPaciente->sgte;
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

void buscarDoctor(TDoctor lista,char nombre[], char especialidad[])
{
	TDoctor tmp = lista;
	TPaciente tmpPaciente=NULL;
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
		}
		tmp = tmp->sgte;
	}
	if(tmp==NULL){
		cout<<"No hemos podido encontrar el nombre del especialista "<<nombre<<endl;
		cout<<"No hemos podido encontrar  su especialidad"<<especialidad<<endl;
	
	}
}
