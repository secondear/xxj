/*【问题描述】
 已知输入n个正整数，正整数之间用空格键分开，请以这n个正整数为权值建立一棵有n个叶子节点的哈夫曼树，求这棵哈夫曼树的带权路径长度。
【输入形式】
 首先输入正整数的个数，然后接下来为接下来的正整数，正整数个数不超过10个，每个数字之间用空格隔开。
【输出形式】
 输出相应的权值
【样例输入】
5 4 5 6 7 8
【样例输出】
69*/
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
typedef struct BTNode {
    int data;
    struct BTNode *lchild, *rchild;
}BTNode, *BTree;

typedef struct Node {
    BTree bt;
    struct Node *link;
} Node, *Forest;

void insertForestNode ( BTree t, Forest fr, Forest head);
void destoryBTree ( BTree t );
void getWPL( BTree t, int depth,  int *WPL);


int main() {

    int num;
    int n;
    int i;
    Forest head, fr, p, q;
    BTree t=NULL,  t1, t2;
    int WPL = 0;

    head = (Forest)malloc(sizeof(Node));
    head->link = NULL;

    scanf("%d",&n);
    //用链式队列存森林
    i = 1;
    while( i <= n ) {

        scanf("%d", &num);

        t = (BTree)malloc(sizeof(BTNode));
        t->data = num;
        t->lchild = t->rchild = NULL;

        fr = (Forest)malloc(sizeof(Node));
        fr->bt = t;
       fr->link = NULL;

        //将元素从大到小排列
        if( head->link == NULL) {
            head->link= fr;
            //top = fr;
        }

        else
            insertForestNode(t,fr,head);

        i++;
    }

    //构造哈夫曼树
    while( head->link != NULL ) {

        t = (BTree)malloc(sizeof(BTNode));
        q = (Forest)malloc(sizeof(Node));
        q->bt = t;
        q->link = NULL;

        t1 = head->link->bt;
        p = head->link;
        head->link = p->link;
        t->lchild = t1;
        free(p);

        t2 = head->link->bt;
        p = head->link;
        head->link = p->link;
        t->rchild = t2;
        free(p);

        t->data = t1->data + t2->data;
        if(head->link != NULL)
            insertForestNode(t,q,head);
    }
    free(head);

    getWPL(t,0,&WPL);
    printf("%d", WPL);

    destoryBTree(t);
    t = NULL;

    return 0;
}

void insertForestNode ( BTree t, Forest fr, Forest head ) {

    Forest p = head->link, q=NULL;

    while ( p != NULL ) {

        if( fr->bt->data > p->bt->data) {
            q = p;
            p = p->link;
        }

        else {
            fr->link = p;

            if( p == head->link)
                head->link = fr;
            else
                q->link = fr;

            break;
        }

    }

    if( p == NULL)
      q->link = fr;

}
void getWPL( BTree t, int depth,  int *WPL) {
    if( t->lchild == NULL && t->rchild == NULL) {
        (*WPL) += depth*t->data;
    }

    else{
        getWPL(t->lchild,depth+1,WPL);
        getWPL(t->rchild,depth+1,WPL);
    }

}

//二叉树的销毁
void destoryBTree ( BTree t ) {

    if( t != NULL ) {
        destoryBTree(t->lchild);
        destoryBTree(t->rchild);
        free(t);
    }

}


