#include "PathFinderNew.h"
#include <queue>
#include <fstream>
#include <sstream>
#include "cocos2d.h"
namespace PathEngine
{
	PolygonQuadObject::PolygonQuadObject(int min_x, int min_y, int max_x, int max_y)
		:QuadObject(min_x, min_y, max_x, max_y)
	{
		
	}
	PolygonQuadObject::~PolygonQuadObject()
	{

	}
	void PolygonQuadObject::SetPolygon(polygon_type value)
	{
		m_Polygon = value;
		box_type box;
		bg::envelope(value, box);
		int min_x = bg::get<bg::min_corner, 0>(box);
		int min_y = bg::get<bg::min_corner, 1>(box);
		int max_x = bg::get<bg::max_corner, 0>(box);
		int max_y = bg::get<bg::max_corner, 1>(box);
		SetBoundingBox(min_x, min_y, max_x, max_y);
	}
	polygon_type PolygonQuadObject::GetPolygon()
	{
		return m_Polygon;
	}

	PathFinderNew::PathFinderNew()
	{
		m_QuadTree = new Geometry::QuadTree(2000,2000);
		m_Render = new PathRenderNew();
	}
	PathFinderNew::~PathFinderNew()
	{
	}
	bool PathFinderNew::TestIntersect(polygon_type_open poly1, polygon_type poly2, bool consider_touch)
	{
		cc_timeval* begin = new cc_timeval();
		cc_timeval* end = new cc_timeval();
		double time_used;
		CCTime::gettimeofdayCocos2d(begin, NULL);
		bool detected = bg::intersects(poly1, poly2);
		CCTime::gettimeofdayCocos2d(end, NULL);
		time_used = CCTime::timersubCocos2d(begin, end);
		cout<<"-- boost::geometry test intersect cost "<<time_used<<" milisecond!"<<endl;
		if(!consider_touch && detected)
		{
			CCTime::gettimeofdayCocos2d(begin, NULL);
			bool touches = bg::touches(poly1, poly2);
			if(touches)
			{
				detected = false;
			}
			else
			{
				touches = bg::touches(poly2, poly1);
				if(touches)
				{
					detected = false;
				}
			}
			CCTime::gettimeofdayCocos2d(end, NULL);
			time_used = CCTime::timersubCocos2d(begin, end);
			cout<<"--- boost::geometry test touches cost more "<<time_used<<" milisecond!"<<endl;
		}
		return detected;
	}
	bool PathFinderNew::TestIntersect(double x1, double y1, double x2, double y2, bool consider_touch)
	{
		double lx, hx, ly, hy;
		if(x1>x2)
		{
			hx = x1;
			lx = x2;
		}else
		{
			hx = x2;
			lx = x1;
		}
		if(y1>y2)
		{
			hy = y1;
			ly = y2;
		}else
		{
			hy = y2;
			ly = y1;
		}
		bool detected = false;
		Geometry::QuadTree* tree = m_QuadTree;
		while(tree)
		{
			Geometry::QuadObjects objects = tree->GetObjects();
			Geometry::QuadObjectIterator it = objects.begin();
			for(;it != objects.end();it++)
			{
				Geometry::QuadObject* quad = *it;
				PolygonQuadObject* poly_quad = (PolygonQuadObject*)quad;
				polygon_type poly;
				polygon_type_open segment;
				{
					poly = poly_quad->GetPolygon();
					point_type p1,p2;
					p1 = bg::make<point_type,double>(x1,y1);
					p2 = bg::make<point_type,double>(x2,y2);
					bg::append(segment,p1);
					bg::append(segment,p2);
					//bg::append(segment,p1);
				}
				if(TestIntersect(segment, poly, consider_touch))
				{
					detected = true;
					break;
				}
			}
			if(detected)
			{
				break;
			}
			Geometry::TREE_LOCATION location = tree->GetLocation(lx, ly, hx, hy);
			if(location == Geometry::TL_CHILD0)
			{
				tree = tree->SubNode(0);
			}
			else if(location == Geometry::TL_CHILD1)
			{
				tree = tree->SubNode(1);
			}
			else if(location == Geometry::TL_CHILD2)
			{
				tree = tree->SubNode(2);
			}
			else if(location == Geometry::TL_CHILD3)
			{
				tree = tree->SubNode(3);
			}
			else
			{
				break;
			}
		}
		return detected;
	}

