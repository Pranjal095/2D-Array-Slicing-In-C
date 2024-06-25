#include <stdio.h>
#include <stdlib.h>

int** arraySlice(int** arr,int startRowIndex,int endRowIndex,int rowStep,int startColumnIndex,int endColumnIndex,int columnStep,int totalRows,int totalColumns);

void printArray(int** arr,int totalRows,int totalColumns);

int main(){
    int M;
    int N;
    printf("Enter the number of rows in the array: ");
    scanf("%d",&M);
    printf("Enter the number of columns in the array: ");
    scanf("%d",&N);
    
    int** arr = (int**) malloc(M*sizeof(int*));
    
    for(int i=0;i<M;i++) arr[i] = (int*) malloc(N*sizeof(int));
    puts("Enter the elements of the array(row-first): ");
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++) scanf("%d",&arr[i][j]);
    }
    
    puts("The input array is:");
    printArray(arr,M,N);
    
    int startRowIndex;
    int startColumnIndex;
    int endRowIndex;
    int endColumnIndex;
    int rowStep;
    int columnStep;
    printf("Enter the starting row index of your slice: ");
    scanf("%d",&startRowIndex);
    printf("Enter the starting column index of your slice: ");
    scanf("%d",&startColumnIndex);
    printf("Enter the ending row index of your slice (not included in the slice): ");
    scanf("%d",&endRowIndex);
    printf("Enter the ending column index of your slice (not included in the slice): ");
    scanf("%d",&endColumnIndex);
    printf("Enter the row step value: ");
    scanf("%d",&rowStep);
    printf("Enter the column step value: ");
    scanf("%d",&columnStep);
    
    int** slice = arraySlice(arr,startRowIndex,endRowIndex,rowStep,startColumnIndex,endColumnIndex,columnStep,M,N);
    
    if(slice){
       printArray(slice,1+(endRowIndex-startRowIndex-1)/rowStep,1+(endColumnIndex-startColumnIndex-1)/columnStep);
    }
    
    free(arr);
    free(slice);
    
    return 0;
}
int** arraySlice(int** arr,int startRowIndex,int endRowIndex,int rowStep,int startColumnIndex,int endColumnIndex,int columnStep,int totalRows,int totalColumns){
    int rowTraverseSize = 1+(endRowIndex-startRowIndex-1)/rowStep;
    int columnTraverseSize = 1+(endColumnIndex-startColumnIndex-1)/columnStep;
    
    if(startRowIndex+(rowTraverseSize-1)*rowStep>totalRows-1 || startColumnIndex+(columnTraverseSize-1)*columnStep>totalColumns-1){   //as current row is selected
        puts("You're going out of bounds! Ending program...");
        return NULL;
    }
    
    int row = 0;
    int column = 0;
    int** p = (int**) malloc(rowTraverseSize*sizeof(int*));
    for(int i=0;i<rowTraverseSize;i++) p[i] = (int*) malloc(columnTraverseSize*sizeof(int));
    for(int i=startRowIndex ; i<=startRowIndex+(rowTraverseSize-1)*rowStep ; i+=rowStep){
        for(int j=startColumnIndex ; j<=startColumnIndex+(columnTraverseSize-1)*columnStep ; j+=columnStep){
            p[row][column] = arr[i][j];
            column++;
        }
        row++;
        column = 0;
    }
    
    return p;
}

void printArray(int** arr,int totalRows,int totalColumns){
    for(int i=0;i<totalRows;i++){
        for(int j=0;j<totalColumns;j++) printf("%d ",arr[i][j]);
        puts(""); 
    }
}
