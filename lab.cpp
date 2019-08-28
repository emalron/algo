#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

int floodfill(const Stage&, int**&, Point, int&);
int combi(const Stage&, int, int, int*, int**&);
int dispute(const Stage&, int**&, std::vector<Point>);
int max = 0;

int main() {
    Stage stage;
    int temp;
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
                    canvas[j][i] = 2;
                    break;
            }
        }
    }

    int flag[stage.size];
    combi(stage, stage.free.size(), 3, flag, canvas);

    std::cout << max << std::endl;

    for(int i=0;i<stage.row; i++) {
        delete [] *(canvas+i);
    }
    delete [] canvas;
}

int floodfill(const Stage& stage, int**& canvas, Point from, int& counter) {
    std::queue<Point> q;

    q.push(from);
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(q.size() != 0) {
        Point current = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int x_ = current.x + dx[i];
            int y_ = current.y + dy[i];

            bool inside_bound = (x_ < stage.column && x_ >= 0) && (y_ < stage.row && y_ >= 0);
            if(inside_bound) {

                bool hit_wall = stage.map[y_][x_] == 1;
                bool is_visited = canvas[y_][x_] == 2;
                if(!hit_wall && !is_visited) {
                    canvas[y_][x_] = 2;
                    q.push(Point{x_, y_});
                    counter++;
                }
            }
        }
    }
}

int combi(const Stage& stage, int n, int r, int* flag, int**& canvas) {
    std::vector<Point> temp(3);

    if(r == 1) {
        for(int i=0; i<n; i++) {
            flag[i] = 1;
            for(int j=0; j<stage.free.size(); j++) {
                if(flag[j] == 1) {
                    temp.push_back(stage.free[j]);
                }
            }

            dispute(stage, canvas, temp);
            temp.clear();
            flag[i] = 0;
        }
        return 0;
    }
    if(r == n) {
        for(int i=0; i<n; i++) {
            temp.push_back(stage.free[i]);
        }
        for(int j=0; j<stage.free.size(); j++) {
            if(flag[j] == 1) {
                temp.push_back(stage.free[j]);
            }
        }

        dispute(stage, canvas, temp);
        temp.clear();
        return 0;
    }
    else {
        flag[n-1] = 1;
        combi(stage, n-1, r-1, flag, canvas);
        flag[n-1] = 0;
        combi(stage, n-1, r, flag, canvas);
    }
}

int dispute(const Stage& stage, int**& canvas, std::vector<Point> map) {
    
    int zero, count = 0;

    for(auto& wall : map) {
        stage.map[wall.y][wall.x] = 1;
    }

    for(auto& virus : stage.virus) {
        floodfill(stage, canvas, virus, count);
    }

    zero = stage.free.size() - 3 - count;

    if(zero >= max) max = zero;

    for(auto& wall : map) {
        stage.map[wall.y][wall.x] = 0;
    }

    for(auto& free : stage.free) {
        canvas[free.y][free.x] = 0;
    }

    
}