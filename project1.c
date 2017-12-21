#include <stdio.h>
#include <stdlib.h>

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques15.c -- each of which tests your knowledge of bitwise C operations. Your goal is to determine what each function does and if there
is a simpler way to implement the function. There are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation.
 Once you determine the function, you should run the code to check your answer. 
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result. 
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result. 
 By simpler, we are interested in fewer operations in C but also more readable code. */

 
/*
 As an example, consider the answers to function ques0 - which you worked out in class.
 
 HANDIN Instructions: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, you can include comments in your code that may provide a secondary explanation (in case
 your report has errors). You MUST provide an explanation for what the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if
 your answers are simply a collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so.
 For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar to the example shown in ques0.c (i.e., the answer to function ques7.c should be named ans7.c).

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile without errors, you will get a zero for Part B of this project.
 
 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on the correctness of your answer, expressing the answer as a logical function where possible, and the efficiency and readability of your rewritten code.

 Collaboration: You can discuss the project with your teammate. You CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of both members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0 returns 1 if x=y and returns 0 if x is not equal to y */
/* the function ans0 does the same in two C statements */

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

/* Answer to PART B: */
int ans0(int x, int y){
    int z=0;
    if (x==y)  z= 0;
    else z= 1;
    return z;
}

/* QUESTIONS */

/* question 1 
This function has int x as a parameter. 
Inside of the function: 
An int z is declared. 
An int y is initialized to the value of the binary ones complement operator (~)
which flips the bits of x added to the value of 1. 
Then z is set equal to the binary ones complement of ( y | x) 
| is the BINARY OR operator which will check each bit of y and x and copy them to a new 
output if they exist in either one. Hence if one of the int's has a 1 in it it doesn't 
matter if the other does or does not have a 1. The 1 will still be copied to the output of OR. 
It will only copy a 0 if 0 exists at the same bit for both binary numbers. So y and x have the 
OR operation applied to them and then the one's complement operator  (~) will flip the bits of 
the OR operation. This is  what the value of z is set to at that line. 
Then in the next line z is set equal  to the value of z from the previous line shifted to the 
right by 31 bits. This means that 31 zeroes will be put in front of the previous binary value of z.
Then z has the AND operator with 1 performed on it. This means that at the first bit from the right
of z, it will return 1 only if this bit is also 1 in z, otherwise it will just return 0.
*/
int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);
    return (z & 1);
  
}

/* Answer to PART B: */
int ans1(int x) {
    int y  = ~x+1;
    int z = ((~(y|x)>>31)&1);
    return z;
}

/* question 2 
This function takes x as a parameter. 
First, int mask is set equal to the value of x right shifted by 31 bits. This means that the binary value of
x will have 31 zeroes placed in front of it.
Second, int y is set equal to the value of x XOR the value of mask from the previous step.
After that, an int z is set equal to the ones complement of the value of mask which means all the bits are flipped
and 1 is then added to this value. 
Finally, the value of y + the value of z is returned by the function.
*/
int ques2(x) {
int mask = x>>31;
    int y= (x ^ mask);
    int z = (~mask + 1);
    return (y+z);

}

/* Answer to PART B: */
int ans2(x) {
    return abs(x);

}

/* question 3 
This function takes int x and int y as parameters. 
The ones complement of x is taken so all of its bits are flipped and the ones complement of y is taken
so all of its bits are flipped as well. Then the OR operator is applied to both of these computed values
which means that if 1 exists in either binary number it will be copied to a new output, otherwise the value 
out that output will be 0. Finally, the ones complement operator is applied to the value from the previous 
step, flipping all the bits. This is the value that the function returns. 
*/
int ques3(int x, int y){
    return ~(~x | ~y);
}

/* Answer to PART B: */
int ans3(int x, int y){
    if(abs(x) == abs(y)){
        return abs(x);
    }
    else {
    return 0;
}

}


