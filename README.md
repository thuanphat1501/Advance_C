# Advance C 
<details><summary>LESSON 1: COMPILER AND MARCO</summary>
<p>
 
## LESSON 1: COMPILER AND MARCO
### Quá trình biên dịch
Quy trình biên dịch là quá trình chuyển đổi ngôn ngữ bậc cao  (C/C++, Pascal, Java,...) sang ngôn ngữ máy, để máy tính có thể hiểu và thực thi.
### Quá trình biên dịch gồm 4 giai đoạn
 >  - Giai đoàn tiền xử lý (Pre-processor)
 >  - Giai đoạn dịch ngôn ngữ bậc cao sang Asembly (Compiler)
 >  - Giai đoạn dịch Assembly sang ngôn ngữ máy (Assemblier)
 >  - Giai đoạn liên kết (Linker)
![Compiler_Marco (2)](https://github.com/DangTruongBT/advance-C/assets/103482832/62ae7186-a6a5-463e-8698-bd0b6aafef55)

#### *Pre-processor (Giai đoạn tiền xử lý):*
 - 1 Project được tạo ra từ nhiều file: `a.h, b.h, a.c, b.c` và file `main.c` sau quá trình tiền xử lý sẽ gọp tất cả các file thành 1 file duy nhất là file `main.i`.
 - Trong quá trình này sẽ chèn Header vào, triển khai Macro và xóa commment.
 - Lệnh trong CMD là: `gcc -E main.c -o main.i`.

#### **3 việc xảy ra trong quá trình tiền xử lý**
 - `include` file header, có nghĩa là nội dung file sẽ được chèn vào vị trí mà mình chỉ định.
 - Xóa bỏ ghi chú (không ảnh hưởng đến dung lượng bộ nhớ và tốc độ xử lý chương trình)
 - Triển khai macro:
     - `Marco` là từ dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý (Pre-processor). Chia làm 3 nhóm chính:
         - `#include`
         - `#define`, `#undef`
         - `#if`, `#elif`, `#ifdef`, `#ifndef`
     - `#define`
         - Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define.
         - Nơi nào có tên Macro sẽ được thay thế bằng nội dung của macro đó.
         - Giảm lặp lại mã, dễ bảo trì.
         - Ví dụ 1:
           ```c
           #include <stdio.h>

           // Định nghĩa hằng số Pi sử dụng #define
           #define PI 3.14
           int main() {
           // Sử dụng hằng số Pi trong chương trình
           double radius = 5.0;
           double area = PI * radius * radius;

           printf("Radius: %.2f\n", radius);
           printf("Area of the circle: %.2f\n", area);

           return 0;
           }

         - Ví dụ 2:
           ```c
           #include <stdio.h>

           // Định nghĩa macro để tìm số lớn hơn giữa hai số
           #define MAX(x, y) ((x) > (y) ? (x) : (y))

           int main() {
           int a = 10, b = 20;
    
           // Sử dụng macro để tìm số lớn hơn giữa a và b
           int maxNumber = MAX(a, b);

           printf("The bigger number between %d and %d is: %d\n", a, b, maxNumber);

           return 0;
           }
    - `#undef`
       - Chỉ thị `#undef` dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng `#define`
       - Nếu hai hoặc nhiều tệp tiêu đề có cùng tên macro, chúng có thể xung đột với nhau. Việc sử dụng các chỉ thị này giúp ngăn chặn các xung đột này.
       - Ví dụ:
         ```c
          #include <stdio.h>
          #include "nhietdo.c"
          #include "doam.c"
          // trong 2 file đều có macro lần lượt là:
          //#define cam_bien 10(nhietdo.c)
          //#define cam_bien 20(doam.c)

          int main(){
 	        #undef cam_bien
 	        #define cam_bien 40
         return 0;
         }
   - `#if`: Sử dụng để bắt đầu 1 điều kiện xử lý.Nếu đúng thì các dòng lệnh sau `#if` sẽ được biên dịch , sai sẽ bỏ qua đến khi gặp `#endif`.
   - `#elif`: Để thêm 1 ĐK mới khi #if hoặc `#elif` sai.
   - `#else`: Dùng khi không có ĐK nào đúng
   - `#ifdef`: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu định nghĩa rồi thì mã sau ifdef sẽ được biên dịch.
   - `#ifndef`: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu chưa định nghĩa thì mã sau `#ifndef` sẽ được biên dịch.Thường dùng để kiểm tra macro đó đã dc định nghĩa trong file nào chưa, kết thúc thì `#endif`
#### Mục đích tránh định nghĩa nhiều lần và xung đột
  - Ví dụ:
    ```c
    #ifndef __ABC_H
    #define __ABC_H

    int a = 10;

    #endif
 - Một số toán tử trong Marco:
   - Ví dụ
   
   ```c
   #include <stdio.h>

   #define STRINGIZE(x) #x
   #define DATA 40

   int main() {

    // Sử dụng toán tử #
    printf("The value is: %s\n", STRINGIZE(DATA));

    return 0;
   }
 - Variadic Marco: Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
    - Ví dụ

   ```c
   #include <stdio.h>

 	#define print_menu_item(...) \
 		do { \
 			const char *items[] = {__VA_ARGS__}; \
 			int n = sizeof(items) / sizeof(items[0]); \
 			for (int i = 0; i < n; i++) { \
 				print_menu_item(i + 1, items[i]); \
 			} \
 		} while (0)

 	#define case_option(number, function) \
 		case number: \
 			function(); \
 			break;

 	#define handle_option(option, ...) \
 		switch (option) { \
 			__VA_ARGS__ \
 			default: \
 				printf("Invalid option!\n"); \
 		}

 	void print_menu_item(int number, const char *item) {
 			printf("%d. %s\n", number, item);
 		}

 	void feature1() { printf("Feature 1 selected\n"); }
 	void feature2() { printf("Feature 2 selected\n"); }
 	void feature3() { printf("Feature 3 selected\n"); }
 	void feature4() { printf("Feature 4 selected\n"); }

 	int main() {
 		print_menu_item("Option 1", "Option 2", "Option 3", "Option 4", "Exit");

 		int option;
 		scanf("%d", &option);

 		handle_option(option,
 					case_option(1, feature1)
 					case_option(2, feature2)
 					case_option(3, feature3)
 					case_option(4, feature4)
 		)

 		return 0;
- Compiler (Giai đoạn dịch ngôn ngữ bậc cao sang ngôn ngữ Assembly):
   - Quá trình này compiler sẽ biên dịch từ file `.i `sang file ngôn ngữ assembly là file `.s`
   - Dùng lệnh `gcc -S main.i -o main.s`
- Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy): compiler sẽ Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o`
   - Dùng lệnh `gcc -c main.s -o main.o` để tạo ra file `.o`
- Linker (Giải đoạn liên kết):
   - 1 hoặc nhiều file.o sẽ được compiler liên kết lại 1 File `.exe`.
   - File này để hệ điều hành chạy
   - Dùng lệnh gcc  `main.o -o filename` để tạo ra tệp thực thi .
</p>
</details>

<details><summary>LESSON 2: STDARG AND ASSERT</summary>
<p>

## LESSON 2: STDARG AND ASSERT
### THƯ VIỆN STDARG
 - Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.
 - Các hàm như printf và scanf là ví dụ điển hình
 - va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
 - va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
 - va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
 - va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.
 ```c
 #include <stdio.h>
 #include <stdarg.h>
 
 typedef enum {
     TEMPERATURE_SENSOR,
     PRESSURE_SENSOR
 } SensorType;
 
 void processSensorData(SensorType type, ...) {
     va_list args;
     va_start(args, type);
 
     switch (type) {
         case TEMPERATURE_SENSOR: {
             int numArgs = va_arg(args, int);
             int sensorId = va_arg(args, int);
             float temperature = va_arg(args, double); // float được promote thành double
             printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
             if (numArgs > 2) {
                 // Xử lý thêm tham số nếu có
                 char* additionalInfo = va_arg(args, char*);
                 printf("Additional Info: %s\n", additionalInfo);
             }
             break;
         }
         case PRESSURE_SENSOR: {
             int numArgs = va_arg(args, int);
             int sensorId = va_arg(args, int);
             int pressure = va_arg(args, int);
             printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
             if (numArgs > 2) {
                 // Xử lý thêm tham số nếu có
                 char* unit = va_arg(args, char*);
                 printf("Unit: %s\n", unit);
             }
             break;
         }
     }
 
     va_end(args);
 }
 
 int main() {
     processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
     processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
     return 0;
 }
 ```
### THƯ VIỆN ASSERT
 - Cung cấp macro assert. 
 - Macro này được sử dụng để kiểm tra một điều kiện. 
 - Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
 - Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
 - Dùng trong debug, dùng #define NDEBUG để tắt debug.
 - Điều kiện đúng
 ```c
 #include <stdio.h>
 #include <assert.h>
 
 int main() {
     int x = 5;
 
     assert(x == 5);
 
     // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
     printf("X is: %d", x);
     
     return 0;
 } // OUTPUT : X is 5
 ```
### LỖI THƯỜNG GẶP
 - Lỗi truy cập mảng không an toàn.
 - Lỗi chia cho số 0.
 - Chia số nguyên cho số nguyên, kết quả là số thực.
### EXAMPLE
```c
#include <assert.h>
#include <stdint.h>

#define ASSERT_SIZE(type, size) assert(sizeof(type) == (size))

void checkTypeSizes() {
    ASSERT_SIZE(uint32_t, 4);
    ASSERT_SIZE(uint16_t, 2);
    // Kiểm tra các kích thước kiểu dữ liệu khác
}
```
```c
#include <assert.h>

#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 10);
    // Thiết lập cấp độ
}
```
</p>
</details>

<details><summary>LESSON 3: POINTER</summary>
<p>
 Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
- Cách khai báo
 
```c
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float
```
- Lấy địa chỉ của một biến và truy cập giá trị
```c
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
int y = *ptr_x;  // y sẽ bằng giá trị của x
```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.

```c
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));
    return 0;
}
```
### EXAMPLE
```c
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}
```
### VOID POINTER
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
- Cú pháp:
 ```c
 void *ptr_void;
 ```
- Ví dụ:
```c
include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}

```
### FUNCTION POINTER 
- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
- Ví dụ:
```c
#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)     
        for (j = i+1; j < n; j++) 
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```
### POINTER TO CONSTANT
Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
- Cú pháp:
```c
int const *ptr_const; 
const int *ptr_const;
```
### CONSTANT POINTER
Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
- Cú pháp:
```c
int *const const_ptr = &value;
```
### POINTER TO POINTER
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
- Ví dụ:
```c
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);

    return 0;
}
```
- Ứng dụng:
> - Kiểu json
> - Cấu trúc List
###   NULL POINTER
Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
- Ví dụ :
```c
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    

    return 0;
}
```
</p>
</details>

<details><summary>LESSON 4: MEMORY LAYOUT</summary>
<p>
Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.
 
 ![1](https://github.com/thuanphat1501/Advance_C/assets/130131756/18af5e84-3cca-4908-a84a-6465eeba6311)
### TEXT SEGMENT
- Mã máy:
    - Chứa tập hợp các lệnh thực thi.
    - Quyền truy cập: Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. 
    - Lưu hằng số, con trỏ kiểu char
    - Tất cả các biến lưu ở phần vùng Text đều không thể thay đổi giá trị mà chỉ được đọc.
 
![2](https://github.com/thuanphat1501/Advance_C/assets/130131756/2784ede6-c4b8-488e-b1b5-4a6ef6363f0d)

- Ví dụ:
```c
#include <stdio.h>

const int a = 10;
char arr[] = "Hello";
char *arr1 = "Hello";

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

    arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}
```
### DATA SEGMENT
- Initialized Data Segment (Dữ liệu Đã Khởi Tạo):
   - Chứa các biến toàn cục được khởi tạo với giá trị khác 0.
   - Chứa các biến static được khởi tạo với giá trị khác 0.
   - Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến .
   - Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
 
 ![image](https://github.com/DangTruongBT/advance-C/assets/103482832/c69d18eb-fb00-4a57-8552-9197b5319cbe)

- Ví dụ:
```c
#include <stdio.h>

int a = 10;
double d = 20.5;

static int var = 5;

void test()
{
    static int local = 10;
}

int main(int argc, char const *argv[])
{  
    a = 15;
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);

    return 0;
}
```
### BSS SEGMENT
- Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):
  - Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.
  - Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.
  - Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến .
  - Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
 
![image](https://github.com/DangTruongBT/advance-C/assets/103482832/6780304c-be05-46b1-856b-1f7bdc680a95)

- Ví dụ:
```c
#include <stdio.h>
typedef struct 
{
    int x;
    int y;
} Point_Data;

int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {5,7};

void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    printf("a: %d\n", a);
    printf("global: %d\n", global);

    return 0;
}
```
### STACK
- Chứa các biến cục bộ, tham số truyền vào.
- Quyền truy cập: đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
- Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.

![Capture](https://github.com/thuanphat1501/Advance_C/assets/130131756/6716f027-36ec-47b0-a9cd-041cf90c010a)

- Ví dụ:
```c
#include <stdio.h>

void test()
{
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b)
{
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}

int main() {

    sum(3,5);
    /*
        0x01
        0x02
        0x03
    */
   test();
   /*
    int test = 0; // 0x01
   */    
    return 0;
}
```
### HEAP
Cấp phát động:
- Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
- Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
- Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.

![1](https://github.com/thuanphat1501/Advance_C/assets/130131756/13882a91-5d77-48ca-8361-8ad297058a9b)
malloc():
- Tham số truyền vào: kích thước mong muốn ( byte)
- Giá trị trả về: con trỏ void
- Ví dụ:
```c
#include <stdlib.h>

int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // ...

    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
```
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;

    char* ten = (char*) malloc(sizeof(char) * soluongkytu);

    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);

        printf("Hello %s\n", ten);
    }
   
    return 0;
}
```
Quyền truy cập: có quyền đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
### STACK VÀ HEAP
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
```c
#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int array[3];
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
}

void test2()
{
    int *array = (int*)malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("address of array[%d]: %p\n", i, (array+i));
    }
    printf("----------------------\n");
    //free(array);
}

int main(int argc, char const *argv[])
{  
    test1();
    test1();
    test2();
    test2();

    return 0;
}
```
Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
```c
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
}
```
Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
```c
int *A = (int *)malloc(18446744073709551615);
```
</p>
</details>

<details><summary>LESSON 5: Extern - Static - Volatile - Register</summary>
<p>

### EXTERN
 Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
 
### STATIC
 Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
#### Static local variables
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
 
```c
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```
#### Static global variables
Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
Ứng dụng: dùng để thiết kế các file thư viện.
#### Static trong class
Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.

```c
#include <iostream>

