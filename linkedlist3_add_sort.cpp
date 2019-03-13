#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    n * next;
};

typedef n node;

node * createNode(int x) {
    node * n;
    n = (node *) malloc(sizeof(node));
    n->next  = NULL;
    n->x = x;
    return n;
}

void bastir (node * r) 
{
    int i = 0;
    while (r != NULL) {
        printf("%d => %d\n", i, r->x);
        i++;
        r = r->next;
    }
}

node * ekleSirali (node * r, int x) 
{
    if (r == NULL) { // linklist boşsa
        r = createNode(x);
        return r;
    }
    if (r->x > x) { // ilk elemandan küçükse durumu
        node * temp;
        temp = createNode(x);
        temp->next = r;
        return temp; // root değişiyor
    }
    node * iter = r;
    while (iter->next != NULL &&  iter->next->x < x) 
    {
        iter = iter->next;
    }
    node * temp = createNode(x);
    temp->next = iter->next;
    iter->next = temp;
    return r;
}

int main () {
    node * root;
    root = NULL;
    root = ekleSirali(root, 400);
    root = ekleSirali(root, 40);
    root = ekleSirali(root, 4);
    root = ekleSirali(root, 450);
    root = ekleSirali(root, 50);
    bastir(root);
}