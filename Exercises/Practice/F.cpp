#include <iostream>
#include <stack>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    int current_time=0;
    for(int i=0;i<n;i++){
        int arrival,processing;
        std::cin >> arrival >> processing;
        current_time = std::max(current_time,arrival) + processing;
    }
    std::cout << current_time << "\n";
    return 0;
}