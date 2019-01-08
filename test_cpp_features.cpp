#include <iostream>
#include <string>

using namespace std; 


int main(){

    cout << "In the main function \n"; 
    
    struct A_struct {
        char a = 'a'; 
        char b = 'b'; 
        char c = 'c'; 
    };

    cout << "The value of A is: " + "hello " + to_string(A_struct.a); 

    return 0; 
}


