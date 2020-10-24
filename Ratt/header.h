#ifndef __FILE__H__
#define __FILE__H__

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum{
    false,
    true
}Bool;

typedef struct ListeElt{
    int val;
    int *elms[MAX];
}ListeElt, *Liste;

#endif
