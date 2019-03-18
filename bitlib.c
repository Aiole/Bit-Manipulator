#include<stdio.h>
/*
 * bitwise_nor  - implement ~(x|y) using only ~ and &.
 *  Example biwise_nor(6, 5) = 0xFFFFFFF8
 *  Max. # of operators: 8
 */
int bitwise_nor(int x, int y) {
  //int xy;
 /* x = ~x;
  y = ~y;
  xy = x&y;
  */
  x = !(x);
  return x;
 

}


/* 
 * bitwise_xor - implement x xor y using only ~ and &.
 * Example bitwise_xor(4,5) = 0x1
 * Max # of operators: 14
 */
int bitwise_xor(int x, int y) {
  int xy1,xy2,xyf;
  xy1=x&~y;
  xy2=~x&y;
  x=~xy1;
  y=~xy2;
  xyf=~(x&y);
  
  return xyf;
}

/*
 * eval_not_equal - implement x!=y.
 *  using only !, ~, &, |, ^, +, << and >>
 *   returns 0 if x == y, otherwise 1
 * Examples: eval_not_equal(2,2) = 0, eval_not_equal(3,4) = 1
 * Max # of operators: 6
 */
int eval_not_equal(int x, int y) {
  int xy;
  xy=!(x&y);
 return xy;
    


}


/*
 * get_byte - extract byte n from word x.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * assume ordering as 0=least significant byte,  
 * 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56
 * Max # of operators: 6
*/
int get_byte(int x, int n) {
  x = ((unsigned int)x >> (n << 3)) & 0xff;
  return x;
  


}



/*
* copy_lsbit - set all bits of result value to the least significant bit of x
*  using only !, ~, &, |, ^, +, << and >>
* do not use any constant values of more than 1 byte in size
*  Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0 
*  Max # of operators: 5
*/
int copy_lsbit(int x) {
  x=x&1;
  x=!x;
  x=-x;
  return ~x;
}

/*
 * bit_count - returns the # of bits in x that are 1.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max # of operators: 40
 */
int bit_count(int x) {
  //int total= 0;
int m1  = 0x55555555;
int m2  = 0x33333333; 
int m4  = 0x0f0f0f0f;
int m8  = 0x00ff00ff;
int m16 = 0x0000ffff;
int m32 = 0xffffffff;
  /*
  total+=(x&1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  total+=((x>>=1) & 1);
  */
    x = (x & m1 ) + ((x >>  1) & m1 );
    x = (x & m2 ) + ((x >>  2) & m2 ); 
    x = (x & m4 ) + ((x >>  4) & m4 ); 
    x = (x & m8 ) + ((x >>  8) & m8 ); 
    x = (x & m16) + ((x >> 16) & m16);
    x = (x & m32) + ((x >> 31) & m32);
  
  return x;
}
