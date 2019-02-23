//#pragma once
//
//
//
///*
//	int center_x = window_width / 2;
//	int center_y = window_height / 2;
//*/
//float angle = 0.1;
//float alpha = 0;
//float beta= 0;
//
//if (prev_x - x != 0) {
//	
//	angle = (prev_x - x) / abs(prev_x - x);
//
//	glRotatef(angle / 3, 0, 0, 1);
//
//
//	if (base.x != 0) 
//		beta = atan(base.y / base.x) * 180 / 3.14;
//	alpha = angle;
//	
//	base.x = cos((alpha + beta) * 3.14 / 180) * sqrt(x*x + y * y);
//	base.y = base.x * tan((angle + beta) * 3.14 / 180);
//
//	std::cout << "OX: axis " << base.x << " | " << base.y << " | " << base.z << std::endl;
//}
//
//if (prev_y - y != 0) {
//
//	 angle = -(prev_x - x) / abs(prev_x - x);
//
//   angle = abs(prev_x - x);
//
//   vector os = { (prev_y - y), 0, 0};
//
//   glRotatef(angle, os.x, os.y, 0);
//
//	glRotatef(angle, -(prev_y - y), 0, 0);
//}
//
//if (prev_x - x != 0) {
//
//	 angle = -(prev_x - x) / abs(prev_x - x);
//
//   angle = abs(prev_x - x);
//
//   vector os = { (prev_y - y), 0, 0};
//
//   glRotatef(angle, os.x, os.y, 0);
//
//	glRotatef(angle, 0, -(prev_x - x), 0);
//}
///**/
//if (prev_y - y != 0) {
//	angle = -(prev_y - y) / abs(prev_y - y);
//
//	vector os = { (prev_y - y), prev_x - x , base.z };
//
//	glRotatef(angle / 2, os.y, os.x, 0);
//}
//
//
//if (base.x != 0)
//	beta = atan(base.y / base.x) * 180 / 3.14;
//alpha = angle;
//
//base.x = cos((alpha + beta) * 3.14 / 180) * sqrt(x*x + y * y);
//base.y = base.x * tan((angle + beta) * 3.14 / 180);
//
//std::cout << "OY axis " << base.x << " | " << base.y << " | " << base.z << std::endl;
//
//}
//
//
//glRotatef(1, result.x, result.y, result.z);
//
// vector 1
//	vector base = { center_x - prev_x, center_y - prev_y, center_x };
//	vector base = { prev_x, prev_y, 100 };
//
//
//	vector user_vec = { x - prev_x, y - prev_y, 0.0f };
//
//	float angle = 0.0f;
//
//	vector result = findDirVector(base, user_vec);
//
//	glRotatef(1, result.x, result.y, result.z);
//
//
//	std::cout << "base vector: " << base.x << " | " << base.y << " | " << base.z << std::endl;
//	std::cout << "user vector: " << user_vec.x << " | " << user_vec.y << " | " << user_vec.z << std::endl;
//	std::cout << "rot vector: " << result.x << " | " << result.y << " | " << result.z << std::endl;
//
//	drawCoordinatesSystemFunc();
//
//
//	int center_x = window_width / 2;
//	int center_y = window_height / 2;
//
//
//	int range = center_x - x;
//	float angle = - range * 1.0 / center_x;
//
//	float huyangle = (x - prev_x) * 1.0 / center_x;
//
//	if (x - prev_x == 0) return;
//	if (y - prev_y == 0) return;
//
//	float zdvyg = 1;
//
//	/*if (x - prev_x < y - prev_y) zdvyg = (x - prev_x) / fabs((x - prev_x) * 5);
//	else zdvyg = (y - prev_y) / fabs((y - prev_y) * 5);*/
//	glRotatef(angle, 1, 0, 0);
//
//	glRotatef(zdvyg, fabs(x - prev_x), fabs(y - prev_y), 0 );
//
//	float delta_x = x - prev_x;
//	float delta_y = y - prev_y;
//
//	float factor = getNormilizinhFactor(delta_x, delta_y);
//
//	float new_x = delta_x / factor + base.x;
//	float new_y = delta_y / factor + base.y;
//
//	factor = getNormilizinhFactor(new_x, new_y);
//
//	base.x = new_x / factor;
//	base.y = new_y / factor;
//
//	std::cout << "vector: " << delta_x << " | " << delta_y << std::endl;
//
//	std::cout << "base vector: " << base.x << " | " << base.y << std::endl;
//
//	 prev_x = x; prev_y = y;