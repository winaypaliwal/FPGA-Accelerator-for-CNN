// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _densifyto64_HH_
#define _densifyto64_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "dev_digits_classihbi.h"
#include "densifyto64_biasefYi.h"
#include "densifyto64_weighg8j.h"

namespace ap_rtl {

struct densifyto64 : public sc_module {
    // Port declarations 14
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<9> > in_V_address0;
    sc_out< sc_logic > in_V_ce0;
    sc_in< sc_lv<12> > in_V_q0;
    sc_out< sc_lv<6> > out_V_address0;
    sc_out< sc_logic > out_V_ce0;
    sc_out< sc_logic > out_V_we0;
    sc_out< sc_lv<12> > out_V_d0;
    sc_in< sc_lv<12> > out_V_q0;


    // Module declarations
    densifyto64(sc_module_name name);
    SC_HAS_PROCESS(densifyto64);

    ~densifyto64();

    sc_trace_file* mVcdFile;

    densifyto64_biasefYi* biases_dense64_V_U;
    densifyto64_weighg8j* weights_dense64_V_U;
    dev_digits_classihbi<1,1,9,12,21>* dev_digits_classihbi_U10;
    sc_signal< sc_lv<12> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<6> > biases_dense64_V_address0;
    sc_signal< sc_logic > biases_dense64_V_ce0;
    sc_signal< sc_lv<7> > biases_dense64_V_q0;
    sc_signal< sc_lv<15> > weights_dense64_V_address0;
    sc_signal< sc_logic > weights_dense64_V_ce0;
    sc_signal< sc_lv<9> > weights_dense64_V_q0;
    sc_signal< sc_lv<7> > j_3_fu_185_p2;
    sc_signal< sc_lv<7> > j_3_reg_504;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<64> > tmp_fu_191_p1;
    sc_signal< sc_lv<64> > tmp_reg_509;
    sc_signal< sc_lv<1> > exitcond5_fu_179_p2;
    sc_signal< sc_lv<9> > i_4_fu_235_p2;
    sc_signal< sc_lv<9> > i_4_reg_522;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > exitcond6_fu_229_p2;
    sc_signal< sc_lv<15> > tmp_59_fu_246_p3;
    sc_signal< sc_lv<15> > tmp_59_reg_532;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<21> > OP1_V_fu_254_p1;
    sc_signal< sc_lv<21> > OP1_V_reg_537;
    sc_signal< sc_lv<7> > j_4_fu_268_p2;
    sc_signal< sc_lv<7> > j_4_reg_545;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<1> > exitcond7_fu_262_p2;
    sc_signal< sc_lv<6> > out_V_addr_2_reg_555;
    sc_signal< sc_lv<9> > weights_dense64_V_lo_reg_560;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<21> > p_Val2_25_fu_495_p2;
    sc_signal< sc_lv<21> > p_Val2_25_reg_565;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<1> > tmp_88_reg_570;
    sc_signal< sc_lv<1> > signbit_reg_575;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<12> > p_Val2_27_reg_584;
    sc_signal< sc_lv<1> > tmp_89_reg_589;
    sc_signal< sc_lv<7> > i_5_fu_478_p2;
    sc_signal< sc_lv<7> > i_5_reg_598;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<6> > out_V_addr_1_reg_603;
    sc_signal< sc_lv<1> > exitcond_fu_472_p2;
    sc_signal< sc_lv<7> > j_reg_134;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<9> > i_reg_145;
    sc_signal< sc_lv<7> > j1_reg_157;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<7> > i2_reg_168;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<64> > tmp_s_fu_241_p1;
    sc_signal< sc_lv<64> > tmp_64_fu_284_p1;
    sc_signal< sc_lv<64> > tmp_62_fu_274_p1;
    sc_signal< sc_lv<64> > tmp_60_fu_484_p1;
    sc_signal< sc_lv<12> > p_Val2_33_cast_fu_224_p1;
    sc_signal< sc_lv<12> > this_assign_1_fu_463_p3;
    sc_signal< sc_lv<1> > tmp_61_fu_489_p2;
    sc_signal< sc_lv<6> > tmp_85_fu_196_p4;
    sc_signal< sc_lv<1> > tmp_86_fu_210_p1;
    sc_signal< sc_lv<7> > p_Val2_32_cast_cas_fu_206_p1;
    sc_signal< sc_lv<7> > tmp_cast_cast_fu_214_p1;
    sc_signal< sc_lv<7> > p_Val2_23_fu_218_p2;
    sc_signal< sc_lv<15> > j1_cast5_fu_258_p1;
    sc_signal< sc_lv<15> > tmp_63_fu_279_p2;
    sc_signal< sc_lv<20> > tmp_65_fu_299_p3;
    sc_signal< sc_lv<21> > tmp_89_cast_fu_307_p1;
    sc_signal< sc_lv<21> > p_Val2_26_fu_311_p2;
    sc_signal< sc_lv<12> > tmp_66_fu_342_p1;
    sc_signal< sc_lv<12> > p_Val2_28_fu_345_p2;
    sc_signal< sc_lv<1> > newsignbit_fu_350_p3;
    sc_signal< sc_lv<1> > tmp_67_fu_358_p2;
    sc_signal< sc_lv<1> > p_Result_16_not_fu_369_p2;
    sc_signal< sc_lv<1> > not_carry_fu_374_p2;
    sc_signal< sc_lv<1> > carry_fu_364_p2;
    sc_signal< sc_lv<1> > deleted_zeros_fu_380_p2;
    sc_signal< sc_lv<1> > p_not_i_i_fu_395_p2;
    sc_signal< sc_lv<1> > brmerge_i_i_fu_401_p2;
    sc_signal< sc_lv<1> > tmp_68_fu_385_p2;
    sc_signal< sc_lv<1> > p_38_i_i_fu_390_p2;
    sc_signal< sc_lv<1> > brmerge40_demorgan_i_fu_413_p2;
    sc_signal< sc_lv<1> > tmp1_demorgan_fu_418_p2;
    sc_signal< sc_lv<1> > underflow_fu_424_p2;
    sc_signal< sc_lv<1> > overflow_fu_407_p2;
    sc_signal< sc_lv<1> > tmp2_fu_435_p2;
    sc_signal< sc_lv<1> > brmerge_i_i_i_fu_429_p2;
    sc_signal< sc_lv<1> > underflow_not_fu_441_p2;
    sc_signal< sc_lv<12> > p_Val2_33_mux_fu_447_p3;
    sc_signal< sc_lv<12> > p_Val2_s_39_fu_455_p3;
    sc_signal< sc_lv<12> > p_Val2_25_fu_495_p1;
    sc_signal< sc_lv<12> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<12> ap_ST_fsm_state1;
    static const sc_lv<12> ap_ST_fsm_state2;
    static const sc_lv<12> ap_ST_fsm_state3;
    static const sc_lv<12> ap_ST_fsm_state4;
    static const sc_lv<12> ap_ST_fsm_state5;
    static const sc_lv<12> ap_ST_fsm_state6;
    static const sc_lv<12> ap_ST_fsm_state7;
    static const sc_lv<12> ap_ST_fsm_state8;
    static const sc_lv<12> ap_ST_fsm_state9;
    static const sc_lv<12> ap_ST_fsm_state10;
    static const sc_lv<12> ap_ST_fsm_state11;
    static const sc_lv<12> ap_ST_fsm_state12;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<7> ap_const_lv7_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<9> ap_const_lv9_0;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<12> ap_const_lv12_0;
    static const sc_lv<7> ap_const_lv7_40;
    static const sc_lv<7> ap_const_lv7_1;
    static const sc_lv<9> ap_const_lv9_157;
    static const sc_lv<9> ap_const_lv9_1;
    static const sc_lv<6> ap_const_lv6_0;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<12> ap_const_lv12_7FF;
    static const sc_lv<12> ap_const_lv12_800;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_OP1_V_fu_254_p1();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_biases_dense64_V_address0();
    void thread_biases_dense64_V_ce0();
    void thread_brmerge40_demorgan_i_fu_413_p2();
    void thread_brmerge_i_i_fu_401_p2();
    void thread_brmerge_i_i_i_fu_429_p2();
    void thread_carry_fu_364_p2();
    void thread_deleted_zeros_fu_380_p2();
    void thread_exitcond5_fu_179_p2();
    void thread_exitcond6_fu_229_p2();
    void thread_exitcond7_fu_262_p2();
    void thread_exitcond_fu_472_p2();
    void thread_i_4_fu_235_p2();
    void thread_i_5_fu_478_p2();
    void thread_in_V_address0();
    void thread_in_V_ce0();
    void thread_j1_cast5_fu_258_p1();
    void thread_j_3_fu_185_p2();
    void thread_j_4_fu_268_p2();
    void thread_newsignbit_fu_350_p3();
    void thread_not_carry_fu_374_p2();
    void thread_out_V_address0();
    void thread_out_V_ce0();
    void thread_out_V_d0();
    void thread_out_V_we0();
    void thread_overflow_fu_407_p2();
    void thread_p_38_i_i_fu_390_p2();
    void thread_p_Result_16_not_fu_369_p2();
    void thread_p_Val2_23_fu_218_p2();
    void thread_p_Val2_25_fu_495_p1();
    void thread_p_Val2_26_fu_311_p2();
    void thread_p_Val2_28_fu_345_p2();
    void thread_p_Val2_32_cast_cas_fu_206_p1();
    void thread_p_Val2_33_cast_fu_224_p1();
    void thread_p_Val2_33_mux_fu_447_p3();
    void thread_p_Val2_s_39_fu_455_p3();
    void thread_p_not_i_i_fu_395_p2();
    void thread_this_assign_1_fu_463_p3();
    void thread_tmp1_demorgan_fu_418_p2();
    void thread_tmp2_fu_435_p2();
    void thread_tmp_59_fu_246_p3();
    void thread_tmp_60_fu_484_p1();
    void thread_tmp_61_fu_489_p2();
    void thread_tmp_62_fu_274_p1();
    void thread_tmp_63_fu_279_p2();
    void thread_tmp_64_fu_284_p1();
    void thread_tmp_65_fu_299_p3();
    void thread_tmp_66_fu_342_p1();
    void thread_tmp_67_fu_358_p2();
    void thread_tmp_68_fu_385_p2();
    void thread_tmp_85_fu_196_p4();
    void thread_tmp_86_fu_210_p1();
    void thread_tmp_89_cast_fu_307_p1();
    void thread_tmp_cast_cast_fu_214_p1();
    void thread_tmp_fu_191_p1();
    void thread_tmp_s_fu_241_p1();
    void thread_underflow_fu_424_p2();
    void thread_underflow_not_fu_441_p2();
    void thread_weights_dense64_V_address0();
    void thread_weights_dense64_V_ce0();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
