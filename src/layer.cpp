#include "layer.h"

Layer::Layer(int layer_index, int node_count)
{
  for (int i = 0; i < node_count; ++i)
  {
    nodes_.push_back(Node(layer_index, i));
  }
}

std::string Layer::readable()
{
  std::string readable = "";
  for (auto &node : nodes_)
  {
    readable += node.readable();
  }
  return readable;
}