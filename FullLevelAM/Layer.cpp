//
// Created by Lo on 2023/4/24.
//

#include "Layer.h"

namespace nsp {

	Layer::Layer(std::multimap <double, Triangle> ts){
		this->triangles = ts;
		int num = 0;
		std::multimap <double, Triangle>::iterator it;
		for (it = triangles.begin(); it != triangles.end(); it++) {
			std::cout << "��=" << (it->first) << " ֵ=" << (it->second).A.toString() << std::endl;
			num++;
		}
		std::cout << num;//480 for 236.STL
	}
}