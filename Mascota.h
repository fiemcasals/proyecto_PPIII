#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Mascota {
private:
    string nombreMascota;
    bool vacunado;
    float precioVenta;
    int edad;
    //no se que seria forma de comunicarse con un string

public:

    virtual void comunicacion(){
        cout <<"esto depende de cada especie"<<endl;

    }
    Mascota() {
        vacunado = false; // Por defecto, la mascota no está vacunada
    }

    void setNombreMascota() {

        string nombreAnimal;

        cout << "Ingrese el tipo de mascota (Perro, Gato o Pajaro): ";
        cin >> nombreAnimal;

        nombreMascota = nombreAnimal;
    }
    void setEdadMascota() {

        int edadAnimal;

        cout << "Ingrese la edad del animal: ";
        cin >> edadAnimal;

        edad = edadAnimal;
    }

    void modificarVacunado() {
        string vacuna;
        cout << "Ingrese si esta vacunado el animal (si/no): ";
        cin >> vacuna;
        vacunado = (vacuna=="si");
    }

    void ingresarPrecioVenta() {
        cout << "A qué precio se vendió la mascota: ";
        cin >> precioVenta;
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
};
