#include<iostream>
#include<vector>
#include<queue>

struct Point {
    int x;
    int y;
};

struct Stage {
    int row = 0;
    int column = 0;
    int size = 0;
    int** map;
    std::vector<Point> free;
    std::vector<Point> virus;
    std::vector<Point> walls;
};

int floodfill(const Stage&, int**&, int**&, Point);
int combi(const std::vector<Point>&, int, int, int*, std::vector<std::vector<Point>>&);
int make_map(const Stage&, const std::vector<std::vector<Point>>&, std::vector<int**>&);

int main() {
    Stage stage;
    Stage& stage_ref = stage;
    int temp, zero_count, virus_count;
    int** canvas;

    std::cin >> stage.row >> stage.column;

    stage.size = stage.row * stage.column;
    stage.map = new int*[stage.row];
    canvas = new int*[stage.row];
    for(int i=0; i<stage.row; i++) {
        stage.map[i] = new int[stage.column];
        canvas[i] = new int[stage.column];
    }

    for(int j=0; j<stage.row; j++) { 
        for(int i=0; i<stage.column; i++) {
            std::cin >> temp;
            stage.map[j][i] = temp;
            
            switch(temp) {
                case 0:
                    stage.free.push_back(Point{i, j});
                    break;
                case 1:
                    stage.walls.push_back(Point {i, j});
                    break;
                case 2:
                    stage.virus.push_back(Point {i, j});
                    break;
            }
        }
    }

    int flag[stage.size];
    std::vector<std::vector<Point>> output;
    std::vector<std::vector<Point>>& output_ref = output;
    std::vector<Point> free_ref = stage.free;
    combi(free_ref, free_ref.size(), 3, flag, output_ref);

    std::vector<int**> maps;
    std::vector<int**>& maps_ref = maps;
    maps.reserve(output.size());

    make_map(stage_ref, output_ref, maps_ref);
    for(auto& map : maps) {
        std::cout << "--MAP TEST---" << std::endl;
        for(int j=0; j<stage.row; j++) {
            for(int i=0; i<stage.column; i++) {
                std::cout << map[j][i] << " ";
            }
            std::cout << std::endl;
        }
    }

    int**& canvas_ref = canvas;
    virus_count = stage.virus.size();

    std::cout << "---Dispute---" << std::endl;
    for(auto& map : maps) {
        int**& map_ref = map;
        int zero = 0;
        for(auto& virus : stage.virus) {
            floodfill(stage_ref, map_ref, canvas_ref, virus);
        }
        for(int j=0; j<stage.row; j++) {
            for(int i=0; i<stage.column; i++) {
                if(map_ref[j][i] == 1) {
                    std::cout << map_ref[j][i] << " ";
                }
                else {
                    std::cout << canvas[j][i] << " ";
                }
                
                if(canvas[j][i] != 2 && map_ref[j][i] == 0) {
                    zero++;
                }
                canvas[j][i] = 0;
            }
            std::cout << std::endl;
        } // DISPLAY: Result for each virus
        std::cout << "free space: " << zero << std::endl;
    }

    std::cout << " - - - - " << std::endl;
    for(int j=0; j<stage.row; j++) {
        for(int i=0; i<stage.column; i++) {
            std::cout << stage.map[j][i] << " ";
        }
        std::cout << std::endl;
    } // DISPLAY: stage.map


}

int floodfill(const Stage& stage, int**& map, int**& canvas, Point from) {
    std::queue<Point> q;

    q.push(from);
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(q.size() != 0) {
        Point current = q.front();
        q.pop();
        canvas[current.y][current.x] = 2;

        for(int i=0; i<4; i++) {
            int x_ = current.x + dx[i];
            int y_ = current.y + dy[i];

            bool inside_bound = (x_ < stage.column && x_ >= 0) && (y_ < stage.row && y_ >= 0);
            if(inside_bound) {

                bool hit_wall = map[y_][x_] == 1;
                bool is_visited = canvas[y_][x_] == 2;
                if(!hit_wall && !is_visited) {
                        q.push(Point{x_, y_});
                }
            }
        }
    }
}

int combi(const std::vector<Point>& free, int n, int r, int* flag, std::vector<std::vector<Point>>& output) {
    std::vector<Point> temp;

    if(r == 1) {
        for(int i=0; i<n; i++) {
            flag[i] = 1;
            for(int j=0; j<free.size(); j++) {
                if(flag[j] == 1) {
                    temp.push_back(free[j]);
                }
            }
            output.push_back(temp);
            temp.clear();
            flag[i] = 0;
        }
        return 0;
    }
    if(r == n) {
        for(int i=0; i<n; i++) {
            temp.push_back(free[i]);
        }
        for(int j=0; j<free.size(); j++) {
            if(flag[j] == 1) {
                temp.push_back(free[j]);
            }
        }
        output.push_back(temp);
        temp.clear();
        return 0;
    }
    else {
        flag[n-1] = 1;
        combi(free, n-1, r-1, flag, output);
        flag[n-1] = 0;
        combi(free, n-1, r, flag, output);
    }
}

int make_map(const Stage& stage, const std::vector<std::vector<Point>>& input, std::vector<int**>& maps) {

    
    for(auto& map : input) {
        int** map_ = new int*[stage.row];
        for(int i=0; i<stage.row; i++) {
            map_[i] = new int[stage.column];
        }

        for(auto& wall : map) {
            map_[wall.y][wall.x] = 1;
        }
        for(auto& wall : stage.walls) {
            map_[wall.y][wall.x] = 1;
        }

        maps.push_back(map_);
    }
}