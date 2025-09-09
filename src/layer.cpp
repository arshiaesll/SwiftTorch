#include "layer.h"
#include "activation_functions.h"

Layer::Layer(int layer_index, int node_count)
{
  for (int i = 0; i < node_count; ++i)
  {
    nodes_.push_back(Node(layer_index, i));
  }
}

std::string Layer::readable() const
{
  std::string readable = "";
  for (auto &node : nodes_)
  {
    readable += node.readable();
  }
  return readable;
}

std::vector<double> Layer::forward_pass() const
{

  std::vector<double> output;

  for (auto &node : nodes_)
  {
    // TODO: we need to change this to pass the layer activation function
    output.push_back(node.calculate_activated_output(sigmoid));
  }

  return output;
}