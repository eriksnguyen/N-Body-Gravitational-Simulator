#include <nbody/Vector3.h>
#include <nbody/Body.h>
#include <nbody/integrator.h>
#include <nbody/rungekutta.h>
#include <nbody/euler.h>
#include <gtest/gtest.h>
#include <assert.h>

TEST( integratorTest, eulerIntegration ){
	auto integrationScheme = Euler{};
	auto body = Body{};
	//Initial conditions
	body.position() = 
	body.velocity() = 
	body.accel() = 
	
	//Under constant acceleration what happens 
	for(int i = 0; i < 1000; i++){
		integrationScheme.updateBody(body, .000001, 1.0);
	}
	float accel_calc = ;
	CPPUNIT_ASSERT(accel_calc - body.accel() < accel_calc * 0.01f)
	
}

TEST( integratorTest, RK4Integration ){aj 
	auto integrationScheme = RungeKutta{};
	auto body = Body{};
	//Initial conditions
	body.position() = 
	body.velocity() = 
	body.accel()    = 

	//Under constant acceleration what happens
	for(int i = 0; i < 10000; i++){
		integrationScheme.updateBody(body, .000001, 1.0);
	}
	float accel_calc = ;
	CPPUNIT_ASSERT(accel_calc - body.accel() < accel_calc * 0.01f)
	
	
}

