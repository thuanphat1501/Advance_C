#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
const char *info;
#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,info) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        info ="Divide by zero";
        THROW(1,info); // Mã lỗi 1 cho lỗi chia cho 0
    }
    if (b == 3) {
    info ="Different error";
    THROW(2,info);  // Mã lỗi 1 cho lỗi chia cho 3
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 3;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("ERROR: %s\n",info);
    }
    CATCH(2) {
        printf("ERROR: %s\n",info);
    }

    // Các xử lý khác của chương trình
    return 0;
}