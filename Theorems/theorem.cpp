/*
1. Kirchhoff’s Theorem
Denote L be a n×n matrix as the Laplacian matrix of graph G, where Lii = d(i),
Lij = −c where c is the number of edge (i, j) in G.
• The number of undirected spanning in G is |det(L˜11)|.

• The number of directed spanning tree rooted at r in G is |det(L˜rr)|.

2. Tutte’s Matrix
Let D be a n × n matrix, where dij = xij (xij is chosen uniform randomly) if
i < j and (i, j) ∈ E, otherwise dij = −dji x (rank(D)/2) is the maximum matching on G.

3. Cayley’s Formula
• Given a degree sequence d1, d2, . . . , dn for each labeled vertices, there’re
(n−2)!/((d1−1)!(d2−1)!···(dn−1)!) spanning trees.

• Let Tn,k be the number of labeled forests on n vertices with k components,
such that vertex 1, 2, . . . , k belong to different components. Then Tn,k = k x n^(n−k−1).


4. Erdős–Gallai theorem
A sequence of non-negative integers d1 ≥ d2 ≥ . . . ≥ dn can be represented as
the degree sequence of a finite simple graph on n vertices if and only if d1 + d2 +. . . + dn is even and
i=k                i=n
∑   di ≤ k(k − 1) +  ∑   min(di, k)
i=1                i=k+1  
holds for all 1 ≤ k ≤ n.

5. Havel–Hakimi algorithm
find the vertex who has greatest degree unused, connect it with other greatest
vertex


6. Hall’s marriage theorem
Let G be a finite bipartite graph with bipartite sets X and Y . For a subset W of
X, let NG(W) denote the set of all vertices in Y adjacent to some element of W.
Then there is an X-saturating matching iff ∀W ⊆ X, |W| ≤ |NG(W)|

*/