/* question 4 
This function takes int x and int y as a parameters. 
First, an int sum is set equal to the value of x added to the value of y. 
Then, an int x_neg is set equal to x right shifted by 31 bits meaning that it will be equal to the binary value of
x with 31 zeroes in front of it. 
Then an int y_neg is set equal to y right shifted by 31 bits putting 31 zeroes once again but this time
in front of y. 
Then, an int s_neg is set equal to the value of sum right shifted by 31 bits so the binary value of x + y has 
31 zeroes placed in front of it. 

The return has many operations being performed:
From the inside out:
1.x_neg ^ y_neg is the value of x_neg XOR the value of y_neg
2.This value has the ~ operator applied to it so the ones complement of the value from the previous step is taken
and all the bits are flipped.
3.x_neg ^ s_neg is the value of x_neg XOR the value of s_neg
4. The & operator is applied to the value computed from step 2 and the value computed from step 3. This means that
an output is generated where 1 has to exist in both of these values to be included in the output otherwise the value
at that bit will just be 1. 
5.The NOT (!) operator is finally applied to the value computed from step 4, this means that the output will only be 1
if the value at 4 is computed to be 0 otherwise the output will just be 0.

*/
int ques4(int x, int y) {

    int sum = x+y;
    int x_neg = x>>31;
    int y_neg = y>>31;
    int s_neg = sum>>31;

    return !(~(x_neg ^ y_neg) & (x_neg ^ s_neg));
}

/* Answer to PART B: */
int ans4(int x, int y) {

    int sum = x+y;
    int x_neg = x>>31;
    int y_neg = y>>31;
    int s_neg = sum>>31;

    return !(~(x_neg ^ y_neg) & (x_neg ^ s_neg));
}


/* question 5 
The function takes int x as a parameter. 
int result is declared an initialized to the value of x left shifted by 31 bits meaning that the binary value of 
x has 31 zeroes placed to the right of the first bit.
Then result is set equal to the value of result from the previous step right shifted by 31 bits which means
that 31 zeroes are placed to the left of the value computed from the previous step. 
The function returns -1 or 0 depending on if the shifts causes a 1 to stay at the 32nd bit of the number
or not based on the binary value of x.
*/

int ques5(int x) {


    int result = (x<<31);
    result = (result >> 31);
    return result;

}

/* Answer to PART B: */
int ans5(int x) {
    if ((x % 2)==0) {
        return 0;
    }
    else {
        return -1;
    }

}

/* question 6 
This function takes void as a parameter which just means that it does not take any parameters.
This means that int ques6(void) is the same thing as just writing int ques6(). 
An int byte is set to the hexadecimal value of 0x55. 0x55 in decimal form is 85 so this is what byte
is set equal to. 
Then, an int word is set equal to OR performed on the value of byte which is 85 and the value of
byte shifted to the left by 8 bits which is 21760. This OR of 85 and 21760 is equal to 21845. 
Then the value of word which is 21845 computed from the previous step has the OR operation performed
with word shifted to the left by 16 bits. The value of word of 21845 shifted to the left by 16 bits 
is equal to 141633920. The OR operator performed on 1431633920 with 21845 is equal to 1431655765.
Hence, the value returned by the function is 1431655765. 

*/

int ques6(void) {

    int byte = 0x55;
    int word = byte | byte<<8;
    return word | word<<16;
}

/* Answer to PART B: */
int ans6(void) {

    int byte = 0x55;
    int word = byte | byte<<8;
    return word | word<<16;
}
    

 /* question 7
This function takes an int x as the parameter. 
The AND operator is applied to the value of x with the value of the ones complement of x added to 1.
All the bits of x are flipped and then one is added. When this happens, depending on where there are 1's
there could be a carry. When the AND operator is applied to the value of ones complement of x, if the value of x
has just one of the bits as 1 and the rest are 0 then the function returns x. If not, then the function returns
the number of bits that are carried when 1 is added to the complement of x. 

*/

int ques7(int x) {
    
        return x & (~x+1);
}

/* Answer to PART B: */
int ans7(int x) {
    
        return x & (~x+1);
}



