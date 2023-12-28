#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record {
	public:
		point3 p;
		vec3 normal;
		double t;
		bool front_face;

		void set_face_normal(const ray& r, const vec3& outward_normal) {
			//Sets the hit record normal vector.
			//NOTE: the parameter outward normal is assumed to have unit length

			front_face = dot(r.direction(), outward_normal) < 0;
			//if front facing, normal pointing away from center to surface; if not front facing, normal pointing to center from surface
			normal = front_face ? outward_normal : -outward_normal;
		}
};

class hittable {
	public:
		virtual ~hittable() = default;

		virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

};

#endif