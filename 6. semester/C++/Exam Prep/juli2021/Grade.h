#ifndef GRADE_H
#define GRADE_H

class Grade {
public:
    Grade(int point = 0, float weight = 100.0f) : mPoint(point), mWeight(weight) {}

    int   getPoint()   const { return mPoint;  }
    float getWeight()  const { return mWeight; }

    // vægtet bidrag (0-100 skala)
    float weightedGrade() const { return mPoint * mWeight / 100.0f; }

private:
    int   mPoint;   // 0-100 %
    float mWeight;  // 0-100 %
};

#endif // GRADE_H
