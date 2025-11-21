#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"


/// Teil 1 //////
/*int const globalVar = 2;
int globalVar2;
int static globalVar3 = 0;*/

////// Teil 4 ////////
void foo() { 
    fmt::print("Hello from foo!\\n"); 


}

int main(int argc, char **argv) {

   
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
  

    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    ///// Teil 1 ///////

    /* 
    fmt::print("Adresse Variable 1, {}\n", fmt::ptr(&globalVar));
    fmt::print("Adresse Variable 2, {}\n", fmt::ptr(&globalVar2));
    fmt::print("Adresse Variable 3, {}\n", fmt::ptr(&globalVar3));
    */

    //Adresse verändert sich pro Ausführung
    // Teil 1, 4. 
    //////** Adresse Variable 1, 0x6545ed7c3020
          // Adresse Variable 2, 0x6545ed7c3028
          //  Adresse Variable 3, 0x6545ed7c302c  
  // Teil 1, 5. 
        // Adresse Variable 1, 0x5f8a7b898020
        // Adresse Variable 2, 0x5f8a7b898028
        // Adresse Variable 3, 0x5f8a7b896068
        // static benötigt ca. 8kByte


    /////////// Teil 2 //////////

    /* 
    int const localVar = 2;
    int localVar2;
    int static locallVar3 = 0;

    fmt::print("Adresse localVar1, {}\n", fmt::ptr(&localVar));
    fmt::print("Adresse localVar2, {}\n", fmt::ptr(&localVar2));
    fmt::print("Adresse localVar3, {}\n", fmt::ptr(&locallVar3));
    */

    // Erkenntnis: static Variablen sind außerhalb des Stacks, daher anderer Speicherbereich
    // bei lokalen Variablen wächst Stack nach unten (neue Variablen werden weiter unten gespeichert)

    //////// Teil 3 //////////

    // new int() reserviert speicher das Int auf dem Heap
    // speichert dauerhaft, wird erst mit delete entfernt
    
    /*
    int* heapVar = new int(3);

    fmt::print("Adresse heapVar, {}\n", fmt::ptr(&*heapVar));
    fmt::print("Wert heapVar, {}\n",  *heapVar);

    delete heapVar;

        fmt::print("Adresse d heapVar, {}\n", fmt::ptr(&*heapVar));
        fmt::print("Wert d heapVar, {}\n",  *heapVar);

        */

    ////// Teil 4 /////////
    fmt::print("Adresse von foo: {}\\n", fmt::ptr(&foo));

    return 0; /* exit gracefully*/
}


