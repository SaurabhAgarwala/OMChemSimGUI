/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "heater1_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation heater1_performSimulation
#define prefixedName_updateContinuousSystem heater1_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation heater1_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int heater1_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int heater1_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int heater1_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int heater1_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int heater1_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 181
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[1,1] = MatStm4.compMolFlo[1,1] * MatStm4.comp[1].MW
*/
void heater1_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  data->localData[0]->realVars[109] /* MatStm4.compMasFlo[1,1] variable */ = (data->localData[0]->realVars[133] /* MatStm4.compMolFlo[1,1] variable */) * (data->simulationInfo->realParameter[481]);
  TRACE_POP
}
/*
equation index: 182
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[1,2] = MatStm4.compMolFlo[1,2] * MatStm4.comp[2].MW
*/
void heater1_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  data->localData[0]->realVars[110] /* MatStm4.compMasFlo[1,2] variable */ = (data->localData[0]->realVars[134] /* MatStm4.compMolFlo[1,2] variable */) * (data->simulationInfo->realParameter[482]);
  TRACE_POP
}
/*
equation index: 183
type: SIMPLE_ASSIGN
MatStm4._K[1] = 9.869232667160129e-006 * MatStm4.Psat[1]
*/
void heater1_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  data->localData[0]->realVars[98] /* MatStm4.K[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[106] /* MatStm4.Psat[1] variable */);
  TRACE_POP
}
/*
equation index: 184
type: SIMPLE_ASSIGN
MatStm4._K[2] = 9.869232667160129e-006 * MatStm4.Psat[2]
*/
void heater1_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->localData[0]->realVars[99] /* MatStm4.K[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[107] /* MatStm4.Psat[2] variable */);
  TRACE_POP
}
void heater1_eqFunction_185(DATA*, threadData_t*);
void heater1_eqFunction_186(DATA*, threadData_t*);
void heater1_eqFunction_187(DATA*, threadData_t*);
void heater1_eqFunction_188(DATA*, threadData_t*);
void heater1_eqFunction_189(DATA*, threadData_t*);
void heater1_eqFunction_190(DATA*, threadData_t*);
void heater1_eqFunction_195(DATA*, threadData_t*);
void heater1_eqFunction_194(DATA*, threadData_t*);
void heater1_eqFunction_193(DATA*, threadData_t*);
void heater1_eqFunction_192(DATA*, threadData_t*);
void heater1_eqFunction_191(DATA*, threadData_t*);
/*
equation index: 207
indexNonlinear: 2
type: NONLINEAR

vars: {MatStm4._totMolFlo[2], MatStm4._compMolFrac[2,2], MatStm4._compMolFrac[2,1], MatStm4._compMolFrac[3,1], MatStm4._compMolFrac[3,2]}
eqns: {185, 186, 187, 188, 189, 190, 195, 194, 193, 192, 191}
*/
void heater1_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 207 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = data->localData[0]->realVars[183] /* MatStm4.totMolFlo[2] variable */;
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[1] = data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[2] = data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[3] = data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[4] = data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,207};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 207 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[183] /* MatStm4.totMolFlo[2] variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[1];
  data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[2];
  data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[3];
  data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[4];
  TRACE_POP
}
/*
equation index: 208
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[3,2] = MatStm4.compMolFlo[3,2] * MatStm4.comp[2].MW
*/
void heater1_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  data->localData[0]->realVars[114] /* MatStm4.compMasFlo[3,2] variable */ = (data->localData[0]->realVars[138] /* MatStm4.compMolFlo[3,2] variable */) * (data->simulationInfo->realParameter[482]);
  TRACE_POP
}
/*
equation index: 209
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[2,2] = MatStm4.compMolFlo[2,2] * MatStm4.comp[2].MW
*/
void heater1_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  data->localData[0]->realVars[112] /* MatStm4.compMasFlo[2,2] variable */ = (data->localData[0]->realVars[136] /* MatStm4.compMolFlo[2,2] variable */) * (data->simulationInfo->realParameter[482]);
  TRACE_POP
}
/*
equation index: 210
type: SIMPLE_ASSIGN
Heater1._inVapPhasMolFrac = (-MatStm4.liqPhasMolFrac) - -1.0
*/
void heater1_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  data->localData[0]->realVars[6] /* Heater1.inVapPhasMolFrac variable */ = (-data->localData[0]->realVars[158] /* MatStm4.liqPhasMolFrac variable */) - (-1.0);
  TRACE_POP
}
/*
equation index: 211
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[2,1] = MatStm4.compMolFlo[2,1] * MatStm4.comp[1].MW
*/
void heater1_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->localData[0]->realVars[111] /* MatStm4.compMasFlo[2,1] variable */ = (data->localData[0]->realVars[135] /* MatStm4.compMolFlo[2,1] variable */) * (data->simulationInfo->realParameter[481]);
  TRACE_POP
}
/*
equation index: 212
type: SIMPLE_ASSIGN
MatStm4._compMasFlo[3,1] = MatStm4.compMolFlo[3,1] * MatStm4.comp[1].MW
*/
void heater1_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  data->localData[0]->realVars[113] /* MatStm4.compMasFlo[3,1] variable */ = (data->localData[0]->realVars[137] /* MatStm4.compMolFlo[3,1] variable */) * (data->simulationInfo->realParameter[481]);
  TRACE_POP
}
/*
equation index: 213
type: SIMPLE_ASSIGN
MatStm4._phasMolEnth[3] = MatStm4.compMolFrac[3,1] * MatStm4.compMolEnth[3,1] + MatStm4.compMolFrac[3,2] * MatStm4.compMolEnth[3,2]
*/
void heater1_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->localData[0]->realVars[163] /* MatStm4.phasMolEnth[3] variable */ = (data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */) * (data->localData[0]->realVars[125] /* MatStm4.compMolEnth[3,1] variable */) + (data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */) * (data->localData[0]->realVars[126] /* MatStm4.compMolEnth[3,2] variable */);
  TRACE_POP
}
/*
equation index: 214
type: SIMPLE_ASSIGN
MatStm4._phasMolSpHeat[3] = MatStm4.compMolFrac[3,1] * MatStm4.compMolSpHeat[3,1] + MatStm4.compMolFrac[3,2] * MatStm4.compMolSpHeat[3,2]
*/
void heater1_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  data->localData[0]->realVars[169] /* MatStm4.phasMolSpHeat[3] variable */ = (data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */) * (data->localData[0]->realVars[149] /* MatStm4.compMolSpHeat[3,1] variable */) + (data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */) * (data->localData[0]->realVars[150] /* MatStm4.compMolSpHeat[3,2] variable */);
  TRACE_POP
}
/*
equation index: 215
type: ALGORITHM

  (MatStm4.compMolEntr[2,1], MatStm4.compMolEntr[3,1]) := Simulator.Files.Thermodynamic_Functions.SId(MatStm4.comp[1].AS, {MatStm4.comp[1].VapCp[1], MatStm4.comp[1].VapCp[2], MatStm4.comp[1].VapCp[3], MatStm4.comp[1].VapCp[4], MatStm4.comp[1].VapCp[5], MatStm4.comp[1].VapCp[6]}, {MatStm4.comp[1].HOV[1], MatStm4.comp[1].HOV[2], MatStm4.comp[1].HOV[3], MatStm4.comp[1].HOV[4], MatStm4.comp[1].HOV[5], MatStm4.comp[1].HOV[6]}, MatStm4.comp[1].Tb, MatStm4.comp[1].Tc, 309.9999999999999, 101325.0, MatStm4.compMolFrac[2,1], MatStm4.compMolFrac[3,1]);
*/
void heater1_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[517], (modelica_real)data->simulationInfo->realParameter[518], (modelica_real)data->simulationInfo->realParameter[519], (modelica_real)data->simulationInfo->realParameter[520], (modelica_real)data->simulationInfo->realParameter[521], (modelica_real)data->simulationInfo->realParameter[522]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[417], (modelica_real)data->simulationInfo->realParameter[418], (modelica_real)data->simulationInfo->realParameter[419], (modelica_real)data->simulationInfo->realParameter[420], (modelica_real)data->simulationInfo->realParameter[421], (modelica_real)data->simulationInfo->realParameter[422]);
  data->localData[0]->realVars[129] /* MatStm4.compMolEntr[2,1] variable */ = omc_Simulator_Files_Thermodynamic__Functions_SId(threadData, data->simulationInfo->realParameter[399], tmp0, tmp1, data->simulationInfo->realParameter[495], data->simulationInfo->realParameter[497], 309.9999999999999, 101325.0, data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */, data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */ ,&data->localData[0]->realVars[131] /* MatStm4.compMolEntr[3,1] variable */);
  TRACE_POP
}
/*
equation index: 216
type: SIMPLE_ASSIGN
MatStm4._phasMolEnth[2] = MatStm4.compMolFrac[2,1] * MatStm4.compMolEnth[2,1] + MatStm4.compMolFrac[2,2] * MatStm4.compMolEnth[2,2]
*/
void heater1_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->localData[0]->realVars[162] /* MatStm4.phasMolEnth[2] variable */ = (data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */) * (data->localData[0]->realVars[123] /* MatStm4.compMolEnth[2,1] variable */) + (data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */) * (data->localData[0]->realVars[124] /* MatStm4.compMolEnth[2,2] variable */);
  TRACE_POP
}
/*
equation index: 217
type: SIMPLE_ASSIGN
MatStm4._phasMolEnth[1] = MatStm4.liqPhasMolFrac * MatStm4.phasMolEnth[2] + Heater1.inVapPhasMolFrac * MatStm4.phasMolEnth[3]
*/
void heater1_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->localData[0]->realVars[161] /* MatStm4.phasMolEnth[1] variable */ = (data->localData[0]->realVars[158] /* MatStm4.liqPhasMolFrac variable */) * (data->localData[0]->realVars[162] /* MatStm4.phasMolEnth[2] variable */) + (data->localData[0]->realVars[6] /* Heater1.inVapPhasMolFrac variable */) * (data->localData[0]->realVars[163] /* MatStm4.phasMolEnth[3] variable */);
  TRACE_POP
}
/*
equation index: 218
type: SIMPLE_ASSIGN
MatStm4._compMolEnth[1,2] = MatStm4.compMolFrac[1,2] * MatStm4.phasMolEnth[1]
*/
void heater1_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->localData[0]->realVars[122] /* MatStm4.compMolEnth[1,2] variable */ = (data->localData[0]->realVars[140] /* MatStm4.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[161] /* MatStm4.phasMolEnth[1] variable */);
  TRACE_POP
}
/*
equation index: 219
type: SIMPLE_ASSIGN
MatStm4._compMolEnth[1,1] = MatStm4.compMolFrac[1,1] * MatStm4.phasMolEnth[1]
*/
void heater1_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->localData[0]->realVars[121] /* MatStm4.compMolEnth[1,1] variable */ = (data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[161] /* MatStm4.phasMolEnth[1] variable */);
  TRACE_POP
}
/*
equation index: 220
type: SIMPLE_ASSIGN
MatStm1._phasMolEnth[1] = MatStm4.phasMolEnth[1] + 100.0 * Heater1.eff
*/
void heater1_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  data->localData[0]->realVars[72] /* MatStm1.phasMolEnth[1] variable */ = data->localData[0]->realVars[161] /* MatStm4.phasMolEnth[1] variable */ + (100.0) * (data->simulationInfo->realParameter[237]);
  TRACE_POP
}
/*
equation index: 221
type: SIMPLE_ASSIGN
MatStm4._phasMolSpHeat[2] = MatStm4.compMolFrac[2,1] * MatStm4.compMolSpHeat[2,1] + MatStm4.compMolFrac[2,2] * MatStm4.compMolSpHeat[2,2]
*/
void heater1_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->localData[0]->realVars[168] /* MatStm4.phasMolSpHeat[2] variable */ = (data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */) * (data->localData[0]->realVars[147] /* MatStm4.compMolSpHeat[2,1] variable */) + (data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */) * (data->localData[0]->realVars[148] /* MatStm4.compMolSpHeat[2,2] variable */);
  TRACE_POP
}
/*
equation index: 222
type: SIMPLE_ASSIGN
MatStm4._phasMolSpHeat[1] = MatStm4.liqPhasMolFrac * MatStm4.phasMolSpHeat[2] + Heater1.inVapPhasMolFrac * MatStm4.phasMolSpHeat[3]
*/
void heater1_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->localData[0]->realVars[167] /* MatStm4.phasMolSpHeat[1] variable */ = (data->localData[0]->realVars[158] /* MatStm4.liqPhasMolFrac variable */) * (data->localData[0]->realVars[168] /* MatStm4.phasMolSpHeat[2] variable */) + (data->localData[0]->realVars[6] /* Heater1.inVapPhasMolFrac variable */) * (data->localData[0]->realVars[169] /* MatStm4.phasMolSpHeat[3] variable */);
  TRACE_POP
}
/*
equation index: 223
type: SIMPLE_ASSIGN
MatStm4._compMolSpHeat[1,2] = MatStm4.compMolFrac[1,2] * MatStm4.phasMolSpHeat[1]
*/
void heater1_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  data->localData[0]->realVars[146] /* MatStm4.compMolSpHeat[1,2] variable */ = (data->localData[0]->realVars[140] /* MatStm4.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[167] /* MatStm4.phasMolSpHeat[1] variable */);
  TRACE_POP
}
/*
equation index: 224
type: SIMPLE_ASSIGN
MatStm4._compMolSpHeat[1,1] = MatStm4.compMolFrac[1,1] * MatStm4.phasMolSpHeat[1]
*/
void heater1_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  data->localData[0]->realVars[145] /* MatStm4.compMolSpHeat[1,1] variable */ = (data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[167] /* MatStm4.phasMolSpHeat[1] variable */);
  TRACE_POP
}
/*
equation index: 225
type: ALGORITHM

  (MatStm4.compMolEntr[2,2], MatStm4.compMolEntr[3,2]) := Simulator.Files.Thermodynamic_Functions.SId(MatStm4.comp[2].AS, {MatStm4.comp[2].VapCp[1], MatStm4.comp[2].VapCp[2], MatStm4.comp[2].VapCp[3], MatStm4.comp[2].VapCp[4], MatStm4.comp[2].VapCp[5], MatStm4.comp[2].VapCp[6]}, {MatStm4.comp[2].HOV[1], MatStm4.comp[2].HOV[2], MatStm4.comp[2].HOV[3], MatStm4.comp[2].HOV[4], MatStm4.comp[2].HOV[5], MatStm4.comp[2].HOV[6]}, MatStm4.comp[2].Tb, MatStm4.comp[2].Tc, 309.9999999999999, 101325.0, MatStm4.compMolFrac[2,2], MatStm4.compMolFrac[3,2]);
*/
void heater1_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[523], (modelica_real)data->simulationInfo->realParameter[524], (modelica_real)data->simulationInfo->realParameter[525], (modelica_real)data->simulationInfo->realParameter[526], (modelica_real)data->simulationInfo->realParameter[527], (modelica_real)data->simulationInfo->realParameter[528]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[423], (modelica_real)data->simulationInfo->realParameter[424], (modelica_real)data->simulationInfo->realParameter[425], (modelica_real)data->simulationInfo->realParameter[426], (modelica_real)data->simulationInfo->realParameter[427], (modelica_real)data->simulationInfo->realParameter[428]);
  data->localData[0]->realVars[130] /* MatStm4.compMolEntr[2,2] variable */ = omc_Simulator_Files_Thermodynamic__Functions_SId(threadData, data->simulationInfo->realParameter[400], tmp2, tmp3, data->simulationInfo->realParameter[496], data->simulationInfo->realParameter[498], 309.9999999999999, 101325.0, data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */, data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */ ,&data->localData[0]->realVars[132] /* MatStm4.compMolEntr[3,2] variable */);
  TRACE_POP
}
/*
equation index: 226
type: SIMPLE_ASSIGN
MatStm4._phasMolEntr[3] = MatStm4.compMolFrac[3,1] * MatStm4.compMolEntr[3,1] + MatStm4.compMolFrac[3,2] * MatStm4.compMolEntr[3,2]
*/
void heater1_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->localData[0]->realVars[166] /* MatStm4.phasMolEntr[3] variable */ = (data->localData[0]->realVars[143] /* MatStm4.compMolFrac[3,1] variable */) * (data->localData[0]->realVars[131] /* MatStm4.compMolEntr[3,1] variable */) + (data->localData[0]->realVars[144] /* MatStm4.compMolFrac[3,2] variable */) * (data->localData[0]->realVars[132] /* MatStm4.compMolEntr[3,2] variable */);
  TRACE_POP
}
/*
equation index: 227
type: SIMPLE_ASSIGN
MatStm4._phasMolEntr[2] = MatStm4.compMolFrac[2,1] * MatStm4.compMolEntr[2,1] + MatStm4.compMolFrac[2,2] * MatStm4.compMolEntr[2,2]
*/
void heater1_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->localData[0]->realVars[165] /* MatStm4.phasMolEntr[2] variable */ = (data->localData[0]->realVars[141] /* MatStm4.compMolFrac[2,1] variable */) * (data->localData[0]->realVars[129] /* MatStm4.compMolEntr[2,1] variable */) + (data->localData[0]->realVars[142] /* MatStm4.compMolFrac[2,2] variable */) * (data->localData[0]->realVars[130] /* MatStm4.compMolEntr[2,2] variable */);
  TRACE_POP
}
/*
equation index: 228
type: SIMPLE_ASSIGN
MatStm4._phasMolEntr[1] = MatStm4.liqPhasMolFrac * MatStm4.phasMolEntr[2] + Heater1.inVapPhasMolFrac * MatStm4.phasMolEntr[3]
*/
void heater1_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->localData[0]->realVars[164] /* MatStm4.phasMolEntr[1] variable */ = (data->localData[0]->realVars[158] /* MatStm4.liqPhasMolFrac variable */) * (data->localData[0]->realVars[165] /* MatStm4.phasMolEntr[2] variable */) + (data->localData[0]->realVars[6] /* Heater1.inVapPhasMolFrac variable */) * (data->localData[0]->realVars[166] /* MatStm4.phasMolEntr[3] variable */);
  TRACE_POP
}
/*
equation index: 229
type: SIMPLE_ASSIGN
MatStm4._compMolEntr[1,2] = MatStm4.compMolFrac[1,2] * MatStm4.phasMolEntr[1]
*/
void heater1_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->localData[0]->realVars[128] /* MatStm4.compMolEntr[1,2] variable */ = (data->localData[0]->realVars[140] /* MatStm4.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[164] /* MatStm4.phasMolEntr[1] variable */);
  TRACE_POP
}
/*
equation index: 230
type: SIMPLE_ASSIGN
MatStm4._compMolEntr[1,1] = MatStm4.compMolFrac[1,1] * MatStm4.phasMolEntr[1]
*/
void heater1_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->localData[0]->realVars[127] /* MatStm4.compMolEntr[1,1] variable */ = (data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[164] /* MatStm4.phasMolEntr[1] variable */);
  TRACE_POP
}
/*
equation index: 231
type: ALGORITHM

  MatStm4.MW[3] := $START.MatStm4.MW[3];
  MatStm4.MW[2] := $START.MatStm4.MW[2];
  MatStm4.MW[1] := $START.MatStm4.MW[1];
  for i in 1:2 loop
    MatStm4.MW[:] := {MatStm4.MW[1] + MatStm4.compMolFrac[1,i] * MatStm4.comp[i].MW, MatStm4.MW[2] + MatStm4.compMolFrac[2,i] * MatStm4.comp[i].MW, MatStm4.MW[3] + MatStm4.compMolFrac[3,i] * MatStm4.comp[i].MW};
  end for;
*/
void heater1_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  real_array tmp4;
  index_spec_t tmp5;
  real_array tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  data->localData[0]->realVars[102] /* MatStm4.MW[3] variable */ = data->modelData->realVarsData[102].attribute /* MatStm4.MW[3] variable */.start;

  data->localData[0]->realVars[101] /* MatStm4.MW[2] variable */ = data->modelData->realVarsData[101].attribute /* MatStm4.MW[2] variable */.start;

  data->localData[0]->realVars[100] /* MatStm4.MW[1] variable */ = data->modelData->realVarsData[100].attribute /* MatStm4.MW[1] variable */.start;

  tmp7 = ((modelica_integer) 1); tmp8 = 1; tmp9 = ((modelica_integer) 2);
  if(!(((tmp8 > 0) && (tmp7 > tmp9)) || ((tmp8 < 0) && (tmp7 < tmp9))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp7, tmp9); $Pi += tmp8)
    {
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[100] /* MatStm4.MW[1] variable */ + ((&data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[481])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[101] /* MatStm4.MW[2] variable */ + ((&data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[481])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[102] /* MatStm4.MW[3] variable */ + ((&data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[481])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[100] /* MatStm4.MW[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}
/*
equation index: 232
type: SIMPLE_ASSIGN
MatStm4._totMasFlo[1] = 200.0 * MatStm4.MW[1]
*/
void heater1_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->localData[0]->realVars[179] /* MatStm4.totMasFlo[1] variable */ = (200.0) * (data->localData[0]->realVars[100] /* MatStm4.MW[1] variable */);
  TRACE_POP
}
/*
equation index: 233
type: SIMPLE_ASSIGN
MatStm4._compMasFrac[1,2] = MatStm4.compMasFlo[1,2] / MatStm4.totMasFlo[1]
*/
void heater1_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  data->localData[0]->realVars[116] /* MatStm4.compMasFrac[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[110] /* MatStm4.compMasFlo[1,2] variable */,data->localData[0]->realVars[179] /* MatStm4.totMasFlo[1] variable */,"MatStm4.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 234
type: SIMPLE_ASSIGN
MatStm4._totMasFlo[3] = MatStm4.totMolFlo[3] * MatStm4.MW[3]
*/
void heater1_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  data->localData[0]->realVars[181] /* MatStm4.totMasFlo[3] variable */ = (data->localData[0]->realVars[184] /* MatStm4.totMolFlo[3] variable */) * (data->localData[0]->realVars[102] /* MatStm4.MW[3] variable */);
  TRACE_POP
}
/*
equation index: 235
type: SIMPLE_ASSIGN
MatStm4._vapPhasMasFrac = MatStm4.totMasFlo[3] / MatStm4.totMasFlo[1]
*/
void heater1_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->localData[0]->realVars[185] /* MatStm4.vapPhasMasFrac variable */ = DIVISION_SIM(data->localData[0]->realVars[181] /* MatStm4.totMasFlo[3] variable */,data->localData[0]->realVars[179] /* MatStm4.totMasFlo[1] variable */,"MatStm4.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 236
type: SIMPLE_ASSIGN
MatStm4._totMasFlo[2] = MatStm4.totMolFlo[2] * MatStm4.MW[2]
*/
void heater1_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->localData[0]->realVars[180] /* MatStm4.totMasFlo[2] variable */ = (data->localData[0]->realVars[183] /* MatStm4.totMolFlo[2] variable */) * (data->localData[0]->realVars[101] /* MatStm4.MW[2] variable */);
  TRACE_POP
}
/*
equation index: 237
type: SIMPLE_ASSIGN
MatStm4._liqPhasMasFrac = MatStm4.totMasFlo[2] / MatStm4.totMasFlo[1]
*/
void heater1_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  data->localData[0]->realVars[157] /* MatStm4.liqPhasMasFrac variable */ = DIVISION_SIM(data->localData[0]->realVars[180] /* MatStm4.totMasFlo[2] variable */,data->localData[0]->realVars[179] /* MatStm4.totMasFlo[1] variable */,"MatStm4.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 238
type: LINEAR

<var>MatStm4._compMasFrac[2,1]</var>
<var>MatStm4._compMasFrac[3,1]</var>
<var>MatStm4._compMasFrac[1,1]</var>
<var>MatStm4._compMasFrac[2,2]</var>
<var>MatStm4._compMasFrac[3,2]</var>
<row>
  <cell>if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then MatStm4.compMasFlo[2,1] else 0.0</cell>
  <cell>if 101325.0 >= MatStm4.Pbubl then -MatStm4.compMasFrac[1,2] else if 101325.0 >= MatStm4.Pdew then MatStm4.compMasFlo[3,2] else -MatStm4.compMasFrac[1,2]</cell>
  <cell>if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then MatStm4.compMasFlo[2,2] else 0.0</cell>
  <cell>if 101325.0 >= MatStm4.Pbubl then MatStm4.compMasFlo[1,1] else if 101325.0 >= MatStm4.Pdew then MatStm4.compMasFlo[3,1] else MatStm4.compMasFlo[1,1]</cell>
  <cell>if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then MatStm4.compMasFlo[1,1] else 0.0</cell>
</row>
<matrix>
  <cell row="0" col="0">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -MatStm4.totMasFlo[2] else 0.0)</residual>
  </cell><cell row="0" col="3">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="0" col="4">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="1" col="3">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="1" col="4">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -MatStm4.totMasFlo[3] else 1.0)</residual>
  </cell><cell row="2" col="0">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="2" col="1">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="2" col="2">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then -1.0 else if 101325.0 >= MatStm4.Pdew then -0.0 else -1.0)</residual>
  </cell><cell row="2" col="3">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -MatStm4.totMasFlo[2] else 0.0)</residual>
  </cell><cell row="3" col="1">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then -0.0 else if 101325.0 >= MatStm4.Pdew then -MatStm4.totMasFlo[3] else -0.0)</residual>
  </cell><cell row="3" col="2">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then -MatStm4.totMasFlo[1] else if 101325.0 >= MatStm4.Pdew then -0.0 else -MatStm4.totMasFlo[1])</residual>
  </cell><cell row="4" col="0">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="4" col="1">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="4" col="2">
    <residual>-(if 101325.0 >= MatStm4.Pbubl then 0.0 else if 101325.0 >= MatStm4.Pdew then -MatStm4.totMasFlo[1] else 0.0)</residual>
  </cell>
