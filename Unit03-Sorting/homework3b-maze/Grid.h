#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

class Grid {
public:
    Grid() : width_(0), height_(0), depth_(0) {}

    int width() const {
        return width_;
    }

    int height() const {
        return height_;
    }

    int depth() const {
        return depth_;
    }

    int& at(int row, int column, int level) {
        return const_cast<int&>(const_cast<const Grid&>(*this).at(row, column, level));
    }

    const int& at(int row, int column, int level) const {
        if (row < 0 || row >= height_) {
            std::stringstream error_message;
            error_message << "row coordinate is out of bounds: row = " << row
                << " but height = " << height_;
            throw std::out_of_range(error_message.str());
        }

        if (column < 0 || column >= width_) {
            std::stringstream error_message;
            error_message << "column coordinate is out of bounds: column = "
                << column << " but width = " << width_;
            throw std::out_of_range(error_message.str());
        }

        if (level < 0 || level >= depth_) {
            std::stringstream error_message;
            error_message << "level coordinate is out of bounds: level = "
                << level << " but depth = " << depth_;
            throw std::out_of_range(error_message.str());
        }

        return spaces[level * width_ * height_ + row * width_ + column];
    }

    friend std::istream& operator>>(std::istream& is, Grid& maze) {
        int height;
        int width;
        int depth;

        is >> height;
        if (!is) {
            throw std::runtime_error("can't read the height of the maze");
        }

        is >> width;
        if (!is) {
            throw std::runtime_error("can't read the width of the maze");
        }

        is >> depth;
        if (!is) {
            throw std::runtime_error("can't read the depth of the maze");
        }

        std::vector<int> spaces;
        spaces.reserve(height * width * depth);

        for (size_t d = 0; d < depth; ++d) {
            for (size_t r = 0; r < height; ++r) {
                for (size_t c = 0; c < width; ++c) {
                    int space;
                    is >> space;
                    if (!is) {
                        std::stringstream error_message;
                        error_message << "can't read the maze space at " << r << ' ' << c << ' ' << d;
                        throw std::runtime_error(error_message.str());
                    }
                    if (space != 0 && space != 1) {
                        std::stringstream error_message;
                        error_message << "got invalid space at " << r << ' ' << c << ' ' << d
                            << ": each space can only be 0 or 1, but this space is " << space;
                        throw std::runtime_error(error_message.str());
                    }
                    spaces.push_back(space);
                }
            }
        }

        // We don't update the maze's data members until now so that if the
        // reading process were to fail, the maze would be left in a valid state
        maze.width_ = width;
        maze.height_ = height;
        maze.depth_ = depth;
        maze.spaces = spaces;

        return is;
    }

private:
    int width_;
    int height_;
    int depth_;
    std::vector<int> spaces;
};
