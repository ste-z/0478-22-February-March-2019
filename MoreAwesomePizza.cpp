#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int ICT_Pizza_data[1000][104]; //Final "Quit program" data
string toppingstring[100] = {"0", "Pepperoni", "Chicken", "Extra Cheese", "Mushrooms", "Spinach", "Olives"};
string sizestring[50] = {"0", "Small", "Medium", "Big"};
string thicknessstring[50] = {"0", "Thin", "Thick"};
int toppinglimit=3;
int toppingtop=3;
int toppingcount=6;
int sizecount=3;
int thicknesscount=2;
void ICT_Pizza_QUIT(int seq)
{
    int top[toppingcount+50],size[sizecount+50],thickness[thicknesscount+50];
    memset(top,0,sizeof(top));
    memset(size,0,sizeof(size));
    memset(thickness,0,sizeof(thickness));
    float totalTop=0,totalSize=seq,totalThick=seq;
    for (int i=0; i<=seq; i++) {
        size[ICT_Pizza_data[i][0]]++;
        thickness[ICT_Pizza_data[i][1]]++;
        for (int j=2; j<=toppingtop+2; j++)
        {        	
        	top[ICT_Pizza_data[i][j]]++;
        }
    }
    for (int i=1; i<=toppingcount; i++) {
        totalTop+=top[i];
    }
    for (int i=1; i<=sizecount; i++)
    {
    	cout<<"Size "<<sizestring[i]<<" orders:"<<size[i]<<"("<<100.0*size[i]/totalSize<<"%)"<<endl;
    }
    for (int i=1; i<=thicknesscount; i++)
    {
    	cout<<"Thick "<<sizestring[i]<<" orders:"<<thickness[i]<<"("<<100.0*thickness[i]/totalThick<<"%)"<<endl;
    }
    for (int i=1; i<=toppingcount; i++) {
        cout<<"Topping "<<toppingstring[i]<<" orders:"<<top[i]<<"("<<100.0*top[i]/totalTop<<"%)"<<endl;
    }
    cout<<endl;
}
string correctpwd="1234";
void ICT_Pizza_Init()
{
	cout<<"---------------\n";
	cout<<"Create Passcode(Press \"Enter\" to confirm):";
	string tmppwd;
	string tmppwd2;
	getline(cin,tmppwd);
	cout<<"Enter the Passcode again(Press \"Enter\" to confirm):";
	getline(cin,tmppwd2);
	if (tmppwd==tmppwd2)
	{
		correctpwd=tmppwd;
	} else {
		while (tmppwd!=tmppwd2) {
			cout<<"Passcode do not match. Again(Press \"Enter\" to confirm):";
			getline(cin,tmppwd);
			cout<<"Enter the Passcode again(Press \"Enter\" to confirm):";
			getline(cin,tmppwd2);
		}
		correctpwd=tmppwd;
	}
	cout<<"---------------\n";
}

void ICT_Pizza_CtrlPanel_exec1(){
	int seclayer;
	cout<<"---------------\n";
	cout<<"1. Change Topping Count\n2. Change Topping Selection\n3. Change Topping Limitations\n4. Show Current Toppings\n";
	cout<<"---------------\nCommand:";
	cin>>seclayer;
	if (seclayer==1)
	{
		cout<<"---------------\n";
		cout<<"How much topping selections:";
		cin>>toppingcount;
		cout<<"Configuration Complete\n";
		cout<<"---------------\n";
	}
	if (seclayer==2)
	{
		cout<<"---------------\n";
		for (int i=1; i<=toppingcount; i++) {
           	cout<<i<<". "<<toppingstring[i]<<"\n";
       	}
       	cout<<"---------------\n";
       	cout<<"---------------\n";
		cout<<"Delete Topping or Change Topping?";
		string thirdlayer;
		cin>>thirdlayer;
		if (thirdlayer=="delete")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			toppingstring[config]="0";
			cout<<"Configuration Complete (Change another one up to prevent shattered menu)\n";
			cout<<"---------------\n";
		}
		if (thirdlayer=="Change")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			string change;
			cout<<"Change to:";
			cin>>change;
			toppingstring[config]=change;
			cout<<"Configuration Complete\n";
			cout<<"---------------\n";
		}
	}
	if (seclayer==3)
	{
		cout<<"---------------\n";
		cout<<"How much toppings at a time:";
		cin>>toppinglimit;
		if (toppinglimit>toppingtop)
		{
			toppingtop=toppinglimit;
		}
		cout<<"Configuration Complete\n";
		cout<<"---------------\n";
	}
	if (seclayer==4)
	{
		cout<<"---------------\n";
		for (int i=1; i<=toppingcount; i++) {
           	cout<<i<<". "<<toppingstring[i]<<"\n";
       	}
       	cout<<"---------------\n";
       	cout<<"Limit:"<<toppinglimit<<", TotalCount:"<<toppingcount<<endl;
       	cout<<"---------------\n";
	}
}

