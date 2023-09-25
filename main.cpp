#include <iostream>
#include <string>
#include "Mascota.h"
#include "Venta.h"
#include "TiendaMascotas.h"

using namespace std;

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

    }

    losTresHermanos.consultaVenta();
    cout<<"El stock restante es: "<<endl;
    losTresHermanos.mostrarStock();
    losTresHermanos.gettotalRecaudado();

    return 0;
}