#include <iostream>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    int aux;
    std::cin>>n;
    std::array<int, 1000> arr;
    for( int i=0;i<n;i++){
        std::cin >> aux;
        arr[i]=aux;
    }
    for( int i=n-1;i>=0;i--){
        std::cout << arr[i] << " "; 
    }
    std::cout << "\n";
    return 0;
}