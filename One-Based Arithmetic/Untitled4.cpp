#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insert(int q,int r,int a[100],int p,int b[101]){
    int i;
    for(i=0;i<p;i++){
        if(i<=r-1){
            b[i]=a[i];
        }
        else{
            break;
        }
    }
    for(i=r;i<p;i++){
        b[i+1]=a[i];
    }
    b[r]=q;
    for(i=0;i<=p;i++){
        printf("%d",b[i]);
    }
}
void add(int q,int a[100],int p,int b[101]){
    int i;
    for(i=0;i<p;i++){
        b[i]=a[i];
    }
    b[p]=q;
    for(i=0;i<=p;i++){
        printf("%d\n",b[i]);
    }
}
void del(int q,int a[100],int p,int b[101]){
    int i;
    for(i=0;i<p;i++){
        if(a[i]!=q){
				b[i]=a[i];
        }
        else{
            break;
        }
    }
    for(i=0;i<p-1;i++){
        b[i]=a[i+1];
    }
    for(i=0;i<p-1;i++){
        printf("%d",b[i]);
    }
}
void rank(int q,int a[100],int p){
    int i,j,temp;
    if(q==1){
    	for (j = 0; j < p - 1; j++){
            for (i = 0; i < p - 1 - j; i++){
                if(a[i] < a[i + 1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
    	}
    }
    else if(q==2){
    	for (j = 0; j < p - 1; j++){
            for (i = 0; i < p - 1 - j; i++){
                if(a[i] > a[i + 1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
    	}
    }
    for(i=0;i<p;i++){
        printf("%d",a[i]);
    }
}
int main()
{
	FILE*fp;
	int n,m,p,a[100],q,r,i,b[101];
	printf("请输入：“1”，添加/插入/删除/排序；“2”，恢复，保存数据运行程序");
	scanf("%d",&n);
	printf("请输入数组长度");
	scanf("%d",&p);
	if(n==1){
		for(i=0;i<p;i++);{
			scanf("%d",&a[i]);
		}
		if((fp=fopen("student.txt","w"))==NULL){
            exit(0);
        }
	    else{
            for(i=0;i<p;i++);{
                fprintf(fp,"%d ",a[i]);
            }
	    }
		fclose(fp);
	}
	else{
		if((fp=fopen("st.txt","r"))==NULL){
            exit(0);
        }
		for(i=0;i<p;i++){
			fscanf(fp,"%d",&a[i]);
		}
	}
    printf("请输入：“1”，添加；“2”，插入；“3”，删除；“4”，排序；");
    scanf("%d",&m);
    if(m==1){
        printf("请输入插入的数");
        scanf("%d",&q);
        add(q,a,p,b);
        for(i=0;i<=p;i++);{
            fprintf(fp,"%d",b[i]);
        }
    }
    else if(m==2){
        printf("请输入插入的数");
        scanf("%d",&q);
        printf("输入插入在第几个数之前");
        scanf("%d",&r);
        insert(q,r,a,p,b);
        for(i=0;i<=p;i++);{
            fprintf(fp,"%d",b[i]);
        }
    }
    else if(m==3){
        printf("输入删除的数:");
        scanf("%d",&q);
        del(q,a,p,b);
        for(i=0;i<p-1;i++);{
            fprintf(fp,"%d",b[i]);
        }
    }
    else if(m==4){
        printf("输入数值：“1”、从大到小；“2”、从小到大；");
        scanf("%d",&q);
        rank(q,a,p);
        for(i=0;i<p;i++);{
            fprintf(fp,"%d",b[i]);
        }
    }
}
