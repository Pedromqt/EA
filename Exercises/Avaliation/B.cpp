#include <iostream>
#include <set>

int count_moves(int n_moves,int x, int y){
    int moves[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    // fazer a coordenada de origem
    std::set<std::pair<int, int>> positions;
    positions.insert({x,y});

    for(int i=0;i<n_moves;i++){
        std::set<std::pair<int,int>> new_pos;
        for(auto pos : positions){
            //coordenadas x y
            int x = pos.first, y = pos.second;

            for(int j=0;j<=7;j++) {
                int aux_x = x + moves[j][0];
                int aux_y = y + moves[j][1];
                if ((aux_x >= -200 && aux_x <= 200) && (aux_y >= -200 && aux_y <= 200)) {
                    new_pos.insert({aux_x, aux_y});
                }
            }
            
        }
        positions = new_pos;
    }
    return positions.size();
}

int main(){
    int n,total_moves,x,y,possible_moves;
    std::cin >> n;
    total_moves=0;

    for(int i=0;i<n;i++){
        std::cin >> x >> y >> possible_moves;
        total_moves+=count_moves(possible_moves,x,y);
    }
    std::cout << total_moves << "\n";
    return 0;
}
