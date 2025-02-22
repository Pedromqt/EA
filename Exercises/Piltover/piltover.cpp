#include <iostream>
#include <vector>

using namespace std;

int turret_places[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int check_grid_limits(int R,int C,int new_x,int new_y){
    if(new_x>=0 && new_x<R &&  new_y>=0 && new_y<C ){
        return 1;
    }else{
        return 0;
    }
}

int heimerdinger(vector<vector<char>> &grid){
    int R = int(grid.size());
    int C = int(grid[0].size());
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(isdigit(grid[r][c])){
                int number_turrets = grid[r][c] - '0';
                int placed_turrets = 0;
                //ver quantas torres já temos antes de colocar novas torres
                for(int p=0;p<4;p++){
                    int new_x = r+turret_places[p][0];
                    int new_y = c+turret_places[p][1];
                    if(check_grid_limits(R,C,new_x,new_y) && grid[new_x][new_y]=='x'){
                        placed_turrets++;
                    }
                }
                //colocar torres que faltam
                for(int p=0;p<4 && placed_turrets < number_turrets; p++){
                    int new_x = r+turret_places[p][0];
                    int new_y = c+turret_places[p][1];
                    if(check_grid_limits(R,C,new_x,new_y)){
                        if (grid[new_x][new_y] == '.' && placed_turrets < number_turrets) {
                            grid[new_x][new_y] = 'x';
                            placed_turrets++;
                        }
                    }
                }
            } 
        }
    }

    for(int r=0;r<int(grid.size());r++){
        for(int c=0;c<int(grid[0].size());c++){
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}


int main(){
    int number_cases;
    cin >> number_cases;
    int C;
    int R;
    for(int i=0;i<number_cases;i++){
        cin >> R >> C;
        vector<vector<char>> grid(R,vector<char>(C));
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                cin >> grid[r][c];
            }
        }
        if(int n_turrets = heimerdinger(grid)!=0){
            cout << n_turrets << "\n";
        }else{
            cout << "noxus will rise!" << "\n";
        }
        
    }
}