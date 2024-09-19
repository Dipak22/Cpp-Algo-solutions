#ifndef lin_h
#define lin_h
struct EduLinkedListNode{
    int data;
    EduLinkedListNode* next;
    EduLinkedListNode(int d){
        data = d;
        next = nullptr;
    }

};
void PrintListWithForwardArrow(EduLinkedListNode *linkedListNode);
void PrintListWithForwardArrowLoop(EduLinkedListNode *linkedListNode);

#endif