typedef enum
{
    red = 0,
    blue,
    green,
    purple,
    black,
    yellow
} Pen_Color;

void print_color_pen(Pen_Color color)
{
    switch (color)
    {
    case red:
        std::cout << "Red\n";
        break;
    case blue:
        std::cout << "Blue\n";
        break;
    case green:
        std::cout << "Green\n";
        break;
    
    default:
        break;
    }
}


class PEN
{
public:
    Pen_Color pen_color;
    static int pen_length;

    PEN(Pen_Color color);
    Pen_Color get_color()
    {
        return pen_color;
    }
    void set_length(int length)
    {
        pen_length = length;
    }
};

int PEN::pen_length;

PEN::PEN(Pen_Color color)
{
    pen_color = color;
    pen_length = 10;
}


int main(int argc, char const *argv[])
{
    PEN blue_pen(blue);
    PEN red_pen(red);
    PEN green_pen(green);

    blue_pen.set_length(9);

    std::cout << "Color: ";
    print_color_pen(blue_pen.get_color());
    std::cout << "Length: " << blue_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(red_pen.get_color());
    std::cout << "Length: " << red_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(green_pen.get_color());
    std::cout << "Length: " << green_pen.pen_length << '\n';

    return 0;
}
```

### VOLATILE
Trong lập trình nhúng (Embedded System), ta rất thường hay gặp khai báo biến với từ khóa volatile. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.

Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua nguồn source code. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

```c
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}
```
### REGISTER

Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.
![R](https://github.com/thuanphat1501/Advance_C/assets/130131756/04ac1b4b-fcef-4bb7-8e79-6af638da5055)
</p>
</details>

<details><summary>LESSON 6: Goto - setjmp.h</summary>
<p>

### GOTO
goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm. Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.

```c
#include <stdio.h>

