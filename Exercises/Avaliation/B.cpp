#include <iostream>
#include <set>

void count_moves(int n_moves,int x, int y,std::set<std::pair<int, int>>& distinct_positions){
    int moves[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    std::set<std::pair<int, int>> positions;
    positions.insert({x,y});
    distinct_positions.insert({x, y});
    
    for(int i=0;i<n_moves;i++){
        std::set<std::pair<int,int>> new_pos;
        for(auto pos : positions){
            int x = pos.first;
            int y = pos.second;
            for(int j=0;j<=7;j++) {
                int aux_x = x + moves[j][0];
                int aux_y = y + moves[j][1];
                if ((aux_x >= -200 && aux_x <= 200) && (aux_y >= -200 && aux_y <= 200)) {
                    new_pos.insert({aux_x, aux_y});
                    distinct_positions.insert({aux_x, aux_y});
                }
            }
            
        }
        positions = new_pos;
    }
}

int main(){
    int n,x,y,possible_moves;
    std::cin >> n;
    std::set<std::pair<int, int>> distinct_positions;
    for(int i=0;i<n;i++){
        std::cin >> x >> y >> possible_moves;
        count_moves(possible_moves,x,y,distinct_positions);
    }
    std::cout << distinct_positions.size() << "\n";
    return 0;
}
