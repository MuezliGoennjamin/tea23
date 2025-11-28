#include <fmt/chrono.h>
#include <fmt/format.h>
#include "list.hpp"



ListNode_t* NewListNode(void)
{
    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    node->data = 0;
    node->pNext = NULL;
    return node;
}

void FreeListNode(ListNode_t* elem)
{
    free(elem);
}

List_t* NewList(void) {
    List_t* List = (List_t*)malloc(sizeof(List_t));
    List->pHead = NULL;
    List->pTail = NULL;
    List->size = 0;
}

void FreeList(ListNode_t* node){

    ListNode_t* current = node;
    while (current != NULL) {
        ListNode_t* next = current->pNext; // nächsten Zeiger retten
        FreeListNode(current);             // aktuellen Knoten freigeben
        current = next;                    // weitermachen
    }

}

int InsertIntoLinkedList(List_t* List, ListNode_t* elem)
{
    if (List == NULL || elem == NULL)
        return -1;

    elem->pNext = NULL;

    // Fall 1: leere Liste
    if (List->pHead == NULL) {
        List->pHead = elem;
        List->pTail = elem;
    }
    else {
        // Fall 2: nicht leere Liste → am Ende anhängen
        List->pTail->pNext = elem;  /*verlinkt das letzte Element der Liste mit dem neuen*/
        List->pTail = elem;         /*das neue Element ist jetzt das letzte Element*/
    }

    List->size++;
    return 0;
}

int InsertIntoLinkedListAfterNode(List_t* List, ListNode_t* node, ListNode_t* elem)
{
    if (List == NULL || node == NULL || elem == NULL)
        return -1;

    // neues Element vorbereiten
    elem->pNext = node->pNext;

    // elem nach node einhängen
    node->pNext = elem;

    // wenn node das letzte Element war, Tail aktualisieren
    if (List->pTail == node) {
        List->pTail = elem;
    }

    List->size++;
    return 0;
}


int RemoveFromList(List_t* List, ListNode_t* elem)
{
    if (List == NULL || elem == NULL)
        return -1;

    ListNode_t* prev = NULL;
    ListNode_t* current = List->pHead;

    // Vorgänger (prev) von elem suchen
    while (current != NULL && current != elem) {
        prev = current;
        current = current->pNext;
    }

    // Element nicht in der Liste gefunden
    if (current == NULL)
        return -1;

    // Sonderfall: Element ist Head
    if (prev == NULL) {
        // elem war pHead
        List->pHead = current->pNext;
    } else {
        // "normales" Element in der Mitte
        prev->pNext = current->pNext;
    }

    // Sonderfall: Element ist Tail
    if (List->pTail == current) {
        List->pTail = prev;   // kann auch NULL werden, wenn Liste jetzt leer ist
    }

    FreeListNode(current);
    List->size--;

    return 0;
}


ListNode_t* GetNext(List_t* List, ListNode_t* elem)
{
    if (List == NULL)
        return NULL;

    if (elem == NULL) {
        // Start: erstes Element
        return List->pHead;
    } else {
        // nächstes Element nach elem
        return elem->pNext;
    }
}





