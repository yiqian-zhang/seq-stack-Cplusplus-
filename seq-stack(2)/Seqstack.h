#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__


// ˳��ջģ����
template<class ElemType>
class SeqStack 
{
protected:
// ˳��ջ�����ݳ�Ա:
	int top;										// ջ��ָ�� 
	int maxSize;									// ջ��������� 
	ElemType *elems;								// Ԫ�ش洢�ռ�

public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SeqStack(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SeqStack();							// ��������
	int GetLength() const;							// ��ջ�ĳ���			 
	bool IsEmpty() const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear();									// ��ջ���
	void Traverse(void (*Visit)(const ElemType &)) const;	// ����ջ
	void Push(const ElemType e);				    // ��ջ
	Status Top(ElemType &e) const;				    // ȡ��Ԫ��
	Status Pop(ElemType &e);					    // ��ջ
	SeqStack(const SeqStack<ElemType> &s);		// ���ƹ��캯��
	SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // ��ֵ�������
	void stackfull(const ElemType &e);
};


// ˳��ջ���ʵ�ֲ���
template<class ElemType>
void SeqStack<ElemType>::stackfull(const ElemType &e)
{
     ElemType *newelems = new ElemType[2*maxSize];
     int count =0;
     for (int i = 0; i <= top; i++)      
		{newelems[i] = elems[i];count++;}
		//cout<<endl<<e;
		
		newelems[count]=e;//cout<<endl<<newelems[count];
		delete []elems;
		maxSize=2*maxSize;
		elems=newelems;
		top++;
}

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top = -1;	
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// �������������ջ
{
	delete []elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
// �������������ջ��Ԫ�ظ���
{
	return top + 1;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	return top == -1;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
// ������������ջ
{
	top = -1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// �����������ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)���� 
{
	for (int i = top; i >=0 ; i--) 
		(*Visit)(elems[i]);
}

template<class ElemType>
void SeqStack<ElemType>::Push(const ElemType e)
{
       if(top==maxSize - 1) {stackfull(e);cout<<"�ռ䲻�㣬����չһ���ռ�";} 
       else elems[++top] = e;
}
/*
template<class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,��ջ����������OVER_FLOW
{
	if (top == maxSize - 1) // ջ����
		return OVER_FLOW;
	else  {	// �����ɹ�
		elems[++top] = e;	// ��Ԫ��e׷�ӵ�ջ�� 
		return SUCCESS;
	}
}
*/
template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
	if(IsEmpty())	 // ջ��
		return UNDER_FLOW;
	else	{ // ջ�ǿ�,�����ɹ�
		e = elems[top];	// ��e����ջ��Ԫ��
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,��������SUCCESS,����
// ��������UNDER_FLOW
{
	if (IsEmpty())	 // ջ��
		return UNDER_FLOW;
	else	{ // �����ɹ�
		e = elems[top--]; // ��e����ջ��Ԫ��
		return SUCCESS;
	}
}

template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s) 
// �����������ջs������ջ--���ƹ��캯��
{
    maxSize = s.maxSize;			    // ջ��������� 
    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
    elems = new ElemType[maxSize];		// ����洢�ռ�
	top = s.top;					    // ����ջ��ָ�� 
	for (int i = 0; i <= top; i++)      // ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
		elems[i] = s.elems[i];
}

template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// �����������ջs��ֵ����ǰջ--��ֵ�������
{
	if (&s != this)	{
	    maxSize = s.maxSize;			    // ջ��������� 
	    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	    elems = new ElemType[maxSize];		// ����洢�ռ�
		top = s.top;					    // ����ջ��ָ�� 
		for (int i = 0; i <= top; i++)		// ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
			elems[i] = s.elems[i];
	}
	return *this;
}

#endif
