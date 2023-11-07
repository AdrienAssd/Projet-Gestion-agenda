#include <stdio.h>
#include "cells.h"
#include "lists.h"
#include "research.h"

int main() {
    t_d_list list;
    list = cellinlist();
    //printf("%d\n",researchclassique(list, 5));
    printf("%d",researchNivHaut(list, 5));
    //listNiv(3);
    return 0;
}