int main() {
    int i = 0;

    // Đặt nhãn
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");

    return 0;
}
```
### SETJMP
Header file có tên setjmp.h trong Thư viện C định nghĩa macro setjmp(), một hàm longjmp(), và một kiểu biến jmp_buf, để bỏ qua lời gọi hàm thông thường và trả về qui tắc, bằng cách cung cấp các phương thức để thực hiện các cú nhảy mà vẫn duy trì môi trường gọi hàm.

Biến được định nghĩa trong setjmp.h

Dưới đây là kiểu biến được định nghĩa trong setjmp.h:

jmp_buf: Đây là một kiểu mảng được sử dụng để giữ thông tin cho macro setjmp() và hàm longjmp().

Các macro được định nghĩa trong setjmp.h

Chỉ có một macro được định nghĩa trong thư viện này:

int setjmp(jmp_buf environment): Macro này lưu trữ môi trường (environment) hiện tại bên trong biến environment để sử dụng sau bởi hàm longjmp(). Nếu macro này trả về một cách trực tiếp từ lời gọi macro, thì nó trả về 0; nhưng nếu nó trả về từ một lời gọi hàm longjmp(), thì một giá trị khác 0 được trả về.

#### Khai báo Macro setjmp() trong C

```c
int setjmp(jmp_buf environment)
```
- Tham số

```c
int setjmp(jmp_buf environment)
```
- Trả về giá trị
  Macro này trả về nhiều hơn 1 lần. Đầu tiên, trên lời gọi trực tiếp của nó, nó luôn luôn trả về 0. Khi longjmp được gọi với thông tin được thiết lập tới environment, macro này lại trả về lần nữa; lúc này nó trả về giá trị đã được truyền tới longjmp như là tham số thứ hai.
### Các hàm được định nghĩa trong setjmp.h
Chỉ có một hàm được định nghĩa trong setjmp.h:

Hàm void longjmp(jmp_buf environment, int value): Hàm này phục hồi môi trường (environment) đã được lưu trữ bởi lời gọi gần nhất tới macro setjmp() trong cùng lời gọi hàm của chương trình với tham số tương ứng là jmp_buf.
#### Khai báo hàm longjmp() trong C

```c
void longjmp(jmp_buf environment, int value)
```
- Tham số
  - environment − Đây là đối tượng của kiểu jmp_buf chứa thông tin để lưu trữ môi trường tại điểm gọi của setjmp.
  - value − Đây là giá trị để biểu thức setjmp ước lượng.
- Giá trị trả về
  - Hàm này không trả về bất cứ giá trị nào.
</p>
</details>

<details><summary>LESSON 7: BITMASK</summary>
<p>
	
- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.

### NOT bitwise
Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.

```c
int result = ~num ;
```
### AND bitwise
Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.

```c
int result = num1 & num2;
```
### OR bitwise
Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1.

```c
int result = num1 | num2;
```
### XOR bitwise
Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1.

```c
int result = num1 ^ num2;
```
### Shift left và Shift right bitwise
Dùng để di chuyển bit sang trái hoặc sang phải.
- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

```c
int resultLeftShift = num << shiftAmount;
int resultRightShift = num >> shiftAmount;
```
### Ví dụ

```c
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;
void displayAllStatusLed(LEDStatus status) {
 	uint8_t* statusPtr = (uint8_t*)&status;
		for (int j = 0; j < 8; j++) {
		printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
}

}


