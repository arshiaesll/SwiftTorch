// Sep 2025 Matt Linder, Arshia Eslami

#include "neural_network.h"
#include <iostream>

int main()
{
  NeuralNetwork *network = (new NeuralNetwork())->add_layer(3)->add_layer(3);
  std::cout << network->readable() << std::endl;
  return 0;
}