#include <iostream>
#include <string>
#include <vector>

using namespace std;

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