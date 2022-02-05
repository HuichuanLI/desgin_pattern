
#include <iostream>
#include <deque>
#include <stack>
using namespace std;
int main() {
	deque<int> myDeq(3, 100);
	stack<int> myStack;
	stack<int> myStack2(myDeq);
	cout << "myStack Size" << (int)myStack.size() << endl;
	cout << "myStack2 size" << (int)myStack2.size() << endl;
	myStack2.pop();
	cout << "myStack2 size" << (int)myStack2.size() << endl;
	cout << "myStack2 top" << (int)myStack2.top() << endl;
	
	
	system("pause");
	return 0;
}