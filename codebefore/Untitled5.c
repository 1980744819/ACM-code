#include <stdio.h>
int main ()
{
	/*�����ֵ����Сֵ�������б�*/
	int i,j,t,max,min,r1,c1,r2,c2;//���Ʊ�������
	int a[3][4]={{4,6,10,28},{7,3,9,11},{32,5,4}};
	max=a[0][0];
	min=a[0][0];//�趨��ֵ���ڱȽ�
	for (i=0;i<3;i++)//ѭ���Ƚ�
		for(j=0;j<4;j++){
			if(a[i][j]>max){
				max=a[i][j];
				r1=i; c1=j; //��¼����
			}
			if(a[i][j]<min){
				min=a[i][j];
				r2=i;	c2=j; //��¼����
			}
		}
	printf("���ֵ:%d,������:%d,������:%d\n",max,r1,c1);
	printf("��Сֵ:%d,������:%d,������:%d\n",min,r2,c2);//������
	/*ȫ����������ð�ݷ�*/
	for(i=0;i<12;i++){//�Ѷ���������ѭ������ȥ����ÿһ������
			for(j=0;j<11;j++){
				if(a[j/4][j%4]>a[(j+1)/4][(j+1)%4]){
					t=a[j/4][j%4];
					a[j/4][j%4]=a[(j+1)/4][(j+1)%4];
					a[(j+1)/4][(j+1)%4]=t;
				} // a[j/(����+1)][j%(����)]���������ȥ����ÿһ������
			}
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			printf("%5d",a[i][j]);//%5d����λ����
			printf("\n");
	} //�������
    return 0;
}