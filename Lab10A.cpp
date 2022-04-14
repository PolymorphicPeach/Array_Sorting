#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FunctionsA.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string goAgainInput {"Unset"};
    
    srand(time(0)); //Setting a seed based on the time for rand()
    
    
    do{
        int * arr;
        int numElements {0};
        
        numElements = getNumElements();
        arr = createDynamicArr(numElements);
        sortArray(arr, numElements);

        cout << endl << "Sorting Array..." << endl
             << "[ ";
        for(int i = 0; i < numElements; i++){
            cout << arr[i] << " ";
        }
        cout << " ]" << endl;
    
        findArrayMedian(arr, numElements);

        arr = nullptr; // Free the memory
        delete[] arr;
        
        do{
            cout << "Would you like to generate another array? (y/n)" << endl
                 << "My Selection: ";
            getline(cin, goAgainInput);
            cin.clear();
            cout << endl;
        }while(goAgainInput != "y" && goAgainInput != "Y" && goAgainInput != "n" && goAgainInput != "N");
        
    }while(goAgainInput == "y" || goAgainInput == "Y");

    
    
    return 0;
}
