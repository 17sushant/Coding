TNode* sortedListToBSTRecur(LNode **head_ref, int n)
{
    if (n <= 0)
        return NULL;
    TNode *left = sortedListToBSTRecur(head_ref, n/2);
    TNode *root = newNode((*head_ref)->data);
    root->left = left;
    *head_ref = (*head_ref)->next;
    root->right = sortedListToBSTRecur(head_ref, n-n/2-1);
    return root;
}
