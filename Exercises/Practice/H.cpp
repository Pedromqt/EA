#include <iostream>
#include <unordered_map>

int main(){
    std::unordered_map<int,int> inv;
    std::string cmd;
    int x,y;
    while(std::cin>>cmd){
        if(cmd!="QUERY"){
            std::cin >> x >> y;
            if(cmd == "ADD"){
                inv[y] += x;
            }else if(cmd=="REM"){
                if(inv[y]>=x){
                    inv[y] -= x;
                }else {
                    std::cout << "removal refused" << "\n";
                }
            }
        }else if(cmd=="QUERY"){
            std::cin>>y;
            std::cout << inv[y] << "\n";
        }
    }
    return 0;
}