#include <poincare/cosinus.h>
#include "layout/horizontal_layout.h"

Expression * Cosinus::clone() {
  return new Cosinus(m_arg, true);
}

Expression::Type Cosinus::type() {
  return Expression::Type::Cosinus;
}

float Cosinus::approximate(Context& context) {
  // FIXME: use cosinus obviously.
  return m_arg->approximate(context);
}
