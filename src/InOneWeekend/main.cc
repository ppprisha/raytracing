//==============================================================================================
// Originally written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==============================================================================================

#include <iostream>
#include "color.h"
#include "vec3.h"

int main() {
	int image_width = 256;
	int image_height = 256;
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining..." << (image_height - j) << ' ' << std::flush; // progress indicator for longer renders
		for (int i = 0; i < image_width; i++) {
			auto pixel_color = color(double(i) / (image_width-1), double(j)/(image_height-1), 0);
			write_color(std::cout, pixel_color);		
		}
	}
	std::clog << "\rDone.				\n";
}
