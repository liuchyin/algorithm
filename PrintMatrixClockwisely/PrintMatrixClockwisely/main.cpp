//
//  main.cpp
//  PrintMatrixClockwisely
//
//  Created by Cong on 13-3-8.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
using namespace std;


void printClockwisely(int** matrix, int row, int column){
    for(int j = 0; j != column; j++)
        cout<<matrix[0][j]<<endl;
    for(int i = 1; i != row; i++)
        cout<<matrix[i][column - 1]<<endl;
    
    if(row >= 2){
        for(int j = column - 2; j >= 0; j--)
            cout<<matrix[row - 1][j]<<endl;
    }
    if(column >= 2){
        for(int i = row - 2; i >= 1; i--)
            cout<<matrix[i][0]<<endl;
    }
    //int *pTemp = &(matrix[1][1]);
    //int **pNewMatrix = &pTemp;
    
    if(row > 2 && column > 2){
        int **pNewMatrix = new int*[row - 2];
        for(int i = 0; i != row - 2; ++i)
            pNewMatrix[i] = matrix[i + 1] + 1;
        printClockwisely(pNewMatrix, row - 2 , column - 2);
        delete pNewMatrix;
    }
}

void print(int** matrix, int row, int column){
    for(int i = 0; i != row; ++i){
        for(int j = 0; j != column; ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main(int argc, const char * argv[])
{
    int column = 6;
    int row = 5;
    int** matrix = new int*[row];
    for(int i = 0; i != row; ++i)
        matrix[i] = new int[column];
    
    for(int i = 0; i != row; i++)
        for(int j = 0; j != column; j++)
            matrix[i][j] = i * row + j;
    
    print(matrix, row, column);
    
    printClockwisely(matrix, row, column);
    return 0;
}

