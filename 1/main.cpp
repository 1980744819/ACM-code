#include <iostream>

const int N=13;
int a[N];
void print();
bool can_place(int column,int row);
int cnt;
inline void place(int column,int row)
{
    a[column]=row;
}

inline int abs(int x)
{
    return x<0?-x:x;
}

void EightQueen(int column)
{
    if(column==N)
        print();
    else{
        for(int i=0;i!=N;++i)
            if(can_place(column,i))
            {
                place(column,i);
                EightQueen(column+1);
            }
    }
}

void print()
{
    ++cnt;
}

bool can_place(int column,int row)
{
    for(int j=0;j!=column;++j)
    {
        if(a[j]==row)
            return false;
        if((column-j)==abs(a[j]-row))
            return false;
    }
    return true;
}

int main()
{
    for(int i=0;i!=N;i++)
    {
        a[0]=i;
        EightQueen(1);
    }
    std::cout<<cnt<<std::endl;
}