void ICT_Pizza_CtrlPanel_exec2(){
	int seclayer;
	cout<<"---------------\n";
	cout<<"1. Change Size Count\n2. Change Size Selection\n3. Show Size Toppings\n";
	cout<<"---------------\nCommand:";
	cin>>seclayer;
	if (seclayer==1)
	{
		cout<<"---------------\n";
		cout<<"How much size selections:";
		cin>>sizecount;
		cout<<"Configuration Complete\n";
		cout<<"---------------\n";
	}
	if (seclayer==2)
	{
		cout<<"---------------\n";
		for (int i=1; i<=sizecount; i++) {
           	cout<<i<<". "<<sizestring[i]<<"\n";
       	}
       	cout<<"---------------\n";
       	cout<<"---------------\n";
		cout<<"Delete Size or Change Size?";
		string thirdlayer;
		cin>>thirdlayer;
		if (thirdlayer=="delete")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			sizestring[config]="0";
			cout<<"Configuration Complete (Change another one up to prevent shattered menu)\n";
			cout<<"---------------\n";
		}
		if (thirdlayer=="Change")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			string change;
			cout<<"Change to:";
			cin>>change;
			sizestring[config]=change;
			cout<<"Configuration Complete\n";
			cout<<"---------------\n";
		}
	}
	if (seclayer==3)
	{
		cout<<"---------------\n";
		for (int i=1; i<=sizecount; i++) {
           	cout<<i<<". "<<sizestring[i]<<"\n";
       	}
       	cout<<"---------------\n";
	}
}

void ICT_Pizza_CtrlPanel_exec3(){
	int seclayer;
	cout<<"---------------\n";
	cout<<"1. Change Thickness Count\n2. Change Thickness Selection\n3. Show Thickness Toppings\n";
	cout<<"---------------\nCommand:";
	cin>>seclayer;
	if (seclayer==1)
	{
		cout<<"---------------\n";
		cout<<"How much thickness selections:";
		cin>>thicknesscount;
		cout<<"Configuration Complete\n";
		cout<<"---------------\n";
	}
	if (seclayer==2)
	{
		cout<<"---------------\n";
		for (int i=1; i<=thicknesscount; i++) {
           	cout<<i<<". "<<thicknessstring[i]<<"\n";
       	}
       	cout<<"---------------\n";
       	cout<<"---------------\n";
		cout<<"Delete thickness or Change thickness?";
		cout<<"---------------\nCommand(delete/change):";
		string thirdlayer;
		cin>>thirdlayer;
		if (thirdlayer=="delete")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			sizestring[config]="0";
			cout<<"Configuration Complete (Change another one up to prevent shattered menu)\n";
			cout<<"---------------\n";
		}
		if (thirdlayer=="Change")
		{
			cout<<"---------------\n";
			int config;
			cout<<"Which one:";
			cin>>config;
			string change;
			cout<<"Change to:";
			cin>>change;
			thicknessstring[config]=change;
			cout<<"Configuration Complete\n";
			cout<<"---------------\n";
		}
	}
	if (seclayer==3)
	{
		cout<<"---------------\n";
		for (int i=1; i<=thicknesscount; i++) {
           	cout<<i<<". "<<thicknessstring[i]<<"\n";
       	}
       	cout<<"---------------\n";
	}
}

