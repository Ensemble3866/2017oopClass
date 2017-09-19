#include "include/Sort.h"
#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>

void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape * first, Shape * second)
	{ 
		return first->perimeter() < second->perimeter(); 
	});
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape * first, Shape * second)
	{
		return first->perimeter() > second->perimeter();
	});
}

void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape * first, Shape * second)
	{
		return first->area() < second->area();
	});
}

void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape * first, Shape * second)
	{
		return first->area() > second->area();
	});
}
  
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape * first, Shape * second)
	{
		return (first->area() / first->perimeter()) < (second->area() / second->perimeter());
	});
}