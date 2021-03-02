#include "bitmask.h"

//Function to set bit
int set(int m, int n) 
{ 
    return (m | (1 << (n - 1))); 
} 
  
// Function to reset the nth bit of m 
int reset(int m, int n) 
{ 
    return (m & (~(1 << (n - 1)))); 
} 
  
// Function to toggle the nth bit of m 
int flip(int m, int n)
{ 
    return (m ^ (1 << (n - 1))); 
} 

int query(int m,int n)
{

}

