// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
    struct Node* ptr1, *ptr2, *ptr3;
    int count = 0;
 
    // generate all possible triplets
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
 
                // if elements in the current triplet sum up to 'x'
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
 
                    // increment count
                    count++;
 
    // required count of triplets
    return count;
}