int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;
    displayAllStatusLed(ledStatus);
	
    return 0;
}
```
</p>
</details>

<details><summary>LESSON 8: STRUCT - UNION</summary>
<p>

### STRUCT

Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.

```c
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```
![st1](https://github.com/thuanphat1501/Advance_C/assets/130131756/3b7bc7f8-124a-49e4-a866-da04f52a2e00)

#### Kích thước của Struct

```c
struct Example {
    uint8_t a;    
    uint16_t b;
    uint32_t c;    
};
```

### UNION
Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.
 ```c
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```
```c
union Data {
    uint8_t a;
    uint16_t b;
    uint32_t c;
};
```

#### Kích thước của Union
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/4e778b75-7708-4f08-bed4-8e2930e8a404)

#### Ứng dụng kết hợp struct và union
```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;


int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

		Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    
    return 0;
}
```

</p>
</details>

<details><summary>LESSON 9: JSON</summary>
<p>

- JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
- JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.
- Bắt đầu chuỗi JSON là dấu " kết thúc là dấu "

### Cú pháp dựa trên cặp key-value

```c
char *json = “ 
{ 
  "name": "John Doe",
  "age": 30,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}

“
```
"name": là key

"John Doe": là 1 value

1 Object JSON mở đầu bằng "{" kết thúc bằng "}"

### Các định dạng 
```c
typedef enum {
            JSON_NULL,
            JSON_BOOLEAN,
            JSON_NUMBER,
            JSON_STRING,
            JSON_ARRAY,
            JSON_OBJECT,
    }JsonType
