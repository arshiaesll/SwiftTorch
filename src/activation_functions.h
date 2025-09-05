#ifndef ACTIVATIONS_FUNCTIONS_H
#define ACTIVATIONS_FUNCTIONS_H
#include <bits/stdc++.h>

double sigmoid(double z)
{
  return 1 / std::exp(-z);
}

double relu(double z)
{
  return std::max(0, z)
}

#endif