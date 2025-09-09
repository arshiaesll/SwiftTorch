#include "node.h"
#include "activation_functions.h"
// Node

Node::Node(int row, int col)
{
  this->row = row;
  this->col = col;
}

double Node::calculate_pre_activation() const
{
  double sum = 0;
  for (size_t i = 0; i < inputs_.size(); ++i)
  {
    sum += inputs_[i].weight_ * inputs_[i].node_->activated_output;
  }
  return sum + bias_;
}

double Node::calculate_activated_output(double (*activation_function)(double z) = sigmoid) const
{
  return activation_function(this->pre_activation);
}

std::string Node::readable() const
{
  std::string output = "(" + std::to_string(this->row) + ", " + std::to_string(this->col) + ") " + std::to_string(this->outputs_.size()) + "\n";
  for (auto &c : outputs_)
  {
    output += "\t" + std::to_string(c.weight_) + "\n";
  }
  return output;
}

// Connection

Connection::Connection()
{
  weight_ = this->generate_weight();
  node_ = nullptr;
}

double Connection::generate_weight() const
{
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
}