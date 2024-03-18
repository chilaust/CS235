#include <iostream>
#include <string>
#include <fstream>
#include "Grid.h"
#include <vector>

bool findPath (int x, int y, int z, int height, int width, int depth, std::vector<std::string> &solution, Grid &maze) {

        solution.push_back(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z)); //starting point added to solution

        //if this point is the oposite corner return true
        if (x == height - 1 && y == width - 1 && z == depth - 1) {
            return true;
        }

        //out of range
        if (x < 0 || x > height - 1 || y < 0 || y > width - 1 || z < 0 || z > depth - 1) {
            solution.pop_back(); //pull the solution off
            return false;
        }

        //already been here, or it is not a path
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
        solution.pop_back();
//        maze.at(x,y,z) = 1;
        return false;

}

int main(int argc, char* argv[]) {
//     open the input file
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << "input_file/n";
        return 1;
    }


    std::string in = argv[1];
    std::ifstream input_file(in);
    std::string output_file = argv[2];
    std::ofstream out(output_file);

    //read in grid
    Grid maze;
    input_file >> maze;

    //set maze dimensions
    int height = maze.height();
    int width = maze.width();
    int depth = maze.depth();

    //process maze
    std::vector<std::string> solution;
    if (findPath(0,0,0, height, width, depth, solution, maze)) { //find path outputs a bool and changes solution and maze passed as a reference
        out << "SOLUTION" << std::endl;

        for (std::string point : solution) { //go through solution line by line and output to out
            out << point << std::endl;
        }
    }
    else {
        out << "NO SOLUTION";
    }

    return 0;
}
