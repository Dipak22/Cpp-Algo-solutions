#include <iostream>
#include <string>
#include <vector>
#include "LinkedList_h.h"
#include "LinkedList.cpp"

EduLinkedListNode* RemoveNthLastNode(EduLinkedListNode* head,int n){
    EduLinkedListNode* left = head;
    EduLinkedListNode* right = head;
    for(int i =0;i<n;i++){
        right = right-> next;
        if(!right)
            return head->next;
    }
        
    
    while(right->next){
        right = right->next;
        left  = left->next;
    }

    left->next = left->next->next;
    return head;
}

int main(){
    std::vector<std::vector < int>> inputs = {
		{ 23, 89, 10, 5, 67, 39, 70, 28 },
		{ 34, 53, 6, 95, 38, 28, 17, 63, 16, 76 },
		{ 288, 224, 275, 390, 4, 383, 330, 60, 193 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 69, 8, 49, 106, 116, 112, 104, 129, 39, 14, 27, 12 }
	};

	std::vector<int> n = { 4, 1, 6, 9, 11 };

	for (int i = 0; i < inputs.size(); i++)
	{
		LinkedList *linkedlists = new LinkedList();
		linkedlists->createLinkedList(inputs[i]);
		std::cout << i + 1 << ".\tLinked List:\t\t";
		PrintListWithForwardArrow(linkedlists->head);
		std::cout << "\n\tn = " << n[i] << std::endl;
		std::cout << "\tUpdated Linked List:\t";
		PrintListWithForwardArrow(RemoveNthLastNode(linkedlists->head, n[i]));
		std::cout << std::endl << std::string(100, '-') << "\n";
	}
}