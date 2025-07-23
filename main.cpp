
#include <iostream>

void run_calculator();
int get_result(int &a, int &b, char & op);



int main(){
    
    run_calculator();

// TEST PUSH
return 0;

}


void run_calculator(){


    int a, b;
    char op;

std::cout << "Enter two numbers" << std::endl;

std::cin >> a >> b;

std::cout << "Enter operation" << std::endl;


std::cin >> op;

std::cout << std::endl;

std::cout << get_result(a, b, op) << std::endl;



}


int get_result(int &a, int &b, char & op){

    switch(op){

    case '+': return a + b;
    case '*': return a * b;
    case '-': return a - b;
    case '/': 
        if (b != 0){

            return a / b;
        }
        else {
            throw("Error: division by 0");
            
        }
    }
    return 0;
}