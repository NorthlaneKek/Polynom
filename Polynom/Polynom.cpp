// Polynom.cpp: определяет точку входа для консольного приложения.
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
cout<<"Введите размер полинома: "; 
cin>>size; 
for (int i = 0; i<size; i++)
{
	cout<<endl<< "Введите коэффициент: "; 
	cin>>mas[i][0]; 
	cout<<"Введите степень х: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable * 100; 
	cout<<"Введите степень y: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable * 10; 
	cout<<"Введите степень z: "; 
	cin>>StepOfVariable; 
	step += StepOfVariable; 
	mas[i][1] = step; 
} 
TPolynom polinom(mas, size); 
int comand; 
for (;;) 
{ 
	cout<<"\n";
	cout<<"1. Вывести полином на экран \n";
	cout<<"2. Добавить моном \n";
	cout<<"3. Сложить два полинома \n";
	cout<<"4. Выйти из программы \n";
	cout<<"Ввести команду: "; 
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
			cout<<endl<< "Введите коэффициент: "; 
			cin>>mas1[0][0];
			cout<<"Введите степень x: ";
			cin>>StepOfVariable;
			step = StepOfVariable*100;
			cout<<"Введите степень y: ";
			cin>>StepOfVariable;
			step += StepOfVariable*10;
			cout<<"Введите степень z: ";
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
			cout<<"Введите размер полинома: "; 
			cin>>size;
			for (int i = 0; i<size; i++)
			{
				cout<<endl<< "Введите коэффициент: "; 
				cin>>mas2[i][0]; 
				cout<<"Введите степень х: "; 
				cin>>StepOfVariable; 
				step = StepOfVariable * 100; 
				cout<<"Введите степень y: "; 
				cin>>StepOfVariable; 
				step += StepOfVariable * 10; 
				cout<<"Введите степень z: "; 
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
		cout<<"Введите степень x: ";
	    cin>>x;
		cout<<"Введите степень y: ";
	    cin>>y;
		cout<<"Введите степень z: ";
	    cin>>z;
	    _power = x*100+y*10+z;
		cout<<"Введите коэффициент монома: ";
		cin>>_coeff;
		TMonom({
	}
}
*/ 