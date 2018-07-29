#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define pNode node *
using namespace std;


struct node
{
    int height;
    node *lch;
    node *rch;
    int val;
};

pNode newnode(int x)
{
    pNode a = (node *)malloc(sizeof(node));
    a->val = x;

    return a;
}
pNode RightRotate(pNode a)
{
    pNode b = a->lch;
    a->lch = b->rch;
    b->rch = a;
    a->height = max(a->lch.height, a->rch.height);
    b->height = max(b->lch.height, b->rch.height);
    return b;
}

pNode LeftRotate(pNode a)
{
    pNode b = a->rch;
    a->rch = b->lch;
    b->lch = a;
    a->height = max(a->lch.height, a->rch.height);
    b->height = max(b->lch.height, b->rch.height);
    return a;
}

pNode LeftRightRotate(pNode a)
{
    a->lch = LeftRotate(a->lch);
    return RightRotate(a);
}
pNode RightLeftRotate(pNode a)
{
    a->rch = RightRotate(a->rch);
    return LeftRotate(a);
}

pNode insertTree(int x, pNode root)
{
    if(root == NULL)
        t = newnode(x);
    else if(x < root->val)
    {
        root->lch = insertTree(x, root->lch);
        if(root->lch.height - root->rch.height == 2)
        {
            if( x < root->lch.val)
                root = RightRotate(root);
            else if( x > root->lch.val )
                root = LeftRightRotate(root);
        }
    }
    else
    {
        root->rch = insertTree(x, root->rch);
        if(root->rch.height - root->lch.height == 2)
            root = LeftRotate(root);
        else
            root = RightLeftRotate(root);
    }
    root->height = max( root->lch.height, root->rch.height ) + 1;
    return root;
}

pNode deleteTree(int x, pNode root)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->val == x)
    {
        if(root->rch == NULL)
        {
            pNode temp = root;
            root = root->lch;
            free(temp);
        }
        else
        {
            pNode head = root->rch;
            while(head->lch)
                head = head->lch;
            root->val = head->val;
            root->rch = deleteTree(root->val, root->rch);
            root->height = max(root->lch.height, root->rch.height)+1;
        }
        return root;
    }
    else if(root->val < x)
    {
        deleteTree(x, root->rch);
        if(root->rch)
            ro
    }
    else
    {

    }
}
int main()
{

    return 0;
}
