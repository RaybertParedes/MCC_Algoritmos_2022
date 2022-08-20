// C++ Implementation of the Quick Sort Algorithm.
#include <chrono>
#include <cstdint>
#include <iostream>

using namespace std;
using namespace std::chrono;

const int tamano = 50000, MAXIMO = 1000000;


uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int partition(int *arr, int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{    
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

int * slice(int tamano)
{
   //int arreglo[ tamano ] = { 0 };
   int * arreglo = new int[ tamano ];
   int i;
   srand( time( 0 ) );
   for ( i = 0; i < tamano; ++i )
      arreglo[ i ] = rand() % MAXIMO;
 
   /*cout << "Los valores del arreglo son:\n";
   for ( i = 0; i < tamano; ++i ){
     cout <<"arreglo[" << i << "] = " << arreglo[ i ];
       cout << "\n";
   } */
 
   return arreglo;
}

int * leerArchivo(string filePath) {
    ifstream inputFile(filePath);
    int i  = 0;
	
    int * arrayFromFile = new int[ tamano ];
    if (!inputFile.is_open())
        cout << "Error al abrir el archivo";

    if (inputFile) {
        int value;

        while (inputFile >> value) {
            //arrayFromFile.push_back(value);
	    arreglo[ i ] = value;
		
        }
    }

    inputFile.close();
    return arrayFromFile;
}

int main()
{

	//int *arr = slice(tamano);
	int *arr = leerArchivo("../Data_1000000.txt");
	int n = tamano;
    
    cout << "Ini:" << timeSinceEpochMillisec() << endl;
    // Get starting timepoint
    auto start = high_resolution_clock::now();

	quickSort(arr, 0, n - 1);

	/*for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout << "Fin:" << timeSinceEpochMillisec() << endl;

	return 0;
}

