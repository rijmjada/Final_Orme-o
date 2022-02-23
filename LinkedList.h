#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define ERROR -1
#define ALLOK 1

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;


LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* pList);
Node* test_getNode(LinkedList* pList, int nodeIndex);
int test_addNode(LinkedList* pList, int nodeIndex,void* pElement);
int ll_add(LinkedList* pList, void* pElement);
void* ll_get(LinkedList* pList, int nodeIndex);
int ll_set(LinkedList* pList, int nodeIndex,void* pElement);
int ll_remove(LinkedList* pList,int nodeIndex);
int ll_clear(LinkedList* pList);
int ll_deleteLinkedList(LinkedList* pList);
int ll_indexOf(LinkedList* pList, void* pElement);
int ll_isEmpty(LinkedList* pList);
int ll_push(LinkedList* pList, int nodeIndex, void* pElement);
void* ll_pop(LinkedList* pList,int nodeIndex);
int ll_contains(LinkedList* pList, void* pElement);
int ll_containsAll(LinkedList* pListA,LinkedList* pListB);
LinkedList* ll_subList(LinkedList* pList,int from,int to);
LinkedList* ll_clone(LinkedList* pList);
int ll_sort(LinkedList* pList, int (*pFunc)(void*,void*), int order);
LinkedList* ll_filter(LinkedList* pList, int (*pFunc)(void*));
LinkedList* ll_map (LinkedList* pList, void*(*pFunc) (void* element));

#endif // LINKEDLIST_H_INCLUDED
