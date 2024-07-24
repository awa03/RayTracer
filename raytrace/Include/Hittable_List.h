#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>
#include "Hittable.h"

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
  hittable_list() {}
  hittable_list(shared_ptr<hittable> obj) {add(obj);}

  void clear() {objects.clear();}
  void add(shared_ptr<hittable> obj) {objects.push_back(obj);}

  virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

private:
  std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
  hit_record tmp; 
  bool hit_anything = false;
  auto closest = t_max;
  for(const auto& obj : objects){
    if(obj->hit(r, t_min, closest, tmp)){
      hit_anything = true;
      closest = tmp.t;
      rec = tmp;
    }
  }
  return hit_anything;
}

#endif // !HITTABLE_LIST_H
