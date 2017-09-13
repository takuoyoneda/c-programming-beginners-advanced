//
//  main.c
//  c-programming-beginners-advanced
//
//  Created by 米田 拓男 on 2017/09/13.
//  Copyright © 2017 shakeweb. All rights reserved.
//

/*
 Dynamic memory allocation in C
 
 malloc()   allocates single block of requested memory.
 calloc()   allocates multiple block of requested memory.
 realloc()  reallocates the memory occupied by malloc() or calloc() functions.
 free()     frees the dynamically allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>

void changeValue(int *p);
void test1();
void test2();
void test3();
void test4();

int main()
{
//    test1();
//    test2();
//    test3();
    test4();
}


void test1()
{
    int a = 10; // 64 bit int 4 byte
    
    printf("Before: a=%d \n", a); // original value
    printf("Address of a: %x \n", (unsigned int)&a); // original address
    changeValue(&a); // value is changed
    printf("After: a=%d \n\n", a); // new value
    
    int *p1;
    p1 = &a;
    
    printf("value of p1 = %x \n", (unsigned int)p1); // original address
    printf("address of a = %x \n", (unsigned int)&a); // original address
    printf("value at of p1 = %d \n\n", *p1); // new value
    
    int **p2;
    p2 = &p1;
    printf("value at of p2 = %x \n", (unsigned int)p2); // new address
    printf("value at of p2 = %x \n", (unsigned int)*p2); // original address
    printf("value of p2 = %d \n\n", **p2); // original value
    
    
    printf("address of a = %u \n", (unsigned int)p1); // original address
//    p1=p1+1; // increases 4 byte
//    p1=p1+1; // increases 8 byte
//    p1=p1-1; // decreases 4 byte
    p1=p1-2; // decreases 8 byte
    printf("p now = %u \n\n",(unsigned int)p1); // new address
}

void changeValue(int *p)
{
    *p=*p+20;
    printf("inside function call by reference p = %d\n", *p); // new value
    
}

void test2()
{
    int n,i,*ptr,sum=0;
    
    printf("Enter size of list of elements: ");
    scanf("%d", &n);
    
    ptr=(int*)malloc(n*sizeof(int));
    printf("sizeof(int): %d \n", (unsigned int)sizeof(int)); // 4
    printf("n*sizeof(int): %lu \n", (unsigned long)n*sizeof(int));
    printf("malloc(n*sizeof(int): %lu \n", (unsigned long)malloc(n*sizeof(int)));
    printf("(int*)malloc(n*sizeof(int): %lu \n\n", (unsigned long)(int*)malloc(n*sizeof(int)));
    
    if(ptr==NULL)
    {
        printf("Sorry! no memory");
        exit(0);
    }
    
    printf("Enter elements: \n");
    for (i=0;i<n;++i)
    {
        scanf("%d", ptr+i);
        printf("ptr+i: %d \n", (unsigned int)ptr+i); // address
        printf("*(ptr+i): %d \n", (unsigned int)*(ptr+i)); // value
        sum+=*(ptr+i);
    }
    
    printf("Sum=%d \n\n", sum);
    free(ptr);
}

void test3()
{
//    char ch[4]={'a','b','c','\n'}; // char array
    char ch[4]="abc"; // string literal
    printf("char: %s \n\n",ch);
    
    char name[50];
    printf("Enter your name: \n");
    gets(name);
    printf("\nNow we will call puts: ");
    puts(name);
    
}

void test4()
{
    FILE *f;
    
    f=fopen("test.txt", "w");
    fprintf(f, "This is a c programming tutorial");
    fclose(f);
    
    char data[255];
    f=fopen("test.txt", "r");
    while(fscanf(f, "%s", data) !=EOF)
    {
        printf("%s ",data);
    }
    fclose(f);
    
    printf("\n\nSuccess \n\n");
}
