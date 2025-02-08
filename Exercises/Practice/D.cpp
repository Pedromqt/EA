#include <iostream>
#include <list>
#include <string>

int main(){

    std::list<int> l = {0}; 
    std::list<int>::iterator ptr = l.begin();
    std::string cmd,dir;
    int val;

    while(std::cin>>cmd){
        if(cmd == "MOVE"){
            std::cin>>dir;
            if(dir=="LEFT" && ptr != l.begin()){
                ptr--;
            }else if(dir=="RIGHT" && ptr != l.end()){
                ptr++;
            }
        }else if(cmd == "INSERT"){
            std::cin>>dir>>val;
            if(dir=="LEFT"){
                l.insert(ptr,val);
            }else if (dir=="RIGHT"){
                l.insert(std::next(ptr),val);
            }
        }
    }
    for(int v:l){
        std::cout << v << "\n";
    }

    return 0;
}   