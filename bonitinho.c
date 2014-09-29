#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define INDICE_ID_FILE 7

char cadeia[10][11]={"aaaaaaaaaa\n","bbbbbbbbbb\n","cccccccccc\n","dddddddddd\n","eeeeeeeeee\n","ffffffffff\n","gggggggggg\n","hhhhhhhhhh\n","iiiiiiiiii\n","jjjjjjjjjj\n"};


int escolher_ficheiro(){

	char file[]="SO2014-0.txt";
	int id_file = rand() % 5;
	file[INDICE_ID_FILE]+=id_file;

	return open(file, O_WRONLY | O_CREAT, 0644);

}

int escritor(){
	int file;
	int escolhida;

	for(int i=0; i<5120; i++){

		file = escolher_ficheiro();
		escolhida = rand() % 10;

		for(int k=0; k<1024; k++){

			if(file < 0){
		        printf("erro1 \n"); 
		        return -1;
		    }
		 
		    if(write(file,cadeia[escolhida],11) != 11){
		        printf("erro2 \n");
		        return -1;
		    }  
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