#include <iostream>
#include <string>
#include <vector>

using namespace std;

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