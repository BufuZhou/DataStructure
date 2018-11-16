#include "varincludes.h"


////////////////////////////////////////////////////////////////////////

#define START_SECTION_OEM_ONLINE_10MS
#include <shared_pragmas.h>

#define START_SECTION_OEM_CODE_10MS
#include <shared_pragmas.h>

/////////////////////////////////////////////////////////////////////

UINT16_T	DIG_OUT_UW = 0;
UINT16_T	DIG_PWM_OUT_UW = 0;
/*
UINT16_T	PPP = 0;
UINT8_T		PPP_Diag = 0;
UINT8_T		PPP_Info = 0;
UINT16_T	TTT = 0;
UINT8_T		TTT_Diag = 0;
UINT8_T		TTT_Info = 0;
*/
///////////////////////////////////////////////

UINT8_T		DIG_S_SHORT_TO_POWER_UB = 0;
UINT8_T		DIG_S_SHORT_TO_GROUND_UB = 0;
UINT8_T		DIG_S_OPEN_CIRCUIT_UB = 0;

UINT8_T		DIG_S_PWM_SHORT_TO_POWER_UB = 0;
UINT8_T		DIG_S_PWM_SHORT_TO_GROUND_UB = 0;
UINT8_T		DIG_S_PWM_OPEN_CIRCUIT_UB = 0;

UINT16_T	DIG_S_H_EL_DIAG_UW = 0;
UINT16_T	DIG_S_H_UV_DIAG_UW = 0;
UINT16_T	DIG_S_H_IL_DIAG_UW = 0;


UINT16_T    TEST_DiagValid = 0;
UINT16_T    TEST_DiagSymp = 0;
UINT16_T    TEST_Result = 0;


UINT32_T	VAR_V_UL = 0;
UINT16_T	VAR_V_UW = 0;
UINT32_T	EWAT_VAR_T_RAW_UL = 0;
UINT32_T	EACM_VAR_T_RAW_UL = 0;
UINT32_T	TEST_VAR_T_RAW_UL = 0;


#define START_SECTION_OEM_CAL
#include <shared_pragmas.h>



const	UINT8_T		NUM_UB = 0;
const	UINT8_T		PWM_NUM_UB = 0;

const	UINT8_T		NUM2_UB = 0;
const	UINT8_T		NUM3_UB = 0;
const	UINT8_T		NUM4_UB = 30;
const	UINT8_T		NUM5_UB = 0;
const	UINT8_T		NUM6_UB = 0;
const	UINT8_T		NUM7_UB = 0;
const	UINT8_T		OUT_SWI_UB = 0;
const	UINT8_T		OUT_SWI7_UB = 0;
const	UINT8_T		NUM8_UB = 0;

const	UINT32_T	VAR_PER_T_W = 5000;
const	INT16_T		VAR_RATE_W = 0;


#define STOP_SECTION_OEM_CAL
#include <shared_pragmas.h>



