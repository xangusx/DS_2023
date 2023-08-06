#include <bits/stdc++.h>
using namespace std;

string ShuntingYard(string s){
    map<char, int> priority {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };

    string postorder;
    stack<char> operator_stack;
    for(auto ch : s){
        if(ch >= 'A' && ch <= 'E')
            postorder.push_back(ch);
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!operator_stack.empty() && operator_stack.top() != '(' && priority[operator_stack.top()] >= priority[ch]){
                postorder.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(ch);
        }
        else if(ch == '('){
            operator_stack.push(ch);
        }
        else if(ch == ')'){
            while(operator_stack.top() != '(') {
                postorder.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
    }
    while(operator_stack.size()) {
        postorder.push_back(operator_stack.top());
        operator_stack.pop();
    }
    return postorder;
}

int solve(string postorder){
    vector<int> val(5+1);
    for(int i=1; i<=5; i++)
        cin>>val[i];
    stack<int> p;
    int a, b;
    for(auto ch : postorder){
        if(ch >= 'A' && ch <= 'E')
            p.push(val[ch-'A'+1]);
        else{
            a = p.top();
            p.pop();
            b = p.top();
            p.pop();
            if(ch == '+') p.push(b+a);
            else if(ch == '-') p.push(b-a);
            else if(ch == '*') p.push(b*a);
            else p.push(b/a);
        }
    }
    return p.top();
}

int main(){
    string s; cin>>s;
    string postorder = ShuntingYard(s);
    int q; cin>>q;
    while(q--){
        cout << solve(postorder) << endl;
    }
}