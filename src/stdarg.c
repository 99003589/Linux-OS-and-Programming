#include "stdarg.h"
int vsum(va_list, va_arg, va_start,va_end)
{
  int i,vsum;
  va_list num;
  va_start(num,N);
  
  vsum=0;
  for(i=0;i<N;i++)
  {
  vsum+=va_arg(var,int);
  }
  return vsum;
}
