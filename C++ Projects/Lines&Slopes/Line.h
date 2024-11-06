
class Line{
public:
    //Constructors
    Line();
    Line(float, float, float);
    Line(float, float);
    Line(float);

    //Public functions or Variables
    void printPointSlope()const;
    void printSlopeIntercept()const;
    void printStandard()const;
    Line getPerpendicular()const;
    void Intersection(Line)const;

    //Getters
    float getXcoord() const;
    float getYcoord() const;
    float getSlope() const;

    //Setters
    void setXcoord(float);
    void setYcoord(float);
    void setSlope(float);

private://Private Variables that should not be accessed.
    float xCoord;
    float yCoord;
    float slope;
};