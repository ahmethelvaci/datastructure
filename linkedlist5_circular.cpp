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
    node * iter = r;
    if (iter == NULL) return;
    do
    {
        printf("%d=>%d ", i, iter->x);
        i++;
        iter = iter->next;
    } while (iter != r);
    
    printf("\n----------\n");
}

node * ekle(node * r, int x) {
    if (r == NULL) { // linklist boşsa
        r = createNode(x);
        r->next = r;
        return r;
    } 
    
    node * iter = r;
    while(iter->next != r){
        iter = iter->next;
    }
    iter->next = createNode(x);
    iter->next->next = r;
    return r;
}

node * ekleSirali (node * r, int x) 
{
    node * temp;
    node * iter = r;
    if (r == NULL) { // linklist boşsa
        r = createNode(x);
        r->next = r;
        return r;
    }
    if (r->x > x) { // ilk elemandan küçükse durumu
        temp = createNode(x);
        temp->next = r;
        while (iter->next != r) 
            iter = iter->next;
        iter->next = temp;
        return temp; // root değişiyor
    }

    while (iter->next != r &&  iter->next->x < x) 
    {
        iter = iter->next;
    }
    temp = createNode(x);
    temp->next = iter->next;
    iter->next = temp;
    return r;
}

node * sil(node * r, int x) {
    node * temp;
    node * iter = r;
    if (r->x == x) { // ilk elemansa
        temp = r->next;
        while (iter->next != r) 
            iter = iter->next;
        iter->next = temp;
        free(r);
        return temp; // root değişiyor
    }
    while (iter->next != r && iter->next->x != x) {
        iter = iter->next;
    }

    if (iter->next == r) { // bulunamazsa
        printf("%d bulunamadı\n--------\n", x);
        return r;
    }

    temp = iter->next;
    iter->next = temp->next;
    free(temp);
    return r;

}

int main () {
    node * root;
    root = NULL;
    // root = ekle(root, 3);
    // bastir(root);
    // root = ekle(root, 4);
    // bastir(root);
    // root = ekle(root, 5);
    // bastir(root);
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
}