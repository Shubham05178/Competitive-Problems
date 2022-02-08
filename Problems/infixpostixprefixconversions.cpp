#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
	if(c == '^') return 2;
	else if(c == '/' || c == '*') return 1;
	else if(c == '+' || c == '-') return 0;
	return -1;
}
string infix_to_postfix(string s){
	string res;
	stack<char>st;
	for(char c : s){
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9'))
		res+=c;
	
		else if( c =='(')
			st.push(c);
		else if(c ==')'){
			while(st.top()!= '('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && precedence(st.top()) >= precedence(c)){
				res+=st.top();
				st.pop();	
			} 
			st.push(c);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}
string postfix_to_infix(string s){
	stack<string>st;
	for(char c : s){
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			string s(1,c);	
			st.push(s);
			}
		else{
			string sf= st.top();
			st.pop();
			string ss= st.top();
			st.pop();
			string s(1,c);
			st.push("("+ss+s+sf+")");
		}
	}
	return st.top();
}
string infix_to_prefix(string s){
	int n = s.size()-1;
	string res;
	stack<char>st;
	for(int i = n; i >= 0; i--){
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		res=c+res;
		else if(c==')') st.push(c);
		else if(c=='('){
			while(st.top()!= ')'){
				res= st.top()+res;
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && precedence(st.top())> precedence(c)){
				res=st.top()+res;
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res= st.top()+res;
		st.pop();
	}
return res;

}
string prefix_to_infix(string s){
	stack<string>st;
	for(int i = s.size()-1; i >= 0 ; i--){
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			string s(1,c);	
			st.push(s);
			}
		else{
			string sf= st.top();
			st.pop();
			string ss= st.top();
			st.pop();
			st.push("("+sf+c+ss+")");
		}
	}
	return st.top();
}
int main(){
	string s;
	cin>>s;
	string  postfix =infix_to_postfix(s);
	cout<<"POSTFIX :  "<<postfix<<endl;
	string infix= postfix_to_infix(postfix);
	cout<<"INFIX   :  "<<infix<<endl;
	string prefix= infix_to_prefix(infix);
	cout<<"PREFIX  :  "<<prefix<<endl;
	string infix3= prefix_to_infix(prefix);
	cout<<"INFIX   :   "<<infix3<<endl;

}