/* question 8 
This function has an int x as the parameter. 
An int xm1 is declared and set equal to the value of x + the complement of 0 which is 1 so it is just x + 1. 
Then an int possible is set equal to the NOT operation applied to the AND of the values of x and xm1. 
The AND produces an output with all the 1's at each bit if both x and xm1 contain them at a particular bit
and the rest of the bits are 0's. The NOT operator will make the value of possible equal to 0 since either
x or xm1 will have the first bit from the right as 0 and AND of 0 and 1 is 0 unless x is -1 which will make
possible equal to 1.
Therefore, possible will be 1 or 0.An int result is set equal to the AND of the value of possible (1 or 0) and 
the values of NOT NOT applied to x which is just x AND the value of not of (X & 1 shifted by 31 bits to the left 
(equal to 10000000000000000000000000000000 which is 2147482648 in decimal)) However due to the not, the value 
will be changed to 0. !!x will be equal to 0 unless the value of x is equal to 1.
These two values computed from the 2 previous steps (0 and 0 or 1) will have the AND operater performed on them 
which will be 0 no matter what. Then the AND of possible with 0 regardless of its computed value will be 0.
The value of result is returned which would be 0.
*/
int ques8(int x) {

    int xm1 = x + ~0;
    int possible = !(x&xm1);
    int result = possible & ( (!!x ) & !(x & (1<<31)));
    return result;
}

/* Answer to PART B: */
int ans8(int x) {

    int xm1 = x + ~0;
    int possible = !(x&xm1);
    int result = possible & ( (!!x ) & !(x & (1<<31)));
    return result;
}

/* question 9 
This function takes 3 parameters: int x, int n, and int c. 
An int n8 is set equal the value of n left shited by 3 bits so the value of n has 3 zeros put to the right of it. 
An int mask is set equal to 0xff shifted to the left by the value of n8. 0xff is the hexadecimal equivalent of 255
so 255 is shifted to the left by the value of n8. Then an int cshift is set equal
to the parameter c shifted by the the value of n8 bits to the left so n8 zeroes are put in front of the value of c. 
After this, an int z is set equal to the & of x and the complement of mask. 
Then the OR operation is applied on z and c shift and is returned. 
*/

int ques9(int x, int n, int c) {


            int n8 = n << 3;
            int mask = 0xff << n8;
            int cshift = c << n8;
            int z= (x & ~mask);
        return (z  | cshift);
}

/* Answer to PART B: */
int ans9(int x, int n, int c) {


            int n8 = n << 3;
            int mask = 0xff << n8;
            int cshift = c << n8;
            int z= (x & ~mask);
        return (z  | cshift);
}


/* question 10
This function takes no parameters.
An int byte is set equal to 0xAA in hexadecimal which is 170 in decimal.
Then, an int word is set equal to the OR of byte and byte shifted by 8 bits to the left. 
The value of byte is 170 which is equal to 10101010. Performing a left shift of 8 bits on
10101010 makes the value of byte<<8 equal to 1010101000000000 which is equivalent to 43520 in decimal form.
Performing OR on 43520 and 170 would equal to 43690 which is the same as just adding the two numbers. 
Hence. the value of word is 43690 (42350 + 170).
The value of word of 43690 has the OR operator performed on it with word shifted by 16 bits to the left.
43690 shifted by 16 bits to the left is 2863267840. 
The OR of 43690 and 2863267840 is 2863311530. 
However, due to the numbers consisting of 32 bits, the MSB is the sign bit which would be 1 so it would mean
2863311530 - 2^32 which would be 1431699456 but since the sign bit is 1 it would be -1431699456 and this 
is what the function returns.
*/
int ques10(void) {

                int byte = 0xAA;
                int word = byte | byte<<8;
                return word | word<<16;
}

/* Answer to PART B: */
int ans10(void) {

                int byte = 0xAA;
                int word = byte | byte<<8;
                return word | word<<16;
}



/* question 11 
This function takes int x as a parameter. An int m8 is set equal to 0xAA which is the 
hexadecimal form of 170. 
An int m16 is set equal to the OR of m8 and m8 left shifted by 8 bits. 
m8 left shifted by 8 bits is equal to 43520. m8 is equal to 170. 
The OR of 170 and 43520 is equivalent to 43690. This is what the value of 
m16 is set eqal to.
An int m32 is set equal to the OR of m16 and m16 left shifted by 16 bits.
m16 is equal to 43690. 43690 (m16) left shifted by 16 bits is 2863267840.
43520 OR 2863267840 is equal to 2863311530. Hence, m32 is equal to 2852170240. 
(--1431699456 if you consider the sign bit)
An int fillx is set equal to the binary OR operation to the value of x OR 
the value of m32.
Then what is returned is the complement of fillx with the NOT operator applied to 
it. If the MSB (most significant bit) is 1 then the value has 2^32 subtracted from it 
and is negative.
*/

