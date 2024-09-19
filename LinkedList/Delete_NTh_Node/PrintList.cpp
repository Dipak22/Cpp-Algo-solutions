// Template for printing the linked list with forward arrows
#include "LinkedList_h.h"
#include<iostream>
void PrintListWithForwardArrow(EduLinkedListNode *linkedListNode)
{
    EduLinkedListNode *temp = linkedListNode;
    while (temp)
    {
        std::cout << temp->data << " "; // print node value
        temp = temp->next;
        if (temp)
        {
            std::cout << "→ ";
        }
        else
        {
            // if this is the last node, print null at the end
            std::cout << "→ NULL ";
        }
    }
}

void PrintListWithForwardArrowLoop(EduLinkedListNode *linkedListNode)
{
    EduLinkedListNode *temp = linkedListNode;
    while (temp)
    {
        std::cout << temp->data << " "; // print node value
        temp = temp->next;
        if (temp)
        {
            std::cout << "→ ";
        }
        
    }
}