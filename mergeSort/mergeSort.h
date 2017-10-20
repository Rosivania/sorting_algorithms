/*
 * mergeSort.h
 *
 *  Created on: 1 de outubro de 2017
 *      Author: Rosivania
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load_file.c"

void merge(int array[], int l, int m, int r);
void mergeSort(int array[], int l, int r);
void print(int v[], unsigned size);
void printResults();
void saveFile(int array[], unsigned lenght);

#endif /* MERGESORT_H_ */