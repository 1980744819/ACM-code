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
    cout<<"����"<<a1.getname()<<"����������: "<<endl;
    cout<<"����:"<<a1.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'Ů':'��'<<endl;
    printf("�Ա�:");
    if(a1.getsex()=='f')
        printf("Ů\n");
    else
        printf("��\n");
    cout<<"����:"<<a1.getage()<<endl;
    cout<<"����:";
    printf("%.2f\n",a1.getweight());
    //cout<<""<<a1.getal()==true?'��':'��'<<endl;
    printf("�Ƿ����:");
    if(a1.getal()==true)
        printf("��\n");
    else
        printf("��\n");

    cout<<"����"<<a2.getname()<<"����������: "<<endl;
    cout<<"����:"<<a2.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'Ů':'��'<<endl;
    printf("�Ա�:");
    if(a2.getsex()=='f')
        printf("Ů\n");
    else
        printf("��\n");
    cout<<"����:"<<a2.getage()<<endl;
    cout<<"����:";
    printf("%.2f\n",a2.getweight());
    //cout<<""<<a1.getal()==true?'��':'��'<<endl;
    printf("�Ƿ����:");
    if(a2.getal()==true)
        printf("��\n");
    else
        printf("��\n");

    cout<<"����"<<a3.getname()<<"����������: "<<endl;
    cout<<"����:"<<a3.getname()<<endl;
    //cout<<""<<a1.getsex()=='f'?'Ů':'��'<<endl;
    printf("�Ա�:");
    if(a3.getsex()=='f')
        printf("Ů\n");
    else
        printf("��\n");
    cout<<"����:"<<a3.getage()<<endl;
    cout<<"����:";
    printf("%.2f\n",a3.getweight());
    //cout<<""<<a1.getal()==true?'��':'��'<<endl;
    printf("�Ƿ����:");
    if(a3.getal()==true)
        printf("��\n");
    else
        printf("��\n");
    return 0;
}
