#include "makeShape.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  Rectangle * makeRectangle(std::istream& in);
  Diamond * makeDiamond(std::istream& in);
  Polygon * makePolygon(std::istream& in);
}

mozhegova::Shape * mozhegova::makeShape(std::istream& in, std::string shapeName)
{
  if (shapeName == "RECTANGLE")
  {
    return mozhegova::makeRectangle(in);
  }
  else if (shapeName == "DIAMOND")
  {
    return mozhegova::makeDiamond(in);
  }
  else if (shapeName == "POLYGON")
  {
    return mozhegova::makePolygon(in);
  }
  else
  {
    throw std::logic_error("unsupported");
  }
}

mozhegova::Rectangle * mozhegova::makeRectangle(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double p3 = 0.0;
  double p4 = 0.0;
  in >> p1 >> p2 >> p3 >> p4;
  point_t lowLef = {p1, p2};
  point_t uppRig = {p3, p4};
  if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  mozhegova::Rectangle * rect = new mozhegova::Rectangle(lowLef, uppRig);
  return rect;
}

mozhegova::Diamond * mozhegova::makeDiamond(std::istream& in)
{
  double p1 = 0.0;
  double p2 = 0.0;
  double p3 = 0.0;
  double p4 = 0.0;
  double p5 = 0.0;
  double p6 = 0.0;
  in >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
  point_t pCent = {p1, p2};
  point_t pVert = {p3, p4};
  point_t pHori = {p5, p6};
  point_t p = {0, 0};
  if (pCent.x == pHori.x && pCent.y == pVert.y)
  {
    p = pVert;
    pVert = pHori;
    pHori = p;
  }
  else if (pVert.x == pCent.x && pVert.y == pHori.y)
  {
    p = pVert;
    pVert = pCent;
    pCent = p;
  }
  else if (pVert.x == pHori.x && pVert.y == pCent.y)
  {
    p = pCent;
    pCent = pVert;
    pVert = pHori;
    pHori = p;
  }
  else if (pHori.x == pCent.x && pHori.y == pVert.y)
  {
    p = pCent;
    pCent = pHori;
    pHori = pVert;
    pVert = p;
  }
  else if (pHori.x == pVert.x && pHori.y == pCent.y)
  {
    p = pHori;
    pHori = pCent;
    pCent = p;
  }
  else if (!(pCent.x == pVert.x && pCent.y == pHori.y))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  Diamond * diam = new Diamond(pCent, pVert, pHori);
  return diam;
}

mozhegova::Polygon * mozhegova::makePolygon(std::istream& in)
{
  size_t len = 0;
  size_t i = 0;
  double * num = new double [len];
  double p = 0.0;
  while (in.peek() != '\n')
  {
    in >> p;
    if (i == len)
    {
      double * newnum = nullptr;
      try
      {
        newnum = new double [len + 2];
        for (size_t i = 0; i < len; i++)
        {
          newnum[i] = num[i];
        }
      }
      catch (const std::bad_alloc& e)
      {
        delete[] num;
        throw;
      }
      delete[] num;
      num = newnum;
      len += 2;
    }
    num[i] = p;
    i++;
  }
  if (len < 6)
  {
    delete[] num;
    throw std::invalid_argument("Incorrect coordinates");
  }
  point_t * numPoint = nullptr;
  try
  {
    numPoint = new mozhegova::point_t [len / 2];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] num;
    throw;
  }
  for (size_t i = 0; i < len / 2; i++)
  {
    numPoint[i] = {num[i * 2], num[i * 2 + 1]};
  }
  for (size_t i = 0; i < (len - 1) / 2; i++)
  {
    for (size_t j = i + 1; j < len / 2; j++)
    {
      if (numPoint[i].x == numPoint[j].x && numPoint[i].y == numPoint[j].y)
      {
        delete[] num;
        delete[] numPoint;
        throw std::invalid_argument("Incorrect coordinates");
      }
    }
  }
  Polygon * poly = new mozhegova::Polygon(len / 2, numPoint);
  delete[] num;
  delete[] numPoint;
  return poly;
}
