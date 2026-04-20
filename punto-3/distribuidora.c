#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

int calcular(int cant,int precio){
    int a;
    a = cant * precio;
    return a;
}

int main(){
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes,a,cantP,precio,total;
    struct Cliente datos[5];
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes visitados: ");
    scanf("%d",&cantClientes);

    if (cantClientes > 0  && cantClientes < 6){
        for (int i = 0; i < cantClientes; i++){
            int totalA;
            char buff[50];
            totalA = 0;
            datos[i].ClienteID = i+1;

            printf("\nIngrese el nombre del usuario n%d: ",i+1);
            scanf("%s",buff);
            int tama = strlen(buff);
            datos[i].NombreCliente = (char *)malloc (tama * sizeof(char) + 1);
            strcpy(datos[i].NombreCliente, buff);

            datos[i].CantidadProductosAPedir = 1 + rand()%4;
            printf("Cantidad de productos: %d", datos[i].CantidadProductosAPedir);
            datos[i].Productos = (struct Producto*)malloc(datos[i].CantidadProductosAPedir * sizeof(struct Producto));

            for (int j = 0; j < datos[i].CantidadProductosAPedir; j++){
                datos[i].Productos[j].ProductoID = j+1;
                datos[i].Productos[j].Cantidad = 1 + rand()%10;
                a = rand()%5;
                datos[i].Productos[j].TipoProducto = TiposProductos[a];
                datos[i].Productos[j].PrecioUnitario = 10 + rand()%91;

                cantP = datos[i].Productos[j].Cantidad;
                precio = datos[i].Productos[j].PrecioUnitario;
                total = calcular(cantP,precio);
                totalA = totalA + total;

                printf("\nNumero de cliente: %d",i+1);
                printf("\nProducto id: %d",datos[i].Productos[j].ProductoID);
                printf("\nCantidad del producto: %d",datos[i].Productos[j].Cantidad);
                printf("\nTipo de producto: %s",datos[i].Productos[j].TipoProducto);
                printf("\nPrecio Unitario: %.2f",datos[i].Productos[j].PrecioUnitario);
                printf("\nPrecio total: %d\n",total);
            }
            printf("Total a pagar: %d",totalA);
        }
        
    }else{
        printf("Datos Invalidos");
    }
    
}