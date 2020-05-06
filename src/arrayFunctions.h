#include "definitions.h"
int eql(int arr1[],int arr2[]){
    for(int i = 0; i < 8; i++)
        if(arr1[i] != arr2[i])
            return FALSE;
    return TRUE;
}
int getIndexInArray(int element,int array[]){
    for(int i = 0; i <8; i++)
        if(array[i] == element) 
            return i;
    return -1;
}
void arCpy(int destino[],int origen[]){
    for(int i = 0; i < 8; i++)
        destino[i] = origen[i];
}
int * append(int array[],int element){
    // Agregar elemento,"element", en la primera posicion vacia de array
    int freeSpace = getIndexInArray(BLANK,array);
    if(freeSpace >= 0)
        array[freeSpace] = element;
    return array;
}
int * clear(int array[]){
    // Restablece el array a una lista de BLANK
    for(unsigned short i = 0; i < 8; i++)
        array[i] = BLANK;
    return array;
}
void removeSpaces(int array[]){
    int fin[] = {-1,-1,-1,-1,-1,-1,-1,-1};
    for(int i = 0; i < 8; i++){
        if(array[i]!=-1)
            append(fin,array[i]);
    }
    arCpy(array,fin);
}
int in(int array[], int element){
    if (getIndexInArray(element, array) == -1)
        return FALSE;
    else
        return TRUE;
}
int * popBack(int array[],int element){
    // Elimina la primera instancia del elemento ,"element", del array
    // en este contexto "eliminar" es cambiar dicho elemento por -1, BLANK
    int *resoult = (int*) malloc(sizeof(int) * 8);
    for(int i = 0; i < 8; i++){
        if(array[i] != element)
            resoult[i] = array[i];
        else
            resoult[i] = BLANK;
    }
    removeSpaces(array);
    return resoult;
}
void pop(int origen[],int element){
    for(int i=0; i < 8; i++)
        if(origen[i] == element)
            origen[i] = BLANK;
    removeSpaces(origen);
}
int find(int array[],int pattern[]){
    // Retorna True si pattern contiene las mismas teclas
    // en el mismo orden que array
    removeSpaces(array);
    removeSpaces(pattern);
    return eql(array,pattern);
}
int arrIsEmpty(int arr[]){
    for(int i = 0; i <8; i++)
        if(arr[i] != BLANK)
            return FALSE;
    return TRUE;
}
