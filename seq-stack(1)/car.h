#ifndef CAR_H_
#define CAR_H_
struct Car{
       char number[10];
       int year;
       int month;
       int day;
       int hour;
       int minute;
       int second;
       };
bool operator!=(const struct Car& c1,const struct Car& c2){
	if (strcmp(c1.number,c2.number)==0)
		return false;
	else return true;
}

ostream& operator<<(ostream& f,const struct Car& c){
	f<<c.number<<"  "<<c.year<<"  "<<c.month<<"  "<<c.day<<"  "<<c.hour<<"  "<<c.minute<<"  "<<c.second<<endl;
	return f;
}

istream& operator>>(istream& f,struct Car& c){
	cout<<"���������복�ƺţ�8���ַ���������ʱ�䣨�ꡢ�¡��ա�ʱ���֡��룩��"<<endl;
    f>>c.number>>c.year>>c.month>>c.day>>c.hour>>c.minute>>c.second;
	
    int cal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(c.year%4==0&&c.year%100!=0||c.year%400==0) cal[2]++;//�ж��Ƿ����� 
	
    if(c.month<1||c.month>12){cout<<endl<<"�·ݲ�����Ҫ������������:" ;f>>c.month;}
	int m=c.month; 
    if(c.day<1||c.day>cal[m]){cout<<endl<<"���·�û����һ�죬����������:" ;f>>c.day;}
	
    if(c.hour<0||c.hour>23){cout<<endl<<"ʱ������Ҫ������������:" ;f>>c.hour;}
	if(c.minute<0||c.minute>60){cout<<endl<<"�ֲ�����Ҫ������������:" ;f>>c.minute;}
    if(c.second<0||c.second>60){cout<<endl<<"�벻����Ҫ������������:" ;f>>c.second;}
	return f;
}
#endif
