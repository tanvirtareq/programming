/// typedef vs #define
/// typedef is the actual definition of type whereas #define works using copy paste
/// typedef interpretation is performed by compiler  on the other hand #define is performed by preprocessor

#include<stdio.h>

#define df char*  /// df is defined as char type pointer

typedef char* td;

int main()
{
    td a, b, c;/// so a, b, c are chare type pointer

    df x, y, z;///df is replaced by char*.
    /// above line is replaced char* x, y, z.  there is a * before x. so only x is pointer .

    char* p, q,* r;/// p and r are pointer because * is before p and r, but there is no * before q so q is not pointer it is variable

    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(x));
    printf("%d\n", sizeof(y));
    printf("%d\n", sizeof(z));
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(q));
    printf("%d\n", sizeof(r));

    return 0;
}

