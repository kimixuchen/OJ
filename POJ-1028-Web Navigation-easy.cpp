/**
 *POJ-1028-Web Navigation
 *xuchen
 *2015-11-20 19:46:10
**/
#include "stdio.h"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

string s;
stack<string> backwordStack;
stack<string> forwardStack;

int main()
{
	char command[10];
	string cur = "http://www.acm.org/";
	string url;
	while(scanf("%s", command) && command[0]!='Q')
	{
		switch(command[0]){
			
			case 'B':
				if(backwordStack.empty())
				{
					printf("Ignored\n");
				}
				else
				{
					forwardStack.push(cur);
					cur = backwordStack.top();
					backwordStack.pop();
					cout<<cur<<endl;
				}
				break;
			case 'F':
				if(forwardStack.empty())
				{
					printf("Ignored\n");
				}
				else
				{
					backwordStack.push(cur);
					cur = forwardStack.top();
					forwardStack.pop();
					cout<<cur<<endl;
				}
				break;
			case 'V':
				cin>>url;
				backwordStack.push(cur);
				cur = url;
				while(!forwardStack.empty())
					forwardStack.pop();
				cout<<cur<<endl;
				break;
		}
	}
	return 0;
}
