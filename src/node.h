#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <random>
#include "readable.h"

#define MEAN 0.5
#define DEVIATION 0.15

struct Connection;

struct Node : IReadable
{
  std::vector<Connection> inputs_;
  std::vector<Connection> outputs_;
  // The input bias
  double bias_;
  double pre_activation;
  double activated_output;
  int row;
  int col;

  Node(int row, int col);

  virtual ~Node() = default;

  // To calculate the raw output before the activation function
  double calculate_pre_activation() const;

  double calculate_activated_output(double (*activation_function)(double z)) const;

  std::string readable() const override;
};

struct Connection
{
  double weight_;
  Node *node_;

  Connection();

  double generate_weight() const;
};

#endif