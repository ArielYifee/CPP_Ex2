#include <string>
#include <vector>
#include "Direction.hpp"

#pragma once
namespace ariel{
    class Board{
        public:
            Board();
            Board(unsigned int row,unsigned int col);
            ~Board();
            void post(unsigned int row, unsigned int column, Direction direction, std::string message);
            std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
            void show();
        private:
            std::vector<std::vector<char>> board;
    };
}