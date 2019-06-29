#include <iostream>
#include <stack>
#include <string>

using namespace std;
// Q1
void reverse_stack(stack<int>& S, stack<int>& S1, stack<int>& S2)
{
	while (!S.empty()) {
		S1.push(S.top());
		S.pop();
	}
	while (!S1.empty()) {
		S2.push(S1.top());
		S1.pop();
	}
	while (!S2.empty()) {
		S.push(S2.top());
		S2.pop();
	}
}

// Q2
double sum(int i)
{
	double value;
	if(i == 1) {
		value = 1;
		return value;
	}
	else if (i%2 == 0) {
		value = 1.0/i + sum(i-1);
		return value;
	}
	else {
		value = sum(i-1) - 1.0/i;
		return value;
	}
}

// Q3
/*void iterative_call()
{
	string statement = "This was written by call number ";
	int call = 1;
	
	for (; call != 5; ++call) {
		cout << statement << call << endl;
		statement = " " + statement; // adds leading white space
	}
	for (--call; call != 0; --call)
		cout << statement.erase(0,1) << call << endl; // removes leading white space
}*/

// The memoized recursive function for the iterative call
void recursive_call(int call = 1)
{
	static string statement = "This was written by call number ";
	static string a[4];
	static char c = ' ';

	if (a[call-1].empty() && call < 5) {
		a[call-1] = string(call-1, c);
		cout << a[call-1] << statement << call << endl;
		++call;
		recursive_call(call);
		--call;
		cout << a[call-1] << statement << call << endl;	
	}
}

int main()
{
	// Q1 Drivers
	stack<int> S, S1, S2;
	S.push(1), S.push(2), S.push(3);
	cout << "The top element of S is: " << S.top() << endl;
	reverse_stack(S, S1, S2);
	cout << "The top element of S is now: " << S.top() << endl;
	cout << endl;
	// Q2 Drivers
	cout << sum(1) << endl;
	cout << sum(2) << endl;
	cout << sum(3) << endl;
	cout << sum(4) << endl;
	cout << sum(5) << endl;
	cout << sum(200) << endl;
	cout<< endl;
	// Q3 Drivers
	//iterative_call();
	recursive_call();*/

	return 0;
}
