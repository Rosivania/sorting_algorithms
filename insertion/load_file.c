#include "load_file.h"

int  *load_file(char *name, unsigned lenght)
{
	//Statement of the pointer (link to the memory address) for the file name: 'pf'
	// Declaracao do ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
	FILE *pf;

	unsigned i;

	//buffer: memory region in which the read data is stored
	//buffer: região de memória na qual serão armazenados os dados lidos
	int *buffer = ( int*) calloc (lenght + 1,sizeof (int)); 

	pf = fopen( name, "rb");/*Opens the file again for reading */
	//Abre o arquivo novamente para leitura 
	if(!pf)
	{
		puts("Did not open - Nao abriu");
		return NULL;
	}
	else
	{
		for(i = 0; i < lenght; i++)
		{
			fscanf(pf,"%d",&buffer[i]);
		}
	}
	fclose(pf);
	return buffer;
}