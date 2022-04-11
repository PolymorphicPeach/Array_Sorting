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
    int *arr = new int(numElements);

    for(int i = 0; i < numElements; ++i){
        arr[i] = getRandom();
    }
    
    return arr;
}

void sortAndDisplayMedian(int * array, const int &numElements){
    //Checking for even or odd
    bool isEven {true};
    if(numElements % 2 != 0){
        isEven = false;
    }

    for(int i = 0;)
}

void evenSort(int * array, const int &numElements) {
    
}