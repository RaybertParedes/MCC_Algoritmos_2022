package main

import (
	"log"	
	"io/ioutil"
	"strconv"
	"strings"
)

func readDataFromFile(filePath string) []float64 {
	var ints []float64
	b, err := ioutil.ReadFile(filePath)
	if err != nil {
		log.Print(err)
	}

	str := string(b)
	for index, element := range strings.Split(str, " ") {
		log.Println(index)

		const bitSize = 64
    intVar, err := strconv.ParseFloat(element, bitSize)
   
		if err != nil {
			log.Print(err)
		}
		ints = append(ints, intVar)
	}

	return ints
}

func insertionSort(array []float64) {
	for i := 0; i < len(array); i++ {
		temp := array[i]
		j := i - 1
		for ; j >= 0 && array[j] > temp; j-- {
			array[j+1] = array[j]
		}
		array[j+1] = temp
	}
}

func bucketSort(array []float64) []float64 {
	var max, min float64
	arraySize := len(array)
	for _, n := range array {
		if n < min {
			min = n
		}
		if n > max {
			max = n
		}
	}
	nBuckets := int(max-min)/arraySize + 1
	buckets := make([][]float64, nBuckets)
	for i := 0; i < nBuckets; i++ {
		buckets[i] = make([]float64, 0)
	}

	for _, n := range array {
		idx := int(n-min) / arraySize
		buckets[idx] = append(buckets[idx], n)
	}

	sorted := make([]float64, 0)
	for _, bucket := range buckets {
		if len(bucket) > 0 {
			insertionSort(bucket)
			sorted = append(sorted, bucket...)
		}
	}

	return sorted
}

func main() {

	start := time.Now()
	arrayToSort := readDataFromFile("sample_data/BucketSort_100000.txt")
	bucketSort(arrayToSort)
	duration :=time.Since(start)
	fmt.Println("tiempo ",duration)
}