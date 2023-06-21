#include <stdio.h>
#include <stdlib.h>

long long decimalToBinary(int decimal) {
    long long binary = 0;
    int remainder, base = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}
// Function to convert binary to decimal
int binaryToDecimal(long long binary) {
    int decimal = 0, weight = 1, remainder;

    while (binary!=0) {
        remainder = binary % 10;
        decimal += remainder * weight;
        binary /= 10;
        weight *= 2;
    }

    return decimal;
}

// Function to perform calculations based on the number system

int calculate(int n) {
    int num1, num2;
    char op;
    int ans;

    switch (n) {
        case 1:
            printf("Enter the first hexadecimal number: ");
            scanf("%x", &num1);
            printf("Enter the operator (+, -, *, /): ");
            scanf(" %c", &op);
            printf("Enter the second hexadecimal number: ");
            scanf("%x", &num2);
            break;
        case 2:
            printf("Enter the first decimal number: ");
            scanf("%d", &num1);
            printf("Enter the operator (+, -, *, /): ");
            scanf(" %c", &op);
            printf("Enter the second decimal number: ");
            scanf("%d", &num2);
            break;
        case 3:
            //int n1,n2;
            printf("Enter the first binary number: ");
            scanf("%lld", &num1);
            printf("Enter the operator (+, -, *, /): ");
            scanf(" %c", &op);
            printf("Enter the second binary number: ");
            scanf("%lld", &num2);
            num1 = binaryToDecimal(num1);
            num2 = binaryToDecimal(num2);
            break;
	
        default:
            printf("Invalid number type.\n");
            
    }

    switch (op) {
        case '+':
           ans= num1+num2;
            break;
        case '-':
            ans= num1-num2;
            break;
        case '*':
           ans= num1*num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                
            } else {
                ans= num1/num2;
            }
            break;
           
        default:
            printf("Invalid operator.\n");
            break;
            
    }
    
    return ans;
  
}

int main() {
    //Here n is number type
    int n;
    int ans;
    printf("Number Type:\n");
    printf("1. Hexadecimal\n");
    printf("2. Decimal\n");
    printf("3. Binary\n");
    printf("Select the number type: ");
    scanf("%d", &n);

    ans=calculate(n);
   
    if(n==1)
    {
        long remainder,quotient = ans;
        int i, j = 0;
        char hexadecimalnum[100];
 
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    for (i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
    }
    else if(n==2)
    {
        printf("%d",ans);
    }
    else if(n==3)
    {
        long long int A3;
        A3=decimalToBinary(ans);
        printf("%lld",A3);
    }
    return 0;
}