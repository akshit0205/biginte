#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
struct bigint
{
    int data;
    struct bigint *next ;
    int l;
};
typedef struct bigint b;
b* create();
void reverse(b** p)
{
    b* current=*p;
    b* prev= NULL;
    b* next;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        (*p)->l++;
    }
    *p=prev;  
}
b* polysub(b* p1, b* p2) {
    int borrow = 0;
    reverse(&p1);
    reverse(&p2);
    b* p3 = NULL;

    while (p1->l < p2->l) {
        b* temp = (b*)malloc(sizeof(b));
        temp->data = 0;
        temp->next = p1;
        p1 = temp;
        p1->l++;
    }

    while (p1 != NULL || p2 != NULL || borrow) {
        int x = borrow;
        b* temp = (b*)malloc(sizeof(b));

        if (p1) {
            x += p1->data;
            p1 = p1->next;
        }

        if (p2) {
            x -= p2->data;
            p2 = p2->next;
        }

        if (x < 0) {
            x += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        temp->data = x;
        temp->next = p3;
        p3 = temp;
    }

    reverse(&p3);

    return p3;
} 
b* polymulti(b* p1, b* p2) {
    b* result = NULL;
    long long N = 1000000007;
    long long num1 = 0;
    long long num2 = 0;

    while (p1 || p2) {
        if (p1) {
            num1 = ((num1) * 10) % N + p1->data;
            p1 = p1->next;
        }

        if (p2) {
            num2 = ((num2) * 10) % N + p2->data;
            p2 = p2->next;
        }
    }

    long long product = num1 * num2;
    b* prev = NULL;
    return result;
}


b* polyadd(b*p1,b*p2)
{
    int x,carry=0;
    b* p3=NULL;
    b* temp;
    reverse(&p1);
    reverse(&p2);
    while (p1!=NULL || p2!=NULL || carry)
    {
        temp=(b*)malloc(sizeof(b));
        x=carry;
        if (p1)
        {
            x+=p1->data;
            p1=p1->next;
        }
        if (p2)
        {
            x+=p2->data;
            p2=p2->next;
        }
        carry=x/10;
        x%=10;
        temp->data=x;
        temp->next=p3;
        p3=temp;
    }
return p3; 
}
void print(b* p)
{
    b* cu=p;
    while (cu!=NULL)
    {
        printf("%d",cu->data);
        cu=cu->next;
    }
    
}
b* create(int data) {
    b* newnode = (b*)malloc(sizeof(b));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
b* input() {
    b* temp = NULL;
    char ch;

    printf("Enter big integer:\n");

    while (1) {
        ch = getchar();
        if (ch == '\n' || !isdigit(ch)) {
            break;
        }

        int digit = ch - '0';
        b* newnode = create(digit);

        if (temp == NULL) {
            temp = newnode;
        } else {
            newnode->next = temp;
            temp = newnode;
        }
    }

    return temp;
}

