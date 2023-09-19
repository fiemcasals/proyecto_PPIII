#include <iostream>
#include <string>

#include <sstream> // Agrega la biblioteca para manipular strings

//el chat me dijo que podia agregarla pero yo ya tengo la iostream...

using namespace std;

class Mascota{
private:
    string nombreMascota;
    bool vacunado;
public:
    void modificarNombreMascota(){
        string nombre;
        cout<<"ingrese el tipo / raza de la mascota"<<endl;
        cin.ignore();//limpia el buffer de entrada
        getline(cin, nombre); // toma la linea entera, interpreto que no se corta en el espacio

        nombreMascota=nombre;
    }
    void modificarVacunado(){
        char vacuna;
        cout<<"ingrese true/false si esta o no vacunado el animal (t/f)"<<endl;
        cin.ignore();
        cin>>vacuna;

        vacunado=(vacuna == 't' || vacuna == 'T');
    }
};

class Venta{
private:
    string fechaVenta;
    int precioVenta;
    Mascota mascotaVendida;

public:
    void ingresarFechaVenta(){
        string fecha;
        cout<<"En que fecha se vendio la mascota (19092023)"<<endl;
        cin>>fecha;

        while (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/' ||
            !isdigit(fecha[0]) || !isdigit(fecha[1]) || !isdigit(fecha[3]) ||
            !isdigit(fecha[4]) || !isdigit(fecha[6]) || !isdigit(fecha[7]) ||
            !isdigit(fecha[8]) || !isdigit(fecha[9])) {
            cout << "Formato de fecha inválido. Use dd/mm/aaaa." << endl;
            ingresarFechaVenta(); // Vuelve a pedir la fecha
        }

        fechaVenta=fecha;
    }
    void ingresarPrecioVenta(){
        int precio;
        cout<<"A que precio se vendio la mascota"<<endl;
        cin>>precio;
        precioVenta=precio;
    }
    void definirMascotaVendida(Mascota MascotaVendida){

        mascotaVendida=MascotaVendida;
    }
};

class TiendaMascotas{
private:
    Venta listaVentas[100];
    int totalVentasRealizadas=0;
public:
    void agregarVenta(Venta ventaMascotaVendida){
        if (totalVentasRealizadas<100){
            totalVentasRealizadas++;
            listaVentas[totalVentasRealizadas-1]=ventaMascotaVendida;
        }
    }
    void consultaVenta(){
        cout<<"se vendio un total de "<<totalVentasRealizadas<<" mascotas"<<endl;
    }
};


int main() {
    TiendaMascotas losTresHermanos;

    Mascota perro;
    Mascota gato;
    Mascota loro;

    perro.modificarNombreMascota();
    perro.modificarVacunado();

    gato.modificarNombreMascota();
    gato.modificarVacunado();

    loro.modificarNombreMascota();
    loro.modificarVacunado();

    Venta primera;
    Venta segunda;

    primera.definirMascotaVendida(perro);
    primera.ingresarFechaVenta();
    primera.ingresarPrecioVenta();

    segunda.definirMascotaVendida(gato);
    segunda.ingresarFechaVenta();
    segunda.ingresarPrecioVenta();

    losTresHermanos.agregarVenta(primera);
    losTresHermanos.agregarVenta(segunda);
    losTresHermanos.consultaVenta();

    return 0;
}
