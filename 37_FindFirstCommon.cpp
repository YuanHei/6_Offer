#include <iostream>
using namespace std;

typedef struct ListNode
{
	int        m_nKey;
	ListNode * m_pNext;
}ListNode, *ListLink;

void Create(ListLink *L)
{
	ListNode * s = NULL, *p;
	*L = new ListNode();
	(*L)->m_pNext = NULL;
	p = *L;
	int value;
	cout << "请输入结点值：" << endl;
	while ((cin >> value))
	{
		if (value == -1)
		{
			break;
		}
		s = new ListNode();
		s->m_nKey = value;
		p->m_pNext = s;
		s->m_pNext = NULL;
		p = s;
	}
}

void Show(ListLink L)
{
	if (L == NULL)
	{
		return;
	}
	ListNode * p = L->m_pNext;
	while (p != NULL)
	{
		cout << p->m_nKey << "-->";
		p = p->m_pNext;
	}
	cout << "NULL" << endl;
}

//获取链表长度
unsigned int GetListLength(ListLink pHead)
{
	unsigned int nLength = 0;
	ListNode * pNode = pHead;
	while (pNode != NULL)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}

//查找第一个公共结点
ListNode * FindFirstCommonNode(ListLink pHead1, ListLink pHead2)
{
	unsigned int nLength1 = GetListLength(pHead1->m_pNext);
	unsigned int nLength2 = GetListLength(pHead2->m_pNext);
	int nLengthDif = nLength1 - nLength2;

	ListNode * pListHeadLond = pHead1->m_pNext;
	ListNode * pListHeadShort = pHead2->m_pNext;

	if (nLength2 > nLength1)
	{
		pListHeadLond = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//先将长链表向后遍历长的部分，由于在之后重合，故第一个结点是在尾部
	for (int i = 0; i < nLengthDif; ++i)
	{
		pListHeadLond = pListHeadLond->m_pNext;
	}

	while ((pListHeadLond != NULL)
		&& (pListHeadShort != NULL)
		&& (pListHeadLond->m_nKey != pListHeadShort->m_nKey))
	{
		pListHeadLond = pListHeadLond->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	ListNode * pFirstCommonNode = pListHeadLond;

	return pFirstCommonNode;
}

//功能测试（输入两个链表有公共交点：第一个
//公共交点在链表的中间、末尾、头结点；输入的两个
//链表没有公共交点）
//特殊输入测试（输入烦人链表头结点为NULL指针）
int main()
{
	ListLink L, L1;
	ListNode *p = NULL;
	Create(&L);
	Show(L);
	Create(&L1);
	Show(L1);
	p = FindFirstCommonNode(L, L1);
	cout << p->m_nKey << endl;
	return 0;
}