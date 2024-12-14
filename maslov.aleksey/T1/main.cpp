#include "shape.hpp"
#include "inputShape.hpp"
#include "base-types.hpp"
#include "shapeManipulator.hpp"
#include <iostream>
#include <iomanip>


int main()
{
  constexpr int maxShapes = 10000;
  maslov::Shape * shapes[maxShapes] = {};
  size_t count = 0;
  try
  {
    count = maslov::inputShapes(std::cin, shapes);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    destroyShapes(shapes, count);
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  if (!(std::cin >> centerX >> centerY >> scaleFactor))
  {
    throw std::invalid_argument("Incorrect parameters");
    destroyShapes(shapes, count);
    return 1;
  }
  maslov::point_t scaleCoordinate = {centerX, centerY};

  std::cout << std::fixed << std::setprecision(1);
  std::cout << maslov::getSumArea(shapes, count);
  maslov::printCoordinates(shapes, count);
  std::cout << "\n";
  maslov::scaleShapes(shapes, count, scaleCoordinate, scaleFactor);
  std::cout << getSumArea(shapes, count);
  maslov::printCoordinates(shapes, count);
  std::cout << "\n";
  destroyShapes(shapes, count);
}