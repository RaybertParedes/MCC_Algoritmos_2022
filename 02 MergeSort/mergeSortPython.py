import datetime
from random import randint


def merge(arreglo,inicio,mitad,final):
    elementosIzq = mitad - inicio + 1
    elementosDer = final - mitad
    
    izquierda = [0] * (elementosIzq)
    derecha = [0]  * (elementosDer)

    for i in range(0, elementosIzq):
        izquierda[i] = arreglo[inicio + i]

    for j in range(0, elementosDer):
        derecha[j] = arreglo[mitad + 1 + j]

    i = 0     # Iniciar inidice del primera subLista
    j = 0     # Iniciar inidice de la segunda subLista
    k = inicio     # Iniciar inidice de merged subLista

    while i < elementosIzq and j < elementosDer:
        if izquierda[i] <= derecha[j]:
            arreglo[k] = izquierda[i]
            i += 1
        else:
            arreglo[k] = derecha[j]
            j += 1
        k += 1
    while i < elementosIzq:
        arreglo[k] = izquierda[i]
        i += 1
        k += 1

    while j < elementosDer:
        arreglo[k] = derecha[j]
        j += 1
        k += 1

def mergeSort(arreglo, inicio, final):
    if inicio < final:
        mitad = inicio+(final-inicio)//2

        mergeSort(arreglo, inicio, mitad)
        mergeSort(arreglo, mitad + 1, final)
        merge(arreglo, inicio, mitad, final)

# def imprimirArreglo(lista):
#     print(lista)

# def generarLista(tamaño):
#     lista = [0] * tamaño
#     for i in range(tamaño):
#         lista[i] = randint(0,999999)
#     return lista

def leerArchivo(file_path):
	input_file = open(file_path, "r")
	return [float(item) for item in input_file.read().split(' ')]

start_time = datetime.datetime.now()
print(start_time)
lista = leerArchivo(r'data/Data_1000000.txt')
# lista = generarLista(20)
# imprimirArreglo(lista)
cantidadElmentosLista = len(lista)
mergeSort(lista, 0, cantidadElmentosLista - 1)
# imprimirArreglo(lista)
end_time = datetime.datetime.now()
print(end_time)
time_diff = (end_time - start_time)
print(time_diff.total_seconds() * 1000.0)