/*
 * nilu_slidingmode_J2.cpp
 *
 *  Created on: 30-Jan-2015
 *      Author: nilxwam
 */
#include <unistd.h>
#include <iostream>
#include <string>
#include <barrett/units.h>
#include <barrett/systems.h>
#include <barrett/products/product_manager.h>
#include <barrett/detail/stl_utils.h>
#include <barrett/log.h>
#include <barrett/standard_main_function.h>
//#include <boost/thread.hpp>
//#include <barrett/thread/null_mutex.h>

using namespace barrett;
using detail::waitForEnter;

#include <samlibs.h>
#include <reference_signal2.hpp>
#include <Dynamics.hpp>
#include <Sliding_mode_4dof_comp.hpp>
//#include <dummy	_system.hpp>
#include <GMM.hpp>
#include <differentiator.hpp>
#include <second_differentiator.hpp>
#include <torque_observer.hpp>
#include <dummy_system.hpp>

template<size_t DOF>
int wam_main(int argc, char** argv, ProductManager& pm,
		systems::Wam<DOF>& wam) {
	BARRETT_UNITS_TEMPLATE_TYPEDEFS(DOF);

	printf("Error 1 \n");
	size_t num_inp, num_op, num_priors;
	Eigen::VectorXd priors;/*!< an Eigen Vector value */
	Eigen::MatrixXd mean;/*!< an Eigen Matrix value */
	Eigen::MatrixXd sigma;
	Eigen::VectorXd output;
	printf("Error 2 \n");
	Sam::initEigenVec<double>(priors, Sam::readFile<double>("priors.txt"));
	Sam::initEigenMat<double>(mean, Sam::readFile<double>("mean.txt"));
	Sam::initEigenMat<double>(sigma, Sam::readFile<double>("sigma.txt"));
	printf("Error 3 \n");
	num_priors = priors.rows();
	std::map<std::string, std::string> allData_inp;
	printf("Error 4 \n");
	if (Sam::readConfigFile("sysconfig.txt", allData_inp)) {
		if (!Sam::findValueFromMap<size_t>(allData_inp, "num_input", num_inp)) {
			exit(EXIT_FAILURE);
		}
		if (!Sam::findValueFromMap<size_t>(allData_inp, "num_output", num_op)) {
			exit(EXIT_FAILURE);
		}
	} else
		exit(EXIT_FAILURE);
	printf("Error 5 \n");
	output.resize(num_op);
//
	Eigen::MatrixXd input_mean_matrix;
	input_mean_matrix.resize(num_inp, num_priors); //   input  position(xi) mean vector for 6 gaussians-------------------------------
	printf("Error 6 \n");
	Eigen::MatrixXd out_mean_matrix;
	out_mean_matrix.resize(num_op, num_priors); // changed here
	printf("Error 7 \n");
	Eigen::MatrixXd sigma_input;
	sigma_input.resize(num_inp * num_priors, num_inp);
	printf("Error 8 \n");
	Eigen::MatrixXd sigma_output_input; //   extracted sigma sigmadot for input
	sigma_output_input.resize(num_op * num_priors, num_inp); //------changed here
	printf("Error 9 \n");
	Eigen::MatrixXd Inverse_sigma_input; // inverse of the sigma matrix taking 6, 2x2 matrix
	Inverse_sigma_input.resize(num_inp * num_priors, num_inp);
	printf("Error 10 \n");
	Eigen::VectorXd p; //probability of input for 6 components
	p.resize(num_priors, 1);
	printf("Error 11 \n");
	Eigen::VectorXd h; // h value in the linear regression equation
	h.resize(num_priors, 1);
	printf("Error 12 \n");
	Eigen::MatrixXd A_matrix; // 'A' matrix in the linear regression equation
	A_matrix.resize(num_op * num_priors, num_inp); //-------------changed here
	printf("Error 13 \n");
	Eigen::MatrixXd B_matrix; // 'B' matrix in the linear regression equation
	B_matrix.resize(num_op, num_priors); //-------------changed here
	printf("Error 14 \n");
	int i = 0;
	int k = 0;

	input_mean_matrix = mean.block(0, 0, num_inp, num_priors);
	out_mean_matrix = mean.block(num_inp, 0, num_op, num_priors); //--------------changed here
	printf("Error 15 \n");
	for (i = 0; i < num_priors; i++) {
		sigma_input.block(num_inp * i, 0, num_inp, num_inp) = sigma.block(
				(num_inp + num_op) * i, 0, num_inp, num_inp);
	}
	printf("Error 16 \n");
	for (i = 0; i < num_priors; i++) {
		sigma_output_input.block(num_op * i, 0, num_op, num_inp) = sigma.block(
				(num_inp + num_op) * i + num_inp, 0, num_op, num_inp);
	}
	printf("Error 17 \n");
	for (i = 0; i < num_inp * num_priors - num_inp; i = i + num_inp) //inverse
			{
		Inverse_sigma_input.block(i, 0, num_inp, num_inp) = sigma_input.block(i,
				0, num_inp, num_inp).inverse();
	}
	printf("Error 18 \n");
	for (k = 0; k < num_op * num_priors - num_inp; k = k + num_op) { // changed
		A_matrix.block(k, 0, num_op, num_inp) = sigma_output_input.block(k, 0,
				num_op, num_inp)
				* Inverse_sigma_input.block(k, 0, num_inp, num_inp);
	}
	printf("Error 19 \n");
	for (k = 0; k < num_priors; k++) {
		B_matrix.col(k) = out_mean_matrix.col(k)
				- A_matrix.block(num_op * k, 0, num_op, num_inp) // changed
				* input_mean_matrix.col(k);
	}
	printf("Error 20 \n");
	Eigen::VectorXd det_tmp_tmp;
	det_tmp_tmp.resize(num_priors, 1);

	Eigen::MatrixXd tmp_inv;
	tmp_inv.resize(num_inp * num_priors, num_inp);
	printf("Error 21 \n");
	for (k = 0; k < num_priors; k++) {
		det_tmp_tmp[k] = pow(
				double(
						fabs(
								sigma_input.block(num_inp * k, 0, num_inp,
										num_inp).determinant())), 0.5);

		tmp_inv.block(num_inp * k, 0, num_inp, num_inp) = sigma_input.block(
				num_inp * k, 0, num_inp, num_inp).inverse();
	}
	printf("Error 22 \n");
	typedef boost::tuple<double, jp_type, jv_type, jp_type, jv_type, jt_type,jt_type> tuple_type;
	typedef systems::TupleGrouper<double, jp_type, jv_type, jp_type, jv_type,
			jt_type,jt_type> tg_type;
	tg_type tg;
	char tmpFile[] = "btXXXXXX";
	if (mkstemp(tmpFile) == -1) {
		printf("ERROR: Couldn't create temporary file!\n");
		return 1;
	}
	const double TRANSITION_DURATION = 0.5;
	double amplitude1, omega1;
	Eigen::Matrix4d tmp_lamda;
	tmp_lamda << 20, 0, 0, 0, 0, 20, 0, 0, 0, 0, 20, 0, 0, 0, 0, 20;
	const Eigen::Matrix4d lamda = tmp_lamda;

	double COEFF;
	std::cout << "Enter Coeff: " << std::endl;
	std::cin >> COEFF;
	const double coeff = COEFF;
	double DELTA;
	std::cout << "Enter delta: " << std::endl;
	std::cin >> DELTA;
	const double delta = DELTA;
	jp_type startpos(0.0);

	std::cout << "Enter amplitude of ref sinusoid: " << std::endl;
	std::cin >> amplitude1;
	std::cout << "Enter omega of ref sinusoid: " << std::endl;
	std::cin >> omega1;
	startpos[3] = +3.14;

	int mode1;
//	mode = 3;
	std::cout << "Enter mode for first diff: " << std::endl;
	std::cin >> mode1;

	int mode2;
	//	mode = 3;
	std::cout << "Enter mode for second diff: " << std::endl;
	std::cin >> mode2;

	bool status = true;	//	mode = 3;
//	std::cout << "Enter the status of the compensator " << std::endl;
//	std::cin >> status;

	const double JP_AMPLITUDE = amplitude1;
	const double OMEGA = omega1;


	Eigen::Matrix4d lambda;
	lambda << 200, 0, 0, 0, 0, 200, 0, 0, 0, 0, 200, 0, 0, 0, 0, 200;

//	// std cout
//	std::cout << "Value of priors\n" << priors << std::endl;
//	std::cout << "Value of sigma\n" << sigma << std::endl;
//	std::cout << "Value of mean\n" << mean << std::endl;
//	std::cout << "Value of num_inp\n" << num_inp << std::endl;
//	std::cout << "Value of num_op\n" << num_op << std::endl;
//	std::cout << "Value of num_priors\n" << num_priors << std::endl;
//	std::cout << "Value of sigma_input\n" << sigma_input << std::endl;
//	std::cout << "Value of input_mean_matrix\n" << input_mean_matrix
//			<< std::endl;
//	std::cout << "Value of A_matrix\n" << A_matrix << std::endl;
//	std::cout << "Value of B_matrix\n" << B_matrix << std::endl;
//	std::cout << "Value of det_tmp_tmp\n" << det_tmp_tmp << std::endl;
//	std::cout << "Value of tmp_inv\n" << tmp_inv << std::endl;

	//

	J_ref<DOF> joint_ref(JP_AMPLITUDE, OMEGA, startpos);
	Slidingmode_Controller<DOF> slide(status, lamda, coeff, delta);
	Dynamics<DOF> nilu_dynamics;
	GMM<DOF> nilu_GMM(priors, mean, sigma, num_inp, num_op, num_priors,
			sigma_input, input_mean_matrix, A_matrix, B_matrix, det_tmp_tmp,
			tmp_inv);

	wam.gravityCompensate();
	printf("Press [Enter] to turn on torque control to go to zero position");
	waitForEnter();

	wam.moveTo(startpos);
	printf("Press [Enter] to turn on torque control to joint 2.");
	waitForEnter();
	systems::Ramp time(pm.getExecutionManager(), 1.0);
	const size_t PERIOD_MULTIPLIER = 1;
	systems::PeriodicDataLogger<tuple_type> logger(pm.getExecutionManager(),
			new log::RealTimeWriter<tuple_type>(tmpFile,
					PERIOD_MULTIPLIER * pm.getExecutionManager()->getPeriod()),
			PERIOD_MULTIPLIER);
	printf("Error a \n");

	systems::connect(tg.output, logger.input);
	systems::connect(time.output, joint_ref.timef);
	systems::connect(wam.jpOutput, slide.feedbackjpInput);
	systems::connect(wam.jvOutput, slide.feedbackjvInput);
	systems::connect(wam.jpOutput, nilu_dynamics.jpInputDynamics);
	systems::connect(wam.jvOutput, nilu_dynamics.jvInputDynamics);
	systems::connect(nilu_dynamics.MassMAtrixOutput, slide.M);
	systems::connect(nilu_dynamics.CVectorOutput, slide.C);
	systems::connect(joint_ref.referencejpTrack, slide.referencejpInput);
	systems::connect(joint_ref.referencejvTrack, slide.referencejvInput);
	systems::connect(joint_ref.referencejaTrack, slide.referencejaInput);
	systems::connect(wam.jpOutput, nilu_GMM.jpInputActual);
	systems::connect(wam.jvOutput, nilu_GMM.jvInputActual);
	systems::connect(nilu_GMM.error_output, slide.C_comp);

	wam.trackReferenceSignal(slide.controlOutput);

	systems::connect(time.output, tg.template getInput<0>());
	systems::connect(joint_ref.referencejpTrack, tg.template getInput<1>());
	systems::connect(joint_ref.referencejvTrack, tg.template getInput<2>());
	systems::connect(wam.jpOutput, tg.template getInput<3>());
	systems::connect(wam.jvOutput, tg.template getInput<4>());
	systems::connect(slide.controlOutput, tg.template getInput<5>());
	systems::connect(nilu_GMM.error_output, tg.template getInput<6>());

	printf("Error b \n");


	time.smoothStart(TRANSITION_DURATION);
	printf("Press [Enter] to stop.");
	waitForEnter();
	logger.closeLog();

	printf("Error e \n");


	time.smoothStop(TRANSITION_DURATION);
	wam.idle();

	printf("Error c \n");


	pm.getSafetyModule()->waitForMode(SafetyModule::IDLE);
	log::Reader<boost::tuple<tuple_type> > lr(tmpFile);
	lr.exportCSV(argv[1]);

	printf("Error d \n");


	printf("Output written to %s.\n", argv[1]);
	std::remove(tmpFile);
//	std::ofstream log(argv[1], std::ios_base::app | std::ios_base::out);
//	log << COEFF << "," << DELTA << "," << amplitude1 << "," << omega1 << ","
//			<< "0" << "," << "0" << "," << "0" << "," << "0" << "," << "0"
//			<< "," << "0" << "," << "0" << "," << "0" << "," << "0" << ","
//			<< "0" << "," << "0" << "," << "0" << "," << "0" << "," << "0"
//			<< "," << "0" << "," << "0" << "," << "0" << "," << "0" << ","
//			<< "0" << "," << "0" << "," << "0" "," << "0" << "," << "0" << ","
//			<< "0" << "," << "0";
//	log.close();
	return 0;
}

