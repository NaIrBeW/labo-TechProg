#include <stdio.h>

//O(1) l’accès à des éléments dans des structures de donnée
void sort(int* arr,int length){
    int y = 0; // O(1)
    for(int i = length; i >= 0;){ //O(n)
        arr[y] = arr[--i];
        if(i < 0){
            printf(stderr,"Something went wrong...");
        }
        ++y;
    }
}

int main(int argc, char** argv){
    int arr[] = {6,9,10,102,27,14};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,len);
    printf("Sorted array is: ");
    int i = 0;
    for(; arr[i+1]; ++i ){
        printf(" %i,",arr[i]);
    }
    printf(" %i",arr[i]);
}