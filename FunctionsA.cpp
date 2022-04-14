#include "FunctionsA.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int getNumElements() {
    string unvalidatedInput{"Unset"};
    int validatedInput {0};

    do{
        cout << "How long would you like the array to be? (enter a number 2-10)" << endl
             << "My Selection: ";
        getline(cin,unvalidatedInput);
        cin.clear();
        validatedInput = posIntegerConvert(unvalidatedInput);
    }while(validatedInput < 2 || validatedInput > 10);

    return validatedInput;
}

int posIntegerConvert(string userInput){
    if (userInput.empty()){
        cout << "\nInput failed! Please enter something!" << endl;
        return -1;
    }
    
    // Since this function only makes sure an integer is returned, only whole numbers are allowed.
    for (int i {0}; i < userInput.length(); i++){
        if (userInput[0] == '-'){
            cout << "\nInput failed! Please enter a positive number (exclude the '+')." << endl;
            return -1;
        }
        if ( !isdigit(userInput[i]) ){
            cout << "\nInput failed! Please only use numbers." << endl;
            return -1;
        }
    }
    // userInput should be able to convert to int now without error, if it skips the previous two "if" statements
    return std::stoi(userInput);
}

int getRandom() {
    return (rand() % 100) + 1;
}

int * createDynamicArr(int numElements){
    int *arr = new int[numElements](); //This was also causing a lot of errors...
                                       // new int(numElements) would work sometimes, but not every time

    for(int i = 0; i < numElements; ++i){
        arr[i] = getRandom();
    }
    cout << "\n======================================================" << endl;
    cout << "Your array: [";
    for(int i = 0; i < numElements; ++i){
        cout << arr[i];
        if(i < (numElements - 1)){cout << ", "; } // If not on the last loop, print a comma
    }
    cout << "]" << endl;
    
    return arr;
}

void sortArray(int * array, const int &numElements){
    bool arraySorted {true};
    for(int i = 0; i <  numElements - 1; ++i){
        int temp {0};
        
        if(array[i] > array[i+1]){
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            arraySorted = false;
        }
    }
    if(!arraySorted){
        sortArray(array, numElements);
    }
}

void findArrayMedian(int * arr, const int &numElements) {
    bool isEven {true};
    double arrMedian {0};
    
    if(numElements % 2 != 0){
        isEven = false;
    }

    if(isEven){
        int lowerMiddleIndex {(numElements/2) - 1};
        int upperMiddleIndex {(numElements/2)};

        //===============================================================================================
        //This part was so weird; I finally figured out that the static casting would seemingly,
        //randomly crash my code. Specifically using the static_cast in the initialization of the double
        //===============================================================================================
        
        double lowerMiddleNumber {0.00}; 
        double upperMiddleNumber {0.00}; 
        lowerMiddleNumber = static_cast<double> (arr[lowerMiddleIndex]);
        upperMiddleNumber = static_cast<double> (arr[upperMiddleIndex]);
 
        //===============================================================================================
        
        arrMedian = (upperMiddleNumber + lowerMiddleNumber)/2.00;
        
        cout << endl << "==============================================" << endl
                     << "The median of the array is: " << arrMedian << endl
                     << "==============================================" << endl;
    }
    else if (!isEven){
        int medianIndex {numElements/2};
        arrMedian = *(arr + medianIndex);
        cout << endl << "==============================================" << endl
                     << "The median of the array is: " << arrMedian << endl
                     << "==============================================" << endl;
        
    }
}
