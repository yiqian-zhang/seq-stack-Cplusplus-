#include "Assistance.h"	// ���������
#include "SeqStack.h"	// ˳��ջ��
#include "car.h"

int main(void)
{
    /*char c = '*';
    LinkList<struct Student> la;
    struct Student e;
	int i;*/
    
	char c = '1';
    SeqStack<struct Car> sa;
    struct Car car;
    int x;

    while (c != '0')
	{
        cout << endl << "1. ����ջ.";
        cout << endl << "2. ��ʾջ.";
        cout << endl << "3. ��ջ.";
        cout << endl << "4. ��ջ.";
        cout << endl << "5. ȡջ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c) 	{
			case '1':
				sa.Clear();
				char op;
 				cout << endl << "����c:";
 				do{
                     cin>>car;
                     
                     sa.Push(car);
                     
                     if(sa.FindCar(car)==SUCCESS) sa.Pop(car);
                     
                     cout << endl << "������������룬����n������";
                     cin >> op;
                }while(op!='n'); 
				break;
	       case '2':
				cout << endl;
			    sa.Traverse(Write<struct Car>);
				break;
		   case '3':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> car;
			    if (sa.Push(car) == SUCCESS)
			    {
                       if(sa.FindCar(car)==SUCCESS) sa.Pop(car);
			           else cout << endl << "��ջ�ɹ� ." << endl;
                }
                else
                       cout << endl << "�ռ䲻������ջʧ�� ." << endl;
			    break;
           case '4':
			    if (sa.Pop(car) == SUCCESS)
			           cout << endl << "ջ��Ԫ��ֵΪ " << car << " ." << endl;
                else
                       cout << endl << "ջΪ�ա� " << endl;
			    break;
           case '5':
			    if (sa.Top(car) == SUCCESS)
			           cout << endl << "ջ��Ԫ��ֵΪ " << car << " ." << endl;
                else
                       cout << endl << "ջΪ�ա� " << endl;
			    break;
		}
	}

	system("PAUSE"); 
	return 0;    
}


