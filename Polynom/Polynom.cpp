// Polynom.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "TLHLP.h"
#include "TPolynom.h"


int _tmain(int argc, _TCHAR* argv[])
{

setlocale(LC_ALL, "Russian"); 
int size;
int step = 0; 
int StepOfVariable; 
int mas[][2] = { NULL }; 
cout<<"������� ������ ��������: "; 
cin>>size; 
for (int i = 0; i<size; i++)
{
	cout<<endl<< "������� �����������: "; 
	cin>>mas[i][0]; 
	cout<<"������� ������� �: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable * 100; 
	cout<<"������� ������� y: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable * 10; 
	cout<<"������� ������� z: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable; 
	mas[i][1] = step; 
} 
TPolynom polinom(mas, size); 
int comand; 
for (;;) 
{ 
	cout<<"\n";
	cout<<"1. ������� ������� �� ����� \n";
	cout<<"2. �������� ����� \n";
	cout<<"3. ������� ��� �������� \n";
	cout<<"4. ����� �� ��������� \n";
	cout<<"������ �������: "; 
	cin>>comand; 
	switch (comand) 
	{ 
	case 1: 
		{ 
			cout<<polinom;
			break;
		} 
	case 2: 
		{ 
			int mas1[1][2] = {0};
			cout<<endl<< "������� �����������: "; 
			cin>>mas1[0][0];
			cout<<"������� ������� x: ";
			cin>>StepOfVariable;
			step = StepOfVariable*100;
			cout<<"������� ������� y: ";
			cin>>StepOfVariable;
			step += StepOfVariable*10;
			cout<<"������� ������� z: ";
			cin>>StepOfVariable;
			step += StepOfVariable;
			mas1[0][1] = step;
			TPolynom monom(mas1, 1);
			polinom+=monom;
			cout<<polinom;
			break;
		} 
	case 3:
		{
			int mas2[][2] = { NULL }; 
			cout<<"������� ������ ��������: "; 
			cin>>size;
			for (int i = 0; i<size; i++)
			{
				cout<<endl<< "������� �����������: "; 
				cin>>mas2[i][0]; 
				cout<<"������� ������� �: "; 
				cin>>StepOfVariable; 
				step = StepOfVariable * 100; 
				cout<<"������� ������� y: "; 
				cin>>StepOfVariable; 
				step += StepOfVariable * 10; 
				cout<<"������� ������� z: "; 
				cin>>StepOfVariable; 
				step += StepOfVariable; 
				mas2[i][1] = step;
			} 
			TPolynom polinom2(mas2, size);
			polinom+=polinom2;
			cout<<polinom;
		}


	case 4: 
		exit(1); 
	default:
		break; 
	} 
} 
}










	
	
	
	
	
	
	
	
	
	
	
	
	
	/*for (int i = 0; i < Size; i++)
	{
		cout<<"������� ������� x: ";
	    cin>>x;
		cout<<"������� ������� y: ";
	    cin>>y;
		cout<<"������� ������� z: ";
	    cin>>z;
	    _power = x*100+y*10+z;
		cout<<"������� ����������� ������: ";
		cin>>_coeff;
		TMonom({
	}
}
*/ 