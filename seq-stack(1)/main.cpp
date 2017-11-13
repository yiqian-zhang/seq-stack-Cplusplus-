#include "Assistance.h"	// 辅助软件包
#include "SeqStack.h"	// 顺序栈类
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
        cout << endl << "1. 生成栈.";
        cout << endl << "2. 显示栈.";
        cout << endl << "3. 入栈.";
        cout << endl << "4. 出栈.";
        cout << endl << "5. 取栈顶.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~5):";
		cin >> c;
		switch (c) 	{
			case '1':
				sa.Clear();
				char op;
 				cout << endl << "输入c:";
 				do{
                     cin>>car;
                     
                     sa.Push(car);
                     
                     if(sa.FindCar(car)==SUCCESS) sa.Pop(car);
                     
                     cout << endl << "任意键继续输入，输入n结束。";
                     cin >> op;
                }while(op!='n'); 
				break;
	       case '2':
				cout << endl;
			    sa.Traverse(Write<struct Car>);
				break;
		   case '3':
			    cout << endl << "输入元素值:";
			    cin >> car;
			    if (sa.Push(car) == SUCCESS)
			    {
                       if(sa.FindCar(car)==SUCCESS) sa.Pop(car);
			           else cout << endl << "入栈成功 ." << endl;
                }
                else
                       cout << endl << "空间不够，入栈失败 ." << endl;
			    break;
           case '4':
			    if (sa.Pop(car) == SUCCESS)
			           cout << endl << "栈顶元素值为 " << car << " ." << endl;
                else
                       cout << endl << "栈为空。 " << endl;
			    break;
           case '5':
			    if (sa.Top(car) == SUCCESS)
			           cout << endl << "栈顶元素值为 " << car << " ." << endl;
                else
                       cout << endl << "栈为空。 " << endl;
			    break;
		}
	}

	system("PAUSE"); 
	return 0;    
}


