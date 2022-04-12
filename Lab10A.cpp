#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FunctionsA.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
    srand(time(0)); //Setting a seed based on the time for rand()
    int numElements {0};
    int * arr;

    numElements = getNumElements();
    arr = createDynamicArr(numElements);
    sortArray(arr, numElements);

    for(int i = 0; i < numElements; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    
    return 0;
}
