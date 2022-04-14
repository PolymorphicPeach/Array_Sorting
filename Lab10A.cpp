// Student: Matthew Peach
// Program Status: Complete
// Description:
//    This program will ask you how large you would like an array, then dynamically allocate an array to the heap
//  of that size. The array is populated with random integers, sorted from least to greatest, then the median
//  is displayed. I tried to use a function a header file, since I usually don't do that - it was ok, but I do still
//  find it easier to put everything into one file. Interestingly, using static_cast was causing me *a lot* of hard-
//  to-catch issues. Sometimes the program would run fine on the first loop, crash on the second, go a few loops, then
//  crash, or never run at all. It appears to be fixed now; I "separated" the casting out between multiple statements
//  instead of putting it all into one.

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
