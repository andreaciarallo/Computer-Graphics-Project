

void SetProjections(A02 *A) {
/**************
 Using A->SetMatrix(i, M) where:
 i -> index of the matrix to set (0 .. 7)
 M -> projection matrix to use

 define eight different types of projections.
 
 0 - Ortogonal Front (already given)
 1 - Isometric
 2 - Dimetric, with an angle of 20 degree
 3 - Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
 4 - Create a Cabinet projection, with the z axis at an angle of 45 degrees
 5 - Create a perspective projection, with a Fov-y of  90 degrees
 6 - Create a perspective projection, with a Fov-y of  30 degrees (zoom)
 7 - Create a perspective projection, with a Fov-y of 120 degrees (wide)

 Projection of type 0 is already done for you. Please create the other seven cases.
 For all the projections, the aspect ratio is supposed to be 4:3 (assuming the application
 is used on a screen with square pixels). Near plane is at 0.1 for perspective and orthogonal,
 while it is at -500 for isometric, dimetric, trimenteric and cabinet.
 The far plane is always at 500.
 For the parlallel projections, the half-width of the screen in world coordinates
 is assumed to be 20.
 
***************/
//	glm::mat4 M;
	glm::mat4 M;

	glm::mat4 vulkanCorrection = glm::mat4(
		1.0f,0,0,0,
		0,-1.0f,0,0,
		0,0,1.0f,0,
		0,0,0,1.0f);

	// Ortogonal Front
	// this is the only one correct, and that should not be modified
	M = glm::mat4(1.0f / 20.0f,0,0,0,
		0,-4.0f / 60.f,0,0,
		0,0,1.0f/(0.1f-500.0f),0,
		0,0,0.1f/(0.1f-500.0f),1);
	A->SetMatrix(0,  M);

	// Isometric
	glm::mat4 RY2 = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0, 1, 0));
	glm::mat4 RX2 = glm::rotate(glm::mat4(1.0f), glm::radians(35.26f), glm::vec3(1, 0, 0));

	M = glm::ortho(-20.0f, 20.0f, -15.0f, 15.0f, -500.0f, 500.0f);
	M = M * RX2 * RY2;

	A->SetMatrix(1,  vulkanCorrection * M);

	// Dimetric, with an angle of 20 degree
	M = glm::mat4(1.0f);
	A->SetMatrix(2,  M);
	
	// Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
	M = glm::mat4(1.0f);
	A->SetMatrix(3,  M);
	
	// Create a Cabinet projection, with the z axis at an angle of 45 degrees
	M = glm::mat4(1.0f);
	A->SetMatrix(4,  M);
	
	// Create a perspective projection, with a Fov-y of  90 degrees
	M = glm::mat4(1.0f);
	A->SetMatrix(5,  M);
	
	// Create a perspective projection, with a Fov-y of  30 degrees (zoom)
	M = glm::mat4(1.0f);
	A->SetMatrix(6,  M);
	
	// Create a perspective projection, with a Fov-y of 120 degrees (wide)
	M = glm::mat4(1.0f);
	A->SetMatrix(7,  M);

}
