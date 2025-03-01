#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int turret_places[][2] = {{-1, 0}, {0, 1}, {1, 0},{0, -1}};

map<pair<int,int>,char> grid;
map<pair<int,int>,int> outposts;
map<pair<int, int>, map<pair<int, int>, int>> turrets;
map<pair<int,int>,int> walls;
int T,R,C;

void clear(){
    grid.clear();
    outposts.clear();
    turrets.clear();
    walls.clear();
}

int check_grid(int x,int y){
    if(x >= 0 && x < R && y >= 0 && y < C){
        return 1;
    }
    return 0;
}

int put_turrets(int r, int c, int number_turrets,int place, bool flag){
    if(place >= 4 && number_turrets <= 0){
        return 1;
    }
    if(place >= 4 && number_turrets > 0){
        return 0;
    }
    int new_x,new_y;
    new_x = r + turret_places[place][0];
    new_y = c + turret_places[place][1];
    place++;
    pair<int,int> outpost_place = {r,c};
    pair<int,int> new_place = {new_x,new_y};
    if(check_grid(new_x,new_y)){
        if(grid[new_place] == '.' && number_turrets > 0){ 
            grid[new_place] = 'x';
            turrets[outpost_place][new_place] = 1;
            number_turrets--;
        }else if(grid[new_place] == '.' && number_turrets == 0 && flag == true){
            grid[new_place] = 'k';
            turrets[outpost_place][new_place] = 2; // para saber que podemos andar as trocas com este lugar depois
        }
    }
    return put_turrets(r,c,number_turrets,place,flag);
}

int count_turrets_around_outpost(int r,int c){
    int turrets_placed = 0;
    for(int i = 0; i < 4; i++){
        int new_x = r + turret_places[i][0];
        int new_y = c + turret_places[i][1];
        if(check_grid(new_x,new_y)){
            if(grid[{new_x,new_y}] == 'x'){
                turrets_placed++;
            }
        }
    }
    return turrets_placed;
}

void work_outposts(){
    for(auto outpost : outposts){
        int r = outpost.first.first;
        int c = outpost.first.second;
        int number_turrets = outpost.second;
        bool flag = number_turrets == 0 ? false : true;
        // quantas torres faltam colocar
        int remaining_turrets_to_place = number_turrets - count_turrets_around_outpost(r,c);
        if(put_turrets(r,c,remaining_turrets_to_place,0,flag)){
            continue;
        }
    }
}

void print_grid() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[{i, j}];
        }
        cout << endl;
    }
}

void print_turrets(){
    for(auto turret : turrets){
        for(auto place : turret.second){
            cout << turret.first.first << " " << turret.first.second << " " << place.first.first << " " << place.first.second << " " << place.second << endl;
        }
    }
}

void heimerdinger(){
    cin >> T;
    while(T--){
        cin >> R >> C;
        clear();
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                char aux;
                cin >> aux;
                grid[{r,c}] = aux;
                if(isdigit(aux)){
                    outposts[{r,c}] = aux - '0';
                }else if(aux == '#'){
                    walls[{r,c}] = 1;
                }
            }
        }
        work_outposts();
        print_grid();
        cout << endl;
        print_turrets();
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    heimerdinger();
    return 0;
}