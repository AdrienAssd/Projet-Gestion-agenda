#include "lists.h"

t_d_list *createEmptyList(int niv_max)
{
    t_d_list *newlist = (t_d_list*)malloc(sizeof(t_d_list));
    newlist->niv_max = niv_max;
    newlist->head = (t_d_cell*)malloc(newlist->niv_max*sizeof(t_d_cell));
    for(int i = 0 ; i < newlist->niv_max ; i++)
    {
        newlist->head[i] = NULL;
    }
    return newlist;
}