```
Các cặp key-value ngăn cách nhau bằng dấu ","

### JSON Values
- Chuỗi (String): chuỗi ký tự Unicode được bao quanh bởi dấu ngoặc kép. Ví dụ:
  ```
  "Hello, World!", "123", "true"
  ```
- Số (Number): JSON hỗ trợ cả số nguyên và số thực. Các số có thể được biểu diễn với hoặc không có dấu thập phân và/hoặc mũ. Ví dụ:
  ```
  123, 3.14, -42, 1.5e10
  ```
- Boolean: Được biểu diễn bởi từ khóa true hoặc false.
- Mảng (Array): Một danh sách các giá trị, được bao quanh bởi dấu ngoặc vuông và các giá trị được phân tách bằng dấu phẩy. Mỗi phần tử trong mảng có thể là bất kỳ kiểu dữ liệu JSON nào. Ví dụ:
  ```
  [1, 2, 3, "apple", true]
  ```
- Đối tượng (Object): Một tập hợp các cặp key-value, được bao quanh bởi dấu ngoặc nhọn. Mỗi cặp key-value được phân tách bằng dấu phẩy. Key là một chuỗi và phải được bao quanh bởi dấu ngoặc kép, sau đó là dấu hai chấm, và sau đó là giá trị. Ví dụ:
  ```
  {"name": "John", "age": 30, "isStudent": true}
  ```
- Null: Được biểu diễn bởi từ khóa null, đại diện cho một giá trị không tồn tại hoặc không xác định.
Lưu ý: Key bắt buộc phải là String còn value có thể là string, number, boolean,...
</p>
</details>


<details><summary>LESSON 10: LINKER LIST</summary>
<p>
	
Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.

### Danh sách liên kết là gì?
Danh sách liên kết (Linker List): là một cấu trúc dữ liệu được sử dụng để lưu trữ các phần tử tương tự như mảng nhưng cớ nhiều điểm khác biệt
Có các loại danh sách liên kết:
- Danh sách liên kết đơn
- Danh sách liên kết đôi
- Danh sách liên kết vòng
### Tính chất
- Danh sách liên kết có thể mở rộng và thu hẹp một cách linh hoạt
- Phần tử cuối cùng trong DSLK trỏ vào NULL (con trỏ NULL)
- Đây kà kiểu cấu trúc dữ liệu kiểu cấp phát động có nghĩa là còn bộ nhớ thì còn cấp phát được, cấp phát đến khi nào hết bộ nhớ thì thôi - Vùng nhớ cấp phát : Heap
- Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ.
  ![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/0ccd237b-cb25-4835-b89a-73abd2810cc7)
Để quản lí danh sách liên kết cần 1 con trỏ Head

Ví dụ:
Phần link của node 1 sẽ lưu địa chỉ node 2 là 6, tương tự với các node tiếp theo cho đến node cuối cùng link địa chỉ NULL
```
- Phần data lưu giá trị node
```
```
- Phần link lưu địa chỉ của node kế tiếp.
```
#### Ưu điểm
- Có thể mở rộng với độ phức tạp
- Dễ mở rộng và thu hẹp kích thước
- Có thể cấp phát số lượng lớn các node tùy vào bộ nhớ
#### Nhược điểm
- Khó khăn trong việc truy cập 1 phần tử ở vị trí bất kì 
- Khó khăn trong việc cài đặt
- Tốn thêm bộ nhớ cho phần tham chiếu bổ sung

### Cấu trúc một node của LINKER LIST
```c
             struct node {
             int data;
             struct node* next; //link
         };
```
#### Giải thích ý nghĩa của cấu trúc node

- Node ở dây có phần tử dữ liệu là một số nguyên lưu ở data, ngoài ra nó còn có 1 phần con trỏ trỏ tới chính struct node. Phần này chính là địa chỉ của node tiếp theo của nó trong DSLK.
- Như vậy mỗi node sẽ có dữ liệu của nó và có địa chỉ của node tiếp sau nó. Đối với con trỏ cuối cùng trong DSLK thì phần địa chỉ này sẽ là con trỏ NULL.

##### Mỗi node trong DSLK đều được cấp phát động

</p>
</details>

<details><summary>LESSON 11: STACK AND QUEUE</summary>
<p>

# 1. STACK
### Định nghĩa:

- Một ngăn xếp là một cấu trúc dữ liệu trừu tượng (Abstract Data Type – viết tắt là ADT), hầu như được sử dụng trong hầu hết mọi ngôn ngữ lập trình. Đặt tên là ngăn xếp bởi vì nó hoạt động như một ngăn xếp trong đời sống thực, ví dụ như một cỗ bài hay một chồng đĩa, …

- Trong đời sống thực, ngăn xếp chỉ cho phép các hoạt động tại vị trí trên cùng của ngăn xếp. Ví dụ, chúng ta chỉ có thể đặt hoặc thêm một lá bài hay một cái đĩa vào trên cùng của ngăn xếp. Do đó, cấu trúc dữ liệu trừu tượng ngăn xếp chỉ cho phép các thao tác dữ liệu tại vị trí trên cùng. Tại bất cứ thời điểm nào, chúng ta chỉ có thể truy cập phần tử trên cùng của ngăn xếp.

- Đặc điểm này làm cho ngăn xếp trở thành cấu trúc dữ liệu dạng `LIFO`. `LIFO` là viết tắt của `Last-In-First-Out`. Ở đây, phần tử được đặt vào (được chèn, được thêm vào) cuối cùng sẽ được truy cập đầu tiên. Trong thuật ngữ ngăn xếp, hoạt động chèn được gọi là hoạt động `PUSH` và hoạt động xóa được gọi là hoạt động `POP`.

- Một ngăn xếp có thể được triển khai theo phương thức của Mảng (Array), Cấu trúc (Struct), Con trỏ (Pointer) và Danh sách liên kết (Linked List). Ngăn xếp có thể là ở dạng kích cỡ cố định hoặc ngăn xếp có thể thay đổi kích cỡ.

### Các hoạt động cơ bản trên cấu trúc dữ liệu ngăn xếp

- Push(): Đẩy 1 phần tử dữ liệu vào trong ngăn xếp

- Pop(): Lấy 1 phần tử dữ liệu ra khỏi ngăn xếp

- Top(): Lấy 1 phần tử trên cùng của ngăng xếp.

- Is_Full(): Kiểm tra xem ngăn xếp đã đầy chưa

- Is_Empty(): Kiểm tra xem ngăn xếp có trống hay không.

### Định nghĩa một Stack

```c
typedef struct Stack {
    int* items; // mảng chứa các giá trị trong ngăn xếp
    int size;   // kích thước của mảng đó
    int top;   // giá trị của phần tử trên cùng
} Stack;
```
### Hoạt động khởi tạo một ngăn xếp

```c
void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size); //cấp phát động 1 mảng chứa các giá trị
    stack->size = size; // truyền vào kích thước mong muốn
    stack->top = -1; // gắn giá trị trên cùng bằng -1
}
```

### Hoạt động Is_Full() trong cấu trúc dữ liệu ngăn xếp
```c
int Is_Full( Stack stack) {
    return stack.top == stack.size - 1;
}
```

### Hoạt động Is_Empty() trong cấu trúc dữ liệu ngăn xếp
```c
int Is_Empty( Stack stack) {
    return stack.top == - 1;
}
```

### Hoạt động Push() trong cấu trúc dữ liệu ngăn xếp
```c
void Push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}
```

### Hoạt động Pop() trong cấu trúc dữ liệu ngăn xếp
```c
int Pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}
```

### Hoạt động Top() trong cấu trúc dữ liệu ngăn xếp
```c
int Top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
```
# Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty( Stack stack) {
    return stack.top == -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}
```

