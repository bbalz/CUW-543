#include <iostream>

class SparseMatrixNode {
public:
    int row;
    int column;
    int value;
    SparseMatrixNode* next;

    SparseMatrixNode(int r, int c, int v) : row(r), column(c), value(v), next(nullptr) {}
};

class SparseMatrixLinkedList {
private:
    SparseMatrixNode* start;

public:
    SparseMatrixLinkedList() : start(nullptr) {}

    ~SparseMatrixLinkedList() {
        SparseMatrixNode* current = start;
        while (current != nullptr) {
            SparseMatrixNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insert(int row, int column, int value) {
        SparseMatrixNode* newNode = new SparseMatrixNode(row, column, value);


        if (start == nullptr) {
            start = newNode;
            return;
        }

        SparseMatrixNode* current = start;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        SparseMatrixNode* current = start;
        std::cout << "Sparse Matrix Linked List Representation:" << std::endl;
        while (current != nullptr) {
            std::cout << "Row: " << current->row << ", Column: " << current->column << ", Value: " << current->value << std::endl;
            current = current->next;
        }
    }
};

int main() {
    int matrix[4][5] = {
        {0, 3, 0, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    SparseMatrixLinkedList sparseMatrix;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] != 0) {
                sparseMatrix.insert(i, j, matrix[i][j]);
            }
        }
    }

    sparseMatrix.display();

    return 0;
}
