#include <iostream>
#include "functions.h"

using namespace std;

void sayHello(){
    cout << "Hello from functions!" << endl;
}

int Factorial(int n){
    if (n==1) return 1;
    return n * Factorial(n-1);
}

int LNKO(int a,int b){
     if (b == 0) {
        return a; 
    }
    return LNKO(b, a % b);
}

int QuickSquare(int n, int i){
    if ( i == 0 ) return 1;
    if ( i == 1 ) return n;
    if( i % 2 == 0 ){
        return (QuickSquare(n*n, i/2));
    }else{
        return n*(QuickSquare(n*n, i/2));
    }
}

int Fibonacci(int n){
    if (n <= 1) {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int NumberMultiplication(int n){
    if(n==0) return 1;
    return (n%10) * NumberMultiplication(n/10);
}

// II
void SwitchedUpArrayWriteing(int n[],int i){
    cout << n[i]<<" ";
    if (i >= 0) SwitchedUpArrayWriteing(n,i-1);
}

int ArraySumm(int n[],int i){
    if(i == 0) return n[i];
    return n[i]+ArraySumm(n,i-1);
}

int ArrayMax(int n[],int i){
    if (i == 0) {
        return n[0];
    }
    
    int maxOfRest = ArrayMax(n, i - 1);
    if (n[i] > maxOfRest) {
        return n[i];
    } else {
        return maxOfRest;
    }
}

int CountEvens(int n[], int i){
    if (i < 0) return 0;

    int currentIsEven = (n[i] % 2 == 0) ? 1 : 0;
    return currentIsEven + CountEvens(n, i - 1);
}

bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int CountPrimes(int n[], int i){
    // Bázis eset
    if (i < 0) return 0;

    // Ha az aktuális prím, akkor 1-et adunk a többi eredményéhez
    int currentIsPrime = isPrime(n[i]) ? 1 : 0;

    return currentIsPrime + CountPrimes(n, i - 1);
}
