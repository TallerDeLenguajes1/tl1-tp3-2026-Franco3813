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

void BuscarNombrePorId(int id, char *nombre[]){
    if (id < 6 && id >= 0){
        printf("el nombre en la posicion %d es: %s", id, nombre[id-1]);
    }else{
        printf("no se encontró el valor buscado");
    }
    
}

int BuscarNombrePorPalabra(char *frase, char *nombre[]){
    for (int i = 0; i < 5; i++){
        if (strstr(nombre[i],frase) != NULL){
            return i;
        }
    }
}

int main(){
    char *nombre[5],frase[10];
    int resultado,id,a;

    for (int i = 0; i < 5; i++){
        char buff[50];

        printf("Escriba un nombre n%d: ",i+1);
        scanf("%s",buff); 
        int tama = strlen(buff);

        nombre[i] = (char *)malloc (tama * sizeof(char) + 1);
        strcpy(nombre[i], buff);
    }

    mostrarPersonas(nombre);

    printf("\nBusqueda de nombre");
    printf("\nSeleccione el tipo de busqueda:");
    printf("\n1)Busqueda por ID \n2)Busqueda por palabra clave");
    printf("\nOpcion elegida: ");
    scanf("%d",&resultado);

    if (resultado == 1){
        printf("\nIngrese una palabra clave para buscar un nombre: ");
        scanf("%s",frase);
        a = BuscarNombrePorPalabra(frase,nombre);

        if (a != -1){
            printf("El nombre encontrado es: %s", nombre[a]);
        }else{
            printf("nombre inexistente");
        }
    }else if(resultado == 2){
        printf("\ningrese la posicion del nombre deseado: ");
        scanf("%d",&id);

        BuscarNombrePorId(id,nombre);
    }else{
        printf("Fin del programa");
    }
    
    for (int i = 0; i < 5; i++){
        free(nombre[i]);
    }
    
    free(nombre);
    free(frase);
}