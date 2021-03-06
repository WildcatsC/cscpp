#include <iostream>
#include <string>
using namespace std;

// The basic formula to calculate the value
int formula(int limit, int payment, double inc, int child){    
   int res = 0;
   res = payment - (inc - limit)/100*5 + child*500;
   if(res < 0) return 0;
   return res; 
}

// The calculator to compute the check value in terms of status
int calculator(string status, int income, int children){

    if(status == "Single"){
        if(income <= 75000) return 1200 + children*500;
        return formula(75000, 1200, income, children); 
    }
    if(status == "Married"){
        if(income <= 150000) return 2400 + children*500;
        return formula(150000, 2400, income, children);
    }
    if(status == "Head of Household"){
        if(income <= 112500) return 1200 + children*500;
        return formula(112500, 1200, income, children);
    }
    cout << status << endl;
    return -1;  // all other inputs of status returns -1, will be used in main().
}

// Check inputs errors in main().
int main(){
    string status;
    double income;
    int children;
    int result;

    cout << "What is your filing status?";
    getline(cin, status);
    result = calculator(status, 0, 0); // check if the status input is valid 
    if(result < 0){
        cout << "Error - Invalid filing status." << endl;
        return 0;
    }

    cout << "What is your adjusted gross income?";
    cin >> income;
    if(income < 0) {
        cout << "Error - Invalid income." << endl;
        return 0;
    }

    cout << "How many children under the age of 17 did you claim as a dependent?";
    cin >> children;
    if(children < 0){
        cout << "Error - Invalid number of dependents." << endl;
        return 0;
    }

    result = calculator(status, income, children);
    if(result >=0) printf("Your stimulus check is $%d\n", result); 

    return 0;
}

