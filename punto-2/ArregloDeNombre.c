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

int BuscarNombre(char *frase[],char *nombre[]){
    for (int i = 0; i < 5; i++){
        if (strstr(nombre[i],frase) != NULL){
            return i;
        }
    }
}

int main(){
    char *nombre[5],frase[10];
    int a;

    for (int i = 0; i < 5; i++){
        char buff[50];

        printf("Escriba un nombre n%d: ",i+1);
        scanf("%s",buff); 
        int tama = strlen(buff);

        nombre[i] = (char *)malloc (tama * sizeof(char) + 1);
        strcpy(nombre[i], buff);
    }

    mostrarPersonas(nombre);

    printf("\nIngrese una palabra clave para buscar un nombre: ");
    scanf("%s",frase);
    a = BuscarNombre(frase,nombre);

    if (a != -1){
        printf("El nombre encontrado es: %s", nombre[a]);
    }else{
        printf("nombre inexistente");
    }
    
}