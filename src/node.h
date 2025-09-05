#ifndef NODE_H
#define NODE_H

#include "connection.h"
#include <string>

struct Node
{
  std::vector<Connection> inputs_;
  std::vector<Connection> outputs_;
  double bias_;
  double pre_activation;
  double activated_output;

  // To calculate the raw output before the activation function
  double calculate_pre_activation()
  {

    double sum = 0;
    for (int i = 0; i < inputs_.size(); ++i)
    {
      sum += inputs_[i].weight_ * inputs_[i].node_->activated_output;
    }
    sum += bias_;
  }

  double calculate_activated_output(double (*activation_function)(double z))
  {
    return activation_function(this->pre_activation);
  }

  std::string readable()
  {
    std::string output = "Node\n";
    for (auto &o : outputs_)
    {
      output += "\t --" + std::to_string(o.weight_) + "-> Node";
    }
    return output;
  }
};

#endif