# 2. QUEUE
### Định nghĩa:

- Hàng đợi (Queue) là một cấu trúc dữ liệu trừu tượng, là một cái gì đó tương tự như hàng đợi trong đời sống hàng ngày (xếp hàng).
- Khác với ngăn xếp, hàng đợi là mở ở cả hai đầu. Một đầu luôn luôn được sử dụng để chèn dữ liệu vào (hay còn gọi là sắp vào hàng) và đầu kia được sử dụng để xóa dữ liệu (rời hàng). Cấu trúc dữ liệu hàng đợi tuân theo phương pháp First-In-First-Out, tức là dữ liệu được nhập vào đầu tiên sẽ được truy cập đầu tiên.
- Trong đời sống thực chúng ta có rất nhiều ví dụ về hàng đợi, chẳng hạn như hàng xe ô tô trên đường một chiều (đặc biệt là khi tắc xe), trong đó xe nào vào đầu tiên sẽ thoát ra đầu tiên. Một vài ví dụ khác là xếp hàng học sinh, xếp hàng mua vé, …
- Tương tự như cấu trúc dữ liệu ngăn xếp, thì cấu trúc dữ liệu hàng đợi cũng có thể được triển khai bởi sử dụng Mảng (Array), Danh sách liên kết (Linked List), Con trỏ (Pointer) và Cấu trúc (Struct).

### Các hoạt động cơ bản trên cấu trúc dữ liệu hàng đợi:

- enqueue(): Thêm 1 phần tử dữ liệu vào trong hàng đợi

- dequeue(): Xóa 1 phần tử từ hàng đợi

- Front(): lấy phần tử ở đầu hàng đợi, mà không xóa phần tử này.

- Is_Full(): Kiểm tra xem hàng đợi đã đầy chưa

- Is_Empty(): Kiểm tra xem hàng đợi có trống hay không.
### Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));

    return 0;
}
```
</p>
</details>

<details><summary>LESSON 12: BINARY SEARCH</summary>
<p>

# BINARY SEARCH
- Trong khoa học máy tính, tìm kiếm nhị phân (tiếng Anh: binary search), còn gọi là tìm kiếm nửa khoảng, tìm kiếm logarit, hay chặt nhị phân, là một thuật toán tìm kiếm xác định vị trí của một giá trị cần tìm trong một mảng đã được sắp xếp.
- Thuật toán này hoạt động bằng cách chia không gian tìm kiếm thành hai phần bằng cách so sánh giá trị cần tìm với giá trị ở giữa mảng. Dựa vào kết quả so sánh, thuật toán tiếp tục tìm kiếm trong nửa phía bên trái hoặc bên phải của mảng.

# FILE OPERATIONS
- Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file. 
- File CSV (Comma-Separated Values) là một loại file văn bản được sử dụng để lưu trữ và truyền tải dữ liệu có cấu trúc dưới dạng bảng, trong đó các dữ liệu của các cột được phân tách bằng dấu phẩy (,) hoặc một ký tự ngăn cách khác.

```c
FILE *file = fopen(const char *file_name, const char *access_mode);

```
### Các chế độ để sử dụng:
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/305e36be-878d-448f-9b5c-77eb8ac00f4f)
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/18f16c99-7418-4c42-ba07-e947bd0172c8)
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/b2f1b6ac-5ac3-4a20-9af7-1c4c76b7f8c4)
### Các hàm sử dụng:
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/b0ab24e2-4a50-4faf-8381-454e56bb2427)
![image](https://github.com/thuanphat1501/Advance_C/assets/130131756/02d8586b-56d1-4e1f-b49c-4a658a7e879a)

</p>
</details>

<details><summary>LESSON 13: CLASS</summary>
<p>

# CLASS
	
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 

```c
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...

protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa

