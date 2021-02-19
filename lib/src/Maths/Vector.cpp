/*=========================================================================

  Library:   P3DS
  File:      Vector.cpp

=========================================================================*/

#include "Maths/Vector.h"
#include "Details.h"

namespace peds {

void Vector::Hello()
{
  this->Variable++;
  Details::Hello();
}

void Vector::UnusedFunction()
{
  this->Variable += 2;
}

}
