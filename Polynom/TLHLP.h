#include <iostream>
using namespace std;

template <class T>
class TLink
{
public:
	T val;
	TLink *pNext;
};

/*-------------------------------------------------------------------*/

template <class T>
class THeadList
{
protected:
	TLink <T> *pHead, *pFirst, *pCurr, *pLast, *pPred, *pStop;
	int pos, len;
public:
	THeadList()
	{
		pHead = new TLink <T>;
		pStop = pHead;
		pHead->pNext=pStop;
		pFirst=pLast=pCurr=pPred=NULL;
		pos = -1;
		len = 0;
	}
	~THeadList()
	{
		if (len!=0)
		{
			pCurr = pFirst;
			while (pCurr!=pStop)
			{
				pPred = pCurr;
				pCurr = pCurr->pNext;
				delete pPred;
			}
		}
			delete pHead;
	}

	void InsFirst(const T elem)  // вставить первый элемент
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		if (len == 0)
		{
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		len++;
		pos++;
	}

	void DelFirst()  // удалить первый элемент
	{
		if (len !=0 )
		{
			pHead->pNext=pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			len--;
			pos--;
		}
	}

	void InsCurr(const T elem) // вставить элемент в текущую позицию
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		pPred->pNext = tmp;
		tmp->pNext = pCurr
			pCurr = tmp;
		len++;
	}

	void DelCurr() // удалить текущий элемент
	{
		if (pCurr==pFirst)
			DelFirst();
		else 
		{
			pPred->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPred->pNext;
			len--;
		}
	}

	void Reset()   // поставить pCurr на первый элемент
	{
		pCurr = pFirst;
	}

	void GoNext() // перейти к следующему элементу
	{
		pPred = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd()
	{
		return pCurr == pStop;
	}
};