public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...

};

```
### Constructor
Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.

```c
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};
```
```c
int main()
{
    HinhChuNhat hinh1;


    std::cout << "Chieu dai: " << hinh1.chieuDai << '\n';


    return 0;
}
```

### Destructor
Destructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự `~`ở phía trước tên.

```c
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }
    ~HinhChuNhat(){
        std::cout << "Destructor " << '\n';
    }


    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};
```

### Static keyword
Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
```c
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    
    static int var;
};

int HinhChuNhat::var;

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    cout << "address of var: " << &hinh1.var << '\n'; 
    cout << "address of var: " << &hinh2.var << '\n'; 
    cout << "address of var: " << &hinh3.var << '\n'; 


    return 0;
}
```
#### Khi một method trong class được khai báo với từ khóa static:
- Method này độc lập với bất kỳ đối tượng nào của lớp.
- Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
- Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử `::` .
- Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
- Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.
```c
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;
    double chieuRong;
    static int count;

    HinhChuNhat(int dai = 5, int rong = 4);
    ~HinhChuNhat();

    double tinhDienTich();
    static void display();
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
    chieuDai = dai;
    chieuRong = rong;
    count++;
}

HinhChuNhat::~HinhChuNhat()
{
    cout << "Destructor" << endl;
}

void HinhChuNhat::display()
{
    cout << "Number of object: " << count << endl;
}

int HinhChuNhat::count = 0;



int main()
{ 
    HinhChuNhat::display();

    return 0;
}
```
### Binary search
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Node {
    int data;
    struct Node *next;
} Node;

//them node va sap xep tu be den lon
void add_node(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head; // current = 0xb3
    while (current->next != NULL && current->next->data < value) {
        current = current->next; // current = 0xa2
    }

    new_node->next = current->next;
    current->next = new_node;
}

typedef struct CenterPoint {
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

//tim diem giua phia ben trai va ben phai su dung de quy
CenterPoint *buildTree(Node *head, int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    root->value = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

//tim diem giua
CenterPoint *centerPoint(Node *head) {
    int length = 0;
    Node *node = head;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

//ham tim kiem nhi phan
CenterPoint *binarySearch(CenterPoint *root, int value) {
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop);
    if (root == NULL) {
        return NULL;
    }

    if (root->value == value) {
        return root;
    }

    if (value < root->value) {
        return binarySearch(root->left, value);
    } else {
        return binarySearch(root->right, value);
    }
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

//tao ngau nhien 10000 node
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }

    //add_node(&head, 5639);

    print_list(head);

    CenterPoint *ptr = centerPoint(head);

    int value = 5639;
    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL) {
        printf("Tim thay %d\n", result->value);
    } else {
        printf("Khong tim thay\n");
    }

    return 0;
}
```
</p>
</details>

<details><summary>LESSON 14: OOP</summary>
<p>

# Encapsulation
Tính đóng gói ( Encapsulation) là ẩn đi các property “ mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private ( tức là không thể truy cập trực tiếp tới các property này). Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta cung cấp các method ở quyền truy cập public.
```c
#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        string Name;
        double GPA;
        int StudentID;
    public:
    Student(string name);

    string getName()
    {
        return Name;
    }

    void setGPA(double gpa)
    {
        GPA = gpa;
    }
    double getGPA()
    {
        return GPA;
    }

    int getID()
    {
        return StudentID;
    }

};

Student::Student(string name)
{
    Name = name;
    static int id = 1000;
    StudentID = id;
    ++id;
}

int main()
{
    Student student1("Trung");
    Student student2("Thai");
    Student student3("Thao");

    cout << "ID: " << student1.getID() << endl;
    cout << "Name: " << student1.getName() << endl;

    cout << "ID: " << student2.getID() << endl;
    cout << "Name: " << student2.getName() << endl;

    cout << "ID: " << student3.getID() << endl;
    cout << "Name: " << student3.getName() << endl;



    return 0;
}

```
# Inheritance
- Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác. Ta chia chúng làm 2 loại là class cha và class con. Để kế thừa từ class khác, ta dùng ký tự `: `.
- Tất cả những property và method có quyền truy cập là public và protected ở class cha sẽ được class con kế thừa.
- Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.
```c
#include <iostream>
#include <string>


using namespace std;

class Person
{
protected:
  string Name;
  int Age;
  string Home_Address;

public:
  string getName()
  {
    return Name;
  }
  void setName(string name)
  {
    Name = name;
  }

  int getAge()
  {
    return Age;
  }
  void setAge(int age)
  {
    Age = age;
  }

  string getAddress()
  {
    return Home_Address;
  }
  void setAddress(string address)
  {
    Home_Address = address;
  }

  void displayInfo()
  {
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Address: " << Home_Address << endl;
  }
  
};


class Student : public Person
{
private:
  string School_Name;
  double GPA;
  int StudentID;

public:
  Student()
  {
    static int id = 1000;
    StudentID = id;
    id++;
  }

  string getSchoolName()
  {
    return School_Name;
  }
  void setSchoolName(string school_name)
  {
    School_Name = school_name;
  }

  double getGPA()
  {
    return GPA;
  }
  void setGPA(double gpa)
  {
    GPA = gpa;
  }

  int getID()
  {
    return StudentID;
  }

  void displayInfo() // overriding
  {
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Address: " << Home_Address << endl;
    cout << "School name: " << School_Name << endl;
    cout << "GPA: " << GPA << endl;
  }

};

int main()
{
  Person person1;
  person1.setName("Trung");
  person1.setAge(20);
  person1.setAddress("HCM");
  person1.displayInfo();

  cout << "-----------------------" << endl;
  
  Student student1;

  student1.setName("Trungg");
  student1.setAge(24);
  student1.setAddress("HCMM");
  student1.setGPA(8.1);
  student1.setSchoolName("DinhTienHoang");
  student1.displayInfo();

  return 0;
}
```
# Polymorphism
- Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.
- Tính đa hình là cách dùng những method được kế thừa để thực hiện các tác vụ khác nhau. Điều này giúp chúng ta thể hiện 1 hành động theo nhiều cách khác nhau. ( Function overriding)
- Function overloading cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.
```c
#include <iostream>
#include <string>


using namespace std;

class Person
{
protected:
  string Name;
  int Age;
  string Home_Address;

public:
  virtual string test()
  {
    return "Hello person";
  }

  void displayInfo()
  {
    cout << test() << endl;
  }
  
};


class Student : public Person
{
private:
  string School_Name;
  double GPA;
  int StudentID;

public:
  string test()
  {
    return "Hello student";
  }

};

int main()
{
  Person person1;
  person1.displayInfo();
  

  cout << "-----------------------" << endl;
  
  Student student1;
  student1.displayInfo();

  

  return 0;
}
```
```c
#include <iostream>
#include <string>

using namespace std;


int sum(int a, int b)
{
    return a+b;
}
int sum(int a, int b, int c)
{
    return a+b+c;
}
double sum(double a, double b)
{
    return a+b;
}

```
# Abstraction
Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.
```c
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GiaiPhuongTrinh
{
    private:
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;
        void tinhNghiem()
        {
            delta = b*b - 4*a*c;
            if (delta < 0)
            {
                delta = -1;
            }
            else if (delta == 0)
            {
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0)
            {
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
    public:

        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();

};

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c)
{
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult()
{
    tinhNghiem();
    if (delta == -1)
    {
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0)
    {
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0)
    {
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
}

int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();

  return 0;
}

```
</p>
</details>

