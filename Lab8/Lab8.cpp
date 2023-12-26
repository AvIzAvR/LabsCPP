#include <forward_list>
#include <algorithm>
#include <iostream>


int main() {
    std::forward_list<int> flist = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    flist.sort();

    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }

    flist.push_front(3);
    flist.push_front(1);

    std::cout << std::endl;
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    flist.remove(5);
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    auto it = std::find(flist.begin(), flist.end(), 1);
    if (it != flist.end()) {
        std::cout << "Element found: " << *it << std::endl;
    }

    flist.reverse();
    std::cout << std::endl;
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }
}
