#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mascota{
private:
    string nombreMascota;

    int edad;
    double precioVenta;
    string FormaDeComunicarse;
protected:
    bool vacunado;//nose porque me tira error si no esta en protected, pero en los demas no
public:
    Mascota(const string& n, int v, int e, double p) : nombreMascota(n), vacunado(v), edad(e), precioVenta(p) {//constructor con los datos que le mando
    }
    virtual void comunicacion(){
        cout<<"No se como comunicarme, no soy de ninguna especie"<<endl;
    }
    string getNombreMascota() const {
        return nombreMascota;
    }

};

class Gato : public Mascota{
private:
    string Pelaje;
public:
    void setPelaje(){
        cout<<"ingrese el pelaje del Gato: ";
        getline(cin, Pelaje); // toma la linea entera, no se corta en el espacio
    }
    Gato(const string& nombre, bool vacuna, int edad, double precio) : Mascota(nombre, vacunado, edad, precio) {}

    void comunicacion() {
        cout << getNombreMascota() << " dice: Miau" << std::endl;
    }
};

class Pajaro : public Mascota{
private:
    string Plumaje;
public:
    void setPlumaje(){
        cout<<"ingrese el plumaje del Pajaro: ";
        getline(cin, Plumaje); // toma la linea entera, interpreto que no se corta en el espacio
    }
    Pajaro(const string& nombre, bool vacuna, int edad, double precio) : Mascota(nombre, vacunado, edad, precio) {}
    void comunicacion() {
        cout << getNombreMascota() << " dice: Pio Pio" << std::endl;
    }
};

class Perro : public Mascota{
private:
    string Raza;
public:
    void setRaza(){
        cout<<"ingrese el raza del Pajaro: ";
        getline(cin, Raza); // toma la linea entera, interpreto que no se corta en el espacio
    }
    Perro(const string& nombre, bool vacuna, int edad, double precio) : Mascota(nombre, vacunado, edad, precio) {}
    void comunicacion() {
        cout << getNombreMascota() << " dice: Guau" << std::endl;
    }
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
        int precioVenta;
        cout<<"A que precioVenta se vendio la mascota"<<endl;
        cin>>precioVenta;
        precioVenta=precioVenta;
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

void NuevaMascota() {
    string nombre;
    int edad, vacuna;
    float precio;
    char vac;
    cout << "ingrese el nombre de la Mascota:";
    //cin.ignore();
    getline(cin, nombre); // toma la linea entera, interpreto que no se corta en el espacio
    cout<<"ingrese true/false si esta o no vacunado el animal (t/f)";
    cin>>vac;
    vacuna=(vac == 't' || vac == 'T')?1:0;

    cout << "Ingrese la edad de la Mascota:";
    cin >> edad;
    cout << "Ingrese el Precio de la Mascota:";
    cin >> precio;
    Mascota M1(nombre, vac, edad, precio);
}



int main() {
    //TiendaMascotas losTresHermanos;
    //NuevaMascota();
    Perro miPerro("Buddy",1, 3, 500.0);
    Gato miGato("Whiskers", 1, 2, 300.0);
    Pajaro miPajaro("Tweety", 0, 1, 100.0);

    Mascota* animales[] = {&miPerro, &miGato, &miPajaro};

    for (int i=0;i<3;i++) {
        animales[i]->comunicacion();
    }


    return 0;
}

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
