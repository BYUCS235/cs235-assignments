#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Grid.h"

bool solve_helper(Grid& maze, int row, int column, int level, std::vector<std::array<int, 3>>& path) {
    path.push_back({ row, column, level });
    if (row + 1 == maze.height() && column + 1 == maze.width() && level + 1 == maze.depth()) {
        return true;
    }
    maze.at(row, column, level) = 2;

    if (row + 1 < maze.height() && maze.at(row + 1, column, level) == 1 && solve_helper(maze, row + 1, column, level, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    if (column + 1 < maze.width() && maze.at(row, column + 1, level) == 1 && solve_helper(maze, row, column + 1, level, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    if (level + 1 < maze.depth() && maze.at(row, column, level + 1) == 1 && solve_helper(maze, row, column, level + 1, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    if (row - 1 >= 0 && maze.at(row - 1, column, level) == 1 && solve_helper(maze, row - 1, column, level, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    if (column - 1 >= 0 && maze.at(row, column - 1, level) == 1 && solve_helper(maze, row, column - 1, level, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    if (level - 1 >= 0 && maze.at(row, column, level - 1) == 1 && solve_helper(maze, row, column, level - 1, path)) {
        maze.at(row, column, level) = 1;
        return true;
    }

    maze.at(row, column, level) = 1;
    path.pop_back();
    return false;
}

bool solve_maze(Grid& maze, std::vector<std::array<int, 3>>& path) {
    return solve_helper(maze, 0, 0, 0, path);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " [MAZE FILE] [SOLUTION FILE]" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Couldn't open " << argv[1] << " for reading";
        return 1;
    }
    Grid maze;
    fin >> maze;
    fin.close();

    std::ofstream fout(argv[2]);
    if (!fout) {
        std::cerr << "Couldn't open " << argv[2] << " for writing";
        return 1;
    }

    std::vector<std::array<int, 3>> path;
    if (solve_maze(maze, path)) {
        fout << "SOLUTION" << std::endl;
        for (const auto& coord : path) {
            fout << coord[0] << ' ' << coord[1] << ' ' << coord[2] << std::endl;
        }
    } else {
        fout << "NO SOLUTION" << std::endl;
    }
    fout.close();

    return 0;
}
