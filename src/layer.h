#ifndef LAYER_H
#define LAYER_H

#include "readable.h"
#include "node.h"

struct Layer : IReadable
{
  std::vector<Node> nodes_;

  Layer(int layer_index, int node_count);

  virtual ~Layer() = default;

  std::string readable() const override;
  std::vector<double> forward_pass() const;
};

#endif