int ques11(int x) {

                int m8  = 0xAA;
                int m16 = m8  | m8  << 8;
                int m32 = m16 | m16 <<16;
                int fillx = x | m32;
                return !~fillx;
}

/* Answer to PART B: */
int ans11(int x) {

                int m8  = 0xAA;
                int m16 = m8  | m8  << 8;
                int m32 = m16 | m16 <<16;
                int fillx = x | m32;
                return !~fillx;
}



/* question 12 
The function has 3 parameters: int x, int m, and int n.
An int a is set equal to the complement of m (all the bits are flipped) added to 1.
An int b is set equal to the complement of x (all the bits are flipped) added to 1.
Then a is set equal to x added to a, and b is set equal to b added to n.
The OR of a and b is taken. then it is right shifted by 31 bits. Then the NOT operator
is applied to this which will return 0 since it would not be possible for the operations 
performed in the parentheses to be equivalent to just one bit of 1.
Therefore, the function will always return 0. 
 */
int ques12(int x, int m, int n) {

                    int a = ~m+1;
                    int b = ~x +1;
                    a = x + a;
                    b = b + n;
                    return !((a|b) >> 31);
}

/* Answer to PART B: */
int ans12(int x, int m, int n) {

                    int a = ~m+1;
                    int b = ~x +1;
                    a = x + a;
                    b = b + n;
                    return !((a|b) >> 31);
}

/* question 13 
The function takes an int x as a parameter.
Then 5 int's: mask1, mask2, mask4, mask8 and mask 16 are declared.
First, mask 2 is set equal to the sum of 0x33 which is the decimal equivalent
of 51 and 0x33 shifted to the left by 8 bits which is equal to 13056 in decimal form.
51 + 13056 equal to 13107. Hence, this is what the value of mask2 is set to.
Then, mask2 is set equal to mask2 added to mask2 shifted to the left by 16 bits.
mask2 is equal to 13107 and mask2 shifted to the left by 16 bits is equal to 
858980352. Adding these two values produces a sum of 858993459 which is what mask2 is 
set equal to. 

On the next line, mask1 is set equal to mask2 XOR mask2 shifted to the left
by 1 bit. mask2 is equal to 858993459 and mask2 shifted to the left by 1 bit is equal 
to 1717986918. 858993459 XOR 1717986918 is an extremely large number which
will max out the 32 bits allowed for a number. In this application, we can just assume that
it is infinity. Therefore, mask1 is equal to infinity.

On the next line mask4 is equal to 0x0F + 0x0F shifted to the left by 8 bits.
0x0F is equivalent to 15 in decimal form. 15 shited to the left by 8 bits is equal to 
3840. 15 + 3840 = 3855. Hence, mask4 is equal to 3855. 

On the next line, mask4 is equal to the current value of mask4 which is 3855 added to that 
value shifted to the left by 16 bits. 3855 shifted to the left by 16 bits is equal to 
252641280. 252641280 + 3855 is equal to 252645135. Hence, mask4 is set to 252645135.

On the next line, mask8 is set equal to 0xFF + OxFF shifted to the left by 16 bits. 
0xFF is equal to 255 in decimal form. 255 shifted to the left by 16 bits is equal to
16711680. 16711680 + 255 = 16711935. Hence, mask8 is set to 16711935. 

On the next line, mask16 is set equal to 0xFF + 0xFF shifted to the left by 8 bits.
0xFF is equal to 255 in decimal form. 255 shifted to the left by 8 bits is equal to 65280.
65280 + 255 = 65535. Hence, mask16 is set to 65535. 

On the next line, x is equal to the AND of x and mask1 added to the AND of x shifted to the right 
by 1 bit and mask1. Since mask1 is infinity, both of the ANDS will produce a value of 32 bit's of 
of all 1's. The sum of these will be 32 bit's of all 1's as well. 
Hence, the value of x will be 32 bits of all 1's which is equal to 2147483647. 

On the next line, x is equal to the AND of x and mask2 added to the AND of x shifted to the right 
by 2 bits and mask2. mask2 is equal to 858993459 and x is equal to 2147483647.
The AND operator applied to x and mask2 is equal to 2147483647 still since x is 32 bits of all 1's.
x shifted to the right by 2 bits is equal to 536870911.
The AND operator applied to 536870911 and 858993459 is equal to 536870911.
Adding these two operators produces a value of 536870911 once again.

On the next line, x is equal to the AND of x and mask4 added to the AND of x shifted to the right 
by 4 bits and mask4. mask4 is equal to 252645135. 

On the next line, x is equal to the AND of x and mask8 added to the AND of x shifted to the right 
by 8 bits and mask8. mask8 is equal to 16711935. 

On the next line, x is equal to the AND of x and mask16 added to the AND of x shifted to the right 
by 16 bits and mask16. mask16 is equal to 65535.


*/

