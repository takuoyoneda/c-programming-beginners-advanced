//
//  main.c
//  sec_02
//
//  Created by 米田 拓男 on 2017/09/13.
//  Copyright © 2017 shakeweb. All rights reserved.
//

#include <stdio.h>

#define LENGTH 5
#define BREADTH 10

int main()
{
    printf("Hello, World!\n");
    
    int area=LENGTH*BREADTH;
    printf("AREA=%d\n\n",area);
    
    int const LENGTH2=10;
    int const BREADTH2=15;
    
    int area2 = LENGTH2*BREADTH2;
    printf("AREA2=%d\n\n",area2);
    
    
    int a,b;
    printf("Please enter first no=");
    scanf("%d",&a);
    
    printf("Please enter first no=");
    scanf("%d",&b);
    
    area = a*b;
    
    printf("AREA=%d\n\n",area);
    
    return 0;
}
