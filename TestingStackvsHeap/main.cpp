struct Vector3
{

    float x, y, z;
    Vector3() : x(10), y(11), z(12) { }

};

int main()
{

    // Stack Allocation
    int value = 5;
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    Vector3 vector;

    // Heap Allocation
    int * hValue = new int;
    *hValue = 5;
    int * hArray = new int[5];
    hArray[0] = 1;
    hArray[1] = 2;
    hArray[2] = 3;
    hArray[3] = 4;
    hArray[4] = 5;
    Vector3 * hVector = new Vector3();

}