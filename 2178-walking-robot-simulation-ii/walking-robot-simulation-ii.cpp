class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> pos;

    Robot(int width, int height) {
        // for bottom boundary
        for(int x = 0; x < width; x++){
            pos.push_back({x, 0, 0});
        }

        // for right boundary
        for(int y = 1; y < height; y++){
            pos.push_back({width-1, y, 1});
        }

        // for top boundary
        for(int x = width-2; x >= 0; x--){
            pos.push_back({x, height-1, 2});
        }
        
        // for left boundary
        for(int y = height-2; y > 0; y--){ // y > 0 because [0][0] hum first loop mai already fill kar chuke hai
            pos.push_back({0, y, 3});
        }
        pos[0][2] = 3; // making pos of [0][0] south, later we will handel the first [0][0] to be east explicitly
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0],pos[idx][1]}; // returning x and y of position
    }
    
    string getDir() {
        if(!moved) return "East";
        if(pos[idx][2] == 0) return "East";
        else if(pos[idx][2] == 1) return "North";
        else if(pos[idx][2] == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */