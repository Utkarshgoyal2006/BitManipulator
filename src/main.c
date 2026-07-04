#include <stdio.h>

//  Write a C program that takes any number number and converts it to binary, octal, and hex — displaying it as actual bit patterns. Then extend it to perform AND, OR, XOR on two numbers and show the result bit by bit. This teaches you bit manipulation in C (which BEL interviews ask directly) and reinforces number systems from their digital electronics syllabus. Every time you write n & 1 or n >> 1 you're doing what BEL's technical paper tests — just in code form instead of theory.
void print_binary_no(int );



int main() {
    int number;

    printf("Enter the number: ");
    scanf("%d",&number);

    print_binary_no(number);

    return 0;
}
void print_binary_no(int n){
    printf("The binary representation of %d is : ",n);
    
    for(int i=7 ; i>=0 ;i--){
        printf("%d",(n>>i & 1));
    }
    printf("\n");
}