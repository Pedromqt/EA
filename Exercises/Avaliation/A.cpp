#include <iostream>
#include <cmath>
#include <unordered_set>

int verify(std::unordered_set<int> men,std::unordered_set<int> women){
    for(int man: men){
        for(int woman: women){
            int sum = man + woman;
            
        }
    }
}

int main(){
    int n;
    int aux;
    int sum;
    std::unordered_set<int> men,women;
    while(std::cin >> n){
        if(n==0){
            std::cin >> n;
        }else{
            for(int i=0;i<n;i++){
                std::cin >> aux;
                if(aux<0){
                    men.insert(std::abs(aux));
                }else{
                    women.insert(aux);
                }
            }
            if (verify(men,women)){
                
            }
        }
    }
    return 0;
}