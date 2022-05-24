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
  struct doctor *sgte;
  struct paciente *proximo;
};

typedef struct paciente *TPaciente;
typedef struct doctor *TDoctor;

void insertar(TDoctor &lista,char nombre[]);
void imprimir(TDoctor lista);
void ingresaPacientes(TDoctor lista);
void buscarDoctor(TDoctor lista,char nombre[]);
int main()
{
	TDoctor listaDoctor=NULL;
	int nd,np;
	char nombre[20];
	cout<<"cantidad de doctores: ";cin>>nd;
	for(int i=0;i<nd;i++)
	{
		cout<<"Nombre del Dr. ("<<i<<"): ";cin>>nombre;
		insertar(listaDoctor,nombre);
	}
	ingresaPacientes(listaDoctor);
	cout<<endl<<"=================="<<endl;
	imprimir(listaDoctor);
	cout<<"=================="<<endl;
	cout<<"Dr. a buscar? ";cin>>nombre;
	buscarDoctor(listaDoctor,nombre);
	return 0;
}

void insertar(TDoctor &lista,char nombre[])
{
	TDoctor nuevo = new(struct doctor);
	strcpy(nuevo->nombre,nombre);
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
		cout<<"Doctor. "<<tmp->nombre<<endl;
		tmpPaciente = tmp->proximo;
		while(tmpPaciente)
		{
			cout<<"  [+] "<<tmpPaciente->nombre<<endl;
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
		cout<<"Cantidad de pacientes para el Dr. "<<tmp->nombre<<": ";cin>>np;
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

void buscarDoctor(TDoctor lista,char nombre[])
{
	TDoctor tmp = lista;
	TPaciente tmpPaciente=NULL;
	while(tmp)
	{
		if(!strcmp(tmp->nombre,nombre))
		{
			cout<<"Doctor. "<<tmp->nombre<<endl;
			tmpPaciente = tmp->proximo;
			while(tmpPaciente)
			{
				cout<<"  [+] "<<tmpPaciente->nombre<<endl;
				tmpPaciente = tmpPaciente->sgte;
			}
			return;
		}
		tmp = tmp->sgte;
	}
	if(tmp==NULL){cout<<"No se encontro el Doctor. "<<nombre<<endl;}
}