#include <iostream>

int main()
{
    // 1D Array
    int * array = new int[50]; // Allocating 50 * 4 bytes - Normal 1D array

    // 2D Array
    int ** array2D = new int*[50]; // Allocating 50 * 4 bytes. Remember that you are not allocating the second dimension of arrays with this allocation! With this line of code, you just allocated 50 int pointers.
    for (int i = 0; i < 50; i++)
        array2D[i] = new int[50]; // Allocating 50 * 4 bytes, but since this is done 50 times. We end up with 50 * 50 * 4 bytes

    for (int x = 0; x < 50; x++) // C++ stores multidimensional arrays in a row-major order
    {
        for (int y = 0; y < 50; y++)
        {
            array2D[x][y] = 2;
        }
    }

    // 3D Array - If you do not understand how it works right away, get a piece of paper and sketch a diagram
    int *** array3D = new int**[50];
    for (int i = 0; i < 50; i++)
    {
        array3D[i] = new int*[50];
        for (int j = 0; j < 50; j++)
            array3D[i][j] = new int[50];
    }

    // Better way to store a "2D Array"
    for (int i = 0; i < 50; i++)
        delete[] array2D[i];
    delete[] array2D; // This line of code only frees the memory allocated in line 9!

    int * otherArray = new int[5 * 5];
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
            otherArray[y + x * 5] = 2;
    }

    delete[] array;
    delete[] otherArray;
}