int ques13(int x) {

        int mask1, mask2, mask4, mask8, mask16;
        
        mask2 = 0x33 + (0x33 << 8);
        mask2 += mask2 << 16;
        mask1 = mask2 ^ (mask2 << 1);
        mask4 = 0x0F + (0x0F << 8);
        mask4 += mask4 << 16;
        mask8 = 0xFF + (0xFF << 16);
        mask16 = 0xFF + (0xFF << 8);
        
        x = (x & mask1) + ((x >> 1) & mask1);
        x = (x & mask2) + ((x >> 2) & mask2);
        x = (x & mask4) + ((x >> 4) & mask4);
        x = (x & mask8) + ((x >> 8) & mask8);
        x = (x & mask16) + ((x >> 16) & mask16);
    
        return x;
    }

/* Answer to PART B: */
int ans13(int x) {

        int mask1, mask2, mask4, mask8, mask16;
        
        mask2 = 0x33 + (0x33 << 8);
        mask2 += mask2 << 16;
        mask1 = mask2 ^ (mask2 << 1);
        mask4 = 0x0F + (0x0F << 8);
        mask4 += mask4 << 16;
        mask8 = 0xFF + (0xFF << 16);
        mask16 = 0xFF + (0xFF << 8);
        
        x = (x & mask1) + ((x >> 1) & mask1);
        x = (x & mask2) + ((x >> 2) & mask2);
        x = (x & mask4) + ((x >> 4) & mask4);
        x = (x & mask8) + ((x >> 8) & mask8);
        x = (x & mask16) + ((x >> 16) & mask16);
    
        return x;
    }
/* question 14 
The function has an int x as a parameter.
An int result is declared and initialized to 0.
Then an int i is declared.
A for loop goes from 0 to 31 incrementing after performing this operation:
The value of x is left shifted by the value of i and the AND operator is applied to this 
with 0x1 which is the hexadecimal equivalent of the decimal value of 1. 
Then result is set equal to the value of the current value of result (0 at first and then its
value from the previous time the operation was performed) XOR the value of the AND 
operation previously mentioned.
After the for loop increments i till 31, the value of result is returned. 

*/
int ques14(int x) {
    int result = 0;
    int i;
    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;
    return result;
}

/* Answer to PART B: */
int ans14(int x) {
    int result = 0;
    for (int i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;
    return result;
}

/* question 15 
The function takes an int x and an int n as a parameter.
An int temp is set equal to 1 left shifted by n bits. (n can not be a negative number so the shift will
always put n zeros to the right of 1).
An int z is set equal to the value of temp from the previous line added to the value of the complement
of 0 which is just 1. This means that z is just equal to temp + 1. 
Finally, the value of z has the AND operation performed on it with the value of x and this is what the 
function returns. 

*/

int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);
    int z = temp + ~0;
    return (z & x);

}

