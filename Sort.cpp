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
		std::cout << first->getShapeName() << ':' << (4*M_PI*first->area()) / pow(first->perimeter(),2) << std::endl;
		std::cout << second->getShapeName() << ':' << (4*M_PI*second->area()) / pow(second->perimeter(), 2) << std::endl;
		return (4*M_PI*first->area()) / pow(first->perimeter(),2) < (4*M_PI*second->area()) / pow(second->perimeter(), 2);
	});
}