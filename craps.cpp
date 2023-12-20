#include <iostream>
#include <ctime>
#include <random>
#include <format>

enum class GameStatus {inProgress, won, lost};

using enum GameStatus;
using std::cout;
using std::endl;
using std::format;

GameStatus firstRoll(int& point);
GameStatus nextRoll(int const& point);

std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<int> randomInt{1, 6};

int main(int argc, char **argv) {
//    default_random_engine engine{time(0)};
//    const uniform_int_distribution<int> randomInt{1, 6};

    int point{0};

    GameStatus game{firstRoll(point)};

    while (inProgress == game) {
        game = nextRoll(point);
    }

    if (won == game) {
        cout << "Player won!\n";
    } else {
        cout << "Player lost!\n";
    }

    return 0;
}

void showRoll(int roll1, int roll2) {
    cout << "Player rolled: " << roll1 << " + " << roll2 << " = " << (roll1 + roll2) << endl;
}

GameStatus firstRoll(int& point) {
    GameStatus game{inProgress};

    const int roll1{randomInt(engine)};
    const int roll2{randomInt(engine)};
    const int total{roll1 + roll2};

    showRoll(roll1, roll2);

    switch (total) {
        case 7:
        case 11:
            game = won;
            break;
        case 2:
        case 3:
        case 12:
            game = lost;
            break;
        default:
            point = total;
            cout << "Player needs to roll " << point << "!\n";
            break;
    }

    return game;
}

GameStatus nextRoll(int const& point) {
    GameStatus game{inProgress};

    const int roll1{randomInt(engine)};
    const int roll2{randomInt(engine)};
    const int total{roll1 + roll2};

    showRoll(roll1, roll2);

    switch (total) {
        case 7:
        case 11:
            game = lost;
            break;
        default:
            if (point == total) {
                game = won;
            }
            break;
    }

    return game;
}

