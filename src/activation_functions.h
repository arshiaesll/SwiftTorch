#ifndef ACTIVATIONS_FUNCTIONS_H
#define ACTIVATIONS_FUNCTIONS_H

#include <cmath>
#include <algorithm>

double sigmoid(double z)
{
  return 1 / std::exp(-z);
}

double relu(double z)
{
  return std::max(0.0, z);
}

#endif