</matrix>
*/
OMC_DISABLE_OPT
void heater1_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  /* Linear equation system */
  int retValue;
  double aux_x[5] = { data->localData[1]->realVars[117] /* MatStm4.compMasFrac[2,1] variable */,data->localData[1]->realVars[119] /* MatStm4.compMasFrac[3,1] variable */,data->localData[1]->realVars[115] /* MatStm4.compMasFrac[1,1] variable */,data->localData[1]->realVars[118] /* MatStm4.compMasFrac[2,2] variable */,data->localData[1]->realVars[120] /* MatStm4.compMasFrac[3,2] variable */ };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 238 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,238};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 238 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[117] /* MatStm4.compMasFrac[2,1] variable */ = aux_x[0];
  data->localData[0]->realVars[119] /* MatStm4.compMasFrac[3,1] variable */ = aux_x[1];
  data->localData[0]->realVars[115] /* MatStm4.compMasFrac[1,1] variable */ = aux_x[2];
  data->localData[0]->realVars[118] /* MatStm4.compMasFrac[2,2] variable */ = aux_x[3];
  data->localData[0]->realVars[120] /* MatStm4.compMasFrac[3,2] variable */ = aux_x[4];
  TRACE_POP
}
/*
equation index: 239
type: SIMPLE_ASSIGN
MatStm1._compMolFrac[1,2] = MatStm4.compMolFrac[1,2]
*/
void heater1_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->localData[0]->realVars[51] /* MatStm1.compMolFrac[1,2] variable */ = data->localData[0]->realVars[140] /* MatStm4.compMolFrac[1,2] variable */;
  TRACE_POP
}
/*
equation index: 240
type: SIMPLE_ASSIGN
MatStm1._compMolFlo[1,2] = 200.0 * MatStm1.compMolFrac[1,2]
*/
void heater1_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  data->localData[0]->realVars[45] /* MatStm1.compMolFlo[1,2] variable */ = (200.0) * (data->localData[0]->realVars[51] /* MatStm1.compMolFrac[1,2] variable */);
  TRACE_POP
}
/*
equation index: 241
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[1,2] = MatStm1.compMolFlo[1,2] * MatStm1.comp[2].MW
*/
void heater1_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->localData[0]->realVars[21] /* MatStm1.compMasFlo[1,2] variable */ = (data->localData[0]->realVars[45] /* MatStm1.compMolFlo[1,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}
/*
equation index: 242
type: SIMPLE_ASSIGN
MatStm1._compMolEnth[1,2] = MatStm1.compMolFrac[1,2] * MatStm1.phasMolEnth[1]
*/
void heater1_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->localData[0]->realVars[33] /* MatStm1.compMolEnth[1,2] variable */ = (data->localData[0]->realVars[51] /* MatStm1.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[72] /* MatStm1.phasMolEnth[1] variable */);
  TRACE_POP
}
/*
equation index: 243
type: SIMPLE_ASSIGN
MatStm1._compMolFrac[1,1] = MatStm4.compMolFrac[1,1]
*/
void heater1_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */ = data->localData[0]->realVars[139] /* MatStm4.compMolFrac[1,1] variable */;
  TRACE_POP
}
/*
equation index: 244
type: SIMPLE_ASSIGN
MatStm1._compMolFlo[1,1] = 200.0 * MatStm1.compMolFrac[1,1]
*/
void heater1_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  data->localData[0]->realVars[44] /* MatStm1.compMolFlo[1,1] variable */ = (200.0) * (data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */);
  TRACE_POP
}
/*
equation index: 245
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[1,1] = MatStm1.compMolFlo[1,1] * MatStm1.comp[1].MW
*/
void heater1_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->localData[0]->realVars[20] /* MatStm1.compMasFlo[1,1] variable */ = (data->localData[0]->realVars[44] /* MatStm1.compMolFlo[1,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}
/*
equation index: 246
type: SIMPLE_ASSIGN
MatStm1._compMolEnth[1,1] = MatStm1.compMolFrac[1,1] * MatStm1.phasMolEnth[1]
*/
void heater1_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  data->localData[0]->realVars[32] /* MatStm1.compMolEnth[1,1] variable */ = (data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[72] /* MatStm1.phasMolEnth[1] variable */);
  TRACE_POP
}
void heater1_eqFunction_247(DATA*, threadData_t*);
void heater1_eqFunction_248(DATA*, threadData_t*);
void heater1_eqFunction_249(DATA*, threadData_t*);
void heater1_eqFunction_250(DATA*, threadData_t*);
void heater1_eqFunction_251(DATA*, threadData_t*);
void heater1_eqFunction_252(DATA*, threadData_t*);
void heater1_eqFunction_253(DATA*, threadData_t*);
void heater1_eqFunction_254(DATA*, threadData_t*);
void heater1_eqFunction_255(DATA*, threadData_t*);
void heater1_eqFunction_256(DATA*, threadData_t*);
void heater1_eqFunction_257(DATA*, threadData_t*);
void heater1_eqFunction_258(DATA*, threadData_t*);
void heater1_eqFunction_259(DATA*, threadData_t*);
void heater1_eqFunction_260(DATA*, threadData_t*);
void heater1_eqFunction_261(DATA*, threadData_t*);
void heater1_eqFunction_262(DATA*, threadData_t*);
void heater1_eqFunction_263(DATA*, threadData_t*);
void heater1_eqFunction_264(DATA*, threadData_t*);
void heater1_eqFunction_265(DATA*, threadData_t*);
void heater1_eqFunction_266(DATA*, threadData_t*);
void heater1_eqFunction_267(DATA*, threadData_t*);
void heater1_eqFunction_268(DATA*, threadData_t*);
void heater1_eqFunction_269(DATA*, threadData_t*);
void heater1_eqFunction_270(DATA*, threadData_t*);
void heater1_eqFunction_276(DATA*, threadData_t*);
void heater1_eqFunction_275(DATA*, threadData_t*);
void heater1_eqFunction_274(DATA*, threadData_t*);
void heater1_eqFunction_273(DATA*, threadData_t*);
void heater1_eqFunction_272(DATA*, threadData_t*);
void heater1_eqFunction_271(DATA*, threadData_t*);
/*
equation index: 277
indexNonlinear: 3
type: NONLINEAR

vars: {MatStm1._totMolFlo[3], Heater1._outT, MatStm1._compMolFrac[3,1], MatStm1._compMolFrac[2,1], MatStm1._compMolFrac[2,2], MatStm1._compMolFrac[3,2]}
eqns: {247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 276, 275, 274, 273, 272, 271}
*/
void heater1_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 277 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = data->localData[0]->realVars[94] /* MatStm1.totMolFlo[3] variable */;
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[1] = data->localData[0]->realVars[8] /* Heater1.outT variable */;
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[2] = data->localData[0]->realVars[54] /* MatStm1.compMolFrac[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[3] = data->localData[0]->realVars[52] /* MatStm1.compMolFrac[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[4] = data->localData[0]->realVars[53] /* MatStm1.compMolFrac[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[5] = data->localData[0]->realVars[55] /* MatStm1.compMolFrac[3,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,277};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 277 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[94] /* MatStm1.totMolFlo[3] variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  data->localData[0]->realVars[8] /* Heater1.outT variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[1];
  data->localData[0]->realVars[54] /* MatStm1.compMolFrac[3,1] variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[2];
  data->localData[0]->realVars[52] /* MatStm1.compMolFrac[2,1] variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[3];
  data->localData[0]->realVars[53] /* MatStm1.compMolFrac[2,2] variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[4];
  data->localData[0]->realVars[55] /* MatStm1.compMolFrac[3,2] variable */ = data->simulationInfo->nonlinearSystemData[3].nlsx[5];
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[3,1] = MatStm1.compMolFlo[3,1] * MatStm1.comp[1].MW
*/
void heater1_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  data->localData[0]->realVars[24] /* MatStm1.compMasFlo[3,1] variable */ = (data->localData[0]->realVars[48] /* MatStm1.compMolFlo[3,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[2,1] = MatStm1.compMolFlo[2,1] * MatStm1.comp[1].MW
*/
void heater1_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  data->localData[0]->realVars[22] /* MatStm1.compMasFlo[2,1] variable */ = (data->localData[0]->realVars[46] /* MatStm1.compMolFlo[2,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[3,2] = MatStm1.compMolFlo[3,2] * MatStm1.comp[2].MW
*/
void heater1_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  data->localData[0]->realVars[25] /* MatStm1.compMasFlo[3,2] variable */ = (data->localData[0]->realVars[49] /* MatStm1.compMolFlo[3,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
MatStm1._compMasFlo[2,2] = MatStm1.compMolFlo[2,2] * MatStm1.comp[2].MW
*/
void heater1_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  data->localData[0]->realVars[23] /* MatStm1.compMasFlo[2,2] variable */ = (data->localData[0]->realVars[47] /* MatStm1.compMolFlo[2,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
Heater1._tempInc = Heater1.outT - 309.9999999999999
*/
void heater1_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  data->localData[0]->realVars[10] /* Heater1.tempInc variable */ = data->localData[0]->realVars[8] /* Heater1.outT variable */ - 309.9999999999999;
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[2,1] = Simulator.Files.Thermodynamic_Functions.LiqCpId({MatStm1.comp[1].LiqCp[1], MatStm1.comp[1].LiqCp[2], MatStm1.comp[1].LiqCp[3], MatStm1.comp[1].LiqCp[4], MatStm1.comp[1].LiqCp[5], MatStm1.comp[1].LiqCp[6]}, Heater1.outT)
*/
void heater1_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[275], (modelica_real)data->simulationInfo->realParameter[276], (modelica_real)data->simulationInfo->realParameter[277], (modelica_real)data->simulationInfo->realParameter[278], (modelica_real)data->simulationInfo->realParameter[279], (modelica_real)data->simulationInfo->realParameter[280]);
  data->localData[0]->realVars[58] /* MatStm1.compMolSpHeat[2,1] variable */ = omc_Simulator_Files_Thermodynamic__Functions_LiqCpId(threadData, tmp0, data->localData[0]->realVars[8] /* Heater1.outT variable */);
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[3,1] = Simulator.Files.Thermodynamic_Functions.VapCpId({MatStm1.comp[1].VapCp[1], MatStm1.comp[1].VapCp[2], MatStm1.comp[1].VapCp[3], MatStm1.comp[1].VapCp[4], MatStm1.comp[1].VapCp[5], MatStm1.comp[1].VapCp[6]}, Heater1.outT)
*/
void heater1_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  data->localData[0]->realVars[60] /* MatStm1.compMolSpHeat[3,1] variable */ = omc_Simulator_Files_Thermodynamic__Functions_VapCpId(threadData, tmp1, data->localData[0]->realVars[8] /* Heater1.outT variable */);
  TRACE_POP
}
/*
equation index: 285
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[2,2] = Simulator.Files.Thermodynamic_Functions.LiqCpId({MatStm1.comp[2].LiqCp[1], MatStm1.comp[2].LiqCp[2], MatStm1.comp[2].LiqCp[3], MatStm1.comp[2].LiqCp[4], MatStm1.comp[2].LiqCp[5], MatStm1.comp[2].LiqCp[6]}, Heater1.outT)
*/
void heater1_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[281], (modelica_real)data->simulationInfo->realParameter[282], (modelica_real)data->simulationInfo->realParameter[283], (modelica_real)data->simulationInfo->realParameter[284], (modelica_real)data->simulationInfo->realParameter[285], (modelica_real)data->simulationInfo->realParameter[286]);
  data->localData[0]->realVars[59] /* MatStm1.compMolSpHeat[2,2] variable */ = omc_Simulator_Files_Thermodynamic__Functions_LiqCpId(threadData, tmp2, data->localData[0]->realVars[8] /* Heater1.outT variable */);
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[3,2] = Simulator.Files.Thermodynamic_Functions.VapCpId({MatStm1.comp[2].VapCp[1], MatStm1.comp[2].VapCp[2], MatStm1.comp[2].VapCp[3], MatStm1.comp[2].VapCp[4], MatStm1.comp[2].VapCp[5], MatStm1.comp[2].VapCp[6]}, Heater1.outT)
*/
void heater1_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  data->localData[0]->realVars[61] /* MatStm1.compMolSpHeat[3,2] variable */ = omc_Simulator_Files_Thermodynamic__Functions_VapCpId(threadData, tmp3, data->localData[0]->realVars[8] /* Heater1.outT variable */);
  TRACE_POP
}
/*
equation index: 287
type: ALGORITHM

  (MatStm1.compMolEntr[2,2], MatStm1.compMolEntr[3,2]) := Simulator.Files.Thermodynamic_Functions.SId(MatStm1.comp[2].AS, {MatStm1.comp[2].VapCp[1], MatStm1.comp[2].VapCp[2], MatStm1.comp[2].VapCp[3], MatStm1.comp[2].VapCp[4], MatStm1.comp[2].VapCp[5], MatStm1.comp[2].VapCp[6]}, {MatStm1.comp[2].HOV[1], MatStm1.comp[2].HOV[2], MatStm1.comp[2].HOV[3], MatStm1.comp[2].HOV[4], MatStm1.comp[2].HOV[5], MatStm1.comp[2].HOV[6]}, MatStm1.comp[2].Tb, MatStm1.comp[2].Tc, Heater1.outT, Heater1.outP, MatStm1.compMolFrac[2,2], MatStm1.compMolFrac[3,2]);
*/
void heater1_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->localData[0]->realVars[41] /* MatStm1.compMolEntr[2,2] variable */ = omc_Simulator_Files_Thermodynamic__Functions_SId(threadData, data->simulationInfo->realParameter[242], tmp4, tmp5, data->simulationInfo->realParameter[338], data->simulationInfo->realParameter[340], data->localData[0]->realVars[8] /* Heater1.outT variable */, data->localData[0]->realVars[7] /* Heater1.outP variable */, data->localData[0]->realVars[53] /* MatStm1.compMolFrac[2,2] variable */, data->localData[0]->realVars[55] /* MatStm1.compMolFrac[3,2] variable */ ,&data->localData[0]->realVars[43] /* MatStm1.compMolEntr[3,2] variable */);
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
MatStm1._phasMolSpHeat[2] = MatStm1.compMolFrac[2,1] * MatStm1.compMolSpHeat[2,1] + MatStm1.compMolFrac[2,2] * MatStm1.compMolSpHeat[2,2]
*/
void heater1_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->localData[0]->realVars[79] /* MatStm1.phasMolSpHeat[2] variable */ = (data->localData[0]->realVars[52] /* MatStm1.compMolFrac[2,1] variable */) * (data->localData[0]->realVars[58] /* MatStm1.compMolSpHeat[2,1] variable */) + (data->localData[0]->realVars[53] /* MatStm1.compMolFrac[2,2] variable */) * (data->localData[0]->realVars[59] /* MatStm1.compMolSpHeat[2,2] variable */);
  TRACE_POP
}
/*
equation index: 289
type: SIMPLE_ASSIGN
MatStm1._phasMolSpHeat[3] = MatStm1.compMolFrac[3,1] * MatStm1.compMolSpHeat[3,1] + MatStm1.compMolFrac[3,2] * MatStm1.compMolSpHeat[3,2]
*/
void heater1_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->localData[0]->realVars[80] /* MatStm1.phasMolSpHeat[3] variable */ = (data->localData[0]->realVars[54] /* MatStm1.compMolFrac[3,1] variable */) * (data->localData[0]->realVars[60] /* MatStm1.compMolSpHeat[3,1] variable */) + (data->localData[0]->realVars[55] /* MatStm1.compMolFrac[3,2] variable */) * (data->localData[0]->realVars[61] /* MatStm1.compMolSpHeat[3,2] variable */);
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
MatStm1._phasMolSpHeat[1] = MatStm1.liqPhasMolFrac * MatStm1.phasMolSpHeat[2] + Heater1.outVapPhasMolFrac * MatStm1.phasMolSpHeat[3]
*/
void heater1_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  data->localData[0]->realVars[78] /* MatStm1.phasMolSpHeat[1] variable */ = (data->localData[0]->realVars[69] /* MatStm1.liqPhasMolFrac variable */) * (data->localData[0]->realVars[79] /* MatStm1.phasMolSpHeat[2] variable */) + (data->localData[0]->realVars[9] /* Heater1.outVapPhasMolFrac variable */) * (data->localData[0]->realVars[80] /* MatStm1.phasMolSpHeat[3] variable */);
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[1,2] = MatStm1.compMolFrac[1,2] * MatStm1.phasMolSpHeat[1]
*/
void heater1_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  data->localData[0]->realVars[57] /* MatStm1.compMolSpHeat[1,2] variable */ = (data->localData[0]->realVars[51] /* MatStm1.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[78] /* MatStm1.phasMolSpHeat[1] variable */);
  TRACE_POP
}
/*
equation index: 292
type: ALGORITHM

  (MatStm1.compMolEntr[2,1], MatStm1.compMolEntr[3,1]) := Simulator.Files.Thermodynamic_Functions.SId(MatStm1.comp[1].AS, {MatStm1.comp[1].VapCp[1], MatStm1.comp[1].VapCp[2], MatStm1.comp[1].VapCp[3], MatStm1.comp[1].VapCp[4], MatStm1.comp[1].VapCp[5], MatStm1.comp[1].VapCp[6]}, {MatStm1.comp[1].HOV[1], MatStm1.comp[1].HOV[2], MatStm1.comp[1].HOV[3], MatStm1.comp[1].HOV[4], MatStm1.comp[1].HOV[5], MatStm1.comp[1].HOV[6]}, MatStm1.comp[1].Tb, MatStm1.comp[1].Tc, Heater1.outT, Heater1.outP, MatStm1.compMolFrac[2,1], MatStm1.compMolFrac[3,1]);
*/
void heater1_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->localData[0]->realVars[40] /* MatStm1.compMolEntr[2,1] variable */ = omc_Simulator_Files_Thermodynamic__Functions_SId(threadData, data->simulationInfo->realParameter[241], tmp6, tmp7, data->simulationInfo->realParameter[337], data->simulationInfo->realParameter[339], data->localData[0]->realVars[8] /* Heater1.outT variable */, data->localData[0]->realVars[7] /* Heater1.outP variable */, data->localData[0]->realVars[52] /* MatStm1.compMolFrac[2,1] variable */, data->localData[0]->realVars[54] /* MatStm1.compMolFrac[3,1] variable */ ,&data->localData[0]->realVars[42] /* MatStm1.compMolEntr[3,1] variable */);
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
MatStm1._phasMolEntr[2] = MatStm1.compMolFrac[2,1] * MatStm1.compMolEntr[2,1] + MatStm1.compMolFrac[2,2] * MatStm1.compMolEntr[2,2]
*/
void heater1_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  data->localData[0]->realVars[76] /* MatStm1.phasMolEntr[2] variable */ = (data->localData[0]->realVars[52] /* MatStm1.compMolFrac[2,1] variable */) * (data->localData[0]->realVars[40] /* MatStm1.compMolEntr[2,1] variable */) + (data->localData[0]->realVars[53] /* MatStm1.compMolFrac[2,2] variable */) * (data->localData[0]->realVars[41] /* MatStm1.compMolEntr[2,2] variable */);
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
MatStm1._phasMolEntr[3] = MatStm1.compMolFrac[3,1] * MatStm1.compMolEntr[3,1] + MatStm1.compMolFrac[3,2] * MatStm1.compMolEntr[3,2]
*/
void heater1_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  data->localData[0]->realVars[77] /* MatStm1.phasMolEntr[3] variable */ = (data->localData[0]->realVars[54] /* MatStm1.compMolFrac[3,1] variable */) * (data->localData[0]->realVars[42] /* MatStm1.compMolEntr[3,1] variable */) + (data->localData[0]->realVars[55] /* MatStm1.compMolFrac[3,2] variable */) * (data->localData[0]->realVars[43] /* MatStm1.compMolEntr[3,2] variable */);
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
MatStm1._phasMolEntr[1] = MatStm1.liqPhasMolFrac * MatStm1.phasMolEntr[2] + Heater1.outVapPhasMolFrac * MatStm1.phasMolEntr[3]
*/
void heater1_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  data->localData[0]->realVars[75] /* MatStm1.phasMolEntr[1] variable */ = (data->localData[0]->realVars[69] /* MatStm1.liqPhasMolFrac variable */) * (data->localData[0]->realVars[76] /* MatStm1.phasMolEntr[2] variable */) + (data->localData[0]->realVars[9] /* Heater1.outVapPhasMolFrac variable */) * (data->localData[0]->realVars[77] /* MatStm1.phasMolEntr[3] variable */);
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
MatStm1._compMolEntr[1,2] = MatStm1.compMolFrac[1,2] * MatStm1.phasMolEntr[1]
*/
void heater1_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  data->localData[0]->realVars[39] /* MatStm1.compMolEntr[1,2] variable */ = (data->localData[0]->realVars[51] /* MatStm1.compMolFrac[1,2] variable */) * (data->localData[0]->realVars[75] /* MatStm1.phasMolEntr[1] variable */);
  TRACE_POP
}
/*
equation index: 297
type: ALGORITHM

  MatStm1.MW[3] := $START.MatStm1.MW[3];
  MatStm1.MW[2] := $START.MatStm1.MW[2];
  MatStm1.MW[1] := $START.MatStm1.MW[1];
  for i in 1:2 loop
    MatStm1.MW[:] := {MatStm1.MW[1] + MatStm1.compMolFrac[1,i] * MatStm1.comp[i].MW, MatStm1.MW[2] + MatStm1.compMolFrac[2,i] * MatStm1.comp[i].MW, MatStm1.MW[3] + MatStm1.compMolFrac[3,i] * MatStm1.comp[i].MW};
  end for;
*/
void heater1_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  real_array tmp8;
  index_spec_t tmp9;
  real_array tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_integer tmp13;
  data->localData[0]->realVars[15] /* MatStm1.MW[3] variable */ = data->modelData->realVarsData[15].attribute /* MatStm1.MW[3] variable */.start;

  data->localData[0]->realVars[14] /* MatStm1.MW[2] variable */ = data->modelData->realVarsData[14].attribute /* MatStm1.MW[2] variable */.start;

  data->localData[0]->realVars[13] /* MatStm1.MW[1] variable */ = data->modelData->realVarsData[13].attribute /* MatStm1.MW[1] variable */.start;

  tmp11 = ((modelica_integer) 1); tmp12 = 1; tmp13 = ((modelica_integer) 2);
  if(!(((tmp12 > 0) && (tmp11 > tmp13)) || ((tmp12 < 0) && (tmp11 < tmp13))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp11, tmp13); $Pi += tmp12)
    {
      array_alloc_scalar_real_array(&tmp8, 3, (modelica_real)data->localData[0]->realVars[13] /* MatStm1.MW[1] variable */ + ((&data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[14] /* MatStm1.MW[2] variable */ + ((&data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[15] /* MatStm1.MW[3] variable */ + ((&data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp9, 1, (1), (int*)0, 'W');
      real_array_create(&tmp10, (modelica_real*)&data->localData[0]->realVars[13] /* MatStm1.MW[1] variable */, 1, 3);
      indexed_assign_real_array(tmp8, &tmp10, &tmp9);
    }
  }
  TRACE_POP
}
/*
equation index: 298
type: SIMPLE_ASSIGN
MatStm1._totMasFlo[3] = MatStm1.totMolFlo[3] * MatStm1.MW[3]
*/
void heater1_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  data->localData[0]->realVars[92] /* MatStm1.totMasFlo[3] variable */ = (data->localData[0]->realVars[94] /* MatStm1.totMolFlo[3] variable */) * (data->localData[0]->realVars[15] /* MatStm1.MW[3] variable */);
  TRACE_POP
}
/*
equation index: 299
type: SIMPLE_ASSIGN
MatStm1._totMasFlo[1] = 200.0 * MatStm1.MW[1]
*/
void heater1_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  data->localData[0]->realVars[90] /* MatStm1.totMasFlo[1] variable */ = (200.0) * (data->localData[0]->realVars[13] /* MatStm1.MW[1] variable */);
  TRACE_POP
}
/*
equation index: 300
type: SIMPLE_ASSIGN
MatStm1._vapPhasMasFrac = MatStm1.totMasFlo[3] / MatStm1.totMasFlo[1]
*/
void heater1_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  data->localData[0]->realVars[95] /* MatStm1.vapPhasMasFrac variable */ = DIVISION_SIM(data->localData[0]->realVars[92] /* MatStm1.totMasFlo[3] variable */,data->localData[0]->realVars[90] /* MatStm1.totMasFlo[1] variable */,"MatStm1.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 301
type: SIMPLE_ASSIGN
MatStm1._compMasFrac[1,2] = MatStm1.compMasFlo[1,2] / MatStm1.totMasFlo[1]
*/
void heater1_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  data->localData[0]->realVars[27] /* MatStm1.compMasFrac[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[21] /* MatStm1.compMasFlo[1,2] variable */,data->localData[0]->realVars[90] /* MatStm1.totMasFlo[1] variable */,"MatStm1.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 302
type: SIMPLE_ASSIGN
MatStm1._totMasFlo[2] = MatStm1.totMolFlo[2] * MatStm1.MW[2]
*/
void heater1_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  data->localData[0]->realVars[91] /* MatStm1.totMasFlo[2] variable */ = (data->localData[0]->realVars[93] /* MatStm1.totMolFlo[2] variable */) * (data->localData[0]->realVars[14] /* MatStm1.MW[2] variable */);
  TRACE_POP
}
/*
equation index: 303
type: SIMPLE_ASSIGN
MatStm1._liqPhasMasFrac = MatStm1.totMasFlo[2] / MatStm1.totMasFlo[1]
*/
void heater1_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  data->localData[0]->realVars[68] /* MatStm1.liqPhasMasFrac variable */ = DIVISION_SIM(data->localData[0]->realVars[91] /* MatStm1.totMasFlo[2] variable */,data->localData[0]->realVars[90] /* MatStm1.totMasFlo[1] variable */,"MatStm1.totMasFlo[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 304
type: LINEAR

<var>MatStm1._compMasFrac[3,2]</var>
<var>MatStm1._compMasFrac[2,2]</var>
<var>MatStm1._compMasFrac[3,1]</var>
<var>MatStm1._compMasFrac[1,1]</var>
<var>MatStm1._compMasFrac[2,1]</var>
<row>
  <cell>if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then MatStm1.compMasFlo[2,1] else 0.0</cell>
  <cell>if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then MatStm1.compMasFlo[1,1] else 0.0</cell>
  <cell>if Heater1.outP >= MatStm1.Pbubl then MatStm1.compMasFlo[1,1] else if Heater1.outP >= MatStm1.Pdew then MatStm1.compMasFlo[3,1] else MatStm1.compMasFlo[1,1]</cell>
  <cell>if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then MatStm1.compMasFlo[2,2] else 0.0</cell>
  <cell>if Heater1.outP >= MatStm1.Pbubl then -MatStm1.compMasFrac[1,2] else if Heater1.outP >= MatStm1.Pdew then MatStm1.compMasFlo[3,2] else -MatStm1.compMasFrac[1,2]</cell>
</row>
<matrix>
  <cell row="0" col="0">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="0" col="1">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="0" col="4">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -MatStm1.totMasFlo[2] else 0.0)</residual>
  </cell><cell row="1" col="2">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="1" col="3">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -MatStm1.totMasFlo[1] else 0.0)</residual>
  </cell><cell row="1" col="4">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="2" col="2">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then -0.0 else if Heater1.outP >= MatStm1.Pdew then -MatStm1.totMasFlo[3] else -0.0)</residual>
  </cell><cell row="2" col="3">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then -MatStm1.totMasFlo[1] else if Heater1.outP >= MatStm1.Pdew then -0.0 else -MatStm1.totMasFlo[1])</residual>
  </cell><cell row="3" col="1">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -MatStm1.totMasFlo[2] else 0.0)</residual>
  </cell><cell row="3" col="2">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -0.0 else 1.0)</residual>
  </cell><cell row="3" col="3">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then -1.0 else if Heater1.outP >= MatStm1.Pdew then -0.0 else -1.0)</residual>
  </cell><cell row="3" col="4">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 1.0 else -0.0)</residual>
  </cell><cell row="4" col="0">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 0.0 else if Heater1.outP >= MatStm1.Pdew then -MatStm1.totMasFlo[3] else 1.0)</residual>
  </cell><cell row="4" col="1">
    <residual>-(if Heater1.outP >= MatStm1.Pbubl then 1.0 else -0.0)</residual>
  </cell>
