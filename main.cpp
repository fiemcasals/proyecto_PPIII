#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mascota{
protected: //para que las clases hijas puedan heredar sus atributos
    string nombreMascota;
    int edad;
    double precioVenta;
    bool vacunado;
public:
    Mascota(const string& n, int v, int e, double p) : nombreMascota(n), vacunado(v), edad(e), precioVenta(p) {//constructor con los datos que le mando
    }
    virtual void comunicacion(){
        cout<<"No se como comunicarme, no soy de ninguna especie"<<endl;
    }
    string getNombreMascota() const {
        return nombreMascota;
    }
    bool getVacunado() const {
        return vacunado;
    }

    double getPrecioVenta() const {
        return precioVenta;
    }
    int getEdad() const {
        return edad;
    }
    void Vacunar() {
        vacunado = 1;
    }
};

class Gato : public Mascota{
private:
    string pelaje;
public:
    Gato(const string& nombre, bool vacuna, int edad, double precio, const string& pelaje) : Mascota(nombre, vacunado, edad, precio) , pelaje(pelaje){}

    void comunicacion() {
        cout << getNombreMascota() << " dice: Miau" << endl;
    }
};

class Pajaro : public Mascota{
private:
    string plumaje;
public:
    Pajaro(const string& nombre, bool vacuna, int edad, double precio, const string& plumaje) : Mascota(nombre, vacunado, edad, precio) , plumaje(plumaje) {}
    void comunicacion() {
        cout << getNombreMascota() << " dice: Pio Pio" << endl;
    }
};

class Perro : public Mascota{
private:
    string raza;
public:
    Perro(const string& nombre, bool vacuna, int edad, double precio, const string& raza) : Mascota(nombre, vacunado, edad, precio) , raza(raza) {}
    void comunicacion() {
        cout << getNombreMascota() << " dice: Guau" << endl;
    }
};

Mascota* crearNuevaMascota() {
    string nombre;
    int edad, vacuna;
    float precio;
    char vac;
    int tipo;

    cout << "ingrese el nombre de la Mascota:";
    cin >> nombre;

    cout<<"ingrese true/false si esta o no vacunado el animal (t/f)";
    cin>>vac;
    vacuna=(vac == 't' || vac == 'T')?1:0;

    cout << "Ingrese la edad de la Mascota:";
    cin >> edad;
    cout << "Ingrese el Precio de la Mascota:";
    cin >> precio;

    cout << "Seleccione el tipo de animal (1: Perro, 2: Gato, 3: Pajaro): ";
    cin >> tipo;

    Mascota* nuevaMascota = NULL;

    switch (tipo) {
        case 1: {
            string raza;
            cout << "Ingrese la raza del perro: ";
            cin >> raza;
            nuevaMascota = new Perro(nombre, vacuna, edad, precio, raza);
            break;
        }
        case 2: {
            string pelaje;
            cout << "Ingrese el tipo de pelaje del gato: ";
            cin >> pelaje;
            nuevaMascota = new Gato(nombre, vacuna, edad, precio, pelaje);
            break;
        }
        case 3: {
            string plumaje;
            cout << "Ingrese el tipo de plumaje del pajaro: ";
            cin >> plumaje;
            nuevaMascota = new Pajaro(nombre, vacuna, edad, precio, plumaje);
            break;
        }
        default:
            cout << "Tipo de animal no válido." << endl;
            break;
    }

    return nuevaMascota;
}

class Venta {
private:
    string fechaVenta;
    vector<Mascota> mascotaVendida;
    float ventaTotal;

public:
    Venta(): ventaTotal(0){};
    int getMascotaVendidaCount() const {
        return mascotaVendida.size();
    }
    void setMascotaVendida(const Mascota &mascota) {
        mascotaVendida.push_back(mascota);//inserto al final del vector la Mascota.
    }

    void ingresarFechaVenta() {
        cout << "En que fecha se vendio la mascota (dd/mm/aaaa): ";
        cin >> fechaVenta;
    }

    string getFechaVenta() const {
        return fechaVenta;
    }

    const Mascota &getMascotaVendida(int index) const { //estos dos const hacen referencia a que no se modificara en la funcion al objeto llamado ni se puede modificar el objeto retornado
        return mascotaVendida[index];
    }

};

class TiendaMascotas {
private:
    vector<Venta> ventas;
    vector<Mascota *> stock;
    int totalRecaudado; // Esta variable se inicializará en el constructor

public:
    TiendaMascotas() : totalRecaudado(0) {} // Inicializa totalRecaudado en 0 en el constructor

    void sumarVenta(int dinero) {
        totalRecaudado += dinero;
    }

    void agregarVenta(const Venta &ventaMascota) {
        if (ventas.size() < 100) {
            ventas.push_back(
                    ventaMascota); //ventaMascota es el objeto vendido, push_back permite agregar el objeto dentro del vector en el final. y ventas es el nombre del vector
            for (int i = 0; i < ventaMascota.getMascotaVendidaCount(); ++i) {
                const Mascota &mascotaVendida = ventaMascota.getMascotaVendida(i);

                // Realiza las operaciones de descuento y suma de venta para cada mascota
                descontarAnimal(mascotaVendida.getNombreMascota());
                sumarVenta(mascotaVendida.getPrecioVenta());
            }

        } else {
            cout << "Se ha alcanzado el límite de ventas (100)." << endl;
        }
    }

