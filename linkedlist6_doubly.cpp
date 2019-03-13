#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    n * next;
    n * prev;
};

typedef n node;

node * createNode(int x) {
    node * n;
    n = (node *) malloc(sizeof(node));
    n->next  = NULL;
    n->prev  = NULL;
    n->x = x;
    return n;
}

void bastir (node * r) 
{
    printf("----BASTIR------\n");
    int i = 0;
    if(r == NULL) return;
    while (r->next != NULL) {
        printf("%d=>%d ", i, r->x);
        i++;
        r = r->next;
    }
    printf("%d=>%d\n", i, r->x);
    i = 0;
    while (r != NULL) {
        printf("%d=>%d ", i, r->x);
        i++;
        r = r->prev;
    }
    printf("\n----/BASTIR------\n");
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
        r->prev = temp;
        return temp; // root değişiyor
    }
    node * iter = r;
    while (iter->next != NULL &&  iter->next->x < x) 
    {
        iter = iter->next;
    }
    node * temp = createNode(x);
    if (iter->next != NULL) {
        temp->next = iter->next;
        temp->next->prev = temp;
    }
    temp->prev = iter;
    iter->next = temp;
    return r;
}

node * sil(node * r, int x) {
    node * temp;
    node * iter = r;
    if (r->x == x) { // ilk elemansa
        temp = r->next;
        temp->prev = NULL;
        free(r);
        return temp;
    }
    while (iter->next != NULL && iter->next->x != x) {
        iter = iter->next;
    }

    if (iter->next == NULL) { // bulunamazsa
        printf("%d bulunamadı\n--------\n", x);
        return r;
    }

    temp = iter->next;
    iter->next = temp->next;
    if (temp->next != NULL)
        iter->next->prev = iter;
    free(temp);
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
    root = ekleSirali(root, 401);
    root = ekleSirali(root, 41);
    root = ekleSirali(root, 5);
    root = ekleSirali(root, 451);
    root = ekleSirali(root, 49);
    bastir(root);

    root = sil(root, 4);
    bastir(root);
    root = sil(root, 999);
    bastir(root);
    root = sil(root, 41);
    bastir(root);
    root = sil(root, 451);
    bastir(root);
    root = sil(root, 450);
    bastir(root);
    root = sil(root, 5);
    bastir(root);
    root = sil(root, 50);
    bastir(root);
}