//
//  main.c
//  c-programming-beginners-advanced
//
//  Created by 米田 拓男 on 2017/09/13.
//  Copyright © 2017 shakeweb. All rights reserved.
//

#include <stdio.h>

#define LENGTH 5
#define BREADTH 10


void changeValue(int *p);
void test1();
void test2();

int main()
{
//    test1();
    test2();
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
    
}


