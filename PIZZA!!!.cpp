#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int ICT_Pizza_data[10000][5];
void ICT_Pizza_QUIT(int seq)
{
    int top[7]={0},size[4]={0},thickness[3]={0};
    float totalTop=0,totalSize=seq,totalThick=seq;
    for (int i=0; i<=seq; i++) {
        size[ICT_Pizza_data[i][0]]++;
        thickness[ICT_Pizza_data[i][1]]++;
        top[ICT_Pizza_data[i][2]]++;
        top[ICT_Pizza_data[i][3]]++;
        top[ICT_Pizza_data[i][4]]++;
    }
    for (int i=1; i<=6; i++) {
        totalTop+=top[i];
    }
    cout<<"Size SMALL orders:"<<size[1]<<"("<<100.0*size[1]/totalSize<<"%)"<<endl;
    cout<<"Size MED orders:"<<size[2]<<"("<<100.0*size[2]/totalSize<<"%)"<<endl;
    cout<<"Size BIG orders:"<<size[3]<<"("<<100.0*size[3]/totalSize<<"%)"<<endl;
    cout<<"Thick THIN orders:"<<thickness[1]<<"("<<100.0*thickness[1]/totalThick<<"%)"<<endl;
    cout<<"Thick THICK orders:"<<thickness[2]<<"("<<100.0*thickness[2]/totalThick<<"%)"<<endl;
    for (int i=1; i<=6; i++) {
        cout<<"Topping "<<i<<" orders:"<<top[i]<<"("<<100.0*top[i]/totalTop<<"%)"<<endl;
    }
    cout<<endl;
}

void ICT_Pizza_1()
{
    int input1,input2,input3;
    int topping[3];
    int exec;
    int sequenceNum=0;
    while (true) {
        memset(topping, 0, sizeof(topping));
        cout<<"SIZE from 1-3: ";
        cin>>input1;
        cout<<"CRUST THICKNESS from 1-2: ";
        cin>>input2;
        cout<<"TOPPING COUNT From 1-3: ";
        cin>>input3;
        for (int i=0; i<input3; i++) {
            cout<<"TOPPING "<<i+1<<" from 1-6: ";
            cin>>topping[i];
        }
        cout<<input1<<" "<<input2<<" ";
        for (int i=0; i<input3; i++) {
            cout<<topping[i]<<" ";
        }
        cout<<endl<<"Correct? (Yes=1,No=2,Quit=3)";
        cin>>exec;
        if (exec==1) {
            ICT_Pizza_data[sequenceNum][0]=input1;
            ICT_Pizza_data[sequenceNum][1]=input2;
            ICT_Pizza_data[sequenceNum][2]=topping[0];
            ICT_Pizza_data[sequenceNum][3]=topping[1];
            ICT_Pizza_data[sequenceNum][4]=topping[2];
            cout<<sequenceNum<<endl;
            sequenceNum++;
        }
        if (exec==2) {
            continue;
        }
        if (exec==3) {
            cout<<"THX(?) for using this program?"<<endl;
            ICT_Pizza_QUIT(sequenceNum);
            return;
        }
        cout<<"MORE PIZZA PARTY(1=YES,2=NO): ";
        cin>>exec;
        if (exec==1) {
            continue;
        }
        if (exec==2) {
            cout<<"THX(?) for using this program?"<<endl;
            ICT_Pizza_QUIT(sequenceNum);
            return;
        }
    }
}

int main()
{
    ICT_Pizza_1();
    return 0;
}
