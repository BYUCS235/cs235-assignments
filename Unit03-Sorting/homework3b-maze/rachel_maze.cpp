#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Grid.h"

bool find_maze_path(Grid& maze, std::vector<std::string>& solution, int x, int y, int z) {
    if (x < 0 || x >= maze.height() || y < 0 || y >= maze.width() || z < 0 || z >= maze.depth()) { //if we've gone out of bounds
        return false;
    }
    if (maze.at(x,y,z) == 2) { //if we've been here before. This prevents infinite recursion
        return false;
    }

    if (maze.at(x,y,z) == 0) { // if we've hit a wall
        maze.at(x,y,z) = 2;
        return false;
    }

    maze.at(x,y,z) = 2;

    if (x == maze.height() - 1 && y == maze.width() - 1 && z == maze.depth() - 1) { //if we're at the exit point of the maze
        std::string currPos = std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z); // make a string out of the current position
        solution.push_back(currPos); // if any of the recursive calls return true, add position to solution vector
        return true;
    }
    
    if (find_maze_path(maze, solution, x + 1, y, z) || 
        find_maze_path(maze, solution, x - 1, y, z) ||
        find_maze_path(maze, solution, x, y + 1, z) ||
        find_maze_path(maze, solution, x, y - 1, z) ||
        find_maze_path(maze, solution, x, y, z + 1) ||
        find_maze_path(maze, solution, x, y, z - 1)) { //recurse through the maze
            std::string currPos = std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z); // make a string out of the current position
            solution.push_back(currPos); // if any of the recursive calls return true, add position to solution vector
            return true;
    } else {
        // depending on where a student push_backs onto the solution vector, they may need a pop_back() here
        // I push_back only after find_maze_path returns true, so I don't need it
        return false;
    }
    
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]); // open input file
    std::ofstream out(argv[2]); //open output file

    if (!in.is_open()) {
        std::cerr << "Error opening " << argv[1] << std::endl;
        return 2;
    }

    if (!out.is_open()) {
        std::cerr << "Error opening " << argv[2] << std::endl;
        return 3;
    }

    Grid maze;

    in >> maze; // calls >> operator overload in Grid.h to read maze

    std::vector<std::string> solution;

    if (find_maze_path(maze, solution, 0,0,0)) {
        out << "SOLUTION" << std::endl;
        std::reverse(solution.begin(), solution.end()); // solution vector ends up reversed so you either need to reverse it or iterate through it backwards
        for (unsigned int i = 0; i < solution.size(); i++) {
            out << solution.at(i) << std::endl;
        }
    } else {
        out << "NO SOLUTION" << std::endl;
    }
    

    return 0;
}