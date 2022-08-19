#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arreglo, int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int>izquierda(elementosIzq);
    vector<int>derecha(elementosDer);

    for (int i = 0; i < elementosIzq; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < elementosDer; j++) {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < elementosIzq && j < elementosDer) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        }
        else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (j < elementosDer) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while (i < elementosIzq) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }

}

void mergeSort(vector<int>& arreglo, int inicio, int final) {
    if (inicio < final) {
        int mitad = inicio + (final - inicio) / 2;
        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad + 1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

//void imprimirArreglo(vector<int>arreglo) {
//    for (int i = 0; i < arreglo.size(); i++) {
//        cout << arreglo[i] << " ";
//    }
//    cout << endl;
//}

vector<int> leerArchivo(string filePath) {
    ifstream inputFile(filePath);

    vector<int> arrayFromFile;
    if (!inputFile.is_open())
        cout << "Error al abrir el archivo";

    if (inputFile) {
        int value;

        while (inputFile >> value) {
            arrayFromFile.push_back(value);
        }
    }

    inputFile.close();
    return arrayFromFile;
}

int main() {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    //vector<int> lista= generarLista(20);
    vector<int> lista = leerArchivo("../Data_1000000.txt");

    auto stop = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    /*imprimirArreglo(lista);*/
    mergeSort(lista, 0, lista.size() - 1);
    /*imprimirArreglo(lista);*/

    cout << endl << "Duracion de ordenamiento" << endl;
    auto duration = stop - start;
    cout << duration << endl;
    return 0;
}
