#include <iostream>
using namespace std;

struct objeto{
    int numeroPila;
    struct objeto *delante;
};
 
typedef objeto *pila;

void errorRegistro(){
    cout << "\n====================================================================\n";
    cout << "\t\tOpcion incorrecta, vuelve a intentarlo.\n" <<
            "\tSolo puedes escribir los numeros entre el [1] y el [5].";
    cout << "\n====================================================================\n";
	cout << endl;
    system("pause");
    system("cls");
}

void menu(){
	int opcion;
    pila p = NULL;
    pila aux;
    int dato;
    int op;
    int x;

	do{ //Creando un menú de opciones
		cout << "\n.:.:. MENU DE OPCIONES .:.:.\n" << endl;
		cout << "[1]. APILAR." << endl;
		cout << "[2]. DESAPILAR." << endl;
		cout << "[3]. MOSTRAR PILA." << endl;
		cout << "[4]. ELIMINAR PILA." << endl;
		cout << "[5]. SALIR." << endl;

		cout << "\nPor favor, digite una opcion (1,2,3,4,5): ";
		cin >> opcion;
		
		switch(opcion){
			case 1:	//en caso escoja la opción 1
				system("cls");
                cout << "\n.:.:. BIENVENIDO - APILAR PILA .:.:." << endl;

                do{
                    cout<< "\n Ingrese el numero para apilar: ";
                    cin>> dato;

                    aux = new(struct objeto);
                    aux -> numeroPila = dato;
                    aux -> delante = p;
                    p = aux;

                    if ((dato == 0)){
						cout << endl << " ---> dato incorrecto, debe ser mayor a 0. Intentelo de nuevo." << endl;
					}

                }while (dato == 0);

                cout << "\n ---> numero apilado correctamente.\n";
                
				system("pause");

                break;
					
			case 2:	//en caso escoja la opción 2
				system("cls");

                    int num;
                    
                    aux = p;
                    num = aux -> numeroPila;
                    
                    p = aux -> delante;
                    delete(aux);
                    
                    cout << "\n ---> numero desapilado correctamente.\n\n";

				system("pause");

                break;

            case 3:	//en caso escoja la opción 3
				system("cls");
                cout << "\n.:.:. BIENVENIDO - MOSTRAR PILA .:.:.\n" << endl;

                if(p != NULL){
                    aux = p;
                    
                    while(aux != NULL){
                        cout << aux -> numeroPila << endl;
                        aux = aux -> delante;
                    }
                }
                else{
                    cout<< "\n ---> La pila esta vacia. \n\n";
                }

				system("pause");

                break;

            case 4:	//en caso escoja la opción 4
				system("cls");
                
                while( p != NULL){
                    aux = p;
                    p = aux -> delante;
                    delete(aux);
                }

                cout<<"\n ---> Pila eliminada correctamente.\n\n";

				system("pause");

                break;

			case 5: //en caso se desea salir el programa
            
                cout << endl;
                cout << "Gracias por usar el sistema, Hasta pronto!" << endl;
                cout << endl;
                exit(0);
                break;
			
			default:
			system("cls");
            errorRegistro();
		}
		system("cls");
	}while(opcion != 5);
}

int main(){
	system("cls");
	menu();
	return 0;
}