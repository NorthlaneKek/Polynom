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
	TPolynom(int mas[][2], int Size)
	{
		//pHead->val.coeff = 0;
		//pHead->val.power = -1;
		for (int i = 0; i < Size; i++)
		{
			TMonom M;
			M.coeff = mas[i][0];
			M.power = mas[i][1];
			InsLast(M);
		}
	}

	void InsMonom(const TMonom elem)  
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
		while (Q.pCurr->val.power != -1)
		{
			if (pCurr->val.power > Q.pCurr->val.power)
				GoNext();
			else 
				if (pCurr->val.power < Q.pCurr->val.power)
				{
					if (len == 0)
						InsFirst(Q.pCurr->val);
					else
					InsCurr(Q.pCurr->val);
					Q.GoNext();
				}
				else 
				{
					pCurr->val.coeff+=Q.pCurr->val.coeff;
					if (pCurr->val.coeff == 0)
					{
						if (pCurr!=pFirst)
						DelCurr();
						else DelFirst();
					}
					else
					GoNext();
					Q.GoNext();
				}
				}
		return *this;
	}

	TPolynom (TPolynom& Q)
	{
		pHead->val.power = -1;
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
			InsLast(Q.pCurr->val);
	}
	friend ostream& operator<<(ostream &out, TPolynom &p)
	{
		if (p.len != 0)
		{
			for (p.Reset(); !p.IsEnd();p.GoNext())
			{
				out<<p.pCurr->val.coeff;
				if (p.pCurr->val.power /100 > 0)
					cout<<"x^"<<p.pCurr->val.power/100;
				if ((p.pCurr->val.power / 10)%10>0)
					cout<<"y^"<<(p.pCurr->val.power/10)%10;
				if (p.pCurr->val.power%10 > 0)
					cout<<"z^"<<p.pCurr->val.power %10;
				if (p.pCurr->pNext!=p.pStop && p.pCurr->pNext->val.coeff > 0)
					out<<"+";
			}
		}
		else
			out<<"Полином пуст";
		return out;
	}


};