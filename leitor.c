#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INDICE_ID_FILE 7

int escolher_ficheiro(){

	char file[]="SO2014-0.txt";
	int id_file = rand() % 5;
	file[INDICE_ID_FILE]+=id_file;

	return open(file, O_RDWR | O_CREAT, 0644);

}


int leitor(){
	int file,i=0;
	char linha[10],primeira[10];

	file = escolher_ficheiro();

	read(file,primeira,10);

	while( read(file,linha,10)>0 ){

		if(strncmp(primeira,linha,10))
			return -1;
		i++;
	}

	if(i==1023)
		return 0;
	
	else
		return -1;
	
}


int main(){

	srand(time(NULL));

	printf("LEITOR: %d\n",leitor());

	return 0;
}



