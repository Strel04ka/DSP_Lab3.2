#include <iostream>
using namespace std;

int main()
{
    int n = 9;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
   
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0; 
   
    for (int j = 0; j < n; j++){
        matrix[j][0] = 1;
        matrix[j][j] = 1;}

    for (int i = 2; i < n; i++)
        for (int j = 1; j < i; j++)
            matrix[i][j] = matrix[i - 1][j - 1] + (j + 1) * matrix[i - 1][j];

    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            if (matrix[j][k] < 0)
                matrix[j][k] = 0;

    int* B = new int[n];
    for (int f = 0; f < n; f++)
        B[f] = 0;

    for (int j = 0; j < n; j++) 
        for (int k = 0; k < n; k++)
            B[j] += matrix[j][k];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << "B[" << i << "] = " << B[i] << endl;
        cout << "\n\n\n";}
     
}
