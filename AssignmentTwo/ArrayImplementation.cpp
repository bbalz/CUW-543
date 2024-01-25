#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<std::vector<int>> fullMatrix;
    std::vector<std::vector<int>> compactMatrix;
    int rows, cols; 

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), fullMatrix(r, std::vector<int>(c, 0)) {}

    void addElement(int r, int c, int value) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "ERROR -- Index out of bounds. Element not added." << std::endl;
            return;
        }
        fullMatrix[r][c] = value;
    }

    void createCompactRepresentation() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (fullMatrix[i][j] != 0) {
                    compactMatrix.push_back({i, j, fullMatrix[i][j]});
                }
            }
        }
    }

    void displayCompactMatrix() {
        std::cout << "Row\tColumn\tValue" << std::endl;
        for (const auto &element : compactMatrix) {
            std::cout << element[0] << "\t" << element[1] << "\t" << element[2] << std::endl;
        }
    }

    void displayFullMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << fullMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }
};

int main() {
    SparseMatrix sm(4, 5);

    sm.addElement(0, 0, 0);
    sm.addElement(0, 1, 0);
    sm.addElement(0, 2, 0);
    sm.addElement(0, 3, 4);
    sm.addElement(0, 4, 0);
    sm.addElement(1, 0, 5);
    sm.addElement(1, 1, 0);
    sm.addElement(1, 2, 0);
    sm.addElement(1, 3, 7);
    sm.addElement(1, 4, 0);
    sm.addElement(2, 0, 0);
    sm.addElement(2, 1, 0);
    sm.addElement(2, 2, 6);
    sm.addElement(2, 3, 0);
    sm.addElement(2, 4, 0);
    sm.addElement(3, 0, 0);
    sm.addElement(3, 1, 0);
    sm.addElement(3, 2, 0);
    sm.addElement(3, 3, 0);
    sm.addElement(3, 4, 0);

    sm.createCompactRepresentation();

    std::cout << "Full Matrix:\n";
    sm.displayFullMatrix();

    std::cout << "\nCompact Representation:\n";
    sm.displayCompactMatrix();

    return 0;
}
