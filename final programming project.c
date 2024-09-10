#include <stdio.h>
#include <math.h>
#include<string.h>
#include<conio.h>
#define Max 1000

int binarytodecimal2(char binumber2[]);
int BinaryToDecimal(char binaryNumber[]);
void decimaltobinary(int value3);
void hexadecimaltobinary(char hexanum5[]);

int main()
{
  int select=0;
  char binaryNumber[33];
  int x3;
  int num3;
  char binaryNumber2[33];
  int decimalresult2;
  int decimalResult;
  char hex4;
  char binarynum5[Max],hexa5[Max];
  while (1){
    printf("\033[1;36m");
    printf("\n**************************************WELCOME TO NUMBERING SYSTEM CONVERTER PROGRAM*************************************\n");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("\nINSTRUCTION\nEnter Numbers Without Space");
    printf("\nEnter -1 To End The Program\n");
    printf("\033[0m");
    printf("\n1-DEC2BIN\n2-DEC2HEX\n3-BIN2DEC\n4-BIN2HEX\n5-HEX2DEC\n6-HEX2BIN\n");
    printf("\nEnter The Number Of The Program: ");
    scanf("%d",&select);
    if (select==-1){
        printf("\033[1;36m");
        printf("****************************************************Program Ended*******************************************************\n");
        printf("\033[0m");
        break;
    }
    switch (select){
     case 1:{
      // a program to display an integer number in binary representation
      printf("%s","\nEnter The Decimal Number: ");
      scanf("%d",&x3);
      decimaltobinary(x3);
      break;
     }
     case 2:{
      // a program to display numbers in hexadecimal
      printf("\nEnter The Decimal Number: ");
      scanf("%d",&num3);
      printf("Hexadecimal Equivalent: %#X\n",num3);
      break;
     }
     case 3:{
      //a program to convert binary to decimal
      printf("\nEnter The Binary Number: ");
      scanf("%32s",binaryNumber2);
      decimalresult2 = binarytodecimal2(binaryNumber2);
      printf("Decimal Equivalent: %d\n",decimalresult2);
      break;
     }
     case 4:{
       //a program to convert binary to hexadecimal
       printf("\nEnter the Binary Number: ");
       scanf("%s", binaryNumber);
       decimalResult = BinaryToDecimal(binaryNumber);
       printf("Hexadecimal Equivalent: %#X\n", decimalResult);
       break;
     }
     case 5:{
      //a program to convert hexadecimal to decimal
      printf("\nEnter the Hexadecimal Number: ");
      scanf("%x",&hex4);
      printf("Decimal Equivalent:%d \n",hex4);
      break;
     }
     case 6:{
      //a program to convert hexadecimal to binary
      printf("\nEnter The Hexadecimal Number: ");
      scanf("%s",&hexa5);
      printf("Binary equivalent: ");
      hexadecimaltobinary(hexa5);
      break;
     }
     default:{
        printf("\033[1;31m");
        printf("\t\tPLEASE ENTER CORRECT NUMBER");
        printf("\033[0m");
        break;
     }
    }
  }
}

int BinaryToDecimal(char binaryNumber[]) {
    int binaryLength = strlen(binaryNumber);
    int decimalNumber = 0;
    int signBit = (binaryNumber[0] == '1') ? -1 : 1;
    if (signBit==-1){
      // Invert all bits (one's complement)
      for (int i = 0; i < binaryLength; ++i) {
         binaryNumber[i] = (binaryNumber[i] == '0') ? '1' : '0';
      }

      // convert array to integer number
      for (int i = binaryLength - 1; i >= 0; --i) {
        int digit = binaryNumber[i] - '0';
        decimalNumber += digit * pow(2, binaryLength - 1 - i);
      }
      decimalNumber++; //two's complement
      return signBit * decimalNumber;
    }
    else{
      for (int i = binaryLength - 1; i >= 0; --i) {
        int digit = binaryNumber[i] - '0';
        decimalNumber += digit * pow(2, binaryLength - 1 - i);
      }
      return  decimalNumber;
    }
}


void decimaltobinary(int value3){

     unsigned int mask3 = 1<<31 ;
     printf("Binary equivalent: ");
     for (unsigned int c=1 ; c<=32 ; ++c)
      {
        //display bits
        putchar(value3 & mask3 ? '1':'0');
        value3 <<=1;
        if (c%8 == 0)
          {
              putchar(' ');
          }
      }
    putchar('\n');
}


int binarytodecimal2(char binumber2[]){
    int decresult=0;
    int binaryLength = strlen(binumber2);
    if(binumber2[0]=='0')
    {
      for(int i=0;i<strlen(binumber2);++i)
        {
           int  bitvalue = binumber2[i] - '0'; // Convert character to integer
           if(bitvalue==1)
            {
              decresult += pow(2,binaryLength-1);
              binaryLength--;
            }
           else if (bitvalue==0)
            {
              binaryLength--;
            }
        }
    }
    else if(binumber2[0]=='1')
    {
      for(int i=0;i<strlen(binumber2);++i)
        {
           binumber2[i] = ( binumber2[i] == '1' ? '0' : '1' ); // Invert all bits (one's complement)
           int  bitvalue = binumber2[i] - '0'; // Convert character to integer
           if(bitvalue==1)
             {
              decresult += pow(2,binaryLength-1);
              binaryLength--;
             }
           else if (bitvalue==0)
             {
              binaryLength--;
             }
        }
      decresult += 1; //two's complement
      decresult *= -1;
    }
    return decresult;
}


void hexadecimaltobinary(char hexanum5[]){
    int i5=0;
    while(hexanum5[i5])
    {

        switch(hexanum5[i5])
        {
        case'0':
            printf("0000 "); break;
        case'1':
            printf("0001 "); break;
        case'2':
            printf("0010 "); break;
        case'3':
            printf("0011 "); break;
        case'4':
            printf("0100 "); break;
        case'5':
            printf("0101 "); break;
        case'6':
            printf("0110 "); break;
        case'7':
            printf("0111 "); break;
        case'8':
            printf("1000 "); break;
        case'9':
            printf("1001 "); break;
        case'A':
            printf("1010 "); break;
        case'a':
            printf("1010 "); break;
        case'B':
            printf("1011 "); break;
        case'b':
            printf("1011 "); break;
        case'C':
            printf("1100 "); break;
        case'c':
            printf("1100 "); break;
        case'D':
            printf("1101 "); break;
        case'd':
            printf("1101 "); break;
        case'E':
            printf("1110 "); break;
        case'e':
            printf("1110 "); break;
        case'F':
            printf("1111 "); break;
        case'f':
            printf("1111 "); break;
        default:
            printf("\033[1;31m");
            printf("\n\tInvalid Hexadecimal Digit %c ", hexanum5[i5]);
            printf("\033[0m");
        }
        i5++;
    }
    printf("\n");
}

