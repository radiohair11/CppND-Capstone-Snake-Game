#include "map.h"

Map::Map(std::string mapFile) {
    if(!this->ReadMap(mapFile)){
        std::cout << "Could not read map!\n";
    };
    
}

// Could be used to make non-square maps or maps of different sizes. To keep things simple, keep all maps 32x32
std::size_t Map::Width() { return map_.size(); }

std::size_t Map::Height() { return map_[0].size(); }

// TODO: this doesn't work for some reason
MapObject Map::GetObjectAt(int x, int y) { return map_.at(x).at(y); }

bool Map::IsEmpty(){ return map_.empty(); }

bool Map::ReadMap(std::string mapFile) {
    std::ifstream file(mapFile);
    std::string line;
    std::vector<MapObject> row;
    int lineCount = 0;
    SDL_Point wall;

    if(file.is_open()) {
        while( std::getline(file, line) ) {
            //std::cout << line << '\n';
            for(int i = 0; i < line.size(); i++) {
                if(line.at(i) == '1') {
                    row.emplace_back(MapObject::Wall);
                    wall = {i, lineCount};
                    walls.emplace_back(wall);   
                } else {
                    row.emplace_back(MapObject::Empty);
                }
            }
            map_.emplace_back(row);
            lineCount++;
        }
    } else {
        return false;
    }
    file.close();
    // std::cout << "Successfully read the map\n";

    // Uncomment to print the locations of all of the walls
    // for (int j = 0; j < walls.size(); j++) {
    //     std::cout << "Wall x: " << walls.at(j).x << ", y: " << walls.at(j).y << '\n';
    // }
    return true;
}