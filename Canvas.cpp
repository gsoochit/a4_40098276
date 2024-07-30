#include "Canvas.h"
#include <algorithm> // For std::max and std::min
#include <stdexcept> // For std::out_of_range

// Constructor that initializes a 10x10 canvas
Canvas::Canvas()
    : Canvas(10, 10) {}

// Parameterized constructor
Canvas::Canvas(int rows, int columns, char fillChar)
    : grid(rows, vector<char>(columns, fillChar)),
      fillChar(fillChar) {}

// Checks if the row and column are within bounds
bool Canvas::check(int r, int c) const {
    return r >= 0 && r < getRows() && c >= 0 && c < getColumns();
}

// Returns the fill character
char Canvas::getFillChar() const {
    return fillChar;
}

// Sets the fill character
void Canvas::setFillChar(char ch) {
    fillChar = ch;
    fill(ch); // Fill the entire canvas with the new character
}

// Returns the vertical frame character
char Canvas::getFrame_ver() const {
    return frame_ver;
}

// Sets the vertical frame character
void Canvas::setFrame_ver(char ch) {
    frame_ver = ch;
}

// Returns the horizontal frame character
char Canvas::getFrame_hor() const {
    return frame_hor;
}

// Sets the horizontal frame character
void Canvas::setFrame_hor(char ch) {
    frame_hor = ch;
}

// Returns the corner frame character
char Canvas::getFrame_cor() const {
    return frame_cor;
}

// Sets the corner frame character
void Canvas::setFrame_cor(char ch) {
    frame_cor = ch;
}

// Returns the number of rows
int Canvas::getRows() const {
    return grid.size();
}

// Returns the number of columns
int Canvas::getColumns() const {
    return grid.empty() ? 0 : grid[0].size();
}

// Flips the canvas horizontally
Canvas Canvas::flip_horizontal() const {
    Canvas flipped(*this);
    for (auto& row : flipped.grid) {
        std::reverse(row.begin(), row.end());
    }
    return flipped;
}

// Flips the canvas vertically
Canvas Canvas::flip_vertical() const {
    Canvas flipped(*this);
    std::reverse(flipped.grid.begin(), flipped.grid.end());
    return flipped;
}

// Print canvas to ostream
void Canvas::print(std::ostream& os) const {
    // Print top frame
    os << "+";
    for (int i = 0; i < getColumns(); ++i) {
        os << "-";
    }
    os << "+" << std::endl;

    // Print canvas content
    for (int i = 0; i < getRows(); ++i) {
        os << "|";
        bool hasChar = false;
        for (int j = 0; j < getColumns(); ++j) {
            if (grid[i][j] != ' ') {
                hasChar = true;
            }
            os << grid[i][j];
        }
        if (hasChar) {
            os << "  |";
        } else {
            os << "|";
        }
        os << std::endl;
    }

    // Print bottom frame
    os << "+";
    for (int i = 0; i < getColumns(); ++i) {
        os << "-";
    }
    os << "+" << std::endl;
}

// Retrieves a character from the grid
char Canvas::get(int r, int c) const {
    if (!check(r, c)) {
        throw std::out_of_range("Canvas index out of range");
    }
    return grid[r][c];
}

// Places a character in the grid
void Canvas::put(int r, int c, char ch) {
    if (!check(r, c)) {
        throw std::out_of_range("Canvas index out of range");
    }
    grid[r][c] = ch;
}

// Fills the canvas with the specified character
void Canvas::fill(char ch) {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), ch);
    }
}


// Write text horizontally
// void Canvas::write_horizontal(int r, int c, const std::string text) {
//     for (int i = 0; i < text.length(); ++i) {
//         if (check(r, c + i)) {
//             grid[r][c + i] = text[i];
//         }
//     }
//     // Fill the rest of the row with spaces
//     for (int i = text.length() + c; i < getColumns(); ++i) {
//         grid[r][i] = ' ';
//     }
// }
// Write text horizontally
void Canvas::write_horizontal(int r, int c, const std::string text) {
    if (c >= 1 && c <= getColumns()) {
        c -= 1; // Convert to 0-based index
        if (r >= 1 && r <= getRows()) {
            r -= 1; // Convert to 0-based index
            for (size_t i = 0; i < text.size(); ++i) {
                if (c + i < getColumns()) {
                    grid[r][c + i] = text[i];
                }
            }
        }
    }
}


// Writes a string vertically to the canvas
void Canvas::write_vertical(int r, int c, const std::string text) {
    if (c >= 1 && c <= getColumns()) {
        c -= 1; // Convert to 0-based index
        if (r >= 1 && r <= getRows()) {
            r -= 1; // Convert to 0-based index
            for (size_t i = 0; i < text.size(); ++i) {
                if (r + i < getRows()) {
                    grid[r + i][c] = text[i];
                }
            }
        }
    }
}

// Overlays another canvas onto the current one
void Canvas::overlay(const Canvas& can, size_t r, size_t c) {
    for (size_t i = 0; i < can.getRows(); ++i) {
        for (size_t j = 0; j < can.getColumns(); ++j) {
            if (can.grid[i][j] != can.fillChar) {
                if (r + i < getRows() && c + j < getColumns()) {
                    grid[r + i][c + j] = can.grid[i][j];
                }
            }
        }
    }
}

// Concatenates the current canvas with another canvas
Canvas Canvas::concat(const Canvas& can) const {
    int newRows = std::max(getRows(), can.getRows());
    int newCols = getColumns() + can.getColumns();

    Canvas newCanvas(newRows, newCols, fillChar);
    newCanvas.resizeRows(getRows());
    newCanvas.overlay(*this, 0, 0);
    newCanvas.overlay(can, 0, getColumns());

    return newCanvas;
}

// Resizes the number of rows
void Canvas::resizeRows(size_t n) {
    if (n > getRows()) {
        grid.resize(n, vector<char>(getColumns(), fillChar));
    } else {
        grid.resize(n);
    }
}

// Overloaded addition operator
Canvas operator+(const Canvas& left_can, const Canvas& right_can) {
    return left_can.concat(right_can);
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& sout, const Canvas& can) {
    can.print(sout);
    return sout;
}

