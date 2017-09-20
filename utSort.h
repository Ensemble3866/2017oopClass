#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
	
	Rectangle testRectangle(0, 0, 2, 2);
	Circle testCircle(0, 0, 4);
	struct Coordinate p1 = {0, 0};
	struct Coordinate p2 = {2, 0};
	struct Coordinate p3 = {0, 2};
	Triangle testTriangle(p1, p2, p3);
	
	std::list<Shape *> testShapeList;
	testShapeList.push_back(&testRectangle);
	testShapeList.push_back(&testCircle);
	testShapeList.push_back(&testTriangle);
	
	Sort mySort;
	mySort.sortByIncreasingPerimeter(&testShapeList);
	
	std::list<Shape *>::iterator it = testShapeList.begin();
	
	ASSERT_EQ(*it, &testTriangle);
	*it++;
	ASSERT_EQ(*it, &testRectangle);
	*it++;
	ASSERT_EQ(*it, &testCircle);
}

TEST (Sort, sortByDecreasingPerimeter) {
	
	Rectangle testRectangle(0, 0, 2, 2);
	Circle testCircle(0, 0, 4);
	struct Coordinate p1 = {0, 0};
	struct Coordinate p2 = {2, 0};
	struct Coordinate p3 = {0, 2};
	Triangle testTriangle(p1, p2, p3);
	
	std::list<Shape *> testShapeList;
	testShapeList.push_back(&testRectangle);
	testShapeList.push_back(&testCircle);
	testShapeList.push_back(&testTriangle);
	
	Sort mySort;
	mySort.sortByDecreasingPerimeter(&testShapeList);
	
	std::list<Shape *>::iterator it = testShapeList.begin();
	
	ASSERT_EQ(*it, &testCircle);
	*it++;
	ASSERT_EQ(*it, &testRectangle);
	*it++;
	ASSERT_EQ(*it, &testTriangle);
}

TEST (Sort, sortByIncreasingArea) {
	
	Rectangle testRectangle(0, 0, 2, 2);
	Circle testCircle(0, 0, 4);
	struct Coordinate p1 = {0, 0};
	struct Coordinate p2 = {2, 0};
	struct Coordinate p3 = {0, 2};
	Triangle testTriangle(p1, p2, p3);
	
	std::list<Shape *> testShapeList;
	testShapeList.push_back(&testRectangle);
	testShapeList.push_back(&testCircle);
	testShapeList.push_back(&testTriangle);
	
	Sort mySort;
	mySort.sortByIncreasingArea(&testShapeList);
	
	std::list<Shape *>::iterator it = testShapeList.begin();
	
	ASSERT_EQ(*it, &testTriangle);
	*it++;
	ASSERT_EQ(*it, &testRectangle);
	*it++;
	ASSERT_EQ(*it, &testCircle);
}

TEST (Sort, sortByDecreasingArea) {
	
	Rectangle testRectangle(0, 0, 2, 2);
	Circle testCircle(0, 0, 4);
	struct Coordinate p1 = {0, 0};
	struct Coordinate p2 = {2, 0};
	struct Coordinate p3 = {0, 2};
	Triangle testTriangle(p1, p2, p3);
	
	std::list<Shape *> testShapeList;
	testShapeList.push_back(&testRectangle);
	testShapeList.push_back(&testCircle);
	testShapeList.push_back(&testTriangle);
	
	Sort mySort;
	mySort.sortByDecreasingArea(&testShapeList);
	
	std::list<Shape *>::iterator it = testShapeList.begin();
	
	ASSERT_EQ(*it, &testCircle);
	*it++;
	ASSERT_EQ(*it, &testRectangle);
	*it++;
	ASSERT_EQ(*it, &testTriangle);
}

TEST (Sort, sortByIncreasingCompactness) {
	
	Rectangle testRectangle(0, 0, 2, 2);
	Circle testCircle(0, 0, 4);
	struct Coordinate p1 = {0, 0};
	struct Coordinate p2 = {2, 0};
	struct Coordinate p3 = {0, 2};
	Triangle testTriangle(p1, p2, p3);
	
	std::list<Shape *> testShapeList;
	testShapeList.push_back(&testRectangle);
	testShapeList.push_back(&testCircle);
	testShapeList.push_back(&testTriangle);
	
	Sort mySort;
	mySort.sortByIncreasingCompactness(&testShapeList);
	
	std::list<Shape *>::iterator it = testShapeList.begin();

	ASSERT_EQ(*it, &testTriangle);
	*it++;
	ASSERT_EQ(*it, &testRectangle);
	*it++;
	ASSERT_EQ(*it, &testCircle);
}

#endif
