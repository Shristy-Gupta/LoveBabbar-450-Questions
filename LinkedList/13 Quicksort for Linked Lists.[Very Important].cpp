struct node* getTail(struct node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}
// here the sorting happens exclusive of the end node
struct node* partition(struct node* head, struct node* end,struct node** newHead,struct node** newEnd)
{
	struct node* pivot = end;
	struct node *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list
	// might change which is updated in the newHead and
	// newEnd variables
	while (cur != pivot) {
		if (cur->data < pivot->data) {
			// First node that has a value less than the
			// pivot - becomes the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change
			// tail
			if (prev)
				prev->next = cur->next;
			struct node* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the
	// current list, pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}
struct node* quickSortRecur(struct node* head,
							struct node* end)
{
	// base condition
	if (!head || head == end)
		return head;

	node *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be
	// updated by the partition function
	struct node* pivot
		= partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur
	// for the left part.
	if (newHead != pivot) {
		// Set the node before the pivot node as NULL
		struct node* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to
		// pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}
//you have to complete this function
void quickSort(struct node **headRef) {
    (*headRef)
		= quickSortRecur(*headRef, getTail(*headRef));
	return;
    
}
