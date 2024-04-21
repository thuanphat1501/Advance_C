#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
const char *error_message;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, error_message) longjmp(buf, (x))

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

void readFile() {
    printf("Đọc file...\n");
    error_message = "Lỗi đọc file: File không tồn tại.";
    THROW(FILE_ERROR, error_message);
}

void networkOperation() {
    printf("Thao tác mạng...\n");
    error_message = "Lỗi kết nối.";
    THROW(NETWORK_ERROR, error_message);
}

void calculateData() {
    printf("Tính toán dữ liệu...\n");
    error_message = "Lỗi tính toán.";
    THROW(CALCULATION_ERROR, error_message);
}

int main() {

    TRY {
        //readFile();
        //networkOperation();
        //calculateData();
        printf("Không có lỗi xảy ra.\n");
    } CATCH(FILE_ERROR) {
        printf("FileError: %s\n", error_message);
    } CATCH(NETWORK_ERROR) {
        printf("NetworkError: %s\n", error_message);
    } CATCH(CALCULATION_ERROR) {
        printf("CalculationError: %s\n", error_message);
    }
    return 0;
}
