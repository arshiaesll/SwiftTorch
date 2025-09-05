#ifndef CONNECTION_H
#define CONNECTION_H

#include "node.h"
#include <random>

#define MEAN 0.5
#define DEVIATION 0.15

struct Connection
{
  double weight_;
  Node *node_;

  Connection()
  {
    weight_ = this->generate_weight();
    node_ = nullptr;
  }

  double generate_weight()
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    double mean = MEAN;
    double deviation = DEVIATION;
    std::normal_distribution<double> dist(mean, deviation);
    double tmp = dist(gen);
    if (tmp < 0)
      return 0;
    if (tmp > 1)
      return 1;
    return tmp;
  }
};

#endif