#ifndef PAAQUIZ2_LEVEL_H
#define PAAQUIZ2_LEVEL_H

class Levels
{
public:
    double level(int size)
    {
        if(size==8)
            return(.15);

        if(size==9)
            return(.2);

        if(size==10)
            return(.3);

        if(size==11)
            return(.35);

        if(size==12)
            return(.3);
    }
};

#endif //PAAQUIZ2_LEVEL_H
