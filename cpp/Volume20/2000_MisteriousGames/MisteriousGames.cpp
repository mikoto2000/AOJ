#include <iostream>
#include <stdio.h>

using namespace std;

class Vector {
    private:
        int x;
        int y;

    public:
        Vector(int x, int y);
        void add(Vector* v);
        bool operator ==(const Vector &obj);
};

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
};

void Vector::add(Vector* v) {
    this->x += v->x;
    this->y += v->y;
}

bool Vector::operator ==(const Vector &obj) {
    if (x == obj.x
            && y == obj.y) {
        return true;
    } else {
        return false;
    }
}

class Game {
    public:
        Vector* robotPos;
        int gemNum;
        Vector **gemPos;
        bool *gotGems;

        Game(int gemNum);
        ~Game();
        void walkRobot(char way, int distance);
        bool isAllGot();
};

Game::Game(int gemNum) {
    this->gemNum = gemNum;

    // init robot vector.
    robotPos = new Vector(10, 10);

    // create got gems.
    gotGems = new bool[gemNum];

    // read gem vectors
    // and init got gems.
    gemPos = new Vector*[gemNum];
    for (int i = 0; i < gemNum; i++) {
        int x,y;
        cin >> x >> y;

        gemPos[i] = new Vector(x, y);
        gotGems[i] = false;
    }
}

Game::~Game() {
    delete robotPos;
    for (int i = 0; i < gemNum; i++) {
        delete gemPos[i];
    }
}

void Game::walkRobot(
        char way, int distance) {
    Vector *v;
    switch (way) {
        case 'N':
            v = new Vector(0, 1);
            break;
        case 'E':
            v = new Vector(1, 0);
            break;
        case 'W':
            v = new Vector(-1, 0);
            break;
        case 'S':
            v = new Vector(0, -1);
            break;
    }

    Vector *robotPos = this->robotPos;
    for (int i = 0; i < distance; i++) {
        robotPos->add(v);

        int gemNum = this->gemNum;
        Vector **gemPos = this->gemPos;
        bool *gotGems = this->gotGems;
        for (int j = 0; j < gemNum; j++) {
            if (*robotPos == *gemPos[j]) {
                gotGems[j] = true;
            }
        }
    }

    delete v;
}

bool Game::isAllGot() {
    bool isAllGot = true;
    for (int i = 0; i < this->gemNum; i++) {
        if (!this->gotGems[i]) {
            isAllGot = false;
        }
    }
    return isAllGot;
}

int main(int argc, char const* argv[])
{
    int gemNum;
    while (cin >> gemNum) {
        if (gemNum == 0) {
            break;
        }

        // create game object.
        Game *game = new Game(gemNum);

        // run robot.
        int walkNum;
        cin >> walkNum;
        for (int i = 0; i < walkNum; i++) {
            char way;
            int distance;
            cin >> way >> distance;

            game->walkRobot(way, distance);
        }

        // check got gems.
        if (game->isAllGot()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

        // clean game.
        delete game;
    }

    return 0;
}
