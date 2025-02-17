#include <iostream>
#include <cmath>
#include <unordered_set>

int verify(std::unordered_set<int> men,std::unordered_set<int> women){
    for (auto man1 = men.begin(); man1 != men.end(); man1++) {
        for (auto man2 = std::next(man1); man2 != men.end(); man2++) {
            int sum = *man1 + *man2;
            if (women.count(sum) > 0) {
                return 1;
            }
        }
    }
    for (auto woman1 = women.begin(); woman1 != women.end(); woman1++) {
        for (auto woman2 = std::next(woman1); woman2 != women.end(); woman2++) {
            int sum = *woman1 + *woman2;
            if (men.count(sum) > 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    int aux;
    while(std::cin >> n){
        std::unordered_set<int> men,women;
        if(n!=0){
            for(int i=0;i<n;i++){
                std::cin >> aux;
                if(aux<0){
                    men.insert(std::abs(aux));
                }else{
                    women.insert(aux);
                }
            }
            if (verify(men,women)){
                std::cout << "Fair" << "\n";
            }else{
                std::cout << "Rigged" << "\n";
            }
        }
    }
    return 0;
}