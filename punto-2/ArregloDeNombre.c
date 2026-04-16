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

void BuscarNombre(int id, char *nombre[]){
    if (id < 6 && id >= 0){
        printf("el nombre en la posicion %d es: %s", id, nombre[id-1]);
    }else{
        printf("no se encontró el valor buscado");
    }
    
}

int main(){
    char *nombre[5];
    int id;

    for (int i = 0; i < 5; i++){
        char buff[50];

        printf("Escriba un nombre n%d: ",i+1);
        scanf("%s",buff); 
        int tama = strlen(buff);

        nombre[i] = (char *)malloc (tama * sizeof(char) + 1);
        strcpy(nombre[i], buff);
    }

    mostrarPersonas(nombre);

    printf("\ningrese la posicion del nombre deseado: ");
    scanf("%d",&id);

    BuscarNombre(id,nombre);

}