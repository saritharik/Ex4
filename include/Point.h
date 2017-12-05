#ifndef EX4_POINT_H
#define EX4_POINT_H


class Point {
public:
    /**
     * Constuctor.
     * @param x the x value.
     * @param y the y value.
     */
    Point(int x, int y);
    /**
     * Return the x value.
     * @return the x.
     */
    int getX();
    /**
     * Return the y value.
     * @return the y.
     */
    int getY();

private:
    int x, y;
};


#endif //EX4_POINT_H
