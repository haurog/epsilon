#ifndef SHARED_CONTINUOUS_FUNCTION_CACHE_H
#define SHARED_CONTINUOUS_FUNCTION_CACHE_H

#include <ion/display.h>
#include <poincare/context.h>
#include <poincare/coordinate_2D.h>

namespace Shared {

class ContinuousFunction;

class ContinuousFunctionCache {
public:
  /* The size of the cache is chosen to optimize the display of cartesian
   * function */
  static constexpr int k_numberOfAvailableCaches = 2;

  static void PrepareForCaching(void * fun, ContinuousFunctionCache * cache, float tMin, float tStep);

  ContinuousFunctionCache() { clear(); }

  float step() const { return m_tStep; }
  void clear();
  Poincare::Coordinate2D<float> valueForParameter(const ContinuousFunction * function, Poincare::Context * context, float t);
private:
  /* The size of the cache is chosen to optimize the display of cartesian
   * function */
  static constexpr int k_sizeOfCache = Ion::Display::Width;
  static constexpr float k_cacheHitTolerance = 1e-3;

  static float StepFactor(ContinuousFunction * function);

  void invalidateBetween(int iInf, int iSup);
  void setRange(ContinuousFunction * function, float tMin, float tStep);
  int indexForParameter(const ContinuousFunction * function, float t) const;
  Poincare::Coordinate2D<float> valuesAtIndex(const ContinuousFunction * function, Poincare::Context * context, float t, int i);
  void pan(ContinuousFunction * function, float newTMin);

  float m_tMin, m_tStep;
  float m_cache[k_sizeOfCache];
  /* m_startOfCache is used to implement a circular buffer for easy panning
   * with cartesian functions. When dealing with parametric or polar functions,
   * m_startOfCache should be zero.*/
  int m_startOfCache;
};

}

#endif