    void mostrarStockVentas() {
        int i = 0;
        if (ventas.begin() != ventas.end()) {
            vector<Venta>::iterator it = ventas.begin(); // Utiliza el tipo de dato explícito
            cout<<"Nombre\tPrecio\tEdad\tVacunado\tFecha Venta"<<endl;

            while (it != ventas.end()) {
                cout << it->getMascotaVendida(i).getNombreMascota() <<"\t"<< it->getMascotaVendida(i).getPrecioVenta()<<"\t"<<it->getMascotaVendida(i).getEdad()<<"\t"<<it->getMascotaVendida(i).getVacunado()<<"\t"<<it->getFechaVenta()<<endl;
                ++it; // Incrementar el iterador
                i++;
            }

        } else {
            cout << "La lista esta vacia" << endl;
        }

    }

    void mostrarStock() {
        if (stock.begin() != stock.end()) {
            vector<Mascota *>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito
            cout<<"Nombre\tPrecio\tEdad\tVacunado"<<endl;
            while (it != stock.end()) {
                cout << (*it)->getNombreMascota() <<"\t"<< (*it)->getPrecioVenta()<<"\t"<< (*it)->getEdad()<<"\t"<<(*it)->getVacunado()<<endl;
                ++it; // Incrementar el iterador
            }
        } else {
            cout << "La lista esta vacia" << endl;
        }
    }

    string seleccionarMascota() {
        string mascotaSeleccionada;
        while (true) {
            cout << "ingrese el nombre de la mascota a vender o la palabra 'stock' para ver el stock disponible"
                 << endl;
            cin >> mascotaSeleccionada;
            if (mascotaSeleccionada == "stock") {
                mostrarStock();
            } else {
                //funcion que retorna la mascota acorde al nombre suministrado
                return mascotaSeleccionada;
            }
        }
    }

    void consultaVenta() {
        cout << "Se han vendido un total de " << ventas.size() << " mascotas." << endl;
        cout << "El total recaudado es de:" << totalRecaudado << endl;

        cout << "La lista de ventas es: " << endl;
        mostrarStockVentas();

    }

    void agregarMascotaNueva(Mascota *nuevaMascota) {
        stock.push_back(nuevaMascota);
    }

    void gettotalRecaudado() const {
        cout << "El total recaudado es " << totalRecaudado << endl;
    }

    Mascota *encontrarAnimalStock(const string &nombreAnimal) {
        vector<Mascota *>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito

        // Buscar el animal en el stock por su nombre
        while (it != stock.end()) {
            if ((*it)->getNombreMascota() == nombreAnimal) { // obtiene el nombre del objeto y lo compara con el nombre buscado
                return *it; // retorna el animal del stock encontrado
            }
            ++it; // Incrementar el iterador
        }

    }

    void descontarAnimal(const string &nombreAnimal) {
        bool encontrado = false;
        vector<Mascota *>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito

        // Buscar el animal en el stock por su nombre
        while (it != stock.end()) {
            if ((*it)->getNombreMascota() == nombreAnimal) { // Acceder al miembro usando (*it)
                it = stock.erase(it); // Eliminar el animal del stock y actualizar el iterador
                encontrado = true;
                break; // Salir del bucle una vez que se haya encontrado y eliminado el animal
            }
            ++it; // Incrementar el iterador
        }

        if (encontrado) {
            cout << "Animal descontado exitosamente del stock." << endl;
        }
    }
};

int main() {

    TiendaMascotas losTresHermanos;

    string respuesta = "si";

    while (respuesta == "si") {

        //si se desea cargar un nuevo animal se procede a cargar todos los campo
        Mascota *nuevaMascota = crearNuevaMascota();//en la creacion de la mascota se elige el tipo y se ingresan los datos
        losTresHermanos.agregarMascotaNueva(nuevaMascota);
        nuevaMascota->comunicacion();
        //se procede a leer el nombre de la mascota agregada en el stock
        cout << "Mascota agregada al stock: " << nuevaMascota->getNombreMascota() << endl;
        cout << "Desea cargar un nuevo animal a la tienda? (si/no)" << endl;
        cin >> respuesta;

    }

        string respuestaVentas;
        cout << "Se realizo una venta? (si/no)" << endl;
        cin >> respuestaVentas;

        if (respuestaVentas == "si") {
            //se crea la venta sin detalles
            Venta nuevaVenta;

            string continuar;
            while(continuar!="continuar"){
                string mascotaSeleccionada=losTresHermanos.seleccionarMascota();
                //debo cargar la mascota en nuevaMascota
                Mascota *nuevaMascotaVendida=losTresHermanos.encontrarAnimalStock(mascotaSeleccionada);
                nuevaVenta.setMascotaVendida(*nuevaMascotaVendida);
                nuevaVenta.ingresarFechaVenta();
                if(nuevaMascotaVendida->getVacunado()==0)
                {
                    string respVacunar;
                    cout<<"Tu Mascota no esta vacunada, desea vacunarla (si/no)?"<<endl;
                    cin>>respVacunar;
                    if(respVacunar=="si")
                        nuevaMascotaVendida->Vacunar();
                }
                losTresHermanos.agregarVenta(nuevaVenta);
                cout<<"Quiere realizar otra compra ('si'/'continuar')?"<<endl;
                cin>>continuar;
            }


        }

    losTresHermanos.consultaVenta();
    cout<<"El stock restante es: "<<endl;

    losTresHermanos.mostrarStock();
    losTresHermanos.gettotalRecaudado();

    return 0;
}