#include <iostream>
#include <stdio.h>
using namespace std;

typedef char ElemType;

typedef struct BiNode
{
	ElemType data;
	BiNode * lchild;
	BiNode * rchild;
}BiNode, *BiTree;

//创建子树
void CreateNode(BiTree * T)
{
	ElemType c;
	scanf("%c", &c);

	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateNode(&(*T)->lchild);
		CreateNode(&(*T)->rchild);
	}
}

//深度为较高子树深度加一
int Depth(BiNode * pRoot)
{
	if (NULL == pRoot)
	{
		return 0;
	}
	int nLeft = Depth(pRoot->lchild);
	int nRight = Depth(pRoot->rchild);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//功能测试（输入普通的二叉树，二叉树中所有的结点
//都没与左/右子树）
//特殊输入测试（二叉树只有一个结点，二叉树的头结点为NULL指针）

int main()
{
	BiTree T;
	CreateNode(&T);
	cout << Depth(T) << endl;
	return 0;
}