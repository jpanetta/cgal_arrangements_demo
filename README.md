# Basic Demo of CGAL Arrangements
Some basic demo code for CGAL's 2D arrangements and arrangements on sphere functionality, adapted from [the documentation](https://doc.cgal.org/latest/Arrangement_on_surface_2/index.html).

```bash
$ mkdir build
$ cd build
$ cmake .. -GNinja
$ ninja
$ ./point_location_demo
The point (1 4) is located on an edge: 0 3 2 5
The point (4 3) is located inside a bounded face.
The point (6 3) is located on a vertex: 6 3
The point (3 2) is located on an isolated vertex: 3 2
The point (5 2) is located on an edge: 6 3 3 0
The point (1 0) is located inside the unbounded face.
$ ./sphere_arrangement_demo
The arrangement size:
   |V| = 6,  |E| = 12,  |F| = 8
   The point (1 1 1 0) is located inside a bounded face.
   The point (0 0 -1 1) is located on a vertex: 0 0 -1 1
   The point (0.5 0 0.5 0) is located on an edge: 1 0 0 0 0 0 1 3 -0 -1 -0 1 1 0
```
