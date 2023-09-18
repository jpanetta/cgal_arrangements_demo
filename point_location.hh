#include <CGAL/Arr_point_location_result.h>
// Print the result of a point-location query.
template <typename Arrangement_>
void print_point_location(const typename Arrangement_::Point_2 &q, typename CGAL::Arr_point_location_result<Arrangement_>::Type obj)
{
    using Vertex_const_handle   = typename Arrangement_::Vertex_const_handle;
    using Halfedge_const_handle = typename Arrangement_::Halfedge_const_handle;
    using Face_const_handle     = typename Arrangement_::Face_const_handle;

    const Vertex_const_handle* v;
    const Halfedge_const_handle* e;
    const Face_const_handle* f;

    std::cout << "The point (" << q << ") is located ";
    if ((f = boost::get<Face_const_handle>(&obj))) {
        std::cout << "inside "
                  << (((*f)->is_unbounded()) ? "the unbounded" : "a bounded")
                  << " face." << std::endl;
    }
    else if ((e = boost::get<Halfedge_const_handle>(&obj))) // on an edge
        std::cout << "on an edge: " << (*e)->curve() << std::endl;
    else if ((v = boost::get<Vertex_const_handle>(&obj)))   // on a vertex
        std::cout << "on " << (((*v)->is_isolated()) ? "an isolated" : "a")
            << " vertex: " << (*v)->point() << std::endl;
    else CGAL_error_msg("Invalid object.");
}

//-----------------------------------------------------------------------------
// Perform a point-location query and print the result.
//
template <typename PointLocation>
void locate_point(const PointLocation& pl,
                  const typename PointLocation::Arrangement_2::Point_2& q)
{
    // Perform the point-location query.
    using Arrangement_2 = typename PointLocation::Arrangement_2;
    typename CGAL::Arr_point_location_result<Arrangement_2>::Type obj = pl.locate(q);

    print_point_location<Arrangement_2>(q, obj);
}
