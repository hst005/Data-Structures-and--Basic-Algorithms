    #include<iostream>
using namespace std;

class queue{

		//int size=10;
		int ar[10];
		int front,rear;
public:
		queue(){
			front=-1;
			rear=-1;
		}

void enque(int val){
	/*
	if(rear>=10){
		rear=-1;
	}
	if(front>=10){
		front  =-1;
	}
	*/
	if((front<=rear || front==-1) && rear<10 ){
//rear++;
			if(front==-1){
				front++;
				ar[++rear]=val;
			}
			else {
					ar[++rear]=val;
				}
		}
		else
			{
				cout<<"overflow";
			}
}

int deque(){
	if(front==-1 || front>rear){
		return -100;
	}
	else if(front<=rear && front>=0){
		int k;
		k=ar[front];
		front++;
		return k;

	}

}
};

int main(){
	queue q;
	int n;
	cin>>n;
	while(n--){
        int t;
        cin>>t;
        q.enque(t);

	}
	/*q.enque(10);
    q.enque(15);
	q.enque(20);
	q.enque(30);
	q.enque(40);
	*/
	for(int i=0;i<n;i++){
        int k;
        k=q.deque();
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
