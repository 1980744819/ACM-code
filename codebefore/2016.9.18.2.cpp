#ifndef _CAR_H_
#define _CAR_H_
class Car{
public:
    void run(){
        cout<<"Car run"<<endl;
    }
    void stop(){
        cout<<"Car stop"<<endl;
    }
    void setPropety(int price,int carNum){
        m_price=price;
        m_carNum=carnum;
    }
private:
    int m_price;
    int m_car_Num;
};
#endif // _CAR_H_
