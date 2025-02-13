#include <iostream>
#include <set>

int main(){
    
    std::string op;
    int size;
    std::multiset<int> shoeStand;
    while(std::cin>>op>>size){
        if(op=="ADD"){
            shoeStand.insert(size);
        }else if(op=="REQUEST"){
            auto ptr = shoeStand.lower_bound(size);
            if (ptr!=shoeStand.end()){
                std::cout << *ptr << "\n";
                shoeStand.erase(ptr);
            }else{
                std::cout << "impossible" << "\n";
            }
        }
    }

    return 0;
}