</matrix>
*/
OMC_DISABLE_OPT
void heater1_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  /* Linear equation system */
  int retValue;
  double aux_x[5] = { data->localData[1]->realVars[31] /* MatStm1.compMasFrac[3,2] variable */,data->localData[1]->realVars[29] /* MatStm1.compMasFrac[2,2] variable */,data->localData[1]->realVars[30] /* MatStm1.compMasFrac[3,1] variable */,data->localData[1]->realVars[26] /* MatStm1.compMasFrac[1,1] variable */,data->localData[1]->realVars[28] /* MatStm1.compMasFrac[2,1] variable */ };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 304 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  retValue = solve_linear_system(data, threadData, 3, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,304};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 304 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[31] /* MatStm1.compMasFrac[3,2] variable */ = aux_x[0];
  data->localData[0]->realVars[29] /* MatStm1.compMasFrac[2,2] variable */ = aux_x[1];
  data->localData[0]->realVars[30] /* MatStm1.compMasFrac[3,1] variable */ = aux_x[2];
  data->localData[0]->realVars[26] /* MatStm1.compMasFrac[1,1] variable */ = aux_x[3];
  data->localData[0]->realVars[28] /* MatStm1.compMasFrac[2,1] variable */ = aux_x[4];
  TRACE_POP
}
/*
equation index: 305
type: SIMPLE_ASSIGN
MatStm1._compMolSpHeat[1,1] = MatStm1.compMolFrac[1,1] * MatStm1.phasMolSpHeat[1]
*/
void heater1_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  data->localData[0]->realVars[56] /* MatStm1.compMolSpHeat[1,1] variable */ = (data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[78] /* MatStm1.phasMolSpHeat[1] variable */);
  TRACE_POP
}
/*
equation index: 306
type: SIMPLE_ASSIGN
MatStm1._compMolEntr[1,1] = MatStm1.compMolFrac[1,1] * MatStm1.phasMolEntr[1]
*/
void heater1_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  data->localData[0]->realVars[38] /* MatStm1.compMolEntr[1,1] variable */ = (data->localData[0]->realVars[50] /* MatStm1.compMolFrac[1,1] variable */) * (data->localData[0]->realVars[75] /* MatStm1.phasMolEntr[1] variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int heater1_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  heater1_functionLocalKnownVars(data, threadData);
  heater1_eqFunction_181(data, threadData);

  heater1_eqFunction_182(data, threadData);

  heater1_eqFunction_183(data, threadData);

  heater1_eqFunction_184(data, threadData);

  heater1_eqFunction_207(data, threadData);

  heater1_eqFunction_208(data, threadData);

  heater1_eqFunction_209(data, threadData);

  heater1_eqFunction_210(data, threadData);

  heater1_eqFunction_211(data, threadData);

  heater1_eqFunction_212(data, threadData);

  heater1_eqFunction_213(data, threadData);

  heater1_eqFunction_214(data, threadData);

  heater1_eqFunction_215(data, threadData);

  heater1_eqFunction_216(data, threadData);

  heater1_eqFunction_217(data, threadData);

  heater1_eqFunction_218(data, threadData);

  heater1_eqFunction_219(data, threadData);

  heater1_eqFunction_220(data, threadData);

  heater1_eqFunction_221(data, threadData);

  heater1_eqFunction_222(data, threadData);

  heater1_eqFunction_223(data, threadData);

  heater1_eqFunction_224(data, threadData);

  heater1_eqFunction_225(data, threadData);

  heater1_eqFunction_226(data, threadData);

  heater1_eqFunction_227(data, threadData);

  heater1_eqFunction_228(data, threadData);

  heater1_eqFunction_229(data, threadData);

  heater1_eqFunction_230(data, threadData);

  heater1_eqFunction_231(data, threadData);

  heater1_eqFunction_232(data, threadData);

  heater1_eqFunction_233(data, threadData);

  heater1_eqFunction_234(data, threadData);

  heater1_eqFunction_235(data, threadData);

  heater1_eqFunction_236(data, threadData);

  heater1_eqFunction_237(data, threadData);

  heater1_eqFunction_238(data, threadData);

  heater1_eqFunction_239(data, threadData);

  heater1_eqFunction_240(data, threadData);

  heater1_eqFunction_241(data, threadData);

  heater1_eqFunction_242(data, threadData);

  heater1_eqFunction_243(data, threadData);

  heater1_eqFunction_244(data, threadData);

  heater1_eqFunction_245(data, threadData);

  heater1_eqFunction_246(data, threadData);

  heater1_eqFunction_277(data, threadData);

  heater1_eqFunction_278(data, threadData);

  heater1_eqFunction_279(data, threadData);

  heater1_eqFunction_280(data, threadData);

  heater1_eqFunction_281(data, threadData);

  heater1_eqFunction_282(data, threadData);

  heater1_eqFunction_283(data, threadData);

  heater1_eqFunction_284(data, threadData);

  heater1_eqFunction_285(data, threadData);

  heater1_eqFunction_286(data, threadData);

  heater1_eqFunction_287(data, threadData);

  heater1_eqFunction_288(data, threadData);

  heater1_eqFunction_289(data, threadData);

  heater1_eqFunction_290(data, threadData);

  heater1_eqFunction_291(data, threadData);

  heater1_eqFunction_292(data, threadData);

  heater1_eqFunction_293(data, threadData);

  heater1_eqFunction_294(data, threadData);

  heater1_eqFunction_295(data, threadData);

  heater1_eqFunction_296(data, threadData);

  heater1_eqFunction_297(data, threadData);

  heater1_eqFunction_298(data, threadData);

  heater1_eqFunction_299(data, threadData);

  heater1_eqFunction_300(data, threadData);

  heater1_eqFunction_301(data, threadData);

  heater1_eqFunction_302(data, threadData);

  heater1_eqFunction_303(data, threadData);

  heater1_eqFunction_304(data, threadData);

  heater1_eqFunction_305(data, threadData);

  heater1_eqFunction_306(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int heater1_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int heater1_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  heater1_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "heater1_12jac.h"
#include "heater1_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks heater1_callback = {
   (int (*)(DATA *, threadData_t *, void *)) heater1_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) heater1_performQSSSimulation,
   heater1_updateContinuousSystem,
   heater1_callExternalObjectDestructors,
   heater1_initialNonLinearSystem,
   heater1_initialLinearSystem,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   heater1_initializeStateSets,
   #else
   NULL,
   #endif
   heater1_initializeDAEmodeData,
   heater1_functionODE,
   heater1_functionAlgebraics,
   heater1_functionDAE,
   heater1_functionLocalKnownVars,
   heater1_input_function,
   heater1_input_function_init,
   heater1_input_function_updateStartValues,
   heater1_output_function,
   heater1_function_storeDelayed,
   heater1_updateBoundVariableAttributes,
   heater1_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   heater1_functionInitialEquations_lambda0,
   heater1_functionRemovedInitialEquations,
   heater1_updateBoundParameters,
   heater1_checkForAsserts,
   heater1_function_ZeroCrossingsEquations,
   heater1_function_ZeroCrossings,
   heater1_function_updateRelations,
   heater1_zeroCrossingDescription,
   heater1_relationDescription,
   heater1_function_initSample,
   heater1_INDEX_JAC_A,
   heater1_INDEX_JAC_B,
   heater1_INDEX_JAC_C,
   heater1_INDEX_JAC_D,
   heater1_initialAnalyticJacobianA,
   heater1_initialAnalyticJacobianB,
   heater1_initialAnalyticJacobianC,
   heater1_initialAnalyticJacobianD,
   heater1_functionJacA_column,
   heater1_functionJacB_column,
   heater1_functionJacC_column,
   heater1_functionJacD_column,
   heater1_linear_model_frame,
   heater1_linear_model_datarecovery_frame,
   heater1_mayer,
   heater1_lagrange,
   heater1_pickUpBoundsForInputsInOptimization,
   heater1_setInputData,
   heater1_getTimeGrid,
   heater1_symbolicInlineSystem,
   heater1_function_initSynchronous,
   heater1_function_updateSynchronous,
   heater1_function_equationsSynchronous,
   heater1_inputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/OpenModelica1.13.264bit/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,40,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/OpenModelica1.13.264bit/lib/omlibrary/Modelica 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,55,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/OpenModelica1.13.264bit/lib/omlibrary/ModelicaServices 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,63,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "Simulator"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/OMChemSimGUI/SimulationFiles"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,9,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,31,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "heater1"
#define _OMC_LIT_RESOURCE_4_dir_data "C:/OMChemSimGUI/SimulationFiles/Simulator"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,7,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,41,_OMC_LIT_RESOURCE_4_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,10,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir)}};
void heater1_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &heater1_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "heater1";
  data->modelData->modelFilePrefix = "heater1";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/OMChemSimGUI/SimulationFiles/Simulator";
  data->modelData->modelGUID = "{92d518cd-83a4-4f08-afc6-2f65126b5968}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "heater1_init.c"
    ;
  static const char contents_info[] =
    #include "heater1_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "heater1_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "heater1_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 188;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 634;
  data->modelData->nParametersInteger = 17;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 16;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 89;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "heater1_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 7;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 944;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 4;
  data->modelData->nNonLinearSystems = 4;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    heater1_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

#ifdef __cplusplus
}
#endif


