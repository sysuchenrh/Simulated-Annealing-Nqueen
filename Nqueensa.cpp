#include<iostream>
#include<cmath>

using namespace std;
//(N，Tmax) (500,8000) (100,8000)
const int N =200;
double Tmax =8000;
double Tmin =1e-100;
float alpha =0.99;
int position[N+1];
int times =100;
float T;
int k=0;
int test(int col[]){
    int COUNT =0;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            if(abs(i-j)==abs(col[i]-col[j])){
                COUNT++;
            }
        }
    }
    return COUNT;
}

void output(){
    cout<<"第N个数表示在第N行，数字代表所在列号："<<endl;
    for(int i=1;i<=N;i++){
        cout<<position[i]<<" ";
    }
    k++;
}

void initpos(){
    for(int i =0;i<=N;i++){
        position[i]=i;
    }
}

void sa(){
    int temp1,temp2;
    int t1,t2,t3;
    int posnew[N+1];
    int cnum_new;
    int cnum =test(position);
    float r;
    float p;
    int f,cnum_temp;
    for(int i =0;i<times;i++){
        f=0;
        if(i>0) Tmax =2;
        T =Tmax;
        if(cnum  ==0){
            break;
        }
        while(T>Tmin){
        //    if(cnum<4){

        //  }
        //else if(f==300){
            //  T=0.1;
        //}
            if(cnum==0){
                output();
                break;
            }
            else{
                t1 = rand()%N+1;
                t2 = rand()%N+1;
                t3 = rand()%N+1;
                if(t1!=t2&&t1!=t3&&t2!=t3){
                    for(int j=0;j<=N;j++){
                            posnew[j]=position[j];
                        }
                    temp1 =posnew[t1];
                    temp2 =posnew[t2];
                    posnew[t1]=posnew[t3];
                    posnew[t2]=temp1;
                    posnew[t3]=temp2;
                    cnum_new =test(posnew);
                    cnum_temp =cnum;
                    if(cnum_new<cnum){
                        for(int j=0;j<=N;j++){
                            position[j]=posnew[j];
                            f=0;
                        }
                        cnum = cnum_new;
                    }
                    else{
                        r=(rand()%1000)/(float)1000;
                        p=exp((cnum - cnum_new) / (T));
                        if(p>r){
                            for(int j=0;j<=N;j++){
                                position[j]=posnew[j];
                            }
                            f=0;
                            cnum = cnum_new;
                        }
                    }
                    if(cnum_temp==cnum){
                        f++;
                    }
                    //cout<<"迭代："<<i<<" 温度:"<<T<<" 冲突数:"<<cnum<<endl;
                    T =alpha*T;
                }
            }
        }
       //cout<<"迭代："<<i<<" 冲突数:"<<cnum<<endl;
    }
}

int main(){
    initpos();
    sa();
    if(k==0){
        printf("未找到");
    }
    return 0;
}
