#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char *nombres[]){
    printf("\n");
    printf("Nombres guardados: ");
    for (int i = 0; i < 5; i++){
        printf("%s, ", nombres[i]);
    }
    
}

int main(){
    char *nombre[5];

    for (int i = 0; i < 5; i++){
        char buff[50];

        printf("Escriba un nombre n%d: ",i+1);
        scanf("%s",buff); 
        int tama = strlen(buff);

        nombre[i] = (char *)malloc (tama * sizeof(char) + 1);
        strcpy(nombre[i], buff);
    }

    mostrarPersonas(nombre);
}