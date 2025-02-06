#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<int> vec;
    int n;
    while (std::cin >> n) {
        vec.push_back(n);
    }
    std::sort(vec.begin(),vec.end());
    for(int i=0;i<(int)vec.size();i++){
        std::cout << vec[i] << "\n";
    }
    return 0;
}