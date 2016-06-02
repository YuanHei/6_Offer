#include <iostream>
#include <stdio.h>
using namespace std;

//输入一棵二叉树的根结点，判断该树是不是平衡二叉树
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

//判断深度相差不超过1
//方法一:调用深度函数，结点遍历多次
bool IsBalanced_1(BiNode * pRoot)
{
	if (NULL == pRoot)
	{
		return true;
	}
	int left = Depth(pRoot->lchild);
	int right = Depth(pRoot->rchild);
	int diff = left - right;
	if (diff > 1 || diff < -1)
	{
		return false;
	}
	return IsBalanced_1(pRoot->lchild) && IsBalanced_1(pRoot->rchild);
}

//方法二：每个结点只遍历一次的解法
bool IsBalanced(BiNode * pRoot, int * pDepth)
{
	if (pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(pRoot->lchild, &left)
		&& IsBalanced(pRoot->rchild, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

bool IsBalanced(BiNode * pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
	//记录深度
}

//功能测试（平衡的二叉树，不是平衡的二叉树，二叉树中所有的结点都没有
//左/右子树）
//特殊输入测试（二叉树中只有一个结点，二叉树的头结点为NULL指针）
int main()
{
	BiTree T;
	CreateNode(&T);
	if (IsBalanced(T))
	{
		cout << "AVL" << endl;
	}
	else
	{
		cout << "Not AVL" << endl;
	}
	if (IsBalanced_1(T))
	{
		cout << "AVL" << endl;
	}
	else
	{
		cout << "Not AVL" << endl;
	}
	return 0;
}