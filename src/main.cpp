// Sep 2025 Matt Linder, Arshia Eslami

#include <vector>
#include <string>
#include <iostream>
#include "node.h"

class IReadable
{
public:
  virtual std::string readable() = 0;
};

struct Layer : IReadable
{
  std::vector<Node> nodes_;

public:
  Layer(int node_count)
  {
    nodes_.resize(node_count);
  }

  std::string readable()
  {
    std::string readable = "";
    for (auto &node : nodes_)
    {
      readable += '\t' + node.readable() + '\n';
    }
    return readable;
  }
};

// TODO: training flag
class NeuralNetwork : IReadable
{
  std::vector<Layer> layers_;

public:
  NeuralNetwork()
  {
  }

  NeuralNetwork *add_layer(int node_count)
  {
    Layer layer = Layer(node_count);
    if (layers_.size() == 0)
    {
      layers_.push_back(layer);
      return this;
    }

    Layer last_layer = layers_[layers_.size() - 1];
    for (int i = 0; i < last_layer.nodes_.size(); ++i)
    {
      for (int j = 0; j < node_count; ++j)
      {
        last_layer.nodes_[i].outputs_.push_back(Connection());
        last_layer.nodes_[i].outputs_[j].node_ = &layer.nodes_[j];
      }
    }
    layers_.push_back(layer);
    return this;
  }

  std::string readable()
  {
    std::string output = "";
    for (auto &layer : layers_)
    {
      output += '\t' + layer.readable() + '\n';
    }
    return output;
  }
};

int main()
{
  NeuralNetwork *network = (new NeuralNetwork())->add_layer(3)->add_layer(3);
  std::cout << network->readable() << std::endl;
  return 0;
}