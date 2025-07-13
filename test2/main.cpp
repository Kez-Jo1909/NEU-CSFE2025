#include <iostream>

class LinearList {
public:
    LinearList() : length(0) {}

    void input() {
        int val;
        while (length < 10) {
            std::cin >> val;
            data[length++] = val;
        }
    }

    void output() {
        for (int i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void sort() {
        for (int i = 0; i < length - 1; ++i) {
            for (int j = 0; j < length - 1 - i; ++j) {
                if (data[j] > data[j + 1]) {
                    int t = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = t;
                }
            }
        }
    }

    void insert(int val) {
        if (length >= 15) return;
        int i = 0;
        while (i < length && data[i] < val) ++i;
        for (int j = length; j > i; --j) {
            data[j] = data[j - 1];
        }
        data[i] = val;
        ++length;
    }

    void remove(int val) {
        int i = 0;
        while (i < length && data[i] != val) ++i;
        if (i == length) return;
        for (int j = i; j < length - 1; ++j) {
            data[j] = data[j + 1];
        }
        --length;
    }

private:
    int data[15];
    int length;
};

int main() {
    LinearList list;
    list.input();
    list.sort();
    list.output();

    int x;
    std::cin >> x;
    list.insert(x);
    list.output();

    std::cin >> x;
    list.remove(x);
    list.output();

    return 0;
}
