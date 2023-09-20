#include <iostream>
#include <string>


using namespace std;

class Mascota{
private:
    string nombreMascota;
    bool vacunado;
    int edad;
    float precio;
public:
    void setNombreMascota(){
        cout<<"ingrese el nombre de la Mascota: ";
        getline(cin, nombreMascota); // toma la linea entera, interpreto que no se corta en el espacio
        cout<<"\nNombre:"<<nombreMascota<<endl;
    }
    void setVacunado(){
        char vacuna;
        cout<<"ingrese true/false si esta o no vacunado el animal (t/f): ";
        cin>>vacuna;
        vacunado=(vacuna == 't' || vacuna == 'T'); //si es true pone automaticamente un 1, sino un 0
    }
    void setEdad(){
        cout<<"Ingrese la edad de la Mascota: ";
        cin>>edad;
    }
    void setPrecio(){
        cout<<"Ingrese el Precio de la Mascota: ";
        cin>>precio;
    }
};


class Gato{

};
/*
class Venta{
private:
    string fechaVenta;
    int precioVenta;
    Mascota mascotaVendida;

public:
    void ingresarFechaVenta(){
        string fecha;
        cout<<"En que fecha se vendio la mascota (dd/mm/aaaa)"<<endl;
        cin>>fecha;
        //verifica cada digito de la fecha ingresada para ver si esta en formato correcto
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

*/
int main() {
    //TiendaMascotas losTresHermanos;

    Mascota perro;
    Mascota gato;
    Mascota loro;

    perro.setNombreMascota();
    perro.setVacunado();
    perro.setEdad();
    perro.setPrecio();


    gato.setNombreMascota();
    gato.setVacunado();
    gato.setEdad();
    gato.setPrecio();


    loro.setNombreMascota();
    loro.setVacunado();
    loro.setEdad();
    loro.setPrecio();

    /*
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
*/
    return 0;
}
