typedef struct node
{
    int val;
    node *next;
} node;

void re_list(node *head)
{
    node *prev;
    node *cur = head;
    node *next = head->next;

    while (cur)
    {
        cur->next = prev;

        prev = cur;
        cur = next;
        next = cur->next;
    }
}