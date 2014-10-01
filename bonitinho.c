#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INDICE_ID_FILE 7
//					  1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890  
char cadeia[10][11]={"aaaaaaaaa\n","bbbbbbbbb\n","ccccccccc\n","ddddddddd\n","eeeeeeeee\n","fffffffff\n","ggggggggg\n","hhhhhhhhh\n","iiiiiiiii\n","jjjjjjjjj\n"};


int escolher_ficheiro(){

	char file[]="SO2014-0.txt";
	int id_file = rand() % 5;
	file[INDICE_ID_FILE]+=id_file;

	return open(file, O_RDWR | O_CREAT, 0644);

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


int leitor(){
	int file,i=0;
	char linha[11],primeira[11];

	file = escolher_ficheiro();

	read(file,primeira,11);

	while( read(file,linha,11)>0 ){
		
		if(strcmp(primeira,linha))
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

	printf("ESCRITOR: %d\n",escritor());

	printf("LEITOR: %d\n",leitor());

	return 0;
}