void ICT_Pizza_CtrlPanel()
{
	cout<<"---------------\n";
	cout<<" Control Panel \n";
	cout<<"---------------\n";
	while (true) {
		cout<<"What do u need? \n1. Change Toppings\n2. Change Sizes\n3. Change Thickness\n4. Change Passcode\n5. Quit\nCommand:";
		int ctrlexec;
		cin>>ctrlexec;
		cout<<"---------------\n";
		if (ctrlexec==4)
		{
			ICT_Pizza_Init();
		}
		if (ctrlexec==1)
		{
			ICT_Pizza_CtrlPanel_exec1();
		}
		if (ctrlexec==2)
		{
			ICT_Pizza_CtrlPanel_exec2();
		}
		if (ctrlexec==3)
		{
			ICT_Pizza_CtrlPanel_exec3();
		}
		if (ctrlexec==5)
		{
			return;
		}
	}
}

void ICT_Pizza_1()
{
	cout<<"PIZZA PROGRAM \n";
	ICT_Pizza_Init();
	int input1,input2,input3;
    int topping[toppinglimit];
    int exec;
    int sequenceNum=0;
    while (true) {
        memset(topping, 0, sizeof(topping));
        cout<<"Please? Select pizza SIZE (";
        for (int i=1; i<=sizecount; i++)
        {
            cout<<i<<": "<<sizestring[i]<<", ";
        }
        cout<<"):"<<endl;
        cin>>input1;
        cout<<"Please? Select pizza CRUST thickness (";
        for (int i=1; i<=thicknesscount; i++)
        {
            cout<<i<<": "<<thicknessstring[i]<<", ";
        }
        cout<<"):"<<endl;
        cin>>input2;
        cout<<"Please? Select pizza Topping required (from 1 to "<<toppinglimit<<"):";
        cin>>input3;
        while (input3>toppinglimit) {
            cout<<"TOO MUCH toppings, get another one:";
            cin>>input3;
        }
        cout<<"Topping Menu:\n";
        for (int i=1; i<=toppingcount; i++) {
        	if (toppingstring[i]!="0")
        	{
        		cout<<i<<". "<<toppingstring[i]<<"\n";
        	}
        }
        for (int i=0; i<input3; i++) {
            cout<<"Select topping "<<i+1<<" (enter 1-"<<toppingcount<<"):";
            cin>>topping[i];
        }
        cout<<sizestring[input1]<<" "<<thicknessstring[input2]<<" ";
        for (int i=0; i<input3; i++) {
            cout<<toppingstring[topping[i]]<<" ";
        }
        cout<<endl<<"Confirm? (Yes=1,No=2,Quit=3)";
        cin>>exec;
        if (exec==1) {
            ICT_Pizza_data[sequenceNum][0]=input1;
            ICT_Pizza_data[sequenceNum][1]=input2;
            for (int i=0; i<toppinglimit; i++)
            {
            	ICT_Pizza_data[sequenceNum][i+2]=topping[i];
            }
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
        cout<<"MORE PIZZA PARTY(1=YES,2=NO,3=Admin): ";
        cin>>exec;
        if (exec==1) {
            continue;
        }
        if (exec==2) {
            cout<<"THX(?) for using this program?"<<endl;
            ICT_Pizza_QUIT(sequenceNum);
            return;
        }
        if (exec==3)
        {
        	cout<<"Passcode(Press \"Enter\" to confirm): ";
        	string pass;
        	getline(cin,pass);
        	while (pass!=correctpwd) {
        		cout<<"Passcode Incorrect, Again?\n(The program will stuck here until correct passcode is inputed)(Press \"Enter\" to confirm):";
        		getline(cin,pass);
        	}
        	ICT_Pizza_CtrlPanel();
        }
    }
}

int main()
{
    ICT_Pizza_1();
    return 0;
}
