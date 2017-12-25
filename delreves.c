#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "auxiliar.h"
#define MAX_LINEA 2048
#define MAX_BUFF_LENGTH 2049
/*TO Compile
  You can use 'make' command on the same dir where all the files are at
	OR
  copy and paste: gcc -g -Wall -Wextra -o delreves delreves.c auxiliar.c
*/
int main(int argc, char *argv[]){

	int i,j,k;
	j=0;
	char texto[MAX_BUFF_LENGTH];
	char invertido[MAX_BUFF_LENGTH];
	char* file_name;
	FILE *fp;
	int num_files;
	int first_print = 1;
	//Si es un argumento
	if(argc == 2){
		//Si es el comando "-h" o "--help"
		if((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
			printf("delreves: Uso: delreves [ fichero... ]\n");
		        printf("delreves: Invierte el contenido de las lineas de los ficheros (o de la entrada).\n");
		}
		//Si no es el comando de ayuda, debe ser un fichero o texto plano por STDIN
		else{
			//Si es un fichero y existe
			file_name = argv[1];
			if(access(file_name, F_OK) != -1){
				fp = fopen(argv[1],"r");
				//Mientras haya fichero a leer
				while(!feof(fp)){
					//Leer linea del fichero
					if(fgets(texto, MAX_LINEA, fp)){ 
						//Empieza en strlen(texto)-2 para no leer el '\n' que tiene almacenado
						for(i=strlen(texto)-2; i>=0; i--){
							invertido[j]=texto[i];
							j++;
						}
						//Indicar fin de cadena caracteres
						invertido[j] = '\0';
						j=0;
						if(!first_print){
							fputs("\n", stdout);
						}
						fputs(invertido, stdout);
						first_print = 0;
					}
				}//fin de while para leer
				printf("\n");
				fclose(fp);
			}
			//Si no es un fichero
			else{
				for(i=strlen(argv[1])-1; i>=0; i--){
					invertido[j]=argv[1][i];
					j++;
				}
				invertido[j] = '\0';
				fputs(invertido, stdout);
				printf("\n");
			}
		}
	}
	//Si el numero de argumentos es mayor
	else if(argc > 2){
		num_files = argc-1;
		//Bucle para leer tantos ficheros como pasen
		for(k=0; k<num_files; k++){
			file_name = argv[k+1];
			//printf("%s\n",file_name);
			if(access(file_name, F_OK) != -1){
				fp = fopen(file_name,"r");
				//Mientras haya fichero a leer
				while(!feof(fp)){
					//Leer linea del fichero
					if(fgets(texto, MAX_LINEA, fp)){ 
						//Empieza en strlen(texto)-2 para no leer el '\n' que tiene almacenado
						for(i=strlen(texto)-2; i>=0; i--){
							invertido[j]=texto[i];
							j++;
						}
						//Indicar fin de cadena caracteres
						invertido[j] = '\0';
						j=0;
						if(!first_print){
							fputs("\n", stdout);
						}
						fputs(invertido, stdout);
						first_print = 0;
					}
				}//fin de while para leer
				fclose(fp);
			}//Fin de impresion de datos del fichero k
		}//Fin de recorrer los k ficheros
		printf("\n");
	}//fin elseif
	else{
		printf("Incorrect usage of the program, write './delreves -h' or './delreves --help' to know how to properly execute it\n");
	}
	return 0;
}
