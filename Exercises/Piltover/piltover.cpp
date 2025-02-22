#include <iostream>
#include <vector>

using namespace std;

int turret_places[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char cant_place_turret = 'N';
char place_turret = 'x';

// verificar se nao saimos fora da grid para nao termos SF
int check_grid_limits(int R, int C, int new_x, int new_y){
    if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C){
        return 1;
    }
    else{
        return 0;
    }
}

// funcao para tentar modificar a posicao das torres de modo a que as torres nao colidam
void modify_grid(vector<vector<char>> &grid){

}

// funcao para verificar se toda a grid esta a ser defendida
void verify_defense(vector<vector<char>> &grid){

}

// colocar torres a volta dos postos
int heimerdinger(vector<vector<char>> &grid){
    int R = int(grid.size());
    int C = int(grid[0].size());
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (isdigit(grid[r][c])){
                int number_turrets = grid[r][c] - '0';
                int placed_turrets = 0;
                // ver quantas torres já temos antes de colocar novas torres
                for (int p = 0; p < 4; p++){
                    int new_x = r + turret_places[p][0];
                    int new_y = c + turret_places[p][1];
                    if (check_grid_limits(R, C, new_x, new_y) && grid[new_x][new_y] == 'x'){
                        placed_turrets++;
                    }
                }
                // colocar torres que faltam
                for (int p = 0; p < 4; p++){
                    int new_x = r + turret_places[p][0];
                    int new_y = c + turret_places[p][1];
                    if (check_grid_limits(R, C, new_x, new_y)){
                        if (grid[new_x][new_y] == '.' && placed_turrets < number_turrets){
                            grid[new_x][new_y] = place_turret;
                            placed_turrets++;
                        }else if(placed_turrets>=number_turrets){
                            // nao podemos depois adicionar torres em lugares na grid que tenham '-'
                            grid[new_x][new_y] = cant_place_turret;
                        }
                    }
                }
            }
        }
    }

    for (int r = 0; r < int(grid.size()); r++){
        for (int c = 0; c < int(grid[0].size()); c++){
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    int C;
    int R;
    for (int i = 0; i < T; i++){
        cin >> R >> C;
        vector<vector<char>> grid(R, vector<char>(C));
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++){
                cin >> grid[r][c];
            }
        }
        int n_turrets = heimerdinger(grid);
        if (n_turrets != 0){
            cout << n_turrets << "\n";
        }
        else{
            cout << "noxus will rise!" << "\n";
        }
    }
}