	bool PathFinderNew::TestPointInPolygon(double x, double y, bool consider_touch)
	{
		point_type point;
		bg::set<0>(point,x);
		bg::set<1>(point,y);
		bool detected = false;
		Geometry::QuadTree* tree = m_QuadTree;
		while(tree)
		{
			Geometry::QuadObjects objects = tree->GetObjects();
			Geometry::QuadObjectIterator it = objects.begin();
			for(;it != objects.end();it++)
			{
				Geometry::QuadObject* quad = *it;
				PolygonQuadObject* poly_quad = (PolygonQuadObject*)quad;
				polygon_type poly;
				poly = poly_quad->GetPolygon();
				bool result;
				if(consider_touch)
				{
					result = bg::covered_by(point, poly);
				}
				else
				{
					result = bg::within(point, poly);
				}
				if(result)
				{
					detected = true;
					break;
				}
			}
			if(detected)
			{
				break;
			}
			Geometry::TREE_LOCATION location = tree->GetLocation(x, y);
			if(location == Geometry::TL_CHILD0)
			{
				tree = tree->SubNode(0);
			}
			else if(location == Geometry::TL_CHILD1)
			{
				tree = tree->SubNode(1);
			}
			else if(location == Geometry::TL_CHILD2)
			{
				tree = tree->SubNode(2);
			}
			else if(location == Geometry::TL_CHILD3)
			{
				tree = tree->SubNode(3);
			}
			else
			{
				break;
			}
		}
		return detected;
	}
	bool PathFinderNew::FixPoint(double* x, double* y, bool consider_touch, double jump_length, int max_try)
	{
		for(int i=1; i<= max_try; i++)
		{
			for(int j=1; j<= max_try; j++)
			{
				double new_x;
				double new_y;
				new_x = *x + i*jump_length;
				new_y = *y + j*jump_length;
				if(TestPointInPolygon(new_x, new_y, consider_touch))
				{
					*x = new_x;
					*y = new_y;
					return true;
				}
				new_x = *x - i*jump_length;
				new_y = *y - j*jump_length;
				if(TestPointInPolygon(new_x, new_y, consider_touch))
				{
					*x = new_x;
					*y = new_y;
					return true;
				}
				new_x = *x + i*jump_length;
				new_y = *y - j*jump_length;
				if(TestPointInPolygon(new_x, new_y, consider_touch))
				{
					*x = new_x;
					*y = new_y;
					return true;
				}
				new_x = *x - i*jump_length;
				new_y = *y + j*jump_length;
				if(TestPointInPolygon(new_x, new_y, consider_touch))
				{
					*x = new_x;
					*y = new_y;
					return true;
				}
			}
		}
		return false;
	}
	void PathFinderNew::AddSinglePolygon(vertexs points)
	{
		polygon_type poly;
		vertexs_iterator it = points.begin();
		for(;it!=points.end();it++)
		{
			vertex p1 = *it;
			point_type p2;
			p2 = bg::make<point_type,double>(p1.first,p1.second);
			bg::append(poly,p2);
		}
		int len = poly.outer().size();
		AddSinglePolygon(poly);
	}
	void PathFinderNew::AddSinglePolygon(polygon_type poly)
	{
		box_type box;
		bg::envelope(poly, box);// envelope = make bounding box from poly
		int min_x = bg::get<bg::min_corner, 0>(box);
		int min_y = bg::get<bg::min_corner, 1>(box);
		int max_x = bg::get<bg::max_corner, 0>(box);
		int max_y = bg::get<bg::max_corner, 1>(box);
		PolygonQuadObject* object = new PolygonQuadObject(min_x, min_y, max_x, max_y);
		object->SetPolygon(poly);
		m_QuadTree->Insert(object);
	}
	void PathFinderNew::UnionPolygon()
	{
		// TODO: union any pair of polygon that intersect
	}
	void PathFinderNew::SinglePolygonToMatrix(ring_type ring_poly, bool outer)
	{
		int begin_index = m_Matrix.size();
		int index = begin_index;
		int length = ring_poly.size();
		length--;
		if(length < 3)
			return;
		ring_iterator it = ring_poly.begin();
		ring_iterator first = ring_poly.begin()+1;
		ring_iterator last = ring_poly.end()-1;
		point_type current, prev, next;
		prev = *(ring_poly.end()-2);
		current = *(it++);
		int first_vertex_index =  m_Vertexs.size();
		int prev_vertex_index =  m_Vertexs.size();
		for(;it != ring_poly.end();it++)
		{
			// !TODO: next point
			next = *it;
			bool convex = IsConvex(prev,current,next,outer);
			// TODO: connect point to point to build matrix.
			vector<double> row;
			row.resize(m_Vertexs.size());
			if(convex)
			{
				// connect to other polygon
				bool* intersect = new bool[first_vertex_index];
				for(int i=0;i<first_vertex_index;i++)
				{
					point_type v = m_Vertexs[i];
					double cx = bg::get<0,point_type>(current);
					double cy = bg::get<1,point_type>(current);
					double vx = bg::get<0,point_type>(v);
					double vy = bg::get<1,point_type>(v);
					intersect[i] = TestIntersect(cx,cy,vx,vy);
				}
				int i, j, k;
				for(i=0;i<first_vertex_index;i++)
				{
					j = m_VertexPrev[i];
					k = m_VertexPrev[j];
					point_type v = m_Vertexs[j];
					if(intersect[j])
					{
						row[j] = INF;
					}
					// optimize
					else if(!intersect[i] && !intersect[k])
					{
						row[j] = INF-1;
					}
					else
					{
						double length = GetLength(current,v);
						row[j] = length;
					}
				}
				// self connecting
				//if(false)
				{
					point_type left = current, mid, right;
					int mid_index=-1;
					for(int i=m_Vertexs.size()-1;i>=first_vertex_index;i--)
					{
						right = m_Vertexs[i];
						if(mid_index!=-1)
						{
							bool mid_convex = IsConvex(right,mid,left,outer);
							if(mid_convex)
							{
								while(i>=first_vertex_index)
								{
									row[i] = INF;
									i--;
								}
								break;
							}
						}
						double length = GetLength(left,right);
						row[i] = length;
						mid = right;
						mid_index = i;
					}
				}
				m_Vertexs.push_back(current);
				m_VertexPrev.push_back(prev_vertex_index);
				m_Matrix.push_back(row);
				prev_vertex_index = m_Vertexs.size()-1;
			}
			// !TODO: next point
			prev = current;
			current = next;
		}
		{
			m_VertexPrev[first_vertex_index] = prev_vertex_index;
			// connect first/last point to others
			point_type left = m_Vertexs[first_vertex_index], mid, right;
			int mid_index=-1;
			for(int i=m_Vertexs.size()-1;i>first_vertex_index;i--)
			{
				right = m_Vertexs[i];
				if(mid_index!=-1)
				{
					bool mid_convex = IsConvex(right,mid,left,outer);
					if(mid_convex)
					{
						break;
					}
				}
				double length = GetLength(left,right);
				m_Matrix[i][first_vertex_index] = length;
				mid = right;
				mid_index = i;
			}
		}
		{// optimize
			int i, j, k;
			for(i=first_vertex_index;i<m_Vertexs.size();i++)
			{
				j = m_VertexPrev[i];
				k = m_VertexPrev[j];
				for(int l = 0;l<first_vertex_index;l++)
				{
					if(m_Matrix[j][l] == INF) continue;
					if(m_Matrix[i][l] < INF && m_Matrix[k][l] < INF)
					{
						m_Matrix[j][l] = INF-1;
					}
				}
			}
			for(i=first_vertex_index;i<m_Vertexs.size();i++)
			{
				for(int j = 0;j<first_vertex_index;j++)
				{
					if(m_Matrix[i][j] == INF-1)
					{
						m_Matrix[i][j] = INF;
					}
				}
			}
		}
	}
	bool PathFinderNew::IsConvex(point_type prev, point_type current, point_type next, bool outer)
	{
		double px = bg::get<0,point_type>(prev);
		double py = bg::get<1,point_type>(prev);
		double cx = bg::get<0,point_type>(current);
		double cy = bg::get<1,point_type>(current);
		double nx = bg::get<0,point_type>(next);
		double ny = bg::get<1,point_type>(next);
		float cross = ((cx - px) * (ny - cy)) - ((cy - py) * (nx - cx));
		bool convex = outer?cross < 0:cross > 0;
		return convex;
	}
	double PathFinderNew::GetLength(point_type u, point_type v)
	{
		double ux = bg::get<0,point_type>(u);
		double uy = bg::get<1,point_type>(u);
		double vx = bg::get<0,point_type>(v);
		double vy = bg::get<1,point_type>(v);
		double dx = vx-ux;
		double dy = vy-uy;
		double length = sqrt(dx*dx+dy*dy);
		return length;
	}
	double PathFinderNew::GetLength(int u, int v)
	{
		if(u<v)
		{
			return m_Matrix[v][u];
		}
		else
		{
			return m_Matrix[u][v];
		}
	}
	void PathFinderNew::PolygonToMatrix()
	{
		queue<Geometry::QuadTree*> tree_queue;
		tree_queue.push(m_QuadTree);
		while(!tree_queue.empty())
		{
			Geometry::QuadTree* tree = tree_queue.front();
			tree_queue.pop();
			if(tree == 0) continue;
			tree_queue.push(tree->SubNode(0));
			tree_queue.push(tree->SubNode(1));
			tree_queue.push(tree->SubNode(2));
			tree_queue.push(tree->SubNode(3));
			Geometry::QuadObjects objects = tree->GetObjects();
			Geometry::QuadObjectIterator it = objects.begin();
			for(;it != objects.end();it++)
			{
				Geometry::QuadObject* quad = *it;
				PolygonQuadObject* poly_quad = (PolygonQuadObject*)quad;
				polygon_type poly;
				poly = poly_quad->GetPolygon();
				{
					// !TODO: get points from polygon.
					ring_type out_points = poly.outer();
					SinglePolygonToMatrix(out_points, true);
					typedef vector<ring_type, allocator<ring_type> > rings_type;
					rings_type inners = poly.inners();
					rings_type::iterator it = inners.begin();
					for(;it != inners.end();it++)
					{
						ring_type in_points = *it;
						SinglePolygonToMatrix(in_points, false);
					}
				}
			}
		}
	}
	void PathFinderNew::FindPath(double x, double y, double gx, double gy, vector<vertex>* result)
	{
		system("cls");
		cc_timeval* begin = new cc_timeval();
		cc_timeval* end = new cc_timeval();
		double time_used;
		{
			CCTime::gettimeofdayCocos2d(begin, NULL);
			bool begin_inside = TestPointInPolygon(x,y);
			if(begin_inside) return;
			bool goal_inside = TestPointInPolygon(gx,gy);
			if(goal_inside)	return;
			CCTime::gettimeofdayCocos2d(end, NULL);
			time_used = CCTime::timersubCocos2d(begin, end);
			cout<<"dijkstra pre test cost "<<time_used<<" milisecond!"<<endl;
		}
		int len = m_Vertexs.size(); int len1 = len+1;
		//-------- dijkstra init ------------
		CCTime::gettimeofdayCocos2d(begin, NULL);
		double* d = new double[len1];
		int* prev = new int[len1];
		bool* pass = new bool[len1];
		for(int i = 0;i < len;i++)
		{
			point_type point_v = m_Vertexs[i];
			double vx = bg::get<0,point_type>(point_v);
			double vy = bg::get<1,point_type>(point_v);
			bool intersect = TestIntersect(x,y,vx,vy);
			if(intersect)
			{
				d[i] = INF;
			}
			else
			{
				double dx = vx-x;
				double dy = vy-y;
				d[i] = sqrt(dx*dx+dy*dy);
			}
			pass[i] = false;
			prev[i] = -1;
		}
		{
			bool intersect = TestIntersect(x,y,gx,gy);
			if(intersect)
			{
					d[len] = INF;
			}
			else
			{
				double dx = gx-x;
				double dy = gy-y;
				d[len] = sqrt(dx*dx+dy*dy);
			}
			pass[len] = false;
			prev[len] = -1;
		}
		CCTime::gettimeofdayCocos2d(end, NULL);
		time_used = CCTime::timersubCocos2d(begin, end);
		cout<<"dijkstra init cost "<<time_used<<" milisecond!"<<endl;
		//-------- dijkstra loop ------------
		CCTime::gettimeofdayCocos2d(begin, NULL);
		while(true)
		{
			if(false){// check result
				if(d[len] != INF)
					break;
			}
			int u = 0;
			double du = INF;
			{// find min node
				//cout<<"find min"<<endl;
				for(int i = 0;i <= len;i++)
				{
					//cout<<"d["<<i<<"]="<<d[i]<<"\tpass="<<pass[i]<<" prev="<<prev[i]<<endl;
					if(pass[i]) continue;
					if(d[i] < du)
					{
						u = i;
						du = d[i];
					}
				}
				if(du == INF || u == len)
				{
					break;
				}
			}
			{// go to min node
				point_type point_u = m_Vertexs[u];
				double ux = bg::get<0,point_type>(point_u);
				double uy = bg::get<1,point_type>(point_u);
				//cout<<"go to "<<u<<" "<<node->X<<"-"<<node->Y<<endl;
				pass[u] = true;
				for(int v = 0;v < len;v++)
				{
					if(pass[v]) continue;
					double dv_pass_u = du + GetLength(u,v);
					if(dv_pass_u < d[v])
					{
						d[v] = dv_pass_u;
						prev[v] = u;
					}
				}
				{
					bool intersect = TestIntersect(ux,uy,gx,gy);
					if(!intersect)
					{
						double dx = gx-ux;
						double dy = gy-uy;
						double dlen_pass_u = du + sqrt(dx*dx+dy*dy);
						if(dlen_pass_u < d[len])
						{
							d[len] = dlen_pass_u;
							prev[len] = u;
						}
					}
				}
			}
		}
		CCTime::gettimeofdayCocos2d(end, NULL);
		time_used = CCTime::timersubCocos2d(begin, end);
		cout<<"dijkstra loop cost "<<time_used<<" milisecond!"<<endl;
		//-------- trace result -------------
		CCTime::gettimeofdayCocos2d(begin, NULL);
		{
			if(d[len] == INF) return;
			result->push_back(make_pair<double,double>(gx,gy));
			int u=len;
			while(prev[u] != -1)
			{
				u = prev[u];
				point_type point_u = m_Vertexs[u];
				double ux = bg::get<0,point_type>(point_u);
				double uy = bg::get<1,point_type>(point_u);
				result->push_back(make_pair<double,double>(ux,uy));
			}
			result->push_back(make_pair<double,double>(x,y));
		}
		CCTime::gettimeofdayCocos2d(end, NULL);
		time_used = CCTime::timersubCocos2d(begin, end);
		cout<<"dijkstra trace result cost "<<time_used<<" milisecond!"<<endl;
	}
	void PathFinderNew::SelfTest()
	{
		cc_timeval* begin = new cc_timeval();
		CCTime::gettimeofdayCocos2d(begin, NULL);
		ifstream fin("path_finder_inp.txt");
		if (fin.is_open())
		{
			int count;
			fin>>count;
			for(int i=0;i<count;i++)
			{
				int len;
				fin>>len;
				vertexs points;
				for(int j=0;j<=len;j++)
				{
					double x, y;
					fin>>x>>y;
					points.push_back(make_pair<double,double>(x,y));
				}
				AddSinglePolygon(points);
			}
		}
		fin.close();
		PolygonToMatrix();
		ofstream fout("path_finder_out.txt");
		if (fout.is_open())
		{
			fout<<"vertexs"<<endl;
			{
				points_iterator it = m_Vertexs.begin();
				for(;it != m_Vertexs.end();it++)
				{
					point_type v = *it;
					double vx = bg::get<0,point_type>(v);
					double vy = bg::get<1,point_type>(v);
					fout<<vx<<" "<<vy<<endl;
				}
			}
			fout<<"matrix"<<endl;
			{
				vector< vector<double> >::iterator it = m_Matrix.begin();
				for(;it != m_Matrix.end();it++)
				{
					vector<double> row = *it;
					vector<double>::iterator it2 = row.begin();
					for(;it2 != row.end();it2++)
					{
						double value = *it2;
						fout<<value<<" ";
					}
					fout<<endl;
				}
			}
		}
		cc_timeval* end = new cc_timeval();
		CCTime::gettimeofdayCocos2d(end, NULL);
		double time_used = CCTime::timersubCocos2d(begin, end);
		fout<<"time used: "<<time_used<<" miliseconds";
		fout.close();
		//-----------------------
		m_Render->SetMatrix(m_Matrix);
		m_Render->SetVertexs(m_Vertexs);
	}
}