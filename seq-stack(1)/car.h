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
	cout<<"请依次输入车牌号（8个字符），进场时间（年、月、日、时、分、秒）。"<<endl;
    f>>c.number>>c.year>>c.month>>c.day>>c.hour>>c.minute>>c.second;
	
    int cal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(c.year%4==0&&c.year%100!=0||c.year%400==0) cal[2]++;//判断是否闰年 
	
    if(c.month<1||c.month>12){cout<<endl<<"月份不符合要求，请重新输入:" ;f>>c.month;}
	int m=c.month; 
    if(c.day<1||c.day>cal[m]){cout<<endl<<"该月份没有这一天，请重新输入:" ;f>>c.day;}
	
    if(c.hour<0||c.hour>23){cout<<endl<<"时不符合要求，请重新输入:" ;f>>c.hour;}
	if(c.minute<0||c.minute>60){cout<<endl<<"分不符合要求，请重新输入:" ;f>>c.minute;}
    if(c.second<0||c.second>60){cout<<endl<<"秒不符合要求，请重新输入:" ;f>>c.second;}
	return f;
}
#endif
