#include "graph_controller.h"

GraphController::GraphController(Responder * parentResponder, Graph::FunctionStore * functionStore) :
  ViewController(parentResponder),
  m_view(GraphView(functionStore))
{
}

View * GraphController::view() {
  return &m_view;
}

const char * GraphController::title() const {
  return "Graphique";
}

bool GraphController::handleEvent(Ion::Events::Event event) {
  switch (event) {
    case Ion::Events::Event::ENTER:
      m_view.moveCursorRight();
      return true;
    default:
      return false;
  }
}
