#include<iostream>
#include<vector>

typedef struct POINT {
    int x;
    int y;
} POINT;

typedef struct STAGE {
    int row = 0;
    int column = 0;
    int size = 0;
    std::vector<int> map;
    std::vector<POINT> virus;
} STAGE;

int combination();
int floodfill(const STAGE&, std::vector<int>&, POINT);

int main() {
    STAGE stage;
    STAGE& stage_ref = stage;
    int temp;

    std::cin >> stage.row >> stage.column;

    stage.size = stage.row * stage.column;
    stage.map.resize(stage.size, 0);

    for(int j=0; j<stage.row; j++) { 
        for(int i=0; i<stage.column; i++) {
            std::cin >> temp;
            stage.map[i + stage.column*j] = temp;
            
            if(temp == 2) {
                stage.virus.push_back(POINT {i, j});
            }
        }
    }

    std::vector<int> canvas;
    std::vector<int>& canvas_ref = canvas;
    canvas.resize(stage.size, 0);

    for(auto& virus : stage.virus) {
        std::cout << "----RESULT----" << std::endl;
        floodfill(stage_ref, canvas_ref, virus);
        for(int i=0; i<stage.size; i++) {
            if(i % stage.column == 0 && i > 0) std::cout << std::endl;
            std::cout << canvas[i] << " ";
        }
        std::cout << std::endl;
    }
}

int floodfill(const STAGE& stage, std::vector<int>& canvas, POINT from) {
    int coord = from.x + stage.column * from.y;
    bool hit_wall = from.x < 0 || from.x >= stage.column || from.y < 0 || from.y >= stage.row || stage.map[coord] == 1;
    bool hit_virus = canvas[coord] == 2;

    if(hit_wall) {
        return 0;
    }
    if(hit_virus) {
        return 0;
    }
    else {
        canvas[coord] = 2;
        if(from.x + 1 < stage.column) floodfill(stage, canvas, POINT{from.x+1, from.y});
        if(from.y + 1 < stage.row) floodfill(stage, canvas, POINT{from.x, from.y+1});
        if(from.x - 1 > 0 ) floodfill(stage, canvas, POINT{from.x-1, from.y});
        if(from.y - 1 > 0 ) floodfill(stage, canvas, POINT{from.x, from.y-1});
    }
}