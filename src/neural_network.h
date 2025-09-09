#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "readable.h"
#include "layer.h"

class NeuralNetwork : IReadable
{
  std::vector<Layer> layers_;

public:
  NeuralNetwork();

  NeuralNetwork *add_layer(int node_count);

  std::string readable() const override;
};

#endif