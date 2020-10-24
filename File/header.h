#ifndef __FILE__H__
#define __FILE__H__

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true
}Bool;

typedef struct FileElt{
    int val;
    struct FileElt *next;
}FileElt, *File;

File newFile();
Bool videFile(File F);
int longFile(File F);
int premierFile(File F);
int dernierFile(File F);
void afficheFile(File F);
File Emfiler(File F,int x);
File Defiler(File F);

#endif