void App_Test(void)
{

	///////////////////////////////////////////////////////////
		FAW_Get_IO_Out_status(NUM5_UB, &DIG_OUT_UW);
	////////////////////////////////////////////////////////////////////////////////
		if (((DIG_OUT_UW & 0x0001) != 0) && ((DIG_OUT_UW & 0x0100) != 0))
		{
			DIG_S_SHORT_TO_POWER_UB = 1;
		}
		else
		{
			DIG_S_SHORT_TO_POWER_UB = 0;
		}
	////////////////////////////////////////////////////////////////////////////////
		if (((DIG_OUT_UW & 0x0002) != 0) && ((DIG_OUT_UW & 0x0200) != 0))
		{
			DIG_S_SHORT_TO_GROUND_UB = 1;
		}
		else
		{
			DIG_S_SHORT_TO_GROUND_UB = 0;
		}
	////////////////////////////////////////////////////////////////////////////////
		if (((DIG_OUT_UW & 0x0004) != 0) && ((DIG_OUT_UW & 0x0400) != 0))
		{
			DIG_S_OPEN_CIRCUIT_UB = 1;
		}
		else
		{
			DIG_S_OPEN_CIRCUIT_UB = 0;
		}
	////////////////////////////////////////////////////////////////////////////////

		FAW_Get_PWM_status(PWM_NUM_UB, &DIG_PWM_OUT_UW);
	////////////////////////////////////////////////////////////////////////////////
			if (((DIG_PWM_OUT_UW & 0x0001) != 0) && ((DIG_PWM_OUT_UW & 0x0100) != 0))
			{
				DIG_S_PWM_SHORT_TO_POWER_UB = 1;
			}
			else
			{
				DIG_S_PWM_SHORT_TO_POWER_UB = 0;
			}
	////////////////////////////////////////////////////////////////////////////////
			if (((DIG_PWM_OUT_UW & 0x0002) != 0) && ((DIG_PWM_OUT_UW & 0x0200) != 0))
			{
				DIG_S_PWM_SHORT_TO_GROUND_UB = 1;
			}
			else
			{
				DIG_S_PWM_SHORT_TO_GROUND_UB = 0;
			}
	////////////////////////////////////////////////////////////////////////////////
			if (((DIG_PWM_OUT_UW & 0x0004) != 0) && ((DIG_PWM_OUT_UW & 0x0400) != 0))
			{
				DIG_S_PWM_OPEN_CIRCUIT_UB = 1;
			}
			else
			{
				DIG_S_PWM_OPEN_CIRCUIT_UB = 0;
			}
	////////////////////////////////////////////////////////////////////////////////

			/*
			if (NUM7_UB == 0)
			{
				DIG_S_H_EL_DIAG_UW = IoHwAb_Hbr_GetElDiag(HB00_Diag);
				DIG_S_H_UV_DIAG_UW = IoHwAb_Hbr_GetUvDiag(HB00_Diag);
				DIG_S_H_IL_DIAG_UW = IoHwAb_Hbr_GetIlimDiag(HB00_Diag);
			}
			else if (NUM7_UB == 1)
			{
				DIG_S_H_EL_DIAG_UW = IoHwAb_Hbr_GetElDiag(HB01_Diag);
				DIG_S_H_UV_DIAG_UW = IoHwAb_Hbr_GetUvDiag(HB01_Diag);
				DIG_S_H_IL_DIAG_UW = IoHwAb_Hbr_GetIlimDiag(HB01_Diag);
			}
			else if (NUM7_UB == 2)
			{
				DIG_S_H_EL_DIAG_UW = IoHwAb_Hbr_GetElDiag(HB02_Diag);
				DIG_S_H_UV_DIAG_UW = IoHwAb_Hbr_GetUvDiag(HB02_Diag);
				DIG_S_H_IL_DIAG_UW = IoHwAb_Hbr_GetIlimDiag(HB02_Diag);
			}
			else{}
			*/
				//璁￠噺闃�骞冲潎鐢垫祦閲囨牱1ms

				FAW_Get_input_a2d(NUM_UB, &VAR_V_UL);

				FAW_Get_input_discrete(NUM2_UB, &VAR_V_UW , 0);

			    FAW_INFR_Dop(NUM3_UB, OUT_SWI_UB);								//X3.07
			    FAW_INFR_Dop(NUM7_UB, OUT_SWI7_UB);								//X3.07

//			    FAW_INFR_Dop(51, 0);								//O_D_UC_DIS0
//			    FAW_INFR_Dop(52, 0);								//O_D_UC_DIS1

			    Put_output_pwm(NUM4_UB, VAR_PER_T_W , VAR_RATE_W);				//X3.06
			    /*
//			    IoHwAb_LsHs_GetDiagEl(NUM8_UB, &TEST_DiagValid, &TEST_DiagSymp, &TEST_Result);


			    FAW_IoHwAb_Hbr_Set(NUM6_UB, VAR_PER_T_W, VAR_RATE_W, 0);

			    FAW_PwmIn_GetTime(NUM6_UB,  &TEST_VAR_T_RAW_UL);  //X1.62

			    FAW_PwmIn_GetTime(0, &EWAT_VAR_T_RAW_UL);  //X2.32
			    FAW_PwmIn_GetTime(3,  &EACM_VAR_T_RAW_UL);  //X1.62

			    IoHwAb_AMP_GetAMP(&PPP, &PPP_Diag, &PPP_Info);
			    IoHwAb_AMP_GetTemp(&TTT, &TTT_Diag, &TTT_Info);
			*/

}



#define STOP_SECTION_OEM_ONLINE_10MS
#include <shared_pragmas.h>

#define STOP_SECTION_OEM_CODE_10MS
#include <shared_pragmas.h>


