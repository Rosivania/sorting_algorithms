/*
 * quickSort.h
 *
 *  Created on: 1 de outubro de 2017
 *      Author: Rosivania
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load_file.c"

void quickSort(int array[], int begin, int end);
void print(int v[], unsigned size);
void printResults();
void saveFile(int array[], unsigned lenght);

#endif /* QUICKSORT_H_ */