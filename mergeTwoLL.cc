#include "LinkedList.h"

Node* mergeTwoList(Node* l1, Node* l2){
    if(!l1) return l2;
	if(!l2) return l1;

	Node* head = (l1->data <= l2->data)?l1:l2;
	Node* p = head;

	if(head == l1){
		l1 = l1->next;
	}else if(head == l2){
		l2 = l2->next;
	}

	while(l1&&l2){
		Node*& temp = (l1->data <= l2->data)?l1:l2;
		p->next = temp;
		temp = temp->next;
		p = p->next;
	}

	if(l1) p->next = l1;
	if(l2) p->next = l2;

	return head;
}

void split(Node* l1,Node** front, Node** back){
/*  if(!l1 || !l1->next) return NULL;
	Node* l2 = l1->next;
	l1->next = l2->next;
	l2->next = split(l2->next);
	return l2;*/
	Node* fast, *slow;
	if(!l1 || !l1->next){
		*front = l1;
		*back = NULL;
	}else{
		slow = l1;
		fast = l1->next;
	}
	while(fast){
		fast = fast->next;
		if(fast){
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front = l1;
	*back = slow->next;
	slow->next = NULL;

}

Node* merge(Node* l1, Node* l2){
	if(!l1) return l2;
	if(!l2) return l1;
	if(l1->data < l2->data){
		l1->next = merge(l1->next, l2);
		return l1;
	}else{
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

void  mergeSort(Node* l1){
	if(!l1 || !l1->next){
		return ;
	}

	Node* head = l1;
	Node* a;
	Node* b;

	split(head, &a, &b);
	mergeSort(a);
	mergeSort(b);
	l1 =  merge(a, b);
	
}


int main(){
    Node* l1;
	Node* l2;	
	l1 = initilizeList(1,5);
	//l2 = initilizeList(3,7);
//    printList(l1);
//	printList(l2);
//	
//
	//Node* head = mergeTwoList(l1,l2);
	
	
	 mergeSort(l1);
	printList(l1);
	while(result){
		printf("%d\n", result->data);
		result = result->next;
	}
	return 0;
}
