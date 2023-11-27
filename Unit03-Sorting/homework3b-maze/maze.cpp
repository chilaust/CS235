#include <iostream>
#include <string>
#include <fstream>
#include "Grid.h"
#include <vector>

bool findPath (int x, int y, int z, int height, int width, int depth, std::vector<std::string> &solution, Grid &maze) {
        solution.push_back(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z));

        if (x == height - 1 && y == width - 1 && z == depth - 1) {
            return true;
        }
        if (x < 0 || x > height - 1 || y < 0 || y > width - 1 || z < 0 || z > depth - 1) {
            solution.pop_back();
            return false;
        }
        if (maze.at(x, y, z) == 2 || maze.at(x, y, z) == 0) {
            solution.pop_back();
            return false;
        }

        maze.at(x,y,z) = 2;

        if(findPath (x+1,y,z,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }
        if(findPath (x-1,y,z,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }
        if(findPath (x,y+1,z,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }
        if(findPath (x,y-1,z,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }
        if(findPath (x,y,z+1,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }
        if(findPath (x,y,z-1,height,width,depth,solution,maze)) {
            //add to solution
            return true;
        }

}

int main(int argc, char* argv[]) {
    // open the input file
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << "input_file/n";
        return 1;
    }
    std::string in = argv[1];
    std::ifstream input_file(in);
    std::string output_file = argv[2];
    std::ofstream out(output_file);
    Grid maze;
    input_file >> maze;
    int height = maze.height();
    int width = maze.width();
    int depth = maze.depth();
    std::vector<std::string> solution;
    if (findPath(0,0,0, height, width, depth, solution, maze)) {
        out << "SOLUTION" << std::endl;
        for (std::string point : solution) {
            out << point << std::endl;
        }
    }
    else {
        out << "NO SOLUTION";
    }








    // iterate over the input file to find what size the maze is and import it into an array
    // recursively iterate over maze array
    // mark spot as 2 if we have been there
    // mark as 3 if it does not work
    // return true when we finally make it through
    // take our array and it should have a path of 2's

    return 0;
}
