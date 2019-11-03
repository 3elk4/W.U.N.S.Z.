#ifndef BOXSIZE_H
#define BOXSIZE_H

struct BoxSize{
    int boxWidth;
    int boxHeight;

    BoxSize(){
        this->boxWidth = 0;
        this->boxHeight = 0;
    }

    BoxSize(int width, int height){
        this->boxWidth = width;
        this->boxHeight = height;
    }
};

#endif // BOXSIZE_H
