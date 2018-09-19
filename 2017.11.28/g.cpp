/*
思路：版本号根据小数点分成几个string，每个string里面包含了数字和字母，数字的话比如123，不能作为字符串直接一个一个来比较，需要转化为数字来比较，比如123b>23b,
也就是说切成string之后还需要把每个strig切成数字加字母的形式，我的程序中数字和字母可以任意混合起来比较。另外应该还可以写递归得出结果

 */


#include<bits/stdc++.h>
#define BIGGER 1
#define SMALLER 2
#define EQUAL 3
using namespace std;
int comper_string(string a,string b){
	int i;
	std::vector<int> v1,v2;
	i=0;
	int num=0;
	while(i<a.size()){
		if(a[i]>='0'&&a[i]<='9'){
			if(i>0&&a[i-1]>='a'&&a[i-1]<='z'){
				v1.push_back(num);
				num=0;
			}
			num*=10;
			num+=a[i]-'0';
		}
		else{
			if(i>0){
				v1.push_back(num);
			}
			num=a[i];//ASCII 字符转数字
		}
		i++;
	}
	v1.push_back(num);

	i=0;
	num=0;
	while(i<b.size()){
		if(b[i]>='0'&&b[i]<='9'){
			if(i>0&&b[i-1]>='a'&&b[i-1]<='z'){
				v2.push_back(num);
				num=0;
			}
			num*=10;
			num+=b[i]-'0';
		}
		else{
			if(i>0){
				v2.push_back(num);
			}
			num=b[i];//ASCII 字符转数字
		}
		i++;
	}
	v2.push_back(num);
	while(i<v1.size()||i<v2.size()){
		if(i<v1.size()&&i<v2.size()){
			if(v1[i]<v2[i]){
				return SMALLER;
			}
			else if(v1[i]>v2[i]){
				return BIGGER;
			}
			else{
				i++;
			}
		}
		else if(i<v1.size()&&i>v2.size()){
			return BIGGER;
		}
		else if(i>v1.size()&&i<v2.size()){
			return SMALLER;
		}
		else{
			i++;
		}
	}
	return EQUAL;
}

int compare(string s1,string s2){
	std::vector<string > v1,v2;
	int i=0;
	string tmp;
	tmp="";
	while(i<s1.size()){
		if(s1[i]!='.'){
			tmp+=s1[i];
		}
		else{
			v1.push_back(tmp);
			tmp="";
		}
		i++;
	}
	i=0;
	tmp="";
	while(i<s2.size()){
		if(s2[i]!='.'){
			tmp+=s2[i];
		}
		else{
			v2.push_back(tmp);
			tmp="";
		}
		i++;
	}
	int flag=0;
	i=0;
	while(i<v1.size()||i<v2.size()){
		if(i<v1.size()&&i<v2.size()){
			int res=comper_string(v1[i],v2[i]);
			if(res==EQUAL){
				i++;
			}
			else{
				return res;
			}
		}
		else if(i>=v1.size()&&i<v2.size()){
				return SMALLER;
		}
		else if(i<v1.size()&&i>=v2.size()){
				return BIGGER;
		}
		else{
				return EQUAL;
		}
	}
	return EQUAL;
}

int main(){
    printf("%d\n",compare("1.2.3a","1.2.4b"));
	return 0;
}
