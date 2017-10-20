#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "originalbubble.h"

clock_t timeBegin, timeEnd;
FILE *gnuplot;
unsigned long  change=0,comparison=0;
unsigned size;

void bubbleSort(int array[], unsigned lenght)
{
	unsigned i,j;
	int temp;
	change = 0;
    comparison = 0;
    timeBegin = clock();

	for (i = 0; i < lenght; i++)
	{
		for (j = 0; j < lenght -1; j++)
		{
			comparison++;
			if (array[j] > array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				change++;
			}
		}
	}
	timeEnd = clock();
}

///----------------------------------------------------------------------------------------
void print(int v[], unsigned size)
{
    unsigned i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    puts(" ");

}

///----------------------------------------------------------------------------------------
    //Writes the results of comparisons, changes, and processing time to a file.
    //grava os resultados de comparações, trocas e tempo de cpu em um arquivo.
void printResults()
{
    fprintf( gnuplot," %d\t\t", size);
    fprintf( gnuplot," %f\t", (float)(timeEnd - timeBegin)/CLOCKS_PER_SEC);
    fprintf( gnuplot, "%ld\t\t",comparison);
    fprintf( gnuplot, "%ld\n", change);

    //displays the changes and comparisons.
    //exibe as trocas e compraçoes.
     printf("Comparison - comparacao: %ld\n Changes - Trocas %ld\n",comparison,change);
     printf("Time - Tempo: %f\n", (float)(timeEnd - timeBegin)/CLOCKS_PER_SEC);
}

///----------------------------------------------------------------------------------------
//writes the ordered vector to a txt file.
//grava o vetor ordenado em um arquivo txt.
void saveFile(int array[], unsigned lenght)
{
    unsigned i;
    FILE *save;
    char filename[200];

    sprintf(filename, "Vector-%d-Ordered.txt", lenght);

    save = fopen(filename,"w");
    for (i = 0; i < lenght; i++)
    {
        fprintf(save,"%d ", array[i]);
        fflush(save);
    }
    fclose(save);
    printf("\n");
}

///----------------------------------------------------------------------------------------
int main()
{
    int *vectorFile;
printf("|================================================================|\n");
printf(" -----------------Random vectors - Vetores randomicos------------\n");

    gnuplot = fopen("reports/Bubble-sort-rand.dat", "w");

    size=100;
    printf("Ordering vector with 100 random elements\nOrdenando vetor com 100 elementos aleatorios\n");
    fprintf(gnuplot, "#RANDOM\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
    vectorFile = load_file("vectors/V100-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///-----------------------------------------------------------------------
    /*
    size=1000;
    printf("Ordering vector with 1000 random elements\nOrdenando vetor com 1000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V1000-RANDOM.txt",size);
    insertionSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    */
    ///------------------------------------------------------------------------
    size=10000;
    printf("\nOrdering vector with 10.000 random elements\nOrdenando vetor com 10.000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V10000-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=50000;
    printf("\nOrdering vector with 50.000 random elements\nOrdenando vetor com 50.000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V50000-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=100000;
    printf("\nOrdering vector with 100.000 random elements\nOrdenando vetor de 100.000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V100000-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=500000;
    printf("\nOrdering vector with 500.000 random elements\nOrdenando vetor de 500.000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V500000-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=1000000;
    printf("\nOrdering vector with 1000000 random elements\nOrdenando vetor de 1000000 elementos aleatorios\n");
    vectorFile = load_file("vectors/V1000000-RANDOM.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    fclose(gnuplot);
    ///-----------------------------------------------------------------------
    printf("|================================================================|\n");
    printf(" ----------------Ordered vectors - Vetores ordenados--------------\n");
    size=100;
    gnuplot = fopen("reports/Bubble-sort-ord.dat", "w");

    printf("\nOrdering vector with 100 ordered elements\nOrdenando vetor de 100 elementos ordenados\n");
    fprintf(gnuplot, "#ORDENADOS\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
    vectorFile = load_file("vectors/V100-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///-----------------------------------------------------------------------
    /*
    size=1000;
    printf("\nOrdering vector with 1000 ordered elements\nOrdenando vetor de 1000 elementos ordenados\n");
    vectorFile = load_file("vectors/V1000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    */
    ///------------------------------------------------------------------------
    size=10000;
    printf("\nOrdering vector with 10.000 ordered elements\nOrdenando vetor de 10.000 elementos ordenados\n");
    vectorFile = load_file("vectors/V10000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=50000;
    printf("\nOrdering vector with 50.000 ordered elements\nOrdenando vetor de 50.000 elementos ordenados\n");
    vectorFile = load_file("vectors/V50000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=100000;
    printf("\nOrdering vector with 100.000 ordered elements\nOrdenando vetor de 100.000 elementos ordenados\n");
    vectorFile = load_file("vectors/V100000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=500000;
    printf("\nOrdering vector with 500.000 ordered elements\nOrdenando vetor de 500.000 elementos ordenados\n");
    vectorFile = load_file("vectors/V500000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=1000000;
    printf("\nOrdering vector with 1000000 ordered elements\nOrdenando vetor de 1000000 elementos ordenados\n");
    vectorFile = load_file("vectors/V1000000-ORDER.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    fclose(gnuplot);
    ///-----------------------------------------------------------------------
     printf("|================================================================|\n");
     printf(" ----Inverted ordered vectors - Vetores inversamente ordenados---\n");

     size=100;
    gnuplot = fopen("reports/Bubble-sort-inv.dat", "w");
    printf("\nOrdering vector with 100 inverted elements\nOrdenando vetor de 100 elementos invertidos\n");
    fprintf(gnuplot, "#INVERSO\n#Tamanho\t Tempo\t\t Comparacao\t trocas\n");
    vectorFile = load_file("vectors/V100-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///-----------------------------------------------------------------------
    /*
    size=1000;
    printf("Ordering vector with 1000 inverted elements\nOrdenando vetor de 1000 elementos invertidos\n");
    vectorFile = load_file("vectors/V1000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    */
    ///------------------------------------------------------------------------
    size=10000;
    printf("\nOrdering vector with 10.000 inverted elements\nOrdenando vetor de 10.000 elementos invertidos\n");
    vectorFile = load_file("vectors/V10000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=50000;
    printf("\nOrdering vector with 50.000 inverted elements\nOrdenando vetor de 50.000 elementos invertidos\n");
    vectorFile = load_file("vectors/V50000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=100000;
    printf("\nOrdering vector with 100.000 inverted elements\nOrdenando vetor de 100.000 elementos invertidos\n");
    vectorFile = load_file("vectors/V100000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=500000;
    printf("\nOrdering vector with 500.000 Inverted elements\nOrdenando vetor de 500.000 elementos invertidos\n");
    vectorFile = load_file("vectors/V500000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    ///------------------------------------------------------------------------
    size=1000000;
    printf("\nOrdering vector with 1000000 inverted elements\nOrdenando vetor de 1000000 elementos invertidos\n");
    vectorFile = load_file("vectors/V1000000-INVERT.txt",size);
    bubbleSort(vectorFile, size);
    saveFile(vectorFile, size);
    printResults();
    fclose(gnuplot);
    ///-----------------------------------------------------------------------

    system("gnuplot -bg gray90 gnuplot_script/plota.gnu");

    return 0;
}
