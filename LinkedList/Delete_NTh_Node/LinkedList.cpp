#include "LinkedList_h.h"
#include<vector>
#include<string>

class LinkedList{
    public:
    EduLinkedListNode* head;
    LinkedList():head{nullptr}{}

    void insertNodeAtHead(EduLinkedListNode* node){
        if(head != nullptr){
            node->next = head;
            head = node;
        }else{
            head = node;
        }
    }

    void createLinkedList(std::vector<int>& vec){
        for(int i=vec.size()-1;i>=0;i--){
            EduLinkedListNode* node = new EduLinkedListNode(vec[i]);
            insertNodeAtHead(node);
        }
    }

    int getLength(EduLinkedListNode *h){
        int length = 0;
        EduLinkedListNode* temp = head;
        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }

    EduLinkedListNode* getNode(EduLinkedListNode* h, int pos){
        if(pos<0)
            return h;
        int p =0;
        EduLinkedListNode* ptr = h;
        while(p<pos){
            ptr = ptr-> next;
            ++p;
        }
        return ptr;
    }

    std::string toString(){
        std::string result = "";
        EduLinkedListNode *temp = head;
        while(temp != nullptr){
            result += std::to_string(temp->data);
            temp = temp->next;
            if(temp !=nullptr){
                result +=", ";
            }
        }
        result +="";
        return result;
    }

};