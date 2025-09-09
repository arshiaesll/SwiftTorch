#include "neural_network.h"

NeuralNetwork::NeuralNetwork()
{
}

NeuralNetwork *NeuralNetwork::add_layer(int node_count)
{
  Layer layer = Layer(layers_.size(), node_count);
  if (layers_.size() == 0)
  {
    layers_.push_back(layer);
    return this;
  }

  Layer *last_layer = &layers_[layers_.size() - 1];
  for (size_t i = 0; i < last_layer->nodes_.size(); ++i)
  {
    for (int j = 0; j < node_count; ++j)
    {
      last_layer->nodes_[i].outputs_.push_back(Connection());
      last_layer->nodes_[i].outputs_[j].node_ = &layer.nodes_[j];
    }
  }
  layers_.push_back(layer);
  return this;
}

std::string NeuralNetwork::readable() const
{
  std::string output = "";
  for (auto &layer : layers_)
  {
    output += layer.readable();
  }
  return output;
}