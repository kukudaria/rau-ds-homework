#include <iostream>
#include <queue>
#include <cassert>
#include <vector>

std::string hotPotato(std::vector<std::string> &people, int passes) {
    std::queue<std::string> players;
    for (int i = 0; i < people.size(); i++) {
        players.push(people[i]);
    }
    while (players.size() > 1) {
        for (int i = 0; i < passes; i++) {
            players.push(players.front());
            players.pop();
        }
        players.pop();
    }
    return players.front();
}

void test_hotPotato() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    assert(hotPotato(players, 7) == "Charlie");

    std::vector<std::string> players1 = {"Alice"};
    assert(hotPotato(players1, 5) == "Alice");

    std::vector<std::string> players2 = {"Alice", "Bob", "Charlie", "David"};
    assert(hotPotato(players2, 1) == "Alice");
}

int main() {
    test_hotPotato();
    std::cout << "All tests pass\n";
}