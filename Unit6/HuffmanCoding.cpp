#include <iostream>
#include <queue>
#include <vector>

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};


void printCodes(struct MinHeapNode* root, std::vector<int>& arr) {
    if (!root->left && !root->right) {
        std::cout << root->data << " ";
        for (int i : arr) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    if (root->left) {
        arr.push_back(0);
        printCodes(root->left, arr);
        arr.pop_back();
    }

    if (root->right) {
        arr.push_back(1);
        printCodes(root->right, arr);
        arr.pop_back();
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    std::vector<int> arr;
    printCodes(minHeap.top(), arr);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}
