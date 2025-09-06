#ifndef READABLE_H
#define READABLE_H

#include <string>

class IReadable
{
public:
  virtual std::string readable() = 0;
};

#endif