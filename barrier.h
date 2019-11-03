#ifndef BARRIER_H
#define BARRIER_H

#include "point.h"
#include "boxsize.h"
#include "constants.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Barrier {
protected:
    vector <Point> barrierBody;
    Point barrierStartingPoint;
    BoxSize size;

public:
    Barrier(BoxSize ptk);
    virtual void initBarrier() = 0; // virtual jak inne bariery

    Point getBarrierStartingPoint() const{
        return barrierStartingPoint;
    }
	void setBarrierStartingPoint(Point point) {
		this->barrierStartingPoint = Point(point);
	}

    BoxSize getBarrierSize() const{
        return size;
    }

    vector <Point> getBarrierShape() const {
        return barrierBody;
    }

    ~Barrier();
};

class lShapeBarrier : public Barrier {
public:
    lShapeBarrier() : Barrier(BoxSize(15, 17)) { }
    void initBarrier() override;
};

class cShapeBarrier : public Barrier {
public:
    cShapeBarrier() : Barrier(BoxSize(15, 17)) { }
    void initBarrier() override;
};

class lineBarrier : public Barrier {
public:
    //x > y ? horizontal : vertical
    lineBarrier() : Barrier(BoxSize(30, 1)) { }
    void initBarrier() override;
};

/*class swasticaBarrier : public Barrier {
public:
    swasticaBarrier() : Barrier({19, 19}) { }
    void initBarrier() override;
};*/

class snailBarrier : public Barrier {
public:
    snailBarrier() : Barrier(BoxSize(19, 19)) { }
    void initBarrier() override;
	~snailBarrier();
};

#endif // BARRIER_H
