#include <iostream>
#include <queue>
#include <cassert>
#include <vector>

int timeRequiredToBuy(std::vector<int> tickets, int k) {
    int time = 0;
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < tickets.size(); i++) {
        queue.push({i, tickets[i]});
    }
    while (true) {
        time++;
        auto person = queue.front();
        queue.pop();
        person.second--;
        if (person.second == 0 && person.first == k) break;
        if (person.second != 0) queue.push(person);
    }
    return time;
}

void test_timeRequiredToBuy() {
    std::vector<int> tickets1 = {2, 3, 2};
    assert(timeRequiredToBuy(tickets1, 2) == 6);

    std::vector<int> tickets2 = {5, 1, 1, 1};
    assert(timeRequiredToBuy(tickets2, 0) == 8);
}

int main() {
    test_timeRequiredToBuy();
    std::cout << "All tests pass\n";
}