///////////////////////////////////////////////////////////////////////////////
///  DijkstraShortestPathAlg.h
///  The implementation of Dijkstra algorithm to get the shortest path of 
///  a pair of vertices in a graph. 
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 5/30/2010
/// 
///  $Id$
///
///////////////////////////////////////////////////////////////////////////////

#pragma once

using namespace std;

class DijkstraShortestPathAlg
{
public: // types

	//typedef GVertex<T> BaseVertex;

private: // members

	BaseGraph& m_rDirectGraph;

	std::map<BaseVertex*, double> m_mpStartDistanceIndex; 
	std::map<BaseVertex*, BaseVertex*> m_mpPredecessorVertex; 

	std::set<BaseVertex*, WeightComparator<BaseVertex> > m_stDeterminedVertices; // The set of vertex IDs
	
	std::priority_queue<BaseVertex*, std::vector<BaseVertex*>, WeightComparator<BaseVertex> > m_quCandidateVertices;
	
public:
	DijkstraShortestPathAlg(BaseGraph& pGraph):m_rDirectGraph(pGraph){}
	~DijkstraShortestPathAlg(void){clear();}

	void clear();

	BasePath* get_shortest_path(BaseVertex* source, BaseVertex* sink);

	BasePath* update_cost_forward(BaseVertex* vertex);

	void correct_cost_backward(BaseVertex* vertex);

protected:

	void determine_shortest_paths(BaseVertex* source, BaseVertex* sink, bool is_source2sink);

	void improve2vertex(BaseVertex* cur_vertex_pt, bool is_source2sink);

};
