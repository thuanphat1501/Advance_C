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
