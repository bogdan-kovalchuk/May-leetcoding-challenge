#include <iostream>
#include <utility>
#include <stack>

using std::string;
using std::vector;

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        while (!stock.empty() && stock.top().first <= price) {
            stock.pop();
            i++;
        }
        int out = stock.empty() ? i : (i + 1 - stock.top().second);
        stock.push({price, i});
        return out;
    }

private:
    std::stack<std::pair<int, int>> stock;
    int i = 1;
};

int main() {
    auto *S = new StockSpanner();
//    std::cout << S->next(100) << std::endl;
//    std::cout << S->next(80) << std::endl;
//    std::cout << S->next(60) << std::endl;
//    std::cout << S->next(70) << std::endl;
//    std::cout << S->next(60) << std::endl;
//    std::cout << S->next(75) << std::endl;
//    std::cout << S->next(85) << std::endl;

//    std::cout << S->next(31) << std::endl; // returns 1,
//    std::cout << S->next(41) << std::endl; // returns 1,
//    std::cout << S->next(48) << std::endl; // returns 1,
//    std::cout << S->next(40) << std::endl; // returns 2,
//    std::cout << S->next(79) << std::endl; // returns 1,

    std::cout << S->next(28) << std::endl; // returns 1,
    std::cout << S->next(28) << std::endl; // returns 1,
    std::cout << S->next(28) << std::endl; // returns 1,
    std::cout << S->next(28) << std::endl; // returns 1,
    return 0;
}
