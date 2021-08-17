// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	if(head == NULL || head->next == NULL)
		return head;

	// perform on all the nodes in list
	for(Node *i = head->next; i != NULL; i = i->next) {
		Node *j = i;
		// There will be atmost k swaps for each element in the list
		// since each node is k steps away from its correct position
		while(j->prev != NULL && j->data < j->prev->data) {
			// swap j and j.prev node
			Node* one = j->prev->prev;
			Node* two = j->prev;
            Node* three=j;
			Node *four = j->next;
			two->next = four;
			two->prev = three;
			three->prev = one;
			three->next = two;
			if(one != NULL)
				one->next = three;
			if(four != NULL)
				four->prev = two;
		}
		// if j is now the new head
	// then reset head
		if(j->prev == NULL)
			head = j;
	}
	return head;
}
