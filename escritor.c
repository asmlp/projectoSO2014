#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INDICE_ID_FILE 7

// 				   1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890    1234567890  
char *cadeia[10]={"aaaaaaaaa\n","bbbbbbbbb\n","ccccccccc\n","ddddddddd\n","eeeeeeeee\n","fffffffff\n","ggggggggg\n","hhhhhhhhh\n","iiiiiiiii\n","jjjjjjjjj\n"};


int escolher_ficheiro(){

	char file[]="SO2014-0.txt";
	int id_file = rand() % 5;
	file[INDICE_ID_FILE]+=id_file;

	return open(file, O_RDWR | O_CREAT, 0644);

}


int escritor(){
	int file,escolhida,i,k;

	for(i=0; i<5120; i++){

		file = escolher_ficheiro();
		escolhida = rand() % 10;

		for(k=0; k<1024; k++){

			if(file < 0){
		        return -1;
		    }
		 
		    if(write(file,cadeia[escolhida],10) != 10){
		        return -1;
		    }  
		}
		close(file);
	}
	return 0;
}


int main(){

	srand(time(NULL));

	printf("ESCRITOR: %d\n",escritor());

	return 0;
}





