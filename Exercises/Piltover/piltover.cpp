#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// onde temos N não podemos ter torres, pois o posto tem 0 torres.
// onde temos P podemos ter torres, pois o posto tem >0 torres. Vou usar para fazer trocas na modify grid.

int turret_places[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char cant_place_turret = 'N';
char place_turret = 'x';

// verificar se nao saimos fora da grid
int check_grid_limits(int R, int C, int new_x, int new_y){
    if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C){
        return 1;
    }
    else{
        return 0;
    }
}

// colococar torres de modo a cobrir os "." que faltam
int put_towers(vector<vector<char>> &grid){
    //chamar recursivamente a verif de colisao de torres

    return 0;
}

// contar numero de torres colocadas
int count_towers(vector<vector<char>> &grid){
    int n_towers=0;
    for(auto r : grid){
       n_towers += count(r.begin(),r.end(),'x');
    }
    return n_towers;
}

// funcao para tentar modificar a posicao das torres de modo a que as torres nao colidam
int modify_grid(vector<vector<char>> &grid){
    int R = int(grid.size());
    int C = int(grid[0].size());
    for(int r = 0 ; r < R ; r++){
        for(int c = 0; c < C ; c++){
            
        }
    }
    //chamar recursivamente a verif de colisao de torres
    return 1;
    
}

// verificar se temos torres a colidir, se tivermos, modify_grid. Depois de nao termos torres a colidir, verify_defense
int verify_towers_collision(vector<vector<char>> &grid){
    int R = int(grid.size());
    int C = int(grid[0].size());
    
    for(int c = 0; c < C; c++) {
        int count = 0;
        for(int r = 0; r < R; r++) {
            if(grid[r][c] == 'x') {
                count++;
            }
            // ha 2 x seguidos
            if(count > 1){
                return 1;
            } 
            if(count>0 && (grid[r][c] == '#' || isdigit(grid[r][c]))){
                count--;
            }
           
        }
    }
    
    for(int r = 0; r < R; r++) {
        int count = 0;
        for(int c = 0; c < C; c++) {
            if(grid[r][c] == 'x') {
                count++;
            }
            if(count > 1){
                return 1;
            } 
            if(count>0 && (grid[r][c] == '#' || isdigit(grid[r][c]))){
                count--;
            }
            
        }
        
    }
    
    return 0;
}

// funcao para verificar se toda a grid esta a ser defendida -> colocar substituir '.' por '-' nas direções que as torres tao a defender. Se nao houver '.' na grid, ta feito
int verify_defense(vector<vector<char>> &grid){
    int R = int(grid.size());
    int C = int(grid[0].size());
    
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            if(grid[r][c]=='x'){
                // '.' passa a '-' na mesma linha
                for (int left = c - 1; left >= 0 && grid[r][left] != '#' && !isdigit(grid[r][left]); left--) {
                    if (grid[r][left] == '.'){
                        grid[r][left] = '-';
                    } 
                }
                for (int right = c + 1; right < C && grid[r][right] != '#'  && !isdigit(grid[r][right]); right++) {
                    if (grid[r][right] == '.'){
                        grid[r][right] = '-';
                    } 
                }
                // '.' passa a '-' na mesma coluna
                for(int up = r-1 ; up >= 0 && grid[up][c] != '#'  && !isdigit(grid[up][c]); up--){
                    if (grid[up][c] == '.'){
                        grid[up][c] = '-';
                    } 
                }
                for(int down = r+1 ; down < R && grid[down][c] != '#' && !isdigit(grid[down][c]); down++){
                    if (grid[down][c] == '.'){
                        grid[down][c] = '-';
                    } 
                }
            }
        }
    }
    for(auto r : grid){
        if(count(r.begin(),r.end(),'.')>0){
            return 0;
        }
    }
    
    return 1;

}

void printGrid(vector<vector<char>> &grid){
    int R = grid.size();
    int C = grid[0].size();
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
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
                        // colocar 'N' quando é um posto e nao podemos ter torres a volta. caso a volta seja um posto, nao substituir por N 
                        if(number_turrets==0 && !isdigit(grid[new_x][new_y])){
                            grid[new_x][new_y] = cant_place_turret;
                        }else{
                            if (grid[new_x][new_y] == '.' && placed_turrets < number_turrets){
                                grid[new_x][new_y] = place_turret;
                                placed_turrets++;
                            }
                        }
                        
                    }
                }
            }
        }
        
    }
    
    // se as torres colidem, modificamos o lugar delas -> isto é para as torres obrigatorias a volta dos postos.
    if(verify_towers_collision(grid)){
        // se conseguirmos modificar a grelha sem termos torres a colidir, verificamos se defende tudo.
        if(modify_grid(grid)){
            // se defender tudo, retornamos o numero de torres usadas.
            if(verify_defense(grid)){
                return count_towers(grid);
            }else{ 
                // adicionar torres de modo a cobrir o que falta. Se conseguirmos adicionar as torres e nao haja colisoes depois de adicionar
                if(put_towers(grid)){
                    return count_towers(grid);
                }else{
                    return 0;
                }
            }
        }else{
            return 0;
        }
    }else{
        if(verify_defense(grid)){
            return count_towers(grid);
        }else{
            if(put_towers(grid)){
                return count_towers(grid);
            }else{
                return 0;
            }
        }
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