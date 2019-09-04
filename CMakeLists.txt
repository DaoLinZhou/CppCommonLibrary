cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm
#        main_performance.cpp
        main.cpp
        sort/SelectionSort.h sort/SortTestHelper.h sort/InsertSort.h sort/ShellSort.h sort/MergeSort.h sort/QuickSort.h sort/ReverseOrder.h sort/NthNumber.h heap/MaxHeap.h sort/HeapSort.h bst/BinarySearch.h sort/CountingSort.h bst/FileOps.h bst/BST.h unionfind/UnionFind1.h unionfind/UnionFindTestHelper.h unionfind/UnionFind2.h unionfind/UnionFind3.h unionfind/UnionFind4.h unionfind/UnionFind5.h unweighted-graph/DenseGraph.h unweighted-graph/SparseGraph.h unweighted-graph/ReadGraph.h unweighted-graph/Component.h unweighted-graph/Path.h unweighted-graph/ShortestPath.h weighted-graph/DenseGraph.h weighted-graph/ReadGraph.h weighted-graph/SparseGraph.h weighted-graph/Edge.h heap/MinHeap.h weighted-graph/Minimum-Span-Trees/LazyPrimMST.h heap/IndexMinHeap.h weighted-graph/Minimum-Span-Trees/PrimMST.h weighted-graph/Minimum-Span-Trees/KruskalMST.h weighted-graph/shortest-path/Dijkstra.h weighted-graph/shortest-path/Dijkstra-Daolin.h weighted-graph/shortest-path/BellmanFord.h MyVector.h heap/IndexMaxHeap.h)