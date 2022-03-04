
#pragma once

#include <concepts>

namespace gmpl {
template <typename T>
concept Vec3 = requires(T a) {
  typename T::value_type;
  { a.x } -> std::same_as<typename T::value_type>;
  { a.y } -> std::same_as<typename T::value_type>;
  { a.z } -> std::same_as<typename T::value_type>;
};

template <typename T>
concept Vertex = requires(T a) {
  { a.position } -> Vec3;
};

template <typename T>
concept Polygon = requires(T a, typename T::vertex_count_type vertex_index_) {
  typename T::vertex_count_type;
  typename T::vertex;
  { a.vertex_count() } -> std::same_as<typename T::vertex_count_type>;
  { a.vertex(vertex_index_) } -> std::same_as<typename T::vertex>;
};

template <typename T>
concept Mesh = requires(T a, typename T::polygon_count_type polygon_index_) {
  typename T::polygon_count_type;
  typename T::polygon_type;
  { a.polygon_count() } -> std::same_as<typename T::polygon_count_type>;
  { a.polygon(polygon_index_) } -> std::same_as<typename T::polygon_type>;
};

template <Mesh TMesh> void triangluate(TMesh &mesh_) {
  const auto nPolygons = mesh_.polygon_count();
  for (typename TMesh::polygon_count_type iPolygon = 0; iPolygon < nPolygons;
       ++iPolygon) {
    const auto polygon = mesh_.polygon(iPolygon);
    const auto nPolygonVertices = polygon.vertex_count();
    for (typename TMesh::polygon_type::vertex_count_type iPolygonVertex = 0;
         iPolygonVertex < nPolygonVertices; ++iPolygonVertex) {
      const auto vertex = polygon.vertex(iPolygonVertex);
    }
  }
}
} // namespace gmpl
