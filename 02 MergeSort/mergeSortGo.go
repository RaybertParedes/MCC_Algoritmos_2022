package main

import (
	"io/ioutil"
	"log"
	"strconv"
	"strings"
)

func main() {

	lista := leerArchivo("data/Data_1000000.txt")
	//lista := generarLista(20)
	// imprimirArreglo(lista)
	mergeSort(lista, 0, len(lista)-1)
	// imprimirArreglo(lista)
}

func leerArchivo(filePath string) []int {
	var ints []int
	bytesLeidos, err := ioutil.ReadFile(filePath)
	if err != nil {
		log.Print(err)
	}

	str := string(bytesLeidos)
	for index, element := range strings.Split(str, " ") {
		log.Println(index)
		intVar, err := strconv.Atoi(element)

		if err != nil {
			log.Print(err)
		}
		ints = append(ints, intVar)
	}
	return ints
}

// func imprimirArreglo(arreglo []int) {
// 	fmt.Println(arreglo)
// }

// func generarLista(tamaño int) []int {

// 	lista := make([]int, tamaño, tamaño)
// 	rand.Seed(time.Now().UnixNano())
// 	for i := 0; i < tamaño; i++ {
// 		//lista[i] = rand.Intn(9999) - rand.Intn(9999)
// 		lista[i] = rand.Intn(9999)
// 	}
// 	return lista
// }

func mergeSort(arreglo []int, inicio int, final int) {
	if inicio < final {
		mitad := inicio + (final-inicio)/2
		mergeSort(arreglo, inicio, mitad)
		mergeSort(arreglo, mitad+1, final)
		merge(arreglo, inicio, mitad, final)
	}
}

func merge(arreglo []int, inicio int, mitad int, final int) {
	elementosIzq := mitad - inicio + 1
	elementosDer := final - mitad
	var izquierda [1000000]int
	var derecha [1000000]int

	for i := 0; i < elementosIzq; i++ {

		izquierda[i] = arreglo[inicio+i]

	}

	for j := 0; j < elementosDer; j++ {
		derecha[j] = arreglo[mitad+1+j]
	}

	i := 0
	j := 0
	k := inicio // Iniciar inidice del primera subLista
	for i < elementosIzq && j < elementosDer {
		if izquierda[i] < derecha[j] {
			arreglo[k] = izquierda[i]
			i++
		} else {
			arreglo[k] = derecha[j]
			j++
		}
		k++
	}

	for i < elementosIzq {
		arreglo[k] = izquierda[i]
		i++
		k++
	}

	for j < elementosDer {
		arreglo[k] = derecha[j]
		j++
		k++
	}
}
