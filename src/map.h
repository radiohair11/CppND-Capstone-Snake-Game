#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "SDL.h"
#include <fstream>
#include <iostream>

enum class MapObject { Empty = 0, Wall };

class Map {
  public:
    Map(std::string mapFile);
    std::size_t Height();
    std::size_t Width();
    std::vector<SDL_Point> Walls();
    bool ReadMap(std::string mapFile);
    MapObject GetObjectAt(int x, int y);
    bool IsEmpty();

    std::vector<SDL_Point> walls;

  private:
    std::size_t mapWidth_ = 0;
    std::size_t mapHeight_ = 0;
    std::vector<std::vector<MapObject>> map_;

};

#endif