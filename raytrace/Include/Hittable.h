#ifndef HITTABLE_H
#define HITTABLE_H
#include "Ray.h"
#include "RTFunc.h"
#include <memory>

class material;

struct hit_record {
  point3 p;
  vec3 normal;
  double t;
  shared_ptr<material> mat_ptr;
  bool front_face;

  inline void set_face_normal(const ray& r, const vec3& outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal :-outward_normal;
  }
};

class hittable {
public:
  // t min and max for valid intervals
  virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif // !HITTABLE_H
