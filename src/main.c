#include <stdio.h>

//  Write a C program that takes any number and converts it to binary, octal, and hex — displaying it as actual bit patterns. Then extend it to perform AND, OR, XOR on two numbers and show the result bit by bit.//

void print_binary_no(int );

void print_octal_no(int);

void print_hexa_no(int);

void performAND(int,int);
void performOR(int,int);
void performXOR(int,int);

int main() {
    int number,choice;
    printf("Select which function you want to use !\n");
    printf("\tOPTIONS\t\n");
    printf("1. Number conversion to Decimal ,Octal ,Hexadecimal \n");
    printf("2. Perform AND, OR, XOR operation\n");

    printf("Enter your choice 1 or 2 : ");
    scanf("%d",&choice);

    if(choice== 1){
        printf("Enter the number: ");
        scanf("%d",&number);
        
        print_binary_no(number);
        print_octal_no(number);
        print_hexa_no(number);
    }
    else if (choice==2)
    {       
        int num1, num2;
        printf("Enter the first number:");
        scanf("%d",&num1);
        printf("Enter the second number:");
        scanf("%d",&num2);
        
        performAND(num1,num2);
        printf("\n");
        performOR(num1,num2);
        printf("\n");
        performXOR(num1,num2);
        printf("\n");
    }
    else
    printf("INVALID INPUT!");
    

    return 0;
}
void print_binary_no(int n){
    printf("The binary representation of %d is: ",n);

    int started = 0; /*started variable for eliminating the extra zeros from the 32 bit representation to make the code look good*/

    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;

        if (bit || started || i == 0)
        {
            printf("%d", bit);
            started = 1;
        }
    }

    printf("\n");
}



void print_octal_no(int n)
{
    printf("Octal representation : ");

    int started = 0;

    // here we are extracting 3 bits at a time

    for (int i = 30; i >= 0; i -= 3) 
     //30 liya kyuki apan ko 32 bits ko 3-3 ke grps main divide krna hain oth   strting with (0,1,2) so on we get to (28,29,30)//aur aise krke apan ne 31 tk cover krli

    {
        int digit = (n >> i) & 7;     // 7 = 111

        if (digit || started || i == 0)
        {
            printf("%d", digit);
            started = 1;
        }
    }

    printf("\n");
}

void print_hexa_no(int n){
    printf("Hexadecimal representation: ");

    int started = 0;

    // Extract 4 bits at a time
    for (int i = 28; i >= 0; i -= 4)
    {
        int digit = (n >> i) & 15;    // 15 = 1111

        if (digit || started || i == 0)
        {
            if (digit < 10)
                printf("%d", digit);
            else
                printf("%c", 'A' + digit - 10);

            started = 1;
        }
    }

    printf("\n");
}
void performAND(int a , int b)
{
    
    int result = a & b;
    print_binary_no(a);
    print_binary_no(b);
    printf("The AND operation between them is: %d",result);
    printf("\n");
    
}
void performOR(int a , int b)
{
    int result = a | b;
    print_binary_no(a);
    print_binary_no(b);
    printf("The OR operation between them is: %d\n",result);
    printf("\n");
}
void performXOR(int a , int b)
{
    int result = a ^ b;
    print_binary_no(a);
    print_binary_no(b);
    printf("The XOr operation between them is: %d\n",result);
    printf("\n");
}