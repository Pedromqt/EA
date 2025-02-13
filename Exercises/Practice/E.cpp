#include <iostream>
#include <stack>
#include <sstream>

int processResult(std::string expression){
    std::stack<int> s;
    std::stringstream expr(expression);
    std::string token;
    while(expr >> token){
        if(token=="+" || token=="-"){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            if(token=="+"){
                s.push(a+b);
            }else{
                s.push(b-a);
            }
        }else{
            s.push(stoi(token));
        }
    }
    int val = s.top(); s.pop();
    return val;
}

int main(){
    int n;
    std::cin>>n;
    // ignorar o \n
    std::cin.ignore();

    for(int i=0;i<n;i++){
        std::string expr;
        std::getline(std::cin,expr);
        std::cout << processResult(expr) << "\n";
    }
    return 0;
}