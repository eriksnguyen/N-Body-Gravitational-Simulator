#include <nbody/Vector3.h>
#include <nbody/Body.h>
#include <nbody/integrator.h>
#include <nbody/rungekutta.h>
#include <gtest/gtest.h>

TEST( rungekuttaTest, RK4Integration0 ){
	auto integrationScheme = nbody::RungeKutta{};
	auto body = nbody::Body{};
	//Initial conditions
	body.position() = Vector3f{ 0, 0, 0 };
	body.velocity() = Vector3f{ 0, 0, 0 };
	body.accel() = Vector3f{ 0, 0, 0 };
	
	//Under constant acceleration what happens 
	for( int i = 0; i < 1000000; i++ ){
		integrationScheme.updateBody( body, .000001, 1.0);
	}
	auto pos_calc = Vector3f{ 0, 0, 0 };
	std::cout << "integrator calc" << body.position() << "\n";
	std::cout << "ideal position" << pos_calc << "\n";
	
	ASSERT_TRUE( (pos_calc - body.position()).norm() <= pos_calc.norm() * 0.01f );
	
}


TEST( rungekuttaTest, RK4Integration1 ){
	auto integrationScheme = nbody::RungeKutta{};
	auto body = nbody::Body{};
	//Initial conditions
	body.position() = Vector3f{ 0, 0, 0 };
	body.velocity() = Vector3f{ 0, 0, 0 };
	body.accel() = Vector3f{ 1, 0, 0 };
	
	//Under constant acceleration what happens 
	for( int i = 0; i < 1000000; i++ ){
		integrationScheme.updateBody( body, .000001, 1.0);
	}
	auto pos_calc = Vector3f{ 0.5, 0, 0 };
	std::cout << "integrator calc" << body.position() << "\n";
	std::cout << "ideal position" << pos_calc << "\n";
	
	ASSERT_TRUE( (pos_calc - body.position()).norm() <= pos_calc.norm() * 0.01f );
	
}

TEST( rungekuttaTest, RK4Integration2 ){
	auto integrationScheme = nbody::RungeKutta{};
	auto body = nbody::Body{};
	//Initial conditions
	body.position() = Vector3f{ 1, 0, 0 };
	body.velocity() = Vector3f{ 1, 0, 0 };
	body.accel() = Vector3f{ 1, 0, 0 };
	
	//Under constant acceleration what happens 
	for( int i = 0; i < 1000000; i++ ){
		integrationScheme.updateBody( body, .000001, 1.0);
	}
	auto pos_calc = Vector3f{ 2.5, 0, 0 };
	std::cout << "integrator calc" << body.position() << "\n";
	std::cout << "ideal position" << pos_calc << "\n";
	
	ASSERT_TRUE( (pos_calc - body.position()).norm() <= pos_calc.norm() * 0.01f );
	
}

TEST( rungekuttaTest, RK4Integration3 ){
	auto integrationScheme = nbody::RungeKutta{};
	auto body = nbody::Body{};
	//Initial conditions
	body.position() = Vector3f{ 1, 0, 0 };
	body.velocity() = Vector3f{ 0, 1, 0 };
	body.accel() = Vector3f{ 0, 0, 1 };
	
	//Under constant acceleration what happens 
	for( int i = 0; i < 1000000; i++ ){
		integrationScheme.updateBody( body, .000001, 1.0);
	}
	auto pos_calc = Vector3f{ 1, 1, 0.5 };
	std::cout << "integrator calc" << body.position() << "\n";
	std::cout << "ideal position" << pos_calc << "\n";
	
	ASSERT_TRUE( (pos_calc - body.position()).norm() <= pos_calc.norm() * 0.01f );
	
}
