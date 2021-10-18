#include<bits/stdc++.h>
using namespace std;

void solve(string s, int open, int close){
	if(open == 0 && close == 0){
		cout<<s<<" ";
		return;
	}
	if(open >= close){
		s.push_back('{');
		solve(s, open-1, close);
		return;
	}
	else if(open == 0 && close>0){
		s.push_back('}');
		solve(s, open, close-1);
		return;
	}
	string s1 = s, s2 = s;
	s1.push_back('{');
	s2.push_back('}');
	solve(s1, open-1, close);
	solve(s2, open, close-1);
	return;
}


void solve1(string s, int open, int close){
	if(open == 0 && close == 0){
		cout<<s;
		return;
	}
	if(open == close){
		s.push_back('{');
		solve1(s, open-1, close);
	}
	else if(open == 0){
		s.push_back('}');
		solve1(s, open, close-1);
	}
	else if(open < close){
		string s1 = s;
	
		s1.push_back('{');
		s.push_back('}');

		solve1(s1, open-1, close);

		solve1(s, open, close-1);
	}
	
}

int main(){
	int n;
	cout<<"Enter the number\n";
	cin>>n;
	string s = " ";
	int open = n, close = n;
	solve1(s, open , close);
}