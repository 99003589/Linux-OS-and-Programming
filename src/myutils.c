#include "myutils.h"

//Function for factorial of a number
int factorial(int n)
{
  if (n == 0) 
    return 1;
  else
    return (n*factorial(n-1));
}

//Function to check prime number
int isPrime(int k)
{
   int x;
 
   for ( x = 2 ; x <= k - 1 ; x++ )
   { 
      if ( k % x == 0 )
     return 0;
   }
   return 1;
}
 
//Function for palindrome
int ispalindrome(int l){
    int r,sum=0,temp;
    temp=l;
    while(l>0)    
    {    
        r=l%10;    
        sum=(sum*10)+r;    
        l=l/10;    
    }    
    if(temp==sum)    
       return 1; 
    else     
       return 0;  

}
