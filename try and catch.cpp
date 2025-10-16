#include<iostream>
using namespace std;
int main()
{
	int age;
	cout<<"enter your age:"<<endl;
	cin>>age;
	try{
		if(age>=18)
		{
			cout<<"eligible for voting"<<endl;
		}
		else{
			throw(age);
		}
	}
	catch(int age){
		cout<<"not eligible for voting"<<endl;
		cout<<"your age is:"<<age<<endl;
	}
	return 0;
}
