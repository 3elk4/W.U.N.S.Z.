#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <set>
#include "point.h"
#include "constants.h"
#include "barrier.h"

class FrameAndBarrier {
public:
	FrameAndBarrier();
	~FrameAndBarrier();

	set<Point> getFrame();
	void initFrame();

	Barrier* getBarrier();
	void setBarrier(Barrier *barrier);

	BoxSize getFrameSize();
	void setFrameSize(BoxSize fs);

	Point getFrameStaringPoint();
	void setFrameStartingPoint(Point p);


private:
	set<Point> frame;
	Barrier *obstacle;
	BoxSize frameSize;
	Point frameStartingPoint;
};



#endif // FRAME_H
