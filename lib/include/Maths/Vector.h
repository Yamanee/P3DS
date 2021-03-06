/*=========================================================================

  Library:   P3DS
  File:      Vector.h

=========================================================================*/

#ifndef PEDS_VECTOR_H
#define PEDS_VECTOR_H

#include "peds_export.h"

namespace peds {

/**
 * @class   Vector
 * @brief   Vector dummy class
 */
class PEDS_EXPORT Vector {
public:
  /**
   * Default constructor
   */
  Vector() = default;

  /**
   * Default destructor
   */
  ~Vector() = default;

  /**
   * Hello World function :)
   */
  void Hello();

  void UnusedFunction();

private:
  /**
   * Dummy :)
   */
  int Variable = 0;
};

} // namespace peds

#endif // PEDS_VECTOR_H