/* Answer to PART B: */
int ans15(int x, int n) {

    int temp = (1 << n);
    int z = temp + ~0;
    return (z & x);

}


 
int
main(){

    // Used to test ques1-ques15 and ans1-ans15 one after the other
    printf("\n");
    // ques1 test
    int x1 = 0;
    int test1 = ques1(x1);
    printf("Test for ques1: %d \n",test1);

    // ans1 test
    int a1 = 0;
    int testa1 = ans1(a1);
    printf("Test for ans1: %d \n",testa1);

    // ques2 test
    int x2 = -100;
    int test2 = ques2(x2);
    printf("Test for ques2: %d \n",test2);

    // ans2 test
    int a2 = -100;
    int testa2 = ans2(a2);
    printf("Test for ans2: %d \n",testa2);

    // ques3 test
    int x3x = -2;
    int x3y = 2;
    int test3 = ques3(x3x,x3y);
    printf("Test for ques3: %d \n",test3);

    // ans3 test
    int a3x = -2;
    int a3y = 2;
    int testa3 = ans3(a3x,a3y);
    printf("Test for ans3: %d \n",testa3);

    // ques4 test
    int x4x = 10;
    int x4y = 15;
    int test4 = ques4(x4x,x4y);
    printf("Test for ques4: %d \n",test4);

    // ans4 test
    int a4x = 10;
    int a4y = 15;
    int testa4 = ans4(a4x,a4y);
    printf("Test for ans4: %d \n",testa4);

    // ques5 test
    int x5 = 21;
    int test5 = ques5(x5);
    printf("Test for ques5: %d \n",test5);

    // ans5 test
    int a5 = 21;
    int testa5 = ans5(a5);
    printf("Test for ans5: %d \n",testa5);

    // ques6 test
    int test6 = ques6();
    printf("Test for ques6: %d \n",test6);

    // ans6 test
    int testa6 = ans6();
    printf("Test for ans6: %d \n",testa6);

    // ques7 test
    int x7 = -5;
    int test7 = ques7(x7);
    printf("Test for ques7: %d \n",test7);

    // ans7 test
    int a7 = -5;
    int testa7 = ans7(a7);
    printf("Test for ans7: %d \n",testa7);

    // ques8 test
    int x8 = 5;
    int test8 = ques8(x8);
    printf("Test for ques8: %d \n",test8);

    // ans8 test
    int a8 = 5;
    int testa8 = ans8(a8);
    printf("Test for ans8: %d \n",testa8);

    // ques9 test
    int x9x = 1;
    int x9n = 1;
    int x9c = 1;
    int test9 = ques9(x9x,x9n,x9c);
    printf("Test for ques9: %d \n",test9);

    // ans9 test
    int a9x = 1;
    int a9n = 1;
    int a9c = 1;
    int testa9 = ans9(a9x,a9n,a9c);
    printf("Test for ans9: %d \n",testa9);

    // ques10 test
    int test10 = ques10();
    printf("Test for ques10: %d \n",test10);

    // ans10 test
    int testa10 = ans10();
    printf("Test for ans10: %d \n",testa10);

    // ques11 test
    int x11 = 1;
    int test11 = ques11(x11);
    printf("Test for ques11: %d \n",test11);

    // ans11 test
    int a11 = 1;
    int testa11 = ans11(a11);
    printf("Test for ans11: %d \n",testa11);

    // ques12 test
    int x12x = 3;
    int x12m = 1;
    int x12n = 1;
    int test12 = ques12(x12x,x12m,x12n);
    printf("Test for ques12: %d \n",test12);

    // ans12 test
    int a12x = 3;
    int a12m = 1;
    int a12n = 1;
    int testa12 = ans12(a12x,a12m,a12n);
    printf("Test for ans12: %d \n",testa12);

    // ques13 test
    int x13 = 3;
    int test13 = ques13(x13);
    printf("Test for ques13: %d \n",test13);

    // ans13 test
    int a13 = 3;
    int testa13 = ans13(a13);
    printf("Test for ans13: %d \n",testa13);

    // ques14 test 
    int x14 = 1;
    int test14 = ques14(x14);
    printf("Test for ques14: %d \n",test14);

    // ans14 test 
    int a14 = 1;
    int testa14 = ans14(a14);
    printf("Test for ans14: %d \n",testa14);

    // ques15 test
    int x15x = 3;
    int x15n = 1;
    int test15 = ques15(x15x,x15n);
    printf("Test for ques15: %d \n",test15);

    // ans15 test
    int a15x = 3;
    int a15n = 1;
    int testa15 = ans15(a15x,a15n);
    printf("Test for ans15: %d \n",testa15);
    printf("\n");


}
