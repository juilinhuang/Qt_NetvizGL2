//
// Created by william on 23/02/17.
//

#ifndef NETVIZGL_DRAGNODE_H
#define NETVIZGL_DRAGNODE_H

#include <algorithm>
#include <iostream>
#include "Command.h"
#include "glwidget.h"

class DragVertex : public Command {
 private:
  GLWindow *window;
 public:
  DragVertex(GLWindow *window) : window(window) {}

  void execute() override {
    if (window->getSelectedNode()) {
      window->getSelectedNode()->posX -= window->mouseDiffX * .2 * window->translateZ;
      window->getSelectedNode()->posY += window->mouseDiffY * .2 * window->translateZ;
    }
  }
};

#endif //NETVIZGL_DRAGNODE_H
