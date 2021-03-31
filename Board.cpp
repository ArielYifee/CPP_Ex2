#include "Board.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;
unsigned int col_len;
unsigned int row_len;
const unsigned int extra_len = 100;

namespace ariel{
    Board::Board(){
        col_len = 0;
        row_len = 0;
    }
    Board::Board(unsigned int row, unsigned int col){
        board.resize(row, vector<char>(col, '_'));
        col_len = col;
        row_len = row;
    }
    Board::~Board(){
        col_len = 0;
        row_len = 0;
    }
    void Board::post(unsigned int row, unsigned int column, Direction direction, string message){
        unsigned int message_len = message.size();
        int direc = 0;
        if(direction == Direction::Horizontal){
            direc = 1;
        }
        unsigned int new_row = row;
        unsigned int new_col = column;
        if(direc == 1){
            new_col += message_len;
        }else{
            new_row += message_len;
        }
        if (new_col > col_len){
            col_len = new_col + extra_len;
            for (size_t i = 0; i < row_len; i++){
                board[i].resize(col_len, '_');
            }
        }
        if (new_row >= row_len){
            row_len = new_row + extra_len;
            vector<char> new_vec(col_len, '_');
            board.resize(row_len, new_vec);
        }
        for (char word : message){
            board[row][column] = word;
            if(direc == 1){
                column++;
            }else{
                row++;
            }
        }
    }
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length){
        int direc = 0;
        if(direction == Direction::Horizontal){
            direc = 1;
        }
        unsigned int new_row = row;
        unsigned int new_col = column;
        if(direc == 1){
            new_col += length;
        }else{
            new_row += length;
        }
        string ans;
        if (length == 0 || row_len <= new_row || col_len <= new_col){
            for (int i = 0; i < length; i++){
                ans += '_';
            }
            return ans;
        }
        if(direc == 1){
            for(unsigned int i = column; i < new_col; i++){
                ans += board[row][i];
            }
        }else{
            for(unsigned int i = row; i < new_row; i++){
                ans += board[i][column];
            }
        }
        return ans;
    }
    void Board::show(){
        for (unsigned int i = 0; i < row_len; i++){
            int first_word = -1;
            for (unsigned int j = 0; j < col_len && first_word == -1; j++){
                if (board[i][j] != '_'){
                    first_word = (int)j;
                }
            }
            if (first_word != -1){
                cout << "line:" << i << " -";
                for (unsigned int j = (unsigned int)first_word; j < col_len; j++){
                    cout << board[i][j];
                }
                cout << endl;
            }
        }
    }
}