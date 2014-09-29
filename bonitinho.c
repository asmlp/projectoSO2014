#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define INDICE_ID_FILE 7

char cadeia[10][11]={"aaaaaaaaa\n","bbbbbbbbbb\n","cccccccccc\n","dddddddddd\n","eeeeeeeeee\n","ffffffffff\n","gggggggggg\n","hhhhhhhhhh\n","iiiiiiiiii\n","jjjjjjjjjj\n"};


int escolher_ficheiro(){

	char file[]="SO2014-0.txt";
	int id_file = rand() % 5;
	file[INDICE_ID_FILE]+=id_file;

	return open(file, O_WRONLY | O_CREAT);

}

int escritor(){
	int file;
	int escolhida;

	for(int i=0; i<100; i++){

		//file = escolher_ficheiro();

		char nome[]="SO2014-0.txt";
		int id_file = rand() % 5;
		nome[INDICE_ID_FILE]+=id_file;

		file=open(nome, O_WRONLY | O_CREAT);

		escolhida = rand() % 10;

		for(int k=0; k<1024; k++){

			if(file < 0)
		        printf("erro1 \n");   
		 
		    if(write(file,cadeia[escolhida],11) != 11)
		        printf("erro2 \n");
		    
		}

		close(file);
	}
	return 0;
}



int main(){

	srand(time(NULL));

	escritor();


	return 0;
}

