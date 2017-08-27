#ifndef COORDINATE_H
#define COORDINATE_H
#include <string>

//using namespace std;

class Coordinate
{
    int x, y;
    bool infected;
    int startInfection;

    public:
        Coordinate(int, int);
        int getX ();
        int getY ();
        void setX (int);
        void setY (int);
        void setInfected ();
        bool isInfected ();
        std::string toString();
        int getStartInfection();
        void countStartInfection();
};

#endif // COORDINATE_H
