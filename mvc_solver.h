//
// Created by prwang on 17-5-28.
//

#include "main.h"
#ifndef MAXCLIQUE_GRAPH_H
#define MAXCLIQUE_GRAPH_H


template<int N, int RG = N>struct unord
{
    int size() const  { return realsize; }
    int* begin()  { return ary; }
    int* end()  { return ary + realsize; }
    void del(int u)
    {
        int pos = rev[u];  rev[u] = -1;
        --realsize;
        if (realsize != pos)
            rev[ary[pos] = ary[realsize]] = pos;
    }
    unord() : realsize(0) { fill(rev, rev + RG, -1);  }
    bool operator()(int u) const  { return -1 != rev[u]; } //probe if exists
    void ins(int u) { if (rev[u] != -1) throw 233; ary[rev[u] = realsize++] = u; }
    int rand() const { return ary[(uniform_int_distribution<int>(0, realsize - 1))(RAND)]; }
private:
    int ary[N], rev[RG], realsize ;
};
class mvc_solver
{
protected:
    int G[maxn][maxn];
    int wgt[maxm]; pii conns[maxm];
    int dsc[maxn],  c_d[maxn], p_c, ed_c, timest;
    unord<maxn> adj[maxn],  partial;
    unord<maxm> uncov;

public:
    unord<maxn> ans, mis;
    int max_oldest();
    mvc_solver(int _p_c, int _ed_c, pii* _conns);
    void init_dscore();
    void construct();
    void validate();

    virtual void ins_pans(int u);
    virtual void del_pans(int v);
    virtual bool iterate(int _timest_) { timest = _timest_; return false; };
};


#endif //MAXCLIQUE_GRAPH_H
