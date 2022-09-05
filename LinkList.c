#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;

//初始化链表
LinkList *InitList(int* a, int num){
    LinkList *np, *L = (LinkList *)malloc(sizeof(LinkList));
    np = L;
    int i = 0;
    for(i = 0; i < num; i++) {
        np->next = (LinkList *)malloc(sizeof(LinkList));
        np = np->next;
        np->data = a[i];
        np->next = NULL;
    }

    return L;
}

//打印链表
void ShowLinkList(LinkList *L) {
    if (L == NULL)
    {
        return;
    }

    L = L->next;
    while (L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}

// 在链表头结点之后插入节点 12
void InsertNodeAtHead(LinkList *L) {
    LinkList *s = (LinkList *)malloc(sizeof(LinkList));
    s->data = 12;
    s->next = L->next;
    L->next = s;
}

// 在节点 34 和节点 56 之间插入节点 45
void InsertNodeAtCentre(LinkList *L){  
    int i = 3;
    int j = 0;
    LinkList *p, *s;
    p = L;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList)); 
        s->data = 45;               
        s->next = p->next;       
        p->next = s;               
    } 
}

// 在链表尾插入节点 90
void InsertNodeAtTail(LinkList *L) {
	LinkList *p, *s = (LinkList *)malloc(sizeof(LinkList));
	p = L;
	s->data = 90;
	s->next = NULL;
	while (p->next != NULL) {
		p = p-> next;
	}
	p->next = s;
	p = s;
}
 
// 删除节点 77
void DelNode(LinkList *L) {
    LinkList *s,*p;
	p = L;
	s = L->next;
    while(s != NULL&& s->data != 77) { 
    	p = s;
		s = s->next; 
	}
    if(s->data == 77) {
        p->next=s->next;
		free(s);   
    }
}

int main() {
    // 请勿删除 main 函数代码
    int a[7] = {23, 34, 56, 67, 77, 78, 89};
    LinkList *L = InitList(a, 7);
    ShowLinkList(L);

    // 在链表头结点之后插入节点 12
    InsertNodeAtHead(L);
    ShowLinkList(L);

    // 在节点 34 和节点 56 之间插入节点 45
    InsertNodeAtCentre(L);
    ShowLinkList(L);

    // 在链表尾插入节点 90
    InsertNodeAtTail(L);
    ShowLinkList(L);

    // 删除节点 77
    DelNode(L);
    ShowLinkList(L);
}