<details><summary>LESSON 15: Standard template library</summary>
<p>

Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.
- Một số thành phần chính của STL:
> - Container
> - Iterator
> - Algorithms
> - Functor

## Container
Một container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể. STL (Standard Template Library) cung cấp một số container tiêu biểu giúp lưu trữ và quản lý dữ liệu. 
Ví dụ:
- Vector
- List
- Map
- Array

### Vector
- Vector là một trong những container quan trọng nhất trong STL của C++. Nó cung cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt. 
- Một số đặc điểm chính của vector:
	 - Vector là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.
 	 - Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
	 - Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.
- Một số method của vector:
	 - at(): Truy cập vào phần tử của vector
	 - size(): Trả về kích thước của vector
	 - resize(): Thay đổi kích thước của vector
	 - begin(): Địa chỉ của phần tử đầu tiên của vector
	 - end(): Địa chỉ của phần tử cuối cùng của vector
	 - push_back(): Thêm phần tử vào vị trí cuối của vector
Ví dụ:
```c
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};

    arr1.at(0) = 3;
    arr1.resize(7);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    arr1.push_back(10);
    cout << "-----------" << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    return 0;
}

```
### List
- List là một container trong STL của C++, triển khai dưới dạng danh sách liên kết hai chiều. 
- Một số đặc điểm chính của list:
	 - Truy cập tuần tự: Truy cập các phần tử của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
	 - Hiệu suất chèn và xóa: Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm/xóa ở giữa danh sách.
- Một số method của list:
	 - push_back():
	 - pop_back():
	 - insert(): Chèn một node vào list
	 - erase(): Xóa một node của list
	 - size(): Trả về kích thước của list
Ví dụ:
```c
#include <iostream>
#include <list>

using namespace std;

int main()
{
  
    list <int> arr1 = {2,5,7,4,9};

    list <int> :: iterator it;

    int i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 2)
        {
            arr1.insert(it,10);
            break;
        }
        i++;
    }

    i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 4)
        {
            arr1.erase(it);
            break;
        }
        i++;
    }

    for (auto const var : arr1)
    {
        cout << "Value: " << var << endl;
    }
    return 0;
}

```
#### Lưu ý:
- Sử dụng vector khi:
	- Cần truy cập ngẫu nhiên đến các phần tử.
	- Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	- Dung lượng có thể biết trước hoặc thay đổi ít.
- Sử dụng list khi:
	- Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	- Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.
	- Dung lượng không quan trọng hoặc thay đổi thường xuyên.
### Map
- Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value.
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map.

Ví dụ:
```c
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> myMap;

    map<string,int> ::iterator it;

    // Thêm phần tử vào map
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap.insert(make_pair("four", 4));
    myMap.erase("one");

    for (auto const var : myMap)
    {
        cout << "Key: " << var.first << " , " << "Value: " << var.second << endl;
    }
    
    for (it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << "Key: " << (*it).first << " , " << "Value: " << (*it).second << endl;
    }
    return 0;
}

```
### Array
- Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library).
- Array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- Array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử [].

Ví dụ:
```c
#include <iostream>
#include <array>

using namespace std;

int main()
{
  
    array <int, 5> arr = {2,3,1,7,6};

    if (arr.empty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << "Array it not empty" << endl;
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Value: " << arr.at(i) << endl;
    }
    
    return 0;
}

```
### Iterator
- Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.
### Algorithm
Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 

Ví dụ:
```c
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    vector <int> arr = {3,5,7,4,1};

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end());
    
    cout << "vector after sort ascending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "vector after sort descending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    return 0;
}

```
</p>
</details>
