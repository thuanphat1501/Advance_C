#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}



void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}



int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}
// Thêm một node vào phía trước 
void push_front(node** pHead, int value)
{
    node* temp = createNode(value);
    temp->next = *pHead;
    *pHead = temp;
}
// xóa một node đầu tiên
void pop_front(node **pHead)    // xoa node dau tien
{
    if(*pHead == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }
    node* temp = *pHead;
    *pHead = (*pHead)->next;
    free(temp);
} 

int front(node *array) // lay gia tri cua node dau tien
{
    if(array == NULL){
        printf("Danh sach rong\n");
        return -1;
    }
    return array-> value;
}

int back(node *array) // lay gia tri cua node cuoi cung
{
    node* current = array;
    while(current->next != NULL){
    current = current->next;
    }
    return current->value;
}
void insert(node **array, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    node* newNode = createNode(value);
    if (pos == 0) {
        newNode->next = *array;
        *array = newNode;
        return;
    }

    node* current = *array;
    for (int i = 0; i < pos - 1 && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri khong hop le\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
// Xoa phan tu o vi tri position trong danh sach lien ket
void deletee(node** array, int pos)
{
    if (*array == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }

    node* current = *array;
    node* prev = NULL;
    int count = 0;

    // Duyet qua danh sach de tim vi tri can xoa
    while (current != NULL && count < pos)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }

    // Xoa phan tu
    if (prev == NULL)
    {
        // Neu phan tu can xoa la phan tu dau tien
        *array = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}
// Lấy kích thước của danh sách liên kết đơn
int getSize(node* array)
{
    int size = 0;
    node* current = array;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}
// Kiểm tra xem danh sách liên kết có rỗng hay không
bool empty(node** array)
{
    return (*array == NULL);
}




int main()
{
    node* arr = NULL;
    


	return 0;
}

