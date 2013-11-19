#pragma once
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#define INF 100000
namespace bg = boost::geometry;
using namespace std;
typedef bg::model::d2::point_xy<double> point_type;
typedef bg::model::box<point_type> box_type;
typedef bg::model::polygon<point_type> polygon_type;
typedef bg::model::polygon<point_type, true, false> polygon_type_open;
typedef bg::model::segment<point_type> segment_type;
typedef vector<point_type> points_type;
typedef vector<point_type>::iterator points_iterator;
typedef bg::model::ring<point_type> ring_type;
typedef ring_type::iterator ring_iterator;
	
typedef vector<polygon_type> polygons_type;
typedef vector<polygon_type>::iterator polygon_iterator;
//------------------------------------------------------
typedef pair<double, double> vertex;
typedef vector<vertex> vertexs;
typedef vector<vertex>::iterator vertexs_iterator;