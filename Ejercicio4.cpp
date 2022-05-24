#include <iostream>

using namespace std;

struct Curso{
	string nombre;
	string profesor;
	int creditos;
};

struct ListaCurso{
	Curso Cur[50];
	int cont;
};

struct Alumno{
	string codigo;
	string nombre;
	string apellido;
	int edad;
	string Nom_Curso[5];
	int cont_curso;
};

struct ListaAlumno{
	Alumno A[50];
	int cont;
};

void Inicia(ListaAlumno &X,ListaCurso &Y)
{
	X.cont = 0;
	Y.cont = 0;
}

void Registrar_Curso(ListaCurso &LC)
{
	cout<<"Ingrese el nombre del curso: "; cin>>LC.Cur[LC.cont].nombre;
	cout<<"Ingrese el profesor que dicta el curso: "; cin>>LC.Cur[LC.cont].profesor;
	cout<<"Ingrese el total de creditos: "; cin>>LC.Cur[LC.cont].creditos;
	LC.cont++;
}

void Modificar_Curso(ListaCurso &LC)
{
	string nom;
	int cont=0;
	cout<<"Ingrese el nombre del curso a modificar: "; cin>>nom;
	for(int i=0;i<LC.cont;i++)
	{
		if(nom==LC.Cur[i].nombre)
		{
			cout<<"Ingrese el profesor que dicta el curso: "; cin>>LC.Cur[i].profesor;
			cout<<"Ingrese el total de creditos: "; cin>>LC.Cur[i].creditos;
		}
		else
		{
			cont++;
		}
	}
	if(cont==LC.cont)
	{
		cout<<"Curso no encontrado"<<endl;
	}
}

void Registrar_Alumno(ListaAlumno &LA,ListaCurso LC)
{
	int flag;
	cout<<"Ingrese el codigo del alumno: "; cin>>LA.A[LA.cont].codigo;
	cout<<"Ingrese el nombre del alumno: "; cin>>LA.A[LA.cont].nombre;
	cout<<"Ingrese el apellido del alumno: "; cin>>LA.A[LA.cont].apellido;
	cout<<"Ingrese la edad del alumno: "; cin>>LA.A[LA.cont].edad;
	cout<<"Ingrese la cantidad de cursos a llevar: "; cin>>LA.A[LA.cont].cont_curso;
	for(int i=0;i<LA.A[LA.cont].cont_curso;i++)
	{
		flag = 0;
		do
		{
			cout<<"CURSO "<<i+1<<endl;
			cout<<"Ingrese el nombre del curso: "; cin>>LA.A[LA.cont].Nom_Curso[i];
			for(int j=0;j<LC.cont;j++)
			{
				if(LA.A[LA.cont].Nom_Curso[i]==LC.Cur[j].nombre)
				{
					flag=1;
				}
			}
		}while(!(flag==1));
	}
	LA.cont++;
}

void Listar_Alumno(ListaAlumno LA)
{
	for(int i=0;i<LA.cont;i++)
	{
		cout<<"---------------------------------------------------"<<endl;
		cout<<"NOMBRE: "<<LA.A[i].nombre<<endl;
		cout<<"APELLIDO: "<<LA.A[i].apellido<<endl;
		cout<<"CODIGO: "<<LA.A[i].codigo<<endl;
		cout<<"EDAD: "<<LA.A[i].edad<<endl;
		for(int j=0;j<LA.A[i].cont_curso;j++)
		{
			cout<<"CURSO LLEVADO: "<<LA.A[i].Nom_Curso[j]<<endl;
		}
	}
	cout<<"---------------------------------------------------"<<endl;
}

int main()
{
	ListaCurso LC;
	ListaAlumno LA;
	Inicia(LA,LC);
	int op=0;
	do
	{
		cout<<"** MENU DE OPCIONES **"<<endl;
		cout<<"1) Registrar Curso"<<endl;
		cout<<"2) Modificar Curso"<<endl;
		cout<<"3) Registrar Alumno"<<endl;
		cout<<"4) Listar Alumnos"<<endl;
		cout<<"Ingrese una opcion: "; cin>>op;
		switch(op)
		{
			case 1:
				Registrar_Curso(LC);
				break;
			case 2:
				Modificar_Curso(LC);
				break;
			case 3:
				Registrar_Alumno(LA,LC);
				break;
			case 4:
				Listar_Alumno(LA);
				break;			
		}
	}while(!(op==6));
	return 0;
}
