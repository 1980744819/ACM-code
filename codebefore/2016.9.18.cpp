#include<iostream>
using namespace::std;
class car{
public:
    void run(){
        cout<<"car run"<<endl;
    }
    void stop(){
        cout<<"car stop"<<endl;
    }
    void setProperty(int price,int carNum){
        m_price=price;
        m_carNum=carNum;
    }
private:
    int m_price;
    int m_carNum;
};
int main(){
    car a;
    cout<<sizeof(a)<<endl;
    a.setProperty(10000,10001);
    a.run();
    a.stop();
    return 0;
}
