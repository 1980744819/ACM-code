#include<stdio.h>
#include<string.h>
#define SIZE 11000
char dic[SIZE][20];
int cnt;
void read_dic()//读取字典
{
     cnt = 0;
     while(scanf("%s%*c",dic[cnt]))
     {
        if(dic[cnt][0]=='#')
        break;
        else
        cnt++;
     }
}
bool isCor(char *str)//是否正确
{
     int i;
     for(i=0;i<cnt;i++)
     if(strcmp(dic[i],str)==0)return true;
     return false;
}
void Replace(char *str)//替换
{
     printf("%s:",str);
     int i,j,k,arr[20],diff,isSort;
     int ls = strlen(str),ld;
     for(i=0;i<cnt;i++)
     {
        ld = strlen(dic[i]);
        if(ls==ld)//如果长度相同
        {
            diff = 0;
            for(j=0;j<ld;j++)
            {
               if(str[j]!=dic[i][j]) diff++;
            }
            if(diff==1)printf(" %s",dic[i]);
        }
        else if(ls==ld+1)//delete
        {
            memset(arr,-1,sizeof(arr));
            for(j=0;j<ld;j++)
            {
               for(k=j==0?0:arr[j-1]+1;k<ls;k++)
               {
                  if(str[k]==dic[i][j])
                  {
                      arr[j] = k;
                      break;
                  }
               }
            }
            isSort = 1;
            //检查arr是否有序
            for(j=0;j<ld-1;j++)
            {
               if(arr[j+1]<arr[j]||arr[j]==-1)
               {
                  isSort = 0;
                  break;
               }
            }
            if(arr[ld-1]==-1)isSort = 0;
            if(isSort)printf(" %s",dic[i]);
        }
        else if(ls+1==ld)//add
        {
            memset(arr,-1,sizeof(arr));
            for(j=0;j<ls;j++)
            {
               for(k=j==0?0:arr[j-1]+1;k<ld;k++)
               {
                  if(str[j]==dic[i][k])
                  {
                      arr[j] = k;
                      break;
                  }
               }
            }
            isSort = 1;
            //检查arr是否有序
            for(j=0;j<ls-1;j++)
            {
               if(arr[j+1]<arr[j]||arr[j]==-1)
               {
                  isSort = 0;
                  break;
               }
            }
            if(arr[ls-1]==-1)isSort = 0;
            if(isSort)printf(" %s",dic[i]);
        }
     }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    read_dic();
    char str[20];
    while(scanf("%s%*c",str),str[0]!='#')
    {
        if(isCor(str))
        printf("%s is correct\n",str);
        else
        {
           Replace(str);
           printf("\n");
        }
    }
}


