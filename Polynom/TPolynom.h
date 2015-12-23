#include <iostream>
using namespace std;

struct TMonom {
	double coeff;
	int power;
};

bool operator<(const TMonom& m1, const TMonom& m2)
{
	return m1.power<m2.power;
}
/*--------------------------------------------------------------*/


class TPolynom: THeadList <TMonom>
{
public:
	TPolynom()
	{
		pHead->val.coeff = 0;
		pHead->val.power = -1;
	}

	void InsMonom(const TMonom elem)  // вставить первый элемент
	{
		TLink <TMonom> *tmp = new TLink <TMonom>;
		tmp->val = elem;
		if (len == 0)
		{
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		else 
		{
			for (Reset();!IsEnd();GoNext())
			{
				if (tmp->val.power > pCurr->val.power)
				{
					InsCurr(tmp->val);
					break;
				}
			}

		}
		len++;
		pos++;
	}

	TPolynom &operator+=( TPolynom &Q)
	{
		Reset();
		Q.Reset();
		while (pCurr->val.power != -1)
		{
			if (pCurr->val.power > Q.pCurr->pNext.power)
				GoNext();
			else 
				if (pCurr->val.power < Q.pCurr->pNext.power)
				{
					InsCurr(Q.pCurr->val);
					Q.GoNext();
				}
				else 
				{
					pCurr->val.coeff+=Q.pCurr->val.coeff;
					if (pCurr->val.coeff == 0)
						DelCurr();
					else 
						GoNext();
					Q.GoNext();
				}
		}
	}

	TPolynom (TPolynom& Q)
	{
		pHead->val.power = -1;
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
			InsLast(Q.pCurr->val);
	}
};