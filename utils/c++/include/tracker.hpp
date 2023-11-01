#ifndef __TRACKER__HPP
#define __TRACKER_HPP

class Tracker{
    
    private:
        int ***prevPoints;
        int ***currentPoints;
    
    public:
        Tracker();

        void stablePoints(int *points, int size, int **pointsOut);

        void track(int ***currentPoints, int ***prevPoints, short int sizeCurrent, short int sizePrev);

};


#endif