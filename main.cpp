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
    bool getVacunado() const {
        return vacunado;
    }

    int getPrecioVenta() const {
        return precioVenta;
    }
    void modificarVacunado() {
        string vacuna;
        cout << "Ingrese si esta vacunado el animal (si/no): ";
        cin >> vacuna;
        vacunado = (vacuna=="si");
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

class Venta {
private:
    string fechaVenta;
    vector<Mascota> mascotaVendida;
    float ventaTotal;

public:
    Venta(): ventaTotal(0){};

    void setMascotaVendida(const Mascota &mascota) {
        mascotaVendida.push_back(mascota);//inserto al final del vector la Mascota.
    }

    void ingresarFechaVenta() {
        cout << "En qué fecha se vendió la mascota (dd/mm/aaaa): ";
        cin >> fechaVenta;
    }

    string getFechaVenta() const {
        return fechaVenta;
    }

    void seeAllPetSold(){
        int i=0;
        for (int i = 0; i < mascotaVendida.size(); i++) {
            cout<<mascotaVendida[i].getNombreMascota()<<"en la posicion: "<<i<<endl;
            i++;
        }
    }
    const Mascota &getMascotaVendida(int index) const { //estos dos const hacen referencia a que no se modificara en la funcion al objeto llamado ni se puede modificar el objeto retornado
        return mascotaVendida[index];
    }

};

class TiendaMascotas {
private:
    vector<Venta> ventas;
    vector<Mascota> stock;
    int totalRecaudado; // Esta variable se inicializará en el constructor

public:
    TiendaMascotas() : totalRecaudado(0) {} // Inicializa totalRecaudado en 0 en el constructor

    void sumarVenta(int dinero){
        totalRecaudado+=dinero;
    }
    void agregarVenta(const Venta &ventaMascota) {
        if (ventas.size() < 100) {
            ventas.push_back(ventaMascota); //ventaMascota es el objeto vendido, push_back permite agregar el objeto dentro del vector en el final. y ventas es el nombre del vector
            descontarAnimal(ventaMascota.getMascotaVendida().getNombreMascota());
            sumarVenta(ventaMascota.getMascotaVendida().getPrecioVenta());
        } else {
            cout << "Se ha alcanzado el límite de ventas (100)." << endl;
        }
    }
    void mostrarStockVentas(){
        if(ventas.begin()!=ventas.end()){
            vector<Venta>::iterator it = ventas.begin(); // Utiliza el tipo de dato explícito

            while (it != ventas.end()) {
                cout<<it->getMascotaVendida().getNombreMascota()<<endl;
                ++it; // Incrementar el iterador
            }
        }else{
            cout<<"La lista esta vacia"<<endl;
        }

    }
    void mostrarStock(){
        if(stock.begin()!=stock.end()){
            vector<Mascota>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito

            while (it != stock.end()) {
                cout<<it->getNombreMascota()<<endl;
                ++it; // Incrementar el iterador
            }
        }else{
            cout<<"La lista esta vacia"<<endl;
        }
    }

    string seleccionarMascota(){
        string mascotaSeleccionada;
        while (true){
            cout<<"ingrese el nombre de la mascota a vender o la palabra 'stock' para ver el stock disponible"<<endl;
            cin>>mascotaSeleccionada;
            if (mascotaSeleccionada=="stock"){
                mostrarStock();
            }else{
                //funcion que retorna la mascota acorde al nombre suministrado
                return mascotaSeleccionada;
            }
        }}
    void consultaVenta() {
        cout << "Se han vendido un total de " << ventas.size() << " mascotas." << endl;
        cout << "El total recaudado es de:" << totalRecaudado << endl;

        cout<<"La lista de ventas es: "<<endl;
        mostrarStockVentas();

    }
    void agregarMascotaNueva(const Mascota &nuevaMascota){
        stock.push_back(nuevaMascota);
    }

    void  gettotalRecaudado() const{
        cout<<"El total recaudado es "<< totalRecaudado<<endl;
    }
    Mascota &encontrarAnimalStock(const string &nombreAnimal) {
        vector<Mascota>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito

        // Buscar el animal en el stock por su nombre
        while (it != stock.end()) {
            if (it->getNombreMascota() == nombreAnimal) { // obtiene el nombre del objeto y lo compara con el nombre buscado
                return *it; // retorna el animal del stock encontrado
            }
            ++it; // Incrementar el iterador
        }

        // Si no se encuentra el animal:
        throw runtime_error("Animal no encontrado en el stock");
    }

    void descontarAnimal(const string &nombreAnimal) {
        bool encontrado = false;
        vector<Mascota>::iterator it = stock.begin(); // Utiliza el tipo de dato explícito

        // Buscar el animal en el stock por su nombre
        while (it != stock.end()) {
            if (it->getNombreMascota() == nombreAnimal) { // obtiene el nombre del objeto y lo compara con el nombre buscado
                it = stock.erase(it); // Eliminar el animal del stock y actualizar el iterador
                encontrado = true;
                break; // Salir del bucle una vez que se haya encontrado y eliminado el animal
            }
            ++it; // Incrementar el iterador
        }

        if (encontrado) {
            cout << "Animal descontado exitosamente del stock." << endl;
        } else {
            cout << "Animal no encontrado en el stock." << endl;
        }
    }

};


int main() {

    TiendaMascotas losTresHermanos;

    string respuesta = "si";

    while (respuesta != "salir") {

        string respuestaAnimales;
        cout << "Desea cargar un nuevo animal a la tienda? (si/no)" << endl;
        cin >> respuestaAnimales;

        //si se desea cargar un nuevo animal se procede a cargar todos los campos
        if (respuestaAnimales == "si") {

            Mascota nuevaMascota;
            nuevaMascota.setNombreMascota();
            nuevaMascota.modificarVacunado();
            nuevaMascota.ingresarPrecioVenta();
            losTresHermanos.agregarMascotaNueva(nuevaMascota);

            //se procede a leer el nombre de la mascota agregada en el stock
            cout << "Mascota agregada al stock: " << nuevaMascota.getNombreMascota() << endl;
        }

        string respuestaVentas;
        cout << "Se realizo una venta? (si/no)" << endl;
        cin >> respuestaVentas;
        /*
        if (respuestaVentas == "si") {
            //se crea la venta sin detalles
            Venta nuevaVenta;
            // hay que definir qué mascota se vendió, puede no haberse vendido la última mascota cargada


            string continuar;
            while(continuar!="continuar"){
                string mascotaSeleccionada=losTresHermanos.seleccionarMascota();
                //debo cargar la mascota en nuevaMascota
                Mascota nuevaMascotaVendida=losTresHermanos.encontrarAnimalStock(mascotaSeleccionada);
                nuevaVenta.setMascotaVendida(nuevaMascotaVendida);
                nuevaVenta.ingresarFechaVenta();
                cout<<"Quiere realizar otra compra ('si'/'continuar')?"<<endl;
                cin>>continuar;
            }

            losTresHermanos.agregarVenta(nuevaVenta);
        }

        cout << "Desea seguir cargando ventas o animales? (si/salir)"<<endl;
        cin >> respuesta;
    */
    }

    losTresHermanos.consultaVenta();
    cout<<"El stock restante es: "<<endl;
    losTresHermanos.mostrarStock();
    losTresHermanos.gettotalRecaudado();

    return 0;
}

