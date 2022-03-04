#include "gmpl.h"
#include <iostream>
#include <vector>

class Vec3 {
public:
  using value_type = double;

  value_type x, y, z;
};

class Vertex {

};

class Polygon {
public:
  using vertex_type = Vertex;
  using vertex_count_type = std::size_t;

  Vertex vertex(vertex_count_type index_) {
    return _vertices[index_];
  }

private:
  std::vector<Vertex> _vertices;
};

class Mesh {
public:
  using polygon_type = Polygon;
  using polygon_count_type = std::size_t;

  Polygon polygon(polygon_count_type index_) {
    return _polygons[index_];
  }

private:
  std::vector<Polygon> _polygons;
};

int main() {
  Mesh mesh;
  gmpl::triangluate(mesh);
  std::cout << "Hello CMake." << std::endl;
  return 0;
}
