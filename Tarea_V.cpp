#include <iostream>
#include <string>

using namespace std;


struct Nodo {
    int carnes;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};


void mostrarEncabezado() {
    cout << "========================================" << endl;
    cout << "   Erix Alejandro Solares   " << endl;
    cout << "   CARNE: 9941-20-23978                " << endl;
    cout << "========================================" << endl;
}


void insertarInicio(Nodo*& lista) {
    Nodo* nuevo_nodo = new Nodo();
    cout << "Ingrese Carne: "; cin >> nuevo_nodo->carnes;
    cin.ignore();
    cout << "Ingrese Nombre: "; getline(cin, nuevo_nodo->nombre);
    cout << "Ingrese Apellido: "; getline(cin, nuevo_nodo->apellido);
    cout << "Ingrese Carrera: "; getline(cin, nuevo_nodo->carrera);

    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
    cout << " Estudiante agregado al inicio correctamente." << endl;
}


void insertarFinal(Nodo*& lista) {
    Nodo* nuevo_nodo = new Nodo();
    cout << "Ingrese Carne: "; cin >> nuevo_nodo->carnes;
    cin.ignore();
    cout << "Ingrese Nombre: "; getline(cin, nuevo_nodo->nombre);
    cout << "Ingrese Apellido: "; getline(cin, nuevo_nodo->apellido);
    cout << "Ingrese Carrera: "; getline(cin, nuevo_nodo->carrera);
    nuevo_nodo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
    cout << " Estudiante agregado al final correctamente." << endl;
}

void mostrarEstudiantes(Nodo* lista) {
    if (lista == NULL) {
        cout << " La lista esta vacia." << endl;
        return;
    }
    Nodo* aux = lista;
    while (aux != NULL) {
        cout << "\n---------------------------------" << endl;
        cout << "Carne: " << aux->carnes << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Apellido: " << aux->apellido << endl;
        cout << "Carrera: " << aux->carrera << endl;
        aux = aux->siguiente;
    }
}

void buscarEstudiante(Nodo* lista) {
    int busqueda;
    bool encontrado = false;
    cout << "Ingrese carne a buscar: "; cin >> busqueda;

    Nodo* aux = lista;
    while (aux != NULL) {
        if (aux->carnes == busqueda) {
            cout << "Estudiante encontrado:" << endl;
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Apellido: " << aux->apellido << endl;
            cout << "Carrera: " << aux->carrera << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (!encontrado) cout << "Estudiante no encontrado." << endl;
}

void eliminarEstudiante(Nodo*& lista) {
    if (lista == NULL) {
        cout << " No hay estudiantes para eliminar." << endl;
        return;
    }
    int busqueda;
    cout << "Ingrese carne a eliminar: "; cin >> busqueda;

    Nodo* aux_borrar = lista;
    Nodo* anterior = NULL;

    while (aux_borrar != NULL && aux_borrar->carnes != busqueda) {
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if (aux_borrar == NULL) {
        cout << "Estudiante no encontrado." << endl;
    } else {
        if (anterior == NULL) {
            lista = lista->siguiente;
        } else {
            anterior->siguiente = aux_borrar->siguiente;
        }
        delete aux_borrar;
        cout << "Estudiante eliminado correctamente." << endl;
    }
}

int main() {
    Nodo* lista = NULL;
    int opcion;

    do {
        mostrarEncabezado();
        cout << "1. Insertar estudiante al inicio" << endl;
        cout << "2. Insertar estudiante al final" << endl;
        cout << "3. Mostrar estudiantes" << endl;
        cout << "4. Buscar estudiante" << endl;
        cout << "5. Eliminar estudiante" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: insertarInicio(lista); break;
            case 2: insertarFinal(lista); break;
            case 3: mostrarEstudiantes(lista); break;
            case 4: buscarEstudiante(lista); break;
            case 5: eliminarEstudiante(lista); break;
            case 6: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }


    } while (opcion != 6);

    return 0;
}