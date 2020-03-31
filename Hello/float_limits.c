// float_limits.c - print the limits of floating point numbers on this system.
// compile with: gcc -o float_limits float_limits.c
//
#include <stdio.h>
#include <float.h> 
#include <math.h>
 
int main(void)
{
    printf("FLT_RADIX    = %d\n", FLT_RADIX);
    printf("DECIMAL_DIG  = %d\n", DECIMAL_DIG);
    printf("FLT_MIN      = %e\n", FLT_MIN);
    printf("FLT_MAX      = %e\n", FLT_MAX);
    printf("FLT_EPSILON  = %e\n", FLT_EPSILON);
    printf("FLT_DIG      = %d\n", FLT_DIG);
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    printf("FLT_MIN_EXP  = %d\n",  FLT_MIN_EXP);
    printf("FLT_MIN_10_EXP  = %d\n",  FLT_MIN_10_EXP);
    printf("FLT_MAX_EXP     = %d\n",  FLT_MAX_EXP);
    printf("FLT_MAX_10_EXP  = %d\n",  FLT_MAX_10_EXP);
    printf("FLT_ROUNDS      = %d\n",  FLT_ROUNDS);
    printf("FLT_EVAL_METHOD = %d\n",  FLT_EVAL_METHOD);
    printf("FLT_HAS_SUBNORM = %d\n",  FLT_HAS_SUBNORM);
    printf("\n");

    printf("DBL_MIN      = %e\n", DBL_MIN);
    printf("DBL_MAX      = %e\n", DBL_MAX);
    printf("DBL_EPSILON  = %e\n", DBL_EPSILON);
    printf("DBL_DIG      = %d\n", DBL_DIG);
    printf("DBL_MANT_DIG = %d\n", DBL_MANT_DIG);
    printf("DBL_MIN_EXP  = %d\n",  DBL_MIN_EXP);
    printf("DBL_MIN_10_EXP  = %d\n",  DBL_MIN_10_EXP);
    printf("DBL_MAX_EXP     = %d\n",  DBL_MAX_EXP);
    printf("DBL_MAX_10_EXP  = %d\n",  DBL_MAX_10_EXP);
    printf("DBL_HAS_SUBNORM = %d\n",  DBL_HAS_SUBNORM);
    printf("\n");

    printf("LDBL_MIN      = %Le\n", LDBL_MIN);
    printf("LDBL_MAX      = %Le\n", LDBL_MAX);
    printf("LDBL_EPSILON  = %Le\n", LDBL_EPSILON);
    printf("LDBL_DIG      = %d\n", LDBL_DIG);
    printf("LDBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
    printf("LDBL_MIN_EXP  = %d\n",  LDBL_MIN_EXP);
    printf("LDBL_MIN_10_EXP  = %d\n",  LDBL_MIN_10_EXP);
    printf("LDBL_MAX_EXP     = %d\n",  LDBL_MAX_EXP);
    printf("LDBL_MAX_10_EXP  = %d\n",  LDBL_MAX_10_EXP);
    printf("LDBL_HAS_SUBNORM = %d\n",  LDBL_HAS_SUBNORM);
    printf("\n");

}


