// Answering point-location queries.
#include <CGAL/basic.h>
#include <CGAL/Arr_naive_point_location.h>
#include <CGAL/Arr_landmarks_point_location.h>

#if 0
#include "arr_inexact_construction_segments.h"
#else
#include "arr_exact_construction_segments.h"
#endif

#include "point_location.hh"
typedef CGAL::Arr_naive_point_location<Arrangement>         Naive_pl;
typedef CGAL::Arr_landmarks_point_location<Arrangement>     Landmarks_pl;

//-----------------------------------------------------------------------------
// Construct the arrangement of segments needed for the point-location and
// the vertical ray-shooting examples.
// The function assumes that the arrangement is of line segments with integer
// coordinates.
//
template <typename Arrangement_>
void construct_segments_arr(Arrangement_& arr)
{
    typedef Arrangement_                                Arrangement_2;
    typedef typename Arrangement_2::Point_2             Point_2;
    typedef typename Arrangement_2::X_monotone_curve_2  Segment_2;
    typedef typename Arrangement_2::Halfedge_handle     Halfedge_handle;

    Point_2 p0(3,2), p1(0,3), p2(2,5), p3(4,5), p4(6,3), p5(3,0);
    Segment_2 s1(p1, p2), s2(p2, p3), s3(p3, p4), s4(p4, p5), s5(p5, p1);

    arr.insert_in_face_interior(p0, arr.unbounded_face());

    Halfedge_handle e1 = arr.insert_in_face_interior(s1, arr.unbounded_face());
    Halfedge_handle e2 = arr.insert_from_left_vertex(s2, e1->target());
    Halfedge_handle e3 = arr.insert_from_left_vertex(s3, e2->target());
    Halfedge_handle e4 = arr.insert_from_right_vertex(s4, e3->target());
    arr.insert_at_vertices(s5, e4->target(), e1->source());
}

int main() {
    // Construct the arrangement.
    Arrangement arr;
    construct_segments_arr(arr);
    // Perform some point-location queries using the naive strategy.
    Naive_pl naive_pl(arr);
    locate_point(naive_pl, Point(1, 4));          // q1
    locate_point(naive_pl, Point(4, 3));          // q2
    locate_point(naive_pl, Point(6, 3));          // q3
                                                  // Perform some point-location queries using the landmark strategy.
    Landmarks_pl landmarks_pl(arr);
    locate_point(landmarks_pl, Point(3, 2));      // q4
    locate_point(landmarks_pl, Point(5, 2));      // q5
    locate_point(landmarks_pl, Point(1, 0));      // q6
    return 0;
}
