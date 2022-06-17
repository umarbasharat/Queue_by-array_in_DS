#include<iostream>
using namespace std;

template<typename  T>
class Queue{
	
private:	
	T *data;
	int size,front,rear;

public:
Queue(int s=4)
{
	size=s;
	data=new T[size];
	front=rear=-1;
}

void enque_Rear(T v)
{
	if(Isfull())
	{
		cout<<"The queue is full:"<<endl;
	}
	else
	{
		rear++;
		data[rear]=v;
	}
}

void enque_front(T v)
{
	if(Isfull())
	{
		cout<<"The queue is full:"<<endl;
	}
	else{
	
	int i=rear;
	for(;i>=0;i--)
	{
		data[i+1]=data[i];
	}

	front++;
	data[front]=v;
     front=-1;
 }
}

T deque_front()
{
	T v;
	front++;
	v=data[front];
	return v;
}

T deque_Rear()
{
	T v;
	v=data[rear];
	rear--;
	return v;
}

bool Isfull()
{
 	if(front==-1 && rear==size)
	{
		return true;
	}
	return false;
}

bool IsEmpty()
{
	if(front==-1 && rear==-1)
	{
		return true;
	}
	return false;
}

void MakeEmpty()
{
	front=rear=-1;
}

~Queue()
{
	delete []data;
} 

};


int main()
{
	Queue<int> Q(4);
	char operation;
	int val;
	do {
		cout << "Enter OPTION" << endl;
		cout << "A for adding from front." << endl;
		cout << "B for adding from rear." << endl;
		cout << "C for deleting from front." << endl;
		cout << "D for deleting from rear." << endl;
		cout << "E for exit." << endl;
		cin >> operation;
		switch (operation)
		{
		case 'A':
		case 'a':	
			cout << "Enter value in qeue from front: ";
			cin >> val;
			Q.enque_front(val);
			
			break;
			
		case 'b':
	    case 'B':
			cout << "Enter value in qeue from rear: ";
			cin >> val;
			Q.enque_Rear(val);
		
			break;
		case 'C':  case 'c':
			cout<<"Deque from front :"<<Q.deque_front()<<endl;
	
			break;
		case 'D': case 'd':
			cout<<"Deqeue from rear :"<<Q.deque_Rear()<<endl;
			
			break;
		case 5:
			break;
		default:
			cout << "You entered wrong choice." << endl;
		}
	} while (operation != 'e' || operation!='E');
	return 0;
}
