#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//wrong
class queu{

		//int size=10;
		int ar[5];
		int fron,rear;
public:

		queu(){
			fron=-1;
			rear=-1;

		}

void enque(int val){
	if(rear>=4 && abs(fron-rear)>0){
		rear=-1;
	}

    if(fron>=5 && abs(fron-rear)>0 && abs(fron-rear)<4 && rear>=0){
		fron=-1;
	}
//*/
	if((fron<=rear || fron==-1) && rear<5 ){

			if(fron==rear && rear==-1){
				fron++;
				rear++;
				ar[rear]=val;
				cout<<"front loop excuted value is "<<val<<endl;
				cout<<"now front is "<<fron<<endl<<"now rear is "<<rear<<endl;
			}
			else {
                    rear++;
					ar[rear]=val;

				cout<<"rear loop excuted value is "<<val<<endl;

				cout<<"now front is "<<fron<<endl<<"now rear is "<<rear<<endl;
				}
		}
		else
			{
				cout<<"overflow";
			}
}

void getfrontandrear(){
cout<<"frot is"<<fron<<endl;
cout<<"rear is"<<rear<<endl;
}

int deque(){
	if(fron==-1){
		return -100;
	}
	else if(rear<=0 && fron>=0 && fron<5 && rear<5){
		int k;
		k=ar[fron];
		fron++;
		return k;

	}

}
};

int main(){
	queu q;
	q.enque(10);
	q.enque(15);
	q.enque(20);
	q.enque(30);
	q.enque(40);
	for(int i=0;i<2;i++){
	int k;
	k=q.deque();
	//cout<<k<<endl;
	}

	q.enque(400);
	q.enque(4000);
	q.getfrontandrear();
	for(int i=0;i<5;i++){
	int k=q.deque();
	cout<<k<<endl;
	}
	/*
	q.deque();
	q.deque();
	q.deque();

	q.deque();
	*/
	return 0;
}
