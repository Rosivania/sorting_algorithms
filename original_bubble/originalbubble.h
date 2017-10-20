/*
 * originalbubble.h
 *
 *  Created on: 1 de outubro de 2017
 *      Author: Rosivania
 */

#ifndef ORIGINALBUBBLE_H_
#define ORIGINALBUBBLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load_file.c"

void bubbleSort(int array[], unsigned lenght);
void print(int v[], unsigned size);
void printResults();
void saveFile(int array[], unsigned lenght);

#endif /* ORIGINALBUBBLE_H_ */