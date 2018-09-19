#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=10000;
class patient
{
public:
	patient(string nm,char sx,int ag,float ft,bool all){
		name=nm;
		sex=sx;
		age=ag;
		weight=ft;
		al=all;
	}
	//~patient();
	void setname(string st){
		name=st;
	}
	void setsex(char sx){
		sex=sx;
	}
	void setage(int num){
		age=num;
	}
	void setweight(float ft){
		weight=ft;
	}
	void setal(bool all){
		al=all;
	}
	string getname(){
		return name;
	}
	char getsex(){
		return sex;
	}
	int getage(){
		return age;
	}
	float getweight(){
		return weight;
	}
	bool getal(){
		return al;
	}
private:
	string name;
	char sex;
	int age;
	float weight;
	bool al;

};
int main(){
	// freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);

	patient a1=patient("ZhangLi",'f',a,154.72f,true);
	patient a2=patient("Liu Wu",'m',b,135.00,false);
	patient a3=patient("Zhang san",'f',45,157.57,true);
    cout<<"病人"<<a1.getname()<<"的属性如下: "<<endl;
    cout<<"姓名:"<<a1.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'女':'男'<<endl;
    printf("性别:");
    if(a1.getsex()=='f')
        printf("女\n");
    else
        printf("男\n");
    cout<<"年龄:"<<a1.getage()<<endl;
    cout<<"体重:";
    printf("%.2f\n",a1.getweight());
    //cout<<""<<a1.getal()==true?'是':'否'<<endl;
    printf("是否过敏:");
    if(a1.getal()==true)
        printf("是\n");
    else
        printf("否\n");

    cout<<"病人"<<a2.getname()<<"的属性如下: "<<endl;
    cout<<"姓名:"<<a2.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'女':'男'<<endl;
    printf("性别:");
    if(a2.getsex()=='f')
        printf("女\n");
    else
        printf("男\n");
    cout<<"年龄:"<<a2.getage()<<endl;
    cout<<"体重:";
    printf("%.2f\n",a2.getweight());
    //cout<<""<<a1.getal()==true?'是':'否'<<endl;
    printf("是否过敏:");
    if(a2.getal()==true)
        printf("是\n");
    else
        printf("否\n");

    cout<<"病人"<<a3.getname()<<"的属性如下: "<<endl;
    cout<<"姓名:"<<a3.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'女':'男'<<endl;
    printf("性别:");
    if(a3.getsex()=='f')
        printf("女\n");
    else
        printf("男\n");
    cout<<"年龄:"<<a3.getage()<<endl;
    cout<<"体重:";
    printf("%.2f\n",a3.getweight());
    //cout<<""<<a1.getal()==true?'是':'否'<<endl;
    printf("是否过敏:");
    if(a3.getal()==true)
        printf("是\n");
    else
        printf("否\n");
    return 0;
}
