#include <nbody/Vector3.h>
#include <nbody/Body.h>
#include <nbody/integrator.h>
#include <nbody/rungekutta.h>
#include <nbody/euler.h>
#include <gtest/gtest.h>
#include <assert.h>

TEST( integratorTest, eulerIntegration0 ){
	auto integrationScheme = Euler{};
	auto body = Body{};
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

TEST( integratorTest, eulerIntegration1 ){
	auto integrationScheme = Euler{};
	auto body = Body{};
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

TEST( integratorTest, RK4Integration0 ){
	auto integrationScheme = RungeKutta{};
	auto body = Body{};
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


TEST( integratorTest, RK4Integration1 ){
	auto integrationScheme = RungeKutta{};
	auto body = Body{};
	//Initial conditions
	body.position() = 
	body.velocity() = 
	body.accel()    = 

	//Under constant acceleration what happens 
	for( int i = 0; i < 1000000; i++ ){
		integrationScheme.updateBody( body, .000001, 1.0);
	}
	auto pos_calc = Vector3f{ 0.5, 0, 0 };
	std::cout << "integrator calc" << body.position() << "\n";
	std::cout << "ideal position" << pos_calc << "\n";
	
	ASSERT_TRUE( (pos_calc - body.position()).norm() <= pos_calc.norm() * 0.01f );
	
}

int main() {

	std::ofstream output{ "integrator_test.out" };
	output << std::fixed;
	output << std::scientific;
	output << std::setprecision( 8 );
	
	TEST( integratorTest, eulerIntegration0 );
	TEST( integratorTest, eulerIntegration1 );
	TEST( integratorTest, RK4Integration0 );
	TEST( integratorTest, RK4Integration1 );
	
}