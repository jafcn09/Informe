#include <iostream>
#include <string>
using namespace std;
//Creación de estructura para las promociones que posee el restaurante
struct promos{
    string promo1="PROMO PERSONAL: 1/4 POLLO PARTE PECHO + PAPAS FRITAS REGULAR + ENSALADA CLASICA + GASEOSA INCA KOLA MEDIANA";
    string promo2="PROMO DUO: 1/2 POLLO + PAPAS FRITAS MEDIANAS + ENSALADA CLASICA + ROLLS + INCA KOLA 1 LT";
    string promo3="LA INFALTABLE: 1 POLLO + PAPAS FRITAS GRANDES + ENSALADA CLASICA + INCA COLA 1.5 LT";
};
//Creacion de estructura para un cliente de el restaurante
struct Cliente{
    string nom="Cliente";
    string correo="";
    int telefono;
    string dir="";
};
typedef struct Cliente Cl;
//Creacion de estructura para el restaurante
struct Restaurante{
    string local;
    int telefono=5008800;
    int mesa=0;
    string correo="contacto@villachicken.com.pe";
    promos p;
    Cl V_C_Cliente;
};
typedef struct Restaurante Res;
//Creacion de la funcion para registrar a un cliente
void Registrar(Res *V_C){
    cout<<"Ingrese nombre del cliente:";
    cin>>V_C->V_C_Cliente.nom;
    cout<<"Ingrese telefono del cliente:";
    cin>>V_C->V_C_Cliente.telefono;
    cout<<"Ingrese correo del cliente:";
    cin>>V_C->V_C_Cliente.correo;
    cout<<"Ingrese direccion del cliente:";
    cin>>V_C->V_C_Cliente.dir;
    cout<<"\nSe ha registrado correctamente con los siguientes datos:\n";
    cout<<"Nombre: "<<V_C->V_C_Cliente.nom<<"\n";
    cout<<"Telefono: "<<V_C->V_C_Cliente.telefono<<"\n";
    cout<<"Correo: "<<V_C->V_C_Cliente.correo<<"\n";
    cout<<"Direccion: "<<V_C->V_C_Cliente.dir<<"\n";
}
//Creacion de la funcion para reservar una mesa por cliente
int reservar_mesa(Res *V_C){
    cout<<"Las mesas disponibles van del 1 al 30, elija 1: ";
    cin>>V_C->mesa;
    if(V_C->mesa==0){
        return 0;
    }
    else{
        return V_C->mesa;
    }
}
//Creacion de la funcion para mostrar las promociones disponibles
void mostrar_promos(Res *V_C){
    cout<<"Nuestras promociones disponibles son: "<<"\n";
    cout<<"-"<<V_C->p.promo1<<"\n";
    cout<<"-"<<V_C->p.promo2<<"\n";
    cout<<"-"<<V_C->p.promo3<<"\n";
}
//Creacion de la funcion para mostrar las formas de contacto del restaurante
void mostrar_contacto(Res *V_C){
    cout<<"Se puede contactar con nosotros mediante: "<<"\n";
    cout<<"-Telefono: "<<V_C->telefono<<"\n";
    cout<<"-Correo electronico: "<<V_C->correo<<"\n";
}
//Ejecucion del programa
int main()
{
    //Inicializacion de algunas variables
    Res villachicken;
    Res *V_C=&villachicken;
    int x=0;
    //Se muestra el menu
    cout<<"¿Que desea hacer hoy?\n";
    cout<<"1. Registrarse\n";
    cout<<"2. Reservar mesa\n";
    cout<<"3. Ver promociones disponibles\n";
    cout<<"4. Ver formas de contacto\n";
    int opc = 0;
    //Seleccion de opcion
    cout<<"Ingrese una opcion (1, 2, 3 o 4): ";
    cin>>opc;
    switch(opc){
        case 1:
            Registrar(V_C);
            break;
        case 2:
            x = reservar_mesa(V_C);
            if(x<=0 or x>30){
                cout<<V_C->V_C_Cliente.nom<<", no seleccionó una mesa o seleccionó una incorrecta.";
            }
            else{
                cout<<V_C->V_C_Cliente.nom<<", la mesa reservada es la mesa: "<<x;
            }
            break;
        case 3:
            mostrar_promos(V_C);
            break;
        case 4:
            mostrar_contacto(V_C);
            break;
        default:
            cout<<"No es una opcion correcta";
            break;
    }
    string ans = "";
    cout<<"\n¿Desea hacer algo más? (Si o No): ";
    cin>>ans;
    //Bucle hasta que el usuario ya no quiera realizar mas acciones
    while(ans=="Si"){
        cout<<"\n¿Que desea hacer?\n";
        cout<<"1. Registrarse\n";
        cout<<"2. Reservar mesa\n";
        cout<<"3. Ver promociones disponibles\n";
        cout<<"4. Ver formas de contacto\n";
        int opc = 0;
        cout<<"Ingrese una opcion (1, 2, 3 o 4): ";
        cin>>opc;
        switch(opc){
            case 1:
                Registrar(V_C);
                break;
            case 2:
                x = reservar_mesa(V_C);
                if(x<=0 or x>30){
                    cout<<V_C->V_C_Cliente.nom<<", no seleccionó una mesa o seleccionó una incorrecta.";
                }
                else{
                    cout<<V_C->V_C_Cliente.nom<<", la mesa reservada es la mesa: "<<x;
                }
                break;
            case 3:
                mostrar_promos(V_C);
                break;
            case 4:
                mostrar_contacto(V_C);
                break;
            default:
                cout<<"No es una opcion correcta";
                break;
        }
        cout<<"\n¿Desea hacer algo más? (Si o No): ";
        cin>>ans;
    }
    //Agradecimiento
    cout<<V_C->V_C_Cliente.nom<<". ¡Gracias por preferir Villa Chicken!";
    return 0;
}