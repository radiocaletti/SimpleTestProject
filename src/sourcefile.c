#include "stdio.h"

int function_f(int);
void test_compare(u_int8_t* u, u_int8_t* v);

int function_f(int x){
    return x*x + 1;
}

u_int8_t bit_to_number(const char* const p) {
 if(NULL == p)
 {
    return 0;
 }
 const char* q = p;
 u_int8_t numberOut = 0u;
 u_int16_t powOf2 = 1u;
 for(u_int8_t t = 0u; t < 8; t++) {
    if(*q == '1') {
    numberOut += powOf2;
    }
    else if(*q != '0') {
        return 0;
    }
    powOf2 *= 2;
    q++;
 }
 return numberOut;
}

void test_method() {
  u_int8_t testNumber;
  u_int8_t testNumberExpect;

  const char* const bitcode = "11111111";
  testNumber = bit_to_number(bitcode);
  testNumberExpect = 255;
  test_compare(&testNumber, &testNumberExpect);
 
  const char* const bitcode2 = "00000000";
  testNumber = bit_to_number(bitcode2);
  testNumberExpect = 0;
  test_compare(&testNumber, &testNumberExpect);

  const char* const bitcode3 = "10000000";
  testNumber = bit_to_number(bitcode3);
  testNumberExpect = 1;
  test_compare(&testNumber, &testNumberExpect);

  const char* const bitcode4 = "01000000";
  testNumber = bit_to_number(bitcode4);
  testNumberExpect = 2;
  test_compare(&testNumber, &testNumberExpect);

  const char* const bitcode5 = NULL;
  testNumber = bit_to_number(bitcode5);
  testNumberExpect = 0;
  test_compare(&testNumber, &testNumberExpect);

  const char* const bitcode6 = "0101ABCDDEWD";
  testNumber = bit_to_number(bitcode6);
  testNumberExpect = 0;
  test_compare(&testNumber, &testNumberExpect);

  const char* const bitcode7 = "110";
  testNumber = bit_to_number(bitcode7);
  testNumberExpect = 0;
  test_compare(&testNumber, &testNumberExpect);

}

void test_compare(u_int8_t* u, u_int8_t* v)
{
    if(*u != *v)
    {
        printf("Error testcase.\n");
    }
    else{
        printf("Success.\n");
    }
}

int main(void){
    test_method();
    return 0;
}