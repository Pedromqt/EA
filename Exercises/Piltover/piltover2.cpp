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

/* int fatorial(int n){

    int res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

int calc_n_combinations(){
    int n_combinations = 1;
    int n_places;
    int n_turrets;
    for(auto turret : turrets){
        n_places = turret.second.size();
        n_turrets = 0;
        for(auto place : turret.second){
            if(place.second == 1){
                n_turrets++;
            }
        }
        n_combinations *= fatorial(n_places)/(fatorial(n_turrets)*fatorial(n_places - n_turrets));
    }
    cout << n_combinations << endl;
    return n_combinations;
}*/

bool check_same_row(int r, int c, bool turret_found) {
    if (c >= C) {
        return false;
    }
    if (grid[{r, c}] == 'x') {
        if (turret_found) {
            return true; 
        }
        turret_found = true;
    } else if (grid[{r, c}] == '#' || isdigit(grid[{r, c}])) {
        turret_found = false;  
    }
    return check_same_row(r, c + 1, turret_found); 
}

bool check_same_column(int c, int r, bool turret_found) {
    if (r >= R) {
        return false; 
    }
    if (grid[{r, c}] == 'x') {
        if (turret_found) {
            return true; 
        }
        turret_found = true;
    } else if (grid[{r, c}] == '#' || isdigit(grid[{r, c}])) {
        turret_found = false; 
    }
    return check_same_column(c, r + 1, turret_found);  
}

bool check_turret_same_column_or_line(){
    for (int r = 0; r < R; r++) {
        if (check_same_row(r, 0, false)) {
            return true; 
        }
    }
    for (int c = 0; c < C; c++) {
        if (check_same_column(c, 0, false)) {
            return true; 
        }
    }
    return false;
}

void work_outposts(){
    for(auto outpost : outposts){
        int r = outpost.first.first;
        int c = outpost.first.second;
        int number_turrets = outpost.second;
        bool flag = number_turrets == 0 ? false : true;
        int remaining_turrets_to_place = number_turrets - count_turrets_around_outpost(r,c);
        if(!put_turrets(r,c,remaining_turrets_to_place,0,flag)){
            cout << "noxus will rise!" << endl;
            return;
        }
    }
}

void put_turrets(){

}

void print_grid() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[{i, j}];
        }
        cout << endl;
    }
}

int combine_turrets(){
    // int n_combinations = calc_n_combinations();
    
    while(1){
        if(!check_turret_same_column_or_line()){
            return 1;
        }
    }
    return 0;
}

void print_turrets(){
    for(auto turret : turrets){
        for(auto place : turret.second){
            cout <<"Outpost: x:" << turret.first.first << " y:" << turret.first.second << " Torre x:" << place.first.first << " y:" << place.first.second << " Valor " << place.second << endl;
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
        if(check_turret_same_column_or_line()){
            cout << "tira que eu bati" << endl;
            combine_turrets();
            print_grid();
        }else{
            put_turrets();
        }
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